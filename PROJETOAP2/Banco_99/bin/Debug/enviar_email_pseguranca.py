import smtplib
from email.mime.text import MIMEText

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
    message = MIMEText('Você acabou de cadastrar suas perguntas de segurança\n\nAs perguntas feitas foram:\n\n\t- Qual o nome de seu primeiro animal de estimação?\n\t- Qual o nome da mãe de sua mãe?\n\t- Qual o nome da primeira cidade que você morou?\n\nLembrando que as perguntas de segurança são uma forma oferecida pelo Banco 99, onde, caso você esqueça sua senha, você poderá recupera-la sem a necessidade de entrar em contato com o suporte.\n\nSempre que precisar estaremos a disposição.\n\nAtenciosamente Banco 99.') # conteúdo da mensagem
    message['subject'] = 'Perguntas de Segurança!' # assunto do email
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
