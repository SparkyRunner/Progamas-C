#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Grafos.h"
#include <time.h>
int main()
{
// Le o arquivo , a primeira linha informa , numero de vertices
// Segunda linha : se é ponderado ou nao, grau maximo
// as seguintes linhas contem : vertice origem, vertice destino, o peso e se é digrafo
    char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'W', 'Z'};

    clock_t tInicio, tFim, tRes; // timer
    FILE *arq;
    Grafo *g;
    int n;// pega a quantidade de vertices
    int grau; // pega a quantidade maxima de graus
    char ponderado;
    arq = fopen("grafos.txt","r");

    char aux[10];
    int first = 0;
    while(fgets(aux, 20,arq) != NULL){

      char tmp[20];

            if(first == 0){ // Primeira linha, pega a quantidade de vertices
                n = atoi(aux);



                first++;
            }else if(first == 1){ // Segunda linha, pega se é ponderado ou nao
                 if(aux[0] == 't'){
                    ponderado = 't';
                }else{
                    ponderado = 'f';
                }
                first++;

            }else if(first == 2){// Terceira linha, pega a quantidade de grau maximo
                grau = atoi(aux);
                if(ponderado == 't'){
                    g = cria_grafo(n, grau, TRUE);
                }else if (ponderado == 'f'){
                    g = cria_grafo(n, grau, FALSE);
                }

                first++;
            }else{ // Seguintes linhas : adiciona grafos
                char numb_aux[4], cont = 0;
                int orig = -1 , dest = -1 , peso = -1 ;
                for(int i = 0 ; i < strlen(aux) ; i++){ // cria string auxiliar para pegar os numeros para converter em int
                    if(orig == -1){
                        if(aux[i] != ' '){
                            numb_aux[cont] = aux[i];
                            cont++;
                        }else{
                            numb_aux[cont] = '\0';
                            cont = 0;
                            orig = atoi(numb_aux);
                        }
                    }
                    else if(dest == -1){
                        if(aux[i] != ' '){
                            numb_aux[cont] = aux[i];
                            cont++;
                        }else{
                            numb_aux[cont] = '\0';
                            cont = 0;
                            dest = atoi(numb_aux);
                        }
                    }
                    else if(peso == -1){
                        if(aux[i] != ' '){
                            numb_aux[cont] = aux[i];

                            cont++;
                        }else{
                            numb_aux[cont] = '\0';
                            cont = 0;
                            peso = atoi(numb_aux);

                        }
                    }

                }

                numb_aux[cont] = '\0';
                cont = 0;
                peso = atoi(numb_aux);

                insereAresta(g, orig, dest, TRUE, peso); // TRUE = deixa o grafo  não direcionado

            }

    }

    fclose(arq);

    /*int n = 11;
    Grafo *g = cria_grafo(n, 2, TRUE);
    insereAresta(g, 2, 6, FALSE, 3);
    insereAresta(g,2, 7, FALSE, 1);
    insereAresta(g,6, 3, FALSE, 3);
    insereAresta(g,6, 10, FALSE, 4);
    insereAresta(g,10, 4, FALSE, 5);
    insereAresta(g,7, 4, FALSE, 2);
    insereAresta(g,10, 9, FALSE, 4);
    insereAresta(g,4, 9, FALSE, 10);
    */
    int flag = TRUE;
    while(flag){
        Lista_grafo(g);
        //int pai[n];
        //algKruskal(g, 2, pai);
        char opt = NULL;
        int orig, dest;
        int visitado[n]; // vetor que auxilia na busca
        int ant[n]; // vetor que seta os vertices anteriores
        float dist[n]; // vetor que guarda a menor distancia de cada vertice a partir de um inicial
        int pai[n]; // vetor para arvore geradora minima
        int limit; // variavel auxiliar para Km
        printf("-----------------Grafos--------------- \n");
        printf("a)Grafo em forma de matriz \n");
        printf("b) Grafo em forma de lista\n");
        printf("c)Lista de adjacencia na ordem inversa \n");
        printf("d)Arestas existentes entre origem e destino \n");
        printf("e) Excentricidade \n");
        printf("f) Excentricidade maxima e minima \n");
        printf("g) Prim \n");
        printf("h) Kruskal \n");
        printf("i)Vertices dentro de um raio em km \n");
        printf("j)Sair\n");
        printf("Opt = ");
        scanf("%c",&opt);
        if(opt != NULL){
            switch(opt){
                case 'a':
                    tInicio = clock();

                    Matriz_grafo(g);

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);

                    system("PAUSE");
                break;
                case 'b':
                    tInicio = clock();

                    Lista_grafo(g);

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");
                break;

                case 'c':
                    tInicio = clock();

                    Lista_grafo_inversa(g);

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");
                break;
                case 'd':
                    printf("Informe a origem \n");
                    printf("orig = ");
                    scanf("%d", &orig);
                    printf("Informe o destino \n");
                    printf("orig = ");
                    scanf("%d", &dest);

                    tInicio = clock();

                    buscaLargura_Grafo(g, orig, visitado);
                    if(visitado[dest] % 2 == 0){ // se os numero de vertices for par, o numero de arestas é a metade
                        printf("Arestas entre %c e %c = %d\n", alpha[orig], alpha[dest], ((visitado[dest])/2));
                    }
                    else{ // se for impar, o numero de arestas é = floor((vertices/2) + 1)
                        printf("Arestas entre %c e %c = %2.f\n", alpha[orig], alpha[dest], floor(((visitado[dest])/2)+1));
                    }

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");

                break;
                case 'e':
                    printf("Informe a origem \n");
                    printf("orig = ");
                    scanf("%d", &orig);

                    tInicio = clock();
                    buscaLargura_Grafo(g, orig, visitado); // Procura o mais distante e armazena seus dados
                    int MAX = 0, indice = 0;
                    for(int i = 0 ; i < n ; i++){
                        if (visitado[i] > MAX){
                            MAX = visitado[i];
                            indice = i;
                        }
                    }
                    menorCaminho_Grafo(g, orig, ant, dist); // Procura o menor caminho e mostra o resultado para o mais distante
                    printf("Mais longo = vertice %c , distancia = %d \n", alpha[indice], MAX);
                    printf("Menor caminho ate o vertice mais longo = %f \n", dist[indice]);

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");
                break;
                case 'f':
                    tInicio = clock();

                    Excentricidade_Max_Min(g, visitado, ant, dist);

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");
                break;
                case 'g':
                    printf("Informe a origem \n");
                    printf("orig = ");
                    scanf("%d", &orig);
                    tInicio = clock();

                    algPRIM_Grafo(g, orig, pai);
                    for(int i = 0 ; i < n ; i++){
                        if(pai[i] >= 0){
                        printf("%c pai %c \n", alpha[i], alpha[pai[i]]);
                        }
                    }
                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");
                break;
                case 'h':
                    printf("Informe a origem \n");
                    printf("orig = ");
                    scanf("%d", &orig);
                    tInicio = clock();

                    algKruskal(g, orig, pai);

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");
                break;
                case 'i':
                    printf("Informe a origem \n");
                    printf("orig = ");
                    scanf("%d", &orig);
                    printf("informe o limite (km)\n");
                    scanf("%d", &limit);

                    tInicio = clock();

                    buscaLargura_Grafo(g, orig, visitado);
                    printf("Vertices dentro da area : \n");
                    for(int i = 0 ; i < n ; i++){
                        if(visitado[i]-1 <= limit && visitado[i] > 0 ){
                            printf("%c distancia %d km \n", alpha[i],  visitado[i]-1);
                        }
                    }

                    tFim = clock();
                    tRes = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nTempo = %d \n", tRes);
                    system("PAUSE");

                break;
                case 'j':
                    flag = FALSE;
                break;
                default:
                break;
            }

        }
        system("cls");


    }
    Deleta_grafo(g);

    /*int visitado[11];
    printf("Largura \n");
    buscaLargura_Grafo(g, 2, visitado);
    printf("Profundidade \n");
    buscaProfundidade_Grafo(g, 2, visitado);
    for(int i = 0 ; i < 11 ; i++){
        if(visitado[i] > 0){
        printf("Distancia minima de %d ate %d = %d \n", 2, i,visitado[i]);
        }
    }
    int dist[11];
    int ant[11];

    menorCaminho_Grafo(g, 2, ant, dist);

    int pai[11];
    algPRIM_Grafo(g, 2, pai);
    for(int i = 0 ; i < 11 ; i++){
        printf("pai[%d] = %d \n",i,  pai[i]);
    }
    Deleta_grafo(g);
    */

    return 0;
}
