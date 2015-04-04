#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define SENSOR_NUMBER 0
#define DEBUG 0
#define SERVER_ADDRESS "HOST0"

void setup(){
  Serial.begin(115200);
  #ifdef DEBUG=1
  while(!Serial);
  #endif 
  
  pinMode(TEMP_PIN,INPUT);
  
  Mirf.cePin = A4;
  Mirf.csnPin = A5;
  
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  
  
  //Configure reciving address.  
  Mirf.setRADDR((byte *)"serv1");
  Mirf.setTADDR((byte *)"serv1");
  
  //configure auto ack
  //configure power level
  //configure data rate
  //configure number of retries
  
  //Set the payload length
  Mirf.payload = sizeof(int);
  
  
  //set channel 
  //Mirf.channel = 10;
   
  Mirf.config();
  
  Serial.println("Beginning ... "); 
}

void loop(){
  //unsigned long time = millis();
  uint8_t adc_value = analogRead(TEMP_PIN);
  Serial.print("adc value:");
  Serial.println(adc_value);
  

  
  Mirf.powerUpRx();

  Mirf.send(&adc_value);
  
  while(Mirf.isSending()){
  }
  Serial.println("Finished sending");
  /*delay(10);
  while(!Mirf.dataReady()){
    //Serial.println("Waiting");
    if ( ( millis() - time ) > 1000 ) {
      Serial.println("Timeout on response from server!");
      return;
    }
  }
  
  Mirf.getData((byte *) &time);
  
  Serial.print("Ping: ");
  Serial.println((millis() - time));
  
  delay(1000);
  */
} 
  
  
  
