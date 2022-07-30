#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXVET 200
#define MAXNOME 256
#define MAXNOTAS 20
struct TipoRegistro {
	long long cpf;
	int nusp;
	char nome[MAXNOME];
};
struct TipoNotas {
	int nusp;
	float notas[MAXNOTAS];
};
struct Imprime {
    long long cpf;
    int nusp;
    char nome[MAXNOME];
    float notas[MAXNOTAS];
    float media;
};
void ImprimeMaioresMenores(struct TipoRegistro vetReg[], struct TipoNotas vetNot[], float medias[], 
    int nR, int K, int T){
    int i;
    int j;
    struct Imprime maiores_menores[MAXVET];
    struct Imprime temp[MAXVET];
    for(i=0 ; i<nR ; i++){
        maiores_menores[i].cpf = vetReg[i].cpf;
        maiores_menores[i].nusp = vetReg[i].nusp;
        strcpy(maiores_menores[i].nome, vetReg[i].nome);
        for(j=0 ; j<K ; j++)
            maiores_menores[i].notas[j] = vetNot[i].notas[j];
        maiores_menores[i].media = medias[i];
    }
    //Ordena/imprime as T maiores
    for(i=0 ; i<nR ; i++){
        for(j=0 ; j<=i ; j++){
            if(maiores_menores[i].media>maiores_menores[j].media){
                temp[i] = maiores_menores[i];
                maiores_menores[i] = maiores_menores[j];
                maiores_menores[j] = temp[i];
            }
       }
    }
    printf("\n");
    for(i=0 ; i<T ; i++){
        printf("%11lld ", maiores_menores[i].cpf);
        printf("%d ", maiores_menores[i].nusp);
        printf("%19s        ", maiores_menores[i].nome);
        for(j=0 ; j<K ; j++)
            printf("%.1f ", maiores_menores[i].notas[j]);
        printf("%4.1f\n\n", maiores_menores[i].media);
    }
    for(i=(nR-T) ; i<nR ; i++){
        printf("%11lld ", maiores_menores[i].cpf);
        printf("%d ", maiores_menores[i].nusp);
        printf("%19s        ", maiores_menores[i].nome);
        for(j=0 ; j<K ; j++)
            printf("%.1f ", maiores_menores[i].notas[j]);
        printf("%4.1f\n", maiores_menores[i].media);
    }
}
void ImprimeIntervalo(struct TipoRegistro vetReg[], struct TipoNotas vetNot[], float medias[], 
	int nReg, int nNotas, int ini, int fim, int ordem){
	int i;
	int j;
    int k;
	float media_turma=0;
    float variancia=0;
    float desvio_padrao;
    float nota_menor=100;
    float nota_maior=0;
    struct Imprime alunos[MAXVET];
    struct Imprime temp[MAXVET];
    for(i=0 ; i<nReg ; i++){
        alunos[i].cpf = vetReg[i].cpf;
        alunos[i].nusp = vetReg[i].nusp;
        strcpy(alunos[i].nome, vetReg[i].nome);
        for(j=0 ; j<nNotas ; j++)
            alunos[i].notas[j] = vetNot[i].notas[j];
        alunos[i].media = medias[i];
    }
    /*CPF*/if(ordem == 0){
        for(i=0 ; i<nReg ; i++){
            for(j=0 ; j<=i ; j++){
                if(alunos[i].cpf<alunos[j].cpf){
                    temp[i] = alunos[i];
                    alunos[i] = alunos[j];
                    alunos[j] = temp[i];
                }
            }
        }
        if(ini==0 && fim==0){
            for(i=ini ; i<=fim ; i++)
                media_turma = media_turma + alunos[i].media;
            media_turma = media_turma/((fim-ini)+1);
            for(i=ini ; i<=fim ; i++)
                variancia = variancia + (alunos[i].media - media_turma)*(alunos[i].media - media_turma);
            variancia = variancia/((fim-ini)+1);
            desvio_padrao = sqrt(variancia);
            for(i=ini ; i<=fim ; i++){
                if(alunos[i].media >= nota_maior)
                    nota_maior = alunos[i].media;   
                if(alunos[i].media <= nota_menor)
                    nota_menor = alunos[i].media;
            }
             printf("%f %f %f %f\n", media_turma, desvio_padrao, nota_menor, nota_maior);
            for(i=ini ; i<=fim ; i++){
                printf("%11lld ", alunos[i].cpf);
                printf("%d ", alunos[i].nusp);
                printf("%19s        ", alunos[i].nome);
                for(j=0 ; j<nNotas ; j++)
                    printf("%.1f ", alunos[i].notas[j]);
                printf("%f\n", alunos[i].media);
            }
        }
        else{
            for(i=ini ; i<=fim-1 ; i++)
                media_turma = media_turma + alunos[i].media;
            media_turma = media_turma/((fim-ini));
            for(i=ini ; i<=fim-1 ; i++)
                variancia = variancia + (alunos[i].media - media_turma)*(alunos[i].media - media_turma);
            variancia = variancia/((fim-ini));
            desvio_padrao = sqrt(variancia);
            for(i=ini ; i<=fim-1 ; i++){
                if(alunos[i].media >= nota_maior)
                    nota_maior = alunos[i].media;   
                if(alunos[i].media <= nota_menor)
                    nota_menor = alunos[i].media;
            }
             printf("%f %f %f %f\n", media_turma, desvio_padrao, nota_menor, nota_maior);
            for(i=ini ; i<=fim-1 ; i++){
                printf("%11lld ", alunos[i].cpf);
                printf("%d ", alunos[i].nusp);
                printf("%19s        ", alunos[i].nome);
                for(j=0 ; j<nNotas ; j++)
                    printf("%.1f ", alunos[i].notas[j]);
                printf("%f\n", alunos[i].media);
            }
        }
    }
    /*NUSP*/if(ordem == 1){
        for(i=0 ; i<nReg ; i++){
            for(j=0 ; j<=i ; j++){
                if(alunos[i].nusp<alunos[j].nusp){
                    temp[i] = alunos[i];
                    alunos[i] = alunos[j];
                    alunos[j] = temp[i];
                }
            }
        }
        if(ini==0 && fim==0){
            for(i=ini ; i<=fim ; i++)
                media_turma = media_turma + alunos[i].media;
            media_turma = media_turma/((fim-ini)+1);
            for(i=ini ; i<=fim ; i++)
                variancia = variancia + (alunos[i].media - media_turma)*(alunos[i].media - media_turma);
            variancia = variancia/((fim-ini)+1);
            desvio_padrao = sqrt(variancia);
            for(i=ini ; i<=fim ; i++){
                if(alunos[i].media >= nota_maior)
                    nota_maior = alunos[i].media;   
                if(alunos[i].media <= nota_menor)
                    nota_menor = alunos[i].media;
            }
            printf("%f %f %f %f\n", media_turma, desvio_padrao, nota_menor, nota_maior);
            for(i=ini ; i<=fim ; i++){
                printf("%11lld ", alunos[i].cpf);
                printf("%d ", alunos[i].nusp);
                printf("%19s        ", alunos[i].nome);
                for(j=0 ; j<nNotas ; j++)
                    printf("%.1f ", alunos[i].notas[j]);
                printf("%f\n", alunos[i].media);
            }
        }
        else{
            for(i=ini ; i<=fim-1 ; i++)
                media_turma = media_turma + alunos[i].media;
            media_turma = media_turma/((fim-ini));
            for(i=ini ; i<=fim-1 ; i++)
                variancia = variancia + (alunos[i].media - media_turma)*(alunos[i].media - media_turma);
            variancia = variancia/((fim-ini));
            desvio_padrao = sqrt(variancia);
            for(i=ini ; i<=fim-1 ; i++){
                if(alunos[i].media >= nota_maior)
                    nota_maior = alunos[i].media;   
                if(alunos[i].media <= nota_menor)
                    nota_menor = alunos[i].media;
            }
            printf("%f %f %f %f\n", media_turma, desvio_padrao, nota_menor, nota_maior);
            for(i=ini ; i<=fim-1 ; i++){
                printf("%11lld ", alunos[i].cpf);
                printf("%d ", alunos[i].nusp);
                printf("%19s        ", alunos[i].nome);
                for(j=0 ; j<nNotas ; j++)
                    printf("%.1f ", alunos[i].notas[j]);
                printf("%f\n", alunos[i].media);
            }
        }
    }
    /*NOME*/if(ordem ==2){
        for(i=0 ; i<nReg ; i++){
            for(j=0 ; j<=i ; j++){
                k=0;
                while(alunos[i].nome[k] != '\0' && alunos[j].nome[k] != '\0'){
                    if(alunos[i].nome[k] == alunos[j].nome[k])
                        k++;
                    else if(alunos[i].nome[k]<alunos[j].nome[k]){
                        temp[i] = alunos[i];
                        alunos[i] = alunos[j];
                        alunos[j] = temp[i];
                        break;
                    }
                    else
                        break;
                }
            }
        }
        if(ini==0 && fim==0){
            for(i=ini ; i<=fim ; i++)
                media_turma = media_turma + alunos[i].media;
            media_turma = media_turma/((fim-ini)+1);
            for(i=ini ; i<=fim ; i++)
                variancia = variancia + (alunos[i].media - media_turma)*(alunos[i].media - media_turma);
            variancia = variancia/((fim-ini)+1);
            desvio_padrao = sqrt(variancia);
            for(i=ini ; i<=fim ; i++){
                if(alunos[i].media >= nota_maior)
                    nota_maior = alunos[i].media;   
                if(alunos[i].media <= nota_menor)
                    nota_menor = alunos[i].media;
            }
             printf("%f %f %f %f\n", media_turma, desvio_padrao, nota_menor, nota_maior);
            for(i=ini ; i<=fim ; i++){
                printf("%11lld ", alunos[i].cpf);
                printf("%d ", alunos[i].nusp);
                printf("%19s        ", alunos[i].nome);
                for(j=0 ; j<nNotas ; j++)
                    printf("%.1f ", alunos[i].notas[j]);
                printf("%f\n", alunos[i].media);
            }
        }
        else{
            for(i=ini ; i<=fim-1 ; i++)
                media_turma = media_turma + alunos[i].media;
            media_turma = media_turma/((fim-ini));
            for(i=ini ; i<=fim-1 ; i++)
                variancia = variancia + (alunos[i].media - media_turma)*(alunos[i].media - media_turma);
            variancia = variancia/((fim-ini));
            desvio_padrao = sqrt(variancia);
            for(i=ini ; i<=fim-1 ; i++){
                if(alunos[i].media >= nota_maior)
                    nota_maior = alunos[i].media;   
                if(alunos[i].media <= nota_menor)
                    nota_menor = alunos[i].media;
            }
             printf("%f %f %f %f\n", media_turma, desvio_padrao, nota_menor, nota_maior);
            for(i=ini ; i<=fim-1 ; i++){
                printf("%11lld ", alunos[i].cpf);
                printf("%d ", alunos[i].nusp);
                printf("%19s        ", alunos[i].nome);
                for(j=0 ; j<nNotas ; j++)
                    printf("%.1f ", alunos[i].notas[j]);
                printf("%f\n", alunos[i].media);
            }
        }
    }
}
void ComputaMedias(struct TipoNotas vetNot[], int pesos[], float medias[], int nReg, int nNot){
	int i;
	int j;
	float somatorio_pesos;
	float somatorio_notas;
	for(i=0 ; i<nReg ; i++){
		somatorio_pesos = 0;
		somatorio_notas = 0;
		for(j=0 ; j<nNot ; j++){
			somatorio_pesos = somatorio_pesos + pesos[j];
			somatorio_notas = (somatorio_notas + pesos[j]*vetNot[i].notas[j]);
		}
		medias[i] = somatorio_notas / somatorio_pesos;
	}	
}
int main(){
    struct TipoRegistro registro[MAXVET];
    struct TipoNotas notas_alunos[MAXVET];
    int i;
    int j;
    int n_alunos=0;
    int n_provas=0;
    int pesos_provas[MAXNOTAS];
    int inicio;
    int fim;
    int ordem;
    int melhores_piores;
    float medias_alunos[MAXVET];
	char nome_arquivo_registro[40];
    char nome_arquivo_pesos[40];
    char nome_arquivo_notas[40];
    char percorre;
    FILE *f_alunos;
    FILE *f_pesos;
    FILE *f_notas;
    scanf(" %s", nome_arquivo_registro);
    scanf(" %s", nome_arquivo_pesos);
    scanf(" %s", nome_arquivo_notas);
	scanf("%d", &ordem);
	scanf("%d", &inicio);
	scanf("%d", &fim);
	scanf("%d", &melhores_piores);
    //Leitura do número de alunos do arquivo de registro
    f_alunos = fopen (nome_arquivo_registro, "r");
    if(f_alunos == NULL){
    	printf("Erro na abertura do arquivo.\n");
    	return 0;
    }
    while( (percorre = fgetc(f_alunos)) != EOF ){
    	if(percorre == '\n')
    		n_alunos++;
    }
    fclose(f_alunos);
	
	//Leitura do número de provas (embora nos exemplos seja fixo - 10) para ver os pesos.
    f_pesos = fopen (nome_arquivo_pesos, "r");
    if(f_pesos == NULL){
    	printf("Erro na abertura do arquivo.\n");
    	return 0;
    }
    while( (percorre = fgetc(f_pesos)) != EOF ){
    	if(percorre == '\n')
    		n_provas++;
    }
    fclose(f_pesos);
    
    //Leitura dos dados do arquivo dados_alunos_min.txt
    f_alunos = fopen (nome_arquivo_registro, "r");
    if(f_alunos == NULL){
    	printf("Erro na abertura do arquivo.\n");
    	return 0;
    }
    for(i=0 ; i<n_alunos ; i++){
    	fscanf(f_alunos, "%lld", &registro[i].cpf);
    	fscanf(f_alunos, "%d", &registro[i].nusp);
    	fscanf(f_alunos, "%s", registro[i].nome);
    }
    fclose(f_alunos);
    
    //Leitura dos dados do arquivo dados_pesos_min.txt
    f_pesos = fopen (nome_arquivo_pesos, "r");
    if(f_pesos == NULL){
    	printf("Erro na abertura do arquivo.\n");
    	return 0;
    }
    for(i=0 ; i<n_provas ; i++)
    	fscanf(f_pesos, "%d", &pesos_provas[i]);
    fclose(f_pesos);

    //Leitura dos dados do arquivo dados_alunos_notas_min.txt
    f_notas = fopen (nome_arquivo_notas, "r");
    if(f_notas == NULL){
    	printf("Erro na abertura do arquivo.\n");
    	return 0;
    }
    for(i=0 ; i<n_alunos ; i++){
    	fscanf(f_notas, "%d", &notas_alunos[i].nusp);
    	for(j=0 ; j<n_provas ; j++){
    		fscanf(f_notas, "%f", &notas_alunos[i].notas[j]);
    	}
    }
    fclose(f_notas);

    ComputaMedias(notas_alunos, pesos_provas, medias_alunos, n_alunos, n_provas); 	
    ImprimeIntervalo(registro, notas_alunos, medias_alunos, n_alunos, n_provas, inicio, fim, ordem);
    ImprimeMaioresMenores(registro, notas_alunos, medias_alunos, n_alunos, n_provas, melhores_piores);

	return 0;
}