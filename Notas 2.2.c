#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno{
	
	char nome[20];
	int matric;
	float p1;
	float p2;
	float p3;
	char desc[140];
	
}aluno;

typedef struct turma{
	
	char nomet[20];
	aluno intgr[10];
	
}turma;

int indexmat = -1;
aluno matriculados[10];
int quantidade = 0;

int criarAluno();
int exibirNotas();
int exibirMedias();
void relatorio();
int criarTurma();

int media(aluno x);
int main() {
	setlocale(LC_ALL,"");
	
	
	int op;
	int opc;
	int opcc;
	do{
		
		printf("------------------------------------------\n");
		printf("1 - Gerenciamento de turmas\n");
		printf("2 - Gerenciamento de alunos\n");
		printf("9 - Encerrar programa\n");
		printf("------------------------------------------\n");
		switch(op){
			case 1 :
				system("cls");
				
				do{
					printf("1 - Cadastrar turma\n");
					printf("2 - Exibir alunos\n");
					
					printf("\nComando: ");
					scanf("%i", &opcc); printf("\n");
					
					switch(opcc){
						case 1:
							
							criarTurma();
							
							break;
						
							case 2:
								
								
								break;
								
								case 9:
									printf("Encerrando...\n");
									
									break;
									
									default:
		
		                                  printf("\nNenhuma opção encontrada. Tente novamente.\n");
		                                  
		                                  break;
									
											}
					
				}while(opcc != 9);
				               printf("Comando principal: \n");
                               scanf("%i", &op);
                               system("cls");
				
				
				
				
				
				
				
				
				
				
				
				
						     break;
				
			case 2 :
				system("cls");
				do{
		printf("------------------------------------------\n");
		printf("GERENCIAMENTO DE ALUNOS\n");
		
		if(indexmat == -1){
			printf("\nNenhum aluno matriculado no momento.\n\n");
		}else{
		if(indexmat == 0){
		
		printf("\n%i aluno matriculado\n\n", indexmat + 1);
	}else{
		printf("\n%i alunos matriculados\n\n", indexmat + 1);
	}
		
	    }
	    
		printf("1 - Cadastrar novo aluno\n");
		printf("2 - Exibir todas as notas\n");
		printf("3 - Exibir todas as médias\n");
		printf("4 - Limpar tela\n");
		printf("5 - Fazer relatório\n");
		printf("6 - Encerrar programa\n");
	    printf("------------------------------------------\n");
		
		
		printf("\nComando: "); 
		scanf("%i", &opc); printf("\n");
		system("cls");
		
		switch (opc){
	case 1:
		
		printf("\nInforme os dados do aluno:\n");
		criarAluno();
		printf("\nAluno criado!\n");
		
		break;
		
	case 2:      
		
		printf("Notas dos alunos");
		exibirNotas();
		
		break;
		
	case 3:
		
		printf("Médias dos alunos:\n");
		exibirMedias();
		
		break;
	case 4:
		
		system("cls");
		break;
	case 5:
		
		relatorio();
		printf("\nRelatorio criado!\n");
		
		break;
	case 6:
		
		
		printf("\nEncerrando... \n");
        
        
		
		break;
		
	default:
		
		printf("\nNenhuma opção encontrada. Tente novamente.\n");
		break;
	
}
     
     
	}while(opc != 6);
	
	break;
	
	case 9:
	
	printf("\nEncerrando...\n");
	
	
	break;
	
	default:
		
		if(op != 0){
		printf("\nNenhuma opção encontrada. Tente novamente.\n");
		}
	
	break;
		
	}
		
		printf("Comando principal: \n");
        scanf("%i", &op);
     system("cls");
	}while(op != 9);
	
	
	
	
	printf("\nEncerrando...\n");
	return 0;




    
}
int criarAluno(){
	if(quantidade == 10){
		printf("\nLista de matrículas está cheia.");
	}else{
	indexmat++;
	aluno novo;
	
	printf("Matricula: ");
	scanf("%i", &novo.matric);
	printf("Nome do aluno: "); 
	fflush(stdin);
	fgets(novo.nome, 20, stdin);
	
	printf("Nota na P1: ");
	scanf("%f",&novo.p1);
	
	printf("Nota na P2: ");
	scanf("%f", &novo.p2);
	
	printf("Nota na P3: ");
	scanf("%f", &novo.p3);
	
	printf("Descrição:");
	fflush(stdin);
	fgets(novo.desc,140,stdin);
	
    printf("\nMatrícula: %i", novo.matric);
	printf("\nNome: %s\n", novo.nome);
	printf("P1: %.1f\n", novo.p1);
	printf("P2: %.1f\n", novo.p2);
	printf("P3: %.1f\n", novo.p3);
	printf("Descricao: %s", novo.desc);
	
	
	
	matriculados[indexmat] = novo;
	
	
	quantidade++;
	
	return 0;
}
}
int media(aluno x){
	
	float mediax;
	int soma;
	int avaliacoes = 3;
	soma = x.p1 + x.p2 + x.p3;
	
	mediax = soma / avaliacoes;
	
	return mediax;
}

int exibirNotas(){
	if(quantidade == 0){
		printf("\n Nenhum aluno matriculado no momento\n.");
	
	}else{
		
		for(int i = 0; i <= indexmat; i++){
			
			printf("Aluno: %s \nP1: %.2f \n", matriculados[i].nome,matriculados[i].p1);
			printf("P2: %.2f \n",matriculados[i].p2);
			printf("P3: %.2f \n",matriculados[i].p3);
			printf("Media: %i\n",media(matriculados[i]));
		
		}
	}
}

int exibirMedias(){
	
	printf("\n------------------------------------------\n");
	for(int i = 0; i <= indexmat; i++){
		
		printf("Aluno: %s - Media: %i", matriculados[i].nome, media(matriculados[i]));
		
	}
	printf("\n------------------------------------------\n");
}

void relatorio(){
	FILE *relat;
	relat = fopen("Relatório Geral","w");
	
	for(int i = 0; i <= indexmat; i++){
			fprintf(relat,"\n-------------------------------------------------------\n");
			fprintf(relat,"Aluno: %s \nMatricula: %i\nP1: %.2f \n", matriculados[i].nome,matriculados[i].matric,matriculados[i].p1);
			fprintf(relat,"P2: %.2f \n",matriculados[i].p2);
			fprintf(relat,"P3: %.2f \n",matriculados[i].p3);
			fprintf(relat,"Média: %i\n",media(matriculados[i]));
			fprintf(relat,"Descricao: %s",matriculados[i].desc);
		}
	fclose(relat);
}

int criarTurma(){
	
	int indext = 0;
	turma novaTurma;
	
	if(indexmat == -1){
		printf("Nenhum aluno matriculado no momento.\n");
	}else{
	
	for(int i = 0; i < 10; i++){
		
		int mat;
		
		
		printf("Matrícula do aluno %i: ", i + 1);
		scanf("%i", &mat); printf("\n");
		
		for(int i = 0; i <= indexmat; i++){
			
			if(matriculados[i].matric == mat){
				
				if(indext > indexmat){
					printf("Nenhum aluno encontrado.\n");
			}else{
			
				novaTurma.intgr[indext] = matriculados[i];
				
				}
			}else{
				indext++;
			      
				}
		} 
	
	 }
	    printf("Nome da Turma: ");
	    fflush(stdin);
	    fgets(novaTurma.nomet, 20, stdin);
		printf("%s \n",novaTurma.nomet);
		for(int i = 0; i <= indext; i++){
			printf("%s\n",novaTurma.intgr[i].nome);
		
	}

}
}












