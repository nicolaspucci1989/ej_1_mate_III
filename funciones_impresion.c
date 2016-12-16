#include <stdio.h>
#include <stdlib.h>
#include "estructuras_datos.h"

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
    if(facturasTuristas[i].numeroDeFactura){
      printf("Numero de factura %d, Provincia %d, Servicio %d, Monto %2.f\n",
                                                      facturasTuristas[i].numeroDeFactura,
                                                      facturasTuristas[i].numeroDeProvincia,
                                                      facturasTuristas[i].numeroDeServicio,
                                                      facturasTuristas[i].montoDeFactura);
    }
  }
}
