#include"box.h"
#ifndef _box_c
    #define _box_c
        typedef struct _box_{
        int nelms;
        void **elms;

    }Box;


    Box *box_Create(int *aloc){
        Box *b = (Box*)malloc(sizeof(Box));

        if(b != NULL){
            b->elms = (void**)malloc(sizeof(void*));
            if(b->elms != NULL){
                b->nelms = 0;
                *aloc = 1;
                b->elms = (void*)encad_Create();
                printf(" box created\n");
                return b;
            }
        }
        printf("fail box create \n");
        return NULL;
    }

    void box_Destroy(Box *b, int *aloc){
        if(b->nelms == 0){
            encad_Destroy(b->elms);
            free(b->elms);
            free(b);
            *aloc = 0;
            printf("sucess box destroy \n");
        }else{
            printf("still have elms \n");
        }
    }

    void box_Add(Box *b, void *elms){
        if(b != NULL){
            if(b->elms != NULL){
                if(b->nelms == 0){
                    if(encad_add_first(b->elms, elms) == TRUE){

                        b->nelms++;
                    }else{
                        printf("fail encad_add_first \n");
                    }
                }else{
                    if(encad_add_next(b->elms, elms) == TRUE){
                            b->nelms++;

                    }else{
                        printf("fail encad_add_next");
                    }
                }


            }else{
            printf("elms doesnt exist \n");
            }

        }else{
            printf(" box doesnt exist \n");
        }
    }
    void *box_Remove(Box *b){
        if(b->nelms > 0){
            void *aux;
            Door *d = b->elms;

            aux = encad_remove(d);
            b->nelms--;
            return aux;

        }else{
            printf("Void \n");
            return NULL;
        }
    }

    void box_Show(Box *b){

        Door *d = (Door*)b->elms;
        printf("---------------------------\n elms = %d \n", b->nelms);
         encad_Show(d);
    }



#endif // _box_c

