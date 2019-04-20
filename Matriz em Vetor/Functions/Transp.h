

float *Transp(int n,int m, float *mat){

    float *transp = (float*)malloc((n*m)*sizeof(float*));

    if(transp == NULL){

        printf("Erro alocacao transp \n");
        return NULL;

    }
    for(int i = 0 ; i < n ; i++){

        for(int j = 0; j < m ; j++){

            transp[(n*j)+i] = mat[(m*i)+j];     // Pega os elementos da linha e coloca em colunas do vetor receptor e o retorna pra main

        }
    }
    return (transp);
}
