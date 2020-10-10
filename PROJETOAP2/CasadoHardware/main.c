#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

char comando[100], txt[100], conteudo[1000], valor[100];
int resp, i, id, quant=0, item, cont_compra=0;

char palavra1[1000][1000] = {"nome completo", "idade", "cpf", "celular", "endere�o", "email", "login", "senha"};
char palavra2[1000][1000] = {"nome completo", "idade", "cpf", "celular", "endere�o", "email", "login", "senha"};

char cartao1[1000][1000] = {"ncartao", "data_validade", "ncodigo", "nconta"};
char cartao2[1000][1000] = {"ncartao", "data_validade", "ncodigo", "nconta"};

char cel1[1000][1000] = {"CAPA", "FONE", "CARREGADOR", "CHIP", "CARTAO SD", "PELICULA"};
char cel2[1000][1000] = {"30.00", "30.00", "40.00", "10.00","20.00", "30.00"};

char eletro1[1000][1000] = {"COMPUTADORES", "NOTEBOOKS", "MOUSES", "TECLADOS", "MOUSEPADS", "FONES"};
char eletro2[1000][1000] = {"1500.00", "1500.00", "30.00", "45.00", "8.00", "30.00"};

char hard1[1000][1000] = {"COOLERS", "HD", "FONTES", "MEM�RIA RAM", "PLACA DE VIDEO", "PLACA MAE", "PROCESSADORES", "SSD"};
char hard2[1000][1000] = {"20.00", "280.00", "44.60", "94.00", "218.00", "352.00", "330.50", "110.00", "160.00"};


//FUN��O INICIAL DO PROGRAMA
int main() // FINALIZADO
{
    system("cls");

    setlocale(LC_ALL, "Portuguese");

    strcpy(comando, "rmdir carrinho /s /q");
    system(comando);

    system("cls");

    del_doc();

    printf("\n\t\tBEM-VINDO A CASA DO HARDWARE!");
    printf("\n               O que voc� quer fazer primeiro?\n\n");

    printf("[0] LOGIN\n");
    printf("[1] CADASTRO\n");
    printf("[2] ACESSAR CAT�LOGO\n");
    printf("[3] SAIR\n\n");

    printf("OP��O: "); scanf("%d",&resp);
    if(resp == 0)
        login_func();
    if(resp == 1)
        quest();
    if(resp == 2)
        catalogo();
    if(resp == 3)
    {
        system("cls");

        printf("\n\tMUITO OBRIGADO PELA PREFER�NCIA! AT� A PR�XIMA\n\n"); system("pause");

        //return 0;
    }
    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3))
    {
        printf("\n\tRESPOSTA INV�LIDA!\n\n"); system("pause");

        main();
    }
}

void login_func() // FINALIZADO
{
    system("cls");

    char login[100], senha[100], login_file[100], senha_file[100];

    printf("\n\tREALIZANDO LOGIN...\n\n");

    printf("LOGIN: "); getchar(); gets(login);
    printf("\nSENHA: "); gets(senha);

    strcpy(txt, login); strcat(txt, "\\"); strcat(txt, login); strcat(txt, "_LOGIN.txt");

    FILE *file;

    file = fopen(txt, "r");
    while(fgets(login_file, sizeof(login_file), file) != NULL)
    fclose(file);

    file = fopen(txt, "r");
    while(fgets(senha_file, sizeof(senha_file), file) != NULL)
    fclose(file);

    if((strcmp(login, login_file) != 0) && (strcmp(senha, senha_file) != 0))
    {
        printf("\n\tUM OU MAIS DADOS INV�LIDOS\n\n"); system("pause");

        main();
    }
    else
    {
        strcpy(palavra2[6], login);

        printf("\n\tLOGADO COM SUCESSO!\n\n"); system("pause");

        catalogo();
    }
}

//FUN��O PARA O USU�RIO ESCOLHER ENTRE FAZER UMA NOVA CONTA OU USAR OS DADOS DO BANCO 99
void quest() // FINALIZADO
{
    system("cls");

    printf("\n\t\tN�S SOMOS PARCEIROS DO BANCO 99!\n");
    printf("\n\tVoc� j� possui conta banc�ria no Banco 99?\n\n");

    printf("[0] SIM\n");
    printf("[1] N�O\n\n");

    printf("OP��O: "); scanf("%d",&resp); getchar();

    //POSSUI CONTA NO BANCO
    if(resp == 0)
    {
        system("cls");

        printf("\n\t\tN�S SOMOS PARCEIROS DO BANCO 99!\n");
        printf("\n\tDeseja realizar seu cadastro utilizando sua conta do Banco 99?\n\n");

        printf("[0] SIM\n");
        printf("[1] N�O\n\n");

        printf("OP��O: "); scanf("%d",&resp); getchar();

        //CADASTRO COM AS INFORMA��ES DO BANCO
        if(resp == 0)
        {
            system("cls");

            char nconta[100], codigo[100], comando[100], temp[100];

            system("cls");

            FILE *file;

            printf("\n\tN�S SOMOS PARCEIROS DO BANCO 99!\n");
            printf("\nPor favor nos informe os dados abaixo\n\n");

            printf("\nDIGITE SEU N� DE CONTA: "); gets(nconta); printf("\n\nLIXO VISUAL LOGO ABAIXO\n\n");

            file = fopen("dados.txt", "w");
            fprintf(file, "%s", nconta);
            fclose(file);

            strcpy(comando, "requisicao_dados.py");
            system(comando);

            printf("\n\nCASO O N� DA CONTA INFORMADO ESTEJA CORRETO, VOC� RECEBER� UM EMAIL COM UM C�DIGO DE VALIDA��O EM ALGUNS INSTANTES.\nPOR FAVOR, DIGITE O C�DIGO AQUI -- C�DIGO: "); gets(codigo);

            printf("\n\nLIXO VISUAL LOGO ABAIXO\n\n");

            file = fopen("dados2.txt", "w");
            fprintf(file, "%s", codigo);
            fclose(file);

            strcpy(comando, "requisicao_dados2.py");
            system(comando);

            file = fopen("resposta.txt", "r");
            while(fgets(temp, sizeof(temp), file) != NULL)
            fclose(file);

            if(strcmp(temp, "FALSE") == 0)
            {
                system("cls");

                printf("\n\tOPS. ALGO DEU ERRADO. TEM CERTEZA DE QUE VOC� DIGITOU O C�DIGO CORRETAMENTE?\n\n"); system("pause");

                main();
            }
            else
            {
                system("cls");

                printf("\n\tSUCESSO! C�DIGO CORRETO.\n\n"); system("pause");

                // PEGANDO AS INFORMA��ES
                for(i = 0; i < 6; i++)
                {
                    strcpy(txt, palavra1[i]); strcat(txt, ".txt");

                    file = fopen(txt, "r");
                    while(fgets(palavra2[i], sizeof(palavra2[i]), file) != NULL)
                    fclose(file);
                }

                for(i = 0; i < 4; i++)
                {
                    strcpy(txt, cartao1[i]); strcat(txt, ".txt");

                    file = fopen(txt, "r");
                    while(fgets(cartao2[i], sizeof(cartao2[i]), file) != NULL)
                    fclose(file);
                }
            }

            system("cls");

            //VERIFICAR LOGIN
            func();

            printf("\nSENHA: "); gets(palavra2[7]);

            printf("\n\tCONFIRMAR CADASTRO?\n");

            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); scanf("%d",&resp); printf("\n\nAGUARDE...");

            if(resp == 0)
            {
                email();

                strcpy(comando, "enviar_email.py");
                system(comando);

                erro_conexao();

                //DIRET�RIO DO USU�RIO
                CreateDirectory(strlwr(palavra2[6]), NULL);

                //DIRET�RIO DO CART�O
                strcpy(txt, palavra2[6]); strcat(txt, "\\cartao");
                CreateDirectory(strlwr(txt), NULL);

                //INFORMA��ES PESSOAIS
                for(i = 0; i < 8; i++)
                {
                    strcpy(txt, strlwr(palavra2[6])); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[6])); strcat(txt, "_"); strcat(txt, strupr(palavra1[i])); strcat(txt, ".txt");

                    FILE *file;

                    file = fopen(txt, "w");
                    fprintf(file, "%s", strlwr(palavra2[i]));
                    fclose(file);
                }

                //CART�O
                for(i = 0; i < 4; i++)
                {
                    strcpy(txt, strlwr(palavra2[6])); strcat(txt, "\\cartao\\"); strcat(txt, cartao1[i]); strcat(txt, ".txt");

                    FILE *file;

                    file = fopen(txt, "w");
                    fprintf(file, "%s", strlwr(cartao2[i]));
                    fclose(file);
                }

                strcpy(txt, strlwr(palavra2[6])); strcat(txt, "\\"); strcat(txt, strlwr(palavra2[6])); strcat(txt, "_"); strcat(txt, "ID"); strcat(txt, ".txt");

                FILE *file;

                file = fopen("id_geral.txt", "r");
                fscanf(file, "%d",&id);
                fclose(file);

                file = fopen(txt, "w");
                fprintf(file, "%d", id);
                fclose(file);

                id++;

                file = fopen("id_geral.txt", "w");
                fprintf(file, "%d",id);
                fclose(file);

                del_doc();

                printf("\n\n\tCADASTRO REALIZADO COM SUCESSO! SEJA MUITO BEM-VINDO!\n\n"); system("pause");

                catalogo();
            }
            if(resp == 1)
            {
                printf("\n\tCADASTRO CANCELADO\n\n"); system("pause");

                main();
            }
            if((resp != 0) && (resp != 1))
            {
                printf("\n\tRESPOSTA INV�LIDA!");

                main();
            }
        }
        if(resp == 1)
        {
            cadastro();
        }
        if((resp != 0) && (resp != 1))
        {
            printf("\n\tRESPOSTA INV�LIDA!");

            main();
        }
    }
    if(resp == 1)
        cadastro();
    if((resp != 0) && (resp != 1))
    {
        printf("\n\tRESPOSTA INV�LIDA!");

        main();
    }
}

//FUN��O PARA VERIFICAR O USU�RIO
void func() // FINALIZADO
{
    system("cls");

    printf("\n\tAQUI EST�O SEUS DADOS\n");

    for(i = 0; i < 6; i++)
    {
        printf("\n%s: %s", strupr(palavra1[i]), strupr(palavra2[i]));
    }

    printf("\n\n\tPOR FAVOR INFORME SEU LOGIN E SENHA\n");

    printf("\nLOGIN: "); gets(palavra2[6]);

    strcpy(txt, palavra2[6]); strcat(txt, "\\"); strcat(txt, palavra2[6]); strcat(txt, "_NOME COMPLETO.txt");

    FILE *file;

    file = fopen(txt, "r");
    fclose(file);

    if(file != NULL)
    {
        printf("\n\tERRO: Nome de usu�rio j� em uso\n\n"); system("pause");
        func();
    }
}

//FUN��O PARA REALIZAR O CADASTRO DAQUELES QUE N�O TEM CONTA NO BANCO 99 OU N�O QUEREM USAR AS INFORMA��ES DO BANCO 99
void cadastro() // FINALIZADO
{
    system("cls");

    int i;

    printf("\n\tINFORME OS SEGUINTES DADOS\n");

    for(i=0; i<8; i++)
    {
        //TRATAMENTO DE ERROS

        if(i == 5)
        {
            int y = 0, cont=0;
            char email[1000];

            printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

            if(strcmp(palavra2[i], "") == 0)
            {
                printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                cadastro();
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

                    cadastro();
                }
            }
        }


        if(i == 3)
        {
            int conteudo=0;

            printf("\n%s: +55", strupr(palavra1[i])); gets(palavra2[i]);

            if(strcmp(palavra2[i], "") == 0)
            {
                printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                cadastro();
            }

            conteudo=strlen(palavra2[i]);

            if((conteudo <= 10) || (conteudo > 11))
            {
                printf("\n\nATEN��O: N�mero de celular inv�lido para o Brasil\n\n"); system("pause");

                cadastro();
            }
        }

        if(i == 2)
        {
            int conteudo=0;

            printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

            if(strcmp(palavra2[i], "") == 0)
            {
                printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                cadastro();
            }

            conteudo=strlen(palavra2[i]);

            if((conteudo < 11) || (conteudo > 11))
            {
                printf("\n\nATEN��O: CPF inv�lido\n\n"); system("pause");

                cadastro();
            }
        }

        if(i == 1)
        {
            int anosN=0;

            printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]); anosN = atoi(palavra2[i]);

            if(strcmp(palavra2[i], "") == 0)
            {
                printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                cadastro();
            }

            if(anosN < 18)
            {
                printf("\n\nATEN��O: Idade inv�lida\n\n"); system("pause");

                cadastro();
            }
        }

        if(i == 0)
        {
            int y, cont=0;
            char nome[1000], txt[100];

            //PRINTANDO NOME
            printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

            if(strcmp(palavra2[i], "") == 0)
            {
                printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                cadastro();
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

                cadastro();
            }
        }

        if((i != 0) && (i != 1) && (i != 2) && (i != 3) && (i != 5))
        {
            printf("\n%s: ", strupr(palavra1[i])); gets(palavra2[i]);

            if(strcmp(palavra2[i], "") == 0)
            {
                printf("\n\nATEN��O: Espa�o vazio detectado, por favor digite suas informa��es corretamente\n\n"); system("pause");

                cadastro();
            }
        }
    }

    //FIM DIGITAR INFORMA��ES

    printf("\n\nDESEJA CONFIRMAR OS DADOS ACIMA? [ 0=SIM / 1=N�O ]: "); scanf("%d",&resp);

    if(resp == 0)
    {
        printf("\nProcessando... Aguarde");

        email();

        strcpy(comando, "enviar_email.py");
        system(comando);

        erro_conexao();

        //DIRETORIO DO USU�RIO
        CreateDirectory(palavra2[6], NULL);

        //INFORMA��ES PESSOAIS
        for(i=0; i<8; i++)
        {
            strcpy(txt, palavra2[6]); strcat(txt, "\\"); strcat(txt, palavra2[6]); strcat(txt, "_"); strcat(txt, strupr(palavra1[i])); strcat(txt, ".txt");

            FILE *file;

            file = fopen(txt, "w");
            fprintf(file, "%s", palavra2[i]);
            fclose(file);
        }

        printf("\n\n\tCADASTRO REALIZADO COM SUCESSO! SEJA MUITO BEM-VINDO!\n\n"); system("pause");

        catalogo();
    }
    if(resp == 1)
    {
        printf("\n\tCADASTRO CANCELADO!\n\n"); system("pause");

        main();
    }
    if((resp != 0) && (resp != 1))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        main();
    }
}

//FUN��O QUE MOSTRA O CAT�LOGO DA LOJA
void catalogo() // FINALIZADO
{
    system("cls");

    for(i = 0; i < 8; i++)
    {
        strcpy(txt, palavra2[6]); strcat(txt, "\\"); strcat(txt, palavra2[6]); strcat(txt, "_"); strcat(txt, palavra1[i]); strcat(txt, ".txt");

        FILE *file;

        file = fopen(txt, "r");
        while(fgets(palavra2[i], sizeof(palavra2[i]), file) != NULL)
        fclose(file);
    }

    if(strcmp(palavra2[0], "nome completo") == 0)
    {
        strcpy(palavra2[0], "cliente");
    }

    printf("\n\tOL� |%s| E SEJA MUITO BEM-VINDO A CASA DO HARDWARE!\n", palavra2[0]);
    printf("\nO que voc� quer olhar primeiro?\n\n");

    printf("[0] ITENS PARA CELULAR\n");
    printf("[1] ELETR�NICOS\n");
    printf("[2] HARDWARE\n");
    printf("[3] CARRINHO\n");
    printf("[4] SAIR\n\n");

    printf("OP��O: "); scanf("%d",&resp);

    if(resp == 0)
        celular();
    if(resp == 1)
        eletronicos();
    if(resp == 2)
        hardware();
    if(resp == 3)
        menu_compra();
    if(resp == 4)
    {
        system("cls");

        printf("\n\tDESEJA SAIR OU VOLTAR AO MENU PRINCIPAL?\n\n");

        printf("[0] SAIR\n");
        printf("[1] MENU PRINCIPAL\n\n");

        printf("OP��O: "); scanf("%d",&resp);

        if(resp == 1)
            main();
        if(resp == 0)
        {
            system("cls");

            printf("\n\tMUITO OBRIGADO PELA PREFER�NCIA! AT� A PR�XIMA\n\n"); system("pause");

            return 0;
        }
    }
    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3) && (resp != 4))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        catalogo();
    }
}

// FUN��O QUE MOSTRA OS ITENS REALACIONADOS A 'ITENS DE CELULAR' QUE EST�O A VENDA
void celular() // FINALIZADO
{
    system("cls");

    printf("\n\tBOM |%s|, POR AQUI N�S TEMOS...\n", palavra2[0]);

    for(i = 0; i < 6; i++)
    {
        printf("\n[%d] %s -> R$: %s", i, cel1[i], cel2[i]);
    }

    printf("\n\n\tQUAL DE NOSSO MARAVILHOS ITENS VOC� DESEJA |%s|?\n\n", palavra2[0]);

    printf("OP��O: "); scanf("%d",&item);

    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3) && (resp != 4) && (resp != 5))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        celular();
    }


    printf("\n\tQUANTOS |%s| VOC� DESEJA?\n\n", cel1[item]);

    printf("RESPOSTA: "); scanf("%d",&quant);

    //ADICIONANDO PRODUTO ESCOLHIDO AO CARRINHO
    FILE *file;

    strcpy(txt, "carrinho"); strcat(txt, "\\carrinho.txt");

    file = fopen(txt, "r");
    fclose(file);

    if(file == NULL)
    {
        //CRIANDO DIRET�RIO DO CARRINHO E 'carrinho.txt'
        strcpy(txt, "carrinho");
        CreateDirectory(txt, NULL);

        strcpy(txt, "carrinho\\carrinho.txt");

        file = fopen(txt, "w");
        fclose(file);

        //VERIFICANDO A EXIST�NCIA DO PRODUTO
        strcpy(txt, "carrinho"); strcat(txt, "\\"); strcat(txt, cel1[item]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
        fclose(file);

        //PRODUTO ADICIONADO AO CARRINHO
        strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, cel1[item]); strcat(txt, ".txt");

        file = fopen(txt, "w");
        fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", cel1[item], quant, cel2[item]);
        fclose(file);

        printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", cel1[item]); system("pause");

        //CONTADOR DE COMPRAS
        cont_compra++;

        strcpy(txt, "carrinho");  strcat(txt, "\\contador.txt");

        file = fopen(txt, "w");
        fprintf(file, "%d", cont_compra);
        fclose(file);
    }
    else
    {
        //VERIFICANDO A EXIST�NCIA DO PRODUTO
        strcpy(txt, "carrinho"); strcat(txt, "\\"); strcat(txt, cel1[item]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
        fclose(file);

        if(file == NULL)
        {
            //PRODUTO ADICIONADO AO CARRINHO
            strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, cel1[item]); strcat(txt, ".txt");

            file = fopen(txt, "w");
            fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", cel1[item], quant, cel2[item]);
            fclose(file);

            printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", cel1[item]); system("pause");
        }
        else
        {
            printf("\n\tPARECE QUE VOC� J� TEM |%s| ADICIONADO. DESEJA SOBREESCR�VE-LO?\n\n", cel1[item]);

            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); scanf("%d",&resp);

            if(resp == 0)
            {
                //PRODUTO ADICIONADO AO CARRINHO
                strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, cel1[item]); strcat(txt, ".txt");

                file = fopen(txt, "w");
                fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", cel1[item], quant, cel2[item]);
                fclose(file);

                printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", cel1[item]); system("pause");
            }
            if(resp == 1)
            {
                printf("\n\t|%s| N�O ADICIONADO AO CARRINHO\n\n", cel1[item]); system("pause");
            }
            if((resp != 0) && (resp != 1))
            {
                printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                catalogo();
            }

        }

        //CONTADOR DE COMPRAS
        cont_compra++;

        strcpy(txt, "carrinho");  strcat(txt, "\\contador.txt");

        file = fopen(txt, "w");
        fprintf(file, "%d", cont_compra);
        fclose(file);
    }

    system("cls");

    printf("\n\tOK! ESTAMOS QUASE FINALIZANDO SUA COMPRA. MAS ANTES NOS DIGA UMA COISA.\nVOC� QUER DAR UMA OLHADA EM OUTROS PRODUTOS OU FINALIZAR SUA COMPRA?\n\n");

    printf("[0] DAR UMA OLHADA EM OUTROS PRODUTOS\n");
    printf("[1] FINALIZAR COMPRA\n\n");

    printf("OP��O: "); scanf("%d",&resp);

    if(resp == 0)
    {
        catalogo();
    }
    if(resp == 1)
    {
        menu_compra();
    }
    if((resp != -1) || (resp != -2))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        celular();
    }
}

// FUN��O QUE MOSTRA OS ITENS REALACIONADOS A 'ELETR�NICOS' QUE EST�O A VENDA
void eletronicos() // FINALIZADO
{
    system("cls");

    printf("\n\tBOM |%s|, POR AQUI N�S TEMOS...\n", palavra2[0]);

    for(i = 0; i < 6; i++)
    {
        printf("\n[%d] %s -> R$: %s", i, eletro1[i], eletro2[i]);
    }

    printf("\n\n\tQUAL DE NOSSO MARAVILHOS ITENS VOC� DESEJA |%s|?\n\n", palavra2[0]);

    printf("OP��O: "); scanf("%d",&item);

    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3) && (resp != 4) && (resp != 5))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        celular();
    }


    printf("\n\tQUANTOS |%s| VOC� DESEJA?\n\n", eletro1[item]);

    printf("RESPOSTA: "); scanf("%d",&quant);

    //ADICIONANDO PRODUTO ESCOLHIDO AO CARRINHO
    FILE *file;

    strcpy(txt, "carrinho"); strcat(txt, "\\carrinho.txt");

    file = fopen(txt, "r");
    fclose(file);

    if(file == NULL)
    {
        //CRIANDO DIRET�RIO DO CARRINHO E 'carrinho.txt'
        strcpy(txt, "carrinho");
        CreateDirectory(txt, NULL);

        strcpy(txt, "carrinho\\carrinho.txt");

        file = fopen(txt, "w");
        fclose(file);

        //VERIFICANDO A EXIST�NCIA DO PRODUTO
        strcpy(txt, "carrinho"); strcat(txt, "\\"); strcat(txt, eletro1[item]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
        fclose(file);

        //PRODUTO ADICIONADO AO CARRINHO
        strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, eletro1[item]); strcat(txt, ".txt");

        file = fopen(txt, "w");
        fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", eletro1[item], quant, eletro2[item]);
        fclose(file);

        printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", eletro1[item]); system("pause");

        //CONTADOR DE COMPRAS
        cont_compra++;

        strcpy(txt, "carrinho");  strcat(txt, "\\contador.txt");

        file = fopen(txt, "w");
        fprintf(file, "%d", cont_compra);
        fclose(file);
    }
    else
    {
        //VERIFICANDO A EXIST�NCIA DO PRODUTO
        strcpy(txt, "carrinho"); strcat(txt, "\\"); strcat(txt, eletro1[item]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
        fclose(file);

        if(file == NULL)
        {
            //PRODUTO ADICIONADO AO CARRINHO
            strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, eletro1[item]); strcat(txt, ".txt");

            file = fopen(txt, "w");
            fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", eletro1[item], quant, eletro2[item]);
            fclose(file);

            printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", eletro1[item]); system("pause");
        }
        else
        {
            printf("\n\tPARECE QUE VOC� J� TEM |%s| ADICIONADO. DESEJA SOBREESCR�VE-LO?\n\n", eletro1[item]);

            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); scanf("%d",&resp);

            if(resp == 0)
            {
                //PRODUTO ADICIONADO AO CARRINHO
                strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, eletro1[item]); strcat(txt, ".txt");

                file = fopen(txt, "w");
                fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", eletro1[item], quant, eletro2[item]);
                fclose(file);

                printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", eletro1[item]); system("pause");
            }
            if(resp == 1)
            {
                printf("\n\t|%s| N�O ADICIONADO AO CARRINHO\n\n", eletro1[item]); system("pause");
            }
            if((resp != 0) && (resp != 1))
            {
                printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                catalogo();
            }

        }

        //CONTADOR DE COMPRAS
        cont_compra++;

        strcpy(txt, "carrinho");  strcat(txt, "\\contador.txt");

        file = fopen(txt, "w");
        fprintf(file, "%d", cont_compra);
        fclose(file);
    }

    system("cls");

    printf("\n\tOK! ESTAMOS QUASE FINALIZANDO SUA COMPRA. MAS ANTES NOS DIGA UMA COISA.\nVOC� QUER DAR UMA OLHADA EM OUTROS PRODUTOS OU FINALIZAR SUA COMPRA?\n\n");

    printf("[0] DAR UMA OLHADA EM OUTROS PRODUTOS\n");
    printf("[1] FINALIZAR COMPRA\n\n");

    printf("OP��O: "); scanf("%d",&resp);

    if(resp == 0)
    {
        catalogo();
    }
    if(resp == 1)
    {
        menu_compra();
    }
    if((resp != -1) || (resp != -2))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        hardware();
    }
}

// FUN��O QUE MOSTRA OS ITENS REALACIONADOS A 'HARDWARE' QUE EST�O A VENDA
void hardware() // FINALIZADO
{
    system("cls");

    printf("\n\tBOM |%s|, POR AQUI N�S TEMOS...\n", palavra2[0]);

    for(i = 0; i < 8; i++)
    {
        printf("\n[%d] %s -> R$: %s", i, hard1[i], hard2[i]);
    }

    printf("\n\n\tQUAL DE NOSSO MARAVILHOS ITENS VOC� DESEJA |%s|?\n\n", palavra2[0]);

    printf("OP��O: "); scanf("%d",&item);

    if((resp != 0) && (resp != 1) && (resp != 2) && (resp != 3) && (resp != 4) && (resp != 5) && (resp != 6) && (resp != 7))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        celular();
    }


    printf("\n\tQUANTOS |%s| VOC� DESEJA?\n\n", hard1[item]);

    printf("RESPOSTA: "); scanf("%d",&quant);

    //ADICIONANDO PRODUTO ESCOLHIDO AO CARRINHO
    FILE *file;

    strcpy(txt, "carrinho"); strcat(txt, "\\carrinho.txt");

    file = fopen(txt, "r");
    fclose(file);

    if(file == NULL)
    {
        //CRIANDO DIRET�RIO DO CARRINHO E 'carrinho.txt'
        strcpy(txt, "carrinho");
        CreateDirectory(txt, NULL);

        strcpy(txt, "carrinho\\carrinho.txt");

        file = fopen(txt, "w");
        fclose(file);

        //VERIFICANDO A EXIST�NCIA DO PRODUTO
        strcpy(txt, "carrinho"); strcat(txt, "\\"); strcat(txt, hard1[item]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
        fclose(file);

        //PRODUTO ADICIONADO AO CARRINHO
        strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, hard1[item]); strcat(txt, ".txt");

        file = fopen(txt, "w");
        fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", hard1[item], quant, hard2[item]);
        fclose(file);

        printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", hard1[item]); system("pause");

        //CONTADOR DE COMPRAS
        cont_compra++;

        strcpy(txt, "carrinho");  strcat(txt, "\\contador.txt");

        file = fopen(txt, "w");
        fprintf(file, "%d", cont_compra);
        fclose(file);
    }
    else
    {
        //VERIFICANDO A EXIST�NCIA DO PRODUTO
        strcpy(txt, "carrinho"); strcat(txt, "\\"); strcat(txt, hard1[item]); strcat(txt, ".txt");

        file = fopen(txt, "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
        fclose(file);

        if(file == NULL)
        {
            //PRODUTO ADICIONADO AO CARRINHO
            strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, hard1[item]); strcat(txt, ".txt");

            file = fopen(txt, "w");
            fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", hard1[item], quant, hard2[item]);
            fclose(file);

            printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", hard1[item]); system("pause");
        }
        else
        {
            printf("\n\tPARECE QUE VOC� J� TEM |%s| ADICIONADO. DESEJA SOBREESCR�VE-LO?\n\n", hard1[item]);

            printf("[0] SIM\n");
            printf("[1] N�O\n\n");

            printf("OP��O: "); scanf("%d",&resp);

            if(resp == 0)
            {
                //PRODUTO ADICIONADO AO CARRINHO
                strcpy(txt, "carrinho");  strcat(txt, "\\"); strcat(txt, hard1[item]); strcat(txt, ".txt");

                file = fopen(txt, "w");
                fprintf(file, "ITEM: %s --- QUANT.: %d --- VALOR: R$%s\n", hard1[item], quant, hard2[item]);
                fclose(file);

                printf("\n\t|%s| ADICIONADO AO CARRINHO COM SUCESSO!\n\n", hard1[item]); system("pause");
            }
            if(resp == 1)
            {
                printf("\n\t|%s| N�O ADICIONADO AO CARRINHO\n\n", hard1[item]); system("pause");
            }
            if((resp != 0) && (resp != 1))
            {
                printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                catalogo();
            }

        }

        //CONTADOR DE COMPRAS
        cont_compra++;

        strcpy(txt, "carrinho");  strcat(txt, "\\contador.txt");

        file = fopen(txt, "w");
        fprintf(file, "%d", cont_compra);
        fclose(file);
    }

    system("cls");

    printf("\n\tOK! ESTAMOS QUASE FINALIZANDO SUA COMPRA. MAS ANTES NOS DIGA UMA COISA.\nVOC� QUER DAR UMA OLHADA EM OUTROS PRODUTOS OU FINALIZAR SUA COMPRA?\n\n");

    printf("[0] DAR UMA OLHADA EM OUTROS PRODUTOS\n");
    printf("[1] FINALIZAR COMPRA\n\n");

    printf("OP��O: "); scanf("%d",&resp);

    if(resp == 0)
    {
        catalogo();
    }
    if(resp == 1)
    {
        menu_compra();
    }
    if((resp != -1) || (resp != -2))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        hardware();
    }
}

// FUN��O QUE EFETUA A COMPRA DOS PRODUTOS
void menu_compra() // FINALIZADO
{
    system("cls");

    char temp[100];
    FILE *file;

    strcpy(txt, palavra2[6]); strcat(txt, "\\"); strcat(txt, palavra2[6]); strcat(txt, "_NOME COMPLETO.txt");
    strcpy(temp, palavra2[0]);

    file = fopen(txt, "r");
    while(fgets(conteudo, sizeof(conteudo), file) != NULL)
    fclose(file);

    if(strcmp(temp, conteudo) != 0)
    {
        system("cls");

        printf("\n\tPARA COMPRAR OS ITENS DE NOSSA LOJA VOC� PRECISA ESTAR LOGADO. DEJESA LOGAR-SE OU CRIAR UMA CONTA?\n\n");

        printf("[0] LOGAR\n");
        printf("[1] CRIAR CONTA\n\n");

        printf("OP��O: "); scanf("%d",&resp);

        if(resp == 0)
            login_func();
        if(resp == 1)
            quest();
        if((resp != 0) && (resp != 1))
        {
            printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

            catalogo();
        }
    }

    system("cls");

    strcpy(txt, "carrinho\\carrinho.txt");

    file = fopen(txt, "r");
    fclose(file);

    if(file == NULL)
    {
        printf("\n\tOPS. PARECE QUE SEU CARRINHO EST� VAZIO\n\n"); system("pause");

        catalogo();
    }
    else
    {
        printf("\n\tVOC� FEZ EXCELENTES ESCOLHAS |%s|! OBRIGADO POR SELECIONAR:\n\n", palavra2[0]);

        //EXECUTA VARREDURA NO DIRET�RIO DO CARRINHO
        strcpy(comando, "varredura.bat");
        system(comando);

        file = fopen("resp_varredura.txt", "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
            printf("%s", conteudo);
        fclose(file);

        //EXECUTA VARREDURA DO PRE�O TOTAL
        strcpy(comando, "varredura_preco.bat");
        system(comando);

        file = fopen("resposta_preco.txt", "r");
        while(fgets(valor, sizeof(valor), file) != NULL)
        fclose(file);

        printf("\nTOTAL: R$%s", valor);

        printf("\n\n\tCONFIRMAR COMPRA OU CANCELAR ITEM?\n\n");

        printf("[0] CONFIRMAR COMPRA\n");
        printf("[1] CANCELAR ITEM\n");
        printf("[2] VOLTAR\n\n");

        printf("OP��O: "); scanf("%d",&resp);

        if(resp == 0)
        {
            strcpy(txt, palavra2[6]); strcat(txt, "\\cartao\\ncartao.txt");

            file = fopen(txt, "r");
            while(fgets(conteudo, sizeof(conteudo), file) != NULL)
            fclose(file);

            if(file == NULL)
            {
                system("cls");

                printf("\n\tVOC� N�O POSSUI NENHUM CART�O REGISTRADO. REGISTRAR UM AGORA?\n\n");

                printf("[0] SIM\n");
                printf("[1] N�O\n\n");

                printf("OP��O: "); scanf("%d",&resp);

                if(resp == 0)
                {
                    registrar_cartao();

                    menu_compra();
                }
                if(resp == 1)
                {
                    catalogo();
                }
                if((resp != 0) && (resp != 1))
                {
                    printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                    menu_compra();
                }
            }
            else
            {
                system("cls");

                for(i = 0; i < 4; i++)
                {
                    strcpy(txt, palavra2[6]); strcat(txt, "\\cartao\\"); strcat(txt, cartao1[i]); strcat(txt, ".txt");

                    FILE *file;

                    file = fopen(txt, "r");
                    while(fgets(cartao2[i], sizeof(cartao2[i]), file) != NULL)
                    fclose(file);
                }

                char temp[100][100];

                printf("\n\tPAGAR COM CART�O MASTERCARD BANCO 99?:\n\n");

                for(i = 0; i < strlen(cartao2[0]); i++)
                {
                    temp[0][i] = cartao2[0][i];

                    if(temp[0][i] == ' ')
                        i = strlen(cartao2[0]);
                }

                printf("N� CART�O: %s**** **** ****\n\n", temp);

                printf("[0] SIM\n");
                printf("[1] N�O\n\n");

                printf("OP��O: "); scanf("%d",&resp);

                if(resp == 0)
                {
                    system("cls");

                    printf("\n\tVOC� GOSTARIA DE PAGAR NO CR�DITO OU NO D�BITO?\n\n");

                    printf("[0] CR�DITO\n");
                    printf("[1] D�BITO\n\n");

                    printf("OP��O: "); scanf("%d",&resp); printf("\n\nLIXO VISUAL LOGO ABAIXO\n\n");

                    if(resp == 0)
                    {
                        file = fopen("info.txt", "w");
                        fprintf(file, "%s-%s-credito", cartao2[3], valor);
                        fclose(file);

                        strcpy(comando, "enviar_info.py");
                        system(comando);

                        file = fopen("resposta.txt", "r");
                        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
                        fclose(file);

                        if(strcmp(conteudo, "FALSE") == 0)
                        {
                            system("cls");

                            printf("\n\tOPS. PARECE QUE ALGO DEU ERRADO POR AQUI... OCORREU UM FALHA NA OPERA��O\n\n"); system("pause");


                            catalogo();
                        }
                        if(strcmp(conteudo, "TRUE") == 0)
                        {
                            system("cls");

                            strcpy(comando, "rmdir carrinho /s /q");
                            system(comando);

                            printf("\n\tCOMPRA REALIZADA COM SUCESSO!\n\n"); system("pause");

                            catalogo();
                        }
                    }
                    if(resp == 1)
                    {
                        file = fopen("info.txt", "w");
                        fprintf(file, "%s-%s-debito", cartao2[3], valor);
                        fclose(file);

                        strcpy(comando, "enviar_info.py");
                        system(comando);

                        file = fopen("resposta.txt", "r");
                        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
                        fclose(file);

                        if(strcmp(conteudo, "FALSE") == 0)
                        {
                            system("cls");

                            printf("\n\tOPS. PARECE QUE ALGO DEU ERRADO POR AQUI... OCORREU UM FALHA NA OPERA��O\n\n"); system("pause");

                            catalogo();
                        }
                        if(strcmp(conteudo, "TRUE") == 0)
                        {
                            system("cls");

                            strcpy(comando, "rmdir carrinho /s /q");
                            system(comando);

                            printf("\n\tCOMPRA REALIZADA COM SUCESSO!\n\n"); system("pause");

                            catalogo();
                        }
                    }
                    if((resp != 0) && (resp != 1))
                    {
                        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                        menu_compra();
                    }
                }
                if(resp == 1)
                {
                    printf("\n\tDESCULPE, MAS NO MOMENTO N�S ACEITAMOS APENAS CART�ES MASTERCARD BANCO 99\n\n"); system("pause");

                    menu_compra();
                }
                if((resp != 0) && (resp != 1))
                {
                    printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                    menu_compra();
                }

            }
        }
        if(resp == 1)
        {
            int indice=0, item;

            file = fopen("resp_varredura_indice.txt", "r");
            fscanf(file, "%d",&indice);
            fclose(file);

            printf("\n\n\tQUAL ITEM VOC� DESEJA CANCELAR?\n\n");

            printf("OP��O: "); scanf("%d",&item);

            if((resp < 0) || (resp > indice))
            {
                printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

                system("cls"); menu_compra();
            }
            else
            {
                file = fopen("resp_varredura_indice.txt", "w");
                fprintf(file, "%d", item);
                fclose(file);

                strcpy(comando, "varredura_del.bat");
                system(comando);

                file = fopen("resp_varredura_item.txt", "r");
                while(fgets(conteudo, sizeof(conteudo), file) != NULL)
                fclose(file);

                printf("\n\tSUCESSO! %s\t\tRETIRADO DO CARRINHO!\n\n", conteudo); system("pause");

                menu_compra();
            }
        }
        if(resp == 2)
        {
            catalogo();
        }
        if((resp != 0) && (resp != 1) && (resp != 2))
        {
            printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

            menu_compra();
        }
    }
}

//FUN��O PARA REGISTRAR O CART�O
void registrar_cartao() // FINALIZADO
{
    cartao:
    system("cls");

    char nconta[100];

    printf("\n\tN�S ACEITAMOS APENAS CART�ES DO BANCO 99. POIS OS MESMOS S�O NOSSOS PARCEIROS.\n\t\tPOR FAVOR, DIGITE AS INFORMA��ES ABAIXO\n\n");

    printf("N� CONTA: "); getchar(); gets(nconta);

    for(i = 0; i < 3; i++)
    {
        printf("\n%s: ", strupr(cartao1[i])); gets(cartao2[i]);
    }

    printf("\n\tSEUS DADOS EST�O CORRETOS?\n\n");

    printf("[0] SIM\n");
    printf("[1] N�O\n\n");

    printf("OP��O: "); scanf("%d",&resp); printf("\n\nLIXO VISUAL LOGO ABAIXO\n\n");

    if(resp == 0)
    {
        FILE *file;

        file = fopen("cartao.txt", "w");
        fprintf(file, "%s-%s-%s-%s", nconta, cartao2[0], cartao2[1], cartao2[2]);
        fclose(file);

        strcpy(comando, "requisicao_cartao.py");
        system(comando);

        file = fopen("resposta.txt", "r");
        while(fgets(conteudo, sizeof(conteudo), file) != NULL)
        fclose(file);

        if(strcmp(conteudo, "FALSE") == 0)
        {
            system("cls");

            printf("\n\tOPS. PARECE QUE ALGO DEU ERRADO. TEM CERTEZA DE QUE VOC� DIGITOU SUAS INFORMA��ES CORRETAMENTE?\n\n"); system("pause");

            goto cartao;
        }
        else
        {
            //DIRET�RIO DO CART�O
            strcpy(txt, palavra2[6]); strcat(txt, "\\cartao");
            CreateDirectory(strlwr(txt), NULL);

            //CART�O
            for(i = 0; i < 4; i++)
            {
                strcpy(comando, "move "); strcat(comando, cartao1[i]); strcat(comando, ".txt"); strcat(comando, " "); strcat(comando, palavra2[6]); strcat(comando, "\\cartao");
                system(comando);
            }

            system("cls");

            printf("\n\tSUCESSO! CART�O ADICIONADO\n\n"); system("pause");
        }
    }
    if(resp == 1)
    {
        goto cartao;
    }
    if((resp != 0) && (resp != 1))
    {
        printf("\n\tOP��O INV�LIDA\n\n"); system("pause");

        registrar_cartao();
    }
}

//FUN��O PARA INFORMAR O EMAIL DO USU�RIO EM UM TXT
void email() // FINALIZADO
{
    char txt[1000];

    strcpy(txt, palavra2[6]); strcat(txt, "\\"); strcat(txt, palavra2[6]); strcat(txt, "_"); strcat(txt, palavra1[5]); strcat(txt, ".txt");

    FILE *arq;
    arq = fopen(txt, "r");
    fscanf(arq, "%s", palavra2[5]);
    fclose(arq);

    arq = fopen("1.txt", "w");
    fprintf(arq, "%s", palavra2[5]);
    fclose(arq);
}

//FUN��O QUE AVISA QUANDO N�O H� CONEX�O COM A INTERNET
void erro_conexao() // FINALIZADO
{
    char conteudo[1000];

    FILE *documento;
    documento = fopen("2.txt", "r");

    if(documento == NULL)
        fclose(documento);
    else
    {
        while(fgets(conteudo, sizeof(conteudo), documento) != NULL); printf("\n\n\t");
        printf("%s", conteudo); printf("\n\n"); system("pause");

        del_doc();

        fclose(documento);

        main();
    }
}

//FUN��O QUE APAGA OS DOCUMENTOS QUE SE TORNAM DESNECESS�RIOS AP�S SEREM USADOS
void del_doc() //FINALIZADO
{
    remove("0.txt");
    remove("1.txt");
    remove("2.txt");
    remove("3.txt");
    remove("4.txt");
    remove("nome completo.txt");
    remove("idade.txt");
    remove("cpf.txt");
    remove("email.txt");
    remove("endere�o.txt");
    remove("celular.txt");
    remove("dados.txt");
    remove("resposta.txt");
    remove("data_validade.txt");
    remove("ncartao.txt");
    remove("ncodigo.txt");
    remove("cartao.txt");
    remove("resp_varredura.txt");
    remove("resposta_preco.txt");
    remove("varredura.txt");
    remove("nconta.txt");
    remove("info.txt");
    remove("dados2.txt");
    remove("resp_varredura_indice.txt");
    remove("resp_varredura_item.txt");
}
