// Bibliotecas
#include "ESP8266WiFi.h"
#include "DHT.h"

//rede Wifi
const char* ssid = "Nome da rede wifi";

//Senha da rede Wifi
const char* password = "senha da rede wifi";

// Pino do DHT
#define DHTPIN 2

// Definindo o sensor DHT11
#define DHTTYPE DHT11

// Inicializando o sensor DHT
DHT dht(DHTPIN, DHTTYPE, 15);

// Site que recebera os dados
const char* host = "dweet.io";

void setup() {
  // Iniciando o DHT 
  dht.begin();

  // Conectando na rede wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  // Criando uma conexao TCP
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    return;
  }
  
  // Lendo a umidade
  int u = dht.readHumidity();

  //Verificando se houve falha na leitura
  if(u == 2147483647){
    delay(10);
    return;
  }
  
  // Lendo a temperatura em graus Celsius
  int t = dht.readTemperature();

  // Calculando o indice de calor
  float f = dht.readTemperature(true);
  float ic = dht.computeHeatIndex(f, u);
  float icC = dht.convertFtoC(ic);
  
  // Enviando para o dweet as leituras efetuadas
  client.print(String("GET /dweet/for/nomedoseudweetaqui?temperatura=") + String(t) +
                "&umidade=" + String(u) + "&indice=" + String(icC) +
                " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  
  // Repetindo a cada 6 segundos
  delay(6000);
}