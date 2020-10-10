from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import time

options = Options()
options.headless = True

driver = webdriver.Chrome(executable_path='C:\chromedriver', chrome_options=options)
driver.get('http://192.168.1.102:5000')

btn = driver.find_element(By.ID, '0')
btn.send_keys('C:\\Users\\arthu\\PROJETOAP2\\CasadoHardware\\bin\\Debug\\info.txt')

btn = driver.find_element(By.ID, '1')
btn.click()


print('\ninfo.txt ENVIADO COM SUCESSO!\n')

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

print('AGUARDE...')

i = 10
while(i >= 1):
    time.sleep(1)
    i -= 1

#try:
driver.get('http://192.168.1.102:5000/static/resposta.txt')

element=driver.find_element_by_tag_name("pre")
element = str(element.text)

file = open('resposta.txt', 'w')
file.write(element)
file.close()

print('RESPOSTA ARMAZENADA COM SUCESSO')

#except:
    #print('ALGO DEU ERRADO')

driver.close()
        
        
