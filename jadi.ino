#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pinSensor      A0     // Pino do sensor de umidade do solo
#define pinTemp        A1     // Pino do sensor de temperatura
#define pinPot         A2     // Pino do potenciômetro
#define verdePin       3      // Pino do LED verde
#define vermelhoPin    2      // Pino do LED vermelho
#define relePin        5      // Pino do módulo relé que controla a válvula solenóide



// Configura o endereço do LCD I2C (normalmente 0x27 ou 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C do LCD, com 16 colunas e 2 linhas

void setup() {
  Serial.begin(9600);
  pinMode(pinSensor, INPUT);     // Define o pino do sensor de umidade do solo como entrada
  pinMode(pinTemp, INPUT);       // Define o pino do sensor de temperatura como entrada
  pinMode(pinPot, INPUT);        // Define o pino do potenciômetro como entrada
  pinMode(verdePin, OUTPUT);     // Define o pino do LED verde como saída
  pinMode(vermelhoPin, OUTPUT);  // Define o pino do LED vermelho como saída
  pinMode(relePin, OUTPUT);      // Define o pino do módulo relé como saída

  lcd.init();          // Inicializa o LCD
  lcd.backlight();     // Liga a luz de fundo do LCD

  digitalWrite(relePin, HIGH);   // Inicializa o relé desligado (estado normalmente fechado)
}

void loop() {
  int umidade = lerSensor(pinSensor);     // Lê o valor do sensor de umidade do solo
  int temperatura = lerSensor(pinTemp);   // Lê o valor do sensor de temperatura
  int potenciometro = lerSensor(pinPot);  // Lê o valor do potenciômetro
  
  // Umidade abaixo de 60: aciona o relé para ligar a válvula solenóide
  Serial.println(analogRead(A0));
  if (analogRead(A0) > 340) {     
    digitalWrite(verdePin, LOW);
    digitalWrite(vermelhoPin, HIGH);
    digitalWrite(relePin, LOW);  // Ativa o módulo relé (liga a válvula solenóide)
    lcd.setCursor(0, 0);
    lcd.print("Umid. Solo: ");    
    lcd.print(analogRead(A0));
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Irrigacao ON");    
    delay(3000);
    lcd.clear();
  } else {       
    digitalWrite(verdePin, HIGH);
    digitalWrite(vermelhoPin, LOW);
    digitalWrite(relePin, HIGH);  // Desativa o módulo relé (desliga a válvula solenóide)
    lcd.setCursor(0, 0);
    lcd.print("Umid. Solo: ");  
    lcd.print(analogRead(A0));
    lcd.print("%"); 
    lcd.setCursor(0, 1);
    lcd.print("Irrigacao OFF");
    delay(3000);
    lcd.clear();
  }
  
  // Exibe a temperatura no LCD por 3 segundos
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(temperatura);
  lcd.print("C");
  delay(3000);
  lcd.clear();

  delay(1000);  // Aguarda 1 segundo
}

int lerSensor(int pin) {
  int valor = analogRead(pin);              // Lê o valor analógico do sensor
  int mapeado = map(valor, 0, 1023, 0, 100); // Mapeia o valor para uma faixa de 0 a 100
  return mapeado;
}
