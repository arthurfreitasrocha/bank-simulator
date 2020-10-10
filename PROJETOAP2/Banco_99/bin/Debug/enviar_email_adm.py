import smtplib
from email.mime.text import MIMEText
import os

arq = open('1.txt', 'r')
email = arq.readlines()
arq.close()

arq = open('2.txt', 'r')
assunto = arq.read()
arq.close()

arq = open('3.txt', 'r')
conteudo = arq.read()
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
    message = MIMEText(conteudo) # conteúdo da mensagem
    message['subject'] = assunto # assunto do email
    message['from'] = from_addr
    message['to'] = ', '.join(to_addrs)

    # conectaremos de forma segura usando SSL
    server = smtplib.SMTP_SSL(smtp_ssl_host, smtp_ssl_port)
    # para interagir com um servidor externo precisaremos
    # fazer login nele
    server.login(username, password)
    server.sendmail(from_addr, to_addrs, message.as_string())
    server.quit()

    os.remove('1.txt')
    os.remove('2.txt')
    os.remove('3.txt')
    
except:
    print('ERRO: Você precisa estar online para realizar esta operação')
