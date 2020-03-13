/*
  2520 es el número más pequeño que puede ser divido por todos los números del 1 al 10 cuyo 
  resultado da como residuo cero. ¿Cuál es el número entero positivo más pequeño que pueda ser 
  divisible por todos los números del 1 al 20 y todos los residuos sean cero?
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
  // Definición de variables
  long maximoComunDivisor(long, long);
  long minimoComunMultiplo(long, long);
  long respuesta = 1;

  for (int i = 1; i <= 20; i++) {
      respuesta = minimoComunMultiplo(respuesta, i);
  }

  printf("%d\n", respuesta);

  return 0;
}

// Obtener el máximo común divisor del número.
// Se utiliza el algoritmo de Euclídes para calcularlo.
// https://es.wikipedia.org/wiki/Algoritmo_de_Euclides
long maximoComunDivisor(long a, long b)
{
  long r;

  if (a > b) {
    long temporal = a;
    a = b;
    b = temporal;
  }

  while (r = a % b) {
    a = b;
    b = r;
  }

  return b;
}

// Obtener el mínimo común múltiplo.
// Se utiliza el máximo común divisor para obtener el mínimo común.
long minimoComunMultiplo(long a, long b)
{
  long long p = (long long) a * b;

  return p / maximoComunDivisor(a, b);
}