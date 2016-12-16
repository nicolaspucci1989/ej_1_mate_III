#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include "header_carga.h"
#include "estructuras_datos.h"
#include "header_impresion.h"

int main()
{
  char *provincias[] = {"Salta", "Jujuy", "Tucuman"};
  float descuentos[CANTIDAD_PROVINCIAS][CANTIDAD_SERVICIOS];
  float totalDescuentos[CANTIDAD_PROVINCIAS][CANTIDAD_SERVICIOS];
  struct Facturas fact[CANTIDAD_FACTURAS];
  int opcion, numeroDeRegistro = 0;
  int facturaParaEliminar;
  cargarMatrizDescuentos(descuentos);
  cargaDeFacturas(fact);
  // inicializarFacturas(fact);
  // imprimirFacturas(fact);

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
        inicializarTotalDescuentos(totalDescuentos); // Inicializa el acumulador de descuentos por provincia
        totalDeDescuentoPorProvincia(fact, descuentos, totalDescuentos); // acumula los descuentos en la matriz
        imprimirDescuentos(totalDescuentos, provincias);
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
        // Ingreso de factura
        if(numeroDeRegistro < CANTIDAD_FACTURAS){
          ingresoFacturas(fact, numeroDeRegistro);
          numeroDeRegistro++;
        } else {
          puts("No se pueden ingresar mas facturas.");
        }
      break;

      case 6:
        //eliminar factura
        ingresoDeFacturaParaEliminar(&facturaParaEliminar);
        eliminarFactura(facturaParaEliminar, fact);
      break;

      case 7:
        // Imprimir facturas
        imprimirFacturas(fact, provincias);
      break;

      case 8:
        // Imprimir facturas
        imprimirDescuentos(descuentos, provincias);
      break;

      default:
        puts("Opcion incorrecta");
      break;
    }
  }
  return 0;
}
