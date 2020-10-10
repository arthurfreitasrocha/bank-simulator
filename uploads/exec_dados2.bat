@echo off

del email.txt

verificacao_dados2.py

move autenticacao_dados2.py C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
move dados2.txt C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
move codigo.txt C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
cd C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug

autenticacao_dados2.py

del dados1.txt
del dados2.txt
del codigo.txt
move autenticacao_dados2.py C:\uploads
move resposta.txt C:\uploads\static
cd C:\uploads

ECHO SUCESSO!

cls

start cmd.exe @cmd /k "exec_dados1"
exit

