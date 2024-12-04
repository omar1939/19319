
#include <SoftwareSerial.h> ;
SoftwareSerial sim(10, 11);  //tx is pin 10 while rx is pin 11
int _timeout;
String _buffer;
String number = "+201281504523"; //-> change with your number






int ldr = 8;
int x;



int sensor_pin = A0;

#include "DHT.h"
#define DHTPIN 4  
#define DHTTYPE DHT22 

float temperature = 0.0;
float humidity = 0.0;
DHT dht(DHTPIN, DHTTYPE);


void setup()
{


  Serial.begin(9600);
  _buffer.reserve(50);
  Serial.println("System Started...");
  sim.begin(9600);
 




  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);

  pinMode(8, INPUT);


 dht.begin();
 




}

void loop()
{
  int sensor_data = analogRead(sensor_pin);

  x = analogRead(8);


  temperature = dht.readTemperature();
humidity = dht.readHumidity();




Serial.print(sensor_data/10);
Serial.print(",");
Serial.print(temperature);
Serial.print(",");
Serial.print(humidity);
Serial.print(",");
Serial.print(x/10);
Serial.println(",");






if (sensor_data < 96)
  {
   SendMessage1();
   delay(3000);
    callNumber();
    delay(5000);

  }



if (temperature > 24)
  {
   SendMessage2();
   delay(3000);
    callNumber();
    delay(5000);


  }



if ( humidity > 57)
  {
   SendMessage3();
   delay(3000);
    callNumber();
    delay(5000);


  }


/*if ( x > 590)
  {
   SendMessage4();
   delay(3000);
    callNumber();
    delay(5000);



  }
*/

  delay(500);



}
