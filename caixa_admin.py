from tkinter import *
from tkinter import messagebox
from datetime import datetime
from PIL import ImageTk, Image
import os

__author__ = 'Arthur Freitas Rocha'

user='admin'
conta='99999'

def main(user, conta):

    def sair():
        janela.destroy()

    def contas_block_func():

        def janela():

            def unblock():
                
                try:
                    user_digitado = e_nome.get()
                    txt = '{}\\{}_BLOCK.txt'.format(user_digitado, user_digitado)

                    file = open('{}\\{}_EMAIL.txt'.format(user_digitado, user_digitado), 'r')
                    email = file.read()
                    file.close()

                    os.remove(txt)

                    file = open('1.txt', 'w')
                    file.write(email)
                    file.close()
                    
                    comando = 'enviar_email_unblock.py'

                    os.system(comando)

                    messagebox.showinfo('Sucesso', 'Cliente desbloqueado com sucesso')

                    top.destroy()
                except:
                    messagebox.showinfo('Erro', 'Cliente inexistente ou já desbloqueado')

                    try:
                        os.remove('1.txt')
                    except:
                        pass

            top = Toplevel()

            # PERGUNTA - INÍCIO
            f1 = Frame(top, width=450, height=70, bg='goldenrod')
            f1.pack(side=TOP)

            l1 = Label(f1, text='ADMINISTRAÇÃO', font=('arial', 20, 'bold'), bg='goldenrod', fg='white')
            l1.place(x=20, y=17)

            logo = ImageTk.PhotoImage(Image.open('logo2.png'))

            l2 = Label(f1, image=logo, bg='goldenrod')
            l2.place(x=350, y=7)
            # FIM

            # FRAME BOTÕES - INÍCIO
            f2 = Frame(top, width=450, height=100, bg='khaki')
            f2.pack(side=TOP)
            #FIM
        
            scrollbar = Scrollbar(f2)
            scrollbar.pack(side=RIGHT, fill=Y)

            mylist = Text(f2, width=60, height=5, yscrollcommand = scrollbar.set, font=('arial', 12))

            i = 0
            while(i < var):

                if situacao[i] == 1:
                    mylist.insert(INSERT, '{}    CONTA BLOQUEADA\n'.format(client_user[i]))
                    
                elif situacao[i] == 0:
                    mylist.insert(INSERT, '{}    OK\n'.format(client_user[i]))

                i += 1

            mylist.pack(side = LEFT)
            scrollbar.config(command = mylist.yview)

            # FRAME BOTÕES - INÍCIO
            f3 = Frame(top, width=450, height=150, bg='khaki')
            f3.pack(side=TOP)
            #FIM

            var_nome = StringVar()
            var_nome.set('Digite o nome do cliente aqui')

            e_nome = Entry(f3, width=47, font=('arial', 13, 'bold'), textvariable=var_nome)
            e_nome.place(x=8, y=25)

            b_unblock = Button(f3, text='Desbloquear Conta', font=('arial', 14, 'bold'), bg='dark khaki', fg='white',
                               activebackground='DarkOliveGreen3', activeforeground='white', command=unblock)
            b_unblock.place(x=120, y=70)

            top.iconbitmap('icone.ico')
            top.title('ADMIN VISUALIZAR CONTAS - BANCO 99')
            top.geometry('450x300+700+100')
            top.resizable(width=False, height=False)
            top.mainloop()
            

        def obter_n_linhas(nomeDoArquivo):
            arquivo = open(nomeDoArquivo, "r")
            n_linhas = sum(1 for linha in arquivo)
            arquivo.close()
            return n_linhas

        comando = 'contas_block.bat'
        
        os.system(comando)

        file = open('lista.txt', 'r')
        diretorios_file = file.readlines()
        file.close

        n = obter_n_linhas(nomeDoArquivo='lista.txt')

        diretorios = []

        i = 0
        while(i < n):
            diretorios_F = (diretorios_file[i].split('\\'))
            diretorios.append(diretorios_F[8])

            i += 1

        pasta = []
        var = 0
        i = 0
        while(i >= 0):
            try:
                pasta.append(int(diretorios[i]))
                
                if (pasta[i] >= 00000) and (pasta[i] <= 99999):
                    i += 1
                    var += 1
            
            except:
                i = -1

        client_user = []
        situacao = []
        i = 0
        while(i < var):
            txt = '{}\\{}_NOME COMPLETO.txt'.format(pasta[i], pasta[i])
            file = open(txt, 'r')
            client_user.append(file.read())
            file.close()
            
            txt = '{}\\{}_BLOCK.txt'.format(client_user[i], client_user[i])

            try:
                file = open(txt, 'r')
                file.close()

                situacao.append(1)
                
            except:
                situacao.append(0)
            
            i += 1

        janela()
        

    def email_func():

        def enviar_email_func():

            email = e_destinatario.get()
            assunto = e_assunto.get()
            conteudo = t_conteudo.get('1.0', END)
            
            comando = 'enviar_email_adm.py'

            file = open('1.txt', 'w')
            file.write(email)
            file.close()

            file = open('2.txt', 'w')
            file.write(assunto)
            file.close()

            file = open('3.txt', 'w')
            file.write(conteudo)
            file.close()

            os.system(comando)

            messagebox.showinfo('Sucesso', 'Email enviado com sucesso para {}!'.format(email))

            top.destroy()

        top = Toplevel()

        # PERGUNTA - INÍCIO
        f1 = Frame(top, width=450, height=70, bg='goldenrod')
        f1.pack(side=TOP)

        l1 = Label(f1, text='ADMINISTRAÇÃO', font=('arial', 20, 'bold'), bg='goldenrod', fg='white')
        l1.place(x=20, y=17)

        logo = ImageTk.PhotoImage(Image.open('logo2.png'))

        l2 = Label(f1, image=logo, bg='goldenrod')
        l2.place(x=350, y=7)
        # FIM

        # FRAME BOTÕES - INÍCIO
        f2 = Frame(top, width=450, height=100, bg='khaki')
        f2.pack(side=TOP)
        #FIM

        e_var_destinatario = StringVar()
        e_var_destinatario.set('Destinatário')

        e_var_assunto = StringVar()
        e_var_assunto.set('Assunto')
        
        
        e_destinatario = Entry(f2, width=38, font=('arial', 15), textvariable=e_var_destinatario)
        e_destinatario.place(x=15, y=20)

        e_assunto = Entry(f2, width=38, font=('arial', 15), textvariable=e_var_assunto)
        e_assunto.place(x=15, y=55)


        f3 = Frame(top, width=450, height=100, bg='khaki')
        f3.pack(side=TOP)

        s = Scrollbar(f3)
        s.pack(side=RIGHT, fill=Y)        
        
        t_conteudo = Text(f3, font=('arial', 15), width=42, height=8, yscrollcommand=s.set)
        t_conteudo.insert(INSERT, 'Conteúdo do email')

        t_conteudo.pack(side=LEFT)
        s.config(command=t_conteudo.yview)


        f4 = Frame(top, width=450, height=45, bg='khaki')
        f4.pack(side=TOP)

        b_enviar = Button(f4, text='ENVIAR', font=('arial', 12, 'bold'), bg='dark khaki', fg='white',
                               activebackground='DarkOliveGreen3', activeforeground='white', command=enviar_email_func)
        b_enviar.place(x=190, y=5)

        top.iconbitmap('icone.ico')
        top.title('ADMIN ENVIAR EMAIL - BANCO 99')
        top.geometry('450x400+700+100')
        top.resizable(width=False, height=False)
        top.mainloop()
            
    janela = Tk()

    # PERGUNTA - INÍCIO
    f1 = Frame(janela, width=600, height=70, bg='goldenrod')
    f1.pack(side=TOP)

    l1 = Label(f1, text='ADMINISTRAÇÃO', font=('arial', 20, 'bold'), bg='goldenrod', fg='white')
    l1.place(x=20, y=17)

    logo = ImageTk.PhotoImage(Image.open('logo2.png'))

    l2 = Label(f1, image=logo, bg='goldenrod')
    l2.place(x=350, y=7)
    # FIM

    # FRAME BOTÕES - INÍCIO
    f2 = Frame(janela, width=600, height=330, bg='khaki')
    f2.pack(side=BOTTOM)
    #FIM

    # BOTÃO CONTAS BLOCK - INÍCIO
    b_contas_block = Button(f2, text='CONTAS BLOQUEADAS', font=('aria', 20, 'bold'), bg='dark khaki', fg='white', command=contas_block_func,
                          activebackground='DarkOliveGreen3', activeforeground='white')
    b_contas_block.place(x=40, y=30)
    # FIM

    # BOTÃO ENVIAR EMAIL - INÍCIO
    b_enviar_email_user = Button(f2, text='ENVIAR EMAIL', font=('aria', 20, 'bold'), bg='dark khaki', fg='white', command=email_func,
                           activebackground='DarkOliveGreen3', activeforeground='white')
    b_enviar_email_user.place(x=40, y=100)
    # FIM

    # BOTÃO SAIR - INÍCIO
    b_sair = Button(f2, text='SAIR', font=('aria', 20, 'bold'), bg='dark khaki', fg='white', command=sair,
                           activebackground='DarkOliveGreen3', activeforeground='white')
    b_sair.place(x=290, y=100)
    # FIM
        
    # CONFIGURAÇÕES JANELA SECUNDÁRIA01 - INÍCIO
    janela.iconbitmap('icone.ico')
    janela.title('SEÇÃO ADMIN - BANCO 99')
    janela.geometry('430x260+200+100')
    janela.resizable(width=False, height=False)
    janela.mainloop()
    # FIM

class Admin:

    def __init__(self, user, conta):
        self.user = user
        self.conta = conta

        main(self.user, self.conta)

#main(user, conta)
