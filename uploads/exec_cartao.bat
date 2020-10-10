@echo off

verificacao_cartao.py

move autenticacao_cartao.py C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
move cartao.txt C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
cd C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug

autenticacao_cartao.py

del cartao.txt
move autenticacao_cartao.py C:\uploads
move resposta.txt C:\uploads\static
cd C:\uploads

ECHO SUCESSO!

cls

start cmd.exe @cmd /k "exec_cartao"
exit

