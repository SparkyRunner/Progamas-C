#ifndef _functions_h
    #define _functions_h
    #define TRUE 1
    #define FALSE !TRUE



    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    #include<conio.h>
    typedef struct _lista_ Lista;
    typedef struct _carro_ Carro;

    #ifdef _functions_c

        Lista *lista_Create(int n);
        int lista_Destroy(Lista *lista, int*p);
        int Lista_dataInsert(Lista *lista);
        void Lista_Search(Lista *lista, char marca[], long int placa);
        void Lista_Remove(Lista *lista, char marca[], long int placa);
        void show_List(Lista *lista);
        void *car_Create();
        void mostra(Lista *lista);
    #endif // _functions_c


#endif // _functions_h

