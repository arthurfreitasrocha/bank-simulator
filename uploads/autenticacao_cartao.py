import os
import time

def resposta2():
    dados2 = ['ncartao', 'data_validade', 'ncodigo', 'nconta']
    
    # le conteudo de 'dados.txt' e atribui as variaveis
    file = open('cartao.txt', 'r')
    conteudo_files = file.read()
    file.close()

    conteudo = conteudo_files.split('-')

    ncartao = conteudo[1]
    data_validade = conteudo[2]
    ncodigo = conteudo[3]
    nconta = conteudo[0]

    try:
        txt = '{}\\{}_NOME COMPLETO.txt'.format(nconta, nconta)
        
        file = open(txt, 'r')
        nome_user = file.read()
        file.close()
        
    except:
        file = open('resposta.txt', 'w')
        file.write('FALSE')
        file.close()

    # VERIFICANDO AUTENTICIDADE DOS DADOS
    txt = '{}\\{}_NCONTA.txt'.format(nconta, nconta)
    
    file = open(txt, 'r')
    nconta_file = file.read()
    file.close()

    txt = '{}\\cartao\\DATA_VALIDADE.txt'.format(nome_user)

    file = open(txt, 'r')
    data_validade_file = file.read()
    file.close()

    txt = '{}\\cartao\\NCODIGO.txt'.format(nome_user)
    
    file = open(txt, 'r')
    ncodigo_file = file.read()
    file.close()

    txt = '{}\\cartao\\NCARTAO.txt'.format(nome_user)
    
    file = open(txt, 'r')
    ncartao_file = file.read()
    file.close()


    # ESCREVENDO INFORMAÇÕES
    
    if (nconta == nconta_file) and (data_validade == data_validade_file) and (ncodigo == ncodigo_file) and (ncartao == ncartao_file):

        file = open('resposta.txt', 'w')
        file.write('{}-'.format(data_validade))
        file.close()

        file = open('resposta.txt', 'a')
        file.write('{}-'.format(ncartao))
        file.close()

        file = open('resposta.txt', 'a')
        file.write('{}-'.format(ncodigo))
        file.close()

        file = open('resposta.txt', 'a')
        file.write('{}'.format(nconta))
        file.close()

    else:

        file = open('resposta.txt', 'w')
        file.write('FALSE'.format(data_validade))
        file.close()

resposta2()
