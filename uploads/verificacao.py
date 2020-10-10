import os
import time

def resposta():
    comando = ['cd C:\\Users\\%username%\\PROJETOAP2\\Banco99\\bin\\Debug', 'contas_block.bat']
    
    # le conteudo de 'info.txt' e atribui as variaveis
    file = open('info.txt', 'r')
    conteudo = file.read()
    file.close()
    
    conteudo_final = conteudo.split('-')
    nome_user = conteudo_final[0]
    valor_compra = conteudo_final[1]
    operacao = conteudo_final[2]
    


# inicio do programa
comando = 'cd C:\\uploads'

start = 0
i = 0
while(i < 1):
    time.sleep(1)
    try:
        os.system(comando)
        
        file = open('info.txt', 'r')
        conteudo = file.read()
        file.close()
        
        print('GERAL: arquivo info.txt encontrado')
        time.sleep(1)
        i = 1
        start = 1

    except:
        print('GERAL: arquivo ainda não encontrado')
        
if start == 1:
    resposta()
