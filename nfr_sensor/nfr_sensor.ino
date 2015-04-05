#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define SENSOR_NUMBER 1

uint8_t SENSOR_ADDR[6][5] = {{231,231,231,231,231},{194,194,194,194,194},{194,194,194,194,195},{194,194,194,194,196},{194,194,194,194,197},{194,194,194,194,198}};

void setup(){
  Serial.begin(115200);
  
  pinMode(TEMP_PIN,INPUT);
  
  Mirf.cePin = A4;
  Mirf.csnPin = A5;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  
  //Configure reciving address.  
  Mirf.setRADDR(SENSOR_ADDR[SENSOR_NUMBER]);
  Mirf.setTADDR(SENSOR_ADDR[SENSOR_NUMBER]);
  
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
  int adc_value = analogRead(TEMP_PIN);
  Serial.print("adc value:");
  Serial.println(adc_value);
  uint8_t buffer[2];
  buffer[0] = (adc_value >> 8);
  buffer[1] = (adc_value & 0b11111111);
  
  //Mirf.printRegisterDetails();
  
  Mirf.powerUpRx();
  
  Mirf.send(buffer);
  
  //check for TX_DS to verify ACK
  
  
  while(Mirf.isSending()){
  }
  //Serial.println("Finished sending");
} 
  
  
  
