

float *Alocador2(int *Po, int *Pp){

            FILE *arc;
               arc = fopen("Matrizes/MatrizB.txt", "r");



        if(arc == NULL){

            printf("Erro 2 \n");
            fclose(arc);
            return NULL;

        }else{

            int o, p;
            fscanf(arc,"%d %d", &o, &p);            // Pega do arquivo os valores da linha e coluna
            *Po = o;                                // O ponteiro Pn armazena o valor de n do arquivo,dessa forma, o N da main recebe o mesmo valor
            *Pp = p;                                // O ponteiro Pn armazena o valor de m do arquivo,dessa forma, o M da main recebe o mesmo valor
            char get_char;
            float vmb[o*p];
            int aux = 0;
            char c = fgetc(arc);

            while((get_char = fgetc(arc)) != EOF ){

                vmb[aux] = get_char-48;             // Condiçao do while pega caractere por caractere no arquivo e armazena cada uma no vetor float, com conversao para numero
                aux++;

            }
            float *mb = (float*) malloc((o*p)*sizeof(float*));

            if(mb != NULL){

                  for(int i = 0 ; i < o*p; i++){
                    mb[i] = vmb[i];                 // Armazena no vetor float num  vetor que sera retornado para o ponteiro da main

                }

            }else{

                printf("Falha na alocaçao 2 \n");
                return NULL;

            }



            fclose(arc);
            return(mb);
        }
    }
