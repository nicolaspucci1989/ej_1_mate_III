#include <stdio.h>
#include <stdlib.h>
#include "header_carga.h"
#include "estructuras_datos.h"
//son 5 servicios y 3 provincias
void cargarMatrizDescuentos(float v[][CANTIDAD_SERVICIOS]){
  //carga provincia 1
  v[0][0] = 10;
  v[0][1] = 40;
  v[0][2] = 30;
  // v[0][3] = 20;
  // v[0][4] = 30;
  //carga provincia 2
  v[1][0] = 15;
  v[1][1] = 45;
  v[1][2] = 20;
  // v[1][3] = 30;
  // v[1][4] = 35;
  //carga provincia 3
  v[2][0] = 45;
  v[2][1] = 50;
  v[2][2] = 20;
  // v[2][3] = 25;
  // v[2][4] = 10;
}
//son 10 facturas
void cargaDeFacturas(struct Facturas str[]){
  str[0].numeroDeFactura = 200;
  str[0].numeroDeProvincia = 0;
  str[0].numeroDeServicio = 0;
  str[0].montoDeFactura = 100;

  str[1].numeroDeFactura = 256;
  str[1].numeroDeProvincia = 0;
  str[1].numeroDeServicio = 0;
  str[1].montoDeFactura = 100;

  str[2].numeroDeFactura = 299;
  str[2].numeroDeProvincia = 2;
  str[2].numeroDeServicio = 2;
  str[2].montoDeFactura = 199;

  str[3].numeroDeFactura = 291;
  str[3].numeroDeProvincia = 2;
  str[3].numeroDeServicio = 1;
  str[3].montoDeFactura = 90;

  str[4].numeroDeFactura = 3832;
  str[4].numeroDeProvincia = 2;
  str[4].numeroDeServicio = 0;
  str[4].montoDeFactura = 700;

  str[5].numeroDeFactura = 77293;
  str[5].numeroDeProvincia = 2;
  str[5].numeroDeServicio = 1;
  str[5].montoDeFactura = 30;

  str[6].numeroDeFactura = 385;
  str[6].numeroDeProvincia = 1;
  str[6].numeroDeServicio = 0;
  str[6].montoDeFactura = 50;

  str[7].numeroDeFactura = 0;
  str[7].numeroDeProvincia = 1;
  str[7].numeroDeServicio = 2;
  str[7].montoDeFactura = 873;

  str[8].numeroDeFactura = 0;
  str[8].numeroDeProvincia = 2;
  str[8].numeroDeServicio = 2;
  str[8].montoDeFactura = 300;

  str[9].numeroDeFactura = 0;
  str[9].numeroDeProvincia = 2;
  str[9].numeroDeServicio = 1;
  str[9].montoDeFactura = 85;
}
