#include <stdio.h>
#include <math.h>
#include "funciones.h"


float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2)
{
   return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f)
{
   *a = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
   *b = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
   *c = calcularDistancias(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);

   *d = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
   *e = calcularDistancias(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
   *f = calcularDistancias(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);

   return *a + *b + *c + *d + *e + *f;
}

float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
   float a = calcularDistancias(x1, y1, z1, x2, y2, z2);
   float b = calcularDistancias(x2, y2, z2, x3, y3, z3);
   float c = calcularDistancias(x1, y1, z1, x3, y3, z3);

   float s = (a + b + c) / 2;
   return sqrt(s * (s - a) * (s - b) * (s - c));
}

float calcularAreaSuperficial(float puntos[4][3])
{
   float areabase = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
   float a1 = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
   float a2 = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
   float a3 = calcularArea(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);

   return areabase + a1 + a2 + a3;
}

float calcularVolumen(float puntos[4][3])
{
   float h = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
   float areabase = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);

   return (areabase * h) / 3;
}