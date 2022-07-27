#include <stdio.h>
#include "grafo.h"

//------------------------------------------------------------------------------

int main(void) {
  int numero_vertices, numero_arestas, grau;

  grafo g = le_grafo();

  escreve_grafo(g);

  //destroi_grafo(g);
  //numero_vertices = n_vertices(g);
  //numero_arestas = n_arestas(g);
  //grau = grau();

  matriz_adjacencia(g);


  return 0;
}
