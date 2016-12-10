#ifndef HEADER_H
#define HEADER_H
#include "estructuras_datos.h"

int menu();
int cmpfunc (const void * a, const void * b);
int provinciaQueRecibioMasPrestaciones(struct Facturas *facturas_de_turistas);
void totalDeDescuentoPorProvincia(struct Facturas facturasDeTuristas[],
                                  float descuentos[][CANTIDAD_SERVICIOS],
                                  float totalDescuentos[][CANTIDAD_SERVICIOS]);
void servicioMenosUtilizadoPorProvincia(struct Facturas facturasDeTuristas[], char **provincias);
void totalDescontadoPorServicio(float totalDescuentos[][CANTIDAD_SERVICIOS]);
void cargarTablaDeDescuentos(float v[][CANTIDAD_SERVICIOS]);
void cargarTablaFacturas(struct Facturas s[]);
void imprimirDescuentos(float v[][CANTIDAD_SERVICIOS]);
void imprimirFacturas( struct Facturas facturasTuristas[] );
int buscarServicioMenosUtilizado(int contadorDeServicios[][CANTIDAD_SERVICIOS],int provincia);
void inicializarEstructuraServicioDescuento(struct servicioDescuentoTotal s[]);

#endif
