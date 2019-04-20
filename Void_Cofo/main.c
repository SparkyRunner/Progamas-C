
#include"cofo.h"
                                    // Struct carro //
//----------------------------------------------------------------------------------------------------//
typedef struct carro{
    char *marca;
    int potencia;
    int num_portas;
    float preco;
    long int placa;
}Carro;

//----------------------------------------------------------------------------------------------------//


                // Funçao para ver se o elemento informado é encontrado no cofo //

//----------------------------------------------------------------------------------------------------//
 int cmp(void *a, void *b){

        if(a == b){

            return TRUE;

        }

    return FALSE;
 }
 //----------------------------------------------------------------------------------------------------//



                    // Preenche a struct Carro armazenada no cofo e mostra //

//----------------------------------------------------------------------------------------------------//

 void show_car(void*c,int n){

    if (c != NULL){

        Carro *pcar = (Carro*)c;
        for(int j = 0 ; j < n ; j++){
            printf("Marca = ");

            printf("%s", pcar[j].marca);

            printf(" - Potencia = %d", (int)pcar[j].potencia);
            printf(" - num portas = %d", (int)pcar[j].num_portas);
            printf(" - preco = %f", (float)pcar[j].preco);
            printf(" - placa = %li \n", pcar[j].placa);
        }
    }

 }
//----------------------------------------------------------------------------------------------------//



                    // Insere dados na struct Carro armazenada no cofo //

//----------------------------------------------------------------------------------------------------//

 void* insert_datacar(void*c,int n){
                                                        //----Pega ponteiro void do cofo e coloca em ponteiro Carro, insere dados e retorna as alteraçoes em ponteiro void para o cofo ------//
    if(c!= NULL){
        Carro *pcar = (Carro*)c;

        for(int j = 0 ; j < n ; j++){

            printf("Informa a marca = ");

            char word[20];
            scanf("%s", &word);                              // aloca 20 posicoes para c-> marca, cria uma string e copiar oq foi armazenado nela posiçao por posiçao para c->marca
            int aux ;


                strcpy(pcar[j].marca,word);








            printf("\n potencia = ");
            scanf("%d", &pcar[j].potencia);
            printf("\n numero de portas = ");
            scanf("%d", &pcar[j].num_portas);
            printf("\n Preco = ");
            scanf("%f", &pcar[j].preco);
            printf("\n placa = ");
            scanf("%ld", &pcar[j].placa);
        }
            return pcar;
    }
    return NULL;
 }
                            //--- Procura a marca encontrada na struct carro do cofo --- //
//----------------------------------------------------------------------------------------------------//

    int show_find(void *c, char marca[], int qtdd){
        Carro *pcar = (Carro*)c;
        if(pcar != NULL){

            for(int i = 0; i < qtdd ; i++){
                if(strcmp(pcar[i].marca,marca) == 0){
                    printf("posicao = %d ",i);
                    printf(" - Potencia = %d", (int)pcar[i].potencia);
                    printf(" - num portas = %d", (int)pcar[i].num_portas);
                    printf(" - preco = %f", (float)pcar[i].preco);
                    printf(" - placa = %li \n", pcar[i].placa);
                    return 1;
                }
            }
        }

        printf("Nao encontrado \n");

        return -1 ;
    }


//----------------------------------------------------------------------------------------------------//


void main(void){

    int loop = 1;               //--- looping principal
    int aloca = 1;              //--- checa se o cofo existe
    int aloca2 = 1;             //--- checa se a estrutura existe
    int car_pos = -1;           //-- checa a posiçao da estrutura no cofo
    int qtdd;
    int car_exist = 1;
    cofo *cof;
    Carro *car;
    while(loop == 1){
            system("cls");

            printf("------------------------------------------ Cofo Manage ------------------------------------------------------\n");
            printf(" a)Criar cofo \n b)Destruir cofo \n c)Colocar elemento \n d)Tirar o ultimo \n e)Tirar o primeiro \n ");
            printf("f)Insere estrutura Carro no cofo \n g)Insere dados Carro \n h)Destruir carros \n i)Pesquisar carro \n j) Sair \n");

            char opt;

             if(aloca != 1){                                        //----- mostra o conteudo do cofo ,se exisitr
                printf("\n-------------Cofo ------------\n");
                cofGet(cof,qtdd,car_pos,aloca2,show_car);
                printf("\n------------------------------\n");

            }


            scanf("%c", &opt);



//----------------------------------------------------------------------------------------------------//

            if(opt == 'a'){

                int n;

                printf("informe o tamanho do cofo \n");

                scanf("%d", &n);

                cof = cofCreate(n);


                if(cof != NULL){

                    aloca++;

                }
            }
//----------------------------------------------------------------------------------------------------//
            if(opt == 'b'){

               if(aloca !=1){

                    cofDestroy(cof, &aloca);

               }else{

                    printf("Inexistente \n");

               }


            }
//----------------------------------------------------------------------------------------------------//
            if(opt == 'c' ){

                if(aloca != 1){

                    int n;

                    printf("numero do elemento \n");

                    scanf("%d", &n);

                    cofInsert(cof, n);

                }else{

                    printf("Inexistente \n");

                }

            }
//----------------------------------------------------------------------------------------------------//
            if(opt == 'd'){

              if(aloca != 1){

                void *P;

                P =  cofRemoveLast(cof,&car_pos);
                if(car_pos == -1 && car_exist != 1){
                    if(cof != NULL && car != NULL){
                        car_Des(cof);
                        free(car);
                        car_pos = -1;
                        aloca2 = 1;
                        car_exist--;
                    }else{
                        printf("carro ou cofo inexistente \n");
                    }
                }


              }else{

                printf("Inexistente \n");

              }
            }
//----------------------------------------------------------------------------------------------------//
            if(opt == 'e'){

                if(aloca != 1){

                    void *Pfirst;

                    Pfirst = cofGetFirst(cof,&car_pos);

                    if(car_pos == -1 && car_exist != 1){

                        if(cof != NULL && car != NULL){
                            car_Des(cof);
                            free(car);
                            car_pos = -1;
                            aloca2 = 1;
                            car_exist--;
                        }else{
                            printf("carro ou cofo inexistente \n");
                        }
                    }

                }else{

                    printf("Inexistente \n");

                }
            }



//----------------------------------------------------------------------------------------------------//
            if(opt == 'f'){


                if(aloca != 1 && car_pos == -1){

                    printf("informe a quantidade = ");
                    scanf("%d", &qtdd);


                    car = (Carro*)malloc(qtdd*sizeof(Carro));
                    for(int i = 0 ; i < qtdd ; i++){
                        car[i].marca = (char*)malloc(20*sizeof(char));
                        if(car[i].marca == NULL){
                            free(car->marca);
                            free(car);
                            break;
                        }
                    }

                    if(car != NULL){

                        cof_GetGen(cof, (void*)car, &car_pos);
                        car_exist++;


                    }
                }else{

                    printf("indisponivel \n");

                }
            }
//----------------------------------------------------------------------------------------------------//
            if(opt == 'g'){

                if(aloca != 1 && car_exist != 1){

                    cof_Inserdatacar(cof,qtdd,&aloca2,car_pos,insert_datacar);

                }else{
                    printf("cofo ou carro inexistente \n");
                }
            }

//----------------------------------------------------------------------------------------------------//

            if(opt == 'h'){
                if(car_exist != 1){
                    if(cof != NULL && car != NULL){
                        car_Des(cof);
                        free(car);
                        car_pos = -1;
                        aloca2 = 1;
                        car_exist--;

                    }else{
                        printf("carro ou cofo inexistente \n");
                    }
                }else{
                    printf("Carro nao existe \n");
                }
            }
            if(opt == 'i'){
                if(car_pos != -1 && aloca2 != 1){
                    char carro[20];
                    printf("informe a marca do carro = ");
                    scanf("%s", &carro);
                    find_car(cof,carro,qtdd, car_pos,show_find);

                }else{
                    printf("nao ha carro(s) \n");
                }

            }
            if(opt == 'j'){

                loop = 2;

            }
//----------------------------------------------------------------------------------------------------//
            system("PAUSE");



        }

    free(cof);

    free(car);


}
//----------------------------------------------------------------------------------------------------//
