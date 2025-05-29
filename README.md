# Projeto: Monitoramento de Qualidade da Água com Arduino e MQTT

## 📋 Descrição do Projeto
Este projeto tem como objetivo monitorar a turbidez da água utilizando um sensor conectado a uma placa Arduino Uno. Os dados obtidos são processados localmente e enviados para a plataforma Ubidots via protocolo MQTT, permitindo o acompanhamento remoto em tempo real por meio de um painel na nuvem.

## 🧠 Funcionamento
- O sensor de turbidez coleta os dados da água em tempo real.
- O Arduino realiza a leitura dos dados, converte a tensão para NTU e determina o nível de turbidez.
- Dois LEDs indicam visualmente o nível de turbidez: LED verde para turbidez baixa e LED vermelho para turbidez alta.
- Os dados processados são enviados via porta serial para um script Python, que os publica no Ubidots utilizando o protocolo MQTT.

## 🛠️ Software Desenvolvido
Este repositório contém dois arquivos principais:

1. `monitoramento.ino`: código fonte carregado na placa Arduino, responsável pela leitura do sensor e acionamento dos LEDs.
2. `publicar_arduino.py`: script Python responsável por fazer a ponte entre o Arduino (via serial) e a plataforma Ubidots.

## ⚙️ Hardware Utilizado
- Placa: Arduino Uno
- Sensor de turbidez (modelo sonda análoga)
- 2 LEDs (vermelho e verde)
- 2 resistores de 220Ω
- Jumpers e protoboard
- Cabo USB para comunicação com o computador

## 🔌 Comunicação e Protocolo
- Comunicação entre Arduino e computador via porta serial (USB)
- Envio dos dados para a internet através do protocolo MQTT
- Plataforma de nuvem utilizada: Ubidots

## 📡 Plataforma Ubidots
- Device criado: `arduino_turbidez`
- Variável: `turbidez`
- Os dados são apresentados em tempo real em um dashboard customizável na Ubidots.


## 📌 Como Executar
### Requisitos
- IDE Arduino (para carregar o código na placa)
- Python 3 instalado
- Bibliotecas Python:
  ```bash
  pip install pyserial paho-mqtt
  ```
- Conta na Ubidots com token e variável criados

### Passos
1. Abra e carregue o código `monitoramento.ino` na IDE do Arduino.
2. Edite o `publicar_arduino.py` inserindo seu token, device label e variable label do Ubidots.
3. Rode o script Python com:
   ```bash
   python publicar_arduino.py
   ```

## 📎 Licença
Este projeto é livre para fins acadêmicos e educacionais.

