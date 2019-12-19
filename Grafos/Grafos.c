#ifndef grafo_c
#define grafo_c


#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE !TRUE
#include "Grafos.h"
typedef struct grafo {
    int ponderado;
    int n_vertices;
    int grau_max;
    int **arestas;
    float **pesos;
    int *grau;
}Grafo;

 char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'W', 'Z'};

Grafo *cria_grafo(int n_vertices, int grau_max, int ponderado){
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
// Aloca o numero de vertices, o grau maximo, se é ou nao ponderado, o grau inicial como 0 e as arestas

    if(g != NULL){
        g->n_vertices = n_vertices;
        g->grau_max = grau_max; // Quantidade maxima de ligaçoes que um vertice pode ter
        g->ponderado = (ponderado == TRUE)? TRUE : FALSE;
        g->grau = (int*)calloc(n_vertices, sizeof(int)); // Quantidade de vertices ligado ao N vertice, com quantidade maxima = grau_max
        g->arestas = (int**)malloc(sizeof(int*)*n_vertices);



        // Pra cada indice alocado em g->arestas, aloca mais N posiçoes de acordo com o grau maximo
        if(g->grau != NULL && g->arestas != NULL){
            for(int i = 0 ; i < n_vertices ; i++){
                g->arestas[i] = (int*)malloc(sizeof(int)*grau_max);
                if(g->arestas[i] == NULL){
                    return NULL;
                }

            }
        }
        // se for ponderado, aloca tambem pra cada N posiçoes um espaço para armazenar o peso de cada aresta
        if(g->ponderado == TRUE){
            g->pesos = (float**)malloc(sizeof(float*)*n_vertices);
            if(g->pesos == NULL){
                return NULL;
            }
            for(int j = 0 ; j < n_vertices ; j++){
                g->pesos[j] = (float*)malloc(sizeof(float)*grau_max);
                if(g->pesos[j] == NULL){
                    return NULL;
                }
            }
        }

        printf("Grafo criado \n");
        return g;
    }
    printf("Erro na criacao de grafo \n");
    return NULL;
}
//Deleta a matriz de arestas e peso
void Deleta_grafo(Grafo *g){
    if(g != NULL){
        for(int i = 0 ; i < g-> n_vertices ; i++){
            free(g->arestas[i]);
        }
        free(g->arestas);
        if(g->ponderado == TRUE){
            for(int i = 0 ; i < g-> n_vertices ; i++){
                free(g->pesos[i]);
            }
        }
        free(g->grau);
        free(g);
        printf("Grafo deletado \n");
    }
}

void Lista_grafo(Grafo *g){
    if(g != NULL){
        printf("Lista :\n");
        for(int i = 0 ; i < g->n_vertices ; i++){
            if(g->grau[i] > 0){
                printf("%c - ", alpha[i]);
                for(int j = 0 ; j < g->grau[i] ; j++){
                    printf("%c ", alpha[g->arestas[i][j]]);
                }
                printf("\n");
            }
        }
        if(g->ponderado){
            printf("Pesos :\n");
            for(int i = 0 ; i < g->n_vertices ; i++){
                if(g->grau[i] > 0){
                    printf("%c - ", alpha[i]);
                    for(int j = 0 ; j < g->grau[i] ; j++){
                        printf("%2.f ", g->pesos[i][j]);
                    }
                    printf("\n");
                }
            }
        }

    }
}

void Lista_grafo_inversa(Grafo *g){
    if(g != NULL){
        printf("Lista :\n");
        for(int i = 0 ; i < g->n_vertices ; i++){
            if(g->grau[i] > 0){
                printf("%c - ", alpha[i]);
                for(int j = g->grau[i]-1 ; j >= 0 ; j--){
                    printf("%c ", alpha[g->arestas[i][j]]);
                }
                printf("\n");
            }
        }
        if(g->ponderado){
            printf("Pesos :\n");
            for(int i = 0 ; i < g->n_vertices ; i++){
                if(g->grau[i] > 0){
                    printf("%c - ", alpha[i]);
                    for(int j = g->grau[i]-1 ; j >= 0 ; j--){
                        printf("%2.f ", g->pesos[i][j]);
                    }
                    printf("\n");
                }
            }
        }

    }
}
void Matriz_grafo(Grafo *g){
    if(g != NULL){
        for(int i = 0 ; i < g->n_vertices ; i++){ // Anda em todos os vertices
            printf("%c - ", alpha[i]);
            for(int j = 0 ; j < g->n_vertices ; j++){ // Procura se cada elemento possui conexao com algum vertice
                int find = FALSE;
                for(int k = 0 ; k < g->grau[i] ; k++){ // O elemento atual é comparado com todos os graus do vertice, se encontrado, é mostrado seu peso ou conexao
                    if(j == g->arestas[i][k]){
                        find = TRUE;
                        if(g->ponderado == TRUE){
                            printf("%1.f ", g->pesos[i][k]);
                        }else{
                            printf(" 1 ");
                        }
                    }
                }
                if(find == FALSE){
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }

}
//Se nao for digrafo, o caminho é da origem ao destino, se nao, o caminho é de mao dupla

int insereAresta(Grafo *g, int orig, int dest, int digrafo, float peso){
    if(g != NULL){
        if(orig < 0 || orig >= g->n_vertices){
            printf("Quantidade maxima de vertices ja foi alcancada ou valor invalido (Orig)\n");
            return FALSE;
        }
        if(dest < 0 || orig >= g->n_vertices){
            printf("Quantidade amxima de vertices ja foi alcancada ou valor invalido (Dest) \n");
            return FALSE;
        }
        g->arestas[orig][g->grau[orig]] = dest; // a aresta da origem na posiçao da quantidade atual de graus(aresta de origem ao destino) recebe o peso

        if(g->ponderado == TRUE){
            g->pesos[orig][g->grau[orig]] = peso; // se for ponderado, a tabela de peso é atualizada

        }
        g->grau[orig]++; // aumenta a quantidade de graus para possibilitar uma nova inserçao ou informar que esta cheio
        if(digrafo == TRUE){
            insereAresta(g, dest, orig, FALSE, peso); // seta o digrafo para FALSE para evitar looping
        }
        return TRUE;
    }
    printf("Erro ao inserir, grafo nao existe \n");
    return FALSE;
}

int removeAresta(Grafo *g, int orig, int dest, int digrafo){
    if(g != NULL){
        if(orig < 0 || orig >= g->n_vertices){
            printf("Quantidade maxima de vertices ja foi alcancada ou valor invalido (Orig)\n");
            return FALSE;
        }
        if(dest < 0 || orig >= g->n_vertices){
            printf("Quantidade amxima de vertices ja foi alcancada ou valor invalido (Dest) \n");
            return FALSE;
        }
        int i = 0;
        while(i < g->grau[orig] && g->arestas[orig][i] != dest){
            i++; // Procura aresta
        }
        if(i == g->grau[orig]){// elemento nao encontrado
            return FALSE;
        }
        g->grau[orig]--; // atualiza o grau do vertice(elimina aresta)
        g->arestas[orig][i] = g->arestas[orig][g->grau[orig]]; // joga o ultimo elemento das arestas para a posiçao da aresta removida
        if(g->ponderado == TRUE){
            g->pesos[orig][i] = g->pesos[orig][g->grau[orig]]; // joga o ultimo elemento dos pesos para a posiçao do peso removido

        }
        if(digrafo == TRUE){
            removeAresta(g, dest, orig, FALSE); // seta digrafo = FALSE  para evitar looping
        }
        return TRUE;


    }
    printf("Grafo nao existe \n");
    return FALSE;
}
#define Busca por profundidade : Parte de um vertice inicial, explora todo o vertice atual antes de retroceder e explorar outro vertice
#define  Utilidade : Encontrar componente conectados e fortemente conectados, resolver puzzles, labirintos quebra-cabeças etc.. e Ordena~]ao topologica

#define Busca por largura : Parte de um vertice inicial, acha todos os vizinhos, vai em cada vizinho e descobre novos vertices, ate que todos tenham sido explorados.
#define Utilidade : Achar componentes conectados, testar bipartiçao, achar menor caminho e achar vertices conectados a um vertice.

#define Busca pelo menor caminho : A partir de um vertice inicial, acha o menor caminho dele a todos os vertices, desde que exista caminho ate tais vertices
#define Algoritmo de Dijkstra : resolve esse problema para grafos dirigidos ou nao-dirigidos com pesos nao negativos.

void buscaProfundidade(Grafo *g, int ini, int *visitado, int cont){
    visitado[ini] = cont; //Marca o vertice como visitado
    for(int i = 0 ; i<g->grau[ini] ; i++){
        if(g->ponderado == TRUE){
            printf("%c ---%f---> %c \n", alpha[ini], g->pesos[ini][i], alpha[g->arestas[ini][i]]);
        }else{
            printf("%c ------> %c \n", alpha[ini], alpha[g->arestas[ini][i]]);
        }
        if(!visitado[g->arestas[ini][i]]){
            buscaProfundidade(g, g->arestas[ini][i],visitado, cont+1); // visita os vizinhos nao visitados
        }
    }
}
void buscaProfundidade_Grafo(Grafo *g, int ini, int *visitado){
    int cont = 1;
    for(int i = 0 ; i < g->n_vertices ; i++){// marca os vertices como nao visitados
        visitado[i] = 0;
    }
    buscaProfundidade(g, ini, visitado, cont);
}
void buscaLargura_Grafo(Grafo *g, int ini, int *visitado){
    int vert, NV, cont = 1, *fila, IF = 0, FF =0 ;  // IF = Inicio da Fila, FF = Final da Fila
    for(int i = 0 ; i < g->n_vertices ; i++){ // marca vertices como nao visitados
        visitado[i] = 0;
    }
    NV = g->n_vertices;
    fila = (int*)malloc(sizeof(int)*NV); // cria fila visita e coloca ini na fila
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    int aux_cont = cont;
    while(IF != FF){ // pega o primeiro da fila (Equanto fila nao esta vazia)
        IF = (IF + 1) % NV;
        vert = fila[IF]; // pega o primeiro da fila

        //printf("vertice %d vizinhos :\n",vert);
        cont++;

        for(int i = 0 ; i < g->grau[vert]; i++){ // visita os vizinhos ainda nao visitados e coloca na fila
            if(!visitado[g->arestas[vert][i]]){


                if(g->grau[g->arestas[vert][i]] > 0){ // confirma se o vertice tem algum grau, evita incremento desnecessario no cont e evita erro de arestas em outros vertices
                    FF = (FF + 1) % NV;
                    fila[FF] = g->arestas[vert][i];
                }


                visitado[g->arestas[vert][i]] = cont;

            }


        }
    }
     /*for(int i = 0 ; i < NV ; i++){
        if(visitado[i] > 0){
            printf("%d vert %d \n",i, visitado[i]);
        }

        }
    */
    free(fila);

}
int procuraMenorDistancia(float *dist, int *visitado,int NV){
    int menor = -1, primeiro = 1;
    for(int i = 0 ; i < NV ; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i]){
                    menor = i;
                }
            }
        }
    }
    return menor; // se retorna -1 [e pq o grafo é desconexo
}
void menorCaminho_Grafo(Grafo *g, int ini, int *ant, float *dist){//Dijkstra
    int cont, NV, ind, *visitado, u;
    cont = NV = g->n_vertices;
    visitado = (int*)malloc(sizeof(int)*NV);
    for(int i = 0 ;i < NV ; i++){//Cria vetor auxiliar , inicializa distancias , anteriores e visitados
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }

    dist[ini] = 0;
    while(cont > 0){//Procura vertice com menor distancia e marca como visitado
        u = procuraMenorDistancia(dist, visitado, NV);
        if(u == -1){

            break;
        }
        visitado[u] = 1;
        cont--;
        for(int i = 0 ; i < g->grau[u] ; i++){ //vertice vizinho
            ind = g->arestas[u][i];
            if(dist[ind] < 0){
                if(g->ponderado == TRUE){
                    dist[ind] = dist[u] + g->pesos[u][i];
                    ant[ind] = u;
                }else{
                    dist[ind] = dist[u] + 1;
                    ant[ind] = u;
                }

            }else{
                if(g->ponderado == TRUE){
                    if(dist[ind] > dist[u] + g->pesos[u][i]){
                        dist[ind] = dist[u] + g->pesos[u][i];
                        ant[ind] = u;
                    }
                }else{
                    if(dist[ind] > dist[u] + 1){
                    dist[ind] = dist[u] + 1;
                    ant[ind] = u;
                }

                }
            }
        }
    }
    /*for(int i = 0 ; i < NV ; i++){
        printf("%d dist %f\n", i, dist[i]);
    }
    */

    free(visitado);

}

void algPRIM_Grafo(Grafo *g, int orig, int *pai){ // O(V^3) pois numero de arestas e pratc v^2, pior caso O(VE) pois a arvore minima é uma fila
    int dest, primeiro, NV = g->n_vertices;
    double menorPeso;
    for(int i = 0 ; i < NV ; i++){
        pai[i] = -1;

    }
    pai[orig] = orig;
    while(1){
        primeiro = 1;
        //percorre os vertices
        for(int i = 0 ; i < NV ; i++){
            //achou vertices visitados
            if(pai[i] != -1){
                //percorre vizinhos dos vertices visitados
                for(int j = 0 ; j < g->grau[i] ; j++){
                    //procura menor peso
                    if(pai[g->arestas[i][j]] == -1){

                        if(primeiro){

                            menorPeso = g->pesos[i][j];
                            orig = i;
                            dest = g->arestas[i][j];
                            primeiro = 0;
                        }else{
                            if(menorPeso > g->pesos[i][j]){
                                menorPeso = g->pesos[i][j];
                                orig = i;
                                dest = g->arestas[i][j];
                            }
                        }
                    }
                }
            }
        }

        if(primeiro == 1){
            break;
        }
        pai[dest] = orig;

    }

}
void algKruskal(Grafo *g, int orig, int *pai){
    int dest, primeiro, NV = g->n_vertices;
    double menorPeso;
    int *arv = (int*)malloc(sizeof(int)*NV);
    for(int i = 0 ; i < NV ; i++){
        arv[i] = i;
        pai[i] = -1;
    }
    pai[orig] = orig;
    while(1){
        primeiro = 1;
        for(int i = 0 ; i < NV ; i++){
            for(int j = 0 ; j < g->grau[i] ; j++){
                if(arv[i] != arv[g->arestas[i][j]]){
                    if(primeiro){
                        menorPeso = g->pesos[i][j];
                        orig = i;
                        dest = g->arestas[i][j];
                        primeiro = 0;
                    }else{
                        if(menorPeso > g->pesos[i][j]){
                            menorPeso = g->pesos[i][j];
                            orig = i;
                            dest = g->arestas[i][j];
                        }
                    }
                }
            }
        }
        if(primeiro == 1){
            break;
        }
        if(pai[orig] == -1){
            pai[orig] = dest;
        }else{
            pai[dest] = orig;
        }
        for(int i = 0 ; i < NV ; i++){
            if(arv[i] == arv[dest]){
                arv[i] = arv[orig];
            }
        }
    }
    for(int i = 0 ; i < NV ; i++){
        printf(" %c ", alpha[arv[i]]);
    }
    printf("\n");
    free(arv);

}
void Excentricidade_Max_Min(Grafo *g, int *visitado, int *ant, float *dist ){
    if(g != NULL){

        float *excentricidades = (float*)malloc(sizeof(float)*g->n_vertices); // vetor que guarda todas as excentricidades
        if(excentricidades != NULL){
            //Realiza uma busca por largura, procurando o vertice mais distante e procura o caminho mais curto até ele
            for(int i = 0 ; i < g->n_vertices ; i++){
                for(int j = 0 ; j < g->grau[i] ; j++){

                    buscaLargura_Grafo(g, i, visitado);
                    int MAX = 0, indice = 0;
                    for(int k = 0 ; k < g->n_vertices ; k++){
                        if (visitado[k] > MAX){
                            MAX = visitado[k];
                            indice = k;
                        }
                    }
                    menorCaminho_Grafo(g, i, ant, dist);
                    excentricidades[i] = dist[indice];
                }
            }
            float exe_Max = 0, exe_Min = g->n_vertices;
            for(int i = 0 ; i < g->n_vertices ; i++){
                if(g->grau[i] > 0){

                    if(excentricidades[i] > exe_Max){
                        exe_Max = excentricidades[i];
                    }else if (excentricidades[i] < exe_Min){
                        exe_Min = excentricidades[i];
                    }
                }
            }
            printf("Diametro = %f \n Raio = %f \n", exe_Max, exe_Min);
            //Diametro = excenricidade maxima de qualquer vertice
            //Raio = excentricidade minima de qualquer vertice
            return excentricidades;
        }
    }
    return NULL;
}
#endif // grafo_c
