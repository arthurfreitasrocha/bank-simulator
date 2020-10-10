def main():
    # LÊ O ARQUIVO QUE CONTÉM O NOME DAS COMPRAS
    file = open('resp_varredura.txt', 'r')
    conteudo_file = file.read()
    file.close()

    conteudo = conteudo_file.split('\n')

    valor = []
    quant = []

    i = 0
    while(i < int(len(conteudo))-1):
        temp = str(conteudo[i])
        temp2 = temp.split('$')
        valor.append(temp2[1])

        i+=1

    i = 0
    while(i < int(len(conteudo))-1):
        temp = str(conteudo[i])
        temp2 = temp.split('QUANT.: ')
        temp3 = str(temp2[1]).split(' ---')
        quant.append(temp3[0])

        i+=1

    total = 0
    i = 0
    while(i < int(len(conteudo))-1):
        temp = float(quant[i]) * float(valor[i])
        total += temp

        i+=1

    file = open('resposta_preco.txt', 'w')
    file.write(str(total))
    file.close()
    
main()
