@echo off

verificacao.py

move autenticacao.py C:\Users\%username%\PROJETOAP2\Banco_99\bin\Debug
move info.txt C:\Users\%username%\PROJETOAP2\Banco_99\bin\Debug
cd C:\Users\%username%\PROJETOAP2\Banco_99\bin\Debug

dir C:\Users\%username%\PROJETOAP2\Banco_99\bin\Debug /b /s > C:\Users\%username%\PROJETOAP2\Banco_99\bin\Debug\lista.txt

autenticacao.py

del info.txt
del lista.txt
move autenticacao.py C:\uploads
move resposta.txt C:\uploads\static
cd C:\uploads

ECHO SUCESSO!

cls

start cmd.exe @cmd /k "exec"
exit

