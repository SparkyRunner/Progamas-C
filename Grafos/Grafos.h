#define grafo_h

#ifndef grafo_c

    #include<stdio.h>
    #include<stdlib.h>
    #define TRUE 1
    #define FALSE !TRUE


    typedef struct grafo Grafo;
    Grafo *cria_grafo(int n_vertices, int grau_max, int ponderado);
    void Deleta_grafo(Grafo *g);
    int insereAresta(Grafo *g, int orig, int dest, int digrafo, float peso);
    int removeAresta(Grafo *g, int orig, int dest, int digrafo);

    void buscaProfundidade_Grafo(Grafo *g, int ini, int *visitado);
    void buscaProfundidade(Grafo *g, int ini, int *visitado, int cont);
    void buscaLargura_Grafo(Grafo *g, int ini, int *visitado);
    void menorCaminho_Grafo(Grafo *g, int ini, int *ant, float *dist);
    void algPRIM_Grafo(Grafo *g, int orig, int *pai);
    void algKruskal(Grafo *g, int orig, int *pai);

    void Excentricidade_Max_Min(Grafo *g, int *visitado, int *ant, float *dist );

    void Lista_grafo(Grafo *g);
     void Lista_grafo_inversa(Grafo *g);
    void Matriz_grafo(Grafo *g);
    #endif // grafo_c
