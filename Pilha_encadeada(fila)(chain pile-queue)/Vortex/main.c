#include"encad.h"
#include"box.h"
int main()
{
    int aloca = 0;
    Box *b;
    int loop = TRUE;
    while(loop == TRUE){
        printf(" a)Box create \n b)Box destroy \n c)Add  encad   \n d)Remove last \n e)Show all  \n f)exit \nopt = ");
        char opt;
        scanf("%c", &opt);

        if(opt == 'a'){
            if(aloca == 0){
            b = box_Create(&aloca);
            }else{
                printf("box already exists");
            }
        }

        if(opt == 'b'){
            if(aloca > 0){
                box_Destroy(b,&aloca);
            }else{
                printf("box doesnt exist \n");
            }
        }

        if(opt == 'c'){
            if(aloca > 0){
                int n;
                printf("input the element  = ");
                scanf("%d", &n);

                box_Add(b, n);
            }else{
                printf("box doesnt exist \n");
            }
        }


        if(opt == 'd'){
            if(aloca > 0){
                void *aux = box_Remove(b);
            }else{
                printf("box doesnt exist \n");
            }
        }

        if(opt == 'e'){
            if(aloca > 0){
                box_Show(b);
            }else{
                printf("box doesnt exist \n");
            }
        }

        if(opt == 'f'){

            loop = FALSE;
        }
        system("PAUSE");
        system("cls");

    }

    return 0;
}
