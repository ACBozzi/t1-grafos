//##################################################################
//Trabalho referente a discuplina de GRAFOS                        #
//                                                                 #
//Autores: Anna Caroline Bozzi                  GRR 20173532       #
//         Jose Guilherme de Oliveira Pedroso   GRR 20182958       #
//###################################################################


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

// https://www.mankier.com/3/cgraph
// https://www.graphviz.org/pdf/cgraph.pdf
// https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html#sec:adjmatrix
// https://graphonline.ru/pt/

//-----------------------FUNÇÕES AUXILIARES--------------------------------------
int **aloca_matriz(int num);
int busca_posicao(char **v, char *value, int n);
void print_v(int n, char **vertices);
void print_adj_m(int **m, int n, char **vertices);
void insere_nodo_deep(char **v);
void b_largura(int i, int size, int *visitado, int **matriz_adjacencia);
int **mat_mult(int tam, int **matriz1, int **matriz2);
void print_mtx(int **m, int tam);

//------------------------------------------------------------------------------

// OK------------------------------------------------------------------------------
// devolve o grafo lido da entrada padrão (formato dot)

grafo le_grafo(void)
{
  // FILE *stdin;
  grafo graph;

  graph = (Agraph_t *)malloc(sizeof(Agraph_t));

  // graph = malloc(sizeof (struct grafo));
  if (!graph)
  {
    printf("Não foi possível alocar o grafo...\n");
    return NULL;
  }
  else
    // printf("Grafo alocado corretamente...\n\n");

    graph = agread(stdin, NULL);

  // devolve o grafo lido, ou NULL
  // return agread(stdin,NULL);
  return graph;
}

// OK------------------------------------------------------------------------------
// desaloca g

void destroi_grafo(grafo g)
{
  agfree(g, NULL);
  // free(g);
  // return 1;
}

// OK------------------------------------------------------------------------------
// escreve g na saída padrão em formato dot
// devolve g

grafo escreve_grafo(grafo g)
{

  agwrite(g, stdout);
  return g;
}
// OK-----------------------------------------------------------------------------
// devolve o número de vértices de g

int n_vertices(grafo g)
{
  int num_vert;
  num_vert = agnnodes(g);
  return num_vert;
}

// OK----------------------------------------------------------------------------
// devolve o número de arestas do grafo

int n_arestas(grafo g)
{
  int num_aresta;
  num_aresta = agnedges(g);

  return num_aresta;
}

// OK-----------------------------------------------------------------------------
int grau(vertice v, grafo g)
{

  int grau;
  vertice vert;

  // procura um nó no grafo
  vert = agnode(g, v, TRUE);

  // retorna o conjunto de arestas de um nó
  grau = agdegree(g, vert, TRUE, TRUE);
  // printf("O grau do vértice v é: %d\n\n", grau);

  return grau;
}

// OK-----------------------------------------------------------------------------
// devolve o grau máximo de g

int grau_maximo(grafo g)
{

  vertice ver;
  int grau_maximo, grau;

  // percorrendo os vértices
  grau = 0;
  grau_maximo = 0;
  for (ver = agfstnode(g); ver; ver = agnxtnode(g, ver))
  {
    grau = agdegree(g, ver, TRUE, TRUE);
    // printf("Grau %d", grau_maximo);
    if (grau > grau_maximo)
      grau_maximo = grau;
  }


  return grau_maximo;
}

// OK-----------------------------------------------------------------------------
// devolve o grau mínimo de g

int grau_minimo(grafo g)
{

  vertice vertices;
  int grau_min, grau;

  // percorrendo os vértices
  grau = -1;
  grau_min = 1;
  for (vertices = agfstnode(g); vertices; vertices = agnxtnode(g, vertices))
  {
    grau_min = agdegree(g, vertices, TRUE, TRUE);
    // printf("Grau %d", grau_min);
    if (grau == -1)
      grau = grau_min;
    if (grau < grau_min)
      grau_min = grau;
  }

  return grau_min;
}

// OK-----------------------------------------------------------------------------
// devolve o grau médio de g

int grau_medio(grafo g)
{

  vertice verti;
  int medio, v;

  // percorrendo os vértices
  v = 0;
  medio = 0;
  for (verti = agfstnode(g); verti; verti = agnxtnode(g, verti))
  {
    medio = agdegree(g, verti, TRUE, TRUE) + medio;
    v++;
  }
  medio = medio / v;

  // printf("Grau médio: %d\n", medio);

  return medio;
}

// OK-----------------------------------------------------------------------------
//  devolve 1 se g é regular, ou 0 caso contrário

int regular(grafo g)
{

  vertice ver, ver2;
  int reg, v;

  // percorrendo os vértices
  //* PODE COLOCAR UM BREAK NO FOR OU VER MELHOR NA DOCUMENTACAO *//
  for (ver = agfstnode(g); ver; ver = agnxtnode(g, ver))
  {
    reg = agdegree(g, ver, TRUE, TRUE);
  }

  for (ver2 = agfstnode(g); ver2; ver2 = agnxtnode(g, ver2))
  {
    v = reg;
    reg = agdegree(g, ver2, TRUE, TRUE);
    if (v != reg)
    {
      return 0;
    }
  }
  return 1;
}

//OK-----------------------------------------------------------------------------
//  devolve 1 se g é completo, ou 0 caso contrário

int completo(grafo g)
{

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
  for (i = 0; i < num; i++)
  {
    for (int j = i + 1; j < num; j++)
      if (adj_m[i][j] == 0)
        return 0;
  }
  return 1;
}


//-----------------------------------------------------------------------------
//---------FUNÇÕES AUXILIARES PARA CONEXO--------------------------------------
//-----------------------------------------------------------------------------


void b_largura(int pos, int n_vert, int *visitado, int **matriz_adjacencia)
{  
  int j;
  visitado[pos] = 1; 

  for(j = 0; j < n_vert; j++){
    if (matriz_adjacencia[pos][j] == 1 && !visitado[j])
      b_largura(j, n_vert, visitado, matriz_adjacencia);
  }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


//OK-----------------------------------------------------------------------------
//  devolve 1 se g é conexo, ou 0 caso contrário
//https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/components.html
int conexo(grafo g)
{
  int **matriz_adj, *visitado, n_vert, n_componentes, pos;
  
  n_componentes = 0;
  n_vert = n_vertices(g);
  matriz_adj = matriz_adjacencia(g);
  visitado = malloc( ((unsigned int) n_vert) *sizeof(int));

  //todo vértice será ainda visitado
  for(pos = 0; pos < n_vert; pos++)
    visitado[pos] = 0;

  // para todo vértice não visitado verificar
  for(pos = 0; pos < n_vert; pos++){
    if(visitado[pos] == 0){
      //passa o vetor pra busca
      b_largura(pos, n_vert, visitado, matriz_adj);
      //se algum não foi visitado aumenta componente
      n_componentes++;
      if(n_componentes > 1){
        return 0;
      }
    }
  }

  free(matriz_adj);
  free(visitado);

  return 1;
}

// //CORRIGIR-----------------------------------------------------------------------------
// devolve 1 se g é bipartido, ou 0 caso contrário
// https://www.geeksforgeeks.org/bipartite-graph/
// https://www.baeldung.com/cs/graphs-bipartite
int bipartido(grafo g)
{
  int num = n_vertices(g);

  int i = 0;

  char **values_v = (char *)malloc(num * sizeof(char *));
  int *v_cores = (int *)malloc(num * sizeof(int));

  vertice v;
  for (v = agfstnode(g); v; v = agnxtnode(g, v))
  {
    values_v[i] = agnameof(v);
    v_cores[i] = -1;
    i++;
  }

  vertice vert;
  i = 0;
  v_cores[0] = 0;
  for (vert = agfstnode(g); vert; vert = agnxtnode(g, vert)) // vertices
  {
    for (Agedge_t *aresta = agfstedge(g, vert); aresta; aresta = agnxtedge(g, aresta, vert)) // arestas do vertice
    {
      vertice tail = NULL;
      vertice head = NULL;

      tail = agtail(aresta); // o vertice
      head = aghead(aresta); // o vizinho

      char *Stail = agnameof(tail);
      char *Shead = agnameof(head);
      if (vert == tail) // garantir q so entra pai -> filho
      {
        // caso o vizinho tenha a msm cor ou ja tenha sido colorido pois dai nao sera uma arvore(simplifiquei para se ja foi explorado)
        if(v_cores[busca_posicao(values_v, Shead, num)] == -1){
          v_cores[busca_posicao(values_v, Shead, num)] = v_cores[busca_posicao(values_v, Stail, num)] == 0 ? 1 : 0;
        }
        else
        {
          if(v_cores[busca_posicao(values_v, Shead, num)] == v_cores[busca_posicao(values_v, Stail, num)])
            return 0;
        }

        //printf("%s cor: %d -> %s cor: %d \n", values_v[busca_posicao(values_v, Stail, num)], v_cores[busca_posicao(values_v, Stail, num)], values_v[busca_posicao(values_v, Shead, num)], v_cores[busca_posicao(values_v, Shead, num)]);
      }
    }
    i++;
  }
  return 1;
}

//-----------------------------------------------------------------------------
//---------FUNÇÕES AUXILIARES PARA NUMERO TRIANGULOS---------------------------
//-----------------------------------------------------------------------------

//quadrado de uma matriz
int **mat_mult(int tam, int **matriz1, int **matriz2){

  int **mat_quadrada = aloca_matriz(tam);
  int linha, coluna,aux;

  int soma = 0;

  for (linha = 0; linha < tam; linha++){
    for (coluna = 0; coluna<tam ;coluna++){
      mat_quadrada[linha][coluna] = 0;
      soma = 0;
      for(aux = 0; aux < tam; aux++){
        soma += matriz1[linha][aux] * matriz2[aux][linha];
      }
      mat_quadrada[linha][coluna]+=soma;
    }
  }

  return mat_quadrada;
}

void print_mtx(int **m, int tam) {

  //printf("matriz quadrada\n");

  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
    }

    printf("fim\n\n");
}

//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// devolve o número de triângulos (subgrafos completos de 3 vértices) em g
//https://www.geeksforgeeks.org/number-of-triangles-in-a-undirected-graph/

int n_triangulos(grafo g) {

  int n_nos,trace, n_tri, i;

  int **matriz1 = matriz_adjacencia(g);
  int **matriz2 = matriz_adjacencia(g);

  n_nos = agnnodes(g);

  //faz matriz de adjacencia ao quadrado
  matriz2 = mat_mult(n_nos,matriz1,matriz2);
  
  //faz agora ao cubo
  matriz2 = mat_mult(n_nos,matriz1,matriz2);

  //traço
  trace = 0;
  for (i = 0; i < n_nos; ++i)
  {
    trace +=matriz2[i][i];
  }

  n_tri = (trace / 6);

  free(matriz1);
  free(matriz2);

  return n_tri-1;

}

//-----------------------------------------------------------------------------
//---------FUNÇÕES AUXILIARES PARA MATRIZ DE ADJANCÊNCIA-----------------------
//-----------------------------------------------------------------------------

int **aloca_matriz(int num)
{
  int **matriz;

  // aloca as linhas
  // matriz = malloc(sizeof(int *) * num);
  matriz = (int **)malloc(sizeof(int *) * num);

  if (matriz)
  {
    for (int i = 0; i < num; ++i)
    {
      matriz[i] = (int *)malloc(sizeof(int) * num);
    }
  }

  if (!matriz)
  {
    printf("Não foi possível alocar a matriz....\n");
    return NULL;
  }
  for (int j = 0; j < num; j++){
    for (int k = 0; k < num; k++){
      matriz[j][k] = 0;
    }
  }

  return matriz;
}

//-----------------------------------------------------------------------------
int busca_posicao(char **v, char *value, int n)
{
  int i;

  for (i = 0; i < n; i++){
    if (strcmp(v[i], value) == 0)
      return i;
  }
  return i;
}

//-----------------------------------------------------------------------------
void print_v(int n, char **vertices)
{
  printf(" ");

  for (int i = 0; i < n; i++)
  {
    printf(" %s", vertices[i]);
  }
  printf("\n");
}

//-----------------------------------------------------------------------------
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




// OK-----------------------------------------------------------------------------
//  devolve uma matriz de adjacência de g onde as linhas/colunas
//  estão ordenadas do mesmo modo que agfstnode() e agnxtnode()
//  em libcgraph

int **matriz_adjacencia(grafo g)
{
  int num = n_vertices(g);

  int **adj_m = aloca_matriz(num);

  char **values_v = (char *)malloc(num * sizeof(char *));

  vertice v;
  int i = 0;
  // coloca os values do grafo como vetor para orientar ao valorar a matriz
  for (v = agfstnode(g); v; v = agnxtnode(g, v))
  {
    values_v[i] = agnameof(v);
    i++;
  }

  vertice vert;
  for (vert = agfstnode(g); vert; vert = agnxtnode(g, vert)) // vertices
  {
    for (Agedge_t *aresta = agfstedge(g, vert); aresta; aresta = agnxtedge(g, aresta, vert)) // arestas do vertice
    {
      vertice tail = NULL;
      vertice head = NULL;

      tail = agtail(aresta); // o vertice
      head = aghead(aresta); // o vizinho

      char *Stail = agnameof(tail);
      char *Shead = agnameof(head);

      adj_m[busca_posicao(values_v, Stail, num)][busca_posicao(values_v, Shead, num)] = 1;
      adj_m[busca_posicao(values_v, Shead, num)][busca_posicao(values_v, Stail, num)] = 1;
    }
  }
  return adj_m;
}

//-----------------------------------------------------------------------------

grafo complemento(grafo g)
{
  int num = n_vertices(g);

  int **adj_m = matriz_adjacencia(g);
  int **compl_m = aloca_matriz(num);
  int i = 0, j, k;

  char **values_v = (char *)malloc(num * sizeof(char *));

  vertice v;
  for (v = agfstnode(g); v; v = agnxtnode(g, v))
  {
    values_v[i] = agnameof(v);
    i++;
  }
  // faz a matriz de adjacencia do grafo complementar
  for (i = 0; i < num; i++)
  {
    for (j = 0; j < i; j++)
      if (adj_m[i][j] == 0)
        compl_m[i][j] = 1;
    for (k = i + 1; k < num; k++)
      if (adj_m[i][k] == 0)
        compl_m[i][k] = 1;
  }

  grafo graph_compl = agopen((char *)"G", Agstrictundirected, NULL);

  for (i = 0; i < num; i++)
  {
    vertice x = agnode(graph_compl, values_v[i], TRUE);
    for (j = i + 1; j < num; j++)
    {
      if (compl_m[i][j] == 1)
      {
        vertice y = agnode(graph_compl, values_v[j], TRUE);
        agedge(graph_compl, x, y, NULL, TRUE);
      }
    }
  }

  return graph_compl;
}