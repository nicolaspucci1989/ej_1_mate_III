#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"
#include "estructuras_datos.h"

int buscarMaximo(int vector[])
{
  int i, maximo, ubicacionMaximo=0;
  maximo = vector[0];
  for(i=1; i<CANTIDAD_PROVINCIAS; i++){
    if(vector[i] > maximo){
      maximo = vector[i];
      ubicacionMaximo = i;
    }
  }
  return ubicacionMaximo;
}

int provinciaQueRecibioMasPrestaciones(struct Facturas *facturasDeTuristas)
{
  int i=0;
  int acumuladorProvincias[CANTIDAD_PROVINCIAS] = {0};
  for(i = 0; i < CANTIDAD_FACTURAS; i++){
    if(facturasDeTuristas[i].numeroDeFactura){
      acumuladorProvincias[facturasDeTuristas[i].numeroDeProvincia]++;
    }
  }
  return buscarMaximo(acumuladorProvincias);
}

void totalDeDescuentoPorProvincia(struct Facturas facturasDeTuristas[],
                                  float descuentos[][CANTIDAD_SERVICIOS],
                                  float totalDescuentos[][CANTIDAD_SERVICIOS])
{
  float porcentajeDescontar;
  int i, provincia, servicio;

  for(i = 0; i < CANTIDAD_FACTURAS; i++){
    if(facturasDeTuristas[i].numeroDeFactura){
      provincia = facturasDeTuristas[i].numeroDeProvincia;
      servicio = facturasDeTuristas[i].numeroDeServicio;
      porcentajeDescontar = descuentos[provincia][servicio] / 100.0;
      totalDescuentos[provincia][servicio] += facturasDeTuristas[i].montoDeFactura
                                              * porcentajeDescontar;
    }
  }
}

void inicializarTotalDescuentos(float v[][CANTIDAD_SERVICIOS])
{
  int i,j;
  for(i=0; i<CANTIDAD_PROVINCIAS; i++){
    for(j=0; j<CANTIDAD_SERVICIOS; j++){
      v[i][j] = 0;
    }
  }
}

void servicioMenosUtilizadoPorProvincia(struct Facturas facturasDeTuristas[], char **provincias)
{
  int contadorDeServicios[CANTIDAD_PROVINCIAS][CANTIDAD_SERVICIOS] = {{0}};
  int i, provincia, servicio;
  for(i = 0; i < CANTIDAD_FACTURAS; i++){
    provincia = facturasDeTuristas[i].numeroDeProvincia;
    servicio = facturasDeTuristas[i].numeroDeServicio;
    contadorDeServicios[provincia][servicio]++;
  }
  for(i = 0; i < CANTIDAD_PROVINCIAS; i++){
    printf("Servicio menos utlizado en %s, %d\n", provincias[i],
            buscarServicioMenosUtilizado(contadorDeServicios, i));
  }
}

int buscarServicioMenosUtilizado(int contadorDeServicios[][CANTIDAD_SERVICIOS],int provincia)
{
  int i, min;
  min = contadorDeServicios[provincia][0];
  for(i = 1; i < CANTIDAD_SERVICIOS; i++){
    if(min < contadorDeServicios[provincia][i])
      min = contadorDeServicios[provincia][i];
  }
  return min;
}

void imprimirDescuentos(float v[][CANTIDAD_SERVICIOS])
{
	int i,j;
	for(i=0; i<CANTIDAD_PROVINCIAS;i++){
		for(j=0; j<CANTIDAD_SERVICIOS; j++){
			printf("elemento %d, %d: %.2f\n", i+1, j+1, v[i][j]);
		}
	}
}

void imprimirFacturas( struct Facturas facturasTuristas[] )
{
  int i;
  for(i=0; i<CANTIDAD_FACTURAS; i++){
    printf("Numero de factura %d, Provincia %d, Servicio %d, Monto %2.f\n",
                                                    facturasTuristas[i].numeroDeFactura,
                                                    facturasTuristas[i].numeroDeProvincia,
                                                    facturasTuristas[i].numeroDeServicio,
                                                    facturasTuristas[i].montoDeFactura);
  }
}

int menu()
{
  int opcion;
  printf("%s\n%s\n%s\n%s\n%s\n","1- Provincia que recibio mas prestaciones en general",
														"2- Monto total descontado por cada provincia sobre cada tipo de servicio.",
                            "3- Servicio mas utilizado para cada provincia.",
														"4- Total descontado por cada tipo de servicio.",
                            "0- Salida.");
  fflush(stdout);
  scanf("%d", &opcion);
  return opcion;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(float*)a - *(float*)b );
}

void totalDescontadoPorServicio(float totalDescuentos[][CANTIDAD_SERVICIOS])
{
  struct servicioDescuentoTotal acumuladorDescuentos[CANTIDAD_SERVICIOS];
  int i,j;

  inicializarEstructuraServicioDescuento(acumuladorDescuentos);
  //acumular
  for(i=0; i<CANTIDAD_PROVINCIAS; i++){
    for(j=0; j<CANTIDAD_SERVICIOS; j++){
      acumuladorDescuentos[j].montoTotalDeDescuento += totalDescuentos[i][j];
    }
  }
  //ordenar
  qsort(acumuladorDescuentos, CANTIDAD_SERVICIOS, sizeof(struct servicioDescuentoTotal), comparacion);
  //imprimir
  for(i=0; i<CANTIDAD_SERVICIOS; i++){
    printf("total descontado servicio %d: %.2f\n", acumuladorDescuentos[i].numeroDeServicio + 1,
                                                  acumuladorDescuentos[i].montoTotalDeDescuento);
  }
}

void inicializarEstructuraServicioDescuento(struct servicioDescuentoTotal s[])
{
  int i;
  for(i=0; i<CANTIDAD_SERVICIOS; i++){
    s[i].numeroDeServicio = i;
    s[i].montoTotalDeDescuento = 0;
  }
}

void ordenar_burbuja(struct servicioDescuentoTotal acumuladorDescuentos[CANTIDAD_SERVICIOS])
{
  int i,j;
  struct servicioDescuentoTotal aux;

  for (i = 0 ; i < CANTIDAD_SERVICIOS; i++)
  {
    for (j = 0 ; j < CANTIDAD_SERVICIOS - 1; j++)
    {

      if (acumuladorDescuentos[j].montoTotalDeDescuento < acumuladorDescuentos[j+1].montoTotalDeDescuento)
      {
        aux = acumuladorDescuentos[j];
        acumuladorDescuentos[j] = acumuladorDescuentos[j+1];
        acumuladorDescuentos[j+1] = aux;
      }
    }
  }
}

int comparacion(const void *a, const void *b)
{
  struct servicioDescuentoTotal *ia = (struct servicioDescuentoTotal*)a;
  struct servicioDescuentoTotal *ib = (struct servicioDescuentoTotal*)b;
  return (int)(100.f*ia->montoTotalDeDescuento - 100.f*ib->montoTotalDeDescuento);
  /* float comparison: returns negative if b > a
  and positive if a > b. We multiplied result by 100.0
  to preserve decimal fraction */
}

void ingresoFacturas(struct Facturas fact[CANTIDAD_FACTURAS], int numeroRegistro)
{
  printf("Ingrese numero de factura\n");
  scanf("%d", &fact[numeroRegistro].numeroDeFactura);
  while(fact[numeroRegistro].numeroDeFactura){
    printf("Ingrese numero de provincia\n");
    printf("Ingrese numero de servicio\n");
    printf("Ingrese monto de factura\n");
    numeroRegistro++;
    printf("Ingrese numero de factura\n");
  }
}

void inicializarFacturas(struct Facturas s[])
{
  int i;
  for(i=0; i<CANTIDAD_FACTURAS; i++){
    s[i].numeroDeFactura = 0;
  }
}
