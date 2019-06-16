
#ifndef _pilha_h

    #define _pilha_h

    #define TRUE (1==1)
    #define FALSE (!TRUE)

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>



    typedef struct _pilha_  Stack;

    #ifdef _pilha_c
        Stack *stkCreate(int n);
        int stkDestroy(Stack *s);
        int stkPush(Stack *s, void *elm);
        void *stkPop(Stack *s);
        void stkGet(Stack *s);
        void p(Stack *s);
        int stkEmpty(Stack *s);
        void ePalindromo(char *s, int n);
        Stack *stkDouble_Create(int n, int *check);
        int stkD_Push1(Stack *q, void*n);
        int stkD_Push2(Stack *q, void*n);
        void*stkD_Pop1(Stack*q);
        void*stkD_Pop2(Stack *q);
        void stkD_Destroy(Stack *q);

    #endif // _pilha_c


#endif // _pilha_h

