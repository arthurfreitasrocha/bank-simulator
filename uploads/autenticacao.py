from datetime import datetime

def verificar_saldo(nconta_comprador, valor_compra, operacao_compra, nome_comprador):

    now = datetime.now()

    dia = now.day
    mes = now.month
    ano = now.year

    nconta = nconta_comprador
    valor = valor_compra
    operacao = operacao_compra
    nome = nome_comprador

    # VERIFICANDO SE O CARTÃO ESTÁ BLOQUEADO
    
    txt = '{}\\{}_CARTAO_BLOCK.txt'.format(nome, nome)

    try:
        file = open(txt, 'r')
        file.close()

        return 0

    except:
        if operacao == 'debito':
            #autenticação saldo
            txt = '{}\\{}_SALDO.txt'.format(nome, nome)

            file = open(txt, 'r')
            saldo = float(file.read())
            file.close()

            if(saldo >= valor) and (saldo != 0):
                saldo -= valor
                saldo = str(saldo)

                txt = '{}\\{}_SALDO.txt'.format(nome, nome)

                file = open(txt, 'w')
                file.write(saldo)
                file.close()

                txt = '{}\\{}_HISTORICO.txt'.format(nome, nome)

                file = open(txt, 'a')
                file.write('\nNo dia {}/{}/{} você fez uma compra na Casa do Hardware no valor de R${}'.format(dia, mes, ano, valor))
                file.close()

                return 1
            else:
                return 0
            
        elif operacao == 'credito':
            #autenticação saldo
            txt = '{}\\{}_LIMITE.txt'.format(nome, nome)

            file = open(txt, 'r')
            limite = float(file.read())
            file.close()

            txt = '{}\\{}_FATURA.txt'.format(nome, nome)

            file = open(txt, 'r')
            fatura = float(file.read())
            file.close()

            if(limite >= valor) and (limite > -1):
                limite -= valor
                limite = str(limite)

                txt = '{}\\{}_LIMITE.txt'.format(nome, nome)

                file = open(txt, 'w')
                file.write(limite)
                file.close()


                fatura += valor
                fatura = str(fatura)

                txt = '{}\\{}_FATURA.txt'.format(nome, nome)

                file = open(txt, 'w')
                file.write(fatura)
                file.close()

                txt = '{}\\{}_HISTORICO.txt'.format(nome, nome)

                file = open(txt, 'a')
                file.write('\nNo dia {}/{}/{} você fez uma compra na Casa do Hardware no valor de R${}'.format(dia, mes, ano, valor))
                file.close()

                return 1
            else:
                return 0


def verificar_existencia(nconta):
    try:
        txt = '{}\\{}_NOME COMPLETO.txt'.format(nconta, nconta)

        file = open(txt, 'r')
        conteudo = file.read()
        file.close()
        nome = conteudo
        return nome


    except:
        file = open('resposta.txt', 'w')
        file.write('FALSE'.format(nconta))
        file.close()
        exit(0)

file = open('info.txt', 'r')
conteudo_file = file.read()
file.close()

conteudo = conteudo_file.split('-')

nconta = conteudo[0]
valor = float(conteudo[1])
operacao = conteudo[2]

#autenticação usuário
nome = verificar_existencia(nconta)

var = verificar_saldo(nconta, valor, operacao, nome)
print(var)

if var == 0:
    file = open('resposta.txt', 'w')
    file.write('FALSE'.format(nconta))
    file.close()

elif var == 1:

    file = open('resposta.txt', 'w')
    file.write('TRUE'.format(nconta))
    file.close()
    

