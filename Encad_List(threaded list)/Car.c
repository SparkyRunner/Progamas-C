#ifndef Car_c
    #define  Car_c
        #include"Car.h"

        typedef struct _carro_ {
        char *marca;
        int potencia;
        int Numportas;
        float preco;
        long int placa;

        }Carro;

//---------------------------------------------------//

    void *car_Create(){

        Carro *p = (Carro*)malloc(sizeof(Carro));
        p->marca = (char*)malloc(20*sizeof(char));
                if(p != NULL){
                    if(p->marca != NULL){
                        printf(" Marca = ");
                        fflush(stdin);
                        char marca[20];
                        scanf("%s", &marca);

                        strcpy(p->marca,marca);


                        printf("\n Potencia = ");
                        fflush(stdin);
                        scanf("%d", &p->potencia);
                        printf("\n NumPortas = ");
                        fflush(stdin);
                        scanf("%d",&p->Numportas);
                        printf("\n Preco = ");
                        fflush(stdin);
                        scanf("%f", &p->preco);
                        printf("\n Placa = ");
                        fflush(stdin);
                        scanf("%li", &p->placa);



                    return p;
                }
            }
            return NULL;

    }
//-------------------------------------------------------------//

    void show_Car(void*elm, int n){
        Carro *p = (Carro*)elm;


                    printf("--------------------------------------------------\n");
                    printf(" Posicao (%d) \n Marca = %s \n Potencia = %d \n NumPortas = %d \n Preco = %f \n Placa = %li \n",n, p->marca, p->potencia,p->Numportas, p->preco, p->placa );
                    printf("---------------------------------------------------\n");
    }

    int comp(Carro *c, char *marca, long int placa, int *temp){
        if(strcmp(c->marca,marca) == 0 && placa == c->placa){
            *temp = 1;
            return TRUE;
        }
        return FALSE;
    }
#endif // Car_c
