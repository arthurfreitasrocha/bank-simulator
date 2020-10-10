from tkinter import *
from tkinter import messagebox
from datetime import datetime
from caixa_menu import Principal #meu módulo
from caixa_admin import Admin

__author__ = 'Arthur Freitas Rocha'

#FUNCIONALIDADE SECUNDÁRIAS - INÍCIO
horario = datetime.now()
horario_h = int(horario.strftime('%H'))
horario_m = int(horario.strftime('%M'))

if horario_m < 10:
    minuto = str('0{}'.format(horario_m))
    horario_m = minuto

#FIM

#ONDE A MÁGICA ACONTECE - INÍCIO
def dados():
    i = 0
    
    #PEGA OS DADOS INFORMADOS
    conta = e_conta.get()
    login = e_login.get()
    senha = e_senha.get()

    if (conta == '99999') and (login == 'admin') and (senha == 'admin'):
        i = 1
        
        user = 'admin'
        conta = '99999'
        
        janela.destroy()

        teste = Admin(user,conta)

        #exit(0)

    if i == 0:
        if (conta == '') or (login == '') or (senha == ''):
            messagebox.showinfo('Campos vazios', 'Um ou mais campos estão vazios. Por favor, preencha todos os campos antes de clicar em ENVIAR')
        else:
            try:
                #A PARTIR DO Nº DA CONTA O PROGRAMA PEGA O NOME DO USUÁRIO
                txt = conta + '\\' + conta + '_NOME COMPLETO.txt'
                user_string = open(txt, 'r')
                user = user_string.read()
                user_string.close()
                    
                #APÓS PEGAR O NOME DO USUÁRIO, O SISTEMA PEGA O LOGIN E A SENHA
                txt = user + '\\' + user + '_LOGIN.txt'
                login_string = open(txt, 'r')
                login_doc = login_string.read()
                login_string.close()

                txt = user + '\\' + user + '_SENHA.txt'
                senha_string = open(txt, 'r')
                senha_doc = senha_string.read()
                senha_string.close()

                if (login != login_doc) or (senha != senha_doc):
                    e_senha.delete(0, END)
                    
                    messagebox.showwarning('Dados Inválidos', 'Um ou mais dados inseridos são inválidos')
                else:
                    messagebox.showinfo('Logado', 'Logado com sucesso!')

                    janela.destroy()

                    # ENTRA NO MENU DO CAIXA #
                    teste = Principal(user, conta) 
            except:
                messagebox.showwarning('Dados Inválidos', 'Um ou mais dados inseridos são inválidos')
#FIM

janela = Tk()

#EVENTOS - INÍCIO
def key(event):
    letra = event.char
    letra = letra.upper()

    if (letra == 'A') or (letra == 'B') or (letra == 'C') or (letra == 'D') or (letra == 'E') or (letra == 'F') or (letra == 'G') or (letra == 'H')\
        or (letra == 'J') or (letra == 'K') or (letra == 'L') or (letra == 'M') or (letra == 'N') or (letra == 'O') or (letra == 'P') or (letra == 'Q')\
        or (letra == 'S') or (letra == 'T') or (letra == 'U') or (letra == 'V') or (letra == 'W') or (letra == 'X') or (letra == 'Y') or (letra == 'Z')\
        or (letra == '!') or (letra == '@') or (letra == '#') or (letra == '$') or (letra == '%') or (letra == '¨') or (letra == '&') or (letra == '&')\
        or (letra == '*') or (letra == '(') or (letra == ')') or (letra == '-') or (letra == '_') or (letra == '+') or (letra == '§') or (letra == '=')\
        or (letra == '´') or (letra == '`') or (letra == '{') or (letra == '[') or (letra == 'ª') or (letra == '^') or (letra == '~') or (letra == '}')\
        or (letra == ']') or (letra == 'º') or (letra == '<') or (letra == ',') or (letra == '>') or (letra == '.') or (letra == ':') or (letra == ';')\
        or (letra == '/') or (letra == '?') or (letra == '°') or (letra == '|') or (letra == 'R') or (letra == 'I'):
        
        messagebox.showinfo('Caracter inválido', 'Por favor, digite apenas números')
#FIM
        

#NOME - CAIXA ELETRÔNICO - INÍCIO
f1 = Frame(janela, bg='goldenrod', height=150, width=500)
f1.pack(side=TOP)

l_nome = Label(f1, fg='white', bg='goldenrod', font=('arial', 25, 'bold'), text='BANCO 99')
l_nome.place(x=320, y=19)

l1_nome = Label(f1, fg='white', bg='goldenrod', font=('arial', 23), text='CAIXA ELETRÔNICO|')
l1_nome.place(x=7, y=20)

#CONFIGURAÇÃO PRA DIZER BOM (...horário...)
if (int(horario_h) >= 6) and (int(horario_h) < 12):
    if horario_h < 10:
        hora = str('0{}'.format(horario_h))
        horario_h = hora
    
    l_bv = Label(f1, fg='white', bg='goldenrod', font=('arial', 30, 'bold'), text='BOM DIA!')
    l_bv.place(x=40, y=75)

    l_H = Label(f1, fg='white', bg='goldenrod', font=('arial', 24, 'bold'), text='{}:{}'.format(horario_h, horario_m))
    l_H.place(x=370, y=78)

if (int(horario_h) >= 12) and (int(horario_h) < 18):
    if horario_h < 10:
        hora = str('0{}'.format(horario_h))
        horario_h = hora
        
    l_bv = Label(f1, fg='white', bg='goldenrod', font=('arial', 27, 'bold'), text='BOA TARDE!')
    l_bv.place(x=40, y=75)

    l_H = Label(f1, fg='white', bg='goldenrod', font=('arial', 24, 'bold'), text='{}:{}'.format(horario_h, horario_m))
    l_H.place(x=370, y=78)

if (int(horario_h) >= 18) and (int(horario_h) < 23.59):
    if horario_h < 10:
        hora = str('0{}'.format(horario_h))
        horario_h = hora
        
    l_bv = Label(f1, fg='white', bg='goldenrod', font=('arial', 30, 'bold'), text='BOA NOITE!')
    l_bv.place(x=40, y=75)

    l_H = Label(f1, fg='white', bg='goldenrod', font=('arial', 24, 'bold'), text='{}:{}'.format(horario_h, horario_m))
    l_H.place(x=370, y=78)

if (int(horario_h) >= 0) and (int(horario_h) < 6):
    if horario_h < 10:
        hora = str('0{}'.format(horario_h))
        horario_h = hora
        
    l_bv = Label(f1, fg='white', bg='goldenrod', font=('arial', 30, 'bold'), text='BOA MADRUGADA!')
    l_bv.place(x=40, y=75)

    l_H = Label(f1, fg='white', bg='goldenrod', font=('arial', 24, 'bold'), text='{}:{}'.format(horario_h, horario_m))
    l_H.place(x=370, y=78)
#FIM


#LABEL BASE - INFO USER - INÍCIO
f2 = Frame(janela, bg='khaki', height=370, width=500)
f2.pack(side=TOP)
#FIM

#INFO CONTA - INÍCIO
f3 = Frame(f2, bg='dark khaki', height=70, width=460)
f3.place(x=20, y=20)

l_conta = Label(f3, fg='white', bg='dark khaki', font=('arial', 20, 'bold'), text='CONTA: ')
l_conta.place(x=10, y=15)

e_conta = Entry(f3, font=('arial', 20))
e_conta.bind('<Key>', key)
e_conta.place(x=130, y=15)
#FIM

#INFO LOGIN - INÍCIO
f4 = Frame(f2, bg='dark khaki', height=70, width=460)
f4.place(x=20, y=110)

l_login = Label(f4, fg='white', bg='dark khaki', font=('arial', 20, 'bold'), text='LOGIN: ')
l_login.place(x=10, y=15)

e_login = Entry(f4, font=('arial', 20))
e_login.place(x=130, y=15)
#FIM

#INFO SENHA - INÍCIO
f5 = Frame(f2, bg='dark khaki', height=70, width=460)
f5.place(x=20, y=200)

l_senha = Label(f5, fg='white', bg='dark khaki', font=('arial', 20, 'bold'), text='SENHA: ')
l_senha.place(x=10, y=15)

e_senha = Entry(f5, font=('arial', 20), show='*')
e_senha.place(x=130, y=15)
#FIM

#BOTÃO ENVIAR - INÍCIO
seta = PhotoImage(file = 'seta.png')
setaimagem = seta.subsample(3, 3)

b_enviar = Button(f2, width=170, fg='white', bg='dark khaki', font=('arial', 15, 'bold'), text='ENVIAR    ',
                  image = setaimagem, compound = RIGHT, activebackground='DarkOliveGreen3', activeforeground='white', command=dados)
b_enviar.place(x=180, y=290)
#FIM

#CONFIG DA JANELA
janela.iconbitmap('icone.ico')
janela.title('CAIXA ELETRÔNICO - BANCO 99')
janela.geometry('500x520+400+100')
janela.resizable(width=False, height=False)
janela.mainloop()
