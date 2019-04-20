

float *multMat(int n, int m, int o, int p, float *ma, float * mb){

    float *res = (float*)malloc((n*p)*sizeof(float*));

    if(res == NULL){
        printf("Erro alocaçao resultado \n");
        return NULL;
    }

    float aux = 0;
    int pos = 0;

    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < p ; j++){

            for(int k = 0 ; k < m ; k++){

                aux += ma[(m*i)+ k] * mb[(p * k)+ j];     // Faz a multiplicação dos elementos da linha de A com a Coluna de B,sendo a linha de A alterada apos ter sido calculada com todas as colunas de B
            }
            res[pos] = aux;
            aux = 0;
            pos++;
        }
    }
    return res;

}
