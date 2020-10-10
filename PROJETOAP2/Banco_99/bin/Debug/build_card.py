from random import *
from datetime import datetime
import os

# pegando o nome do usuario
file = open('0.txt', 'r')
user = file.read()
file.close()

i = 0
j = 0
ncartao = ''

while(i < 4):
    while(j < 4):
        # criando numero do cartao
        n1 = randrange(1,9)
        n2 = randrange(0,9)
        n3 = randrange(0,9)
        n4 = randrange(0,9)

        if j == 0:
            ncartao = str(n1) + str(n2) + str(n3) + str(n4)
        else:
            ncartao = ncartao + ' ' + str(n1) + str(n2) + str(n3) + str(n4)

        j += 1
    i += 1


# criando código de segurança
n1 = randrange(1,9)
n2 = randrange(0,9)
n3 = randrange(0,9)
ncodigo = str(n1) + str(n2) + str(n3)


# criando data de validade do cartao
agora = datetime.now()

dia = agora.strftime('%d')
mes = int(agora.strftime('%m')) + 1 
data_validade = str(dia) + '/' + str(mes)


# criando código de segurança
n1 = randrange(1,9)
n2 = randrange(0,9)
n3 = randrange(0,9)
n4 = randrange(0,9)
n5 = randrange(0,9)
nconta = str(n1) + str(n2) + str(n3) + str(n4) + str(n5)


lista = [ncartao, ncodigo, data_validade]
lista2 = ['NCARTAO', 'NCODIGO', 'DATA_VALIDADE']
lista3 = [nconta, user]
lista4 = ['NCONTA', 'NOME COMPLETO']

# criando diretorio e armazenando dados do cartao
try:
    os.mkdir('{}\cartao'.format(user))
    os.mkdir(nconta)
except:
    i = 0
    while(i < 3):
        txt = '{}\cartao\{}.txt'.format(user, lista2[i])
        os.remove(txt)
        i += 1
    
    os.rmdir('{}\cartao'.format(user))
    os.mkdir('{}\cartao'.format(user))
    os.rmdir(nconta)
    os.mkdir(nconta)
    

i = 0
while(i < 3):
    txt = '{}\cartao\{}.txt'.format(user, lista2[i])
    file = open(txt, 'w')
    file.write(lista[i])
    file.close()
    
    i += 1

i = 0
while(i < 2):
    txt = '{}\{}_{}.txt'.format(nconta, nconta, lista4[i])
    file = open(txt, 'w')
    file.write(lista3[i])
    file.close()
    
    i += 1

txt = '{}\{}_NCONTA.txt'.format(user, user)
file = open(txt, 'w')
file.write(nconta)
file.close()

file = open('3.txt', 'w')
file.write(nconta)
file.close()
