#ifndef _cofo_c

    #define _cofo_c
    #include "cofo.h"

//---- Struct do cofo -------//

    typedef struct _cofo_ {
        int max;
        int nelms;
        int cur;
        int cpfCreate;
        void **elms;
    }cofo;

//--------------------------//


//-------------- Cria o cofo ------------//
    cofo *cofCreate(int n){
        cofo *c;
        if(n>0){
            c = (cofo*)malloc(sizeof(cofo));
            if(c != NULL){
                c->elms = (void**)malloc(n*sizeof(void*));
                if(c->elms != NULL){
                    c->nelms = 0;
                    c->max = n;
                    c->cur = -1;
                    printf("Sucesso 1 \n");
                    return c;
                }
            }
        }
         printf("Erro 1 \n");
         return NULL;
    }

//-----------------------------------------//


//------------------- Destroi o cofo --------------//

    int cofDestroy(cofo *c,int *aloca){
        if(c != NULL){
            if(c->nelms == 0){
                free(c->elms);
                c->nelms--;
                *aloca = 1;
                printf("Destruido com sucesso \n");
                return TRUE;
            }
        }
        printf("Inexistente ou cofo com elementos armazenados\n");
        return FALSE;
    }

//---------- Coloca elemento no cofo ---------------//

    int cofInsert(cofo *c, void *elm){
        if(c != NULL){
            if(c->nelms < c->max){
                c->elms[c->nelms] = elm;
                c->nelms++;
                printf("Sucesso \n");
                return c->nelms;
            }else{
                printf("cofo cheio, operacao nao realizada \n");
            }
        }else{
            printf("Inexistente \n");
        }
         return FALSE;
    }

//--------------------- Remove o ultimo elemento do cofo -------------------------//

    void *cofRemoveLast(cofo*c, int *car_pos){

        if(c != NULL){

            if(c->nelms > 0){
                if(*car_pos == c->nelms-1){

                    *car_pos = -1;

                }
                void *elm;
                elm = (void*)c->elms[c->nelms-1];
                c->nelms--;

                return elm;
            }else{
                printf("%d", c->nelms);
                printf("Vazio \n");
            }
        }return NULL;
    }

//----------------------- Recebe informaçoes do cofo ---------------------//

    void cofGet(cofo *c,int qtdd, int car_pos,int aloca_car, void(*show_car)(void *a,int n) ){
            printf("Tamanho cofo = %d \n Qtdd no cofo = %d \n", c->max, c->nelms);
            printf("Elementos do cofo = \n ");

            for(int i = 0 ; i < c->nelms ; i++){


                if(car_pos >= 0){
                    if(i == car_pos && aloca_car != 1 ){
                        printf(" Posicao (%d) : ",i+1);
                        show_car(c->elms[car_pos],qtdd);
                    }else if(i == car_pos){
                        printf(" Posicao (%d) = Carro \n",i+1);
                    }else{
                        printf(" Posicao (%d) : %d \n", i+1, (int) c->elms[i]);
                    }
                }else{
                    printf(" Posicao (%d) : %d \n",i+1,(int) c->elms[i]);
                }

            }
        printf(" \n");
    }

//---------Remove o primeiro do cofo --------------------//

    void *cofGetFirst(cofo *c, int *car_pos){
        if(c != NULL){
            if(c->nelms > 0){
                if(*car_pos == 0){
                    *car_pos = -1;


                }
                void *elm;
                elm = (void*)c->elms[0];
                for(int i = 0 ; i < c->nelms; i++){
                    if(*car_pos == i ){
                        *car_pos -= 1;
                    }
                    c->elms[i] = c->elms[i+1];
                }
                c->nelms--;
                return elm;
            }else{
                printf("Vazio \n");

            }
        }
       return NULL;
    }
// --------------------- Armazena uma struct qualquer no cofo ----------------------------//

     void cof_GetGen(cofo *c, void *a, int *car_pos){
        if(c!=NULL){
            c->elms[c->nelms] = a;
            if(c->elms[c->nelms] != NULL){
                int aux = c->nelms;
                c->nelms++;
                *car_pos = aux;



            }
         }else{
             printf("erro 7 \n");
             free(c->elms);
         }

     }

//---------------------- Insere dados na struct carro armazenada no cofo ---------------------------------------------//

    void cof_Inserdatacar(cofo *c,int n,int *aloca_car, int car_pos, void*(insert_datacar(void*a,int n))){
        if(c != NULL){
        insert_datacar(c->elms[car_pos],n);
        *aloca_car = 2;
        }

    }

//------------------------- Destroi struct carro ----------------//

    void car_Des(cofo *c){
        c->nelms--;
        free(c->elms);
    }

//------------------------------- Procura a marca informada na struct carro do cofo -----------------------------//

    int find_car(cofo *c, char marca[], int qtdd, int car_pos, int(show_find(void* c, char marca[],int qtdd))){
        int result;
        result = show_find(c->elms[car_pos],marca,qtdd);

        return result;
    }

#endif // _cofo_c
