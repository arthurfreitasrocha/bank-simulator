@echo off

verificacao_dados1.py

move autenticacao_dados1.py C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
move dados.txt C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
move enviar_email_duasetapas_codigo.py C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug
cd C:\Users\arthu\PROJETOAP2\Banco_99\bin\Debug

autenticacao_dados1.py

move autenticacao_dados1.py C:\uploads
move enviar_email_duasetapas_codigo.py C:\uploads
move email.txt C:\uploads
move codigo.txt C:\uploads
cd C:\uploads

ECHO SUCESSO!

cls

start cmd.exe @cmd /k "exec_dados2"
exit

