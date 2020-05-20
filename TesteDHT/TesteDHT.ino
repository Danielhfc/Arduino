#include <dht.h>
 dht DHT;
#define DHT22_PIN A5 // pino que estamos conectado

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
} stat = { 0,0,0,0,0,0,0,0};
 
void setup() 
{
  Serial.begin(115200);
  Serial.println("DHTxx test!");

}
 
void loop() 
{
// DISPLAY DATA
    Serial.print(DHT.humidity, 1);
    Serial.print(",\t");
    Serial.print(DHT.temperature, 1);
    Serial.print(",\t");
    Serial.println();

    delay(3000);
}
