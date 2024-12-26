# Código Arduino - Projeto Jadi  

Este repositório contém o código do Arduino utilizado no projeto **Jadi**, desenvolvido para monitorar e automatizar o processo de irrigação de plantas. O código controla os sensores, o relé e outros componentes para garantir o funcionamento eficiente do sistema.  

## Funcionalidades do Código  
- **Leitura de Sensores**: Realiza a leitura da umidade do solo e da temperatura.  
- **Automação da Irrigação**: Aciona a válvula solenóide via módulo relé automaticamente quando o solo está seco.  
- **Indicação por LEDs**: Sinaliza o estado do sistema com LEDs (verde e vermelho).  
- **Exibição de Dados**: Mostra informações no display LCD, como umidade do solo e status da irrigação.    

## Componentes Utilizados  
- **Sensores**:  
  - Sensor de Umidade do Solo  
  - Sensor de Temperatura  
- **Atuadores**:  
  - Módulo Relé  
  - Válvula Solenóide  
  - LEDs (verde e vermelho)  
- **Outros**:  
  - Display LCD I2C  
  - ESP32 (para comunicação Wi-Fi)  

## Configuração do Código  
1. **Pinos do Arduino**:  
   - Sensor de Umidade: A0  
   - Sensor de Temperatura: A1  
   - Relé: D5  
   - LEDs: D3 (verde) e D2 (vermelho)  
   - Display LCD: Pinos I2C (SDA e SCL)  

2. **Dependências**:  
   O código utiliza as bibliotecas `Wire.h`, `LiquidCrystal_I2C.h`, e `WiFi.h`. Certifique-se de instalá-las antes de compilar o código.  

3. **Rede Wi-Fi**:  
   Configure o `SSID` e a `senha` da sua rede Wi-Fi no código para conectar o ESP32.  

## Como Utilizar  
1. Carregue o código no Arduino UNO.  
2. Conecte os componentes conforme o esquema de pinos descrito.  
3. Alimente o Arduino e o circuito.  
4. Observe o funcionamento automático do sistema de irrigação, com dados exibidos no LCD.  
