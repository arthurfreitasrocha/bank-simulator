#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include "scanint.h"

struct conta_pessoal
{
    float saldo[2];
    float limite[2];
    float fatura[2];
};

struct conta_pessoal contP;

//VARIAVEIS IMPORTANTES
int bt=0;

char palavra1[1000][1000] = {"nome completo", "idade", "cpf", "celular", "renda", "endere�o", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", "nconta"};
char palavra2[1000][1000] = {"nome", "idade", "cpf", "celular", "renda", "endere�o", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", ""};

char contaP1[1000][1000] = {"saldo", "limite", "fatura"};
char contaP2[1000][1000] = {"0", "1000", "0"};

char cartao1[1000][1000] = {"ncartao", "nconta", "data_validade"};
char cartao2[1000][1000] = {"ncartao", "nconta", "data_validade"};

char Pseguranca1[1000][1000] = {"Qual o nome de seu primeiro animal de estima��o?", "Qual o nome da m�e de sua m�e?", "Qual o nome da primeira cidade que voc� morou?"};
char Pseguranca2[1000][1000] = {"PSEGURANCA1", "PSEGURANCA2", "PSEGURANCA3"};
char Pseguranca3[1000][1000] = {"PSEGURANCA1", "PSEGURANCA2", "PSEGURANCA3"};


//MAIN
int main() //FINALIZADO
{
    system("cls");

    setlocale(LC_ALL, "Portuguese");

    SetConsoleTitle("BANCO 99");

    del_doc();

    int i=0, resp=0;

    for(;i < 1;)
    {
        printf("\n\tBEM-VINDO AO BANCO 99!");
        printf("\n   O que voc� deseja fazer primeiro?");

        printf("\n\n[0] LOGIN\n");
        printf("[1] CADASTRO\n");
        printf("[2] SUPORTE\n");
        printf("[3] SAIR\n\n");

        printf("OP��O: "); resp=scanint(resp);

        if((resp < 0) || (resp > 3))
        {
            printf("Op��o Inv�lida\n\n");

            system("pause");
            system("cls");
        }

        if(resp == 0)
        {
            login();

            i = 1;
        }

        if(resp == 1)
        {
            cadastro();

            i = 1;
        }

        if(resp == 2)
        {
            suporte();

            i = 1;
        }

        if(resp == 3)
        {
            system("cls");

            printf("\n\tOBRIGADO POR USAR O BANCO 99!\n\n"); system("pause");

            exit(0);
        }
    }

    return NULL;
}

/*
//PROMO
int promo(float valor_compra)
{
    float pontos, pontos_F, cont;

    if(pontos == 20)
        pontos_F = pontos_F + 5;
    else
    {
        cont++;
        pontos = promo(valor_compra/5);
    }

    return pontos_F*cont;
}*/

//LOGIN
int login() //FINALIZADO
{
    system("cls");

    char txt[100], conteudo[100];
    char logadofile[100], senhafile[100], logado[100], senha[100];
    int ver=0;

    printf("\n\t\tFA�A SEU LOGIN NO BANCO 99!"); printf("\n\n      Esqueceu sua senha? Digite 99 no campo N� CONTA");

    printf("\n\nN� CONTA: "); gets(palavra2[13]);

    if(strcmp(palavra2[13], "99") == 0)
        esquecisenha();

    //TRATAMENTO DE ERROS

    strcpy(txt, palavra2[13]); strcat(txt, "\\"); strcat(txt, palavra2[13]); strcat(txt, "_NOME COMPLETO.txt");

    FILE *arq;

    arq = fopen(txt, "r");
    while(fgets(conteudo, 100, arq) != NULL)
    fclose(arq);

    if(arq == NULL)
    {
        printf("\nErro. Informa��o inv�lida\n\n"); system("pause");

        main();
    }

    strcpy(palavra2[0], conteudo);

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[0]); strcat(txt, ".txt");

    system("cls");

    printf("\n\t\tBEM-VINDO %s!\n\tPor favor, digite abaixo seu login e senha", strupr(palavra2[0]));


    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "BLOCK"); strcat(txt, ".txt");

    arq = fopen(txt,"r");
    fclose(arq);

    if(arq != NULL)
    {
        printf("\nPor medidas de seguran�a, esta conta est� BLOQUEADA\n\n"); system("pause");

        main();
    }

    if(bt == 3)
    {
        char comando[1000] = "enviar_email_block.py";

        printf("\nProcessando... Aguarde");

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "BLOCK"); strcat(txt, ".txt");

        arq = fopen(txt,"w");
        fclose(arq);


        email();

        system(comando);

        erro_conexao();



        strcpy(comando, "enviar_email_suporte_block.py");

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "NOME COMPLETO"); strcat(txt, ".txt");

        FILE *arq;

        arq = fopen("3.txt", "w");
        fprintf(arq, "%s", palavra2[0]);
        fclose(arq);

        system(comando);

        erro_conexao();

        printf("\n\nV�rias tentativas de acesso suspeitas detectadas. Por medidas de seguran�a, esta conta ser� bloqueada.\n\n"); system("pause");

        main();
    }

    printf("\n\nLOGIN: "); gets(logado);
    printf("\nSENHA: "); gets(senha);

    //LOGIN
    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[7]); strcat(txt, ".txt");

    arq = fopen(txt,"r");
    while(fgets(logadofile, sizeof(logadofile), arq) != NULL);
    fclose(arq);

    //SENHA
    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[8]); strcat(txt, ".txt");

    arq = fopen(txt,"r");
    while(fgets(senhafile, sizeof(senhafile), arq) != NULL);
    fclose(arq);



    if(strcmp(logadofile, logado) == 0)
        ver++;

    if(strcmp(senhafile, senha) == 0)
        ver++;

    if(ver == 2)
    {
        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[9]); strcat(txt, ".txt");

        FILE *arq;
        arq = fopen(txt,"r");

        if(arq != NULL)
        {
            char comando[1000] = "enviar_email_duasetapas_codigo.py", codigo1[100], codigo2[100];

            printf("\n\nProcessando... Aguarde");

            email();

            system(comando);

            erro_conexao();

            FILE *file;
            file = fopen("0.txt", "r");
            fscanf(file, "%s", codigo2);
            fclose(file);

            //getchar();
            printf("\n\nINFORME O C�DIGO ENVIANDO EM SEU EMAIL: ");  gets(codigo1);

            if(strcmp(codigo2, codigo1) == 0)
            {
                del_doc();

                printf("\n\tLOGADO COM SUCESSO!\n\n"); system("pause");

                principal();
            }
            else
            {
                if(bt > 2)
                {
                    printf("\n\nProcessando... Aguarde");

                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[0]); strcat(txt, ".txt");

                    FILE *file;
                    file = fopen(txt, "w");
                    fprintf(file, "block");
                    fclose(file);

                    strcpy(comando, "enviar_email_block.py");

                    email();

                    system(comando);

                    erro_conexao();

                    printf("\n\tSEU N�MERO DE TENTATIVAS FOI MAIOR DO QUE 3.\n\tPOR SEGURAN�A ESTA CONTA EST� SENDO BLOQUEADA.\n\n"); system("pause");
                }

                if(bt <= 3)
                {
                    printf("\n\tC�DIGO INV�LIDO!\n\n");

                    bt++; printf("%d", bt); system("pause");

                    main();
                }
            }
        }
        else
        {
            printf("\n\tLOGADO COM SUCESSO!\n\n"); system("pause");

            principal();
        }

        fclose(arq);
    }
    else
    {
        printf("\nErro. Um ou mais dados s�o inv�lidos ou incorretos\n\n"); system("pause"); bt++;

        main();
    }

    return NULL;
}

//CADASTRO
int cadastro() //FINALIZADO
{
    system("cls");

    int resp=0, i, j;

    //DIGITANDO AS INFORMA��ES

    for(j=0; j<1;)
    {
        printf("\n\tINFORME OS SEGUINTES DADOS\n");

        for(i=0; i<9; i++)
        {
            //TRATAMENTO DE ERROS

            if(i == 6)
            {
                int y = 0, cont=0;
                char email[1000];

                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                    main();
                }

                strcpy(email, palavra2[i]); cont=strlen(email);

                for(y = 0; y < strlen(email); y++)
                {
                    if(email[y] == '@')
                    {
                        y = strlen(email);
                        i++;
                    }
                    else
                    {
                        cont--;
                    }

                    if(cont == 0)
                    {
                        printf("\n\nATEN��O: EMAIL inv�lido!\n\n"); system("pause");

                        main();
                    }
                }
            }

            if(i == 4)
            {
                float renda=0;

                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                    main();
                }

                renda=atof(palavra2[i]);

                if(renda < 0)
                {
                    printf("\n\nATEN��O: Renda inv�lida\n\n"); system("pause");

                    main();
                }

                if((renda > 0) && (renda < 998))
                {
                    printf("\n\nATEN��O: Imposs�vel criar conta banc�ria com renda inferior a 1 sal�rio m�nimo\n\n"); system("pause");

                    main();
                }
            }

            if(i == 3)
            {
                int conteudo=0;

                printf("\n%s: +55", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                    main();
                }

                conteudo=strlen(palavra2[i]);

                if((conteudo <= 10) || (conteudo > 11))
                {
                    printf("\n\nATEN��O: N�mero de celular inv�lido para o Brasil\n\n"); system("pause");

                    main();
                }
            }

            if(i == 2)
            {
                int conteudo=0;

                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                    main();
                }

                conteudo=strlen(palavra2[i]);

                if(conteudo < 11)
                {
                    printf("\n\nATEN��O: CPF inv�lido\n\n"); system("pause");

                    main();
                }
            }

            if(i == 1)
            {
                int anosN=0;

                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]); anosN = atoi(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                    main();
                }

                if(anosN < 18)
                {
                    printf("\n\nATEN��O: Idade inv�lida\n\n"); system("pause");

                    main();
                }
            }

            if(i == 0)
            {
                int y, cont=0;
                char nome[1000], txt[100];

                //PRITANDO NOME
                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                    main();
                }


                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[i]); strcat(txt, ".txt");

                FILE *file;
                file = fopen(txt, "r");
                fclose(file);

                if(file != NULL)
                {
                    printf("\n\nATEN��O: NOME j� em uso\n\n"); system("pause");

                    main();
                }


                strcpy(nome, palavra2[i]);

                for(y=0; y<strlen(nome); y++)
                {
                    if(nome[y] == ' ')
                        cont++;
                }

                if(cont == 0)
                {
                    printf("\n\nATEN��O: NOME inv�lido\n\n"); system("pause");

                    main();
                }
            }

            if((i != 0) && (i != 1) && (i != 2) && (i != 3) && (i != 4) && (i != 6))
            {
                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                    main();
                }
            }
        }

        //FIM DIGITAR INFORMA��ES

        printf("\n\nDESEJA CONFIRMAR OS DADOS ACIMA? [ SIM=0 / N�O=1 ]: "); scanf("%d",&resp); getchar(); printf("\nProcessando... Aguarde");


        if(resp == 0)
        {
            char txt[1000], comando[1000];
            int i;

            FILE *file;

            //CRIANDO O CART�O E A CONTA

            file = fopen("0.txt", "w");
            fprintf(file, "%s", palavra2[0]);
            fclose(file);

            CreateDirectory(palavra2[0], NULL);

            strcpy(comando, "build_card.py");
            system(comando);

            email();

            strcpy(comando, "enviar_email.py");
            system(comando);

            erro_conexao();

            //INFORMA��ES PESSOAIS
            for(i=0; i<9; i++)
            {
                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[i]); strcat(txt, ".txt");

                FILE *file;

                file = fopen(txt, "w");
                fprintf(file, "%s", palavra2[i]);
                fclose(file);
            }

            //SALDO, LIMITE, FATURA
            for(i=0; i<3; i++)
            {
                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[i])); strcat(txt, ".txt");

                FILE *file;

                file = fopen(txt, "w");
                fprintf(file, "%s", contaP2[i]);
                fclose(file);
            }

            printf("\n\n\tCADASTRO REALIZADO COM SUCESSO! CHEQUE SEU EMAIL PARA TER ACESSO AO N�MERO DE SUA CONTA\n\n"); system("pause");

            i = 1;

            main();
        }
        if(resp == 1)
        {
            system("cls");

            i = 0;
        }
        if((resp < 0) || (resp > 1))
        {
            printf("Resposta inv�lida");

            i = 0;
        }
    }

    return NULL;
}

//RECUPERAR A SENHA
int esquecisenha() //FINALIZADO
{
    system("cls");

    int resp=0, i;
    char txt[100], conteudo[100], word[1000];

    printf("\n\tN�S VAMOS TE AJUDAR A RECUPERAR SUA CONTA. PRIMEIRO DIGITE O N� DA SUA CONTA");

    printf("\n\nN� CONTA: "); gets(palavra2[13]);

    strcpy(txt, palavra2[13]); strcat(txt, "\\"); strcat(txt, palavra2[13]); strcat(txt, "_NOME COMPLETO.txt");

    FILE *arq;

    arq = fopen(txt, "r");
    while(fgets(conteudo, 100, arq) != NULL)
    fclose(arq);

    if(arq == NULL)
    {
        printf("\nErro. Informa��o inv�lida\n\n"); system("pause");

        main();
    }

    strcpy(palavra2[0], conteudo);

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[0]); strcat(txt, ".txt");

    system("cls"); printf("\n\tCOMO VOC� DESEJA RECUPERAR SUA CONTA? %s\n\n", strupr(palavra2[0]));

    printf("[0] VIA EMAIL\n");
    printf("[1] RESPONDENDO AS PERGUNTAS DE SEGURAN�A\n");
    printf("[2] VOLTAR\n\n");

    printf("OP��O: "); resp=scanint(resp);


    if(resp == 0)
    {
        printf("\n\nProcessando... Aguarde");

        char comando[100] = "enviar_email_recuperacao.py", codigo1[100], codigo2[100];

        email();

        system(comando);

        erro_conexao();

        printf("\n\nUm c�digo de verifica��o foi enviado para seu email.\n\nDIGITE O C�DIGO AQUI: "); gets(codigo1);

        FILE *file;
        file = fopen("0.txt", "r");
        fscanf(file, "%s", codigo2);
        fclose(file);

        if(strcmp(codigo1, codigo2) == 0)
        {
            printf("\n\n\tC�DIGO DE VERIFICA��O CORRETO\n\n"); system("pause"); system("cls");

            char password[1000], password2[1000];

            printf("\n\tDIGITE SUA NOVA SENHA\n\n");

            printf("NOVA SENHA: "); gets(password);
            printf("\nCONFIRME: "); gets(password2);


            if(strcmp(password, password2) == 0)
            {
                strcpy(palavra2[8], password2);

                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[8]); strcat(txt, ".txt"); strcpy(palavra2[8], password2);

                FILE *file;
                file = fopen(txt, "w");
                fprintf(file, "%s", palavra2[8]);
                fclose(file);

                printf("\n\tSENHA ALTERADA COM SUCESSO!\n\n"); system("pause");

                main();
            }
            else
            {
                printf("\n\tAS SENHAS INFORMADAS N�O COINCIDEM!\n\n"); system("pause");

                main();
            }
        }
    }

    if(resp == 1)
    {
        char txt[1000];

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "PSEGURANCA1"); strcat(txt, ".txt");

        FILE *file;

        file = fopen(txt, "r");
        fclose(file);

        if(file != NULL)
        {
            system("cls");

            int conferir = 0;
            char texto[1000] = "", comando[1000] = "enviar_email_recuperacao_pseguranca.py";

            printf("\n\tRESPONDA AS SEGUINTES PERGUNTAS\n");

            for(int i=0; i<3; i++)
            {
                printf("\n%s: ", Pseguranca1[i]); gets(Pseguranca2[i]);


                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, Pseguranca3[i]); strcat(txt, ".txt");

                FILE *file;

                file = fopen(txt, "r");
                while(fgets(texto, sizeof(texto), file) != '\0'){};
                fclose(file);

                if(strcmp(texto, Pseguranca2[i]) == 0)
                    conferir++;
                else
                    conferir--;
            }

            if(conferir == 3)
            {
                system("cls");

                printf("\n\tRESPOSTAS CORRETAS. DIGITE SUA NOVA SENHA\n\n");

                printf("NOVA SENHA: "); gets(palavra2[7]);
                printf("\nCONFIRME: "); gets(palavra2[8]);

                printf("\nProcessando... Aguarde");

                email();

                system(comando);

                erro_conexao();


                FILE *arquivo;

                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "LOGIN"); strcat(txt, ".txt");

                arquivo = fopen(txt, "w");
                fprintf(arquivo, "%s", palavra2[7]);
                fclose(arquivo);

                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "SENHA"); strcat(txt, ".txt");

                arquivo = fopen(txt, "w");
                fprintf(arquivo, "%s", palavra2[8]);
                fclose(arquivo);

                printf("\n\n\tLOGIN E SENHA ALTERADOS COM SUCESSO!\n\n"); system("pause");

                main();
            }
            else
            {
                printf("\n\tUMA OU MAIS RESPOSTAS INCORRETAS.\n\n"); system("pause");

                main();
            }
        }
        else
        {
            printf("\n\tVOC� N�O CADASTROU AS PERGUNTAS DE SEGURAN�A!\n\n"); system("pause");

            main();
        }
    }

    if(resp == 2)
        main();

    if((resp != 0) && (resp != 1) && (resp != 2))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        main();
    }

    return NULL;
}

//RESPOSTAS AUTOM�TICAS SUPORTE
int suporte()
{
    system("cls");

    int resp=0;

    printf("\n\tEST� TENDO PROBLEMAS? PODERIA NOS DAR MAIS DETALHES?\n\n");

    printf("[0] MINHA CONTA EST� BLOQUEADA\n");
    printf("[1] PERDI MINHA SENHA\n");
    printf("[2] NECESSITO FALAR DIRETAMENTE COM O SUPORTE\n");
    printf("[3] VOLTAR\n\n");

    printf("OP��O: "); resp=scanint(resp);


    if(resp == 0)
    {
        printf("\n\nNeste caso, sua conta s� poder� ser desbloqueada depois que voc� falar com o suporte e provar sua autoria da conta.\n\n");
        printf("Esse � nosso email: no.answer.banco99@gmail.com\n\nN�s atendemos sempre em hor�rio comercial e respondemos em menos de 48h.\n\n\n"); system("pause");

        main();
    }

    if(resp == 1)
    {
        printf("\n\nBom... Isso � bem simples de resolver!\n\nDigite '0' para entrar no login, depois no campo 'NOME COMPLETO' digite '99'.\n\n\n");
        printf("Logo ap�s voc� ser� encaminhado para uma p�gina que ir� te orientar a recuperar sua senha!\n\n"); system("pause");

        main();
    }

    if(resp == 2)
    {
        printf("\n\nTudo bem ent�o. Esse � nosso email: no.answer.banco99@gmail.com\n\nN�s atendemos sempre em hor�rio comercial e respondemos em menos de 48h.\n\n\n"); system("pause");

        main();
    }

    if(resp == 3)
    {
        main();
    }

    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        main();
    }

    return NULL;
}

//MENU PRINCIPAL
int principal() //FINALIZADO
{
    system("cls");

    del_doc();

    char txt[1000] = "";
    int i, resp=0;

    for(i=0; i<3; i++)
    {
        char txt[1000];

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[i])); strcat(txt, ".txt");

        FILE *file;

        file = fopen(txt, "r");
        fscanf(file, "%s", contaP2[i]);
        fclose(file);
    }

    contP.saldo[0] = atof(contaP2[0]);
    contP.limite[0] = atof(contaP2[1]);
    contP.fatura[0] = atof(contaP2[2]);

    printf("\n\tBEM VINDO   %s\n\n\t| MENU PRINCIPAL |\t\tSALDO: R$%.2f\n\n", strupr(palavra2[0]), contP.saldo[0]);

    printf("[0] TRANSFER�NCIA BANC�RIA\n");
    printf("[1] DEPOSITAR\n");
    printf("[2] CART�O\n");
    printf("[3] MINHA CONTA");

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_EMAIL SUPORTE.txt");

    FILE *file;

    file = fopen(txt, "r");
    fclose(file);

    if(file != NULL)
        printf("    [!!]");

    printf("\n[4] ATUALIZAR\n");
    printf("[5] SAIR\n\n");

    printf("OP��O: "); resp=scanint(resp);

    if(resp == 0)
        transferencia();
    if(resp == 1)
        deposito();
    if(resp == 2)
        cartao();
    if(resp == 3)
        conta();
    if(resp == 4)
        atualizar();
    if(resp == 5)
        sair();
    if((resp == 0) && (resp == 1) && (resp == 2)  && (resp == 3) && (resp == 4) && (resp == 5))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        principal();
    }

    return NULL;
}

//ATUALIZAR
void atualizar()
{
    system("cls");

    principal();
}

//TRANSFER�NCIA BANC�RIA
void transferencia()
{
    system("cls");

    char txt[1000];

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_TRANSACAO BLOCK.txt");

    FILE *file;

    file = fopen(txt, "r");
    fclose(file);

    if(file == NULL)
    {
        aviso();

        principal();
    }

    printf("\n\tPOR FAVOR %s DIGITE AS INFORMA��ES ABAIXO (PARA VOLTAR DIGITE: voltar)\n\n", strupr(palavra2[0]));

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "NCONTA"); strcat(txt, ".txt");

    char nconta[1000], ncontaD[1000], ncontaDfile[1000];

    file = fopen(txt, "r");
    fscanf(file, "%s", nconta);
    fclose(file);

    printf("CONTA ORIGEM: %s\n", nconta);
    printf("CONTA DESTINO: "); gets(ncontaD);

    if(strcmp(ncontaD, "voltar") == 0)
        principal();

    strcpy(txt, ncontaD); strcat(txt, "\\"); strcat(txt, ncontaD); strcat(txt, "_"); strcat(txt, palavra1[13]); strcat(txt, ".txt");

    file = fopen(txt, "r");
    fscanf(file, "%s", ncontaDfile);
    fclose(file);

    if(strcmp(ncontaD, ncontaDfile) == 0)
    {
        char nome[1000];
        int i=0;
        float valor=0;

        strcpy(txt, ncontaD); strcat(txt, "\\"); strcat(txt, ncontaD); strcat(txt, "_"); strcat(txt, "NOME COMPLETO"); strcat(txt, ".txt");

        file = fopen(txt, "r");
        while(fgets(nome, sizeof(nome), file) != NULL);
        fclose(file);

        char palavra3[1000][1000] = {"nome completo", "idade", "cpf", "celular", "renda", "endere�o", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", "nconta"};
        char palavra4[1000][1000] = {"nome", "idade", "cpf", "celular", "renda", "endere�o", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", ""};

        for(i=0; i<6; i++)
        {
            strcpy(txt, nome); strcat(txt, "\\"); strcat(txt, nome); strcat(txt, "_"); strcat(txt, strupr(palavra3[i])); strcat(txt, ".txt");

            file = fopen(txt, "r");
            while(fgets(palavra4[i], sizeof(palavra4[i]), file) != NULL)
            fclose(file);
        }

        printf("\n\tINFORMA��ES DA CONTA DESTINO\n\n");

        for(i=0; i<6; i++)
        {
            if(i == 4){}
            else{printf("%s: %s\n", strupr(palavra3[i]), strupr(palavra4[i]));}
        }

        printf("\n"); system("pause"); system("cls");

        printf("\n\n|%s| DIGITE A QUANTIDADE EM R$(REAIS) QUE SER� TRANSFERIDA PARA |%s|: R$", strupr(palavra2[0]), strupr(palavra4[0])); scanf("%f",&valor);


        if(valor < 5)
        {
            printf("\n\tO VALOR MIN�MO PARA TRANSFER�NCIA � R$5\n\n"); system("pause");

            principal();
        }

        if(strcmp(ncontaD, "voltar") == 0)
            principal();

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(palavra1[9])); strcat(txt, ".txt");

        FILE *arquivo;

        arquivo = fopen(txt, "r");
        fclose(arquivo);

        if(arquivo == NULL)
        {
            char logado[1000], senhado[1000];
            char logadofile[1000], senhadofile[1000];


            strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(palavra1[7])); strcat(txt, ".txt");

            file = fopen(txt, "r");
            while(fgets(logadofile, sizeof(logadofile), file) != NULL){}
            fclose(file);


            strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(palavra1[8])); strcat(txt, ".txt");

            file = fopen(txt, "r");
            while(fgets(senhadofile, sizeof(senhadofile), file) != NULL){}
            fclose(file);

            printf("\n\n|%s| POR FAVOR CONFIRME A OPERA��O COM SEU LOGIN/SENHA\n\n", strupr(palavra2[0]));

            printf("LOGIN: "); getchar(); gets(logado);

            if(strcmp(logado, "voltar") == 0)
                principal();

            printf("\nSENHA: "); gets(senhado);

            if(strcmp(senhado, "voltar") == 0)
                principal();

            if((strcmp(logado, logadofile) == 0) && (strcmp(senhado, senhadofile) == 0))
            {
                if(valor > contP.saldo[0])
                {
                    printf("\n\tVOC� N�O POSSUI SALDO SUFICIENTE PARA REALIZAR ESTA OPERA��O\n\n"); system("pause");

                    principal();
                }
                else
                {
                    //DEBITA��O DA CONTA ORIGEM
                    contP.saldo[0] = contP.saldo[0] - valor;

                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[0])); strcat(txt, ".txt");

                    file = fopen(txt, "w");
                    fprintf(file, "%.2f", contP.saldo[0]);
                    fclose(file);


                    //SOMA DA CONTA DESTINO
                    strcpy(txt, palavra4[0]); strcat(txt, "\\"); strcat(txt, palavra4[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[0])); strcat(txt, ".txt");

                    file = fopen(txt, "r");
                    fscanf(file, "%s", contaP2[0]);
                    fclose(file);

                    contP.saldo[1] = atof(contaP2[0]);

                    contP.saldo[1] = contP.saldo[1] + valor;

                    file = fopen(txt, "w");
                    fprintf(file, "%.2f", contP.saldo[1]);
                    fclose(file);

                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

                    int dia, mes, ano;

                    time_t mytime;
                    mytime = time(NULL);
                    struct tm tm = *localtime(&mytime);

                    dia = tm.tm_mday;
                    mes = tm.tm_mon + 1;
                    ano = tm.tm_year + 1900;

                    file = fopen(txt, "a");
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transfer�ncia banc�ria no valor de R$%.2f para |%s|", dia, mes, ano, palavra2[0], valor, palavra4[0]);
                    fclose(file);

                    strcpy(txt, palavra4[0]); strcat(txt, "\\"); strcat(txt, palavra4[0]); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

                    file = fopen(txt, "a");
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transfer�ncia banc�ria no valor de R$%.2f para voc�.", dia, mes, ano, palavra2[0], valor, palavra4[0]);
                    fclose(file);

                    printf("\n\tVALOR DE R$%.2f ADICIONADOS A CONTA %s (PERTENCENTE A: %s) COM SUCESSO!\n\n", valor, ncontaD, palavra4[0]); system("pause");

                    principal();
                }
            }
            else
            {
                printf("\n\n\tSENHA INCORRETA\n\n"); system("pause");

                principal();
            }








        }
        else
        {
            printf("\nProcessando... Aguarde");

            char comando[100] = "enviar_email_transferencia.py", codigo1[100], codigo2[100];

            email();

            system(comando);

            erro_conexao();

            printf("\n\n\nUm c�digo de verifica��o foi enviado para seu email.\n\nDIGITE O C�DIGO AQUI: "); getchar(); gets(codigo1);

            FILE *file;
            file = fopen("0.txt", "r");
                fscanf(file, "%s", codigo2);
            fclose(file);

            if(strcmp(codigo1, codigo2) == 0)
            {
                printf("\n\nC�DIGO DE VERIFICA��O CORRETO\n\n");

                if(valor > contP.saldo[0])
                {
                    printf("\n\tVOC� N�O POSSUI SALDO SUFICIENTE PARA REALIZAR ESTA OPERA��O\n\n"); system("pause");

                    principal();
                }
                else
                {
                    //DEBITA��O DA CONTA ORIGEM
                    contP.saldo[0] = contP.saldo[0] - valor;

                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[0])); strcat(txt, ".txt");

                    file = fopen(txt, "w");
                    fprintf(file, "%.2f", contP.saldo[0]);
                    fclose(file);


                    //SOMA DA CONTA DESTINO
                    strcpy(txt, palavra4[0]); strcat(txt, "\\"); strcat(txt, palavra4[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[0])); strcat(txt, ".txt");

                    file = fopen(txt, "r");
                    fscanf(file, "%s", contaP2[0]);
                    fclose(file);

                    contP.saldo[1] = atof(contaP2[0]);

                    contP.saldo[1] = contP.saldo[1] + valor;

                    file = fopen(txt, "w");
                    fprintf(file, "%.2f", contP.saldo[1]);
                    fclose(file);

                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

                    int dia, mes, ano;

                    time_t mytime;
                    mytime = time(NULL);
                    struct tm tm = *localtime(&mytime);

                    dia = tm.tm_mday;
                    mes = tm.tm_mon;
                    ano = tm.tm_year + 1900;

                    file = fopen(txt, "a");
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transfer�ncia banc�ria no valor de R$%.2f para |%s|", dia, mes, ano, palavra2[0], valor, palavra4[0]);
                    fclose(file);

                    strcpy(txt, palavra4[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra4[0])); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

                    file = fopen(txt, "a");
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transfer�ncia banc�ria no valor de R$%.2f para voc�.", dia, mes, ano, palavra2[0], valor, palavra4[0]);
                    fclose(file);

                    printf("\n\tVALOR DE R$%.2f ADICIONADOS A CONTA %s (PERTENCENTE A: %s) COM SUCESSO!\n\n", valor, ncontaD, palavra4[0]); system("pause");

                    principal();
                }
            }
            else
            {
                printf("\n\n\tC�DIGO DE VERIFICA��O INCORRETO\n\n"); system("pause");

                principal();
            }

        }
    }
    else
    {
        printf("\n\n\tCONTA INEXISTENTE\n\n"); system("pause");

        principal();
    }
}

//DEP�SITO BANC�RIO
int deposito()
{
    system("cls");

    char txt[1000];

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "TRANSACAO BLOCK"); strcat(txt, ".txt");

    FILE *arquivo;

    arquivo = fopen(txt, "r");
    fclose(arquivo);

    if(arquivo == NULL)
    {
        aviso();

        principal();
    }

    strcpy(txt, strlwr(palavra2[0])); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, "BOLETO"); strcat(txt, ".txt");

    FILE *file;

    file = fopen(txt, "r");
    fclose(file);

    if(file == NULL)
    {
        //file = fopen(txt, "w");

        float valor;
        char valorF[1000];

        printf("\n\tQUAL � O VALOR QUE VOC� DESEJA DEPOSITAR  %s?\n\n", strupr(palavra2[0]));

        printf("VALOR EM R$: "); scanf("%f",&valor);

        if(valor < 10)
        {
            printf("\n\tVOC� S� PODE DEPOSITAR VALORES ACIMA DE R$10\n\n"); system("pause");

            principal();
        }
        else
        {
            strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

            int dia, mes, ano;

            time_t mytime;
            mytime = time(NULL);
            struct tm tm = *localtime(&mytime);

            dia = tm.tm_mday;
            mes = tm.tm_mon;
            ano = tm.tm_year + 1900;

            FILE *file;

            file = fopen(txt, "a");
            fprintf(file, "\nNo dia %d/%d/%d |%s| criou um boleto no valor de R$%.2f", dia, mes+1, ano, strupr(palavra2[0]), valor);
            fclose(file);

            strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, "BOLETO"); strcat(txt, ".txt");

            itoa(valor, valorF, 10);

            file = fopen(txt, "w");
            fprintf(file, "%s", valorF);
            fclose(file);

            printf("\n\tBOLETO CRIADO COM SUCESSO! PAGUE EM QUALQUER LOT�RICA OU AG�NCIA BANC�RIA DO BANCO 99 EM NO M�XIMO 2 DIAS\n\n"); getchar(); system("pause");

            principal();
        }
    }
    else
    {
        printf("\n\tVOC� J� CRIOU UM BOLETO. PAGUE O BOLETO ANTERIOR ANTES DE CRIAR OUTRO.\n\n"); system("pause");

        principal();
    }

    return NULL;
}

//PROPRIEDADES DO CART�O
int cartao() //FINALIZADO
{
    system("cls");

    int resp=0;
    char txt[1000];

    for(int i=0; i<3; i++)
    {
        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(cartao2[i])); strcat(txt, ".txt");

        FILE *file;

        file = fopen(txt, "r");
        while(fgets(cartao1[i], sizeof(cartao1[i]), file) != NULL)
        fclose(file);
    }


    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[2])); strcat(txt, ".txt");

    FILE *file;

    file = fopen(txt, "r");
    while(fgets(contaP2[2], sizeof(contaP2[2]), file) != NULL)
    fclose(file);

    contP.fatura[0] = atof(contaP2[2]);


    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_CARTAO_BLOCK.txt");

    file = fopen(txt, "r");
    fclose(file);

    if(file == NULL)
    {
        printf("\n\tO QUE VOC� DESEJA FAZER PRIMEIRO    %s?             FATURA: R$%.2f\n\n", strupr(palavra2[0]), contP.fatura[0]);

        printf("[0] VER TRANSA��ES\n");
        printf("[1] PAGAR FATURA\n");
        printf("[2] BLOQUEAR CART�O\n");
        printf("[3] VOLTAR\n\n");

        printf("OP��O: "); resp=scanint(resp);
    }
    else
    {
        printf("\n\tO QUE VOC� DESEJA FAZER PRIMEIRO    %s?             FATURA: R$%.2f\n\n", strupr(palavra2[0]), contP.fatura[0]);

        printf("[0] VER TRANSA��ES\n");
        printf("[1] PAGAR FATURA\n");
        printf("[2] DESBLOQUEAR CART�O\n");
        printf("[3] VOLTAR\n\n");

        printf("OP��O: "); resp=scanint(resp);
    }

    if(resp == 0) //OK
    {
        system("cls");

        FILE *arquivo;

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

        arquivo = fopen(txt, "r");
        fclose(arquivo);

        if(arquivo == NULL)
        {
            printf("\n\tVOC� AINDA N�O REALIZOU NENHUMA TRANSA��O BANC�RIA\n\n"); system("pause");

            cartao();
        }
        else
        {
            char conteudo[1000];

            printf("\n\tAQUI EST�O TODAS AS SUAS TRANSA��ES BANC�RIAS   %s\n", strupr(palavra2[0]));


            strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

            FILE *file;

            file = fopen(txt, "r");
            while(fgets(conteudo, sizeof(conteudo), file) != NULL)
            {
                printf("%s", conteudo);
            }
            fclose(file);

            printf("\n\n"); system("pause");

            cartao();
        }
    }

    if(resp == 1) //OK
    {
        system("cls");

        float fatura;

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "TRANSACAO BLOCK"); strcat(txt, ".txt");

        FILE *arquivo;

        arquivo = fopen(txt, "r");
        fclose(arquivo);

        if(arquivo == NULL)
        {
            aviso();

            principal();
        }

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, contaP1[2]); strcat(txt, ".txt");

        arquivo = fopen(txt, "r");
        fscanf(arquivo, "%f",&fatura);
        fclose(arquivo);

        if(fatura != 0)
        {
            printf("Processando... Aguarde");

            strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[0])); strcat(txt, ".txt");

            FILE *file;

            file = fopen(txt, "r");
            while(fgets(contaP2[0], sizeof(contaP2[0]), file) != NULL)
            fclose(file);

            contP.saldo[0] = atof(contaP2[0]);

            if((contP.saldo[0] >= contP.fatura[0]) && (contP.saldo[0] != 0))
            {
                char comando[100] = "enviar_email_pagar_fatura.py";

                email();

                file = fopen("3.txt", "w");
                fprintf(file, "%s", contaP2[2]);
                fclose(file);

                system(comando);

                erro_conexao();

                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

                int dia, mes, ano;

                time_t mytime;
                mytime = time(NULL);
                struct tm tm = *localtime(&mytime);

                dia = tm.tm_mday;
                mes = tm.tm_mon;
                ano = tm.tm_year + 1900;

                FILE *file;

                file = fopen(txt, "a");
                fprintf(file, "\nNo dia %d/%d/%d |%s| pagou sua fatura no valor de R$%.2f", dia, mes, ano, strupr(palavra2[0]), contP.fatura[0]);
                fclose(file);

                //SUBTRAINDO O SALDO-FATURA
                contP.saldo[0] = contP.saldo[0] - contP.fatura[0];
                itoa(contP.saldo[0], contaP2[0], 10);

                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[0])); strcat(txt, ".txt");

                file = fopen(txt, "w");
                fprintf(file, "%s", contaP2[0]);
                fclose(file);

                //ZERANDO A FATURA
                contP.fatura[0] = 0;
                itoa(contP.fatura[0], contaP2[2], 10);

                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(contaP1[2])); strcat(txt, ".txt");

                file = fopen(txt, "w");
                fprintf(file, "%s", contaP2[2]);
                fclose(file);

                printf("\n\n\tFATURA PAGA COM SUCESSO!\n\n"); system("pause");

                cartao();
            }
            else
            {
                printf("\n\tVOC� N�O POSSUI SALDO SUFICIENTE PARA PAGAR SUA FATURA\n\n"); system("pause");

                cartao();
            }
        }
        else
        {
            printf("\n\tVOC� N�O POSSUI FATURA PARA PAGAR\n\n"); system("pause");

            cartao();
        }
    }

    if(resp == 2) //OK
    {
        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "TRANSACAO BLOCK"); strcat(txt, ".txt");

        FILE *arquivo;

        arquivo = fopen(txt, "r");
        fclose(arquivo);

        if(arquivo == NULL)
        {
            aviso();

            principal();
        }

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "CARTAO_BLOCK"); strcat(txt, ".txt");

        arquivo = fopen(txt, "r");
        fclose(arquivo);

        if(arquivo == NULL)
        {
            system("cls");

            printf("\n\tTEM CERTEZA QUE VOC� DESEJA BLOQUEAR SEU CART�O?\n\n");

            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); resp=scanint(resp);

            if(resp == 0)
            {
                char comando[50] = "enviar_email_cartao_block.py";

                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, "CARTAO_BLOCK"); strcat(txt, ".txt");

                FILE *file;

                file = fopen(txt, "w");
                fclose(file);

                printf("\nProcessando... Aguarde");

                email();

                system(comando);

                erro_conexao();

                int dia, mes, ano;

                time_t mytime;
                mytime = time(NULL);
                struct tm tm = *localtime(&mytime);

                dia = tm.tm_mday;
                mes = tm.tm_mon;
                ano = tm.tm_year + 1900;

                file = fopen(txt, "a");
                fprintf(file, "\nNo dia %d/%d/%d voc� bloqueou seu cart�o", dia, mes, ano);
                fclose(file);

                printf("\n\n\tCART�O BLOQUEADO COM SUCESSO\n\n"); system("pause");

                cartao();
            }
            if(resp == 1)
            {
                cartao();
            }
            if((resp != 0) && (resp != 1))
            {
                printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                cartao();
            }
        }
        else
        {
            system("cls");

            printf("\n\tDESEJA DESBLOQUEAR SEU CART�O?\n\n");

            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); resp=scanint(resp);

            if(resp == 0)
            {
                char teste[1000];

                strcpy(teste, palavra2[0]); strcat(teste, "\\"); strcat(teste, palavra2[0]); strcat(teste, "_"); strcat(teste, "DUASETAPAS"); strcat(teste, ".txt");

                FILE *arquivo;

                arquivo = fopen(teste, "r");
                fclose(file);

                if(arquivo != NULL)
                {
                    printf("\nProcessando... Aguarde");

                    char comando[100] = "enviar_email_cartao_unblock.py", codigo1[100], codigo2[100];

                    email();

                    system(comando);

                    erro_conexao();

                    printf("\n\nUm c�digo de verifica��o foi enviado para seu email.\n\nDIGITE O C�DIGO AQUI: "); gets(codigo1);

                    FILE *file;
                    file = fopen("0.txt", "r");
                    fscanf(file, "%s", codigo2);
                    fclose(file);

                    if(strcmp(codigo1, codigo2) == 0)
                    {
                        char txt[1000];

                        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "CARTAO_BLOCK"); strcat(txt, ".txt");

                        remove(txt);

                        printf("\n\tC�DIGO DE VERIFICA��O CORRETO\n\n"); system("pause");

                        cartao();
                    }
                    else
                    {
                        printf("\n\tC�DIGO DE VERIFICA��O INCORRETO\n\n"); system("pause");

                        cartao();
                    }
                }
                else
                {
                    char logado[1000], senhado[1000];
                    char logadofile[1000], senhadofile[1000];

                    system("cls");

                    printf("\n\tINFORME OS DADOS ABAIXO\n\n");

                    printf("LOGIN: "); gets(logado);
                    printf("\nSENHA: "); gets(senhado);

                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(palavra1[7])); strcat(txt, ".txt");

                    file = fopen(txt, "r");
                    while(fgets(logadofile, sizeof(logadofile), file) != NULL)
                    fclose(file);

                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, strupr(palavra1[8])); strcat(txt, ".txt");

                    file = fopen(txt, "r");
                    while(fgets(senhadofile, sizeof(senhadofile), file) != NULL)
                    fclose(file);

                    if((strcmp(logado, logadofile) == 0) && (strcmp(senhado, senhadofile) == 0))
                    {
                        char comando[1000] = "enviar_email_cartao_unblock_info.py";

                        printf("\nProcessando... Aguarde");

                        strcpy(txt, strlwr(palavra2[0])); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, "CARTAO_BLOCK"); strcat(txt, ".txt");

                        remove(txt);

                        email();

                        system(comando);

                        erro_conexao();

                        printf("\n\n\tCART�O DESBLOQUEADO COM SUCESSO!\n\n"); system("pause");

                        cartao();
                    }
                    else
                    {
                        printf("\n\tLOGIN OU SENHA INV�LIDOS\n\n"); system("pause");

                        cartao();
                    }
                }
            }
            if(resp == 1)
            {
                cartao();
            }
            if((resp != 0) && (resp != 1))
            {
                printf("\n\tOP��O INV�LIDA!\n\n"); system("pause");

                cartao();
            }
        }
    }

    if(resp == 3)
    {
        principal();
    }

    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        cartao();
    }

    return NULL;
}

//PROPRIEDADES DA CONTA
int conta() //FINALIZADO
{
    system("cls");

    char txt[1000];
    int resp=0;

    printf("\n\tO QUE VOC� DESEJA FAZER PRIMEIRO    %s?\n\n", strupr(palavra2[0]));

    printf("[0] ALTERAR LOGIN/SENHA\n");
    printf("[1] VERIFICA��O POR DUAS ETAPAS");

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[9]); strcat(txt, ".txt");

    FILE *file;
    file = fopen(txt, "r");

    if(file == NULL)
        printf("    [!!]");

    fclose(file);


    printf("\n[2] PERGUNTAS DE SEGURAN�A");

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[10]); strcat(txt, ".txt");

    file = fopen(txt, "r");

    if(file == NULL)
        printf("    [!!]");

    fclose(file);

    printf("\n[3] INTERNET BANKING");

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "TRANSACAO BLOCK"); strcat(txt, ".txt");

    file = fopen(txt, "r");

    if(file == NULL)
        printf("    [!!]");

    fclose(file);


    printf("\n[4] VOLTAR");


    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "EMAIL SUPORTE"); strcat(txt, ".txt");

    file = fopen(txt, "r");

    if(file != NULL)
    {
        printf("\n[5] ENVIAR EMAIL    [!!]");
    }

    fclose(file);

    printf("\n\nOP��O: "); resp=scanint(resp);


    if(resp == 0)
    {
        system("cls");

        printf("\n\tVOC� DESEJA ALTERAR O LOGIN OU A SENHA  %s?\n\n", strupr(palavra2[0]));

        printf("[0] LOGIN\n");
        printf("[1] SENHA\n\n");

        printf("OP��O: "); resp=scanint(resp);


        if(resp == 0)
        {
            char user[1000], user2[1000];

            printf("\n\nNOVO LOGIN: "); gets(user);
            printf("\nCONFIRME: "); gets(user2);


            if(strcmp(user, user2) == 0)
            {
                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "DUASETAPAS"); strcat(txt, ".txt");

                FILE *arquivo;

                arquivo = fopen(txt, "r");
                fclose(arquivo);

                if(arquivo != NULL)
                {
                    printf("\n\nProcessando... Aguarde");

                    char comando[100] = "enviar_email_login.py", codigo1[100], codigo2[100];

                    email();

                    system(comando);

                    erro_conexao();

                    printf("\n\nUm c�digo de verifica��o foi enviado para seu email.\n\nDIGITE O C�DIGO AQUI: "); gets(codigo1);

                    FILE *file;
                    file = fopen("0.txt", "r");
                    fscanf(file, "%s", codigo2);
                    fclose(file);

                    if(strcmp(codigo1, codigo2) == 0)
                    {
                        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[7]); strcat(txt, ".txt");

                        strcpy(palavra2[7], user2);

                        FILE *file;
                        file = fopen(txt, "w");
                        fprintf(file, "%s", palavra2[7]);
                        fclose(file);

                        printf("\n\tC�DIGO DE VERIFICA��O CORRETO. LOGIN ALTERADO COM SUCESSO!\n\n"); system("pause");

                        conta();
                    }
                    else
                    {
                        printf("\n\tC�DIGO DE VERIFICA��O INCORRETO\n\n"); system("pause");

                        conta();
                    }
                }
                else
                {
                    printf("\n\tLOGIN ALTERADO COM SUCESSO!\n\n"); system("pause");

                    conta();
                }
            }
            else
            {
                printf("\n\tOS LOGINS INFORMADOS N�O COINCIDEM!\n\n"); system("pause");

                conta();
            }
        }

        if(resp == 1)
        {
            char password[1000], password2[1000];

            printf("\n\nNOVA SENHA: "); gets(password);
            printf("\nCONFIRME: "); gets(password2);

            if(strcmp(password, password2) == 0)
            {
                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt,"DUASETAPAS"); strcat(txt, ".txt");

                FILE *arquivo;

                arquivo = fopen(txt, "r");
                fclose(arquivo);

                if(arquivo != NULL)
                {
                    printf("\n\nProcessando... Aguarde");

                    char comando[100] = "enviar_email_senha.py", codigo1[100], codigo2[100];

                    email();

                    system(comando);

                    erro_conexao();

                    printf("\n\nUm c�digo de verifica��o foi enviado para seu email.\n\nDIGITE O C�DIGO AQUI: "); gets(codigo1);

                    FILE *file;
                    file = fopen("0.txt", "r");
                    fscanf(file, "%s", codigo2);
                    fclose(file);

                    if(strcmp(codigo1, codigo2) == 0)
                    {
                        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[8]); strcat(txt, ".txt");

                        strcpy(palavra2[8], password2);

                        FILE *file;
                        file = fopen(txt, "w");
                        fprintf(file, "%s", palavra2[8]);
                        fclose(file);

                        printf("\n\tC�DIGO DE VERIFICA��O CORRETO. SENHA ALTERADA COM SUCESSO!\n\n"); system("pause");

                        conta();
                    }
                    else
                    {
                        printf("\n\tC�DIGO DE VERIFICA��O INCORRETO\n\n"); system("pause");

                        conta();
                    }
                }
                else
                {
                    printf("\n\tSENHA ALTERADA COM SUCESSO!\n\n"); system("pause");

                    conta();
                }
            }
            else
            {
                printf("\n\tAS SENHAS INFORMADAS N�O COINCIDEM!\n\n"); system("pause");

                conta();
            }
        }
    }

    if(resp == 1)
    {
        system("cls");

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[9]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        fclose(file);

        if(file == NULL)
        {
            printf("\n\tATEN��O: VOC� AINDA N�O POSSUI ATIVA A VERIFICA��O POR DUAS ETAPAS!");

            printf("\n\nSTATUS: DESATIVADO");

            printf("\n\n\nATIVAR VERIFICA��O POR DUAS ETAPAS?\n\n");
            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); resp=scanint(resp);

            if(resp == 0)
            {
                char comando[1000] = "enviar_email_duasetapas.py";

                printf("\n\nProcessando... Aguarde");

                email();

                strcpy(txt, strlwr(palavra2[0])); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, strupr(palavra1[9])); strcat(txt, ".txt");

                FILE *arq;
                arq = fopen(txt, "w");
                fclose(arq);

                system(comando);

                erro_conexao();

                del_doc();

                printf("\n\n\tVERIFICA��O POR DUAS ETAPAS ATIVADA COM SUCESSO!\nMAIS INFORMA��ES EST�O DISPON�VEIS NO EMAIL QUE ENVIAMOS PARA VOC�\n\n"); system("pause");

                conta();
            }

            if(resp == 1)
                conta();
        }
        else
        {
            printf("\n\tVERIFICA��O POR DUAS ETAPAS");

            printf("\n\nSTATUS: ATIVADO\n\n"); system("pause");

            conta();
        }
    }

    if(resp == 2)
    {
        system("cls");

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[10]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        fclose(file);

        if(file == NULL)
        {
            printf("\n\tATEN��O: VOC� AINDA N�O RESPONDEU AS PERGUNTAS DE SEGURAN�A!");

            printf("\n\nSTATUS: DESATIVADO");

            printf("\n\n\nRESPONDER AGORA?\n\n");
            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); resp=scanint(resp);

            if(resp == 0)
            {
                int i;

                for(i=0; i<3; i++)
                {
                    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[0])); strcat(txt, "_"); strcat(txt, strupr(palavra1[i+10])); strcat(txt, ".txt");

                    printf("\n%s ", Pseguranca1[i]); gets(Pseguranca2[i]);


                    FILE *arq;

                    arq = fopen(txt, "w");
                    fprintf(arq, "%s", Pseguranca2[i]);
                    fclose(arq);
                }

                printf("\nProcessando... Aguarde");

                char comando[100] = "enviar_email_pseguranca.py";

                email();

                system(comando);

                erro_conexao();

                printf("\n\n\tRESPOSTAS DE SEGURAN�A ARMAZENADAS COM SUCESSO\n\n"); system("pause");

                conta();
            }

            if(resp == 1)
                conta();
        }
        else
        {
            printf("\n\tPERGUNTAS DE SEGURAN�A");

            printf("\n\nSTATUS: ATIVADO\n\n"); system("pause");

            conta();
        }
    }

    if(resp == 3)
    {
        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "TRANSACAO BLOCK"); strcat(txt, ".txt");

        FILE *arquivo;

        arquivo = fopen(txt,"r");
        fclose(arquivo);

        if(arquivo == NULL)
        {
            aviso();

            conta();
        }
        else
        {
            system("cls");

            printf("\n\tINTERNET BANKING\n\n");

            printf("STATUS: ATIVADO\n\n"); system("pause");

            conta();
        }
    }

    if(resp == 4)
        principal();


    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "EMAIL SUPORTE"); strcat(txt, ".txt");

    file = fopen(txt, "r");
    fclose(file);

    if((file != NULL) && (resp == 5))
    {
        char assunto[1000], mensagem[1000], comando[100] = "enviar_email_suporte.py";

        system("cls");

        printf("\n\tDIGITE AS INFORMA��ES ABAIXO\n\n");

        printf("POR FAVOR DIGITE O ASSUNTO DO EMAIL: "); gets(assunto);

        printf("\n\nDIGITE ABAIXO SUA MENSAGEM PARA O SUPORTE:\n\n"); gets(mensagem);

        printf("\n\nProcessando... Aguarde");

        //CRIANDO TXT PARA ARMAZENAR O NOME DO USU�RIO
        FILE *arquivo;

        arquivo = fopen("1.txt", "w");
        fprintf(arquivo, "%s", palavra2[0]);
        fclose(arquivo);

        arquivo = fopen("3.txt", "w");
        fprintf(arquivo, "%s", assunto);
        fclose(arquivo);

        arquivo = fopen("4.txt", "w");
        fprintf(arquivo, "%s", mensagem);
        fclose(arquivo);

        system(comando);

        erro_conexao();

        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "EMAIL SUPORTE"); strcat(txt, ".txt");
        remove(txt);

        printf("\n\n\tEMAIL ENVIADO COM SUCESSO PARA O SUPORTE\n\n"); system("pause");

        principal();
    }

    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        principal();
    }

    return NULL;
}

//FUN��O PARA INFORMAR O EMAIL DO USU�RIO EM UM TXT
int email() //FINALIZADO
{
    char txt[1000];

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[6]); strcat(txt, ".txt");

    FILE *arq;
    arq = fopen(txt, "r");
    fscanf(arq, "%s", palavra2[6]);
    fclose(arq);

    arq = fopen("1.txt", "w");
    fprintf(arq, "%s", palavra2[6]);
    fclose(arq);

    return NULL;
}

//FUN��O QUE AVISA QUANDO N�O H� CONEX�O COM A INTERNET
int erro_conexao() //FINALIZADO
{
    char conteudo[1000];

    FILE *documento;
    documento = fopen("2.txt", "r");

    if(documento == NULL){fclose(documento);}
    else
    {
        while(fgets(conteudo, sizeof(conteudo), documento) != NULL); printf("\n\n\t");
        printf("%s", conteudo); printf("\n\n"); system("pause");

        del_doc();

        fclose(documento);

        main();
    }

    return NULL;
}

//FUN��O QUE APAGA OS DOCUMENTOS QUE SE TORNAM DESNECESS�RIOS AP�S SEREM USADOS
int del_doc() //FINALIZADO
{
    remove("0.txt");
    remove("1.txt");
    remove("2.txt");
    remove("3.txt");
    remove("4.txt");

    return NULL;
}

//FUN��O APENAS PARA AVISAR O USU�RIO QUE SEU APP N�O EST� TOTALMENTE DESBLOQUEADO
int aviso()
{
    system("cls");

    printf("\n\tINTERNET BANKING\n\n");

    printf("STATUS: DESATIVADO");

    printf("\n\nAVISO: POR QUEST�ES DE SEGURAN�A.\nATUALMENTE SUA CONTA EST� BLOQUEADA PARA FAZER QUALQUER TIPO DE OPERA��O BANC�RIA VIA INTERNET BANKING.\
            \n\nPARA DESBLOQUEAR ESSA A��O, POR FAVOR V� A UM CAIXA ELETR�NICO DO BANCO 99 MAIS PR�XIMO DE VOC� E ACESSE:\
            \n\n\tCONFIGURA��ES -> INTERNET BANKING\n\nPARA QUE VOC� POSSA APROVEITAR TODOS OS BENEF�CIOS OFERECIDOS POR N�S.\n\n"); system("pause");

    return NULL;
}

//SAIR DO PROGRAMA
int sair() //FINALIZADO
{
    system("cls");

    int resp=0;

    printf("\n\tVOC� DESEJA SAIR OU VOLTAR PARA O MENU PRINCIPAL?\n\n");

    printf("[0] SAIR\n");
    printf("[1] MENU PRINCIPAL\n\n");

    printf("OP��O: "); resp=scanint(resp);

    if(resp == 0)
    {
        system("cls");

        printf("\n\tOBRIGADO POR USAR O BANCO 99!\n\n"); system("pause");

        exit(0);
    }
    if(resp == 1)
    {
        main();
    }
    if((resp != 0) && (resp != 1))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        exit(0);
    }

    return NULL;
}
