#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE (1==1)
#define FALSE !TRUE

#define BLOCKS 500
#define INODES 100
/*Estrutura do inode para ter controle dos blocos*/
typedef struct _inode_{
	int status;
	char name[30];
	int tam;
	int start;
}Inode;

/* Super bloco controla a quantidade de blocos, quantos inodes ja existem e quantos podem ter, alem de ter o espaço dos blocos*/
typedef struct SuperBlock{
	int block_numb;
	int inode_blocks_numb;
	int inodes_in_system;
	Inode *inodes;
	char *block_space;
}Super_Block;

/*cria a estrutura do superbloco, pre-setando os valores do arquivo*/

Super_Block* create_fs(){

	Super_Block *temp = (Super_Block*)malloc(sizeof(Super_Block));
	if(temp != NULL){
		temp->block_numb = BLOCKS;
		temp->inode_blocks_numb = INODES;
		temp->inodes_in_system = 0;
		temp->block_space = (char*)malloc(sizeof(char)*temp->block_numb);
		if(temp->block_space != NULL ){
		    temp->inodes = (Inode*)malloc(sizeof(Inode)*temp->inode_blocks_numb);
		    if(temp->inodes != NULL){

		        return temp;
		    }
		}
	}
	return FALSE;
}
/*Procura um espaço disponivel nos blocos para armazenar e procura um inode disponivel*/
int cat(Super_Block *super, char *data, char *name){
    char *temp = super->block_space;
    int cont = 1;
    int flag = TRUE;
    int next = 0;

	for(int i = 0; i < super->block_numb; i++){
	    if(cont == strlen(data)){

	        int free_inode = look_free_inode(super);
	        if(free_inode >= 0){
    	        super->inodes[free_inode].status = TRUE;
    	        super->inodes[free_inode].start = next;
    	        super->inodes[free_inode].tam = strlen(data);
    	        strcpy(super->inodes[free_inode].name,name);


    	        /*copia os dados para o bloco*/
    	        for(int j = 0 ; j < strlen(data) ; j++){

    	            temp[next] = data[j];
    	            next++;

    	        }
    	        super->inodes_in_system++;
	            return TRUE;
	        }
	        break;
	    }else if(temp[i] == NULL && cont != strlen(data)){

	        cont++;
	    }else{
	        next = i+1;
	        cont = 0;

	    }

	}
	printf("cant create archive\n");
    return FALSE;
}
int look_free_inode(Super_Block *fs){
    if(fs != NULL){
        for(int i = 0 ; i < fs->inode_blocks_numb ; i++){
            if(fs->inodes[i].status == NULL){
                return i;
                break;
            }
        }
    }
    return -1;
}

void ls (Super_Block *fs){
    if(fs != NULL){
        for(int i = 0 ; i < fs->inodes_in_system ; i++){
            if(fs->inodes[i].status != NULL){
                printf("%s \n", fs->inodes[i].name);

            }
        }
    }

}

void more (Super_Block *fs, char*arc_name){
    if(fs != NULL){
        for(int i = 0 ; i < fs->inodes_in_system ; i++){
            if(strcmp(fs->inodes[i].name, arc_name) == 0){
                int j = fs->inodes[i].start;
            	int f = fs->inodes[i].tam;
            	int cont = 0;

            	for(j ; cont < f  ; j++){
                    printf("%c", fs->block_space[j]);
                    cont++;
            	}
            }
        }
    }
    printf("\n");
}



int main(int argc, char*argv[]){

	Super_Block *File_sys = create_fs();
    int flag = TRUE;
	if(File_sys != FALSE){

	    while(flag == TRUE){
            system("clear");
            int opt;
            int used_blocks = 0;
            /*conta os blocos utilizados*/
            for(int i = 0 ; i < File_sys->inodes_in_system ; i++){
                used_blocks = used_blocks + File_sys->inodes[0].tam;
            }
            printf("Blocos %d  Blocos usados %d     Blocos disponiveis %d\n", File_sys->block_numb, used_blocks, (File_sys->block_numb - used_blocks));

            printf("1: cat\n2: ls \n3: more\n escolha: ");
            scanf("%d", &opt);

            char nome_arquivo[30];
            char conteudo[100];
            switch(opt){
                case 1 :

                    printf("nome do arquivo: ");
                    scanf("%s", &nome_arquivo);
                    printf("\nconteudo : ");
                    scanf("%s", &conteudo);

                    cat(File_sys, conteudo, nome_arquivo);
                    getchar();
                    break;
                case 2:
                    ls(File_sys);
                    getchar();
                    break;
                case 3:
                    printf("nome do arquivo : ");
                    scanf("%s", &nome_arquivo);
                    more(File_sys, nome_arquivo);
                    getchar();
                    break;
                default:
                    printf("nani\n");
                    getchar();

            }
            getchar();
	    }

	}

	if(File_sys != FALSE){
    	free(File_sys->inodes);
    	free(File_sys);
	}
	return 0;
}

