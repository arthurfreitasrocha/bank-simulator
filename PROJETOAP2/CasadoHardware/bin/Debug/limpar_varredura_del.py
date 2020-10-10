import os

def main():
    cont = 0
    cont_del = 0
    
    # LÊ O ARQUIVO QUE CONTÉM O NOME DAS COMPRAS
    file = open('varredura.txt', 'r')
    conteudo_file = file.read()
    file.close()

    file = open('resp_varredura_indice.txt', 'r')
    indice = file.read()
    file.close()

    file = open('carrinho\\contador.txt', 'r')
    contador_file = file.read()
    file.close()

    # FILTRA O NOME DOS ARQUIVOS
    conteudo = conteudo_file.split('"')

    lista = []
    lista_del = []
    lista_F = []
    
    # COLOCA EM UMA LISTA O NOME DE CADA ARQUIVO
    i = 0
    while(i < len(conteudo)):
        if (str(conteudo[i]) != '\n') and (str(conteudo[i]) != 'carrinho.txt') and (str(conteudo[i]) != 'contador.txt'):
            conteudo_F = str(conteudo[i]).split('.')
            lista.append(str(conteudo_F[0]))

            
        i+=1


    i = 0
    while(i < int(contador_file)):
        
        if i != int(indice):
            lista_F.append(lista[i])
            
        else:
            lista_del.append(lista[i])

        i+=1

    # COLOCA O CONTEUDO DO ARQUIVO QUE SERÁ EXCLUIDO
    txt = 'carrinho\\{}.txt'.format(lista_del[0])
    comando = 'del carrinho\\{}.txt'.format(lista_del[0])
    
    file = open(txt, 'r')
    conteudo = file.read()
    file.close()

    os.system(comando)

    file = open('resp_varredura_item.txt', 'w')
    file.write('{}'.format(conteudo))
    file.close()

    # ATUALIZA CONTADOR CARRINHO
    file = open('carrinho\\contador.txt', 'r')
    contador = int(file.read())
    file.close()

    contador -= 1

    # VERIFICA SE O CARRINHO ESTÁ VAZIO
    if contador == 0:
        comando = 'rmdir carrinho /s /q'
        os.system(comando)

    else:
        file = open('carrinho\\contador.txt', 'w')
        file.write(str(contador))
        file.close()

        # ABRE OS ARQUIVOS E COLOCA O CONTEUDO DE CADA UM EM UM ARQUIVO
        i = 0
        while(i < cont):
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
