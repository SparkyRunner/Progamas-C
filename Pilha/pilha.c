#ifndef _pilha_c
    #define _pilha_c

    #include"pilha.h"

    typedef struct _pilha_ {
        int top;
        int top2;
        int maxelms;
        void **elms;

    }Stack;

    Stack *stkCreate(int n){ //------------------------------------------------------------------------------------------
        Stack *s ;

        if (n>0){
            s =(Stack*)malloc(sizeof(Stack));
            if(s != NULL){
                s->top = -1;
                s->maxelms = n;
                s->elms = (void**)malloc(sizeof(void*));
                printf("Sucesso 1 \n");
                return s;
            }
        }
        printf("Erro 1 \n");
        return NULL;
    }


    int stkDestroy(Stack *s){ //------------------------------------------------------------------------------------------
        if(s != NULL){
            if(s->top < 0){
                free(s->elms);
                free(s);
                return TRUE;
            }

        }
        printf("ainda ha elementos na pilha \n");
        return FALSE;
    }

    int stkPush(Stack *s, void *elm){ //------------------------------------------------------------------------------------
        if(s != NULL){
            if(s->top < s->maxelms -1){

                s->top++;


                s->elms[s->top] = elm;
                return TRUE;
            }

        }
        printf("Overflow \n");
        return FALSE;
    }
    void *stkPop(Stack *s){ //----------------------------------------------------------------------------
        void *elm;
        if(s != NULL){
            if(s->top >= 0){
                 s->elms[s->top];
                s->top--;

                return elm;
            }
        }
        printf("Underflow \n");
        return NULL;
    }

    void stkGet(Stack *s){ //---------------------------------------------------------------------------

        for(int i = s->top ; i >= 0 ; i--){
            printf(" | %c | \n",(char) s->elms[i]);
        }
    }

    int stkEmpty(Stack *s){ //----------------------------------------------------------------------
        if(s != NULL){
            if(s->top < 0){
                return TRUE;
            }
        }
        return FALSE;
    }

     void ePalindromo(char *str, int n){ //------------------------------------------------------
        Stack *s ;

        s = stkCreate(n);
        char original[n];

        if(s != NULL){
            for(int i = 0 ; i < n ;i++){
                stkPush(s,(void*)str[i]);
                printf("%c", (char)s->elms[s->top]);
                original[i] = str[i];
            }

            char invertido[n];
            for (int i = 0 ; i < n ; i++){
                invertido[i] = stkPop(s);
                printf("%c",invertido[i]);
            }

            if(strcmp(original,invertido) == 0 ){
                printf("Palindromo \n");
            }else{
                printf("Nope \n");
            }


        }
        free(s);
     }
//---------------------- Pilha dupla -------------------------------------------------------------------//




    Stack *stkDouble_Create(int n, int*check){ //-------------------------------------------------------------------
        Stack *p = (Stack*)malloc(sizeof(Stack));
        if(p != NULL){
            p->elms = (void**)malloc(sizeof(Stack*)*n);
            if(p->elms != NULL){
                p->top = -1;
                p->top2 = n;
                p->maxelms = n;
                *check += 1;
                printf("sucesso criacao \n");
                return p;
            }else{
                printf("Erro alocacao elms de p \n");
            }
        }else{
            printf("Erro alocacao \n");
        }
        return NULL;
    }

    int stkD_Push1(Stack *q, void* n){ //--------------------------------------------------------------------
        if(q != NULL){
            if(q->top == q->top2-1){
                printf("OverFlow \n");
            }else{
                q->top++;
                q->elms[q->top] = n;
                return TRUE;
            }
        }else{
            printf("Erro Push1\n");
        }
        return FALSE;
    }
   int stkD_Push2(Stack *q, void*n){ //---------------------------------------------------------------------------------
        if(q != NULL){
            if(q->top == q->top2-1){
                printf("OverFlow \n");
            }else{
                q->top2--;
                q->elms[q->top2] = n;
                return TRUE;
            }
        }else{
            printf("Erro Push2 \n");
        }
            return FALSE;


    }

    void *stkD_Pop1(Stack *q){ //---------------------------------------------------------------------
        if(q != NULL){
            if(q->top >= 0){
                void* p = q->elms[q->top];
                q->top--;
            }else{
                printf("Underflow \n");
            }
        }else{
            printf("Erro pop 1 \n");
        }
            return NULL;
    }
    void *stkD_Pop2(Stack *q){ //----------------------------------------------------------------------
        if(q != NULL ){
            if(q->top2 <= q->maxelms-1){
                void* p = q->elms[q->top2];
                q->top2++;
            }else{
                printf("Underflow \n");
            }
        }else{
            printf("Erro pop 2 \n");
        }
            return NULL;
    }

    void stkD_Destroy(Stack *q){ //----------------------------------------------------------------
        if(q != NULL){
            if(q->elms != NULL){
                free(q->elms);
            }
            free(q);
        }
    }
    void stkDGet(Stack *q){ //------------------------------------------------------------------------


        if(q->top == -1 && q->top2 == q->maxelms){
            printf("Pilha vazia \n");
        }else if(q->top >=0 && q->top2 == q->maxelms){
            for(int i = q->top ; i >= 0 ; i--){
                if(i == q->top){
                    printf("Posicao (%d) = %d    <---- top \n", i+1,(int)q->elms[i]);
                }else{
                    printf("Posicao (%d) = %d \n", i+1, (int)q->elms[i]);
                }
            }
        }else if(q->top >= 0 && q->top2 <= q->maxelms-1){
            for(int i = q->maxelms-1 ; i >= q->top2 ; i--){
                if(i == q->top2){
                    printf("Posicao (%d) = %d    <---- top2 \n", i+1,(int)q->elms[i]);
                }else{
                    printf("Posicao (%d) = %d \n", i+1, (int)q->elms[i]);
                }
            }
            for(int i = q->top ; i >= 0 ; i--){
                if(i == q->top){
                    printf("Posicao (%d) = %d    <---- top1 \n", i+1,(int)q->elms[i]);
                }else{
                    printf("Posicao (%d) = %d \n", i+1, (int)q->elms[i]);
                }
            }
        }else if(q->top < 0 && q->top2 <= q->maxelms-1 ){
            for(int i = q->top ; i >= 0 ; i--){
                if(i == q->top){
                    printf("Posicao (%d) = %d    <---- top1 \n", i+1,(int)q->elms[i]);
                }else{
                    printf("Posicao (%d) = %d \n", i+1, (int)q->elms[i]);
                }
            }
        }

    }


#endif // _pilha_c


