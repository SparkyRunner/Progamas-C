#ifndef Car_h

    #define Car_h
    #include<stdlib.h>
    #include<stdio.h>

    #define TRUE 1
    #define FALSE !TRUE
    typedef struct _carro_ Carro;

    #ifdef Car_c
        void *Car_create();
        void show_car(void*elm, int n);
        int comp(Carro *c, char *marca, long int placa, int *temp);

    #endif // Car_c
#endif // Car_h
