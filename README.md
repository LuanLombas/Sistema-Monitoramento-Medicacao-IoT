# Projeto IoT: Caixa de Remédios Inteligente (ODS 3)

Este projeto consiste em um protótipo de caixa de remédios monitorada via IoT, desenvolvida para auxiliar na adesão medicamentosa de pacientes idosos, alinhado ao ODS 3 (Saúde e Bem-Estar).

## 📋 Hardware Necessário

* **Placa:** NodeMCU ESP8266 (v1.0 ou equivalente)
* **Sensor:** Reed Switch (Sensor Magnético MC-38)
* **Atuadores:**
    * 1x Módulo Buzzer Ativo (5V)
    * 1x LED Difuso Vermelho (5mm)
* **Componentes Extras:**
    * 1x Resistor 220Ω (para o LED)
    * 1x Resistor 10kΩ (Pull-down para o sensor)
    * Protoboard e Jumpers

## 🔧 Montagem e Pinos

As conexões devem ser feitas conforme o diagrama Fritzing incluído na documentação:

* **Buzzer:** Pino D1 (GPIO 5)
* **LED:** Pino D2 (GPIO 4)
* **Sensor Reed Switch:** Pino D5 (GPIO 14)

## 🚀 Como Executar o Projeto

### Pré-requisitos de Software
1.  Instalar a **Arduino IDE**.
2.  Configurar a IDE para placas ESP8266 (Gerenciador de Placas > `esp8266 by ESP8266 Community`).
3.  Instalar a biblioteca **PubSubClient** (autor: Nick O'Leary) via Gerenciador de Bibliotecas, para comunicação MQTT.

### Passos para Compilação
1.  Clone este repositório ou baixe o arquivo `codigo.ino`.
2.  Abra o arquivo `codigo.ino` na Arduino IDE.
3.  Nas linhas indicadas no código, insira o **SSID** (nome) e a **Senha** da sua rede Wi-Fi.
4.  Conecte o NodeMCU via USB.
5.  Selecione a porta COM correta e a placa "NodeMCU 1.0 (ESP-12E Module)".
6.  Clique em **Carregar (Upload)**.

### Monitoramento
Utilize um cliente MQTT (como MQTTX ou aplicativo de celular) e inscreva-se no tópico:
`mackenzie/saude/remedio/status` para visualizar os alertas em tempo real.
