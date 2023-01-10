# ArduinoButtonClock
### Description
An Arduino stopwatch that works using interrupts. Current version works with two buttons, but the code can be easilly modified to work with one button.

### Prerequisites
- Arduino Uno or any other microcontroller that uses ATmega328P (or similiar enough for the interupts to work)
- <a href="https://www.arduino.cc/en/software">Arduino IDE</a>
- two buttons
- two 10k ohm resistors
- jump wires
- a breadboard to help with connecting the components

### Schematics
![img](https://github.com/SakRoi/arduinoButtonClock/blob/main/image.png)


### How-to-use
1. Build the above schematic on a breadboard or in an another way.
2. Clone the repository to your computer.
3. Using Arduino IDE, compile and upload ArduinoClock.ino into your Arduino.
4. Give the starting time through the serial monitor, set to 9600 baud rate.
5. Control the stopwatch by using the two buttons.
