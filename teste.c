#include <stdio.h>
#include "grafo.h"

//------------------------------------------------------------------------------

int main(void) {

  grafo g = le_grafo();
  
//FINALIZADO-------------------------------------------------------------------
  //escreve_grafo(g);

//FINALIZADO-------------------------------------------------------------------
  //destroi_grafo(g);

//FINALIZADO-------------------------------------------------------------------
  // int numero_vertices;
  // numero_vertices = n_vertices(g);
  // printf("Numero de vertices %d: \n",numero_vertices);

//FINALIZADO-------------------------------------------------------------------
  // int numero_arestas;
  // numero_arestas = n_arestas(g);
  // printf("Numero de arestas %d: \n",numero_arestas);

//FINALIZADO-------------------------------------------------------------------
  // int grau_max;  
  // grau_max = grau_maximo(g);
  // printf("Grau máximo: %d \n",grau_max);

//FINALIZADO-------------------------------------------------------------------
  // int grau_min;
  // grau_min = grau_minimo(g);
  // printf("Grau minimo: %d \n",grau_min);

//FINALIZADO-------------------------------------------------------------------
  // int grau_med;
  // grau_med = grau_medio(g);
  // printf("Grau medio %d: \n",grau_med);

//FINALIZADO-------------------------------------------------------------------
  // int grau_v;
  // grau_v = grau("PARNAIBA",g);
  // printf("Grau de B é %d: \n",grau_v);

//CONFERIR-------------------------------------------------------------------
   //int **adjacencia;
   //int num_vertices,i,j;
   //num_vertices = n_vertices(g);
   //adjacencia =  aloca_matriz(num_vertices);
   //adjacencia = matriz_adjacencia(g);

   //for(i=0; i<num_vertices; i++){
   //  for(j=0; j<num_vertices; j++){
   //   printf("%d ", adjacencia[i][j]);
   //  }
   //  printf("\n");
   //}

//FINALIZADO-------------------------------------------------------------------
  // grafo complem =  complemento(g);
  // escreve_grafo(complem);

//FINALIZADO-------------------------------------------------------------------
  // int regul;
  // regul = regular(g);

  // if (regul == 1){
  //   printf("É regular\n");
  // }else{
  //   printf("Não é regular\n");
  // }

//FINALIZADO---------------------------------------------------------------------
  // int comple;
  // comple = completo(g);
  // printf("Completo %d\n", comple);
  // if (comple == 1){
  //   printf("O grafo é completo\n");
  // }else{
  //   printf("O grafo não é completo\n");
  // }

//CORRIGIR-----------------------------------------------------------------------
  // int bipart;
  // bipart = bipartido(g);
  // printf("Bipart %d\n", bipart);
  // if (bipart == 1){
  //   printf("O grafo é bipartido\n");
  // }else{
  //   printf("O grafo não é bipartido\n");
  // }

//FINALIZADO-----------------------------------------------------------------------
  // int cnx;
  // cnx = conexo(g);
  // printf("cnx %d\n", cnx);
  // if (cnx == 1){
  //   printf("O grafo é conexo\n");
  // }else{
  //   printf("O grafo não é conexo\n");
  // }

//FINALIZADO-----------------------------------------------------------------------
  int tri;
  tri = n_triangulos(g);
  printf("Número de triangulos %d\n", tri);

  return 0;
}
