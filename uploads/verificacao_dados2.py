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
        
        file = open('dados2.txt', 'r')
        conteudo = file.read()
        file.close()

        print('DADOS 2: arquivo dados2.txt encontrado')
        time.sleep(1)
        i = 1
        start = 2

    except:
        print('DADOS 2: arquivo ainda não encontrado')

