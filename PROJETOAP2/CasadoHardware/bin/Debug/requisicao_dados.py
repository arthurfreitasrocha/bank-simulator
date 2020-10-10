from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import time
import os       

options = Options()
options.headless = True

driver = webdriver.Chrome(executable_path='C:\chromedriver', chrome_options=options)
driver.get('http://192.168.1.102:5000')

#os.system('cls')

btn = driver.find_element(By.ID, '0')
btn.send_keys('C:\\Users\\arthu\\PROJETOAP2\\CasadoHardware\\bin\\Debug\\dados.txt')

#os.system('cls')

btn = driver.find_element(By.ID, '1')
btn.click()

#os.system('cls')

print('\ndados.txt ENVIADO COM SUCESSO!\n')

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#print('RESPOSTA ARMAZENADA COM SUCESSO')

#except:
    #print('ALGO DEU ERRADO')

driver.close()


        
        
