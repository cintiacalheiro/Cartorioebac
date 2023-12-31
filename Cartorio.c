#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadstrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e a "w" significa escrever
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s,",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,nome); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,sobrenome); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,cargo); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as infroma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //coletando informa��o do usu�rio
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�tio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)
		{

			system("cls");
	
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
		printf("### Cart�tio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n");
		printf("\t4 - Sair do sistema!\n\n");
		printf("Op��o:");//fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
	
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
		
			case 2:
			consulta(); //chamada de fun��es
			break;
		
			case 3:
			deletar(); //chamada de fun��es
			break;
		
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;		
			} //fim da sele��o	
		}	
	}

	else
	printf("Senha incorreta!");
}
	
