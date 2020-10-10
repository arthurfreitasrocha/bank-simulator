import smtplib
from email.mime.text import MIMEText
from random import *

# criando codigo de acesso
codigoacesso1 = randrange(0,9)
codigoacesso2 = randrange(0,9)
codigoacesso3 = randrange(0,9)
codigoacesso = str(codigoacesso1) + str(codigoacesso2) + str(codigoacesso3)

# colocando o codigo de acesso em um arquivo .txt
arq = open('0.txt', 'w')
arq.write(str(codigoacesso))
arq.close

# lendo arquivo criado pelo programa em C
arq = open('1.txt', 'r')
email = arq.readlines()
arq.close()

try:
    # conexão com os servidores do google
    smtp_ssl_host = 'smtp.gmail.com'
    smtp_ssl_port = 465
    # username ou email para logar no servidor
    username = 'no.answer.banco99@gmail.com'
    password = '#EsUh100%'

    from_addr = 'no.answer.banco99@gmail.com'
    to_addrs = email

    # a biblioteca email possuí vários templates
    # para diferentes formatos de mensagem
    # neste caso usaremos MIMEText para enviar
    # somente texto
    message = MIMEText('Parece que você está tentando mudar sua senha.\n\nDigite o código abaixo para confirmar a operação.\n\nCÓDIGO: {}'.format(codigoacesso)) # conteúdo da mensagem
    message['subject'] = 'Você está mudando sua senha?' # assunto do email
    message['from'] = from_addr
    message['to'] = ', '.join(to_addrs)

    # conectaremos de forma segura usando SSL
    server = smtplib.SMTP_SSL(smtp_ssl_host, smtp_ssl_port)
    # para interagir com um servidor externo precisaremos
    # fazer login nele
    server.login(username, password)
    server.sendmail(from_addr, to_addrs, message.as_string())
    server.quit()
except:
    arq = open('2.txt', 'w')
    arq.write('VOCÊ PRECISA ESTAR ONLINE PARA REALIZAR ESTA OPERAÇÃO')
    arq.close()
