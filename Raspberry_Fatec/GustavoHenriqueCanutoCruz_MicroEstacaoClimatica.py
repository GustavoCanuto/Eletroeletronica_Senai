# publico:https://thingspeak.mathworks.com/channels/2731763?classId=cb30488b-8e7d-4d0a-bf62-a103b8121c2a&assignmentId=f005e6eb-1c1c-4e4b-9589-e75fd737c04d&submissionId=28111938-8399-0439-44b2-21f336ab1713

from sense_emu import SenseHat
import time
import thingspeak

ID_IOT = "2"
CHAVE_IOT = "9"
CANAL_IOT = thingspeak.Channel(ID_IOT, CHAVE_IOT)

NOME_PROJETO = "Gustavo Henrique Canuto Cruz 21"

COR_PERIGO_VERMELHO = (255, 0, 0)     
COR_ATENCAO_AMARELO = (255, 255, 0)   
COR_NORMAL_VERDE = (0, 255, 0)        
COR_BRANCO = (255, 255, 255)         
COR_PROJETO_AZUL = (0, 0, 255)

# Configurações de exibição e tempo
VELOCIDADE_TEXTO = 0.05              
TEMPO_ESPERA = 6                      

sense = SenseHat()
sense.clear()

# Função para definir a cor do alerta e a mensagem de status
def definir_alerta(temp, umidade, pressao):
    
    # Condição de Perigo (Temperaturas acima de 32°C ou abaixo de -5°C)
    if temp > 32 or temp < -5 or \
       umidade > 80 or umidade < 20 or \
       pressao < 1000 or pressao > 1015:
        return COR_PERIGO_VERMELHO, "Perigo"
    
    # Condição de Atenção (Temperaturas entre -5°C e 10°C, ou entre 26°C e 32°C)
    elif (temp >= -5 and temp < 10) or (temp > 26 and temp <= 32) or \
         (umidade > 60 and umidade <= 80) or \
         (umidade > 20 and umidade <= 30) or \
         (pressao >= 1000 and pressao <= 1010):
        return COR_ATENCAO_AMARELO, "Atencao"
    
    # Condição Normal (Temperaturas entre 10°C e 26°C)
    else:
        return COR_NORMAL_VERDE, "Normal"

# Função para exibir o nome do projeto na tela
def exibir_nome_projeto():
    sense.show_message(NOME_PROJETO, text_colour=COR_PROJETO_AZUL)

exibir_nome_projeto()

while True:
    temp = sense.get_temperature()     # Temperatura em °C
    umidade = sense.get_humidity()     # Umidade relativa (%)
    pressao = sense.get_pressure()     # Pressão atmosférica (hPa)

    print(f"Temperatura: {temp}°C")
    print(f"Umidade: {umidade}%")
    print(f"Pressão: {pressao} hPa")

    dados_envio = {'field1': temp, 'field2': umidade, 'field3': pressao}
    
    if CANAL_IOT.update(dados_envio):
        print("Dados enviados para a nuvem!")
    else:
        print("Falha ao enviar dados...")

    cor_alerta, estado = definir_alerta(temp, umidade, pressao)
    
    print(f"estado: {estado}")
    
    sense.clear(COR_BRANCO)
    sense.show_message(f"{estado}: T: {temp:.1f}°C  U: {umidade:.1f}%  P: {pressao:.1f} hPa", 
                       text_colour=cor_alerta,  
                       scroll_speed=VELOCIDADE_TEXTO)

    print("---------------------")
    time.sleep(TEMPO_ESPERA)