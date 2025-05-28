// Pinos dos LEDs
const int LED_VERDE = 9;
const int LED_VERMELHO = 8;

// Função para calcular NTU
double calc_NTU(double volt) {
  return -(1120.4 * volt * volt) + (5742.3 * volt) - 4352.9;
}

void setup() {
  Serial.begin(9600); 
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1024.0);
  double NTU;

  // Verifica se a tensão está na faixa esperada
  if (voltage >= 2.5 && voltage <= 4.2) {
    NTU = calc_NTU(voltage);
      
    Serial.println(NTU);

    if (NTU > 500) {
      digitalWrite(LED_VERMELHO, HIGH);
      digitalWrite(LED_VERDE, LOW);
      Serial.println("LED VERMELHO ACESO (Nível de turbidez alto)");
    } else {
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_VERDE, HIGH);
      Serial.println("LED VERDE ACESO (Nível de turbidez baixo)");
    }
  } else {
    Serial.print("Tensão fora da faixa válida: ");
    Serial.print(voltage, 2);
    Serial.println(" V. Verifique o sensor.");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, LOW);
  }

  delay(1000);
}

