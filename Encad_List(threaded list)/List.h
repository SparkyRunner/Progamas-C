
    #ifndef List_h

        #define List_h

        #include<stdlib.h>
        #include<stdio.h>
        #define TRUE 1
        #define FALSE !TRUE


        typedef struct Next_ Next;
        typedef struct List_ List;
        #ifdef List_c

            List *List_Create();
            int List_Dex(List *l, int *n);
            int add_List(List *l, int *n);
            int remove_List(List *l,char *marca, long int placa);
            void List_show_spec(List *l, char *marca, long int placa);
            void List_show_all(List *l);


        #endif // List_c
    #endif // List_h

