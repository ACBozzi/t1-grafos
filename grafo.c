#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"


//https://www.mankier.com/3/cgraph
//https://www.graphviz.org/pdf/cgraph.pdf

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
  //printf("Número de vértices do grafo é: %d\n\n", num_vert);
  return num_vert;
}

//OK----------------------------------------------------------------------------
int n_arestas(grafo g) {
  int num_aresta;
  num_aresta = agnedges (g);
  //printf("Número de arestas do grafo é: %d\n\n", num_aresta);
  
  return 0;
}

//NÃO SOUBE TESTAR-----------------------------------------------------------------------------
//ATENÇÃO: AQUI TALVEZ PRECISE USAR agnameof
// int grau(vertice v, grafo g) {
//   int grau;
//   vertice vert;

//   //procura um nó no grafo
//   vert = agnode (g,v,TRUE);

//   //retorna o conjunto de arestas de um nó
//   grau = agdegree(g,vert,TRUE,TRUE);
//   printf("O grau do vértice v é: %d\n\n", grau); 

//   return 0;
// }

//OK-----------------------------------------------------------------------------
int grau_maximo(grafo g)  {

  Agnode_t *vertice;
  int grau_maximo, grau;

  //percorrendo os vértices
  grau = 0;
  grau_maximo = 0;
  for (vertice = agfstnode(g); vertice; vertice = agnxtnode(g,vertice)) {
    grau = agdegree(g,vertice,TRUE,TRUE);
    //printf("Grau %d", grau_maximo);
    if(grau > grau_maximo)
      grau_maximo = grau;
  }

  printf("Grau máximo: %d\n", grau_maximo);

  return 0;
}

//OK-----------------------------------------------------------------------------
int grau_minimo(grafo g)  {
  
  Agnode_t *vertice;
  int grau_min, grau;

  //percorrendo os vértices
  grau = 1;
  grau_min = 1;
  for (vertice = agfstnode(g); vertice; vertice = agnxtnode(g,vertice)) {
    grau_min = agdegree(g,vertice,TRUE,TRUE);
    //printf("Grau %d", grau_min);
    if(grau < grau_min)
      grau_min = grau;
  }

  printf("Grau min: %d\n", grau_min);

  return 0;
}

//OK-----------------------------------------------------------------------------
int grau_medio(grafo g) {
  
  Agnode_t *vertice;
  int medio, v;

  //percorrendo os vértices
  v = 0;
  medio = 0;
  for (vertice = agfstnode(g); vertice; vertice = agnxtnode(g,vertice)) {
    medio = agdegree(g,vertice,TRUE,TRUE) + medio;
    v++;
  }
  medio = medio / v;

  printf("Grau medio: %d\n", medio);
}

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


// // -----------------------------------------------------------------------------
// //https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html#sec:adjmatrix
// int **matriz_adjacencia(grafo g) {
//   int num, **matriz, linha, coluna;

//   num = n_vertices(g);

//   //aloca as linhas
//   matriz= malloc(sizeof(int*)* num);

//   for(linha = 0; linha<num; linha++){

//     //coluna para cada linha
//     matriz[linha] = malloc(sizeof(int)*num);

//     //inicializando a matriz
//     for(coluna = 0; coluna < num; coluna++){
//       matriz[linha][coluna] = 0;
//     }
//   }
  
//   if(!matriz)
//   {
//     printf("Não foi possível alocar o grafo.\n");
//     return NULL;
//   }else
//     printf("Alocado corretamente.\n\n");

  
//   return NULL;
// }

// // -----------------------------------------------------------------------------
// grafo complemento(grafo g) {
  
//   return NULL;
// }

