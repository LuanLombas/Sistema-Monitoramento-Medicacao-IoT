# Sistema de Monitoramento de Adesão Medicamentosa (ODS 3)

Este projeto apresenta um protótipo de **Caixa de Remédios Inteligente** baseada em IoT. O objetivo é auxiliar pacientes idosos na adesão ao tratamento, enviando notificações automáticas para cuidadores quando a medicação é tomada.

## 📋 Hardware (Simulado)

* **Microcontrolador:** ESP32 (DevKit V1)
* **Sensor:** Slide Switch (No pino D4) -> Simula o sensor magnético da tampa.
* **Atuador:** LED Vermelho (No pino D15) -> Simula o alerta visual/sonoro.

## 🚀 Como Testar (Simulação)

1. **Acesse o Simulador:** [COLE AQUI O SEU LINK DO WOKWI]
2. **Monitore via MQTT:**
   * Acesse: https://mqttx.app/web-client/
   * Host: `broker.hivemq.com` | Porta: `8884` (SSL)
   * Tópico: `mackenzie/saude/#`

## ⚙️ Funcionamento
* **Caixa Fechada:** O sistema envia "ALERTA_HORA_DO_REMEDIO" e liga o LED.
* **Caixa Aberta:** O sistema envia "REMEDIO_TOMADO" e desliga o LED.
