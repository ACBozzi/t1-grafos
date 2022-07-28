#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

// https://www.mankier.com/3/cgraph
// https://www.graphviz.org/pdf/cgraph.pdf

// OK------------------------------------------------------------------------------
grafo le_grafo(void)
{
  // FILE *stdin;
  grafo graph;

  graph = (Agraph_t *)malloc(sizeof(Agraph_t));

  // graph = malloc(sizeof (struct grafo));
  if (!graph)
  {
    printf("Não foi possível alocar o grafo.\n");
    return NULL;
  }
  else
    printf("Alocado corretamente.\n\n");

  graph = agread(stdin, NULL);

  // devolve o grafo lido, ou NULL
  // return agread(stdin,NULL);
  return graph;
}

// OK------------------------------------------------------------------------------
void destroi_grafo(grafo g)
{
  agclose(g);
  // free(g);
  return 1;
}

// OK------------------------------------------------------------------------------
grafo escreve_grafo(grafo g)
{

  return agwrite(g, stdout);
}

// OK-----------------------------------------------------------------------------
int n_vertices(grafo g)
{
  int num_vert;
  num_vert = agnnodes(g);
  // printf("Número de vértices do grafo é: %d\n\n", num_vert);
  return num_vert;
}

// OK----------------------------------------------------------------------------
int n_arestas(grafo g)
{
  int num_aresta;
  num_aresta = agnedges(g);
  // printf("Número de arestas do grafo é: %d\n\n", num_aresta);

  return 0;
}

// NÃO SOUBE TESTAR-----------------------------------------------------------------------------
// ATENÇÃO: AQUI TALVEZ PRECISE USAR agnameof
//  int grau(vertice v, grafo g) {
//    int grau;
//    vertice vert;

//   //procura um nó no grafo
//   vert = agnode (g,v,TRUE);

//   //retorna o conjunto de arestas de um nó
//   grau = agdegree(g,vert,TRUE,TRUE);
//   printf("O grau do vértice v é: %d\n\n", grau);

//   return 0;
// }

// OK-----------------------------------------------------------------------------
int grau_maximo(grafo g)
{

  Agnode_t *vertice;
  int grau_maximo, grau;

  // percorrendo os vértices
  grau = 0;
  grau_maximo = 0;
  for (vertice = agfstnode(g); vertice; vertice = agnxtnode(g, vertice))
  {
    grau = agdegree(g, vertice, TRUE, TRUE);
    // printf("Grau %d", grau_maximo);
    if (grau > grau_maximo)
      grau_maximo = grau;
  }

  printf("Grau máximo: %d\n", grau_maximo);

  return 0;
}

// OK-----------------------------------------------------------------------------
int grau_minimo(grafo g)
{

  Agnode_t *vertice;
  int grau_min, grau;

  // percorrendo os vértices
  grau = 1;
  grau_min = 1;
  for (vertice = agfstnode(g); vertice; vertice = agnxtnode(g, vertice))
  {
    grau_min = agdegree(g, vertice, TRUE, TRUE);
    // printf("Grau %d", grau_min);
    if (grau < grau_min)
      grau_min = grau;
  }

  printf("Grau min: %d\n", grau_min);

  return 0;
}

// OK-----------------------------------------------------------------------------
int grau_medio(grafo g)
{

  Agnode_t *vertice;
  int medio, v;

  // percorrendo os vértices
  v = 0;
  medio = 0;
  for (vertice = agfstnode(g); vertice; vertice = agnxtnode(g, vertice))
  {
    medio = agdegree(g, vertice, TRUE, TRUE) + medio;
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
// // da para usar a matriz de adjacencia pergutando se tudo menos a diagonal eh 1
/*
  int num = n_vertices(g);

  int **adj_m = matriz_adjacencia(g);

  char **values_v = (char *)malloc(num * sizeof(char *));

  Agnode_t *v;
  int i = 0;
  for (v = agfstnode(g); v; v = agnxtnode(g, v))
  {
    values_v[i] = agnameof(v);
    i++;
  }
  
  // verifica se a matriz eh completa
  for (int i = 0; i < num; i++)
  {
    for (int j = i+1; j < i; j++)
      if (adj_m[i][j] == 0)
        return 0;
  }
*/
//   return 1;
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

//-----------------------------------------------------------------------------
//---------FUNÇÕES AUXILIARES PARA MATRIZ DE ADJANCÊNCIA-----------------------
//-----------------------------------------------------------------------------
int **aloca_matriz(int num)
{
  int **matriz, linha, coluna;

  // aloca as linhas
  matriz = malloc(sizeof(int *) * num);

  for (linha = 0; linha < num; linha++)
  {

    // coluna para cada linha
    matriz[linha] = malloc(sizeof(int) * num);

    // inicializando a matriz
    for (coluna = 0; coluna < num; coluna++)
    {
      matriz[linha][coluna] = 0;
    }
  }

  if (!matriz)
  {
    printf("Não foi possível alocar o grafo.\n");
    return NULL;
  }
  else
    printf("Alocado corretamente.\n\n");

  return matriz;
}

int busca_posicao(char **v, char *value, int n)
{
  for (int i = 0; i < n; i++)
    if (strcmp(v[i], value) == 0)
      return i;
}

void print_v(int n, char **vertices)
{
  printf(" ");

  for (int i = 0; i < n; i++)
  {
    printf(" %s", vertices[i]);
  }
  printf("\n");
}

void print_adj_m(int **m, int n, char **vertices)
{
  print_v(n, vertices);
  for (int i = 0; i < n; i++)
  {
    printf("%s ", vertices[i]);
    for (int j = 0; j < n; j++)
    {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html#sec:adjmatrix
int **matriz_adjacencia(grafo g)
{
  int num = n_vertices(g);

  int **adj_m = aloca_matriz(num);

  char **values_v = (char *)malloc(num * sizeof(char *));

  Agnode_t *v;
  int i = 0;
  // coloca os values do grafo como vetor para orientar ao valorar a matriz
  for (v = agfstnode(g); v; v = agnxtnode(g, v))
  {
    values_v[i] = agnameof(v);
    i++;
  }

  Agnode_t *vertice;
  for (vertice = agfstnode(g); vertice; vertice = agnxtnode(g, vertice)) // vertices
  {
    for (Agedge_t *aresta = agfstedge(g, vertice); aresta; aresta = agnxtedge(g, aresta, vertice)) // arestas do vertice
    {
      Agnode_t *tail = NULL;
      Agnode_t *head = NULL;

      tail = agtail(aresta); // o vertice
      head = aghead(aresta); // o vizinho

      char *Stail = agnameof(tail);
      char *Shead = agnameof(head);

      adj_m[busca_posicao(values_v, Stail, num)][busca_posicao(values_v, Shead, num)] = 1;
      adj_m[busca_posicao(values_v, Shead, num)][busca_posicao(values_v, Stail, num)] = 1;
    }
  }
  printf("num %d \n", num);
  printf("\n");

  print_adj_m(adj_m, num, values_v);
  return adj_m;
}

// // -----------------------------------------------------------------------------
grafo complemento(grafo g)
{
  int num = n_vertices(g);

  int **adj_m = matriz_adjacencia(g);
  int **compl_m = aloca_matriz(num);

  char **values_v = (char *)malloc(num * sizeof(char *));

  Agnode_t *v;
  int i = 0;
  for (v = agfstnode(g); v; v = agnxtnode(g, v))
  {
    values_v[i] = agnameof(v);
    i++;
  }
  // faz a matriz de adjacencia do grafo complementar
  for (int i = 0; i < num; i++)
  {
    for (int j = 0; j < i; j++)
      if (adj_m[i][j] == 0)
        compl_m[i][j] = 1;
    for (int k = i + 1; k < num; k++)
      if (adj_m[i][k] == 0)
        compl_m[i][k] = 1;
  }

  printf("num %d \n", num);
  printf("\n");

  print_adj_m(compl_m, num, values_v);
  Agraph_t  *graph_compl = agopen((char*)"G", Agstrictundirected, NULL);

  //printf("to maluxo");
  for (int i = 0; i < num; i++)
  {
    Agnode_t *x = agnode(graph_compl, values_v[i], TRUE);
    for (int j = i + 1; j < num; j++)
    {
      if (compl_m[i][j] == 1)
      {
        Agnode_t *y = agnode(graph_compl, values_v[j], TRUE);
        agedge(graph_compl, x, y, NULL, TRUE);
      }
    }
  }
  agwrite(graph_compl, stdout);
  return NULL;
}
