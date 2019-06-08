from tkinter import *
from tkinter import messagebox
from datetime import datetime
import os

# VARIÁVEIS
global contc, saldo, fatura, limite, var_valor, agora, nome, idade, cpf, login, senha,\
    var_teste_login, var_teste_senha
contc = 0 # RESPONSÁVEL POR DIZER QUANDO O CADASTRO TERMINA
saldo = 0 # RESPONSÁVEL POR INFORMAR O SALDO DO CLIENTE
fatura = 0 # RESPONSÁVEL POR INFORMAR A FATURA DO CLIENTE
limite = 1000 # RESPONSÁVEL POR INFORMAR O LIMITE DO CLIENTE
var_valor = 0 # RESPONSÁVEL POR RECEBER A VARIÁVEL SALDO E TRANSFORMA-LA EM INT/STRING QUANDO NECESSÁRIO
agora = datetime.now() # RESPONSÁVEL POR INFORMAR O DIA/MÊS/ANO ATUAIS


def backspace(string): # função para apagar o ultimo caracter da string
    
    palavra = string # palavra irá receber a string informada pelo usuário para não haver alteração da string original
    numero = len(palavra) # numero vai ler a quantidade de caracteres da string para dps usar esse número no loop, numero sera o contador
    letra = '' # limpa string letra
    
    for i in palavra:

        numero -= 1 # numero diminui -1  a cada loop


        if numero > 0: # quando loop == 0, loop se encerra
            letra += i # irá receber letra por letra da string com excessão da ultima

        else:
            palavra = letra # palavra vai receber a string final sem o ultimo caracter
    
    return palavra # retorna string sem o ultimo caracter


def logado():

    arq = open('dados.txt', 'r')
    text = arq.readlines()
    palavra = text[0]
    palavra = palavra.split('-')
    arq.close()

    nome = palavra[0]
    idade = palavra[1]
    cpf = palavra[2]
    login = palavra[3]
    senha = palavra[4]

    # destroi janela de validação de dados
    janela.destroy()

    if (os.path.isfile('dados.txt') == True): # se existir o arquivo dados.txt -> foi realizado o cadastro do usuário

        # =======================
        # FUNÇÕES NÃO PRINCIPAIS
        # =======================

        # INÍCIO

        # INÍCIO ATUALIZAR2
        def atualizar2():

            arq = open('dados.txt', 'r')
            text = arq.readlines()
            palavra = text[0]
            palavra = palavra.split('-')
            arq.close()

            nome = palavra[0]

            arq = open('dados_financeiro.txt', 'r')
            text = arq.readlines()
            palavra = text[0]
            palavra = palavra.split('-')
            arq.close()

            saldo = palavra[0]

            # depois as labels sao criadas novamente, porem com os novos valores
            labelUSUARIO = Label(tela, text='Usuário: {}'.format(nome.title()), font=('Arial', 12), bg='gray',
                                 fg='white')
            labelSALDO = Label(tela, text='Saldo: R${}  '.format(saldo), font=('Arial', 12), bg='gray', fg='white')

            labelUSUARIO.place(x=25, y=30)
            labelSALDO.place(x=450, y=30)
            # FIM ATUALIZAR2


        # INÍCIO SAIR
        def sair():
            tela.destroy()
            # FIM SAIR

        # FIM FUNÇÕES NÃO PRINCIPAIS



        # ================
        # BOTÃO DEPOSITAR
        # ================

        # INÍCIO
        def depositar():

            global saldo, word

            # lê o arquivo responsavel por armazenar o valor do boleto
            try:
                arq = open('dados_boleto.txt', 'r')
                text = arq.readlines()
                palavra = text[0]
                palavra = palavra.split('-')
                arq.close()

            except:
                arq = open('dados_boleto.txt', 'w')
                arq.write('0-0')
                arq.close()

                arq = open('dados_boleto.txt', 'r')
                text = arq.readlines()
                palavra = text[0]
                palavra = palavra.split('-')
                arq.close()

            saldo = int(palavra[0])
            word = int(palavra[1])

            # FUNÇÃO VOLTAR
            def voltar():
                top4.destroy()

            # FUNÇÃO PARA DEPOSITAR VIA CHEQUE
            def cheque():
                messagebox.showinfo('Erro', 'Disponível a partir da v3.0')



            # FUNÇÃO PARA PAGAR BOLETO
            def ver_boleto():

                arq = open('dados_boleto.txt', 'r')
                text = arq.readlines()
                palavra = text[0]
                palavra = palavra.split('-')
                arq.close()

                saldo = int(palavra[0])
                word = int(palavra[1])

                if word == 1:  # verifica se o documento q existe é o 0/1

                    global var_valor

                    def pergunta():

                        def destroy():

                            def destruir():
                                top4.destroy()

                            global saldo, limite, fatura

                            print(var_valor)

                            arq = open('dados_financeiro.txt', 'w')
                            arq.write('{}-{}-{}'.format(saldo, limite, fatura))
                            arq.close()

                            messagebox.showinfo('Sucesso',
                                                'Boleto pago com sucesso! Valor de R${} adicionados a sua conta'.format(
                                                    var_valor))

                            destruir()

                        pergunta = messagebox.askquestion('Pagar boleto?', 'Deseja pagar seu boleto agora?')

                        if pergunta == 'yes':

                            global saldo

                            # le o valor do boleto armazenado
                            arq = open('dados_boleto.txt', 'r')
                            text = arq.readlines()
                            palavra = text[0]
                            palavra = palavra.split('-')
                            arq.close()

                            var_valor = int(palavra[0]) # variavel responsavel por receber o valor do boleto



                            arq = open('dados_financeiro.txt', 'r')
                            text = arq.readlines()
                            palavra = text[0]
                            palavra = palavra.split('-')
                            arq.close()

                            saldo = int(palavra[0])
                            limite = int(palavra[1])
                            fatura = int(palavra[2])

                            # transforma saldo(str) em saldo(int)
                            saldofake = int(saldo)
                            saldo = saldofake

                            # transforma var_valor(int) para var_valor(str) -> necessario ser str para ser escrito no .txt
                            fakevar = str(var_valor)
                            var_valor = fakevar

                            # armazena no historico o pagamento
                            arq = open('historico.txt', 'a')
                            arq.write('\nNo dia {}/{}/{} foi feito o PAGAMENTO de um boleto no valor de R${}\n'.format(
                                agora.day, agora.month, agora.year, var_valor))
                            arq.close()

                            saldo += int(var_valor)

                            # escreve o novo valor do saldo
                            arq = open('dados_boleto.txt', 'w')
                            arq.write('{}-0'.format(var_valor)) # 1 = BOLETO PENDENTE/ 0 = BOLETO PAGO
                            arq.close()

                            arq = open('dados_financeiro.txt', 'w')
                            arq.write('{}-{}-{}'.format(saldo, limite, fatura))
                            arq.close()

                            destroy()

                        else:
                            top41.destroy()


                    top41 = Toplevel(top4)

                    # ===================================================================
                    # ============= BOLETO =============
                    # IMAGEM
                    imagem = PhotoImage(file='boleto 4.png')

                    # FRAME
                    frameCOSTA = Frame(top41, width=500, height=300, bg='gray')

                    # LABELS
                    labelBOLETO_IMAGEM = Label(top41, image=imagem)
                    labelBOLETO_IMAGEM.image = imagem

                    # BUTTONS
                    buttonBACK = Button(top41, text='<- VOLTAR', font=('Arial', 8, 'bold'), bg='firebrick1',
                                        fg='white',
                                        command=pergunta)
                    # ===================================================================


                    # ATRIBUIÇÃO
                    labelBOLETO_IMAGEM.pack()
                    buttonBACK.place(x=200, y=620)
                    frameCOSTA.place(x=0, y=400)


                    # CONFIGURAÇÕES TOP41
                    top41.iconbitmap('bank-73-94206.ico')
                    top41.geometry('500x650+400+50')
                    top41.title('Boleto')
                    top41.mainloop()

                elif word == 0:
                    messagebox.showinfo('Erro', 'Você ainda não criou nenhum boleto')

                elif not os.path.isfile('dados_boleto.txt') == True:

                    arq = open('dados_boleto.txt', 'w')
                    arq.write('{}-0'.format(var_valor))
                    arq.close()

                    messagebox.showerror('Erro', 'Dados do boleto corrompidos! Por favor, faça outro boleto')

                    ver_boleto()



            # FUNÇÃO PARA CRIAR BOLETO
            def boleto():

                arq = open('dados_boleto.txt', 'r')
                text = arq.readlines()
                palavra = text[0]
                palavra = palavra.split('-')
                arq.close()

                saldo = int(palavra[0])
                word = int(palavra[1])

                if word == 0:  # verifica se o documento q existe é o 0/1
                    def voltar():
                        top4.destroy()

                    def success():

                        if str(entryVALOR.get()) != '':

                            def destroy():
                                def destruir():
                                    top4.destroy()


                                arq = open('historico.txt', 'a')
                                arq.write('\nNo dia {}/{}/{} foi feito o pedido de um boleto no valor de R${}, que vence no ' \
                                        'dia {}/{}/{}\n'.format(agora.day, agora.month, agora.year, var_valor,
                                                                   agora.day + 2, agora.month, agora.year))
                                arq.close()

                                arq = open('dados_boleto.txt', 'w')
                                arq.write('{}-1'.format(var_valor)) #1 = BOLETO PENDENTE/ 0 = BOLETO PAGO
                                arq.close()

                                messagebox.showinfo('Sucesso', 'Boleto no valor de R${} criado com sucesso. '
                                                               'Pague até o dia {}/{}/{} em qualquer agência lotérica. '
                                                               'Pagamentos depois da data prevista somente nas agências '
                                                               'bancárias do Banco 99'.format(var_valor, agora.day + 2,
                                                                                              agora.month, agora.year))

                                destruir()

                            var_valor = entryVALOR.get()

                            top41 = Toplevel(top42)

                            # =================================================================
                            # =========== BOLETO ============
                            # IMAGEM
                            imagem = PhotoImage(file='boleto 4.png')

                            # FRAME
                            frameCOSTA = Frame(top41, width=500, height=300, bg='gray')

                            # LABELS
                            labelBOLETO_IMAGEM = Label(top41, image=imagem)
                            labelBOLETO_IMAGEM.image = imagem
                            # ===============================================================

                            # BUTTONS
                            buttonBACK = Button(top41, text='<- VOLTAR', font=('Arial', 8, 'bold'), bg='firebrick1',
                                                fg='white',
                                                command=destroy)

                            # ATRIBUIÇÃO
                            labelBOLETO_IMAGEM.pack()
                            buttonBACK.place(x=200, y=620)
                            frameCOSTA.place(x=0, y=400)

                            # CONFIGURAÇÃO TOP41
                            top41.iconbitmap('bank-73-94206.ico')
                            top41.geometry('500x650+400+50')
                            top41.title('Boleto')
                            top41.mainloop()

                        else:
                            messagebox.showwarning('Erro', 'Impossível criar boleto com esse valor!')

                            top4.destroy()

                    top42 = Toplevel(top4)

                    # FRAMES
                    frameFUNDO = Frame(top42, width=210, height=150, bg='gray')

                    # LABELS
                    labelINFORME = Label(frameFUNDO, text='INFORME', font=('Arial', 12, 'bold'), bg='gray', fg='white')
                    labelVALOR = Label(frameFUNDO, text='Valor R$', font=('Arial', 10), bg='gray', fg='white')

                    # ENTRY
                    entryVALOR = Entry(frameFUNDO)

                    # BUTTONS
                    buttonENVIAR = Button(frameFUNDO, text='ENVIAR', bg='firebrick1', fg='white', command=success)
                    buttonVOLTAR = Button(frameFUNDO, text='<- VOLTAR', bg='firebrick1', fg='white', command=voltar)

                    # ATRIBUIÇÃO
                    frameFUNDO.place(x=0, y=0)
                    labelINFORME.place(x=65, y=10)
                    labelVALOR.place(x=10, y=60)
                    entryVALOR.place(x=70, y=60)
                    buttonENVIAR.place(x=10, y=110)
                    buttonVOLTAR.place(x=120, y=110)

                    # CONFIGURAÇÕES TOP42
                    top42.iconbitmap('bank-73-94206.ico')
                    top42.geometry('210x150+400+200')
                    top42.title('Informações Boleto')
                    top42.mainloop()

                elif word == 1:
                    messagebox.showwarning('Erro', 'Primeiro pague o boleto anterior!')

                elif not os.path.isfile('dados_boleto.txt') == True:

                    arq = open('dados_boleto.txt', 'w')
                    arq.write('{}-0'.format(var_valor))
                    arq.close()

                    messagebox.showerror('Erro', 'Dados do boleto corrompidos! Por favor, faça outro boleto')

                    boleto()

            top4 = Toplevel(tela)

            # FRAMES
            frameBACKGROUND = Frame(top4, width=300, height=300, bg='gray')

            # LABELS
            labelDEPOSITAR_LOGO = Label(top4, text='MODO DE DEPÓSITO', font=('Arial', 14, 'bold'),
                                        bg='grey', fg='white')

            labelBOLETO = Label(top4, text='Boleto', font=('Arial', 12, 'bold'), bg='grey', fg='white')
            labelCHEQUE = Label(top4, text='Cheque', font=('Arial', 12, 'bold'), bg='grey', fg='white')
            labelBOLETO_VER = Label(top4, text='Ver Boleto', font=('Arial', 12, 'bold'), bg='grey', fg='white')

            # BUTTONS
            buttonBOLETO = Button(top4, text='SELECIONAR', font=('Arial', 10, 'bold'), bg='firebrick1', fg='white',
                                  command=boleto)
            buttonCHEQUE = Button(top4, text='SELECIONAR', font=('Arial', 10, 'bold'), bg='firebrick1', fg='white',
                                  command=cheque)
            buttonBOLETO_VER = Button(top4, text='SELECIONAR', font=('Arial', 10, 'bold'), bg='firebrick1', fg='white',
                                      command=ver_boleto)
            buttonVOLTAR = Button(top4, text='<- VOLTAR', font=('Arial', 10, 'bold'), bg='firebrick1', fg='white',
                                  command=voltar)

            # ATRIBUIÇÃO
            frameBACKGROUND.place(x=0, y=0)
            labelDEPOSITAR_LOGO.place(x=50, y=10)

            labelBOLETO.place(x=15, y=70)
            buttonBOLETO.place(x=190, y=70)

            labelCHEQUE.place(x=15, y=100)
            buttonCHEQUE.place(x=190, y=100)

            labelBOLETO_VER.place(x=15, y=130)
            buttonBOLETO_VER.place(x=190, y=130)

            buttonVOLTAR.place(x=100, y=180)

            top4.iconbitmap('bank-73-94206.ico')
            top4.geometry('300x230+300+200')
            top4.title('Depósito')
            top4.mainloop()
            # FIM BOTÃO DEPOSITAR


        # =============
        # BOTÃO CARTÃO
        # =============

        # INÍCIO
        def cartao():

            # FUNÇÃO VOLTAR
            def voltar():
                top1.destroy()



            # FUNÇÃO PARA VER O LIMITE
            def ver_limite():

                arq = open('dados_financeiro.txt', 'r')
                text = arq.readlines()
                palavra = text[0]
                palavra = palavra.split('-')
                arq.close()

                saldo = palavra[0]
                limite = palavra[1]
                fatura = palavra[2]

                # INÍCIO FUNÇÃO USAR

                def usar():
                    def success():

                        # finaliza a tela ver_limite
                        def destroy():
                            top1.destroy()

                        global saldo, limite, fatura

                        valorfake = int(entryVALOR.get()) # variavel que ira receber o valor utilizado do crédito

                        # transformando as variaveis limite(str) e fatura(str) em int
                        limitefake = limite
                        faturafake = fatura

                        limite = int(limitefake)
                        fatura = int(faturafake)

                        if valorfake <= 0:
                            messagebox.showwarning('Erro', 'Digite um valor maior que R$0,00')

                            destroy()

                        elif limite == 0:
                            messagebox.showerror('Erro', 'Você não possui crédito suficiente')

                            destroy()

                        elif valorfake > limite:
                            messagebox.showerror('Erro', 'Você não possui crédito suficiente')

                            destroy()

                        else:
                            fatura += valorfake
                            limite -= valorfake

                            arq = open('dados_financeiro.txt', 'w')
                            arq.write('{}-{}-{}'.format(saldo, limite, fatura))
                            arq.close()


                            # registrando o historico do uso do credito
                            arq = open('historico.txt', 'a')
                            text = '\nNo dia {}/{}/{} foi feito o uso de R${} de seu crédito\n'.format(
                                agora.day, agora.month, agora.year, limite)
                            arq.write(text)
                            arq.close()

                            arq = open('dados_financeiro.txt', 'r')
                            text = arq.readlines()
                            palavra = text[0]
                            palavra = palavra.split('-')
                            arq.close()


                            saldo = palavra[0]
                            limite = palavra[1]
                            fatura = palavra[2]

                            messagebox.showinfo('Sucesso',
                                                'Valor de R${} utilizados de seu crédito. '
                                                'Seu atual limite é R${}. '
                                                'Sua atual fatura é R${}'.format(valorfake, limite, fatura))

                            destroy()

                    top111 = Toplevel(top11)

                    # ENTRY
                    entryVALOR = Entry(top111)

                    # BUTTON
                    buttonENVIAR = Button(top111, text='ENVIAR', font=('Arial', 8, 'bold'), bg='firebrick1', fg='white',
                                          command=success)

                    # ATRIBUIÇÃO
                    entryVALOR.grid(row=0, column=0)
                    buttonENVIAR.grid(row=0, column=1)

                    # CONFIGURAÇÕES TOP111
                    top111.iconbitmap('bank-73-94206.ico')
                    top111.geometry('+560+200')
                    top111.title('Informar valor')
                    top111.mainloop()
                    # FIM FUNÇÃO USAR


                # FUNÇÕES VOLTAR/ATUALIZAR
                def voltar():
                    top11.destroy()

                def update():
                    top11.destroy()

                    ver_limite()



                top11 = Toplevel(top1)

                # FRAME
                frameBACKGROUND = Frame(top11, width=200, height=150, bg='gray')

                # LABELS
                labelLIMITE_LOGO = Label(frameBACKGROUND, text='LIMITE', font=('Arial', 14, 'bold'), bg='gray',
                                         fg='white')

                labelLIMITE_VER = Label(frameBACKGROUND, text='Limite: R${}'.format(limite), font=('Arial', 12),
                                        bg='gray', fg='white')

                # BUTTONS
                buttonUSAR = Button(frameBACKGROUND, text='USAR', font=('Arial', 8, 'bold'), bg='firebrick1',
                                    fg='white', command=usar)
                buttonVOLTAR = Button(frameBACKGROUND, text='<- VOLTAR', font=('Arial', 8, 'bold'), bg='firebrick1',
                                      fg='white', command=voltar)
                buttonUPDATE = Button(frameBACKGROUND, text='( ) Atualizar', font=('Arial', 8, 'bold'), bg='firebrick1',
                                      fg='white', command=update)


                # ATRIBUIÇÃO
                frameBACKGROUND.place(x=0, y=0)
                labelLIMITE_LOGO.place(x=50, y=10)
                labelLIMITE_VER.place(x=10, y=60)
                buttonUSAR.place(x=150, y=60)
                buttonVOLTAR.place(x=120, y=110)
                buttonUPDATE.place(x=10, y=110)


                # CONFIGURAÇÕES TOP11
                top11.iconbitmap('bank-73-94206.ico')
                top11.geometry('200x150+550+200')
                top11.mainloop()
                # FIM FUNÇÃO VER LIMITE

            def ver_fatura():

                arq = open('dados_financeiro.txt', 'r')
                text = arq.readlines()
                palavra = text[0]
                palavra = palavra.split('-')
                arq.close()

                saldo = palavra[0]
                limite = palavra[1]
                fatura = palavra[2]

                # FUNÇÕES VOLTAR/ATUALIZAR

                def update():
                    top12.destroy()

                    ver_fatura()

                def voltar():
                    top12.destroy()


                # FUNÇÃO PARA PAGAR A FATURA

                def pagar_fatura():

                    global saldo, limite, fatura, fakefatura

                    arq = open('dados_financeiro.txt', 'r')
                    text = arq.readlines()
                    palavra = text[0]
                    palavra = palavra.split('-')
                    arq.close()

                    saldo = int(palavra[0])
                    limite = int(palavra[1])
                    fatura = int(palavra[2])

                    fakefatura = fatura


                    # FUNÇÃO PARA ENCERRAR A JANELA QUANDO O PROCESSO FOR FINALIZADO
                    def success():
                        top1.destroy()

                    # verificações
                    if fatura == 0:
                        messagebox.showinfo('Sucesso', 'Você não possui fatura para pagar')

                        success()

                    elif fatura > saldo:
                        messagebox.showerror('Erro', 'Você não possui saldo suficiente para pagar sua fatura')
                        print(saldo)

                        success()

                    elif fatura > 0 and saldo > fatura:

                        limite = 1000
                        saldo -= fatura
                        fatura = 0

                        arq = open('dados_financeiro.txt', 'w')
                        texto = '{}-{}-{}'.format(saldo, limite, fatura)
                        arq.write(texto)
                        arq.close()

                        arq = open('historico.txt', 'a')
                        text = '\nNo dia {}/{}/{} foi feito o PAGAMENTO da fatura no valor de R${}\n'.format(
                            agora.day, agora.month, agora.year, fakefatura)
                        arq.write(text)
                        arq.close()

                        messagebox.showinfo('Sucesso',
                                            'Fatura de R${} paga com sucesso! Seu saldo atual é de R${}'.format(fakefatura,
                                                                                                                saldo))

                        success()

                top12 = Toplevel(top1)

                # FRAMES
                frameBACKGROUND = Frame(top12, width=250, height=150, bg='gray')

                # LABELS
                labelFATURA_LOGO = Label(frameBACKGROUND, text='FATURA', font=('Arial', 12, 'bold'), bg='gray',
                                         fg='white')
                labelFATURA_VER = Label(frameBACKGROUND, text='Fatura: R${}'.format(fatura), font=('Arial', 12),
                                        bg='gray', fg='white')

                # BUTTONS
                buttonPAGAR = Button(frameBACKGROUND, text='PAGAR FATURA', font=('Arial', 8, 'bold'),
                                     bg='firebrick1', fg='white', command=pagar_fatura)
                buttonUPDATE = Button(frameBACKGROUND, text='( ) Atualizar', font=('Arial', 8, 'bold'), bg='firebrick1',
                                      fg='white', command=update)
                buttonVOLTAR = Button(frameBACKGROUND, text='<- VOLTAR', font=('Arial', 8, 'bold'),
                                      bg='firebrick1', fg='white', command=voltar)

                # ATRIBUIÇÃO
                frameBACKGROUND.place(x=0, y=0)
                labelFATURA_LOGO.place(x=80, y=10)
                labelFATURA_VER.place(x=10, y=50)
                buttonPAGAR.place(x=140, y=50)
                buttonUPDATE.place(x=15, y=90)
                buttonVOLTAR.place(x=160, y=90)

                # CONFIGURAÇÕES TOP12
                top12.iconbitmap('bank-73-94206.ico')
                top12.geometry('250x130+550+200')
                top12.mainloop()

            top1 = Toplevel(tela)

            # FRAMES
            frameFUNDO = Frame(top1, width=200, height=200, bg='gray')

            # LABELS
            labelINFO = Label(frameFUNDO, text='INFO CARTÃO', font=('Arial', 14, 'bold'), bg='gray', fg='white')
            labelLIMITE = Label(frameFUNDO, text='Limite', font=('Arial', 12, 'bold'), bg='gray', fg='white')
            labelFATURA = Label(frameFUNDO, text='Fatura', font=('Arial', 12, 'bold'), bg='gray', fg='white')

            # BUTTONS
            buttonLIMITE = Button(frameFUNDO, text='VER', font=('Arial', 10, 'bold'), bg='firebrick1', fg='white',
                                  command=ver_limite)
            buttonFATURA = Button(frameFUNDO, text='VER', font=('Arial', 10, 'bold'), bg='firebrick1', fg='white',
                                  command=ver_fatura)
            buttonVOLTAR = Button(frameFUNDO, text='<- VOLTAR', font=('Arial', 10, 'bold'), bg='firebrick1', fg='white',
                                  command=voltar)

            # ATRIBUIÇÕES
            frameFUNDO.place(x=0, y=0)

            labelINFO.place(x=30, y=15)
            labelLIMITE.place(x=10, y=60)
            buttonLIMITE.place(x=150, y=60)

            labelFATURA.place(x=10, y=90)
            buttonFATURA.place(x=150, y=90)

            buttonVOLTAR.place(x=65, y=140)

            top1.iconbitmap('bank-73-94206.ico')
            top1.title('DADOS CARTÃO')
            top1.geometry('200x180+350+200')
            top1.mainloop()
            # FIM BOTÃO CARTÃO

        # ============
        # BOTÃO DADOS
        # ============

        # INÍCIO
        def dados():

            # =================
            # FUNÇÕES BÁSICAS
            # =================

            # FUNÇÃO ATUALIZA DADOS
            def atualizar():
                top.destroy()

                dados()
                # FIM FUNÇÃO ATUALIZA DADOS

            # FUNÇÃO VOLTAR
            def voltar():
                top.destroy()
                # FIM FUNÇÃO VOLTAR


            # ====================
            # FUNÇÕES MAIS SIMPLES
            # ====================

            # FUNÇÃO ALTERAR CPF
            def alterar_cpf():
                def confirmar():

                    cpfentry = str(entryCPF.get())

                    arq = open('dados.txt', 'w')
                    arq.write('{}-{}-{}-{}-{}'.format(nome, idade, cpfentry, login, senha))
                    arq.close()

                    arq = open('historico.txt', 'a')
                    arq.write(
                        '\nNo dia {}/{}/{} foi alterado o CPF de {} para {}\n'.format(agora.day, agora.month, agora.year,
                                                                                    nome, cpfentry))
                    arq.close()

                    top1.destroy()

                top1 = Toplevel(top)

                # ENTRY
                entryCPF = Entry(top1)

                # BUTTON
                buttonENVIAR = Button(top1, font=('Arial', 10, 'bold'), text='ENVIAR', bg='firebrick1',
                                      fg='white',
                                      command=confirmar)

                # ATRIBUIÇÃO
                buttonENVIAR.grid(row=0, column=1)
                entryCPF.grid(row=0, column=0)


                # CONFIGURAÇÕES DA JANELA
                top1.iconbitmap('bank-73-94206.ico')
                top1.geometry('+300+200')
                top1.title('ALTERAR CPF')
                top1.mainloop()
                # FIM FUNÇÃO ALTERAR CPF

            # FUNÇÃO ALTERAR IDADE
            def alterar_idade():
                def confirmar():
                    idadeentry = str(entryIDADE.get())

                    arq = open('dados.txt', 'w')
                    arq.write('{}-{}-{}-{}-{}'.format(nome, idadeentry, cpf, login, senha))
                    arq.close()

                    arq = open('historico.txt', 'a')
                    arq.write(
                        '\nNo dia {}/{}/{} foi alterado a IDADE de {} para {}\n'.format(agora.day, agora.month, agora.year,
                                                                                    nome, idadeentry))
                    arq.close()

                    top1.destroy()

                top1 = Toplevel(top)

                # ENTRY
                entryIDADE = Entry(top1)

                # BUTTON
                buttonENVIAR = Button(top1, font=('Arial', 10, 'bold'), text='ENVIAR', bg='firebrick1',
                                      fg='white',
                                      command=confirmar)

                # ATRIBUIÇÃO
                buttonENVIAR.grid(row=0, column=1)
                entryIDADE.grid(row=0, column=0)

                # CONFIGURAÇÕES DA JANELA
                top1.iconbitmap('bank-73-94206.ico')
                top1.geometry('+300+200')
                top1.title('ALTERAR IDADE')
                top1.mainloop()
                # FIM FUNÇÃO ALTERAR IDADE

            # FUNÇÃO ALTERAR NOME
            def alterar_nome():
                def confirmar():
                    nomeentry = str(entryNOME.get())

                    arq = open('dados.txt', 'w')
                    arq.write('{}-{}-{}-{}-{}'.format(nomeentry, idade, cpf, login, senha))
                    arq.close()

                    arq = open('historico.txt', 'a')
                    arq.write(
                        '\nNo dia {}/{}/{} foi alterado o NOME de {} para {}\n'.format(agora.day, agora.month,
                                                                                      agora.year,
                                                                                      nome, nomeentry))
                    arq.close()

                    top1.destroy()

                top1 = Toplevel(top)

                # ENTRY
                entryNOME = Entry(top1)

                # BUTTON
                buttonENVIAR = Button(top1, font=('Arial', 10, 'bold'), text='ENVIAR', bg='firebrick1',
                                      fg='white',
                                      command=confirmar)

                # ATRIBUIÇÃO
                buttonENVIAR.grid(row=0, column=1)
                entryNOME.grid(row=0, column=0)

                # CONFIGURAÇÕES DA JANELA
                top1.iconbitmap('bank-73-94206.ico')
                top1.geometry('+300+200')
                top1.title('ALTERAR NOME')
                top1.mainloop()
                # FIM FUNÇÃO ALTERAR NOME



            # =======================
            # FUNÇÕES MAIS COMPLEXAS
            # =======================

            # INÍCIO OPÇÕES AVANÇADAS
            def opcoes_avancadas():

                global loginlabel, senhalabel

                # ================
                # FUNÇÃO PARA AUTENTICAÇÃO DE LOGIN/SENHA
                # ================

                def autenticar():

                    loginlabel = str(entryLOGADO.get())
                    senhalabel = str(entrySENHADO.get())

                    if login == loginlabel and senha == senhalabel:  # VERIFICA LOGIN/SENHA

                        autent.destroy()

                        def opcoesavancadas():

                            arq = open('dados.txt', 'r')
                            text = arq.readlines()
                            palavra = text[0]
                            palavra = palavra.split('-')
                            arq.close()

                            nome = str(palavra[0])
                            idade = str(palavra[1])
                            cpf = str(palavra[2])
                            login = str(palavra[3])
                            senha = str(palavra[4])


                            # FUNÇÕES VOLTAR/ATUALIZAR
                            def back():
                                top1.destroy()

                            def update():
                                top1.destroy()

                                opcoesavancadas()



                                # FUNÇÃO PARA CRIAR NOVA CONTA
                            def nova_conta():

                                # ===================
                                # TRATAMENTO DE ERROS
                                # ===================

                                # INÍCIO
                                
                                def tratamento_erro_nome(key): # tratamento de erro para nome

                                    def restart():

                                        labelNOMEtxt.delete(0, END)
                                        
                                    
                                    if key.char == '0' or key.char == '1' or key.char == '2' or key.char == '3' or \
                                            key.char == '4' or key.char == '5' or key.char == '6' or \
                                            key.char == '7' or key.char == '8' or key.char == '9' or \
                                            key.char == "'" or key.char == '!' or key.char == '@' or \
                                            key.char == '#' or key.char == '$' or key.char == '%' or \
                                            key.char == '¨' or key.char == '&' or key.char == '*' or \
                                            key.char == '(' or key.char == ')' or key.char == '-' or \
                                            key.char == '_' or key.char == '+' or key.char == '=' or \
                                            key.char == '§' or key.char == '´' or key.char == '`' or \
                                            key.char == '[' or key.char == ']' or key.char == '{' or \
                                            key.char == '}' or key.char == 'ª' or key.char == '^' or \
                                            key.char == '~' or key.char == 'º' or key.char == '<' or \
                                            key.char == '>' or key.char == ',' or key.char == '.' or \
                                            key.char == ':' or key.char == ';' or key.char == '?' or \
                                            key.char == '/' or key.char == '°' or key.char == '|' or \
                                            key.char == '*':
                                        
                                        labelNOMEtxt.delete(0, END)
                                        
                                        messagebox.showwarning('Erro', 'Digite apenas letras no nome')

                                        restart()


                                def tratamento_erro_idade(key): # tratamento de erro para idade

                                    def restart():

                                        labelIDADEtxt.delete(0, END)
                                        

                                    global var_idade, varIDADE, numeroIDADE

                                    if key.char == '\b':

                                        string = backspace(var_idade)
                                        var_idade = string

                                        if var_idade == '':
                                            numeroIDADE = 0
                                        else:
                                            numeroIDADE -= 1


                                    if key.char == '0' or key.char == '1' or key.char == '2' or key.char == '3' or \
                                       key.char == '4' or key.char == '5' or key.char == '6' or \
                                       key.char == '7' or key.char == '8' or key.char == '9':

                                        var_idade += key.char
                                        numeroIDADE += 1
                                        

                                        varIDADE = int(var_idade)

                                        if numeroIDADE == 2:
                                            
                                            if varIDADE < 18:
                                                
                                                numeroIDADE = 0
                                                var_idade = ''
                                                labelIDADEtxt.delete(0, END)

                                                messagebox.showwarning('Erro', 'Você precisa ter uma idade igual ou superior a 18 anos')

                                                restart()
                                                

                                        if numeroIDADE == 3:

                                            labelIDADEtxt.delete(0, END)
                                            numeroIDADE = 0
                                            var_idade = ''
                                            
                                            messagebox.showwarning('Erro', 'Valor inválido')

                                            restart()


                                    elif key.char == "'" or key.char == '!' or key.char == '@' or \
                                            key.char == '#' or key.char == '$' or key.char == '%' or \
                                            key.char == '¨' or key.char == '&' or key.char == '*' or \
                                            key.char == '(' or key.char == ')' or key.char == '-' or \
                                            key.char == '_' or key.char == '+' or key.char == '=' or \
                                            key.char == '§' or key.char == '´' or key.char == '`' or \
                                            key.char == '[' or key.char == ']' or key.char == '{' or \
                                            key.char == '}' or key.char == 'ª' or key.char == '^' or \
                                            key.char == '~' or key.char == 'º' or key.char == '<' or \
                                            key.char == '>' or key.char == ',' or key.char == '.' or \
                                            key.char == ':' or key.char == ';' or key.char == '?' or \
                                            key.char == '/' or key.char == '°' or key.char == '|' or \
                                            key.char == '*' or key.char == '\\' or key.char == 'a' or key.char == 'b' or key.char == 'c' or key.char == 'd' or \
                                            key.char == 'e' or key.char == 'f' or key.char == 'g' or key.char == 'h' or \
                                            key.char == 'i' or key.char == 'j' or key.char == 'k' or key.char == 'l' or \
                                            key.char == 'm' or key.char == 'n' or key.char == 'o' or key.char == 'p' or \
                                            key.char == 'q' or key.char == 'r' or key.char == 's' or key.char == 't' or \
                                            key.char == 'u' or key.char == 'v' or key.char == 'w' or key.char == 'x' or \
                                            key.char == 'y' or key.char == 'z' or key.char == 'A' or key.char == 'B' or key.char == 'C' or key.char == 'D' or \
                                            key.char == 'E' or key.char == 'F' or key.char == 'G' or key.char == 'H' or \
                                            key.char == 'I' or key.char == 'J' or key.char == 'K' or key.char == 'L' or \
                                            key.char == 'M' or key.char == 'N' or key.char == 'O' or key.char == 'P' or \
                                            key.char == 'Q' or key.char == 'R' or key.char == 'S' or key.char == 'T' or \
                                            key.char == 'U' or key.char == 'V' or key.char == 'W' or key.char == 'X' or \
                                            key.char == 'Y' or key.char == 'Z':


                                        labelIDADEtxt.delete(0, END)

                                        messagebox.showwarning('Erro', 'Digite apenas números na idade')

                                        restart()



                                def tratamento_erro_cpf(key): # tratamento de erro para cpf

                                    def restart():

                                            labelCPFtxt.delete(0, END)

                                    global var_cpf


                                    if key.char == ' ':

                                        labelSENHAtxt.delete(0, END)
                                        var_cpf = ''

                                        messagebox.showwarning('Erro', 'O CPF não pode conter espaços')

                                        restart()

                                    elif key.char == '\b':

                                        varCPF = backspace(var_cpf)
                                        var_cpf = varCPF
                                        

                                    if key.char == '0' or key.char == '1' or key.char == '2' or key.char == '3' or \
                                            key.char == '4' or key.char == '5' or key.char == '6' or \
                                            key.char == '7' or key.char == '8' or key.char == '9':


                                        var_cpf += key.char

                                        
                                        numero = len(var_cpf)

                                        if numero > 11:
                                            
                                            numero = 0
                                            var_cpf = ''
                                            labelCPFtxt.delete(0, END)
                                            
                                            messagebox.showwarning('Erro', 'O CPF não pode conter mais de 11 digitos')

                                            restart()



                                    elif key.char == "'" or key.char == '!' or key.char == '@' or \
                                            key.char == '#' or key.char == '$' or key.char == '%' or \
                                            key.char == '¨' or key.char == '&' or key.char == '*' or \
                                            key.char == '(' or key.char == ')' or key.char == '-' or \
                                            key.char == '_' or key.char == '+' or key.char == '=' or \
                                            key.char == '§' or key.char == '´' or key.char == '`' or \
                                            key.char == '[' or key.char == ']' or key.char == '{' or \
                                            key.char == '}' or key.char == 'ª' or key.char == '^' or \
                                            key.char == '~' or key.char == 'º' or key.char == '<' or \
                                            key.char == '>' or key.char == ',' or key.char == '.' or \
                                            key.char == ':' or key.char == ';' or key.char == '?' or \
                                            key.char == '/' or key.char == '°' or key.char == '|' or \
                                            key.char == '*' or key.char == '\\' or key.char == 'a' or key.char == 'b' or key.char == 'c' or key.char == 'd' or \
                                            key.char == 'e' or key.char == 'f' or key.char == 'g' or key.char == 'h' or \
                                            key.char == 'i' or key.char == 'j' or key.char == 'k' or key.char == 'l' or \
                                            key.char == 'm' or key.char == 'n' or key.char == 'o' or key.char == 'p' or \
                                            key.char == 'q' or key.char == 'r' or key.char == 's' or key.char == 't' or \
                                            key.char == 'u' or key.char == 'v' or key.char == 'w' or key.char == 'x' or \
                                            key.char == 'y' or key.char == 'z' or key.char == 'A' or key.char == 'B' or key.char == 'C' or key.char == 'D' or \
                                            key.char == 'E' or key.char == 'F' or key.char == 'G' or key.char == 'H' or \
                                            key.char == 'I' or key.char == 'J' or key.char == 'K' or key.char == 'L' or \
                                            key.char == 'M' or key.char == 'N' or key.char == 'O' or key.char == 'P' or \
                                            key.char == 'Q' or key.char == 'R' or key.char == 'S' or key.char == 'T' or \
                                            key.char == 'U' or key.char == 'V' or key.char == 'W' or key.char == 'X' or \
                                            key.char == 'Y' or key.char == 'Z':


                                        labelIDADEtxt.delete(0, END)

                                        messagebox.showwarning('Erro', 'Digite apenas números no CPF')

                                        restart()


                                def tratamento_erro_login(key): # tratamento de erros login

                                    def restart():

                                        labelLOGINtxt.delete(0, END)
                                        

                                    global var_teste_login, aviso_login, varLOGIN


                                    if aviso_login == 1: # se aviso_login == 1, então excedeu o limite de caracteres, entry é limpado
                                        aviso_login = 0

                                        labelLOGINtxt.delete(0, END)

                                    if var_teste_login.isalnum() == True and key.char == '\b': # se apertada a tecla backspace e já houver algo escrito no campo, então a ultima letra da string é apagada

                                        varTESTE = backspace(var_teste_login)
                                        var_teste_login = varTESTE
                                        varLOGIN -= 1

                                    if key.char == ' ': # se digitar espaço, recebe erro

                                        labelLOGINtxt.delete(0, END)
                                        var_teste_login = ''
                                        aviso_login = 1

                                        messagebox.showwarning('Erro', 'O login não pode conter espaços')

                                        restart()

                                    if key.char == 'a' or key.char == 'b' or key.char == 'c' or key.char == 'd' or \
                                       key.char == 'e' or key.char == 'f' or key.char == 'g' or key.char == 'h' or \
                                       key.char == 'i' or key.char == 'j' or key.char == 'k' or key.char == 'l' or \
                                       key.char == 'm' or key.char == 'n' or key.char == 'o' or key.char == 'p' or \
                                       key.char == 'q' or key.char == 'r' or key.char == 's' or key.char == 't' or \
                                       key.char == 'u' or key.char == 'v' or key.char == 'w' or key.char == 'x' or \
                                       key.char == 'y' or key.char == 'z' or key.char == "'" or key.char == '!' or key.char == '@' or \
                                       key.char == '#' or key.char == '$' or key.char == '%' or \
                                       key.char == '¨' or key.char == '&' or key.char == '*' or \
                                       key.char == '(' or key.char == ')' or key.char == '-' or \
                                       key.char == '_' or key.char == '+' or key.char == '=' or \
                                       key.char == '§' or key.char == '´' or key.char == '`' or \
                                       key.char == '[' or key.char == ']' or key.char == '{' or \
                                       key.char == '}' or key.char == 'ª' or key.char == '^' or \
                                       key.char == '~' or key.char == 'º' or key.char == '<' or \
                                       key.char == '>' or key.char == ',' or key.char == '.' or \
                                       key.char == ':' or key.char == ';' or key.char == '?' or \
                                       key.char == '/' or key.char == '°' or key.char == '|' or \
                                       key.char == '*' or key.char == '\\' or key.char == '1' or \
                                       key.char == '2' or key.char == '3' or key.char == '4' or \
                                       key.char == '5' or key.char == '6' or key.char == '7' or \
                                       key.char == '8' or key.char == '9':

                                        if key.char == ' ' and key.char == '\b':
                                            
                                            print('backspace ou barra de espaço entrou')

                                        else:

                                            var_teste_login += str(key.char)
                                            varLOGIN += 1

                                            if varLOGIN > 8:

                                                labelLOGINtxt.delete(0, END)
                                                var_teste_login = ''
                                                varLOGIN = 0
                                                aviso_login = 1

                                                messagebox.showwarning('Erro', 'O login não pode ter mais que 8 caracteres')

                                                restart()


                                    if key.char == 'A' or key.char == 'B' or key.char == 'C' or key.char == 'D' or \
                                       key.char == 'E' or key.char == 'F' or key.char == 'G' or key.char == 'H' or \
                                       key.char == 'I' or key.char == 'J' or key.char == 'K' or key.char == 'L' or \
                                       key.char == 'M' or key.char == 'N' or key.char == 'O' or key.char == 'P' or \
                                       key.char == 'Q' or key.char == 'R' or key.char == 'S' or key.char == 'T' or \
                                       key.char == 'U' or key.char == 'V' or key.char == 'W' or key.char == 'X' or \
                                       key.char == 'Y' or key.char == 'Z':

                                        labelLOGINtxt.delete(0, END)
                                        var_teste_login = ''
                                        varLOGIN = 0
                                        aviso_login = 1

                                        messagebox.showwarning('Erro', 'O login deve ser escrito apenas com letras minúsculas')

                                        restart()



                                def tratamento_erro_senha(key): # tratamento de erros senha

                                    def restart():

                                        labelSENHAtxt.delete(0, END)
                                        

                                    global var_teste_senha, aviso_senha

                                    if aviso_senha == 1:
                                        aviso_senha = 0

                                        labelSENHAtxt.delete(0, END)

                                    if var_teste_senha.isalnum() == True and key.char == '\b':

                                        varTESTE = backspace(var_teste_senha)
                                        var_teste_senha = varTESTE

                                    if key.char == ' ':

                                        labelSENHAtxt.delete(0, END)
                                        var_teste_senha = ''
                                        aviso_senha = 1

                                        messagebox.showwarning('Erro', 'A senha não pode conter espaços')

                                        restart()

                                    elif key.char == '\b':
                                        var_teste_senha += ''

                                    else:

                                        var_teste_senha += key.char

                                        if len(var_teste_senha) > 8:

                                            labelSENHAtxt.delete(0, END)
                                            var_teste_senha = ''
                                            aviso_senha = 1

                                            messagebox.showwarning('Erro', 'A senha não pode ter mais que 8 caracteres')

                                            restart()

                                            #FIM

                                top13 = Toplevel(top1)

                                # funçao responsavel por armazenar as informaçoes que o usuario forneceu
                                def armazenar():
                                    # ARMAZENAR DADOS PESSOAIS
                                    nome = str(labelNOMEtxt.get())
                                    idade = labelIDADEtxt.get()
                                    cpf = labelCPFtxt.get()
                                    login = labelLOGINtxt.get()
                                    senha = labelSENHAtxt.get()

                                    # nome-idade-cpf-login-senha
                                    arq = open('dados.txt', 'w')
                                    arq.write('{}-{}-{}-{}-{}'.format(nome, idade, cpf, login, senha))
                                    arq.close()

                                    # atribuição de valores as variaveis
                                    arq = open('dados.txt', 'r')
                                    text = arq.readlines()
                                    palavra = text[0]
                                    palavra = palavra.split('-')
                                    arq.close()

                                    nome = palavra[0]
                                    idade = palavra[1]
                                    cpf = palavra[2]
                                    login = palavra[3]
                                    senha = palavra[4]

                                    global contc, saldo, limite, fatura

                                    contc += 1  # informa fim do cadastro

                                    arq = open('dados_financeiro.txt', 'w')
                                    arq.write('{}-{}-{}'.format(saldo, limite, fatura))
                                    arq.close()

                                    # pega data atual
                                    dia = agora.day
                                    mes = agora.month
                                    ano = agora.year

                                    # informa ao historico o cadastro
                                    arq = open('historico.txt', 'w')
                                    arq.write(
                                        '=== CADASTRO DO USUÁRIO ===\nNo dia {}/{}/{} foi realizado o cadastro do cliente {}\n'.format(
                                            dia, mes, ano, nome.title()))

                                    question = messagebox.askquestion('Tem certeza?', 'Tem certeza de que deseja criar uma nova conta? Todos os dados serão perdidos')

                                    if question == 'yes':
                                        messagebox.showinfo('Sucesso', 'Conta criada com sucesso! Por favor, faça login novamente')

                                        tela.destroy()

                                    else:
                                        top13.destroy()


                                # FRAMES

                                frameFUNDO = Frame(top13, width=200, height=150, bg='dim gray')
                                frameDADOS = Frame(top13, width=200, height=150, bg='dim gray')
                                frameCONFIRMAR = Frame(top13, width=200, height=50, bg='gray')

                                # LABELS

                                labelNOME = Label(frameDADOS, text='Nome:', fg='white', bg='dim gray')
                                labelNOMEtxt = Entry(frameDADOS)

                                labelIDADE = Label(frameDADOS, text='Idade:', fg='white', bg='dim gray')
                                labelIDADEtxt = Entry(frameDADOS)

                                labelCPF = Label(frameDADOS, text='CPF:', fg='white', bg='dim gray')
                                labelCPFtxt = Entry(frameDADOS)

                                labelBRANCO = Label(frameDADOS, text='\n', fg='white', bg='dim gray')

                                labelLOGIN = Label(frameDADOS, text='Login:', fg='white', bg='dim gray')
                                labelLOGINtxt = Entry(frameDADOS)

                                labelSENHA = Label(frameDADOS, text='Senha:', fg='white', bg='dim gray')
                                labelSENHAtxt = Entry(frameDADOS)

                                # BUTTONS

                                buttonCONFIRMAR = Button(top13, text='CONFIRMAR', font=('Arial', 8, 'bold'),
                                                         fg='light slate gray',
                                                         command=armazenar)

                                # ATRIBUIÇÃO

                                frameFUNDO.grid(row=0, column=0)
                                frameDADOS.place(x=0, y=10)
                                frameCONFIRMAR.place(x=0, y=150)
                                labelNOME.grid(row=0, column=0)
                                labelNOMEtxt.grid(row=0, column=1)
                                labelIDADE.grid(row=1, column=0)
                                labelIDADEtxt.grid(row=1, column=1)
                                labelCPF.grid(row=2, column=0)
                                labelCPFtxt.grid(row=2, column=1)
                                labelBRANCO.grid(row=3, column=0)
                                labelLOGIN.grid(row=4, column=0)
                                labelLOGINtxt.grid(row=4, column=1)
                                labelSENHA.grid(row=5, column=0)
                                labelSENHAtxt.grid(row=5, column=1)
                                buttonCONFIRMAR.place(x=60, y=160)

                                # EVENTOS

                                labelNOMEtxt.bind('<Key>', tratamento_erro_nome)
                                labelIDADEtxt.bind('<Key>', tratamento_erro_idade)
                                labelCPFtxt.bind('<Key>', tratamento_erro_cpf)
                                labelLOGINtxt.bind('<Key>', tratamento_erro_login)
                                labelSENHAtxt.bind('<Key>', tratamento_erro_senha)


                                # CONFIGURAÇÕES NOVA CONTA
                                top13.iconbitmap('bank-73-94206.ico')
                                top13.title('Cadastro')
                                top13.geometry('185x200+200+100')
                                top13.mainloop()
                                

                            global contador, var_teste_login, var_teste_senha, teste, var_idade, var_cpf, aviso_senha, aviso_login, numeroIDADE, varLOGIN
                            contador = 0
                            var_teste_login = ''
                            var_teste_senha = ''
                            teste = ''
                            var_idade = ''
                            numeroIDADE = 0
                            var_cpf = ''
                            var = ''
                            varLOGIN = 0
                            aviso_senha = 0
                            aviso_login = 0


                            # FUNÇÃO PARA ALTERAR O SENHA
                            def alterar_senha():
                                def confirmar():
                                    senhaentry = str(entrySENHA.get())

                                    os.remove('dados.txt')

                                    arq = open('dados.txt', 'w')
                                    arq.write('{}-{}-{}-{}-{}'.format(nome, idade, cpf, login, senhaentry))
                                    arq.close()

                                    arq = open('historico.txt', 'a')
                                    arq.write(
                                            '\nNo dia {}/{}/{} foi alterado a SENHA de {} para {}'.format(agora.day,
                                                                                                          agora.month,
                                                                                                          agora.year,
                                                                                                          nome, senhaentry))
                                    arq.close()

                                    top2.destroy()

                                top2 = Toplevel(top)

                                # ENTRY
                                entrySENHA = Entry(top2)

                                # BUTTON
                                buttonENVIAR = Button(top2, font=('Arial', 10, 'bold'), text='ENVIAR', bg='firebrick1',
                                                          fg='white',
                                                          command=confirmar)

                                # ATRIBUIÇÃO
                                buttonENVIAR.grid(row=0, column=1)
                                entrySENHA.grid(row=0, column=0)

                                # CONFIGURAÇÃO TOP1
                                top2.iconbitmap('bank-73-94206.ico')
                                top2.geometry('+600+200')
                                top2.title('ALTERAR SENHA')
                                top2.mainloop()
                                # FIM FUNÇÃO ALTERA SENHA


                            # FUNÇÃO PARA ALTERAR O LOGIN
                            def alterar_login():
                                def confirmar():

                                    loginentry = str(entryLOGIN.get())

                                    os.remove('dados.txt')

                                    arq = open('dados.txt', 'w')
                                    arq.write('{}-{}-{}-{}-{}'.format(nome, idade, cpf, loginentry, senha))
                                    arq.close()

                                    arq = open('historico.txt', 'a')
                                    arq.write(
                                           '\nNo dia {}/{}/{} foi alterado o LOGIN de {} para {}'.format(agora.day,
                                                                                                          agora.month,
                                                                                                          agora.year,
                                                                                                          nome, loginentry))
                                    arq.close()

                                    top2.destroy()

                                top2 = Toplevel(top)

                                # ENTRY
                                entryLOGIN = Entry(top2)

                                # BUTTON
                                buttonENVIAR = Button(top2, font=('Arial', 10, 'bold'), text='ENVIAR', bg='firebrick1',
                                                          fg='white',
                                                          command=confirmar)

                                # ATRIBUIÇÃO
                                buttonENVIAR.grid(row=0, column=1)
                                entryLOGIN.grid(row=0, column=0)


                                # CONFIGURAÇÃO TOP1
                                top2.iconbitmap('bank-73-94206.ico')
                                top2.geometry('+600+200')
                                top2.title('ALTERAR LOGIN')
                                top2.mainloop()
                                # FIM FUNÇÃO ALTERA LOGIN



                            # =======================
                            # CORPO FUNÇÃO AVANÇADA
                            # =======================

                            top1 = Toplevel(top)

                            # FRAMES
                            frameBACKGROUND = Frame(top1, width=300, height=300, bg='gray')

                            # LABELS
                            labelOPCOES_AVANCADAS = Label(top1, font=('Arial', 12, 'bold'), text='OPÇÕES AVANÇADAS',
                                                              bg='gray',
                                                              fg='white')
                            labelLOGIN_ = Label(top1, font=('Arial', 12, 'bold'), text='Login: {}'.format(login),
                                                    bg='gray',
                                                    fg='white')
                            labelSENHA_ = Label(top1, font=('Arial', 12, 'bold'), text='Senha: {}'.format(senha),
                                                    bg='gray',
                                                    fg='white')
                            labelNOVA_CONTA = Label(top1, font=('Arial', 12, 'bold'), text='Criar nova conta',
                                                        bg='gray',
                                                        fg='white')

                            # BUTTONS
                            buttonLOGIN_ = Button(top1, font=('Arial', 10, 'bold'), text='ALTERAR', bg='firebrick1',
                                                      fg='white',
                                                      command=alterar_login)
                            buttonSENHA_ = Button(top1, font=('Arial', 10, 'bold'), text='ALTERAR', bg='firebrick1',
                                                      fg='white',
                                                      command=alterar_senha)
                            buttonNOVA_CONTA = Button(top1, font=('Arial', 10, 'bold'), text='CRIAR', bg='firebrick1',
                                                          fg='white',
                                                          command=nova_conta)
                            buttonBACK = Button(top1, font=('Arial', 10, 'bold'), text='<- Voltar', bg='firebrick1',
                                                    fg='white',
                                                    command=back)
                            buttonACTUALIZAR = Button(top1, font=('Arial', 10, 'bold'), text='( ) Atualizar',
                                                          bg='firebrick1', fg='white',
                                                          command=update)

                            # ATRIBUIÇÃO
                            frameBACKGROUND.place(x=0, y=0)
                            labelOPCOES_AVANCADAS.place(x=50, y=10)
                            labelLOGIN_.place(x=10, y=70)
                            labelSENHA_.place(x=10, y=100)
                            labelNOVA_CONTA.place(x=10, y=160)
                            buttonLOGIN_.place(x=200, y=70)
                            buttonSENHA_.place(x=200, y=100)
                            buttonNOVA_CONTA.place(x=215, y=160)
                            buttonACTUALIZAR.place(x=15, y=220)
                            buttonBACK.place(x=210, y=220)


                            # CONFIGURAÇÕES TOP1
                            top1.iconbitmap('bank-73-94206.ico')
                            top1.geometry('300x270+550+200')
                            top1.title('Opções Avançadas')
                            top1.mainloop()
                            # FIM CORPO FUNÇÃO AVANÇADA

                        opcoesavancadas()

                    else:
                        messagebox.showerror('Erro', 'Login ou Senha incorretos!')

                        autent.destroy()

                # ====================
                # JANELA AUTENTICAÇÃO
                # ====================

                autent = Toplevel(top)

                # FRAMES
                frameBACKGROUND = Frame(autent, width=350, height=200, bg='gray')

                # LABELS
                labelLOGADO = Label(frameBACKGROUND, text='Login:', bg='gray', fg='white')
                labelSENHADO = Label(frameBACKGROUND, text='Senha:', bg='gray', fg='white')

                # ENTRIES
                entryLOGADO = Entry(frameBACKGROUND)
                entrySENHADO = Entry(frameBACKGROUND)

                # BUTTONS
                buttonENVIAR = Button(frameBACKGROUND, text='ENVIAR', bg='firebrick1', fg='white', command=autenticar)

                # ATRIBUIÇÃO
                frameBACKGROUND.grid()

                labelLOGADO.grid(row=0, column=0)
                entryLOGADO.grid(row=0, column=1)

                labelSENHADO.grid(row=1, column=0)
                entrySENHADO.grid(row=1, column=1)

                buttonENVIAR.grid(row=2, columnspan=2)

                # CONFIGURAÇÕES AUTENT
                autent.iconbitmap('bank-73-94206.ico')
                autent.geometry('165x65+550+200')
                autent.title('Autenticação')
                autent.mainloop()
                # FIM OPÇÕES AVANÇADAS

            # CORPO BOTÃO DADOS

            arq = open('dados.txt', 'r')
            text = arq.readlines()
            palavra = text[0]
            palavra = palavra.split('-')
            arq.close()

            nome = str(palavra[0])
            idade = str(palavra[1])
            cpf = str(palavra[2])
            login = str(palavra[3])
            senha = str(palavra[4])

            top = Toplevel(tela)

            # FRAMES
            frameFUNDO = Frame(top, width=300, height=300, bg='gray')

            # LABELS
            labelDAD = Label(top, font=('Arial', 16, 'bold'), text='SEUS DADOS PESSOAIS', bg='gray', fg='white')
            labelNOME = Label(top, font=('Arial', 12, 'bold'), text='Nome: {}'.format(nome.title()), bg='gray',
                              fg='white')
            labelIDADE = Label(top, font=('Arial', 12, 'bold'), text='Idade: {}'.format(idade), bg='gray',
                               fg='white')
            labelCPF = Label(top, font=('Arial', 12, 'bold'), text='CPF: {}'.format(cpf), bg='gray',
                             fg='white')
            labelOPCOES_AVANCADAS = Label(top, font=('Arial', 12, 'bold'),
                                          text='Opções Avançadas\n(necessário autenticação)', bg='gray', fg='white')

            # BUTTONS
            buttonNOME = Button(top, font=('Arial', 10, 'bold'), text='ALTERAR', bg='firebrick1', fg='white',
                                command=alterar_nome)
            buttonIDADE = Button(top, font=('Arial', 10, 'bold'), text='ALTERAR', bg='firebrick1', fg='white',
                                 command=alterar_idade)
            buttonCPF = Button(top, font=('Arial', 10, 'bold'), text='ALTERAR', bg='firebrick1', fg='white',
                               command=alterar_cpf)
            buttonOPCOES_AVANCADAS = Button(top, font=('Arial', 10, 'bold'), text='IR', bg='firebrick1', fg='white',
                                            command=opcoes_avancadas)

            buttonVOLTAR = Button(top, font=('Arial', 10, 'bold'), text='<- VOLTAR', bg='firebrick1', fg='white',
                                  command=voltar)
            buttonUPDATE = Button(top, font=('Arial', 10, 'bold'), text='( ) Atualizar', bg='firebrick1', fg='white',
                                  command=atualizar)


            # ATRIBUIÇÃO
            frameFUNDO.place(x=0, y=0)

            labelDAD.place(x=20, y=10)
            labelNOME.place(x=10, y=60)
            labelIDADE.place(x=10, y=90)
            labelCPF.place(x=10, y=120)
            labelOPCOES_AVANCADAS.place(x=10, y=170)

            buttonNOME.place(x=200, y=58)
            buttonIDADE.place(x=200, y=88)
            buttonCPF.place(x=200, y=118)
            buttonOPCOES_AVANCADAS.place(x=240, y=178)
            buttonVOLTAR.place(x=190, y=250)
            buttonUPDATE.place(x=15, y=250)

            # CONFIGURAÇÕES "TOP"
            top.iconbitmap('bank-73-94206.ico')
            top.geometry('300x300+250+200')
            top.title('DADOS')
            arq.close()
            # FIM BOTÃO DADOS

        # FIM



        # ===============
        # TELA PRINCIPAL
        # ===============

        # INÍCIO

        arq = open('dados.txt', 'r')
        text = arq.readlines()
        palavra = text[0]
        palavra = palavra.split('-')
        arq.close()

        nome = str(palavra[0])

        try:
            arq = open('dados_financeiro.txt', 'r')
            texto = arq.readlines()
            palavras = texto[0]
            palavras = palavras.split('-')
            arq.close()

        except:
            arq = open('dados_financeiro.txt', 'w')
            text = '{}-{}-{}'.format(saldo, limite, fatura)
            arq.write(text)
            arq.close()

            arq = open('dados_financeiro.txt', 'r')
            texto = arq.readlines()
            palavras = texto[0]
            palavras = palavras.split('-')
            arq.close()


        # armazena as variaveis (str) que estavam no .txt em variaveis "fakes"
        saldofake = palavras[0]
        limitefake = palavras[1]
        faturafake = palavras[2]

        # transforma as variaveis em int, que no caso é esse tipo que eu preciso
        saldo = int(saldofake)
        limite = int(limitefake)
        fatura = int(faturafake)


        # MENU DE OPÇÕES
        tela = Tk()

        # FRAMES

        frameBASE_TOP = Frame(tela, width=600, height=80, bg='gray')
        frameBASE_LEFT = Frame(tela, width=30, height=500, bg='gray')
        frameBASE_RIGHT = Frame(tela, width=30, height=500, bg='gray')
        frameBASE_BUTTON = Frame(tela, width=600, height=30, bg='gray')

        frameMEIO = Frame(tela, width=540, height=320, bg='dim gray')

        frameOPCOES01 = Frame(frameMEIO, width=230, height=100, bg='firebrick1')
        frameOPCOES02 = Frame(frameMEIO, width=230, height=100, bg='firebrick1')
        frameOPCOES03 = Frame(frameMEIO, width=230, height=100, bg='firebrick1')
        frameOPCOES05 = Frame(frameMEIO, width=120, height=50, bg='firebrick1')
        frameOPCOES06 = Frame(frameMEIO, width=120, height=50, bg='firebrick1')


        # LABELS

        labelUSUARIO = Label(tela, text='Usuário: {}'.format(nome.title()), font=('Arial', 12), bg='gray',
                             fg='white')
        labelLOGO1 = Label(tela, text='BANCO 99', font=('Arial', 20, 'bold'), bg='gray', fg='white')
        labelSALDO = Label(tela, text='Saldo: R${}'.format(saldo), font=('Arial', 12), bg='gray', fg='white')

        labelDADOS = Button(frameOPCOES01, text='Dados', font=('Arial', 20, 'bold'), bg='firebrick1',
                            fg='white',
                            command=dados)
        labelCARTAO = Button(frameOPCOES02, text='Cartão', font=('Arial', 20, 'bold'), bg='firebrick1',
                             fg='white',
                             command=cartao)
        labelDEPOSITAR = Button(frameOPCOES03, text='Depositar', font=('Arial', 20, 'bold'), bg='firebrick1',
                                fg='white', command=depositar)

        # INÍCIO ATUALIZAR
        def atualizar1(): # atualiza informações da tela

            # primeiro sao destruidos as labels
            labelUSUARIO.destroy()
            labelSALDO.destroy()

            atualizar2()


        # BUTTONS

        buttonATUALIZAR = Button(frameOPCOES05, text='( ) Atualizar', font=('Arial', 12, 'bold'), bg='firebrick1',
                                 fg='white', command=atualizar1)
        buttonSAIR = Button(frameOPCOES06, text='X Sair', font=('Arial', 12, 'bold'), bg='firebrick1',
                            fg='white', command=sair)


        # ATRIBUIÇÃO

        frameBASE_TOP.pack(side=TOP)
        frameBASE_LEFT.pack(side=LEFT)
        frameBASE_RIGHT.pack(side=RIGHT)
        frameBASE_BUTTON.pack(side=BOTTOM)
        labelUSUARIO.place(x=25, y=30)
        labelLOGO1.place(x=230, y=23)
        labelSALDO.place(x=450, y=30)

        frameMEIO.place(x=30, y=80)

        frameOPCOES01.place(x=20, y=10)
        frameOPCOES02.place(x=290, y=10)
        frameOPCOES03.place(x=150, y=130)
        frameOPCOES05.place(x=75, y=250)
        frameOPCOES06.place(x=350, y=250)
        labelDADOS.place(x=60, y=20)
        labelCARTAO.place(x=60, y=20)
        labelDEPOSITAR.place(x=35, y=20)
        buttonATUALIZAR.place(x=10, y=10)
        buttonSAIR.place(x=30, y=10)


        # CONFIGURAÇÕES TELA

        tela.iconbitmap('bank-73-94206.ico')
        tela.title('PÁGINA PRINCIPAL')
        tela.geometry('600x430+350+150')
        tela.mainloop()

    else:
        messagebox.showinfo('Erro', 'Você não possui conta registrada!')
        # FIM TELA PRINCIPAL


# ===================
# INÍCIO DO PROGRMAMA
# ===================

janela = Tk()

# FUNÇÃO RESPONSÁVEL PELO CADASTRO DO USUÁRIO
def cadastro():
    if not (os.path.isfile('dados.txt')) == True: # se não existir o arquivo dados.txt -> não houve cadastro
        if (contc == 0): # se contc == 0 -> não houve cadastro

            # janela responsavel por exibir as informaçoes de cadastro
            top = Toplevel(janela)

            # ===================
            # TRATAMENTO DE ERROS
            # ===================

            # INÍCIO
            
            def tratamento_erro_nome(key): # tratamento de erro para nome

                def restart():

                    labelNOMEtxt.delete(0, END)
                    
                
                if key.char == '0' or key.char == '1' or key.char == '2' or key.char == '3' or \
                        key.char == '4' or key.char == '5' or key.char == '6' or \
                        key.char == '7' or key.char == '8' or key.char == '9' or \
                        key.char == "'" or key.char == '!' or key.char == '@' or \
                        key.char == '#' or key.char == '$' or key.char == '%' or \
                        key.char == '¨' or key.char == '&' or key.char == '*' or \
                        key.char == '(' or key.char == ')' or key.char == '-' or \
                        key.char == '_' or key.char == '+' or key.char == '=' or \
                        key.char == '§' or key.char == '´' or key.char == '`' or \
                        key.char == '[' or key.char == ']' or key.char == '{' or \
                        key.char == '}' or key.char == 'ª' or key.char == '^' or \
                        key.char == '~' or key.char == 'º' or key.char == '<' or \
                        key.char == '>' or key.char == ',' or key.char == '.' or \
                        key.char == ':' or key.char == ';' or key.char == '?' or \
                        key.char == '/' or key.char == '°' or key.char == '|' or \
                        key.char == '*':
                    
                    labelNOMEtxt.delete(0, END)
                    
                    messagebox.showwarning('Erro', 'Digite apenas letras no nome')

                    restart()


            def tratamento_erro_idade(key): # tratamento de erro para idade

                def restart():

                    labelIDADEtxt.delete(0, END)
                    

                global var_idade, varIDADE, numeroIDADE

                if key.char == '\b':

                    string = backspace(var_idade)
                    var_idade = string

                    if var_idade == '':
                        numeroIDADE = 0
                    else:
                        numeroIDADE -= 1


                if key.char == '0' or key.char == '1' or key.char == '2' or key.char == '3' or \
                   key.char == '4' or key.char == '5' or key.char == '6' or \
                   key.char == '7' or key.char == '8' or key.char == '9':

                    var_idade += key.char
                    numeroIDADE += 1
                    

                    varIDADE = int(var_idade)

                    if numeroIDADE == 2:
                        
                        if varIDADE < 18:
                            
                            numeroIDADE = 0
                            var_idade = ''
                            labelIDADEtxt.delete(0, END)

                            messagebox.showwarning('Erro', 'Você precisa ter uma idade igual ou superior a 18 anos')

                            restart()
                            

                    if numeroIDADE == 3:

                        labelIDADEtxt.delete(0, END)
                        numeroIDADE = 0
                        var_idade = ''
                        
                        messagebox.showwarning('Erro', 'Valor inválido')

                        restart()


                elif key.char == "'" or key.char == '!' or key.char == '@' or \
                        key.char == '#' or key.char == '$' or key.char == '%' or \
                        key.char == '¨' or key.char == '&' or key.char == '*' or \
                        key.char == '(' or key.char == ')' or key.char == '-' or \
                        key.char == '_' or key.char == '+' or key.char == '=' or \
                        key.char == '§' or key.char == '´' or key.char == '`' or \
                        key.char == '[' or key.char == ']' or key.char == '{' or \
                        key.char == '}' or key.char == 'ª' or key.char == '^' or \
                        key.char == '~' or key.char == 'º' or key.char == '<' or \
                        key.char == '>' or key.char == ',' or key.char == '.' or \
                        key.char == ':' or key.char == ';' or key.char == '?' or \
                        key.char == '/' or key.char == '°' or key.char == '|' or \
                        key.char == '*' or key.char == '\\' or key.char == 'a' or key.char == 'b' or key.char == 'c' or key.char == 'd' or \
                        key.char == 'e' or key.char == 'f' or key.char == 'g' or key.char == 'h' or \
                        key.char == 'i' or key.char == 'j' or key.char == 'k' or key.char == 'l' or \
                        key.char == 'm' or key.char == 'n' or key.char == 'o' or key.char == 'p' or \
                        key.char == 'q' or key.char == 'r' or key.char == 's' or key.char == 't' or \
                        key.char == 'u' or key.char == 'v' or key.char == 'w' or key.char == 'x' or \
                        key.char == 'y' or key.char == 'z' or key.char == 'A' or key.char == 'B' or key.char == 'C' or key.char == 'D' or \
                        key.char == 'E' or key.char == 'F' or key.char == 'G' or key.char == 'H' or \
                        key.char == 'I' or key.char == 'J' or key.char == 'K' or key.char == 'L' or \
                        key.char == 'M' or key.char == 'N' or key.char == 'O' or key.char == 'P' or \
                        key.char == 'Q' or key.char == 'R' or key.char == 'S' or key.char == 'T' or \
                        key.char == 'U' or key.char == 'V' or key.char == 'W' or key.char == 'X' or \
                        key.char == 'Y' or key.char == 'Z':


                    labelIDADEtxt.delete(0, END)

                    messagebox.showwarning('Erro', 'Digite apenas números na idade')

                    restart()



            def tratamento_erro_cpf(key): # tratamento de erro para cpf

                def restart():

                        labelCPFtxt.delete(0, END)

                global var_cpf


                if key.char == ' ':

                    labelSENHAtxt.delete(0, END)
                    var_cpf = ''

                    messagebox.showwarning('Erro', 'O CPF não pode conter espaços')

                    restart()

                elif key.char == '\b':

                    varCPF = backspace(var_cpf)
                    var_cpf = varCPF
                    

                if key.char == '0' or key.char == '1' or key.char == '2' or key.char == '3' or \
                        key.char == '4' or key.char == '5' or key.char == '6' or \
                        key.char == '7' or key.char == '8' or key.char == '9':


                    var_cpf += key.char

                    
                    numero = len(var_cpf)

                    if numero > 11:
                        
                        numero = 0
                        var_cpf = ''
                        labelCPFtxt.delete(0, END)
                        
                        messagebox.showwarning('Erro', 'O CPF não pode conter mais de 11 digitos')

                        restart()



                elif key.char == "'" or key.char == '!' or key.char == '@' or \
                        key.char == '#' or key.char == '$' or key.char == '%' or \
                        key.char == '¨' or key.char == '&' or key.char == '*' or \
                        key.char == '(' or key.char == ')' or key.char == '-' or \
                        key.char == '_' or key.char == '+' or key.char == '=' or \
                        key.char == '§' or key.char == '´' or key.char == '`' or \
                        key.char == '[' or key.char == ']' or key.char == '{' or \
                        key.char == '}' or key.char == 'ª' or key.char == '^' or \
                        key.char == '~' or key.char == 'º' or key.char == '<' or \
                        key.char == '>' or key.char == ',' or key.char == '.' or \
                        key.char == ':' or key.char == ';' or key.char == '?' or \
                        key.char == '/' or key.char == '°' or key.char == '|' or \
                        key.char == '*' or key.char == '\\' or key.char == 'a' or key.char == 'b' or key.char == 'c' or key.char == 'd' or \
                        key.char == 'e' or key.char == 'f' or key.char == 'g' or key.char == 'h' or \
                        key.char == 'i' or key.char == 'j' or key.char == 'k' or key.char == 'l' or \
                        key.char == 'm' or key.char == 'n' or key.char == 'o' or key.char == 'p' or \
                        key.char == 'q' or key.char == 'r' or key.char == 's' or key.char == 't' or \
                        key.char == 'u' or key.char == 'v' or key.char == 'w' or key.char == 'x' or \
                        key.char == 'y' or key.char == 'z' or key.char == 'A' or key.char == 'B' or key.char == 'C' or key.char == 'D' or \
                        key.char == 'E' or key.char == 'F' or key.char == 'G' or key.char == 'H' or \
                        key.char == 'I' or key.char == 'J' or key.char == 'K' or key.char == 'L' or \
                        key.char == 'M' or key.char == 'N' or key.char == 'O' or key.char == 'P' or \
                        key.char == 'Q' or key.char == 'R' or key.char == 'S' or key.char == 'T' or \
                        key.char == 'U' or key.char == 'V' or key.char == 'W' or key.char == 'X' or \
                        key.char == 'Y' or key.char == 'Z':


                    labelIDADEtxt.delete(0, END)

                    messagebox.showwarning('Erro', 'Digite apenas números no CPF')

                    restart()


            def tratamento_erro_login(key): # tratamento de erros login

                def restart():

                    labelLOGINtxt.delete(0, END)
                    

                global var_teste_login, aviso_login, varLOGIN


                if aviso_login == 1: # se aviso_login == 1, então excedeu o limite de caracteres, entry é limpado
                    aviso_login = 0

                    labelLOGINtxt.delete(0, END)

                if var_teste_login.isalnum() == True and key.char == '\b': # se apertada a tecla backspace e já houver algo escrito no campo, então a ultima letra da string é apagada

                    varTESTE = backspace(var_teste_login)
                    var_teste_login = varTESTE
                    varLOGIN -= 1

                if key.char == ' ': # se digitar espaço, recebe erro

                    labelLOGINtxt.delete(0, END)
                    var_teste_login = ''
                    aviso_login = 1

                    messagebox.showwarning('Erro', 'O login não pode conter espaços')

                    restart()

                if key.char == 'a' or key.char == 'b' or key.char == 'c' or key.char == 'd' or \
                   key.char == 'e' or key.char == 'f' or key.char == 'g' or key.char == 'h' or \
                   key.char == 'i' or key.char == 'j' or key.char == 'k' or key.char == 'l' or \
                   key.char == 'm' or key.char == 'n' or key.char == 'o' or key.char == 'p' or \
                   key.char == 'q' or key.char == 'r' or key.char == 's' or key.char == 't' or \
                   key.char == 'u' or key.char == 'v' or key.char == 'w' or key.char == 'x' or \
                   key.char == 'y' or key.char == 'z' or key.char == "'" or key.char == '!' or key.char == '@' or \
                   key.char == '#' or key.char == '$' or key.char == '%' or \
                   key.char == '¨' or key.char == '&' or key.char == '*' or \
                   key.char == '(' or key.char == ')' or key.char == '-' or \
                   key.char == '_' or key.char == '+' or key.char == '=' or \
                   key.char == '§' or key.char == '´' or key.char == '`' or \
                   key.char == '[' or key.char == ']' or key.char == '{' or \
                   key.char == '}' or key.char == 'ª' or key.char == '^' or \
                   key.char == '~' or key.char == 'º' or key.char == '<' or \
                   key.char == '>' or key.char == ',' or key.char == '.' or \
                   key.char == ':' or key.char == ';' or key.char == '?' or \
                   key.char == '/' or key.char == '°' or key.char == '|' or \
                   key.char == '*' or key.char == '\\' or key.char == '1' or \
                   key.char == '2' or key.char == '3' or key.char == '4' or \
                   key.char == '5' or key.char == '6' or key.char == '7' or \
                   key.char == '8' or key.char == '9':

                    if key.char == ' ' and key.char == '\b':
                        
                        print('backspace ou barra de espaço entrou')

                    else:

                        var_teste_login += str(key.char)
                        varLOGIN += 1

                        if varLOGIN > 8:

                            labelLOGINtxt.delete(0, END)
                            var_teste_login = ''
                            varLOGIN = 0
                            aviso_login = 1

                            messagebox.showwarning('Erro', 'O login não pode ter mais que 8 caracteres')

                            restart()


                if key.char == 'A' or key.char == 'B' or key.char == 'C' or key.char == 'D' or \
                   key.char == 'E' or key.char == 'F' or key.char == 'G' or key.char == 'H' or \
                   key.char == 'I' or key.char == 'J' or key.char == 'K' or key.char == 'L' or \
                   key.char == 'M' or key.char == 'N' or key.char == 'O' or key.char == 'P' or \
                   key.char == 'Q' or key.char == 'R' or key.char == 'S' or key.char == 'T' or \
                   key.char == 'U' or key.char == 'V' or key.char == 'W' or key.char == 'X' or \
                   key.char == 'Y' or key.char == 'Z':

                    labelLOGINtxt.delete(0, END)
                    var_teste_login = ''
                    varLOGIN = 0
                    aviso_login = 1

                    messagebox.showwarning('Erro', 'O login deve ser escrito apenas com letras minúsculas')

                    restart()



            def tratamento_erro_senha(key): # tratamento de erros senha

                def restart():

                    labelSENHAtxt.delete(0, END)
                    

                global var_teste_senha, aviso_senha

                if aviso_senha == 1:
                    aviso_senha = 0

                    labelSENHAtxt.delete(0, END)

                if var_teste_senha.isalnum() == True and key.char == '\b':

                    varTESTE = backspace(var_teste_senha)
                    var_teste_senha = varTESTE

                if key.char == ' ':

                    labelSENHAtxt.delete(0, END)
                    var_teste_senha = ''
                    aviso_senha = 1

                    messagebox.showwarning('Erro', 'A senha não pode conter espaços')

                    restart()

                elif key.char == '\b':
                    var_teste_senha += ''

                else:

                    var_teste_senha += key.char

                    if len(var_teste_senha) > 8:

                        labelSENHAtxt.delete(0, END)
                        var_teste_senha = ''
                        aviso_senha = 1

                        messagebox.showwarning('Erro', 'A senha não pode ter mais que 8 caracteres')

                        restart()

                        #FIM
                        

            def armazenar(): # funçao responsavel por armazenar as informaçoes que o usuario forneceu
                
                    # ARMAZENAR DADOS PESSOAIS
                    nome = str(labelNOMEtxt.get())
                    idade = labelIDADEtxt.get()
                    cpf = labelCPFtxt.get()
                    login = labelLOGINtxt.get()
                    senha = labelSENHAtxt.get()

                    # nome-idade-cpf-login-senha
                    arq = open('dados.txt', 'w')
                    arq.write('{}-{}-{}-{}-{}'.format(nome, idade, cpf, login, senha))
                    arq.close()

                    # atribuição de valores as variaveis
                    arq = open('dados.txt', 'r')
                    text = arq.readlines()
                    palavra = text[0]
                    palavra = palavra.split('-')
                    arq.close()

                    nome = palavra[0]

                    global contc, saldo, limite, fatura

                    contc += 1  # informa fim do cadastro

                    arq = open('dados_financeiro.txt', 'w')
                    arq.write('{}-{}-{}'.format(saldo, limite, fatura))
                    arq.close()


                    # pega data atual
                    dia = agora.day
                    mes = agora.month
                    ano = agora.year

                    # informa ao historico o cadastro
                    arq = open('historico.txt', 'w')
                    arq.write('=== CADASTRO DO USUÁRIO ===\nNo dia {}/{}/{} foi realizado o cadastro do cliente {}\n'.format(dia, mes, ano, nome.title()))

                    messagebox.showinfo('Sucesso', 'Cadastro Efetuado com Sucesso!')

                    if contc == 1:
                        top.destroy()


            global contador, var_teste_login, var_teste_senha, teste, var_idade, var_cpf, aviso_senha, aviso_login, numeroIDADE, varLOGIN
            contador = 0
            var_teste_login = ''
            var_teste_senha = ''
            teste = ''
            var_idade = ''
            numeroIDADE = 0
            var_cpf = ''
            var = ''
            varLOGIN = 0
            aviso_senha = 0
            aviso_login = 0

            # FRAMES

            frameFUNDO = Frame(top, width=200, height=150, bg='dim gray')
            frameDADOS = Frame(top, width=200, height=150, bg='dim gray')
            frameCONFIRMAR = Frame(top, width=200, height=50, bg='gray')

            # LABELS

            labelNOME = Label(frameDADOS, text='Nome:', fg='white', bg='dim gray')
            labelNOMEtxt = Entry(frameDADOS)

            labelIDADE = Label(frameDADOS, text='Idade:', fg='white', bg='dim gray')
            labelIDADEtxt = Entry(frameDADOS)

            labelCPF = Label(frameDADOS, text='CPF:', fg='white', bg='dim gray')
            labelCPFtxt = Entry(frameDADOS)

            labelBRANCO = Label(frameDADOS, text='\n', fg='white', bg='dim gray')

            labelLOGIN = Label(frameDADOS, text='Login:', fg='white', bg='dim gray')
            labelLOGINtxt = Entry(frameDADOS)

            labelSENHA = Label(frameDADOS, text='Senha:', fg='white', bg='dim gray')
            labelSENHAtxt = Entry(frameDADOS)


            # BUTTONS

            buttonCONFIRMAR = Button(top, text='CONFIRMAR', font=('Arial', 8, 'bold'), fg='light slate gray',
                                     command=armazenar)


            # ATRIBUIÇÃO

            frameFUNDO.grid(row=0, column=0)
            frameDADOS.place(x=0, y=10)
            frameCONFIRMAR.place(x=0, y=150)
            labelNOME.grid(row=0, column=0)
            labelNOMEtxt.grid(row=0, column=1)
            labelIDADE.grid(row=1, column=0)
            labelIDADEtxt.grid(row=1, column=1)
            labelCPF.grid(row=2, column=0)
            labelCPFtxt.grid(row=2, column=1)
            labelBRANCO.grid(row=3, column=0)
            labelLOGIN.grid(row=4, column=0)
            labelLOGINtxt.grid(row=4, column=1)
            labelSENHA.grid(row=5, column=0)
            labelSENHAtxt.grid(row=5, column=1)
            buttonCONFIRMAR.place(x=60, y=160)

            # EVENTOS

            labelNOMEtxt.bind('<Key>', tratamento_erro_nome)
            labelIDADEtxt.bind('<Key>', tratamento_erro_idade)
            labelCPFtxt.bind('<Key>', tratamento_erro_cpf)
            labelLOGINtxt.bind('<Key>', tratamento_erro_login)
            labelSENHAtxt.bind('<Key>', tratamento_erro_senha)

            # CONFIGURAÇÕES CADASTRO
            top.iconbitmap('bank-73-94206.ico')
            top.title('Cadastro')
            top.geometry('185x200+200+100')
            top.mainloop()

        else:
            messagebox.showinfo('Erro', 'Você já fez seu cadastro. Agora faça login')

    else:
        messagebox.showinfo('Erro', 'Você já fez seu cadastro. Agora faça login')


# FUNÇÃO RESPONSÁVEL POR VERIFICAR O LOGIN/SENHA QUE O USUÁRIO INFORMA
def sucesso():
    if os.path.isfile('dados.txt') == True: # verifica a existencia do arquivo dados.txt

        # atribuição de valores as variaveis
        arq = open('dados.txt', 'r')
        text = arq.readlines()
        palavra = text[0]
        palavra = palavra.split('-')
        arq.close()

        login = palavra[3]
        senha = palavra[4]

        # variaveis que recebem oq o usuario digita
        loginlabel = str(labelLOGINtxt.get())
        senhalabel = str(labelSENHAtxt.get())

        if (login == loginlabel and senha == senhalabel): # se o conteudo digitado == ao conteudo gravado no .txt, entao entra na funçao

            logado()

        else:
            messagebox.showinfo('Erro', 'Login ou Senha incorretos!')

    else:
        messagebox.showwarning('Erro', 'Informações pessoais não encontradas ou cadastro ainda não realizado. Por favor, realize seu cadastro')

        try:
            arq = open('dados.txt', 'w')
            arq.write('a')
            arq.close()

            os.remove('dados.txt')

            global contc
            contc = 0
        except:
            messagebox.showinfo('Erro', 'Você não possui conta registrada')



# TENTA ABRIR ARQUIVO QUE GUARDA OS DADOS DO CLIENTE
try: # se abrir arquivo -> já foi feito o cadastro
    arq = open('dados.txt', 'r')
    text = arq.readlines()
    palavra = text[0]
    palavra = palavra.split('-')
    arq.close()

    nome = str(palavra[0])
    idade = str(palavra[1])
    cpf = str(palavra[2])
    login = str(palavra[3])
    senha = str(palavra[4])

except:
    print('[Warning01] ARQUIVO \'dados.txt\' NÃO ENCONTRADO') # print apenas para sinalizar quando não existir arquivo, ou seja, quando não houver cadastro




# ===========INÍCIO==================================

# FRAMES

frameLOGIN_SENNHA = Frame(janela, width=250, height=150, bg='gray')
framePERGUNTA = Frame(janela, width=300, height=30, bg='black')
frameLOGO = Frame(janela, width=250, height=200, bg='blue')


# LABELS

labelLOGO = Label(frameLOGO, text='BEM-VINDO AO\nBANCO 99!', font=('Calibri', 25, 'bold'),
                  fg='white', bg='blue')

# LOGIN/SENHA
labelLOGIN = Label(frameLOGIN_SENNHA, text='Login:', font=('Arial', 12, 'bold'), fg='white', bg='gray')
labelLOGINtxt = Entry(frameLOGIN_SENNHA)

labelSENHA = Label(frameLOGIN_SENNHA, text='Senha:', font=('Arial', 12, 'bold'), fg='white', bg='gray')
labelSENHAtxt = Entry(frameLOGIN_SENNHA)

buttonCONFIRMAR = Button(frameLOGIN_SENNHA, text='CONFIRMAR', font=('Arial', 8, 'bold'), fg='light slate gray',
                         command=sucesso)

# PERGUNTA/BOTÃO CRIE UMA
labelPERGUNTA = Label(framePERGUNTA, text='       Não possui uma conta?', font=('Arial', 9), bg='black',
                      fg='white')
buttonCRIE_UMA = Button(janela, text='CRIE UMA!', font=('Arial', 7, 'bold'), command=cadastro)



# ATRIBUIÇÃO

frameLOGIN_SENNHA.place(x=0, y=0)
framePERGUNTA.place(x=0, y=120)
frameLOGO.place(x=250, y=0)
labelLOGIN.place(x=20, y=22)
labelLOGINtxt.place(x=80, y=25)
labelSENHA.place(x=20, y=44)
labelSENHAtxt.place(x=80, y=50)
buttonCONFIRMAR.place(x=100, y=80)
labelPERGUNTA.pack(side=BOTTOM, anchor=W)
buttonCRIE_UMA.place(x=165, y=122)
labelLOGO.place(x=20, y=25)


# CONFIG DA JANELA

janela.iconbitmap('bank-73-94206.ico')
janela.geometry('500x150+480+200')
janela.title('BANK SIMULATOR 2.0')
janela.mainloop()
