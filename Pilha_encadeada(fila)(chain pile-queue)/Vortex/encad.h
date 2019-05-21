#ifndef _encad_h
    #define _encad_h

    #include<stdio.h>
    #include<stdlib.h>

    #define TRUE 1
    #define FALSE !TRUE


    typedef struct _door_  Door;
    typedef struct _next_ Next;

    typedef struct _next_ *last;
    #ifdef _encad_c

        Door *encad_Create();
        void encad_Destroy(Door *d);
        void encad_add_first(Door *d, void *elm);
        void *encad_remove(Door *d);
        void encad_show(Door *d);
         int encad_add_next(Door *d, void*elm);


    #endif // _encad_c
#endif // _encad_h
