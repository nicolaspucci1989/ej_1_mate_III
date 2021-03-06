#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include "header_carga.h"
#include "estructuras_datos.h"

int main()
{
  char *provincias[] = {"Salta", "Jujuy", "Tucuman"};
  float descuentos[CANTIDAD_PROVINCIAS][CANTIDAD_SERVICIOS];
  float totalDescuentos[CANTIDAD_PROVINCIAS][CANTIDAD_SERVICIOS];
  struct Facturas fact[CANTIDAD_FACTURAS];
  int opcion, numeroDeRegistro = 0;
  cargarMatrizDescuentos(descuentos);
  cargaDeFacturas(fact);
  while((opcion = menu()) != SALIDA) {
    switch (opcion) {
      case 1:
        /*1.	Provincia que recibio mas presentaciones en general*/
        printf("Provincia que recibio mas prestaciones %s\n",
         provincias[provinciaQueRecibioMasPrestaciones(fact)]);
        break;
      case 2:
        /*2.	Monto total descontado por cada provincia sobre
        cada tipo de servicio*/
        inicializarTotalDescuentos(totalDescuentos);
        totalDeDescuentoPorProvincia(fact, descuentos, totalDescuentos);
        imprimirDescuentos(totalDescuentos);
        break;
      case 3:
        /*3.	Para cada provincia, que servicio fue el menos utilizado*/
        servicioMenosUtilizadoPorProvincia(fact, provincias);
        break;
      case 4:
        /*4.	Ordene de menor a mayor el total descontado por cada tipo de
        servicio en general*/
        inicializarTotalDescuentos(totalDescuentos);
        totalDeDescuentoPorProvincia(fact, descuentos, totalDescuentos);
        totalDescontadoPorServicio(totalDescuentos);
        break;
      case 5:
        ingresoFacturas(fact, numeroDeRegistro);
      default:
        puts("Opcion incorrecta");
        break;
    }
  }
  return 0;
}
