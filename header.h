#ifndef HEADER_H
#define HEADER_H
#include "estructuras_datos.h"

int menu(void);
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
void ordenar_burbuja(struct servicioDescuentoTotal acumuladorDescuentos[CANTIDAD_SERVICIOS]);
int comparacion(const void *a, const void *b);
void ingresoFacturas(struct Facturas fact[CANTIDAD_FACTURAS], int numeroRegistro);
void inicializarTotalDescuentos(float v[][CANTIDAD_SERVICIOS]);
void inicializarFacturas(struct Facturas s[]);
void eliminarFactura(int facturaParaEliminar, struct Facturas fact[]);
void ingresoDeFacturaParaEliminar(int *facturaParaEliminar);
#endif
