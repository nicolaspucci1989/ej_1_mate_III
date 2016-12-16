#include <stdio.h>
#include <stdlib.h>
#include "estructuras_datos.h"

void imprimirDescuentos(float v[][CANTIDAD_SERVICIOS], char *provincias[])
{
	int i,j;
	for(i=0; i<CANTIDAD_PROVINCIAS;i++){
    printf("%s ", provincias[i]);
		for(j=0; j<CANTIDAD_SERVICIOS; j++){
	    printf("%.2f ", v[i][j]);
		}
    printf("\n");
	}
} // fin funcion imprimirDescuentos

void imprimirFacturas( struct Facturas facturasTuristas[], char *provincias[] )
{
  int i;
  printf(" %-15s%15s%15s%15s\n", "Numero de factura", "Provincia", "Servicio", "Monto");
  for(i=0; i<CANTIDAD_FACTURAS; i++){
    if(facturasTuristas[i].numeroDeFactura){
      printf(" %-15d%15s%15d%17.2f\n",facturasTuristas[i].numeroDeFactura,
                                      provincias[facturasTuristas[i].numeroDeProvincia],
                                      facturasTuristas[i].numeroDeServicio,
                                      facturasTuristas[i].montoDeFactura);
    }
  }
} // fin funcion imprimirFacturas
