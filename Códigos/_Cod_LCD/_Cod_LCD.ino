
//Código de sensor de temperatura DHT com LCD 16x2
//ESP32 ou ESP8266
//Projeto que lê a temperatura e umidade pelo sensor DTH22/11 do ambiente e exibe no display LCD 16x2

// ==Bibliotecas Utilizadas==
//LiquidCrystal: display LCD 16x2
#include <LiquidCrystal_I2C.h>
//DHT:  sensor de temperatura e umidade para ESPs
#include <DHTesp.h>

// ==Declaração de Variáveis==
//Váriaveis do sensor DHT contendo as leituras
float t; // Temperatura
float h; // Umidade

//Váriaveis do LCD contendo o número de colunas e linhas do display(16x2)
int lcdColumns = 16;
int lcdRows = 2;

// ==Instância de Objetos Incluídos==
//Instância do sensor DHT22/11
DHTesp dht;

//  Instância do LCD 16x2
// biblioteca nome_do_objeto(resoluçãoLCD, comprimento(colunas), largura(linhas))
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

//Início da programação
//Inicializando os periféricos
void setup() 
{
  //Inicialização do LCD e set da luz de fundo
  lcd.init ();
  lcd.backlight();
  
  // Inicializando o sensor DHT
  // objeto.função_iniciar(Pino de entrada, DHTesp::versão_sensor);
   dht.setup(4, DHTesp::DHT22);
}

//Codificação propriamente dita
void loop() 
{
  // Atribuindo a leitura do sensor como valor das variaveis
  h = dht.getHumidity();
  t = dht.getTemperature();

  // Limpar o LCD para a próxima leitura
  lcd.clear();

  // (nota: a linha 1 é a segunda linha, pois a contagem começa com 0):
  // defina o cursor para a coluna 0, linha 0
  lcd.setCursor(0, 0);
  
  //funções de exibição dos valores
  lcd.print("Temp: " + (String)t + " *C");//linha temperatura
  
  // defina o cursor para a coluna 0, linha 1
  lcd.setCursor(0, 1);
  
  //funções de exibição dos valores
  lcd.print("Umid: " + (String)h + " %");//linha umidade
  
  //tempo de espera para execução da próxima leitura
  delay(5000);
}
