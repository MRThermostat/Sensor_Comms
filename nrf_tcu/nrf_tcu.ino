#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define SENSOR0 "SENS0"
#define SENSOR1 "SENS1"
#define SENSOR2 "2"
#define SENSOR3 "3"
#define SENSOR4 "4"
#define SENSOR5 "5"

void setup(){
  Serial.begin(115200);
  //while(!Serial);
  /*
   * Set the SPI Driver.
   */
  Mirf.cePin = A4;
  Mirf.csnPin = A5;
  Mirf.spi = &MirfHardwareSpi;
  
  /*
   * Setup pins / SPI.
   */
   
  Mirf.init();
  
  /*
   * Configure reciving address.
   */
   
  Mirf.setRADDR((byte *)"serv1");
  //All data pipes enabled
  //All data pipes enabled

/*

  Mirf.ceLow();
  Mirf.writeRegister(RX_ADDR_P0,(byte*)SENSOR0,5);
  Mirf.ceHi();
  
  Mirf.ceLow();
  Mirf.writeRegister(RX_ADDR_P1,(byte*)SENSOR1,5);
  Mirf.ceHi();
  
  Mirf.ceLow();
  Mirf.writeRegister(RX_ADDR_P2,(byte*)SENSOR2,1);
  Mirf.ceHi();
  Mirf.ceLow();
  Mirf.writeRegister(RX_ADDR_P3,(byte*)SENSOR3,1);
  Mirf.ceHi();
  Mirf.ceLow();
  Mirf.writeRegister(RX_ADDR_P4,(byte*)SENSOR4,1);
  Mirf.ceHi();
  Mirf.ceLow();
  Mirf.writeRegister(RX_ADDR_P5,(byte*)SENSOR5,1);
  Mirf.ceHi();
  *//*
  uint8_t temp[5];
  Mirf.readRegister(10, temp, 5);
  Serial.print("pipe0:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Serial.println((char)temp[4]);
  Mirf.readRegister(11, temp, 5);
  Serial.print("pipe1:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Serial.println((char)temp[4]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe2:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(12, temp, 1);
  Serial.println(temp[0]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe3:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(13, temp, 1);
  Serial.println(temp[0]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe4:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(14, temp, 1);
  Serial.println(temp[0]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe5:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(15, temp, 1);
  Serial.println(temp[0]);
  */
  /*
   * Set the payload length to sizeof(unsigned long) the
   * return type of millis().
   *
   * NB: payload on client and server must be the same.
   */
   
  Mirf.payload = sizeof(int);
  
  /*
   * Write channel and payload config then power up reciver.
   */
   
  Mirf.config();
  
  Serial.println("Listening..."); 
}

void loop(){
  /*
   * A buffer to store the data.
   */
    uint8_t temp[5];
  Mirf.readRegister(10, temp, 5);
  Serial.print("pipe0:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Serial.println((char)temp[4]);
  Mirf.readRegister(11, temp, 5);
  Serial.print("pipe1:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Serial.println((char)temp[4]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe2:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(12, temp, 1);
  Serial.println((char)temp[0]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe3:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(13, temp, 1);
  Serial.println((char)temp[0]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe4:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(14, temp, 1);
  Serial.println((char)temp[0]);
  Mirf.readRegister(11, temp, 4);
  Serial.print("pipe5:");
  Serial.print((char)temp[0]);
  Serial.print((char)temp[1]);
  Serial.print((char)temp[2]);
  Serial.print((char)temp[3]);
  Mirf.readRegister(15, temp, 1);
  Serial.println((char)temp[0]);
  
  
  Mirf.readRegister(EN_RXADDR,temp, 1);
  Serial.print("enabled pipes:");
  Serial.println(temp[0]);
  Mirf.readRegister(EN_AA,temp, 1);
  Serial.print("enabled auto ack:");
  Serial.println(temp[0]);
  Mirf.readRegister(STATUS,temp, 1);
  Serial.print("status:");
  Serial.println(temp[0]);
  
  Mirf.readRegister(RX_PW_P0,temp, 1);
  Serial.print("pipe 0 width:");
  Serial.println(temp[0]);
  Mirf.readRegister(RX_PW_P2,temp, 1);
  Serial.print("pipe 1 width:");
  Serial.println(temp[0]);
  Mirf.readRegister(RX_PW_P2,temp, 1);
  Serial.print("pipe 2 width:");
  Serial.println(temp[0]);
  Mirf.readRegister(RX_PW_P3,temp, 1);
  Serial.print("pipe 3 width:");
  Serial.println(temp[0]);
  Mirf.readRegister(RX_PW_P4,temp, 1);
  Serial.print("pipe 4 width:");
  Serial.println(temp[0]);
  Mirf.readRegister(RX_PW_P5,temp, 1);
  Serial.print("pipe 5 width:");
  Serial.println(temp[0]);
  
  Mirf.readRegister(FIFO_STATUS,temp, 1);
  Serial.print("fifo status:");
  Serial.println(temp[0]);
   
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
    int adc_value = data[1];
    adc_value = adc_value << 8;
    adc_value = adc_value | data[0];
    
    Serial.print("adc sensor ");
    Serial.print(source);
    Serial.print(":");
    Serial.println(adc_value);
    
    
    /*
     * Set the send address.
     */
     
     
    //Mirf.setTADDR((byte *)"clie1");
    
    /*
     * Send the data back to the client.
     */
     
    //Mirf.send(data);
    
    /*
     * Wait untill sending has finished
     *
     * NB: isSending returns the chip to receving after returning true.
     */
      
    //Serial.println("Reply sent.");
  }
}
