/*******************************************
An Example program for GY-MCU90615
Code Written by Shivam Gautam (www.amritsar.tech)
www.github.com/shivamgautam1
Connections:
Sensor VCC -> Arduino 5V
Sensor GND -> Arduino GND
Sensor Rx  -> Arduino 11
Sensor Tx  -> Arduino 10

Serial port settings:
Set serial monitor baud rate to 57600

Working of my code:
The code utilizes Software Serial library to
communicate with GY-MCU90615. So, that normal
communication sould stay intact within Arduino 
& PC. First, begin serial communication with the sensor at 
115200 bauds(default). Then send instruction HEX commands
to enable continuous Communication (more info at 
http://www.ekt2.com/pdf/412_ARDUINO_INFRARED_THERMOMETER_MODULE.pdf)

Now, in loop section, We check if serial communication
with sensor is established. Then, we take 32 readings
and now check for the starting of the output data by checking
for 0x5A. If found, we increment by +4 & +5 and then 
retrieve the temperature data by the formula
temp = (4thByte | 5thByte)/100 

*******************************************/

#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
unsigned char output[33];
unsigned char need[2];
void setup() {
  Serial.begin(57600);
  while(!Serial){
    ;  
  }
  mySerial.begin(115200);
  mySerial.write(0xA5);
  mySerial.write(0x45);
  mySerial.write(0xEA);
}

void loop() {
  if(mySerial.available()){
    Serial.print("Taking Readings");
    for(int counter=0;counter<=32;counter++){
      output[counter] = (unsigned char)mySerial.read();
      Serial.print(".");
    }
    for(int obj=0;obj<=32;obj++){
      if(output[obj]==0x5A){
        need[0] = output[obj+4];
        need[1] = output[obj+5];
        float temp = (float)(need[0] << 8 | need[1])/100;
        Serial.println();
        Serial.println("Temperature is: ");
        Serial.print(temp);
      }
      else{//No need to do anything}  
    }
    delay(100);
    }
  }
}
