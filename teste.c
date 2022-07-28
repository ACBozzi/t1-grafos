#include <stdio.h>
#include "grafo.h"

//------------------------------------------------------------------------------

int main(void) {

  grafo g = le_grafo();
  

  //escreve_grafo(g);

  //destroi_grafo(g);

  // int numero_vertices;
  // numero_vertices = n_vertices(g);
  // printf("Numero de vertices %d: \n",numero_vertices);

  // int numero_arestas;
  // numero_arestas = n_arestas(g);
  // printf("Numero de arestas %d: \n",numero_arestas);


  // int grau_max;  
  // grau_max = grau_maximo(g);
  // printf("Grau máximo %d: \n",grau_max);

  // int grau_min;
  // grau_min = grau_minimo(g);
  // printf("Grau minimo %d: \n",grau_min);


  // int grau_med;
  // grau_med = grau_medio(g);
  // printf("Grau medio %d: \n",grau_med);

  // int grau_v;
  // grau_v = grau("PARNAIBA",g);
  // printf("Grau de B é %d: \n",grau_v);


  // int **adjacencia;
  // int num_vertices,i,j;
  // num_vertices = n_vertices(g);
  // adjacencia =  aloca_matriz(num_vertices);
  // adjacencia = matriz_adjacencia(g);

  // for(i=0; i<num_vertices; i++){
  //   for(j=0; j<num_vertices; j++){
  //     printf(&adjacencia[i][j]);
  //   }
  //   printf("\n");
  // }

  //grafo complem =  complemento(g);
  //escreve_grafo(complem);

  int regul;
  regul = regular(g);
  if (regular == 1){
    printf("É regular\n");
  }else{
    printf("Não é regular\n");
  }



  return 0;
}
