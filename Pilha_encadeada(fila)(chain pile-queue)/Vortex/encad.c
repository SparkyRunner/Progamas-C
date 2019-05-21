#include"encad.h"
#ifndef _encad_c
    #define _encad_c

    typedef struct _next_{
        struct _next_ *next;
        void *data;
    }Next;
    typedef struct _door_ {
        Next *first;

    }Door;

    Door *encad_Create(){
        Door *p = (Door*)malloc(sizeof(Door));

        if(p != NULL){
            p->first = NULL;

            return p;

        }
        printf("fail encad create \n");
    }

    void encad_Destroy(Door *d){
        if(d->first == NULL){
            free(d);
        }else{
            printf("still have elms \n");
        }
    }

    int  encad_add_first (Door *d, void*elms){
        if(d != NULL){

            Next *newbie = (Next*)malloc(sizeof(Next));
            if(newbie != NULL){

                newbie->data = elms;
                newbie->next = d->first;
                d->first = newbie;






                return TRUE;
            }

        }
        printf("List doesnt exist \n");
        return FALSE;
    }

    void *encad_remove(Door *d){
        if(d != NULL){
            void *aux;
            Next *temp, *temp2;
            temp = d->first;

            if(temp->next == NULL){
                aux = temp->data;
                free(temp);
                d->first = NULL;
                return aux;

            }

            for( temp ; temp->next != NULL ;temp = temp ->next){
                temp2 = temp;
            }
            temp2->next = NULL;
            aux = temp->data;


            free(temp);


            return aux;

        }
        return NULL;
    }

    void encad_Show(Door *d){

        if(d->first != NULL){
        Next *p = d->first;
        int cont = 0;
        for(p ; p != NULL ; p = p->next){
            printf(" %d -> %d \n",cont+1, p->data);
            cont++;
        }

        printf("-------------------------------\n");
        }else{
            printf("Void \n");
            printf("-------------------------------\n");
        }

    }

    int encad_add_next(Door *d, void*elm){
        if(d != NULL){

            Next *newbie = (Next*)malloc(sizeof(Next));

            if(newbie != NULL){
                newbie->data = elm;
                Next *n = d->first;

                for(n; n->next != NULL ; n = n->next){

                }
                if(n->next == NULL){
                    newbie->next = n->next;
                    n->next = newbie;

                    return TRUE;
                }else{
                    printf("ue");
                }
            }
        }
        return FALSE;
    }

#endif // _encad_c

