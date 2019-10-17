#include"pilha.h"
//eae nego; by luisnofb

int ePalindromo(char *str, int n);

int main(){

    int loop = 1;

    int pilha_exist = 0;
    int pilha_double_exist = 0;

    Stack *s;
    Stack *ds;

    while(loop == 1){
        system("cls");
        char opt ;

        printf("a)Coloca na pilha \n b)Remove da pilha \n c)Cria Pilha \n d)Destroi pilha \n e)Palindromo \n f)Criar pilha dupla \n g) Colocar na pilha 1 \n h)Colocar na pilha 2 \n i)Tirar pilha 1 \n j)Tirar pilha 2 \n k)Excluir pilha dupla \n l)Sair \n");

        if(pilha_exist > 0){
            printf("Pilha = \n");
            stkGet(s);
        }
        if(pilha_double_exist > 0){
            printf("Pilha dupla = \n");
            stkDGet(ds);
        }


        fflush(stdin);
        scanf("%c", &opt);



        if(opt == 'a'){
            if(pilha_exist > 0){
                char elm;
                printf("informe o elemento = ");
                fflush(stdin);
                scanf("%c", &elm);

                stkPush(s,(void*)elm);
            }else{
                printf("inexistente \n");
            }
        }

        if(opt == 'b'){
            if(pilha_exist > 0){
                stkPop(s);
            }else{
                printf("inexistente \n");
            }
        }
        if(opt =='c'){

             if(pilha_exist == 0){
                int n ;
                printf("informe o tamanho da pilha \n");
                fflush(stdin);
                scanf("%d", &n);
                s = stkCreate(n);
                pilha_exist++;
             }else{
                printf("ja existe uma \n");
             }

        }
        if(opt== 'd'){
            if(pilha_exist > 0){
                stkDestroy(s);
                if(s == NULL){
                    pilha_exist = 0;
                }
            }else{
                printf("inexistente \n");
            }
        }
        if(opt == 'e'){
            int n ;
            printf("informe o tamanho da palavra= ");
            fflush(stdin);
            scanf("%d", &n);
            char str[n];
            printf("informe a palavra = \n");
            fflush(stdin);
            scanf("%s", &str);

            ePalindromo(str, sizeof(str));




        }
        if(opt == 'f'){
            if(pilha_double_exist == 0){
                int n;
                printf("\nInforme o tamanho da pilha");
                scanf("%d", &n);

                ds = stkDouble_Create(n, &pilha_double_exist);
            }else{
                printf("Pilha dubla ja existe \n");
            }
        }

        if(opt == 'g'){
            if(pilha_double_exist == 1){
                int n;
                printf("Informe o elemento \n");
                scanf("%d", &n);

                stkD_Push1(ds,n);

            }else{
                printf("pilha dupla nao existe \n");
            }

        }
        if(opt == 'h'){
            if(pilha_double_exist == 1){
                int n;
                printf("Informe o elemento \n");
                scanf("%d", &n);

                stkD_Push2(ds,n);

            }else{
                printf("pilha dupla nao existe \n");
            }

        }
        if(opt == 'i'){
            if(pilha_double_exist ==1){
                int aux = (int)stkD_Pop1(ds);
            }else{
                printf("pilha dupla nao existe \n");
            }
        }
        if(opt == 'j'){
            if(pilha_double_exist == 1){
                int aux2 = (int)stkD_Pop2(ds);
            }else{
                printf("pilha dupla nao existe \n");
            }
        }
        if(opt == 'k'){
            if(pilha_double_exist == 1){
                stkD_Destroy(ds);
                pilha_double_exist--;
            }else{
                printf("Pilha dupla nao existe \n");
            }

        }
        if(opt == 'l'){
            loop = 2;
        }

        getch();
        
    }
    stkD_Destroy(ds);
    free(s);
    return 0;
}
