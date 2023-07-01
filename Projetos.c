#include <stdio.h>

typedef struct projeto{
	char nome[20];
	int codigo;
	float despesa;
	float receita;
	float saldo;
}proj;
int cod = -1;
proj projetos[9];

int adicionar();
int remover();
int exibirproj();
int main(){
adicionar();
adicionar();
adicionar();
exibirproj();
}
int adicionar(){
	if(cod == 9){
		printf("\nLista de projetos cheia.\n");
		}else{
			proj novoproj;
			printf("Nome do projeto: ");
			fflush(stdin);
			fgets(novoproj.nome,20,stdin); printf("\n");
			fflush(stdin);
			printf("Receita: ");
			fflush(stdin);
			scanf("%f",&novoproj.receita); printf("\n");
			printf("Despesas: ");
			fflush(stdin);
			scanf("%f",&novoproj.despesa); printf("\n");
			novoproj.saldo = (novoproj.receita - novoproj.despesa);
			cod++;
			novoproj.codigo = cod;
			projetos[cod] = novoproj;	
		}
}
int remover(){
	if(cod == -1){
		printf("\nLista de projetos vazia.\n");
		}else{
			cod--;
			printf("Projeto removido com sucesso!");
	}
}
int exibirproj(){
	if(cod == -1){
		printf("Lista de projetos vazia.");
	}else{
		for(int i = 0; i < cod; i++){	
			printf("\n\nCodigo: %i  Projeto: %s  Receita: R$ %.2f  Despesas: R$ %.2f  Saldo: R$ %.2f",projetos[i].codigo,projetos[i].nome,projetos[i].receita,projetos[i].despesa,projetos[i].saldo);
		}
	}
}





