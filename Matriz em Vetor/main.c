#include<stdio.h>
#include<stdlib.h>
#include"Functions/Aloca1.h"
#include"Functions/Aloca2.h"
#include"Functions/MultMat.h"
#include"Functions/Transp.h"

int main(){

    int loop = 1;

    while(loop == 1){

        system("cls");
        int opt = 0;

        printf("-------------------- Escolha uma opcao --------------------\n 1) A x B \n 2) A x B(t) \n 3) A(t)\n 4) Triangular superior de A \n 5) Diagonal de A \n 6) Linha K de A \n 7) Linha k de B \n 8) Sair \n");




        float *ma, *mb;
        int n,m,o,p;

        ma = Alocador1(&n,&m);    // Função que puxa do arquivo a matriz A para o ponteiro e N,M pro escopo global
        mb = Alocador2(&o,&p);    // Função que puxa do arquivo a matriz B para o ponteiro e O,P pro escopo global

    //-------------------------------------------------------------------------------------------------------------------//
        printf(" \nMatriz A : %d x %d  \n \n", n, m);

            for(int i = 0 ; i < n ; i++){
                printf("| ");
                for(int j = 0 ; j < m ; j++){       // Laços que pegam do vetor MA e mostra em forma de matriz
                    printf("%.1f |", ma[i*m]+j);
                }

                printf("\n");
            }
            printf("\n");

         printf("Matriz B : %d x %d \n \n", o , p);

            for(int i = 0 ; i < o ; i++){
                printf("| ");
                for(int j = 0 ; j < p ; j++){       // Laços que pegam do vetor MB e mostram em forma de matriz
                    printf("%.1f |", mb[(i*p)+j]);
                }

                printf("\n");
            }
            printf("\n");
         printf("Opt = ");
         scanf("%d", &opt);

    //-----------------------------------------------------------------------------------------------------------------//
        if(opt == 1){

            if(m == o){                // verifica se a coluna de A é igual a linha de B
                   float *mult;

                   mult = multMat(n,m,o,p,ma,mb);            // A funçao reporta para o ponteiro o vetor resultado da multiplicação

                   printf(" \n A x B : %d x %d \n \n", n, p);

                   for(int i = 0 ; i < n ; i++){
                        printf("| ");
                        for(int j = 0 ; j < p ; j++){        // Laços que mostram o vetor resultado da multiplicação em forma de matriz

                            printf("%.1f |", mult[(p*i)+j]);
                        }
                        printf("\n");

                   }

                free(mult);
            }else{
                printf("Numero de colunas de A diferente do de linhas de B \n");
            }
        }

    //---------------------------------------------------------------------------------------------------------------//
        if(opt == 2){
            if(m == p){         // Verifica se a coluna de A é igual a coluna P(antes coluna mas agora linha, pois a transposta inverte) da transposta de B

                float *result;
                float *transp;

                transp = Transp(o,p,mb);                 // Essa função retorna um vetor com a matriz transposta de B
                result = multMat(n,m,p,o,ma,transp);     // Essa função retorna o vetor da multiplicação A x B(t)

                printf(" \n A x B(t) :  %d x %d\n", n, o);

                for(int i = 0 ; i < n ; i++){
                    printf("| ");
                    for(int j = 0 ; j < o ; j++){           // Laços que mostram o vetor resultado da multiplicação em forma de matriz

                        printf("%.1f |",result[(o*i)+j] );

                    }

                    printf("\n");
                }

                free(transp);

                free(result);

            }else{

                printf("Numero de colunas de A diferente do de linhas da transposta B \n");
            }

        }

    //---------------------------------------------------------------------------------------------------------------//
        if(opt == 3){
            float *transp;
            transp = Transp(n,m,ma);    // Retorna um vetor com a transposta de A

            printf(" \n Transposta de A : %d x %d \n \n", m, n);

            for(int i = 0 ; i < m ; i++){
                printf("| ");
                for(int j = 0 ; j < n ; j++){           // Laços que mostram a transposta de A em forma de matriz
                    printf("%.1f |", transp[(n*i)+j]);
                }
                printf("\n");
            }
            free(transp);
        }

    //---------------------------------------------------------------------------------------------------------------//
        if(opt == 4){


            for(int i = 0 ; i < n ; i++){

                for(int j = 0 ; j < m ; j++){

                    if(j > i){                          // Laços que mostram a triangular superior (A(ixj) sendo i > j)

                        printf("%.1f ",ma[(m*i)+j]);

                    }else{

                        printf("  ");

                    }
                    }

                printf("\n");

            }

        }

    //---------------------------------------------------------------------------------------------------------------//
        if(opt == 5){
            if(n == m){
                for(int i = 0 ; i < n ; i ++){

                    for(int j = 0 ;j < m ; j++){

                        if(j == i ){                        // Laços que mostram a diagonal principal de A (A(ixj) i = j)

                            printf("%.1f", ma[(m*i)+j]);

                        }else{

                            printf("  ");

                        }
                    }

                    printf("\n");
                }

            }else{
                printf(" n != m \n");
            }

        }
        if(opt == 6){

            int k;
            printf("Informe uma linha (1 a %d) \n", n);
            scanf("%d", &k);
            k -= 1;
            printf("Linha %d de A : \n ", k+1);

            for(int i = 0 ; i < n ; i++){

                for(int j = 0 ; j < m ; j++){               // Laços que mostram determinada linha de A, linha informada pelo usuario, recebida em K

                    if(i == k){
                        printf("| ");
                        printf("%.1f |", ma[(m*i)+j]);

                    }
                }
            }

            printf("\n");

        }

    //---------------------------------------------------------------------------------------------------------------//
        if(opt == 7){
            int k;
            printf("Informe uma linha (1 a %d) \n", o);
            scanf("%d", &k);
            k -= 1;
            printf("Linha %d de B : \n ", k+1);

            for(int i = 0 ; i < o ; i++){

                for(int j = 0 ; j < p ; j++){

                    if(i == k){                         // Laços que mostram deteminada linha de B informada pelo usuario , recebida em K
                        printf("| ");
                        printf("%.1f |", mb[(p*i)+j]);

                    }
                }

            }

            printf("\n");

        }

    //---------------------------------------------------------------------------------------------------------------//
        if( opt == 8 ){
            loop++;
        }                           // Sair do programa

        free(ma);
        free(mb);
        system("PAUSE");
        system("cls");
    }
}

