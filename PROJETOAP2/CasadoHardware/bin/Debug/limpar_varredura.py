import os

def main():
    # LÊ O ARQUIVO QUE CONTÉM O NOME DAS COMPRAS
    file = open('varredura.txt', 'r')
    conteudo_file = file.read()
    file.close()

    # FILTRA O NOME DOS ARQUIVOS
    conteudo = conteudo_file.split('"')
    print(conteudo)
    os.system('pause')

    lista = []
    
    # COLOCA EM UMA LISTA O NOME DE CADA ARQUIVO
    i = 0
    while(i < len(conteudo)):
        if (str(conteudo[i]) != '\n') and (str(conteudo[i]) != 'carrinho.txt') and (str(conteudo[i]) != 'contador.txt'):
            conteudo_F = str(conteudo[i]).split('.')

            print(conteudo_F)
            os.system('pause')
            
            lista.append(str(conteudo_F[0]))

            print(lista)
            os.system('pause')

        i+=1

    

    # ABRE OS ARQUIVOS E COLOCA O CONTEUDO DE CADA UM EM UM ARQUIVO
    i = 0
    while(i < len(lista)):
        txt = 'carrinho\\{}.txt'.format(lista[i])

        file = open(txt, 'r')
        conteudo = file.read()
        file.close()

        if(i == 0):
            file = open('resp_varredura.txt', 'w')
            file.write('[{}] {}'.format(i, conteudo))
            file.close()
            
        elif(i > 0):
            file = open('resp_varredura.txt', 'a')
            file.write('[{}] {}'.format(i, conteudo))
            file.close()

        i+=1

    file = open('resp_varredura_indice.txt', 'w')
    file.write('{}'.format(i))
    file.close()
    
main()
