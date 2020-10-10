import os
import time

def resposta2():

    comando = 'enviar_email_duasetapas_codigo.py'
    
    # le conteudo de 'dados.txt' e atribui as variaveis
    file = open('dados.txt', 'r')
    nconta = file.read()
    file.close()

    try:
        # pegando o nome do cliente
        
        txt = '{}\\{}_NOME COMPLETO.txt'.format(nconta, nconta)
        
        file = open(txt, 'r')
        nome = file.read()
        file.close()

        # pegando o email do cliente

        txt = '{}\\{}_EMAIL.txt'.format(nome, nome)

        file = open(txt, 'r')
        email = file.read()
        file.close()

        file = open('email.txt', 'w')
        file.write(email)
        file.close()

        os.system(comando)
        
    except:
        file = open('resposta.txt', 'w')
        file.write('FALSE')
        file.close()
        exit(0)

resposta2()
