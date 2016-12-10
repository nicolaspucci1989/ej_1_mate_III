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
  float totalDescuentos[CANTIDAD_PROVINCIAS][CANTIDAD_SERVICIOS] = {{0}};
  struct Facturas fact[CANTIDAD_FACTURAS];
  int opcion, flag = 1;
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
        if(flag){
          totalDeDescuentoPorProvincia(fact, descuentos, totalDescuentos);
          flag = 0;
        }
        imprimirDescuentos(totalDescuentos);
        break;
      case 3:
        /*3.	Para cada provincia, que servicio fue el menos utilizado*/
        servicioMenosUtilizadoPorProvincia(fact, provincias);
        break;
      case 4:
        /*4.	Ordene de menor a mayor el total descontado por cada tipo de
        servicio en general*/
        if(flag){
          totalDeDescuentoPorProvincia(fact, descuentos, totalDescuentos);
          flag = 0;
        }
        totalDescontadoPorServicio(totalDescuentos);
        break;
      default:
        puts("Opcion incorrecta");
        break;
    }
  }
  return 0;
}
