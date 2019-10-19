#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct nb {
  char *data;
}bank;

int hash_key(int key){
  return key%6;
}

bank *Data_Create(int n){
  return (bank*)malloc (n*sizeof(bank));
}

int Hash_insert(bank *checker, char *name){
  int tam = strlen(name);
  
  int pos = hash_key(tam);

  checker[pos].data = malloc(20);
  
   strcpy(checker[pos].data, name);
  

  if(checker[pos].data != NULL){
   
    printf("%s \n", checker[pos].data);
    return 1;
  }
  printf("Insert error \n");
  return 0;
}

void *Hash_Search(bank *checker, char *name){
  int tam = strlen(name);
  int pos = hash_key(tam);
  if(checker[pos].data != NULL){
   
    printf("Pos = %d tam = %d ",pos, tam);
    return checker[pos].data;
  }
  printf("Not find \n");
  return 0;
}

int main(void) {
  int quant;
  bank *checker;
  printf("Quantidade de dados = ");
  
  scanf("%d", &quant);

  checker = Data_Create(quant);
  if(checker != NULL){
    while(1){
      int opt;
      printf("1 -> Search \n2 -> Add name \nAnother -> Exit \nMake a choice = ");
      scanf("%d", &opt);
      if(opt == 1){
        char name[20];
        printf("name = ");
        scanf("%s", &name);
        
        printf("%s \n", Hash_Search(checker,name));
        

      }else if (opt == 2){
        char name[20];
        printf("name = ");
        scanf("%s", &name);
        Hash_insert(checker, name);
      }else{
        break;
      }
      
  }
  }else{
    printf("Bank malloc error \n");
  }
  
  
  

    
  return 0;
}
//-----------------------------------------------------------
