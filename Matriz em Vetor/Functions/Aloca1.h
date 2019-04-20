

float *Alocador1(int *Pn,int *Pm){

            FILE *arc;
               arc = fopen("Matrizes/MatrizA.txt", "r");



        if(arc == NULL){

            printf("Erro 1 \n");
            fclose(arc);
            return NULL;
        }else{

            int n, m;
            fscanf(arc,"%d %d", &n, &m);       // Pega do arquivo os valores da linha e coluna
            *Pn = n;                           // O ponteiro Pn armazena o valor de n do arquivo,dessa forma, o N da main recebe o mesmo valor
            *Pm = m;                           // O ponteiro Pn armazena o valor de m do arquivo,dessa forma, o M da main recebe o mesmo valor
            char get_char;
            float vma[n*m];
            int aux = 0;
            char c = fgetc(arc);

            while((get_char = fgetc(arc)) != EOF ){

                vma[aux] = get_char-48;                // Condiçao do while pega caractere por caractere no arquivo e armazena cada uma no vetor float, com conversao para numero
                aux++;

            }
            float *ma = (float*) malloc((n*m)*sizeof(float*));

            if(ma != NULL){

                for(int i = 0 ; i < n*m; i++){
                    ma[i] = vma[i];                    // Armazena no vetor float num  vetor que sera retornado para o ponteiro da main
                }

            }else{
                printf("Falha na alocaçao 1 \n");
                return NULL;
            }

            fclose(arc);
            return(ma);
        }
    }
