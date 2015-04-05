#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup(){
  Serial.begin(115200);
  
  /*
   * Set the SPI Driver.
   */
  Mirf.cePin = A4;
  Mirf.csnPin = A5;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  
  //Configure reciving address.
  //using default addresses 

  //set payload length 
  Mirf.payload = sizeof(int);
  
  //configure auto ack
  
  
  //configure power level
  
  
  //configure data rate
  
  
  //configure number of retries
  
  
  //set channel 
  //Mirf.channel = 10;
   
  Mirf.config();
}



void loop(){
  /*
   * A buffer to store the data.
   */
   
  uint8_t data[Mirf.payload];
  
  /*
   * If a packet has been recived.
   *
   * isSending also restores listening mode when it 
   * transitions from true to false.
   */
   
  if(!Mirf.isSending() && Mirf.dataReady()){
    Serial.println("Got packet");
    
    /*
     * Get load the packet into the buffer.
     */
    uint8_t source = ((Mirf.getStatus() & 0b00001110) >> 1);
    Mirf.getData(data);
    int adc_value = data[0];
    adc_value = adc_value << 8;
    adc_value = adc_value | data[1];
    
    Serial.print("adc sensor ");
    Serial.print(source);
    Serial.print(":");
    Serial.println(adc_value);
    
  }else{
     //Mirf.printRegisterDetails(); 
  }
}
