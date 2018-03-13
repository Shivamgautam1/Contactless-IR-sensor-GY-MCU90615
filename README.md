# Contactless-IR-sensor-GY-MCU90615
An example code for interfacing Contactless IR sensor GY-MCU90615 with Serial Interface (Non I2C breakouts)

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
