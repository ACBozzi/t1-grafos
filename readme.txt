Trabalho referente a discuplina de GRAFOS

Alunos: Anna Caroline Bozzi GRR 20173532
		Jose Guilherme de Oliveira Pedroso   GRR 20182958


A implementação das funções:
	n_vertices,
	n_arestas,
	le_grafo,
	destroi_grafo,
	escreve_grafo,
	grau,
	grau_minimo,
	grau_maximo,
	grau_medio,

Exigiram apenas algumas combinações de funçõeo da biblioteca trivial de manipulação de grafos.
Porém exigiu estudo.

Foram criadas funções auxiliares com o abjetivo de modularizar e complementar as funções principais:
	int **aloca_matriz(int num);
	int busca_posicao(char **v, char *value, int n);
	void print_v(int n, char **vertices);
	void print_adj_m(int **m, int n, char **vertices);
	void insere_nodo_deep(char **v);
	void b_largura(int i, int size, int *visitado, int **matriz_adjacencia);
	int **mat_mult(int tam, int **matriz1, int **matriz2);
	void print_mtx(int **m, int tam);

Todas estão indicadas no grafo.c, de forma a identificar quais são auxiliares para quais.


As demais funções foram escritas utilizando lógica, bem como, refenciais teóricos e exemplos.

Regular: é percorrido cada vértice e conferido a cada laço a igualdade com o anterior verificado

Completo: para classificar a completude foi utilizada a matriz de adjacência

Conexo: Para essa função foi utilizado busca em laargura e verificação de um componente apenas para classificar a conexidade.

Bipartido: Foi implementado a técnica de bi-coloração, pois a bi-coloração garante a sua bipartição.

n_triangulos: para o número de triângulos utilizou a matriz de adjacência. A referência 1 abaixo elucida melhor a técnica utilziada.

Matriz de adjacência: Foi utilizado um vetor auxiliar que mapeia os vértices para que a posição do vértice no vetor seja a representação numérica dele na matriz por exemplo:
	VETOR = [A, B, C], onde A é vizinho de B, sendo assim a posição [0][1] receberá 1 assim como a posição [1][0].
Para percorrer o grafo foi usado o modelo conforme a documentação da cgraph


Complemento: para o complemento foi feito a matriz de adjacencia do grafo complementar, para então gerar o complemento.


Bugs Conhecidos:
Na função de bipartição, por motivo desconhecido o último vértice não é colorido, o que não comprometeu a corretude das respostas para os testes realizado.


A compilação resulta em muitos warnings, por algumas opções do Makefile.




REFERÊNCIAS:

1 - https://www.geeksforgeeks.org/number-of-triangles-in-a-undirected-graph/
2 - https://www.mankier.com/3/cgraph
3 - https://www.graphviz.org/pdf/cgraph.pdf
4 - https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html#sec:adjmatrix
5 - https://graphonline.ru/pt/