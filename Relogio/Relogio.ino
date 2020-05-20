#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define LCD_LIGHT_PIN A2

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  lcd.begin(16,2); //Inicializa LCD
lcd.clear(); //Limpa o LCD
pinMode(LCD_LIGHT_PIN, OUTPUT);
 digitalWrite(LCD_LIGHT_PIN, HIGH); 
 lcd.display();
}

void loop() {
tmElements_t tm; // declarar comando do rtc
  if (RTC.read(tm)) { // Conferir se nao resetou o tempo
    lcd.setCursor(0,0);
    lcd.print("Hora: ");
    print2digits(tm.Hour);
    lcd.print(":");
    print2digits(tm.Minute);
    lcd.print(":");
    print2digits(tm.Second);
    lcd.setCursor(0,1);  
 
      switch(tm.Wday){ // printar o dia da semana
     case 0:
     lcd.print("Qui   ");
     break;
     case 1:
     lcd.print("Sex   ");
     break;
     case 2:
     lcd.print("Sab   ");
     break;
     case 3:
     lcd.print("Dom   ");
     break;
     case 4:
     lcd.print("Seg   ");
     break;
     case 5:
     lcd.print("Ter   ");
     break;
     case 6:
     lcd.print("Qua   ");
     
     break;}
     
    lcd.print(tm.Day);
     lcd.print('/');
    lcd.print(tm.Month);
     lcd.print('/');
    lcd.print(tmYearToCalendar(tm.Year));
    
  } else {
    if (RTC.chipPresent()) { //Caso precisar rodar SetTime
      lcd.print("Rodar SetTime");
    } else {
      lcd.print("Erro no circuito");
    }
    delay(9000);
  }
  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    lcd.print('0');
  }
  lcd.print(number);
}
