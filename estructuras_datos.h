#ifndef ESTRUCTURAS_DATOS_H_
#define ESTRUCTURAS_DATOS_H_
#define SALIDA 0
#define CANTIDAD_PROVINCIAS 3
#define CANTIDAD_SERVICIOS 5
#define CANTIDAD_FACTURAS 10
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
struct Facturas {
  int numeroDeFactura;
  int numeroDeProvincia;
  int numeroDeServicio;
  float montoDeFactura;
};

struct servicioDescuentoTotal {
  int numeroDeServicio;
  float montoTotalDeDescuento;
};
#endif  // ESTRUCTURAS_DATOS_H_
