#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadstrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e a "w" significa escrever
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s,",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,nome); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,sobrenome); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,cargo); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");	
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as infromações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n"); //coletando informação do usuário
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

	system("cls");
	
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	printf("### Cartótio da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a opção desejada do menu\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar os nomes\n");
	printf("\t3 - Deletar os nomes\n\n");
	printf("Opção:");//fim do menu
	
	scanf("%d",&opcao); //armazenando a escolha do usuário
	
	system("cls"); //responsavel por limpar a tela
	
	
	switch(opcao) //inicio da seleção do menu
	{
		case 1:
		registro(); //chamada de funções
		break;
		
		case 2:
		consulta(); //chamada de funções
		break;
		
		case 3:
		deletar(); //chamada de funções
		break;
				
		default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break;		
	} //fim da seleção	

	}
}
	
