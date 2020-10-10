from tkinter import *
from tkinter import messagebox
from datetime import datetime
from PIL import ImageTk, Image
import os
import locale

__author__ = 'Arthur Freitas Rocha'

agora = datetime.now()

dia = agora.strftime('%d')
mes = agora.strftime('%m')
ano = agora.strftime('%Y')

user='paulo ricardo'
conta='45843'

# =========================================== MAIN ===========================================================

def main(user, conta):

    locale.setlocale(locale.LC_ALL, '')

    # FUNÇÃO RESPONSÁVEL PELAS CONFIGURAÇÕES DO CLIENTE

    def config_func():

        # =========== FUNÇÃO BOLETO ============== - INÍCIO
        
        def app_func():

            cont = 0
            
            try:
                txt = user + '\\' + user + '_TRANSACAO BLOCK.txt'
                file = open(txt, 'r')
                file.close()

                cont += 1
                    
            except:
                cont += -1
            
            if cont == -1:

                def sim_func():
                    
                     txt = user + '\\' + user + '_TRANSACAO BLOCK.txt'
                     file = open(txt, 'w')
                     file.close()

                     messagebox.showinfo('Sucesso', 'APP debloqueado com sucesso. Agora você já pode aproveitar todas as\
     vantagens oferecidas por nós através do Internet Banking.')

                     top1.destroy()
                     top.destroy()
                    
                def nao_func():
                    
                    top1.destroy()
                    top.destroy()

                top1 = Toplevel()
                    
                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='TRANSAÇÕES E MAIS\nCOM O APP', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=20, y=10)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))
                
                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=400, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # FRAME INFO - INÍCIO
                l_info = Label(f2, text='ATUALMENTE SEU APP ESTÁ BLOQUEADO\nPARA REALIZAR QUALQUER TIPO\nDE AÇÃO PELO INTERNET BANKING.\n\nDESEJA DESBLOQUEA-LO AGORA?',
                                   font=('arial', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=20, y=20)
                # FIM

                # BOTÃO SIM - INÍCIO
                sim = PhotoImage(file = 'sim.png')
                sim_imagem = sim.subsample(3, 3)
                    
                b_sim = Button(f2, width=100, text=' SIM', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=sim_imagem, compound=LEFT, command=sim_func)
                b_sim.place(x=90, y=160)
                # FIM

                # BOTÃO NÃO - INÍCIO
                nao = PhotoImage(file = 'nao.png')
                nao_imagem = nao.subsample(3, 3)
                    
                b_nao = Button(f2, width=100, text=' NÃO', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=nao_imagem, compound=LEFT, command=nao_func)
                b_nao.place(x=260, y=160)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('icone.ico')
                top1.title('APP - BANCO 99')
                top1.geometry('500x300+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM

            elif cont == 1:

                top1 = Toplevel()
                    
                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='TRANSAÇÕES E MAIS\nCOM O APP', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=20, y=10)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))

                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=400, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # FRAME INFO - INÍCIO
                l_info = Label(f2, text='STATUS DO INTERNET BANKING:\nDESBLOQUEADO',
                                   font=('arial', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=70, y=20)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('icone.ico')
                top1.title('APP - BANCO 99')
                top1.geometry('500x170+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM
                
        # FIM FUNÇÃO APP


        # =========== FUNÇÃO PERGUNTAS DE SEGURANÇA ==============
        
        def pseguranca_func():

            cont = 0
            
            try:
                txt = user + '\\' + user + '_PSEGURANCA1.txt'
                
                file = open(txt, 'r')
                file.close()

                cont += 1
                
            except:
                cont += -1


            if cont == 1:

                def sim_func():

                     txt = user + '\\' + user + '_PSEGURANCA1.txt'
                     os.remove(txt)
                     txt = user + '\\' + user + '_PSEGURANCA2.txt'
                     os.remove(txt)
                     txt = user + '\\' + user + '_PSEGURANCA3.txt'
                     os.remove(txt)

                     messagebox.showinfo('Sucesso', 'Verificação por duas etapas desativadas com sucesso')

                     top1.destroy()
                     top.destroy()
                    
                def nao_func():
                    
                    top1.destroy()
                    top.destroy()

                
                top1 = Toplevel()

                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='PERGUNTAS DE\nSEGURANÇA', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=20, y=10)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))

                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=350, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # LABEL INFO - INÍCIO
                l_info = Label(f2, text='PERGUNTAS DE SEGURANÇA ATIVADAS.\nDESEJA DESATIVAR?',
                               font=('aria', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=20, y=20)
                # FIM

                # BOTÃO SIM - INÍCIO
                sim = PhotoImage(file = 'sim.png')
                sim_imagem = sim.subsample(3, 3)
                    
                b_sim = Button(f2, width=100, text=' SIM', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=sim_imagem, compound=LEFT, command=sim_func)
                b_sim.place(x=90, y=100)
                # FIM

                # BOTÃO NÃO - INÍCIO
                nao = PhotoImage(file = 'nao.png')
                nao_imagem = nao.subsample(3, 3)
                    
                b_nao = Button(f2, width=100, text=' NÃO', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=nao_imagem, compound=LEFT, command=nao_func)
                b_nao.place(x=260, y=100)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('pseguranca.ico')
                top1.title('PERGUNTAS DE SEGURANÇA - BANCO 99')
                top1.geometry('450x250+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM

            elif cont == -1:
                top1 = Toplevel()

                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='PERGUNTAS DE SEGURANÇA', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=15, y=20)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))

                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=400, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # LABEL INFO - INÍCIO
                l_info = Label(f2, text='PERGUNTAS DE SEGURANÇA DESATIVADAS',
                               font=('aria', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=35, y=30)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('pseguranca.ico')
                top1.title('PERGUNTAS DE SEGURANÇA - BANCO 99')
                top1.geometry('500x170+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM

        # FIM FUNÇÃO PERGUNTAS DE SEGURANÇA

        # =========== FUNÇÃO DUAS ETAPAS ============== - INÍCIO
        
        def duas_etapas_func():

            cont = 0

            try:
                txt = user + '\\' + user + '_DUASETAPAS.txt'
                
                file = open(txt, 'r')
                file.close()

                cont += 1
                
            except:
                cont += -1


            if cont == 1:

                def sim_func():

                     txt = user + '\\' + user + '_DUASETAPAS.txt'
                     os.remove(txt)

                     messagebox.showinfo('Sucesso', 'Verificação por duas etapas desativadas com sucesso')

                     top1.destroy()
                     top.destroy()
                    
                def nao_func():
                    
                    top1.destroy()
                    top.destroy()

                
                top1 = Toplevel()

                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='VERIFICAÇÃO POR\nDUAS ETAPAS', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=20, y=10)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))

                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=370, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # LABEL INFO - INÍCIO
                l_info = Label(f2, text='VERIFICAÇÃO POR DUAS ETAPAS ATIVADA.\nDESEJA DESATIVAR?',
                               font=('aria', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=20, y=20)
                # FIM

                # BOTÃO SIM - INÍCIO
                sim = PhotoImage(file = 'sim.png')
                sim_imagem = sim.subsample(3, 3)
                    
                b_sim = Button(f2, width=100, text=' SIM', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=sim_imagem, compound=LEFT, command=sim_func)
                b_sim.place(x=90, y=100)
                # FIM

                # BOTÃO NÃO - INÍCIO
                nao = PhotoImage(file = 'nao.png')
                nao_imagem = nao.subsample(3, 3)
                    
                b_nao = Button(f2, width=100, text=' NÃO', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=nao_imagem, compound=LEFT, command=nao_func)
                b_nao.place(x=260, y=100)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('cadeado.ico')
                top1.title('VERIFICAÇÃO POR DUAS ETAPAS - BANCO 99')
                top1.geometry('470x250+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM

            elif cont == -1:
                top1 = Toplevel()

                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='VERIFICAÇÃO POR DUAS ETAPAS', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=15, y=20)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))

                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=400, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # LABEL INFO - INÍCIO
                l_info = Label(f2, text='VERIFICAÇÃO POR DUAS ETAPAS DESATIVADA',
                               font=('aria', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=20, y=30)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('cadeado.ico')
                top1.title('VERIFICAÇÃO POR DUAS ETAPAS - BANCO 99')
                top1.geometry('500x170+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM
                

        # FIM FUNÇÃO DUAS ETAPAS
            
        top = Toplevel()

        # PERGUNTA - INÍCIO
        f1 = Frame(top, width=600, height=70, bg='goldenrod')
        f1.pack(side=TOP)

        l1 = Label(f1, text='O QUE VOCÊ DESEJA\nFAZER PRIMEIRO?', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
        l1.place(x=20, y=10)

        logo = ImageTk.PhotoImage(Image.open('logo2.png'))

        l2 = Label(f1, image=logo, bg='goldenrod')
        l2.place(x=350, y=7)
        # FIM

        # FRAME BOTÕES - INÍCIO
        f2 = Frame(top, width=600, height=330, bg='khaki')
        f2.pack(side=BOTTOM)
        #FIM

        # BOTÃO DESBLOQUEAR APP - INÍCIO
        app = PhotoImage(file = 'logo3.png')
        app_imagem = app.subsample(3, 3)
        
        b_app = Button(f2, width=350, text=' DESBLOQUEAR APP', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                          activebackground='DarkOliveGreen3', activeforeground='white', image=app_imagem, compound=LEFT, command=app_func)
        b_app.place(x=40, y=30)
        # FIM

        # BOTÃO PERGUNTAS DE SEGURANÇA - INÍCIO
        psegunraca = PhotoImage(file = 'pseguranca.png')
        psegunraca_imagem = psegunraca.subsample(3, 3)
        
        b_psegunraca = Button(f2, width=280, text=' P. SEGURANÇA', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                           activebackground='DarkOliveGreen3', activeforeground='white', image=psegunraca_imagem, compound=LEFT, command=pseguranca_func)
        b_psegunraca.place(x=40, y=100)
        # FIM

        # BOTÃO DUAS ETAPAS - INÍCIO
        duas_etapas = PhotoImage(file = 'cadeado.png')
        duas_etapas_imagem = duas_etapas.subsample(3, 3)
        
        b_duas_etapas = Button(f2, width=270, text=' DUAS ETAPAS', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                           activebackground='DarkOliveGreen3', activeforeground='white', image=duas_etapas_imagem, compound=LEFT, command=duas_etapas_func)
        b_duas_etapas.place(x=40, y=170)
        # FIM   
        
        # CONFIGURAÇÕES JANELA SECUNDÁRIA01 - INÍCIO
        top.iconbitmap('config.ico')
        top.title('CONFIGURAÇÕES - BANCO 99')
        top.geometry('450x330+200+100')
        top.resizable(width=False, height=False)
        top.mainloop()
        # FIM

    # FIM FUNÇÃO RESPONSÁVEL PELAS CONFIGURAÇÕES DO CLIENTE















    # FUNÇÃO RESPONSÁVEL PELAS TRANSAÇÕES DO CLIENTE

    def transacao_func():

        # =========== FUNÇÃO BOLETO ============== - INÍCIO
        
        def boleto_func():

            cont = 0
            
            try:
                txt = user + '\\' + user + '_BOLETO.txt'
                file = open(txt, 'r')
                boleto = file.read()
                file.close()

                cont += 1
                    
            except:
                cont += -1

            if cont == 1:
                def sim_func():

                     nonlocal boleto

                     valor = boleto

                     saldo = []
                     teste = ''
                     i = 0
                     j = 0
                     k = 0
                    
                     txt = user + '\\' + user + '_SALDO.txt'
                     file = open(txt, 'r')
                     saldo_file = file.read()
                     file.close()

                     for x in saldo_file:
                         i += 1
                         if x == '.' or x == ',':
                             k = i
                             x = '.'
                             saldo.append(x)
                             
                         else:
                             saldo.append(int(x))

                     while(j < i):
                        teste = teste + (str(saldo[j]))
                        j += 1

                     saldo = float(teste)
                     valor = float(valor)

                     valor += saldo
                     valor = str(valor)

                     txt = user + '\\' + user + '_SALDO.txt'
                     file = open(txt, 'w')
                     file.write(valor)
                     file.close()

                     txt = user + '\\' + user + '_HISTORICO.txt'
                     file = open(txt, 'a')
                     file.write('\nNo dia {}/{}/{} |{}| pagou um boleto no valor de R${}'.format(dia, mes, ano, user.upper(), boleto))
                     file.close()

                     txt = user + '\\' + user + '_BOLETO.txt'
                     os.remove(txt)

                     messagebox.showinfo('Sucesso', 'Valor de R${} depositados em sua conta com sucesso!'.format(boleto))

                     top1.destroy()
                     top.destroy()
                    
                def nao_func():
                    
                    top1.destroy()
                    top.destroy()

                
                top1 = Toplevel()

                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='PAGAMENTO DE BOLETO', font=('arial', 20, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=15, y=10)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))

                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=400, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # LABEL INFO - INÍCIO
                l_info = Label(f2, text='VOCÊ POSSUI UM BOLETO PARA PAGAR\nNO VALOR DE R${}\n\nDESEJA PAGA-LO AGORA?'.format(boleto),
                               font=('aria', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=20, y=20)
                # FIM

                # BOTÃO SIM - INÍCIO
                sim = PhotoImage(file = 'sim.png')
                sim_imagem = sim.subsample(3, 3)
                    
                b_sim = Button(f2, width=100, text=' SIM', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=sim_imagem, compound=LEFT, command=sim_func)
                b_sim.place(x=90, y=150)
                # FIM

                # BOTÃO NÃO - INÍCIO
                nao = PhotoImage(file = 'nao.png')
                nao_imagem = nao.subsample(3, 3)
                    
                b_nao = Button(f2, width=100, text=' NÃO', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', image=nao_imagem, compound=LEFT, command=nao_func)
                b_nao.place(x=260, y=150)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('cifrao.ico')
                top1.title('PAGAR BOLETO - BANCO 99')
                top1.geometry('500x300+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM

            elif cont == -1:
                top1 = Toplevel()

                # LABEL INICIAL - INÍCIO
                f1 = Frame(top1, width=600, height=70, bg='goldenrod')
                f1.pack(side=TOP)

                l1 = Label(f1, text='PAGAMENTO DE BOLETO', font=('arial', 20, 'bold'), bg='goldenrod', fg='white')
                l1.place(x=15, y=15)

                logo = ImageTk.PhotoImage(Image.open('logo2.png'))

                l2 = Label(f1, image=logo, bg='goldenrod')
                l2.place(x=400, y=7)
                # FIM

                # FRAME BOTÕES - INÍCIO
                f2 = Frame(top1, width=600, height=330, bg='khaki')
                f2.pack(side=BOTTOM)
                #FIM

                # LABEL INFO - INÍCIO
                l_info = Label(f2, text='VOCÊ NÃO POSSUI NENHUM\nBOLETO PARA PAGAR',
                               font=('aria', 15, 'bold'), bg='dark khaki', fg='white')
                l_info.place(x=90, y=20)
                # FIM

                # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
                top1.iconbitmap('cifrao.ico')
                top1.title('PAGAR BOLETO - BANCO 99')
                top1.geometry('500x170+200+100')
                top1.resizable(width=False, height=False)
                top1.mainloop()
                # FIM
                
        # FIM FUNÇÃO BOLETO

        # =========== FUNÇÃO BOLETO ============== - INÍCIO
        
        def transacao_func():

            #EVENTOS - INÍCIO
            def key(event):
                letra = event.char
                letra = letra.upper()

                if (letra == 'A') or (letra == 'B') or (letra == 'C') or (letra == 'D') or (letra == 'E') or (letra == 'F') or (letra == 'G') or (letra == 'H')\
                    or (letra == 'J') or (letra == 'K') or (letra == 'L') or (letra == 'M') or (letra == 'N') or (letra == 'O') or (letra == 'P') or (letra == 'Q')\
                    or (letra == 'S') or (letra == 'T') or (letra == 'U') or (letra == 'V') or (letra == 'W') or (letra == 'X') or (letra == 'Y') or (letra == 'Z')\
                    or (letra == '!') or (letra == '@') or (letra == '#') or (letra == '$') or (letra == '%') or (letra == '¨') or (letra == '&') or (letra == '&')\
                    or (letra == '*') or (letra == '(') or (letra == ')') or (letra == '_') or (letra == '+') or (letra == '§') or (letra == '=')\
                    or (letra == '´') or (letra == '`') or (letra == '{') or (letra == '[') or (letra == 'ª') or (letra == '^') or (letra == '~') or (letra == '}')\
                    or (letra == ']') or (letra == 'º') or (letra == '<') or (letra == ',') or (letra == '>') or (letra == '.') or (letra == ':') or (letra == ';')\
                    or (letra == '/') or (letra == '?') or (letra == '°') or (letra == '|') or (letra == 'R') or (letra == 'I') or (letra == ' '):
                    
                    messagebox.showinfo('Caracter inválido', 'Por favor, digite apenas números')
            #FIM
            
            def dados():

                def confirmacao():

                    def checar():
                        login = e_login.get()
                        senha = e_senha.get()

                        txt = '{}\\{}_LOGIN.txt'.format(user, user)

                        file = open(txt, 'r')
                        login2 = file.read()
                        file.close()

                        txt = '{}\\{}_SENHA.txt'.format(user, user)

                        file = open(txt, 'r')
                        senha2 = file.read()
                        file.close()

                        if (login != login2) and (senha != senha2):
                            messagebox.showinfo('Login ou Senha Inválidos', 'Login ou Senha Inválidos!')

                            top2.destroy()
                            top1.destroy()
                            transacao_func()

                        else:
                            saldo_F = ''
                            
                            txt = '{}\\{}_SALDO.txt'.format(user, user)

                            file = open(txt, 'r')
                            saldo = file.read()
                            file.close

                            for letra in saldo:
                                if letra == ',' or letra == '.':
                                    letra = '.'
                                    saldo_F = saldo_F + letra
                                else:
                                    saldo_F = saldo_F + letra

                            saldo = float(saldo_F)


                            saldo_F = ''

                            txt = '{}\\{}_SALDO.txt'.format(user2, user2)

                            file = open(txt, 'r')
                            saldo2 = file.read()
                            file.close

                            for letra in saldo2:
                                if letra == ',' or letra == '.':
                                    letra = '.'
                                    saldo_F = saldo_F + letra
                                else:
                                    saldo_F = saldo_F + letra

                            saldo2 = float(saldo_F)


                            if (saldo >= valor) and (saldo > 0):

                                # DECREMENTO SALDO USER

                                txt = '{}\\{}_SALDO.txt'.format(user, user)

                                file = open(txt, 'w')
                                file.write('{}'.format(saldo-valor))
                                file.close


                                # INCREMENTO SALDO USER2

                                txt = '{}\\{}_SALDO.txt'.format(user2, user2)

                                file = open(txt, 'w')
                                file.write('{}'.format(saldo2+valor))
                                file.close

                                

                                txt = '{}\\{}_HISTORICO.txt'.format(user, user)

                                file = open(txt, 'a')
                                file.write('\nNo dia {}/{}/{} |{}| fez uma transferência no valor de R${} para |{}| através do caixa eletrônico'.format(dia, mes, ano, user.upper(), valor, user2.upper()))
                                file.close()

                                txt = '{}\\{}_HISTORICO.txt'.format(user2, user2)

                                file = open(txt, 'a')
                                file.write('\nNo dia {}/{}/{} |{}| recebeu uma transferência no valor de R${} de |{}| através do caixa eletrônico'.format(dia, mes, ano, user2.upper(), valor, user.upper()))
                                file.close()

                                top2.destroy()
                                top1.destroy()
                                top.destroy()

                                messagebox.showinfo('Sucesso', 'Valor de R${} transferidos para {} com sucesso!'.format(valor, user2.upper()))

                            else:

                                messagebox.showinfo('Falha na operação', 'Você não possui saldo suficiente para realizar esta operação')
                            
                    top2 = Toplevel()

                    f1 = Frame(top2, width=200, height=200, bg='khaki')
                    f1.pack()

                    l_login = Label(f1, text='Login:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
                    l_login.grid(row=0, column=0)

                    e_login = Entry(f1, font=('arial', 18, 'bold'))
                    e_login.grid(row=0, column=1)


                    l_senha = Label(f1, text='Senha:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
                    l_senha.grid(row=1, column=0)

                    e_senha = Entry(f1, font=('arial', 18, 'bold'), show='*')
                    e_senha.grid(row=1, column=1)


                    b_enviar = Button(f1, text='ENVIAR', font=('arial', 15, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', command=checar)
                    b_enviar.grid(row=2, columnspan=2)

                    top2.iconbitmap('icone.ico')
                    top2.title('AUTENTICAÇÃO - BANCO 99')
                    top2.resizable(width=False, height=False)
                    top2.mainloop()

            
                try:
                    nconta_destino = e_nconta_destino.get()
                    valor = float(e_valor.get())
                    user2 = ''

                    txt = '{}\\{}_NOME COMPLETO.txt'.format(nconta_destino, nconta_destino)

                    file = open(txt, 'r')
                    user2 = file.read()
                    file.close()

                    if valor < 1:
                       messagebox.showinfo('Dados Inválidos', 'Um ou mais dados inválidos')

                       top1.destroy()
                       transacao_func()
                        
                    if valor > 0:
                        confirmacao()
                        
                except:
                    messagebox.showinfo('Dados Inválidos', 'Um ou mais dados inválidos')

                    top1.destroy()
                    transacao_func()


            top1 = Toplevel()

            # LABEL INICIAL - INÍCIO
            f1 = Frame(top1, width=600, height=70, bg='goldenrod')
            f1.pack(side=TOP)

            l1 = Label(f1, text='TRANSAÇÃO\nBANCÁRIA', font=('arial', 18, 'bold'), bg='goldenrod', fg='white')
            l1.place(x=20, y=4)

            logo = ImageTk.PhotoImage(Image.open('logo2.png'))

            l2 = Label(f1, image=logo, bg='goldenrod')
            l2.place(x=260, y=7)
            # FIM

            # FRAME BOTÕES - INÍCIO
            f2 = Frame(top1, width=600, height=330, bg='khaki')
            f2.pack(side=BOTTOM)
            #FIM

            # LABEL NCONTAS - INÍCIO
            l_nconta_origem = Label(f2, text='NºCONTA ORIGEM: ', bg='dark khaki', fg='white', font=('arial', 18, 'bold'))
            l_nconta_origem.place(x=20, y=20)

            nconta = StringVar()
            e_nconta_origem = Entry(f2, width=5, textvariable=nconta, state=DISABLED, font=('arial', 18, 'bold'))
            e_nconta_origem.place(x=260, y=20)

            nconta.set(conta)


            l_nconta_destino = Label(f2, text='NºCONTA DESTINO: ', bg='dark khaki', fg='white', font=('arial', 18, 'bold'))
            l_nconta_destino.place(x=20, y=80)

            e_nconta_destino = Entry(f2, width=5, font=('arial', 18, 'bold'))
            e_nconta_destino.bind('<Key>', key)
            e_nconta_destino.place(x=270, y=80)
            # FIM


            # LABEL VALOR - INÍCIO
            l_valor = Label(f2, text='VALOR EM R$: ', bg='dark khaki', fg='white', font=('arial', 18, 'bold'))
            l_valor.place(x=20, y=140)

            e_valor = Entry(f2, width=9, font=('arial', 18, 'bold'))
            e_valor.bind('<Key>', key)
            e_valor.place(x=210, y=140)
            # FIM
            

            #BOTÃO ENVIAR - INÍCIO
            b_enviar = Button(f2, fg='white', bg='dark khaki', font=('arial', 15, 'bold'), text='ENVIAR',
                              activebackground='DarkOliveGreen3', activeforeground='white', command=dados)
            b_enviar.place(x=140, y=200)
            # FIM
                    
            # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
            top1.iconbitmap('transferencia.ico')
            top1.title('TRANSAÇÃO - BANCO 99')
            top1.geometry('360x340+200+100')
            top1.resizable(width=False, height=False)
            top1.mainloop()
            # FIM
                
        # FIM FUNÇÃO APP

        # =========== FUNÇÃO PERGUNTAS DE SEGURANÇA ==============
        
        def deposito_func():

            #EVENTOS - INÍCIO
            def key(event):
                letra = event.char
                letra = letra.upper()

                if (letra == 'A') or (letra == 'B') or (letra == 'C') or (letra == 'D') or (letra == 'E') or (letra == 'F') or (letra == 'G') or (letra == 'H')\
                    or (letra == 'J') or (letra == 'K') or (letra == 'L') or (letra == 'M') or (letra == 'N') or (letra == 'O') or (letra == 'P') or (letra == 'Q')\
                    or (letra == 'S') or (letra == 'T') or (letra == 'U') or (letra == 'V') or (letra == 'W') or (letra == 'X') or (letra == 'Y') or (letra == 'Z')\
                    or (letra == '!') or (letra == '@') or (letra == '#') or (letra == '$') or (letra == '%') or (letra == '¨') or (letra == '&') or (letra == '&')\
                    or (letra == '*') or (letra == '(') or (letra == ')') or (letra == '_') or (letra == '+') or (letra == '§') or (letra == '=')\
                    or (letra == '´') or (letra == '`') or (letra == '{') or (letra == '[') or (letra == 'ª') or (letra == '^') or (letra == '~') or (letra == '}')\
                    or (letra == ']') or (letra == 'º') or (letra == '<') or (letra == ',') or (letra == '>') or (letra == '.') or (letra == ':') or (letra == ';')\
                    or (letra == '/') or (letra == '?') or (letra == '°') or (letra == '|') or (letra == 'R') or (letra == 'I') or (letra == ' '):
                    
                    messagebox.showinfo('Caracter inválido', 'Por favor, digite apenas números')
            #FIM

            def dados():

                valor = float(e_valor.get())

                def checar():
                    
                    login = e_login.get()
                    senha = e_senha.get()

                    txt = '{}\\{}_LOGIN.txt'.format(user, user)

                    file = open(txt, 'r')
                    login2 = file.read()
                    file.close()

                    txt = '{}\\{}_SENHA.txt'.format(user, user)

                    file = open(txt, 'r')
                    senha2 = file.read()
                    file.close()

                    if (login != login2) and (senha != senha2):

                        messagebox.showinfo('Login ou Senha Inválidos', 'Login ou Senha Inválidos!')

                        top2.destroy()
                        top1.destroy()
                        transacao_func()

                    else:

                        saldo_F = ''
                            
                        txt = '{}\\{}_SALDO.txt'.format(user, user)

                        file = open(txt, 'r')
                        saldo = file.read()
                        file.close

                        for letra in saldo:
                            if letra == ',' or letra == '.':
                                letra = '.'
                                saldo_F = saldo_F + letra
                            else:
                                saldo_F = saldo_F + letra

                        saldo = float(saldo_F)
                        

                        # INCREMENTO SALDO USER

                        txt = '{}\\{}_SALDO.txt'.format(user, user)

                        file = open(txt, 'w')
                        file.write('{}'.format(saldo+valor))
                        file.close
        

                        txt = '{}\\{}_HISTORICO.txt'.format(user, user)

                        file = open(txt, 'a')
                        file.write('\nNo dia {}/{}/{} |{}| fez um depósito no valor de R${} através do caixa eletrônico'.format(dia, mes, ano, user.upper(), valor))
                        file.close()

                        messagebox.showinfo('Sucesso', 'Valor de R${} depositados com sucesso!'.format(valor))

                        top2.destroy()
                        top1.destroy()
                        top.destroy()
                        

                top2 = Toplevel()

                f1 = Frame(top2, width=200, height=200, bg='khaki')
                f1.pack()

                l_login = Label(f1, text='Login:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
                l_login.grid(row=0, column=0)

                e_login = Entry(f1, font=('arial', 18, 'bold'))
                e_login.grid(row=0, column=1)


                l_senha = Label(f1, text='Senha:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
                l_senha.grid(row=1, column=0)

                e_senha = Entry(f1, font=('arial', 18, 'bold'), show='*')
                e_senha.grid(row=1, column=1)


                b_enviar = Button(f1, text='ENVIAR', font=('arial', 15, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', command=checar)
                b_enviar.grid(row=2, columnspan=2)

                top2.iconbitmap('icone.ico')
                top2.title('AUTENTICAÇÃO - BANCO 99')
                top2.resizable(width=False, height=False)
                top2.mainloop()

            top1 = Toplevel()

            # PERGUNTA - INÍCIO
            f1 = Frame(top1, width=600, height=70, bg='goldenrod')
            f1.pack(side=TOP)

            l1 = Label(f1, text='DEPÓSITO BANCÁRIO', font=('arial', 18, 'bold'), bg='goldenrod', fg='white')
            l1.place(x=20, y=15)

            logo = ImageTk.PhotoImage(Image.open('logo2.png'))

            l2 = Label(f1, image=logo, bg='goldenrod')
            l2.place(x=315, y=7)
            # FIM

            # FRAME BOTÕES - INÍCIO
            f2 = Frame(top1, width=600, height=330, bg='khaki')
            f2.pack(side=BOTTOM)
            #FIM

            # LABEL VALOR - INÍCIO
            l_valor = Label(f2, text='VALOR EM R$:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
            l_valor.place(x=20, y=20)

            e_valor = Entry(f2, width=13, font=('arial', 18, 'bold'))
            e_valor.bind('<Key>', key)
            e_valor.place(x=210, y=20)
            # FIM

            #BOTÃO ENVIAR - INÍCIO
            b_enviar = Button(f2, fg='white', bg='dark khaki', font=('arial', 15, 'bold'), text='ENVIAR',
                              activebackground='DarkOliveGreen3', activeforeground='white', command=dados)
            b_enviar.place(x=160, y=70)
            # FIM

            # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
            top1.iconbitmap('deposito.ico')
            top1.title('DEPÓSITO - BANCO 99')
            top1.geometry('400x200+200+100')
            top1.resizable(width=False, height=False)
            top1.mainloop()
            # FIM

        # FIM FUNÇÃO PERGUNTAS DE SEGURANÇA

        # =========== FUNÇÃO DUAS ETAPAS ============== - INÍCIO
        
        def saque_func():

            #EVENTOS - INÍCIO
            def key(event):
                letra = event.char
                letra = letra.upper()

                if (letra == 'A') or (letra == 'B') or (letra == 'C') or (letra == 'D') or (letra == 'E') or (letra == 'F') or (letra == 'G') or (letra == 'H')\
                    or (letra == 'J') or (letra == 'K') or (letra == 'L') or (letra == 'M') or (letra == 'N') or (letra == 'O') or (letra == 'P') or (letra == 'Q')\
                    or (letra == 'S') or (letra == 'T') or (letra == 'U') or (letra == 'V') or (letra == 'W') or (letra == 'X') or (letra == 'Y') or (letra == 'Z')\
                    or (letra == '!') or (letra == '@') or (letra == '#') or (letra == '$') or (letra == '%') or (letra == '¨') or (letra == '&') or (letra == '&')\
                    or (letra == '*') or (letra == '(') or (letra == ')') or (letra == '_') or (letra == '+') or (letra == '§') or (letra == '=')\
                    or (letra == '´') or (letra == '`') or (letra == '{') or (letra == '[') or (letra == 'ª') or (letra == '^') or (letra == '~') or (letra == '}')\
                    or (letra == ']') or (letra == 'º') or (letra == '<') or (letra == ',') or (letra == '>') or (letra == '.') or (letra == ':') or (letra == ';')\
                    or (letra == '/') or (letra == '?') or (letra == '°') or (letra == '|') or (letra == 'R') or (letra == 'I') or (letra == ' '):
                    
                    messagebox.showinfo('Caracter inválido', 'Por favor, digite apenas números')
            #FIM
                
            def dados():

                valor = float(e_valor.get())

                def checar():
                    
                    login = e_login.get()
                    senha = e_senha.get()

                    txt = '{}\\{}_LOGIN.txt'.format(user, user)

                    file = open(txt, 'r')
                    login2 = file.read()
                    file.close()

                    txt = '{}\\{}_SENHA.txt'.format(user, user)

                    file = open(txt, 'r')
                    senha2 = file.read()
                    file.close()

                    if (login != login2) and (senha != senha2):

                        messagebox.showinfo('Login ou Senha Inválidos', 'Login ou Senha Inválidos!')

                        top2.destroy()
                        top1.destroy()
                        transacao_func()

                    else:

                        saldo_F = ''
                            
                        txt = '{}\\{}_SALDO.txt'.format(user, user)

                        file = open(txt, 'r')
                        saldo = file.read()
                        file.close

                        for letra in saldo:
                            if letra == ',' or letra == '.':
                                letra = '.'
                                saldo_F = saldo_F + letra
                            else:
                                saldo_F = saldo_F + letra

                        saldo = float(saldo_F)

                        if (saldo > valor) and (saldo > 0):

                            # DECREMENTO SALDO USER

                            txt = '{}\\{}_SALDO.txt'.format(user, user)

                            file = open(txt, 'w')
                            file.write('{}'.format(saldo-valor))
                            file.close
            

                            txt = '{}\\{}_HISTORICO.txt'.format(user, user)

                            file = open(txt, 'a')
                            file.write('\nNo dia {}/{}/{} |{}| fez um saque no valor de R${} através do caixa eletrônico'.format(dia, mes, ano, user.upper(), valor))
                            file.close()

                            messagebox.showinfo('Sucesso', 'Valor de R${} sacados com sucesso!'.format(valor))

                            top2.destroy()
                            top1.destroy()
                            top.destroy()
                        

                top2 = Toplevel()

                f1 = Frame(top2, width=200, height=200, bg='khaki')
                f1.pack()

                l_login = Label(f1, text='Login:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
                l_login.grid(row=0, column=0)

                e_login = Entry(f1, font=('arial', 18, 'bold'))
                e_login.grid(row=0, column=1)


                l_senha = Label(f1, text='Senha:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
                l_senha.grid(row=1, column=0)

                e_senha = Entry(f1, font=('arial', 18, 'bold'), show='*')
                e_senha.grid(row=1, column=1)


                b_enviar = Button(f1, text='ENVIAR', font=('arial', 15, 'bold'), bg='dark khaki', fg='white',
                                      activebackground='DarkOliveGreen3', activeforeground='white', command=checar)
                b_enviar.grid(row=2, columnspan=2)

                top2.iconbitmap('icone.ico')
                top2.title('AUTENTICAÇÃO - BANCO 99')
                top2.resizable(width=False, height=False)
                top2.mainloop()

            top1 = Toplevel()

            # PERGUNTA - INÍCIO
            f1 = Frame(top1, width=600, height=70, bg='goldenrod')
            f1.pack(side=TOP)

            l1 = Label(f1, text='SAQUE BANCÁRIO', font=('arial', 18, 'bold'), bg='goldenrod', fg='white')
            l1.place(x=20, y=15)

            logo = ImageTk.PhotoImage(Image.open('logo2.png'))

            l2 = Label(f1, image=logo, bg='goldenrod')
            l2.place(x=315, y=7)
            # FIM

            # FRAME BOTÕES - INÍCIO
            f2 = Frame(top1, width=600, height=330, bg='khaki')
            f2.pack(side=BOTTOM)
            #FIM

            # LABEL VALOR - INÍCIO
            l_valor = Label(f2, text='VALOR EM R$:', font=('arial', 18, 'bold'), bg='dark khaki', fg='white')
            l_valor.place(x=20, y=20)

            e_valor = Entry(f2, width=13, font=('arial', 18, 'bold'))
            e_valor.bind('<Key>', key)
            e_valor.place(x=210, y=20)
            # FIM

            #BOTÃO ENVIAR - INÍCIO
            b_enviar = Button(f2, fg='white', bg='dark khaki', font=('arial', 15, 'bold'), text='ENVIAR',
                              activebackground='DarkOliveGreen3', activeforeground='white', command=dados)
            b_enviar.place(x=160, y=70)
            # FIM

            # CONFIGURAÇÕES JANELA SECUNDÁRIA02 - INÍCIO
            top1.iconbitmap('saque.ico')
            top1.title('SAQUE - BANCO 99')
            top1.geometry('400x200+200+100')
            top1.resizable(width=False, height=False)
            top1.mainloop()
            # FIM
                

        # FIM FUNÇÃO DUAS ETAPAS
            
        top = Toplevel()

        # PERGUNTA - INÍCIO
        f1 = Frame(top, width=600, height=70, bg='goldenrod')
        f1.pack(side=TOP)

        l1 = Label(f1, text='O QUE VOCÊ DESEJA\nFAZER PRIMEIRO?', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
        l1.place(x=20, y=10)

        logo = ImageTk.PhotoImage(Image.open('logo2.png'))

        l2 = Label(f1, image=logo, bg='goldenrod')
        l2.place(x=315, y=7)
        # FIM

        # FRAME BOTÕES - INÍCIO
        f2 = Frame(top, width=600, height=330, bg='khaki')
        f2.pack(side=BOTTOM)
        #FIM
        
        # BOTÃO PAGAR BOLETO - INÍCIO
        boleto = PhotoImage(file = 'cifrao.png')
        boleto_imagem = boleto.subsample(3, 3)
        
        b_boleto = Button(f2, width=290, text=' PAGAR BOLETO', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                             activebackground='DarkOliveGreen3', activeforeground='white', image=boleto_imagem, compound=LEFT, command=boleto_func)
        b_boleto.place(x=40, y=30)
        # FIM

        # BOTÃO TRANSAÇÃO - INÍCIO
        transacao = PhotoImage(file = 'transferencia.png')
        transacao_imagem = transacao.subsample(3, 3)
        
        b_transacao = Button(f2, width=240, text=' TRANSAÇÃO', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                          activebackground='DarkOliveGreen3', activeforeground='white', image=transacao_imagem, compound=LEFT, command=transacao_func)
        b_transacao.place(x=40, y=100)
        # FIM

        # BOTÃO DEPÓSITO - INÍCIO
        deposito = PhotoImage(file = 'deposito.png')
        deposito_imagem = deposito.subsample(3, 3)
        
        b_deposito = Button(f2, width=210, text=' DEPÓSITO', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                           activebackground='DarkOliveGreen3', activeforeground='white', image=deposito_imagem, compound=LEFT, command=deposito_func)
        b_deposito.place(x=40, y=170)
        # FIM

        # BOTÃO SAQUE - INÍCIO
        saque = PhotoImage(file = 'saque.png')
        saque_imagem = saque.subsample(3, 3)
        
        b_saque = Button(f2, width=160, text=' SAQUE', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                           activebackground='DarkOliveGreen3', activeforeground='white', image=saque_imagem, compound=LEFT, command=saque_func)
        b_saque.place(x=40, y=240)
        # FIM   
        
        # CONFIGURAÇÕES JANELA SECUNDÁRIA01 - INÍCIO
        top.iconbitmap('seta_girando.ico')
        top.title('TRANSAÇÕES - BANCO 99')
        top.geometry('400x400+200+100')
        top.resizable(width=False, height=False)
        top.mainloop()
        # FIM











    # FUNÇÃO RESPONSÁVEL PELO SUPORTE AO CLIENTE

    def suporte_func():

        def enviar_email():

            def email():
                # CRIANDO ARQUIVO PARA O PROGRAMA EM C IDENTIFICAR A NECESSIDADE DE SUPORTE
                txt = user + '\\' + user + '_EMAIL SUPORTE.txt'
                user_string = open(txt,'w')
                user_string.close()

                messagebox.showinfo('Sucesso', 'Sucesso. Acesse o Banco 99 pelo APP. Na seção CONTA, aparecerá a nova opção ENVIAR EMAIL,\
                                    acesse essa opção para enviar um email personalizado para o Suporte')

                top.destroy()
                top1.destroy()

            def auto_email():
                # CRIANDO ARQUIVO COM NOME DO USER
                user_string = open('1.txt','w')
                user_string.write('{}'.format(user.upper()))
                user_string.close()

                comando = 'enviar_email_suporte_caixa.py'
                os.system(comando)
                os.remove('1.txt')

                messagebox.showinfo('Sucesso', 'Email enviado com sucesso para o Suporte')

                top.destroy()
                top1.destroy()
            
            top1 = Toplevel()

            # FRAME INICIAL - INÍCIO
            f1 = Frame(top1, width=600, height=70, bg='goldenrod')
            f1.pack(side=TOP)

            l1 = Label(f1, text='COMO VOCÊ DESEJAR\nFALAR CONOSCO?', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
            l1.place(x=15, y=10)

            logo = ImageTk.PhotoImage(Image.open('logo2.png'))

            l2 = Label(f1, image=logo, bg='goldenrod')
            l2.place(x=320, y=7)
            #FIM

            # FRAME BOTÕES - INÍCIO
            f2 = Frame(top1, width=400, height=330, bg='khaki')
            f2.pack(side=BOTTOM)
            # FIM
            
            # BOTÃO EMAIL AUTOMÁTICO - INÍCIO
            b_auto = Button(f2, text='EMAIL AUTOMÁTICO', font=('arial', 18, 'bold'), bg='dark khaki', fg='white',
                            activebackground='dark khaki', activeforeground='white', command=auto_email)
            b_auto.place(x=65, y=20)

            b_auto = Button(f2, text='ESCREVER UM EMAIL', font=('arial', 18, 'bold'), bg='dark khaki', fg='white',
                            activebackground='dark khaki', activeforeground='white', command=email)
            b_auto.place(x=60, y=100)
            # FIM
            
            # CONFIGURAÇÕES JANELA TOP02 - INÍCIO
            top1.iconbitmap('email.ico')
            top1.title('CONFIGURAÇÕES - BANCO 99')
            top1.geometry('400x250+200+100')
            top1.resizable(width=False, height=False)
            top1.mainloop()
            # FIM

        def voltar():
            print('entrou voltar')
            top.destroy()
            janela.update()
            janela.deiconify()
        
        top = Toplevel()

        # PERGUNTA - INÍCIO
        f1 = Frame(top, width=600, height=70, bg='goldenrod')
        f1.pack(side=TOP)

        l1 = Label(f1, text='COMO VOCÊ DESEJAR\nFALAR CONOSCO?', font=('arial', 15, 'bold'), bg='goldenrod', fg='white')
        l1.place(x=15, y=10)

        logo = ImageTk.PhotoImage(Image.open('logo2.png'))

        l2 = Label(f1, image=logo, bg='goldenrod')
        l2.place(x=300, y=7)
        # FIM

        # FRAME BOTÕES - INÍCIO
        f2 = Frame(top, width=400, height=230, bg='khaki')
        f2.pack(side=BOTTOM)
        # FIM

        # BOTÃO EMAIL - INÍCIO
        email = PhotoImage(file = 'email.png')
        email_imagem = email.subsample(3, 3)
        
        b_email = Button(f2, font=('aria', 20, 'bold'), bg='khaki', fg='white',
                          activebackground='dark khaki', activeforeground='white', image=email_imagem, command=enviar_email)
        b_email.place(x=140, y=35)
        # FIM

        # CONFIGURAÇÕES JANELA SECUNDÁRIA01 - INÍCIO
        top.iconbitmap('suporte.ico')
        top.title('SUPORTE - BANCO 99')
        top.geometry('400x200+200+100')
        top.resizable(width=False, height=False)
        top.mainloop()
        # FIM



        
    




    

    def atualizar_func():
        janela.destroy()
        
        teste = Principal(user, conta)

    def sair_func():
        messagebox.showinfo('Obrigado', 'Obrigado por usar o Caixa Eletrônico do Banco 99! Volte sempre que precisar.')
    
        janela.destroy()

    # FUNCIONALIDADES SECUNDÁRIAS - INÍCIO
    
    nome = user.split(' ')

    txt = user + '\\' + user + '_SALDO.txt'
    saldo_string = open(txt, 'r')
    saldo = saldo_string.read()
    saldo_string.close()

    #saldo_string = '{}0'.format(saldo)
    #saldo = float(saldo_string)
    # FIM
    
    janela = Tk()

    # RECEPÇÃO - INÍCIO
    f1 = Frame(janela, width=600, height=70, bg='goldenrod')
    f1.pack(side=TOP)

    l1 = Label(f1, text='BEM VINDO: {}'.format(nome[0].upper()), font=('arial', 20, 'bold'), bg='goldenrod', fg='white')
    l1.place(x=30, y=18)

    logo = ImageTk.PhotoImage(Image.open('logo2.png'))

    l2 = Label(f1, image=logo, bg='goldenrod')
    l2.place(x=500, y=7)
    # FIM

    # FRAME BOTÕES - INÍCIO
    f2 = Frame(janela, width=600, height=330, bg='khaki')
    f2.pack(side=BOTTOM)
    #FIM

    # BOTÃO FUNCIONALIDADES - INÍCIO
    config = PhotoImage(file = 'config.png')
    config_imagem = config.subsample(3, 3)
    
    b_config = Button(f2, width=300, text=' CONFIGURAÇÕES', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                      activebackground='DarkOliveGreen3', activeforeground='white', image=config_imagem, compound=LEFT, command=config_func)
    b_config.place(x=30, y=30)
    # FIM
    
    # BOTÃO TRANSAÇÕES - INÍCIO
    transacao = PhotoImage(file = 'seta_girando.png')
    transacao_imagem = transacao.subsample(3, 3)
    
    b_transacao = Button(f2, width=250, text=' TRANSAÇÕES', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                         activebackground='DarkOliveGreen3', activeforeground='white', image=transacao_imagem, compound=LEFT, command=transacao_func)
    b_transacao.place(x=30, y=110)
    # FIM

    # BOTÃO SUPORTE - INÍCIO
    suporte = PhotoImage(file = 'suporte.png')
    suporte_imagem = suporte.subsample(3, 3)
    
    b_suporte = Button(f2, width=200, text=' SUPORTE', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                       activebackground='DarkOliveGreen3', activeforeground='white', image=suporte_imagem, compound=LEFT, command=suporte_func)
    b_suporte.place(x=30, y=190)
    # FIM

    # BOTÃO SAIR - INÍCIO
    atualizar = PhotoImage(file = 'seta_atualizar.png')
    atualizar_imagem = atualizar.subsample(3, 3)
    
    b_atualizar = Button(f2, width=220, text=' ATUALIZAR', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                       activebackground='DarkOliveGreen3', activeforeground='white', image=atualizar_imagem, compound=LEFT, command=atualizar_func)
    b_atualizar.place(x=350, y=30)
    # FIM
    
    # BOTÃO SAIR - INÍCIO
    sair = PhotoImage(file = 'sair.png')
    sair_imagem = sair.subsample(3, 3)
    
    b_sair = Button(f2, width=130, text=' SAIR', font=('aria', 20, 'bold'), bg='dark khaki', fg='white',
                       activebackground='DarkOliveGreen3', activeforeground='white', image=sair_imagem, compound=LEFT, command=sair_func)
    b_sair.place(x=400, y=110)
    # FIM

    # LABEL SALDO - INÍCIO
    l_saldo = Label(f2, text='SALDO: R${}'.format(saldo), font=('arial', 20, 'bold'), bg='khaki', fg='dark goldenrod')
    l_saldo.place(x=285, y=202)
    # FIM

    # CONFIGURAÇÕES JANELA RAIZ - INÍCIO    
    janela.iconbitmap('icone.ico')
    janela.title('CAIXA ELETRÔNICO - BANCO 99')
    janela.geometry('600x350+400+150')
    janela.resizable(width=False, height=False)
    janela.mainloop()
    # FIM


class Principal:

    def __init__(self, user, conta):
        self.user = user
        self.conta = conta

        main(self.user, self.conta)

#main(user, conta)
