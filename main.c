#include <stdio.h>
#include <math.h>
#include "funciones.h"

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f);
float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
float calcularAreaSuperficial(float puntos[4][3]);
float calcularVolumen(float puntos[4][3]);

int main(int argc, char *argv[])
{
   float puntos[4][3] = {{0, 0, 0}, {0, 0, 3}, {3, 0, 0}, {1, 7, 1}};

   float a, b, c, d, e, f;

   float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);
   printf("El perimetro de la piramide es %f\n", perimetro);

   float areasuperficial = calcularAreaSuperficial(puntos);
   printf("El area superficial de la piramide es %f\n", areasuperficial);

   float volumen = calcularVolumen(puntos);
   printf("El volumen de la piramide es %f\n", volumen);

   return 0;
}