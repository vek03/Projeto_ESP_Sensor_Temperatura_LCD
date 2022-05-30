//Código de sensor de temperatura DHT no Terminal

// Inclua as seguintes bibliotecas:
//DHT:  sensor de temperatura e umidade para ESP
#include <DHTesp.h>

// Instância de objeto. O Objeto é o sensor DHT
DHTesp dht;

// Declaração de variáveis
float t; // Temperatura
float h; // Umidade

void setup() 
{
  //Inicialização do monitor serial
  Serial.begin(115200);

  // Inicializando o sensor DHT
  // objeto.função_iniciar(Pino de entrada, DHTesp::versão_sensor);
  dht.setup(4, DHTesp::DHT22);
}

void loop() 
{
  // Atribuindo a leitura do sensor como valor das variaveis
  h = dht.getHumidity();
  t = dht.getTemperature();

  // Funções de exibição dos valores
  Serial.println("Temp: " + (String)t + " *C");

  // Funções de exibição dos valores
  Serial.println("Umid: " + (String)h + " %");

  // Pula uma linha por organização
  Serial.println("");
  
  //tempo de espera para execução da próxima leitura
  
  delay(1000);
}
