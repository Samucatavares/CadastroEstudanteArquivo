#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 100 //definiu-se uma constante que pode ser facilmente alterada para determinar o tamanho do vetor estrutura.
#define nmat 200
FILE *cd; // declaração do ponteiro para o arquivo "cd", que faz alusão a cadastro, possa ser manipulado
int x;
// declaração da estrutura CADASTRO e de um vetor estrutura que conterá as informações de todos alunos cadastrados.
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


//declaração dos protótipos das funções a serem utilizadas no programa
void controle(); // a função controle tem por objetivo verificar a existência de cadastros
void inserir(); // a função inserir tem por objetivo a inserção de dados pelo usuário para que as informações sejam gravadas no arquivo
void listar(); // a função listar abre o arquivo, lê os dados registrados e os lista
void pesquisar(); // a função pesquisar tem por objetivo dar a entrada da matrícul de um aluno para a busca de todas informações referentes ao mesmo
void ordenar(); // a função ordenar tem por objetivo ajeitar os dados em ordem alfabética de nome
void abrir(); // a função abrir é responsável por abrir o arquivo de cada turma
void mga();// a função tem por objetivo calcular o coeficiente de rendimento acadêmico. *obs.: nesse caso considera-se o MGA (média geral acumulada)
/*
A função main contém as diretrizes gerais do programa, englobando um menu de opções que guia o usuário pelas funções do programa. Utilizou-se para isso
um comando "do,while" aliado a uma estrutura condicional do tipo "switch case" para coordenar as opções de execução do programa.
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
A função controle tem por objetivo verificar a integridade do arquivo, bem como auxiliar no controle dos dados já registrados/manipulados.
De maneira geral, abre-se o arquivo para a manipulação das informações, ou quando não existe ou há erro no arquivo, informa-se ao usuário.
Para controlar o número de cadastros, utiliza-se da função "fseek", posicionando o ponteiro no fim do arquivo e a variável "x" é igualada à função
"ftell" que informa o tamanho do arquivo. A variável "x" é então dividida pelo tamanho da estrutura, fato que nos retorna o número presente de cadastros.
A função "rewind" retorna o ponteiro à posição inicial, evitando qualquer problema ao se percorrer o arquivo. Caso exista algum cadastro, ou seja, "x>=1"
indica-se ao usuário o número de cadastros, ou, quando não existir nenhum cadastro exibe-se uma mensagem na tela.
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
A função inserir abre o arquivo, ou verifica a existência do mesmo, dando essa informação ao usuário. A variável "k" é inicializada com intuito de ser
utilizada para o looping do laço "for", que irá fazer o cadastro e após fechar o arquivo, garantindo que as informações foram salvas, irá passar a informação
à função "controle" de que mais um cadastro foi realizado com sucesso.
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
        printf("Insira o número de materias do aluno\n");
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
A função listar tem por objetivo listar todas as informações já manipuladas por meio do arquivo. Verifica-se inicialmente a existência do arquivo e se não
há nenhum erro que possa comprometê-lo, retornando a informação, quando conveniente, ao usuário. São inicializadas duas variáveis: "cont" e "count".
A variável "cont" armazena o número de cadastros, para o controle do looping "for" na leitura das informações. Esse armazenamento é semelhante ao ocorrido
na função controle, utilizando funções referentes à manipulação de arquivos: fseek, fteel e rewind. A variável "count" serve como índice para o laço "for"
e, portanto, índice do vetor estrutura que contém as informações cadastradas. Assim, por meio da função "fread", cujo buffer adotado é o vetor estrutura, lê-se
cada conjunto de informações referente a um aluno, um a um, e as informações lidas são printadas na tela.
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
//por meio da função STRCMP os dados de matrícula inserido e cadastrado são comparados e caso sejam iguais o usuário recebe o texto formatado em relação ao 
//aluno que tenha essa matrícula.Caso dois alunos tenham a mesma matrícula ambos terão seus dados printados


void pesquisar()
{
	char mat2[18];
	int p = 0; // índice para o vetor
	int leitura = 1; // enquanto o fread ler alguma coisa ele retorna 1, verificando a existência de informação
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



