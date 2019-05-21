#ifndef _box_h
    #define _box_h

    #include<stdio.h>
    #include<stdlib.h>

    #define TRUE 1
    #define FALSE !TRUE

    typedef struct _box_ Box;

    typedef struct _door_  Door;
    typedef struct _next_ Next;


    #ifdef _box_c

        Box *box_Create(int *aloc);
        void box_Destroy(Box *b,int *aloc);
        void box_Add(Box *b, void*elm);
        void *box_Remove(Box *b);
        void box_Show(Box *b);

    #endif // _box_c
#endif // _box_h
