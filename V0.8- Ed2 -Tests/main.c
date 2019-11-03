#include "avltree.h"
#include "Hash.h"
#include "Chained_list.h"
#include "Binary_Tree.h"
#include "rbt.h" 
#include "time.h"

int main(){
   
    Node *dadosB_AVL; // Ponteiro Avl

    bank *dadosB_Hash; // Ponteiro Hash

    Tnode *dadosB_BTree; // Ponteiro Árvore binária

    List *dadosA_Chained; // Ponteiro Lista encadeada
    List *dadosB_Chained; // Ponteiro Lista encadeada

    RBNode *dadosB_RBTree;

    int am; // Metodo de armazenamento
    int op; // Opcao
    int arc; // qual dos arquivos sera utilizado como maior

    clock_t tInicio, tFim, tInsert, tAdd, tRemove, tEquals; // timer

    printf("Armazenar:\n");
    printf("[1] Lista encadeada\n[2] Hash\n[3] Arvore binaria\n[4] Arvore AVL\n[5] Arvore rubro-negra\nDigite: ");
    scanf("%d",&am);

    printf("Opcoes?\n");
    printf("[1] Buscar os elementos de A que estao em B\n");
    printf("[2] Inserir em B, os elementos de A que nao est�o em B\n");
    printf("[3] Remover os elementos de A que est�o em B\nDigite: ");
    scanf("%d",&op);
    
    printf("\n[1] 1000 \n[2] 5000 \n[3] 10000 \n[4]50000 \n[5] 100000 \n[6] 500000 \n[7] 1000000");
    scanf("%d", &arc);

// lera o arquivo e armazenara de arcordo com a esolha feita
    switch(am){
        case 1:
            dadosA_Chained = list_create();
            dadosB_Chained = list_create();
            
            Insert_FILE(dadosA_Chained, 1);
            tInicio = clock();
            Insert_FILE(dadosB_Chained, arc);
            tFim = clock();
            tInsert = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

            printf("Dados A (Encadeada):\n");
            printf("\nQuant %d \n ", show_list(dadosA_Chained));
            printf("\nDados B (Encadeada): \n");
            printf("\nQuant %d \n", show_list(dadosB_Chained));
            

            switch(op){
                case 1:
                    printf("\nElementos de A em B : \n");
                    tInicio = clock();
                    Equals_Chain_Chain(dadosA_Chained, dadosB_Chained);
                    tFim = clock();
                    tEquals = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nInsert %d, Equals %d \n", tInsert, tEquals);
                    printf("\n");
                break;
                case 2:
                    
                    printf("\nDados de A que estao em B : \n");
                    tInicio = clock();
                    Add_Not_Equals_Chain_Chain(dadosA_Chained, dadosB_Chained);
                    tFim = clock();
                    tAdd = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nCom adiçao dos nao iguais  : \n");
                    printf("\nQuant %d \n ", show_list(dadosB_Chained));
                    printf("\nInsert %d, Add  %d\n",tInsert, tAdd );
                break;
                case 3:
                    printf("\n Dados de A que estao em B removidos de B : \n");
                    tInicio = clock();
                    Remove_Equals_Chain_Chain(dadosA_Chained, dadosB_Chained);
                    tFim = clock();
                    tRemove = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nCom remoçao dos iguais : \n");
                    printf("\nQuant %d \n", show_list(dadosB_Chained));
                    printf("\nInsert %d, Remove %d \n", tInsert, tRemove);
                break;
                tFim = clock();
           
            }

        break;
        case 2:
           
            dadosA_Chained = list_create();
            dadosB_Hash = Data_Create(1000000);
    
            Insert_FILE(dadosA_Chained, 1);
            tInicio = clock();
            Hash_FILE_Insert(dadosB_Hash, arc);
            tFim = clock();
            tInsert = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

            printf("dados A (Encadeada): \n");
            printf("\nQuant %d \n ",show_list(dadosA_Chained));
            printf("\ndados B : (Hash)\n");
            printf("\nQuant %d ", Show_Hash_list(dadosB_Hash, 1000000));
           
            switch(op){
                case 1:
                    printf("\nElementos de A que estao em B : \n");
                    tInicio = clock();
                    Equals_Chain_Hash(dadosA_Chained, dadosB_Hash);
                    tFim = clock();
                    tEquals = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

                    printf("\nInser %d, Equals %d\n",tInsert,tEquals);
                    printf("\n");

                    
                break;
                case 2:
                    printf("\n");
                    tInicio  = clock();
                    Add_Not_Equals_Chain_Hash(dadosA_Chained, dadosB_Hash);
                    tFim = clock();
                    tAdd= ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nCom adiçao : \n");
                    printf("\nQuant %d \n ", Show_Hash_list(dadosB_Hash, 1000000));
                    printf("\nInsert %d, Add %d \n",tInsert, tAdd);

                break;
                
                case 3:
                    tInicio = clock();
                    Remove_Equals_Chain_Hash(dadosA_Chained, dadosB_Hash);
                    tFim = clock();
                    tRemove = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nCom remocao dos iguais : \n");
                    printf("\nQuant %d \n ", Show_Hash_list(dadosB_Hash, 1000000));
                    printf("\nInsert %d, Remove %d\n", tInsert, tRemove);
                break;
            }
            break;
        case 3:
            dadosA_Chained = list_create();
            Insert_FILE(dadosA_Chained, 1);
            
            
            dadosB_BTree = abCreate(NULL);
            tInicio = clock();
            ab_FILE_Insert(dadosB_BTree, arc);
            tFim = clock();
            tInsert = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

            printf("dados A (Encadeada) : \n");
            printf("\nQuant %d \n ", show_list(dadosA_Chained));
            printf("\ndados B (Arvore B, Pre Ord) : \n");
            printf("\nQuant %d \n", Pre_ordem(dadosB_BTree));

            switch(op){
                case 1:
                    printf("\nElementos de A que estao em B : \n");
                    tInicio = clock();
                    Equals_Chain_BTree(dadosA_Chained, dadosB_BTree);
                    tFim = clock();
                    tEquals = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nInsert %d, Equals %d\n", tInsert, tEquals);
                break;
                case 2:
               
                   tInicio = clock();
                    Add_Not_Equals_Chain_BTree(dadosA_Chained, dadosB_BTree);
                    tFim = clock();
                    tAdd = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nCom adicao : \n");
                    printf("\nQuant %d \n ", Pre_ordem(dadosB_BTree));
                    printf("\nInsert %d, Add %d", tInsert, tAdd);
                break;
                case 3:
                    printf("\nElementos de A que estao em B, removidos de B : \n");
                    tInicio = clock();
                    Remove_Equals_Chain_BTree(dadosA_Chained, dadosB_BTree);
                    tFim = clock();
                    tRemove = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nCom elementos removidos : \n");
                    printf("\nQuant %d ", Pre_ordem(dadosB_BTree));
                    printf("\nInsert %d, Remove %d", tInsert, tRemove);
                break;
            }
            break;

        case 4:
            dadosA_Chained = list_create();
            tInicio = clock();
            Insert_FILE(dadosA_Chained, 1);
            tFim = clock();
            tInsert = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

            dadosB_AVL = createAvlTree(arc);
            printf("\nDados A: (Encadeada)\n");
            printf("\nQuant %d\n", show_list(dadosA_Chained));
            printf("\n\nDados B: (Arvore AVL)\n");
            printf("\nQuant %d\n", preOrder(dadosB_AVL));
            switch(op){
                case 1:
                    printf("\n\nElementos de A que estao em B:\n");
                    tInicio = clock();
                    Equals_Chain_AVLTree(dadosA_Chained, dadosB_AVL);
                    tFim = clock();
                    tEquals = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nInsert %d Equals %d \n", tInsert, tEquals);
                    printf("\n");
                    
                break;
                case 2:
                    printf("\nElementos de A que estao nao em B,  adicionados em B :  \n");
                    tInicio = clock();
                    Add_Not_Equals_Chain_AVLTree(dadosA_Chained, dadosB_AVL);
                    tFim = clock();
                    tAdd = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nQuant %d\n", preOrder(dadosB_AVL));
                      printf("\nInsert %d Add %d \n", tInsert, tAdd);
                    
                    printf("\n");
                break;
                case 3:
                    printf("\nElementos de A que estao em  B, removidos de B : \n");
                    tInicio = clock();
                    Remove_Equals_Chain_AVLTree(dadosA_Chained, dadosB_AVL);
                    tFim = clock();
                    tRemove = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\nQuant %d\n", preOrder(dadosB_AVL));
                    printf("\nInsert %d Remove %d \n", tInsert, tRemove);
                break;
                
            }
            break;
        case 5:
            dadosA_Chained = list_create();
            Insert_FILE(dadosA_Chained, 1);
            tInicio = clock();
            dadosB_RBTree = RB_FILE_Insert(arc);
            tFim = clock();
            tInsert = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
            printf("\nDados A: (Encadeada)\n");
            printf("\nQuant %d \n", show_list(dadosA_Chained));
            printf("\n\nDados B: (RBT)\n");
            printf("\nQuant %d \n", rbtPreOrder(dadosB_RBTree));
            switch(op){
                case 1:
                    printf("\nElementos de A que estao em B : \n");
                    tInicio = clock();
                    Equals_Chain_RBTree(dadosA_Chained, dadosB_RBTree);
                    tFim = clock();
                    tEquals = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("Insert %d, Equals %d \n", tInsert, tEquals);
                break;
                case 2:
                    printf("\nElementos de A que nao estao em B, adicionados em B : \n");
                    tInicio = clock();
                    Add_Not_Equals_Chain_RBTree(dadosA_Chained, dadosB_RBTree);
                    tFim = clock();
                    tAdd = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    printf("\n");
                    printf("\n Quant %d\n ", rbtPreOrder(dadosB_RBTree));
                    printf("Insert %d, Add %d\n", tInsert, tAdd);
                break;
                case 3:
                    printf("\nCom remocao: \n");
                    tInicio = clock();
                    Remove_Equals_Chain_RBTree(dadosA_Chained, dadosB_RBTree);
                    tFim = clock();
                    tRemove = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                    
            
                    printf("\nQuant %d \n ", rbtPreOrder(dadosB_RBTree));
                    printf("Insert %d, Remove %d\n", tInsert, tRemove);
                break;
            }
            
        break;
        default:

            break;
    }

}
