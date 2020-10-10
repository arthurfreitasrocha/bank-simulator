import os
import time


# inicio do programa
comando = 'cd C:\\uploads'

start = 0
i = 0
while(i < 1):
    time.sleep(1)
    try:
        os.system(comando)
        
        file = open('dados.txt', 'r')
        conteudo = file.read()
        file.close()

        print('DADOS 1: arquivo dados.txt encontrado')
        time.sleep(1)
        i = 1
        start = 2

    except:
        print('DADOS 1: arquivo ainda não encontrado')

