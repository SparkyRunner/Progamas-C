#ifndef _funtions_c
    #define _functions_c
    #include"functions.h"

    typedef struct _lista_ {
        int max;
        int nelms;
        void **elms;
    }Lista;

    typedef struct _carro_ {
        char *marca;
        int potencia;
        int Numportas;
        float preco;
        long int placa;

    }Carro;

//--------------------- Cria Lista ------------------//

    Lista *lista_Create(int n){
        Lista *lista = (Lista*)malloc(sizeof(Lista));

        if(lista != NULL){
            lista->elms = (void**)malloc(sizeof(void*)*n);
            if(lista->elms != NULL){

                lista->max = n;
                lista->nelms = 0;
                printf(" Sucesso 1 \n");
                return lista;
            }
        }
        printf(" Erro 1 \n");

        return NULL;
    }

//----------------------- Destroi Lista ----------------------------//

    int lista_Destroy(Lista *lista, int *p){
        if(lista != NULL){
            if(lista->nelms == 0){
                free(lista->elms);
                free(lista);
                *p = 1;
                printf(" Sucesso  2\n");
                return TRUE;
            }



        }
        printf("Lista inexistente ou com elementos \n");


        return FALSE;
    }

//---------------------------- Inserir dados T na lista --------------------//

    int Lista_dataInsert(Lista *lista){
        if(lista != NULL){


                if(lista->nelms < lista->max){
                    lista->elms[lista->nelms] = car_Create();

                    if(lista->elms[lista->nelms] != NULL){
                        lista->nelms++;
                        printf("Sucesso 2");
                        return TRUE;
                    }else{
                        printf("Falha criacao carro \n");
                    }
                }else{
                    printf(" Lista cheia \n");
                }


        }else{
            printf("lista inexistente \n");
        }
        return FALSE;
    }

//------------------ Consulta T com F  -----------------------//

    void Lista_Search(Lista *lista, char marca[], long int placa){
        if(lista != NULL){
            if(lista->nelms > 0){
                for(int i = 0 ; i < lista->nelms ; i++){
                    Carro *p = (Carro*)lista->elms[i];
                    if(p != NULL){
                        if(strcmp(p->marca,marca) == 0 && placa == p->placa){
                            printf("Posicao (%d) \n Marca = %s \n Potencia = %d \n NumPortas = %d \n Preco = %f \n Placa = %li \n",i, p->marca, p->potencia,p->Numportas, p->preco, p->placa );

                        }
                    }else{
                        printf("Erro na posicao %d \n", i);
                    }
                }
            }else{
                printf(" Lista vazia \n");
            }
        }else{
            printf("Lista inexistente \n");
        }
    }

//--------------------- Remover T com F --------------------------//


    void Lista_Remove(Lista *lista, char marca[], long int placa){
        if(lista != NULL){
            if(lista->nelms > 0){
                for(int i = 0 ; i < lista->nelms ; i++){
                    Carro *p = (Carro*)lista->elms[i];
                    if(p != NULL){
                        if(strcmp(p->marca,marca) == 0 && placa == p->placa){


                             for(int j = i ; j < lista->nelms ; j++){
                                lista->elms[j] = lista->elms[j+1];

                             }
                             lista->nelms--;
                             printf("Sucesso \n");
                             free(p->marca);
                            free(p);

                        }
                    }else{
                        printf(" Erro na posicao %d \n", i);
                    }
                }
            }else{
                printf(" Lista vazia \n");
            }
        }else{
            printf(" Lista inexistente \n");
        }
    }

//----------------------- Listar elementos da lista ------------------------------//

    void show_List(Lista *lista){
        if(lista != NULL){
            if(lista->nelms > 0){
                Carro *p;
                for(int i = 0; i < lista -> nelms ; i++){

                    p = (Carro*)lista->elms[i];
                    printf("--------------------------------------------------\n");
                    printf(" Posicao (%d) \n Marca = %s \n Potencia = %d \n NumPortas = %d \n Preco = %f, Placa = %li \n",i+1, p->marca, p->potencia,p->Numportas, p->preco, p->placa );
                    printf("---------------------------------------------------\n");
                }
            }else{
                printf(" Lista vazia \n");
            }
        }else{
            printf(" Lista inexistente \n");
        }
    }

//--------------------------- Cria dados carro -----------------------------------//

    void *car_Create(){

        Carro *p = (Carro*)malloc(sizeof(Carro));
        p->marca = (char*)malloc(20*sizeof(char));
                if(p != NULL){
                    if(p->marca != NULL){
                        printf(" Marca = ");
                        fflush(stdin);
                        char marca[20];
                        scanf("%s", &marca);

                        strcpy(p->marca,marca);







                        printf("\n Potencia = ");
                        fflush(stdin);
                        scanf("%d", &p->potencia);
                        printf("\n NumPortas = ");
                        fflush(stdin);
                        scanf("%d",&p->Numportas);
                        printf("\n Preco = ");
                        fflush(stdin);
                        scanf("%f", &p->preco);
                        printf("\n Placa = ");
                        fflush(stdin);
                        scanf("%li", &p->placa);



                    return p;
                }
            }
            return NULL;

    }
    void mostra(Lista *lista){


            if(lista->nelms > 0){
                printf(" Tamanho da lista  = %d \n Elementos na lista =  \n", lista->max, lista->nelms);

                for(int i = 0 ; i < lista->nelms; i++){

                    printf("---------------Posicao (%d)------------------\n ",i+1);
                    Carro *p;
                    p = (Carro*)lista->elms[i];
                    printf("\nMarca = %s \n", p->marca);

                    printf("Potencia = %d \n", p->potencia);
                    printf("Portas = %d \n", p->Numportas);
                    printf("Preco = %f \n", p->preco);
                    printf("Placa = %li \n", p->placa);
                    printf("--------------------------------------------\n");
                }
            }else{

                printf(" Tamanho da lista  = %d \n Elementos na lista =  \n", lista->max, lista->nelms);
            }

    }

#endif // _funtions_c
