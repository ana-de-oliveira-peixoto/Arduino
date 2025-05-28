import serial
import time
import requests

UBIDOTS_TOKEN = "BBUS-wVBo0DsI7Ir0XGXlRHDVb4FheZvzRr"
DEVICE_LABEL = "arduino_turbidez"
VARIABLE_LABEL = "turbidez"
SERIAL_PORT = "COM6"  
BAUD_RATE = 9600      


def send_to_ubidots(value):
    url = f"https://industrial.api.ubidots.com/api/v1.6/devices/{DEVICE_LABEL}"
    headers = {
        "X-Auth-Token": UBIDOTS_TOKEN,
        "Content-Type": "application/json"
    }
    payload = {VARIABLE_LABEL: value}
    try:
        response = requests.post(url, headers=headers, json=payload)
        print(">> Enviado para o Ubidots:", value)
    except Exception as e:
        print("Erro ao enviar:", e)

def main():
    arduino = serial.Serial(SERIAL_PORT, BAUD_RATE)
    time.sleep(2)  # Aguarda conexão estabilizar
    print("Conectado à porta serial.")

    while True:
        try:
            linha = arduino.readline().decode().strip()
            if linha:
                print("Valor recebido:", linha)
                try:
                    valor = float(linha)
                    send_to_ubidots(valor)
                except ValueError:
                    print("Não foi possível converter:", linha)
        except KeyboardInterrupt:
            print("Encerrando...")
            break

if __name__ == "__main__":
    main()
