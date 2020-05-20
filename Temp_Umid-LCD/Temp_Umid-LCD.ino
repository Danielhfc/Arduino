//Programa : Temperatura e umidade com o DHT11 e LCD 16x2
//Autor : FILIPEFLOP
 
#include <LiquidCrystal.h> //Carrega a biblioteca LCD
#include <dht.h> //Carrega a biblioteca DHT
 #define LCD_LIGHT_PIN A2
//Define a ligação ao pino de dados do sensor
#define DHT22_PIN A3
 
dht DHT;
 
//Define os pinos que serão ligados ao LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

struct
{
  uint32_t total;
  uint32_t ok;
  uint32_t crc_error;
  uint32_t time_out;
  uint32_t connect;
  uint32_t ack_l;
  uint32_t ack_h;
  uint32_t unknown;
} stat = { 0, 0, 0, 0, 0, 0, 0, 0};
 
//Array simbolo grau
byte grau[8] ={ B00001100,
                B00010010,
                B00010010,
                B00001100,
                B00000000,
                B00000000,
                B00000000,
                B00000000,};
 
void setup()
{
Serial.begin(115200); //Inicializa a serial
lcd.begin(16,2); //Inicializa LCD
lcd.clear(); //Limpa o LCD
//Cria o caractere customizado com o simbolo do grau
lcd.createChar(0, grau);
pinMode(LCD_LIGHT_PIN, OUTPUT);
 digitalWrite(LCD_LIGHT_PIN, HIGH); 
 lcd.display();
}
 
void loop()
{
  uint32_t start = micros();
  int chk = DHT.read22(DHT22_PIN);
  uint32_t stop = micros();
float h = DHT.humidity; //Le o valor da umidade
float t = DHT.temperature; //Le o valor da temperatura
lcd.setCursor(0,0);
lcd.print("Temp : ");
lcd.print(" ");
lcd.setCursor(7,0);
lcd.print(t);
lcd.setCursor(12,0);
 
//Mostra o simbolo do grau formado pelo array
lcd.write((byte)0);
 
//Mostra o simbolo do grau quadrado
//lcd.print((char)223);
 
lcd.setCursor(0,1);
lcd.print("Umid : ");
lcd.print(" ");
lcd.setCursor(7,1);
lcd.print(h);
lcd.setCursor(12,1);
lcd.print("%");
//Intervalo recomendado para leitura do sensor
delay(2000);
}
