#ifndef _cofo_h

#define _cofo_h
#define TRUE (1==1)
#define FALSE (!TRUE)

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct _cofo_ cofo;


    #ifdef _cofo_c
//----------------------------------( cria cofo )------------------------------------------------------//

        cofo *cofCreate(int n);

//-----------------------------( coloca elemento no cofo )---------------------------------------------//

        int cofInsert(cofo *c, void*elm);

//-----------------------------( remove ultimo elemento )----------------------------------------------//

        void *cofRemoveLast(cofo *c, int*car_pos);

//------------------------------( destroi cofo )-------------------------------------------------------//

        int cofDestroy(cofo *c, int *aloca);


//------------------------------( pega dados do cofo )------------------------------------------------//

        void cofGet(cofo *c,int qtdd, int car_pos,int aloca_car,void(*show_car)(void *a,int n) );


//-----------------------------( remove o primeiro elemento do cofo )----------------------------------//

        void *cofGetFirst(cofo *c, int *car_pos);



//--------------------------------( insere struct carro no cofo )---------------------------------------//

        void cof_GetGen(cofo *c, void*a, int*car_pos);

//------------------------------( insere dados do tipo carro no cofo )----------------------------------//

        void cof_Inserdatacar(cofo *c,int n,int *aloca_car, int car_pos, void*(insert_datacar(void*a, int n)));

//--------------------------------( Destroi carros )-----------------------------------------------------//
        void car_Des(cofo *c);


//--------------------------------( Procura carros )-----------------------------------------------------//
        int find_car(cofo *c, char marca[], int qtdd, int car_pos, int(show_find(void* c, char marca[],int qtdd)));

    #endif // _cofo_c


#endif // _cofo_h
