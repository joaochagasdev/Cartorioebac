#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Funçao responsavel por cadastrar os usuarios no sistema
{
	//inicio ciraçao de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criaçao de variaveis 
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informaçoes do usuario
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf);  //responsavel por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
     
}

int consulta()

{
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file== NULL)
    {
    	printf("Nao foi possivel abrir o arquivo, nao foi localizado1!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
     system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usuario nao se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
    {
	
	int opcao=0; //Definindo Variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {

	system("cls");
	
	setlocale(LC_ALL, "Portuguese");
    
	printf("###Cartório EBAC### \n\n ");
	printf("Escolha a opção desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistem\n\n");
	printf("Opcao:" ); //fim do menu
	
	scanf("%d" , &opcao); //armazenando a escolha do usuario
	
	system("cls"); //responsavel por limpar a tela
	
	switch(opcao)
	{
		case 1:
		registro(); //chamada de funçoes
		break;
		
		case 2: 
	    consulta();
		break;
		
		case 3: 
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n+");
		return 0;
		break;

		
		default:
		printf("Essa opcao nao esta disponivel ");
	    system("pause");
	    break;
   } //fim da seleçao 
   
   }
}
