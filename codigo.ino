#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// --- Configurações de Hardware (Pinos do NodeMCU) ---
const int PINO_BUZZER = D1; // Atuador Sonoro
const int PINO_LED    = D2; // Atuador Visual
const int PINO_SENSOR = D5; // Sensor Reed Switch

// --- Configurações de Rede ---
const char* ssid = "NOME_DA_SUA_REDE";      // Coloque aqui o nome do Wi-Fi
const char* password = "SENHA_DA_SUA_REDE"; // Coloque aqui a senha do Wi-Fi

// --- Configurações MQTT ---
const char* mqtt_server = "broker.hivemq.com"; // Broker público gratuito para testes
const char* topico_status = "mackenzie/saude/remedio/status";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  
  // Configura os pinos
  pinMode(PINO_BUZZER, OUTPUT);
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_SENSOR, INPUT); // O resistor de 10k externo faz o pull-up/down

  // Inicializa
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando em ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  // Loop de espera até conectar (para demonstração)
}

void reconnect() {
  // Loop até reconectar no MQTT
  while (!client.connected()) {
    Serial.print("Tentando conexao MQTT...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("conectado");
    } else {
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // --- Lógica do Projeto ---
  // Lê o estado do sensor (1 = Aberto/Longe, 0 = Fechado/Perto)
  int estadoSensor = digitalRead(PINO_SENSOR);

  if (estadoSensor == HIGH) {
    // Caixa ABERTA (Ímã longe) - Paciente tomando remédio
    digitalWrite(PINO_LED, LOW);    // Desliga LED
    digitalWrite(PINO_BUZZER, LOW); // Desliga Buzzer
    client.publish(topico_status, "CAIXA_ABERTA_REMEDIO_TOMADO");
    Serial.println("Caixa Aberta");
  } else {
    // Caixa FECHADA (Ímã perto)
    // Aqui entraria a lógica de horário. Para teste, vamos supor que está em alerta:
    // digitalWrite(PINO_LED, HIGH);    // Liga LED
    // digitalWrite(PINO_BUZZER, HIGH); // Liga Buzzer
    client.publish(topico_status, "CAIXA_FECHADA");
    Serial.println("Caixa Fechada");
  }
  
  delay(2000); // Espera 2 segundos antes de ler de novo
}
