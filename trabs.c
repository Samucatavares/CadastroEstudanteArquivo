#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 100 //definiu-se uma constante que pode ser facilmente alterada para determinar o tamanho do vetor estrutura.
#define nmat 200
FILE *cd; // declara��o do ponteiro para o arquivo "cd", que faz alus�o a cadastro, possa ser manipulado
int x;
// declara��o da estrutura CADASTRO e de um vetor estrutura que conter� as informa��es de todos alunos cadastrados.
typedef struct CADASTRO
{
	char nome_aluno[60];
	char mat[18];
	char ingresso[6];
	char endereco[150];
	char telefone[12];
	char email[50];
	int numat;
	double nota[100];
	double ch[100];

}cad;
cad conjunto[num];
char nom;


//declara��o dos prot�tipos das fun��es a serem utilizadas no programa
void controle(); // a fun��o controle tem por objetivo verificar a exist�ncia de cadastros
void inserir(); // a fun��o inserir tem por objetivo a inser��o de dados pelo usu�rio para que as informa��es sejam gravadas no arquivo
void listar(); // a fun��o listar abre o arquivo, l� os dados registrados e os lista
void pesquisar(); // a fun��o pesquisar tem por objetivo dar a entrada da matr�cul de um aluno para a busca de todas informa��es referentes ao mesmo
void ordenar(); // a fun��o ordenar tem por objetivo ajeitar os dados em ordem alfab�tica de nome
void abrir(); // a fun��o abrir � respons�vel por abrir o arquivo de cada turma
void mga();// a fun��o tem por objetivo calcular o coeficiente de rendimento acad�mico. *obs.: nesse caso considera-se o MGA (m�dia geral acumulada)
/*
A fun��o main cont�m as diretrizes gerais do programa, englobando um menu de op��es que guia o usu�rio pelas fun��es do programa. Utilizou-se para isso
um comando "do,while" aliado a uma estrutura condicional do tipo "switch case" para coordenar as op��es de execu��o do programa.
*/
int main(int argc, char *argv[])
{
	int opcao = 0;
	int opcaomenu = 0;



	printf("CADASTRO  DE ALUNOS\n");
	printf("Insira o ano do cadastro\n");
	printf("\n\nAperte a tecla ENTER para iniciar o menu de opcoes ou ESC para finalizar o programa: ");
	opcao = getch();
	if(opcao==27)
	{
		exit(0);
	}
	do
	{
		system("cls");
		printf("\nSELECIONE UMA OPCAO: \n(1) Inserir dados \n(2)Listar dados \n(3)Pesquisar dados \n(4)Verificar numero de cadastros \n(5)Ver o MGA\n(6)Finalizar o programa\n");
         printf("\n");
		scanf("%d",&opcaomenu);
		printf("\n");
		switch(opcaomenu)
		{
			case 1:
				inserir();
			break;
			case 2:
				listar();
			break;
			case 3:
				pesquisar();
			break;
			case 4:
				controle();
			break;
			case 5:
                mga();
                break;

			default:
				exit(0);

		}
	}while(opcaomenu<6);

	getchar();
	return 0;
}
void abrir(char tip[3]){
	char ano[20];
	printf("Insira o ano e a turma da operacao\n");
	fflush(stdin);
	gets(ano);

	cd=fopen(ano,tip);
			
			/*if (cd == NULL)
	{
		printf("\n\nErro ao abrir!\n");
		getchar();
	}*/
    fseek(cd,0, SEEK_END);
	x=ftell(cd);
	x=x/sizeof(cad);
	rewind(cd);
	if(x==0) printf("Ainda nao existem cadastros!\n");
}

/*
A fun��o controle tem por objetivo verificar a integridade do arquivo, bem como auxiliar no controle dos dados j� registrados/manipulados.
De maneira geral, abre-se o arquivo para a manipula��o das informa��es, ou quando n�o existe ou h� erro no arquivo, informa-se ao usu�rio.
Para controlar o n�mero de cadastros, utiliza-se da fun��o "fseek", posicionando o ponteiro no fim do arquivo e a vari�vel "x" � igualada � fun��o
"ftell" que informa o tamanho do arquivo. A vari�vel "x" � ent�o dividida pelo tamanho da estrutura, fato que nos retorna o n�mero presente de cadastros.
A fun��o "rewind" retorna o ponteiro � posi��o inicial, evitando qualquer problema ao se percorrer o arquivo. Caso exista algum cadastro, ou seja, "x>=1"
indica-se ao usu�rio o n�mero de cadastros, ou, quando n�o existir nenhum cadastro exibe-se uma mensagem na tela.
*/
void controle()
{
	int x = 0;
   abrir("r+b");
	fseek(cd,0, SEEK_END);
	x=ftell(cd);
	x=x/sizeof(cad);
	printf("\n\n%d\n\n",x);
	rewind(cd);
	if(x==0) printf("Ainda nao existem cadastros neste ano!\n");
	getchar();
	system("pause");
}

/*
A fun��o inserir abre o arquivo, ou verifica a exist�ncia do mesmo, dando essa informa��o ao usu�rio. A vari�vel "k" � inicializada com intuito de ser
utilizada para o looping do la�o "for", que ir� fazer o cadastro e ap�s fechar o arquivo, garantindo que as informa��es foram salvas, ir� passar a informa��o
� fun��o "controle" de que mais um cadastro foi realizado com sucesso.
*/
void inserir()
{
    int i;

    int k = 0;
   abrir("a+b");

	for(k=0;k<1;k++)
	{
        getchar();
		printf("Digite o nome da aluno: ");
		gets(conjunto[k].nome_aluno);
		fflush(stdin);
		printf("Digite a mat da aluno: ");
		gets(conjunto[k].mat);
		fflush(stdin);
		printf("Digite o ano de ingresso do aluno: ");
		gets(conjunto[k].ingresso);
		fflush(stdin);
		printf("Digite o endereco da aluno: ");
		fflush(stdin);
		gets(conjunto[k].endereco);
       	fflush(stdin);
		printf("Digite o telefone da aluno: ");
		gets(conjunto[k].telefone);
		fflush(stdin);
		printf("Digite o e-mail de contato da aluno: ");
		gets(conjunto[k].email);
        fflush(stdin);
        printf("Insira o n�mero de materias do aluno\n");
        scanf("%d",&conjunto[k].numat);
        for(i=0;i<conjunto[k].numat;i++){
        printf("Insira a nota na  materia %d\n",i+1);
        scanf("%lf",&conjunto[k].nota[i]);
        fflush(stdin);
        printf("Insira o numero de aulas da materia %d\n",i+1);
        fflush(stdin);
        scanf("%lf",&conjunto[k].ch[i]);
       }
    fwrite(&conjunto[k],sizeof(cad),1,cd);


	}
    fclose(cd);
}

/*
A fun��o listar tem por objetivo listar todas as informa��es j� manipuladas por meio do arquivo. Verifica-se inicialmente a exist�ncia do arquivo e se n�o
h� nenhum erro que possa compromet�-lo, retornando a informa��o, quando conveniente, ao usu�rio. S�o inicializadas duas vari�veis: "cont" e "count".
A vari�vel "cont" armazena o n�mero de cadastros, para o controle do looping "for" na leitura das informa��es. Esse armazenamento � semelhante ao ocorrido
na fun��o controle, utilizando fun��es referentes � manipula��o de arquivos: fseek, fteel e rewind. A vari�vel "count" serve como �ndice para o la�o "for"
e, portanto, �ndice do vetor estrutura que cont�m as informa��es cadastradas. Assim, por meio da fun��o "fread", cujo buffer adotado � o vetor estrutura, l�-se
cada conjunto de informa��es referente a um aluno, um a um, e as informa��es lidas s�o printadas na tela.
*/
void listar()
{
    int i;
	   abrir("rb");

	if(cd == NULL)
	{
		printf("\n\nErro ao abrir!\n");
		exit(0);
		system("pause");
		getchar();
	}
	else{


	int cont  = 0;
	int count  = 0;
	fseek(cd,0,SEEK_END);
	cont = ftell(cd);
	cont = cont/sizeof(cad);
	rewind(cd);

	for(count = 0; count<cont; count++)
	{
		fread(&conjunto[count],sizeof(cad),1,cd);
		printf("\naluno: %s ", conjunto[count].nome_aluno);
        printf("\nmat: %s", conjunto[count].mat);
        printf("\ningresso: %s",conjunto[count].ingresso);
		printf("\nEndereco: %s",conjunto[count].endereco);
		printf("\nTelefone: %s", conjunto[count].telefone);
        printf("\nE-mail: %s", conjunto[count].email);
        printf("\nO numero de materias: %d\n",conjunto[count].numat);
       ;

        printf("\n");

	}
	}

	printf("\n");
	getchar();
	fflush(stdin);
	system("pause");

}
//por meio da fun��o STRCMP os dados de matr�cula inserido e cadastrado s�o comparados e caso sejam iguais o usu�rio recebe o texto formatado em rela��o ao 
//aluno que tenha essa matr�cula.Caso dois alunos tenham a mesma matr�cula ambos ter�o seus dados printados


void pesquisar()
{
	char mat2[18];
	int p = 0; // �ndice para o vetor
	int leitura = 1; // enquanto o fread ler alguma coisa ele retorna 1, verificando a exist�ncia de informa��o
	int ct; // contador
	abrir("rb");
	if(cd==NULL){
		
			exit(0);
		system("pause");
	}

	else
    {


	fflush(stdin);
	printf("Insira o Numero de Matricula\n");
	gets(mat2);


		int cont  = 0,i;
	int count  = 0;
	fseek(cd,0,SEEK_END);
	cont = ftell(cd);
	cont = cont/sizeof(cad);
	rewind(cd);

	for(count = 0; count<cont; count++)
	{
			fread(&conjunto[count],sizeof(cad),1,cd);


		if(strcmp(mat2,conjunto[count].mat)==0){
		printf("\naluno: %s ", conjunto[count].nome_aluno);
        printf("\nmat: %s", conjunto[count].mat);
        printf("\ningresso: %s", conjunto[count].ingresso);
		printf("\nEndereco: %s", conjunto[count].endereco);
		printf("\nTelefone: %s", conjunto[count].telefone);
        printf("\nE-mail: %s", conjunto[count].email);
        printf("\nO numero de materias: %d\n",conjunto[count].numat);


	}

        printf("\n");
        }

	printf("\n");
	getchar();
	system("pause");
    }

}
void mga()
{
     int i;
	   abrir("rb");

	if(cd == NULL)
	{
		printf("\n\nErro ao abrir!\n");
		getchar();
	}
	int cont  = 0;
	int count  = 0;
	double  cr;
   double cht;
    double notat;
	fseek(cd,0,SEEK_END);
	cont = ftell(cd);
	cont = cont/sizeof(cad);
	rewind(cd);


	for(count = 0; count<cont; count++)
	{
	    cr=0;
	    cht=0;
	    notat=0;
		fread(&conjunto[count],sizeof(cad),1,cd);
		printf("\naluno: %s ", conjunto[count].nome_aluno);
        printf("\nmat: %s", conjunto[count].mat);
		for(i=0;i<conjunto[count].numat;i++){
            notat+=conjunto[count].nota[i]*conjunto[count].ch[i];
            cht+= conjunto[count].ch[i];

		}
        cr=notat/cht;
        printf("\nMGA aluno %lf",cr);
        printf("\n");

	}
	printf("\n");
	getchar();
	fflush(stdin);
	system("pause");

}



