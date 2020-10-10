import os
import time

def resposta2():
    dados1 = ['nome completo', 'idade', 'cpf', 'celular', 'endereço', 'email']
    dados2 = ['data_validade', 'ncartao', 'ncodigo']
    
    # le conteudo de 'dados.txt' e atribui as variaveis
    file = open('dados2.txt', 'r')
    codigo_user = file.read()
    file.close()

    file = open('codigo.txt', 'r')
    codigo = file.read()
    file.close()

    if codigo_user == codigo:

        file = open('dados.txt', 'r')
        nconta = file.read()
        file.close()

        txt = '{}\\{}_NOME COMPLETO.txt'.format(nconta, nconta)
        
        file = open(txt, 'r')
        nome_user = file.read()
        file.close()

        i = 0
        while(i < 6):
            txt = '{}\\{}_{}.txt'.format(nome_user, nome_user, dados1[i])

            file = open(txt, 'r')
            conteudo = file.read()
            file.close()

            
            file = open('resposta.txt', 'a')
            file.write('{}-'.format(conteudo))
            file.close()

            i+=1

        i = 0
        while(i < 3):
            txt = '{}\\cartao\\{}.txt'.format(nome_user, dados2[i])

            file = open(txt, 'r')
            conteudo = file.read()
            file.close()

            print(txt, conteudo)


            if(i == 2):
                file = open('resposta.txt', 'a')
                file.write('{}'.format(conteudo))
                file.close()
                
            else:
                file = open('resposta.txt', 'a')
                file.write('{}-'.format(conteudo))
                file.close()

            i+=1

        file = open('resposta.txt', 'a')
        file.write('-{}'.format(nconta))
        file.close()
        
    else:
        file = open('resposta.txt', 'w')
        file.write('FALSE')
        file.close()

resposta2()
