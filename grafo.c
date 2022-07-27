#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"


//https://www.mankier.com/3/cgraph

//OK------------------------------------------------------------------------------
grafo le_grafo(void) {
  // FILE *stdin;
  grafo graph;

  graph = (Agraph_t *) malloc(sizeof(Agraph_t));

  // graph = malloc(sizeof (struct grafo));
  if(!graph)
  {
    printf("Não foi possível alocar o grafo.\n");
    return NULL;
  } else
    printf("Alocado corretamente.\n\n");

  graph = agread(stdin, NULL);

  //devolve o grafo lido, ou NULL
  //return agread(stdin,NULL); 
  return graph;
}

//OK------------------------------------------------------------------------------
void destroi_grafo(grafo g) {
  agclose(g);
  //free(g);
  return 1;
}

//OK------------------------------------------------------------------------------
grafo escreve_grafo(grafo g) {
  
  return agwrite(g, stdout);
}

//OK-----------------------------------------------------------------------------
int n_vertices(grafo g) {
  int num_vert;
  num_vert = agnnodes(g);
  printf("Número de vértices do grafo é: %d\n\n", num_vert);
  return num_vert;
}

//OK----------------------------------------------------------------------------
int n_arestas(grafo g) {
  int num_aresta;
  num_aresta = agnedges (g);
  printf("Número de arestas do grafo é: %d\n\n", num_aresta);
  
  return 0;
}

// //NÃO SOUBE TESTAR-----------------------------------------------------------------------------
// //ATENÇÃO: AQUI TALVEZ PRECISE USAR agnameof
// int grau(vertice v, grafo g) {
//   int grau;
//   vertice vert;

//   //procura um nó no grafo
//   vert = agnode (g,v);

//   //retorna o conjunto de arestas de um nó
//   grau = agdegree(vert)
//   printf("O grau do vértice v é: %d\n\n", grau); 

//   return 0;
// }

// // -----------------------------------------------------------------------------
// int grau_maximo(grafo g)  {
  
//   return 0;
// }

// // -----------------------------------------------------------------------------
// int grau_minimo(grafo g)  {
  
//   return 0;
// }

// // -----------------------------------------------------------------------------
// int grau_medio(grafo g) {
  
//   return 0;
// }

// // -----------------------------------------------------------------------------
// int regular(grafo g) {
  
//   return 0;
// }

// // -----------------------------------------------------------------------------
// int completo(grafo g) {
  
//   return 0;
// }

// // -----------------------------------------------------------------------------
// int conexo(grafo g) {
  
//   return 0;
// }

// // -----------------------------------------------------------------------------
// int bipartido(grafo g) {
  
//   return 0;
// }

// // -----------------------------------------------------------------------------
// int n_triangulos(grafo g) {
  
//   return 0;
// }

// //----FUNÇÕES NECESSÁRIAS PARA A MATRIS DE ADJACÊNCIA----------------------------



// -----------------------------------------------------------------------------

int **matriz_adjacencia(grafo g) {
   int num;

   num = n_vertices(g);
   printf("Num dentro de matrix %d\n\n", num);

  
  return NULL;
}

// // -----------------------------------------------------------------------------
// grafo complemento(grafo g) {
  
//   return NULL;
// }

