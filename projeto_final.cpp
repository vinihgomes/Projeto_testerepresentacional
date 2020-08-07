//Bibliotecas
#include <stdlib.h> 
#include <iostream> // cin e cout
#include <locale.h> // setlocale
#include <string.h> // char
#include <stdio.h>  
#include <conio.h> //getche
#include <windows.h>  /* para usar a fun��o sleep */

using namespace std;

void master(); //m�dulo MASTER
void perguntas(); //M�dulo global teste (j� que usa tanto no MASTER quando no USER
FILE *arq, *resultado, *referencial, *arq2; //ponteiros de arquivos
typedef struct cadastrar_questionario //struct questionario
{
	char pergunta[100], opc_1[100], opc_2[100], opc_3[100], opc_4[100];
}cadastrar_questionario;

cadastrar_questionario questionario[5];

typedef struct resultado_teste // struct respostas do questionario
{
	int quest_1, quest_2, quest_3, quest_4;
}resultado_teste;

resultado_teste respostas;

char nome[100], prontuario[9], usuario[100]="RESULTADO_"; //vari�veis do tipo char, respons�veis por receber nome, prontuario e a "usuario" concatenar o nome e prontuario anterior

int main (void)
{	
	int i=0;//contador do char usuario, para substituir por _ os espa�os
	setlocale (LC_ALL, "Portuguese"); //permitir caracteres como � e acentos
	cout << "\t\t\t\t********************************\n";
	cout << "\t\t\t\t*       Informe seu nome:      *\n\n"; //ok
	fflush (stdin); // limpa o buffer do teclado
	cout << "\t\t\t\t=>  ";
	strupr(gets (nome)); // converter para maiusculo com o strupr
	
	cout << "\n\n\n\t\t\t\t*    Informe seu prontu�rio:   *\n\n"; //ok
	fflush (stdin); //ok
	cout << "\t\t\t\t=>  ";
	strupr(gets (prontuario)); //ok
	cout << "\t\t\t\t********************************\n";
	strcat (usuario,nome);
	strcat (usuario,"_");
	strcat (usuario,prontuario);
	strcat (usuario,".txt");
	while (usuario[i] != '\0') {
		if (usuario[i] == ' ')
		usuario[i] = '_';
	    i++;
	}
	if ((strcmp (nome, "MASTER") == 0)) //ok
		master(); //ok
	else //ok		
		perguntas();
}
void master() 
{	
	char opc;
	void cadastro();
	void visualizar();
	void sobre();	
	system("cls");
	while (opc != 'f' && opc != 'F')
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n";
		cout << "\t\t\t\t***********************************************************\n";
		cout << "\t\t\t\t*                                                         *\n";
		cout << "\t\t\t\t*   USU�RIO LOGADO COMO MASTER, ESCOLHA UMA OP��O ABAIXO: *\n";
		cout << "\t\t\t\t*                                                         *\n";	
		cout << "\t\t\t\t*                1. Cadastrar question�rio                *\n";
		cout << "\t\t\t\t*                2. Visualizar question�rio               *\n";
		cout << "\t\t\t\t*                3. Realizar teste                        *\n";
		cout << "\t\t\t\t*                4. Sobre o teste                         *\n";
		cout << "\t\t\t\t*                F. Fim                                   *\n";     
		cout << "\t\t\t\t*                                                         *\n";
		cout << "\t\t\t\t***********************************************************\n";
		cout << "\t\t\t\t";
	 // preciso receber o 'opc' como char.
		opc = getche();
		getch();
		
		switch (opc)
		{
			case '1': 
				cadastro();
			break;
			case '2':
				visualizar();
			break;
			case '3':
				perguntas();
			break;
			case '4': 
				sobre();
			break;
			case 'F': 
			case 'f': 
				cout << "\n\n programa ser� encerrado\n\n";
				//getch();
				exit(1);
			break;
			default: 
				cout << "Op��o inv�lida.\n";
		}
	}

}
void cadastro()
{
	setlocale (LC_ALL, "Portuguese"); //ok	
	char frase[100];
	int i;
		arq = fopen ("TESTE_REPRESENTACIONAL.DAT" , "w");
		if ( arq == NULL ) //
			cout << "\nImposs�vel criar arquivo TESTE_REPRESENTACIONAL.dat!";
		else
	{
		system("cls");
			cout << "CADASTRO DE QUESTION�RIO\n\n\n";
		for (i=0; i<5; i++)
		{	
			cout << "***********************************************************\n";
			cout << "*               Digite a pergunta n�mero" << i+1 << ":                *\n\n\n";
			fflush(stdin);
			gets(questionario[i].pergunta);
		//	system("cls");
			cout << "*               Digite a alternativa 1:                   *\n\n";
			fflush(stdin);
			gets(questionario[i].opc_1);
		//	system("cls");
			cout << "*               Digite a alternativa 2:                   *\n\n";
			fflush(stdin);
			gets(questionario[i].opc_2);
		//	system("cls");
			cout << "*               Digite a alternativa 3:                   *\n\n";
			fflush(stdin);
			gets(questionario[i].opc_3);
		//	system("cls");
			cout << "*               Digite a alternativa 4:                   *\n\n";
			fflush(stdin);
			gets(questionario[i].opc_4);
			cout << "***********************************************************\n";
			cout << "Aperte qualquer tecla para continuar: ";
			getch();
			system("cls");
		}
		fwrite(&questionario, sizeof(cadastrar_questionario), 5,arq);
		fclose(arq);
		cout << "Question�rio cadastrado com sucesso!";
	}
}
void visualizar() //ok
{
	int contador, j, i;
    system ("cls");
    cout << "\n\n\n\n";
    cout << "***************************************************************************\n";
    cout << "         Seu question�rio est� sendo carregado. Por favor, aguarde!        ";
    cout << "\n\n";
    cout << "Ap�s realizar a leitura, feche o arquivo para dar continuidade no programa.\n\n";
    contador = 0; 
    while ( contador < 75 )
    {
        cout << "�";
        Sleep(10);
        contador = contador + 1;
    }
    cout << "\a";
    cout << "\n\nTeste aberto, confira informa��es no bloco de notas.\n\n";
    arq = fopen("TESTE_REPRESENTACIONAL.DAT", "r");
	if (arq != NULL)
	{
		system("cls");
		system ("color a");
		setlocale (LC_ALL, "Portuguese");					
		for(j=0; j<5;j++)
		{
			system("cls");
			while ( !feof(arq) )
			{
				fread(&questionario, sizeof(cadastrar_questionario), 5, arq);
				if ( !feof(arq) )  
				{	
					for(i=0; i<5;i++)
					{
						arq2 = fopen("QUESTIONARIO_1.TXT","w");
						if (arq2 != NULL)
						fwrite(&questionario, sizeof(cadastrar_questionario), 5,arq2);
						fclose(arq2);
					}
				}
			}
		}
		cout << "Question�rio aberto! ";
		system("QUESTIONARIO_1.TXT");
		cout << "Para continuar, pressione qualquer tecla!";
		cout << "\n***************************************************************************\n";
	}
}
void sobre() // ok
{
	int contador;
    system ("cls");
    cout << "\n\n\n\n";
    cout << "***************************************************************************\n";
    cout << "\t\t      Arquivo est� sendo carregado";
    cout << "\n\n";
    cout << "Ap�s realizar a leitura, feche o arquivo para dar continuidade no programa.\n\n";
    /* Monta a "barra de progress�o" */
    contador = 0; /* zera o contador */
    while ( contador < 75 )
    {
        /* Mostra um quadradinho */
        cout << "�";
        /* "pausa dram�tica" */
        Sleep(25);
        /* aumenta o contador de 1 */
        contador = contador + 1;
    }
    cout << "\a";
	system("sobre.txt");
	cout << "\n\nTeste aberto, confira informa��es no bloco de notas.\n\n";
	cout << "Para continuar, pressione qualquer tecla!";
	cout << "\n***************************************************************************\n";
	getch();
	
}
void perguntas()
{
	char perfil[100], abrir;
	int cines=0, aud=0, vis=0, dig=0, maior=0;
	int igual = 0;
	int i,j;
	arq = fopen("TESTE_REPRESENTACIONAL.DAT", "r");
	if (arq != NULL)
	{
		system("cls");
		system ("color a");
		setlocale (LC_ALL, "Portuguese");					
		for(j=0; j<5;j++)
		{
			system("cls");
			while ( !feof(arq) )
			{
				fread(&questionario, sizeof(cadastrar_questionario), 5, arq);
				if ( !feof(arq) )  
				{	
					for(i=0; i<5;i++)
					{
						system("cls");
						cout << "\tTeste do sistema representacional\n\n";
						cout << "********************************************\n";
						cout << "Nas frases a seguir, pontue com:            \n";
						cout << "4 a que melhor descreve voc�;               \n";
						cout << "3 a pr�xima melhor descri��o;               \n";
						cout << "2 a pr�xima melhor;                         \n";
						cout << "1 aquela que menos descreve voc�.           \n";
						cout << "********************************************\n\n";						
						cout << "\n" << i+1 << ": " << questionario[i].pergunta;
						cout << "\na) " << questionario[i].opc_1;
						cout << "\nb) " << questionario[i].opc_2;
						cout << "\nc) " << questionario[i].opc_3;
						cout << "\nd) " << questionario[i].opc_4;
						do
						{
							cout << "\n\na) ";
							cin >> respostas.quest_1;
							if (respostas.quest_1>4 || respostas.quest_1 < 1)
								cout << "Valor inv�lido, favor, inserir n�mero de 1 � 4 conforme orientado acima!\n";
						}while(respostas.quest_1> 4 || respostas.quest_1 < 1);
						cines = cines + respostas.quest_1;
						cout << "\n";
						do
						{
							cout << "b) ";
							cin >> respostas.quest_2;
							if(respostas.quest_2> 4 || respostas.quest_2 < 1 || respostas.quest_2 == respostas.quest_1)
								cout << "Op��o inv�lida ou repetida. Responda novamente!\n";
						}while(respostas.quest_2> 4 || respostas.quest_2 < 1 || respostas.quest_2 == respostas.quest_1);
						aud = aud + respostas.quest_2;
						cout << "\n";
						do
						{
							cout << "c) ";
							cin >> respostas.quest_3;
							if(respostas.quest_3> 4 || respostas.quest_3 < 1 || respostas.quest_3 == respostas.quest_1 || respostas.quest_3 == respostas.quest_2)
								cout << "Op��o inv�lida ou repetida. Responda novamente!\n";
						}while(respostas.quest_3> 4 || respostas.quest_3 < 1 || respostas.quest_3 == respostas.quest_1 || respostas.quest_3 == respostas.quest_2);
						vis = vis + respostas.quest_3;
						cout << "\n";
						do
						{
							cout << "d) ";
							cin >> respostas.quest_4;
							if(respostas.quest_4> 4 || respostas.quest_4 < 1 || respostas.quest_4 == respostas.quest_1 || respostas.quest_4 == respostas.quest_2 || respostas.quest_4 == respostas.quest_3)
								cout << "Op��o inv�lida ou repetida. Responda novamente!\n";
						}while(respostas.quest_4> 4 || respostas.quest_4 < 1 || respostas.quest_4 == respostas.quest_1 || respostas.quest_4 == respostas.quest_2 || respostas.quest_4 == respostas.quest_3);
						dig = dig + respostas.quest_4;	
					}
				}
			}
		}
		fclose(arq); /* Fecha o arquivo */
		getch();
	}
	cines = cines*2;
	aud = aud*2;
	dig = dig*2;
	vis = vis*2;	
	resultado = fopen(usuario, "a");
	if (maior < cines)
	maior = cines;
	if (maior < aud)
	maior = aud;
	if (maior < dig)
	maior = dig;
	if (maior < vis)
	maior = vis;
	if ( resultado == NULL ) 
		cout << "\nImposs�vel criar arquivo!";
	else
		fprintf	(resultado, "====================PERFIL REPRESENTACIONAL DE ");
		fprintf (resultado, "%s",nome);
		fprintf (resultado, "====================");
		fprintf (resultado, "\n%d%% Cinest�sico \t %d%% Digital \t %d%% Auditivo \t %d%% Visual",cines,dig,aud,vis);
		fprintf (resultado, "\n=======================================================================");
		fprintf (resultado, "\nAlgumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as chamadas auditivas. ");
		fprintf (resultado, "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.");
		fprintf (resultado, "\nAs cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas e as emo��es.");
		fprintf (resultado, "\nJ� as visuais aprendem melhor quando se valendo da vis�o.");
		fprintf (resultado, "\n=======================================================================");
		if(maior == cines)
			fprintf (resultado, "\nSeu perfil � CINEST�SICO.");
		if(maior == aud)
			fprintf (resultado, "\nSeu perfil � AUDITIVO.");	
		if(maior == dig)
			fprintf (resultado, "\nSeu perfil � DIGITAL.");
		if(maior == vis)
			fprintf (resultado, "\nSeu perfil � VISUAL.");
		fclose (resultado);
		system("cls");
		abrir = 'n';
		do
		{
		cout << "\nResultado criado com sucesso! Deseja abrir o arquivo agora? (s = SIM ou n = N�O)\n";
		abrir = getche();
		getch();
		}while (abrir != 's' && abrir != 'n' && abrir != 'S' && abrir != 'N');
		switch(abrir)
		{
			case 'n':
			case 'N':
				cout << "\n\n\nVoc� optou por n�o abrir o arquivo. Para acessar futuramente, procure o arquivo pelo nome " << usuario;
			break;
			case 's':
			case 'S':
				int contador;
    			system ("cls");
    			cout << "\n\n\n\n";
    			cout << "***************************************************************************\n";
    			cout << "         Seu resultado est� sendo carregado. Por favor, aguarde!        ";
   				cout << "\n\n";
   				contador = 0; /* zera o contador */
    			while ( contador < 50 )
    			{
			        cout << "�";
	        		Sleep(20);
	        		contador = contador + 1;
    			}
	    		cout << "\a";
	    		cout << "\n\nTeste aberto, confira informa��es no bloco de notas.\n\n";
				system(usuario);
				cout << "Para continuar, pressione qualquer tecla!";
				cout << "\n***************************************************************************\n";
				getch();
			break;
			default:
				cout << "Op��o inv�lida!";
			break;
		}
		getch();
		
		sobre();		
}

	
	

