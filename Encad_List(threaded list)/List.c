
    #ifndef List_c
        #define List_c

        #include"List.h"
        //-------------------------------------------------------------------------------//
    typedef struct Next_{
        struct Next_ *next;
        void **data;
    }Next;

    typedef struct List_{
        int nelms;
        Next *first;
        Next *last;
    }List;
//-------------------------------------------------------------------------------//
    List *List_Create(){
       List *l = (List*)malloc(sizeof(List));

       if(l != NULL){
            l->nelms = 0;
            l->first = NULL;
            l->last = NULL;
            return l;

       }

    }
//-------------------------------------------------------------------------------//
    int List_Dex(List *l, int*n ){
        if(l != NULL){
            if(l->nelms == 0 && l->first == NULL && l->last == NULL){
                free(l);
                *n = 1;
                printf("Sucess \n");
                return TRUE;
            }else{
                printf("Already have elms");
            }
        }
        printf("error dex");
        return FALSE;
    }
//---------------------------------------------------------------------------------//

    int add_List(List *l, int *aloca2){
        if(l != NULL){
            Next *n = (Next*)malloc(sizeof(Next));
            if(n != NULL){

                if(n->data != NULL){
                    n->data = car_Create();
                    n->next = NULL;
                    if(l->first == NULL){
                        l->first = n;
                        l->last = l->first;
                        l->nelms++;
                        *aloca2 = 2;
                        return TRUE;
                    }else{
                        Next *aux ;

                        aux = l->last;
                        aux->next = n;
                        l->last = n;
                        l->nelms++;
                        *aloca2 = 2;
                        return TRUE;


                    }
                }else{
                    printf("Error malloc2");
                }
            }else{
                printf("Error malloc 1");
            }

        }
        printf("List doesnt exists");
        return FALSE;
    }
//---------------------------------------------------------------------//
    int remove_List(List *l, char *marca, long int placa){
        if(l!= NULL){

            Next *aux = l->first;
            Next *aux2;
            int temp = 0;

                while(comp(aux->data,marca,placa, &temp)!= TRUE && aux->next != NULL){
                    aux2 = aux;
                    aux = aux->next;
                }

                if(temp == 1){
                    if(aux != l->first){

                        aux2->next = aux->next;
                        if(aux2->next == NULL){
                            l->last = aux2;
                        }
                        free(aux->data);
                        free(aux);
                        l->nelms--;
                        return TRUE;
                    }else{
                        aux2 = aux->next;
                        l->last = aux2;
                        free(aux->data);
                        free(aux);
                        l->first =aux2;
                        l->nelms--;
                        return TRUE;
                    }
                }else{
                    printf("Car not found");
                }


        }
            return FALSE;
    }


//-----------------------------------------------------------//

    void List_show_spec(List *l, char *marca, long int placa){
        if(l != NULL){
            Next *aux = l->first;
            int cont = 1;
            int temp = 0;
            if(aux != NULL){

                while(comp(aux->data,marca,placa, &temp) != TRUE && aux ->next != NULL){
                    aux = aux->next;
                    cont++;
                }
                    if(temp == 1){
                    show_Car(aux->data, cont);
                    }else{
                    printf("Car not found \n");
                    }
            }else{
                printf("Void List \n");
            }


        }
    }
    void List_show_all(List *l){
        if(l != NULL){
            Next *aux = l->first;
            int cont = 1;
            if(aux != NULL){
                while(aux->next != NULL){
                    show_Car(aux->data,cont);
                    aux = aux->next;
                    cont++;
                }
                show_Car(aux->data,cont);
            }else{
                printf("Void List \n");
                printf("Elms = %d \n", l->nelms);
            }

        }
    }

    #endif // List_c

