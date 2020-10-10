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

char palavra1[1000][1000] = {"nome completo", "idade", "cpf", "celular", "renda", "endereço", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", "nconta"};
char palavra2[1000][1000] = {"nome", "idade", "cpf", "celular", "renda", "endereço", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", ""};

char contaP1[1000][1000] = {"saldo", "limite", "fatura"};
char contaP2[1000][1000] = {"0", "1000", "0"};

char cartao1[1000][1000] = {"ncartao", "nconta", "data_validade"};
char cartao2[1000][1000] = {"ncartao", "nconta", "data_validade"};

char Pseguranca1[1000][1000] = {"Qual o nome de seu primeiro animal de estimação?", "Qual o nome da mãe de sua mãe?", "Qual o nome da primeira cidade que você morou?"};
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
        printf("\n   O que você deseja fazer primeiro?");

        printf("\n\n[0] LOGIN\n");
        printf("[1] CADASTRO\n");
        printf("[2] SUPORTE\n");
        printf("[3] SAIR\n\n");

        printf("OPÇÃO: "); resp=scanint(resp);

        if((resp < 0) || (resp > 3))
        {
            printf("Opção Inválida\n\n");

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

    printf("\n\t\tFAÇA SEU LOGIN NO BANCO 99!"); printf("\n\n      Esqueceu sua senha? Digite 99 no campo Nº CONTA");

    printf("\n\nNº CONTA: "); gets(palavra2[13]);

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
        printf("\nErro. Informação inválida\n\n"); system("pause");

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
        printf("\nPor medidas de segurança, esta conta está BLOQUEADA\n\n"); system("pause");

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

        printf("\n\nVárias tentativas de acesso suspeitas detectadas. Por medidas de segurança, esta conta será bloqueada.\n\n"); system("pause");

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
            printf("\n\nINFORME O CÓDIGO ENVIANDO EM SEU EMAIL: ");  gets(codigo1);

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

                    printf("\n\tSEU NÚMERO DE TENTATIVAS FOI MAIOR DO QUE 3.\n\tPOR SEGURANÇA ESTA CONTA ESTÁ SENDO BLOQUEADA.\n\n"); system("pause");
                }

                if(bt <= 3)
                {
                    printf("\n\tCÓDIGO INVÁLIDO!\n\n");

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
        printf("\nErro. Um ou mais dados são inválidos ou incorretos\n\n"); system("pause"); bt++;

        main();
    }

    return NULL;
}

//CADASTRO
int cadastro() //FINALIZADO
{
    system("cls");

    int resp=0, i, j;

    //DIGITANDO AS INFORMAÇÕES

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
                    printf("\n\nATENÇÃO: Espaço vazio detectado, por favor digite suas informações corretamente\n\n"); system("pause");

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
                        printf("\n\nATENÇÃO: EMAIL inválido!\n\n"); system("pause");

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
                    printf("\n\nATENÇÃO: Espaço vazio detectado, por favor digite suas informações corretamente\n\n"); system("pause");

                    main();
                }

                renda=atof(palavra2[i]);

                if(renda < 0)
                {
                    printf("\n\nATENÇÃO: Renda inválida\n\n"); system("pause");

                    main();
                }

                if((renda > 0) && (renda < 998))
                {
                    printf("\n\nATENÇÃO: Impossível criar conta bancária com renda inferior a 1 salário mínimo\n\n"); system("pause");

                    main();
                }
            }

            if(i == 3)
            {
                int conteudo=0;

                printf("\n%s: +55", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATENÇÃO: Espaço vazio detectado, por favor digite suas informações corretamente\n\n"); system("pause");

                    main();
                }

                conteudo=strlen(palavra2[i]);

                if((conteudo <= 10) || (conteudo > 11))
                {
                    printf("\n\nATENÇÃO: Número de celular inválido para o Brasil\n\n"); system("pause");

                    main();
                }
            }

            if(i == 2)
            {
                int conteudo=0;

                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATENÇÃO: Espaço vazio detectado, por favor digite suas informações corretamente\n\n"); system("pause");

                    main();
                }

                conteudo=strlen(palavra2[i]);

                if(conteudo < 11)
                {
                    printf("\n\nATENÇÃO: CPF inválido\n\n"); system("pause");

                    main();
                }
            }

            if(i == 1)
            {
                int anosN=0;

                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]); anosN = atoi(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATENÇÃO: Espaço vazio detectado, por favor digite suas informações corretamente\n\n"); system("pause");

                    main();
                }

                if(anosN < 18)
                {
                    printf("\n\nATENÇÃO: Idade inválida\n\n"); system("pause");

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
                    printf("\n\nATENÇÃO: Espaço vazio detectado, por favor digite suas informações corretamente\n\n"); system("pause");

                    main();
                }


                strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[i]); strcat(txt, ".txt");

                FILE *file;
                file = fopen(txt, "r");
                fclose(file);

                if(file != NULL)
                {
                    printf("\n\nATENÇÃO: NOME já em uso\n\n"); system("pause");

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
                    printf("\n\nATENÇÃO: NOME inválido\n\n"); system("pause");

                    main();
                }
            }

            if((i != 0) && (i != 1) && (i != 2) && (i != 3) && (i != 4) && (i != 6))
            {
                printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

                if(strcmp(palavra2[i], "") == 0)
                {
                    printf("\n\nATENÇÃO: Espaço vazio detectado, por favor digite suas informações corretamente\n\n"); system("pause");

                    main();
                }
            }
        }

        //FIM DIGITAR INFORMAÇÕES

        printf("\n\nDESEJA CONFIRMAR OS DADOS ACIMA? [ SIM=0 / NÃO=1 ]: "); scanf("%d",&resp); getchar(); printf("\nProcessando... Aguarde");


        if(resp == 0)
        {
            char txt[1000], comando[1000];
            int i;

            FILE *file;

            //CRIANDO O CARTÃO E A CONTA

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

            //INFORMAÇÕES PESSOAIS
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

            printf("\n\n\tCADASTRO REALIZADO COM SUCESSO! CHEQUE SEU EMAIL PARA TER ACESSO AO NÚMERO DE SUA CONTA\n\n"); system("pause");

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
            printf("Resposta inválida");

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

    printf("\n\tNÓS VAMOS TE AJUDAR A RECUPERAR SUA CONTA. PRIMEIRO DIGITE O Nº DA SUA CONTA");

    printf("\n\nNº CONTA: "); gets(palavra2[13]);

    strcpy(txt, palavra2[13]); strcat(txt, "\\"); strcat(txt, palavra2[13]); strcat(txt, "_NOME COMPLETO.txt");

    FILE *arq;

    arq = fopen(txt, "r");
    while(fgets(conteudo, 100, arq) != NULL)
    fclose(arq);

    if(arq == NULL)
    {
        printf("\nErro. Informação inválida\n\n"); system("pause");

        main();
    }

    strcpy(palavra2[0], conteudo);

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[0]); strcat(txt, ".txt");

    system("cls"); printf("\n\tCOMO VOCÊ DESEJA RECUPERAR SUA CONTA? %s\n\n", strupr(palavra2[0]));

    printf("[0] VIA EMAIL\n");
    printf("[1] RESPONDENDO AS PERGUNTAS DE SEGURANÇA\n");
    printf("[2] VOLTAR\n\n");

    printf("OPÇÃO: "); resp=scanint(resp);


    if(resp == 0)
    {
        printf("\n\nProcessando... Aguarde");

        char comando[100] = "enviar_email_recuperacao.py", codigo1[100], codigo2[100];

        email();

        system(comando);

        erro_conexao();

        printf("\n\nUm código de verificação foi enviado para seu email.\n\nDIGITE O CÓDIGO AQUI: "); gets(codigo1);

        FILE *file;
        file = fopen("0.txt", "r");
        fscanf(file, "%s", codigo2);
        fclose(file);

        if(strcmp(codigo1, codigo2) == 0)
        {
            printf("\n\n\tCÓDIGO DE VERIFICAÇÃO CORRETO\n\n"); system("pause"); system("cls");

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
                printf("\n\tAS SENHAS INFORMADAS NÃO COINCIDEM!\n\n"); system("pause");

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
            printf("\n\tVOCÊ NÃO CADASTROU AS PERGUNTAS DE SEGURANÇA!\n\n"); system("pause");

            main();
        }
    }

    if(resp == 2)
        main();

    if((resp != 0) && (resp != 1) && (resp != 2))
    {
        printf("\n\tOPÇÃO INVÁLIDA\n\n"); system("pause");

        main();
    }

    return NULL;
}

//RESPOSTAS AUTOMÁTICAS SUPORTE
int suporte()
{
    system("cls");

    int resp=0;

    printf("\n\tESTÁ TENDO PROBLEMAS? PODERIA NOS DAR MAIS DETALHES?\n\n");

    printf("[0] MINHA CONTA ESTÁ BLOQUEADA\n");
    printf("[1] PERDI MINHA SENHA\n");
    printf("[2] NECESSITO FALAR DIRETAMENTE COM O SUPORTE\n");
    printf("[3] VOLTAR\n\n");

    printf("OPÇÃO: "); resp=scanint(resp);


    if(resp == 0)
    {
        printf("\n\nNeste caso, sua conta só poderá ser desbloqueada depois que você falar com o suporte e provar sua autoria da conta.\n\n");
        printf("Esse é nosso email: no.answer.banco99@gmail.com\n\nNós atendemos sempre em horário comercial e respondemos em menos de 48h.\n\n\n"); system("pause");

        main();
    }

    if(resp == 1)
    {
        printf("\n\nBom... Isso é bem simples de resolver!\n\nDigite '0' para entrar no login, depois no campo 'NOME COMPLETO' digite '99'.\n\n\n");
        printf("Logo após você será encaminhado para uma página que irá te orientar a recuperar sua senha!\n\n"); system("pause");

        main();
    }

    if(resp == 2)
    {
        printf("\n\nTudo bem então. Esse é nosso email: no.answer.banco99@gmail.com\n\nNós atendemos sempre em horário comercial e respondemos em menos de 48h.\n\n\n"); system("pause");

        main();
    }

    if(resp == 3)
    {
        main();
    }

    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3))
    {
        printf("\n\tOPÇÃO INVÁLIDA\n\n"); system("pause");

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

    printf("[0] TRANSFERÊNCIA BANCÁRIA\n");
    printf("[1] DEPOSITAR\n");
    printf("[2] CARTÃO\n");
    printf("[3] MINHA CONTA");

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_EMAIL SUPORTE.txt");

    FILE *file;

    file = fopen(txt, "r");
    fclose(file);

    if(file != NULL)
        printf("    [!!]");

    printf("\n[4] ATUALIZAR\n");
    printf("[5] SAIR\n\n");

    printf("OPÇÃO: "); resp=scanint(resp);

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
        printf("\n\tOPÇÃO INVÁLIDA\n\n"); system("pause");

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

//TRANSFERÊNCIA BANCÁRIA
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

    printf("\n\tPOR FAVOR %s DIGITE AS INFORMAÇÕES ABAIXO (PARA VOLTAR DIGITE: voltar)\n\n", strupr(palavra2[0]));

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

        char palavra3[1000][1000] = {"nome completo", "idade", "cpf", "celular", "renda", "endereço", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", "nconta"};
        char palavra4[1000][1000] = {"nome", "idade", "cpf", "celular", "renda", "endereço", "email", "login", "senha", "duasetapas", "pseguranca1", "pseguranca2", "pseguranca3", ""};

        for(i=0; i<6; i++)
        {
            strcpy(txt, nome); strcat(txt, "\\"); strcat(txt, nome); strcat(txt, "_"); strcat(txt, strupr(palavra3[i])); strcat(txt, ".txt");

            file = fopen(txt, "r");
            while(fgets(palavra4[i], sizeof(palavra4[i]), file) != NULL)
            fclose(file);
        }

        printf("\n\tINFORMAÇÕES DA CONTA DESTINO\n\n");

        for(i=0; i<6; i++)
        {
            if(i == 4){}
            else{printf("%s: %s\n", strupr(palavra3[i]), strupr(palavra4[i]));}
        }

        printf("\n"); system("pause"); system("cls");

        printf("\n\n|%s| DIGITE A QUANTIDADE EM R$(REAIS) QUE SERÁ TRANSFERIDA PARA |%s|: R$", strupr(palavra2[0]), strupr(palavra4[0])); scanf("%f",&valor);


        if(valor < 5)
        {
            printf("\n\tO VALOR MINÍMO PARA TRANSFERÊNCIA É R$5\n\n"); system("pause");

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

            printf("\n\n|%s| POR FAVOR CONFIRME A OPERAÇÃO COM SEU LOGIN/SENHA\n\n", strupr(palavra2[0]));

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
                    printf("\n\tVOCÊ NÃO POSSUI SALDO SUFICIENTE PARA REALIZAR ESTA OPERAÇÃO\n\n"); system("pause");

                    principal();
                }
                else
                {
                    //DEBITAÇÃO DA CONTA ORIGEM
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
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transferência bancária no valor de R$%.2f para |%s|", dia, mes, ano, palavra2[0], valor, palavra4[0]);
                    fclose(file);

                    strcpy(txt, palavra4[0]); strcat(txt, "\\"); strcat(txt, palavra4[0]); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

                    file = fopen(txt, "a");
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transferência bancária no valor de R$%.2f para você.", dia, mes, ano, palavra2[0], valor, palavra4[0]);
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

            printf("\n\n\nUm código de verificação foi enviado para seu email.\n\nDIGITE O CÓDIGO AQUI: "); getchar(); gets(codigo1);

            FILE *file;
            file = fopen("0.txt", "r");
                fscanf(file, "%s", codigo2);
            fclose(file);

            if(strcmp(codigo1, codigo2) == 0)
            {
                printf("\n\nCÓDIGO DE VERIFICAÇÃO CORRETO\n\n");

                if(valor > contP.saldo[0])
                {
                    printf("\n\tVOCÊ NÃO POSSUI SALDO SUFICIENTE PARA REALIZAR ESTA OPERAÇÃO\n\n"); system("pause");

                    principal();
                }
                else
                {
                    //DEBITAÇÃO DA CONTA ORIGEM
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
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transferência bancária no valor de R$%.2f para |%s|", dia, mes, ano, palavra2[0], valor, palavra4[0]);
                    fclose(file);

                    strcpy(txt, palavra4[0]); strcat(txt, "\\"); strcat(txt, strlwr(palavra4[0])); strcat(txt, "_"); strcat(txt, "HISTORICO"); strcat(txt, ".txt");

                    file = fopen(txt, "a");
                    fprintf(file, "\nNo dia %d/%d/%d |%s| fez uma transferência bancária no valor de R$%.2f para você.", dia, mes, ano, palavra2[0], valor, palavra4[0]);
                    fclose(file);

                    printf("\n\tVALOR DE R$%.2f ADICIONADOS A CONTA %s (PERTENCENTE A: %s) COM SUCESSO!\n\n", valor, ncontaD, palavra4[0]); system("pause");

                    principal();
                }
            }
            else
            {
                printf("\n\n\tCÓDIGO DE VERIFICAÇÃO INCORRETO\n\n"); system("pause");

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

//DEPÓSITO BANCÁRIO
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

        printf("\n\tQUAL É O VALOR QUE VOCÊ DESEJA DEPOSITAR  %s?\n\n", strupr(palavra2[0]));

        printf("VALOR EM R$: "); scanf("%f",&valor);

        if(valor < 10)
        {
            printf("\n\tVOCÊ SÓ PODE DEPOSITAR VALORES ACIMA DE R$10\n\n"); system("pause");

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

            printf("\n\tBOLETO CRIADO COM SUCESSO! PAGUE EM QUALQUER LOTÉRICA OU AGÊNCIA BANCÁRIA DO BANCO 99 EM NO MÁXIMO 2 DIAS\n\n"); getchar(); system("pause");

            principal();
        }
    }
    else
    {
        printf("\n\tVOCÊ JÁ CRIOU UM BOLETO. PAGUE O BOLETO ANTERIOR ANTES DE CRIAR OUTRO.\n\n"); system("pause");

        principal();
    }

    return NULL;
}

//PROPRIEDADES DO CARTÃO
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
        printf("\n\tO QUE VOCÊ DESEJA FAZER PRIMEIRO    %s?             FATURA: R$%.2f\n\n", strupr(palavra2[0]), contP.fatura[0]);

        printf("[0] VER TRANSAÇÕES\n");
        printf("[1] PAGAR FATURA\n");
        printf("[2] BLOQUEAR CARTÃO\n");
        printf("[3] VOLTAR\n\n");

        printf("OPÇÃO: "); resp=scanint(resp);
    }
    else
    {
        printf("\n\tO QUE VOCÊ DESEJA FAZER PRIMEIRO    %s?             FATURA: R$%.2f\n\n", strupr(palavra2[0]), contP.fatura[0]);

        printf("[0] VER TRANSAÇÕES\n");
        printf("[1] PAGAR FATURA\n");
        printf("[2] DESBLOQUEAR CARTÃO\n");
        printf("[3] VOLTAR\n\n");

        printf("OPÇÃO: "); resp=scanint(resp);
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
            printf("\n\tVOCÊ AINDA NÃO REALIZOU NENHUMA TRANSAÇÃO BANCÁRIA\n\n"); system("pause");

            cartao();
        }
        else
        {
            char conteudo[1000];

            printf("\n\tAQUI ESTÃO TODAS AS SUAS TRANSAÇÕES BANCÁRIAS   %s\n", strupr(palavra2[0]));


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
                printf("\n\tVOCÊ NÃO POSSUI SALDO SUFICIENTE PARA PAGAR SUA FATURA\n\n"); system("pause");

                cartao();
            }
        }
        else
        {
            printf("\n\tVOCÊ NÃO POSSUI FATURA PARA PAGAR\n\n"); system("pause");

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

            printf("\n\tTEM CERTEZA QUE VOCÊ DESEJA BLOQUEAR SEU CARTÃO?\n\n");

            printf("[0] SIM\n");
            printf("[1] NÃO\n\n");

            printf("OPÇÃO: "); resp=scanint(resp);

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
                fprintf(file, "\nNo dia %d/%d/%d você bloqueou seu cartão", dia, mes, ano);
                fclose(file);

                printf("\n\n\tCARTÃO BLOQUEADO COM SUCESSO\n\n"); system("pause");

                cartao();
            }
            if(resp == 1)
            {
                cartao();
            }
            if((resp != 0) && (resp != 1))
            {
                printf("\n\tOPÇÃO INVÁLIDA\n\n"); system("pause");

                cartao();
            }
        }
        else
        {
            system("cls");

            printf("\n\tDESEJA DESBLOQUEAR SEU CARTÃO?\n\n");

            printf("[0] SIM\n");
            printf("[1] NÃO\n\n");

            printf("OPÇÃO: "); resp=scanint(resp);

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

                    printf("\n\nUm código de verificação foi enviado para seu email.\n\nDIGITE O CÓDIGO AQUI: "); gets(codigo1);

                    FILE *file;
                    file = fopen("0.txt", "r");
                    fscanf(file, "%s", codigo2);
                    fclose(file);

                    if(strcmp(codigo1, codigo2) == 0)
                    {
                        char txt[1000];

                        strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, "CARTAO_BLOCK"); strcat(txt, ".txt");

                        remove(txt);

                        printf("\n\tCÓDIGO DE VERIFICAÇÃO CORRETO\n\n"); system("pause");

                        cartao();
                    }
                    else
                    {
                        printf("\n\tCÓDIGO DE VERIFICAÇÃO INCORRETO\n\n"); system("pause");

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

                        printf("\n\n\tCARTÃO DESBLOQUEADO COM SUCESSO!\n\n"); system("pause");

                        cartao();
                    }
                    else
                    {
                        printf("\n\tLOGIN OU SENHA INVÁLIDOS\n\n"); system("pause");

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
                printf("\n\tOPÇÃO INVÁLIDA!\n\n"); system("pause");

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
        printf("\n\tOPÇÃO INVÁLIDA\n\n"); system("pause");

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

    printf("\n\tO QUE VOCÊ DESEJA FAZER PRIMEIRO    %s?\n\n", strupr(palavra2[0]));

    printf("[0] ALTERAR LOGIN/SENHA\n");
    printf("[1] VERIFICAÇÃO POR DUAS ETAPAS");

    strcpy(txt, palavra2[0]); strcat(txt, "\\"); strcat(txt, palavra2[0]); strcat(txt, "_"); strcat(txt, palavra1[9]); strcat(txt, ".txt");

    FILE *file;
    file = fopen(txt, "r");

    if(file == NULL)
        printf("    [!!]");

    fclose(file);


    printf("\n[2] PERGUNTAS DE SEGURANÇA");

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

    printf("\n\nOPÇÃO: "); resp=scanint(resp);


    if(resp == 0)
    {
        system("cls");

        printf("\n\tVOCÊ DESEJA ALTERAR O LOGIN OU A SENHA  %s?\n\n", strupr(palavra2[0]));

        printf("[0] LOGIN\n");
        printf("[1] SENHA\n\n");

        printf("OPÇÃO: "); resp=scanint(resp);


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

                    printf("\n\nUm código de verificação foi enviado para seu email.\n\nDIGITE O CÓDIGO AQUI: "); gets(codigo1);

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

                        printf("\n\tCÓDIGO DE VERIFICAÇÃO CORRETO. LOGIN ALTERADO COM SUCESSO!\n\n"); system("pause");

                        conta();
                    }
                    else
                    {
                        printf("\n\tCÓDIGO DE VERIFICAÇÃO INCORRETO\n\n"); system("pause");

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
                printf("\n\tOS LOGINS INFORMADOS NÃO COINCIDEM!\n\n"); system("pause");

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

                    printf("\n\nUm código de verificação foi enviado para seu email.\n\nDIGITE O CÓDIGO AQUI: "); gets(codigo1);

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

                        printf("\n\tCÓDIGO DE VERIFICAÇÃO CORRETO. SENHA ALTERADA COM SUCESSO!\n\n"); system("pause");

                        conta();
                    }
                    else
                    {
                        printf("\n\tCÓDIGO DE VERIFICAÇÃO INCORRETO\n\n"); system("pause");

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
                printf("\n\tAS SENHAS INFORMADAS NÃO COINCIDEM!\n\n"); system("pause");

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
            printf("\n\tATENÇÃO: VOCÊ AINDA NÃO POSSUI ATIVA A VERIFICAÇÃO POR DUAS ETAPAS!");

            printf("\n\nSTATUS: DESATIVADO");

            printf("\n\n\nATIVAR VERIFICAÇÃO POR DUAS ETAPAS?\n\n");
            printf("[0] SIM\n");
            printf("[1] NÃO\n\n");

            printf("OPÇÃO: "); resp=scanint(resp);

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

                printf("\n\n\tVERIFICAÇÃO POR DUAS ETAPAS ATIVADA COM SUCESSO!\nMAIS INFORMAÇÕES ESTÃO DISPONÍVEIS NO EMAIL QUE ENVIAMOS PARA VOCÊ\n\n"); system("pause");

                conta();
            }

            if(resp == 1)
                conta();
        }
        else
        {
            printf("\n\tVERIFICAÇÃO POR DUAS ETAPAS");

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
            printf("\n\tATENÇÃO: VOCÊ AINDA NÃO RESPONDEU AS PERGUNTAS DE SEGURANÇA!");

            printf("\n\nSTATUS: DESATIVADO");

            printf("\n\n\nRESPONDER AGORA?\n\n");
            printf("[0] SIM\n");
            printf("[1] NÃO\n\n");

            printf("OPÇÃO: "); resp=scanint(resp);

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

                printf("\n\n\tRESPOSTAS DE SEGURANÇA ARMAZENADAS COM SUCESSO\n\n"); system("pause");

                conta();
            }

            if(resp == 1)
                conta();
        }
        else
        {
            printf("\n\tPERGUNTAS DE SEGURANÇA");

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

        printf("\n\tDIGITE AS INFORMAÇÕES ABAIXO\n\n");

        printf("POR FAVOR DIGITE O ASSUNTO DO EMAIL: "); gets(assunto);

        printf("\n\nDIGITE ABAIXO SUA MENSAGEM PARA O SUPORTE:\n\n"); gets(mensagem);

        printf("\n\nProcessando... Aguarde");

        //CRIANDO TXT PARA ARMAZENAR O NOME DO USUÁRIO
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
        printf("\n\tOPÇÃO INVÁLIDA\n\n"); system("pause");

        principal();
    }

    return NULL;
}

//FUNÇÃO PARA INFORMAR O EMAIL DO USUÁRIO EM UM TXT
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

//FUNÇÃO QUE AVISA QUANDO NÃO HÁ CONEXÃO COM A INTERNET
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

//FUNÇÃO QUE APAGA OS DOCUMENTOS QUE SE TORNAM DESNECESSÁRIOS APÓS SEREM USADOS
int del_doc() //FINALIZADO
{
    remove("0.txt");
    remove("1.txt");
    remove("2.txt");
    remove("3.txt");
    remove("4.txt");

    return NULL;
}

//FUNÇÃO APENAS PARA AVISAR O USUÁRIO QUE SEU APP NÃO ESTÁ TOTALMENTE DESBLOQUEADO
int aviso()
{
    system("cls");

    printf("\n\tINTERNET BANKING\n\n");

    printf("STATUS: DESATIVADO");

    printf("\n\nAVISO: POR QUESTÕES DE SEGURANÇA.\nATUALMENTE SUA CONTA ESTÁ BLOQUEADA PARA FAZER QUALQUER TIPO DE OPERAÇÃO BANCÁRIA VIA INTERNET BANKING.\
            \n\nPARA DESBLOQUEAR ESSA AÇÃO, POR FAVOR VÁ A UM CAIXA ELETRÔNICO DO BANCO 99 MAIS PRÓXIMO DE VOCÊ E ACESSE:\
            \n\n\tCONFIGURAÇÕES -> INTERNET BANKING\n\nPARA QUE VOCÊ POSSA APROVEITAR TODOS OS BENEFÍCIOS OFERECIDOS POR NÓS.\n\n"); system("pause");

    return NULL;
}

//SAIR DO PROGRAMA
int sair() //FINALIZADO
{
    system("cls");

    int resp=0;

    printf("\n\tVOCÊ DESEJA SAIR OU VOLTAR PARA O MENU PRINCIPAL?\n\n");

    printf("[0] SAIR\n");
    printf("[1] MENU PRINCIPAL\n\n");

    printf("OPÇÃO: "); resp=scanint(resp);

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
        printf("\n\tOPÇÃO INVÁLIDA\n\n"); system("pause");

        exit(0);
    }

    return NULL;
}
