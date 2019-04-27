#include"functions.h"


int main()
{
    int loop = TRUE;
    int aloca1 = 1;


    Lista *lista;

    while(loop == TRUE){
        system("CLS");

        char opt;

        printf("-----------------------------Lista Manage ------------------------------- \n");
        printf(" a) Cria lista \n b) Destroi lista \n c) Inserir dados T \n d) Consultar estrutura T \n e) Remover estrutura T \n f) Listar estruturas \n g) Sair \n");

        if(aloca1 == 2){
            mostra(lista);
        }

        fflush(stdin);
        scanf("%c", &opt);


        if(opt == 'a'){
            if(aloca1 == 1){
                int n;
                printf(" Informe quantidade de elementos da lista \n ");

                fflush(stdin);
                scanf("%d", &n);
                if(aloca1 == 1){
                    lista = lista_Create(n);
                    aloca1++;
                }else{
                    printf(" Lista ja existe \n");
                }
            }else{
                printf("Lista ja existe \n");
            }



        }

        if(opt == 'b'){

            if(aloca1 == 2){
                lista_Destroy(lista, &aloca1);

            }else{

                printf(" Lista nao existe \n");
            }



        }

        if(opt == 'c'){
            if(aloca1 == 2){


                Lista_dataInsert(lista);






            }else{
                printf(" Lista inexistente \n");
            }
        }

        if(opt == 'd'){
            if(aloca1 == 2){
                char p[20];
                long int placa;
                printf(" Informe a marca = ");
                scanf("%s", &p);
                printf("\n Informe a placa =  ");
                scanf("%li", &placa);
                int cont = 0;
                for(int i = 0 ; p[i] != '\0' ; i++){
                    cont++;
                }
                char marca[cont];

                strcpy(marca,p);

                 Lista_Search(lista,marca, placa);
            }else{
                printf(" Lista ou Estrutura nao existente \n");
            }




        }

        if(opt == 'e'){
            if(aloca1 == 2){
                char p[20];
                long int placa;
                printf(" Informe a marca = ");
                scanf("%s", &p);
                printf("\n Informe a placa =  ");
                scanf("%li", &placa);
                int cont = 0;
                for(int i = 0 ; p[i] != '\0' ; i++){
                    cont++;
                }
                char marca[cont];

                strcpy(marca,p);

                Lista_Remove(lista,marca,placa);
            }else{
                printf(" Lista inexistente \n");
            }

        }

        if(opt == 'f'){
            show_List(lista);
        }

        if(opt == 'g'){
            loop = FALSE;
        }

       getch();
        int clrscr();

    }
    free(lista);
    return 0;
}
