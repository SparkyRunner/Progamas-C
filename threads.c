#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 4 /* number of threads*/

#define LINE 10000
#define COLUMN 10000
#define MACROBLOCK_SIZE 100

/* time control variables*/
int primes_seq = 0 ;
float time_mean = 0;
float total_time = 0;
clock_t begin_total, finish_total;
/*---------------------------------------*/

/*-----------------matrix and thread controllers----------*/
int matrix[LINE][COLUMN];
int count_primes = 0;

int flag = 0;
int flags[SIZE];
int prev_line = 0;
int prev_column = 0;
int element;
int subgroup_cont = 0;
/*----------------------------------------*/

/*------------------ matrix functions-------------*/
void fill_matrix();
void find_prime();
void create_thread_sequential(pthread_t *threads,void  *function);
void create_thread_subgroup(pthread_t *threads, void*function);
void create_new_work(pthread_t *threads,int subgroups,void* function);

int main (){
    fill_matrix();
    pthread_t thread[SIZE];
    int opt;
    printf("1 - sequential 2 - macroblock \n");
    scanf("%d", &opt);
    if(opt == 1){
        create_thread_sequential(thread, find_prime);
        printf("total time %f\n", total_time);
        if(flag == 0){
            count_primes = count_primes/SIZE;
        }
        printf("primes %d", count_primes);
    }else{
        create_thread_subgroup(thread,find_prime);
        printf("total time %f\n", total_time);
        printf("primes %d", count_primes);
    }
    
    
}

void fill_matrix(){
    for(int i = 0 ; i < LINE ; i++){
        for(int j = 0 ; j< COLUMN ; j++){
            matrix[i][j] = rand() % 20000;
        }
    }
    
}

void find_prime(){
    int count = 0;
    int cont = 0;
    int initial_line = 0;
    int initial_column = 0;
    int temp_j = 0;
    if (flag == 1){
        initial_line = prev_line;
        initial_column = prev_column;
    }
    for(int i = initial_line ; i < LINE  ; i++){
        for(int j = initial_column ; j < COLUMN ; j++){
            
           if(matrix[i][j] > 10){
               
                for(int k = 2 ; k < 10 ; k++){
                    if(matrix[i][j] % k == 0){
                        count++;
                        
                    }
                    
                  
                }

            }else{
                for(int k = 2 ; k < matrix[i][j] ; k++){
                    if(matrix[i][j] % k == 0){
                        count++;
                    }
                   
                   
                }
            }
            
            if(count == 0){
                 
               count_primes++;
            }else{
                count = 0;
            }
            cont++;
            
            
                   
        
        }
        
        if(cont == element){
           prev_line = i+1;
           prev_column = temp_j;
            break;
        }
        
         
    }
   
    
 
  
}

void create_thread_sequential(pthread_t *threads,void  *function){
    
    
    begin_total = clock();
    
    for(int i = 0 ; i < SIZE ; i++){
        int *thread_number = (int*)malloc(sizeof(int));
        *thread_number = i;
        /*----- count the time while searching values----*/
        clock_t begin, finish;
        float total_time_thread;
       begin = clock();
        printf("Running thread %i \n", i);
   
        /*--------------------create----------------------*/ 
        
        pthread_create(&threads[i], NULL, function, (void*)(thread_number));
        pthread_join(threads[i], NULL);
        printf("thread %i done \n",i);
        
        /*------------------count--------------------------*/
        
        finish = clock();
        total_time_thread = (float)(finish - begin)/CLOCKS_PER_SEC;
        printf("thread %d time %f\n", i, total_time_thread);
    }
    finish_total = clock();
    total_time = (float)(finish_total - begin_total)/ CLOCKS_PER_SEC;
    time_mean = time_mean/ SIZE;
    
}

void create_thread_subgroup(pthread_t *threads, void*function){
    flag = 1;
    if((LINE*COLUMN) % MACROBLOCK_SIZE == 0){
        
        element = (LINE*COLUMN) / MACROBLOCK_SIZE;
        int stop_flag = 0; /*flag to know when stop looping*/
        int subgroups = (LINE*COLUMN)/element;
        int cont = 0;
        
        
        begin_total = clock();
        
        for(int i = 0 ; i < SIZE ; i++){
            flags[i] = 0;
        }
         
        for(int i = 0 ; i < SIZE ; i++){
            flags[i] = 1;
            int *thread_number = (int*)malloc(sizeof(int));
            *thread_number = cont;
            pthread_create(&threads[cont], NULL, function, (void*)(thread_number));
            pthread_join(threads[cont], NULL);
            flags[i] = 0;
            subgroup_cont++;
           
            create_new_work(threads,subgroups, function);
            
        }
        
        finish_total = clock();
        total_time = (float)(finish_total - begin_total)/ CLOCKS_PER_SEC;
        time_mean = time_mean/ SIZE;
        
    
        
    }else{
        printf("macroblock_size doesnt divid in equal parts, choose another size of matrix or macroblock size");
    }
}

/* if flags[i] = 0 means this thread was finished and a new can be created*/
void create_new_work(pthread_t *threads, int subgroups, void *function){
    if(subgroup_cont < subgroups){
        for(int i = 0; i < SIZE ; i++){
            if(flags[i] == 0){
                flags[i] = 1;
                int *thread_number = (int*)malloc(sizeof(int));
                        
                *thread_number = i;
                pthread_create(&threads[i], NULL, function, (void*)(thread_number));
                pthread_join(threads[i], NULL);
                subgroup_cont++;
                flags[i] = 0;
                create_new_work(threads, subgroups, function);
            }
        }
    }
}


