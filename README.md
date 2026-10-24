# ECE 528/L - Robotics and Embedded Systems with Lab
**CSU Northridge**

**Department of Electrical and Computer Engineering**

## Reflectance Sensor Lab
The Reflectance Sensor lab interfaces with the following:

* User LEDs of the TI MSP432 LaunchPad
* 8-Channel QTRX Sensor Array - [Product Link](https://www.pololu.com/product/3672)

## Overview

The lab introduces the 8-Channel QTRX reflectance sensor array. It is located at the bottom of the robot and uses infrared light to determine the robot's position relative to black line. The reflectance sensor array contains 8 infrared LED and phototransistor pairs that detect changes in the amount of infrared light reflected by the surface underneath it. The infrared LED shines infrared light onto the surface and the light is reflected from the surface. It is then detected by the photoresistor. When the reflectance sensor is under a white surface, it reflects more infrared light while under a black surface, it reflects less infrared light. The MSP432 reads the array and produces an 8-bit binary value. When a sensor is under a black surface, it reads an output of 1, while a white surface reads an output of 0. The main objective of the lab is to initialize and read the reflectance sensor. The robot is moved manually over black tape to observe sensor readings and LED outputs.

## Pre Lab
1. What does a reflectance sensor consist of? How many reflectance sensors are on the QTRX Reflectance Sensor Array? What is its operating voltage? Refer to Pololu’s documentation page of the QTRX Reflectance Sensor Array.

    - The reflectance sensor consists of a dimmable IR emitter coupled with a phototransistor. The QTRX Reflectance Sensor Array has 8 reflectance sensors. The operating voltage is 2.9 V to 5.5 V.

2. Which control pins on the QTRX Reflectance Sensor Array are responsible for enabling the reflectance sensors? What is their default value after powering on the sensor array? List the pin names and the pin numbers used to connect the two control pins. Refer to Pololu’s documentation page of the QTRX Reflectance Sensor Array. 

    - On the QTRX Reflectance Sensor Array CTRL EVEN and CTRL ODD are responsible for enabling the reflectance sensors, the CTRL EVEN is connected to P5.3 while the other is connected to P9.2 on the TI-RSLK MSP432. The default value after powering on the sensor array for the pins are logic HIGH. 

3. Write a void function named P5_0_and_P9_7_Init that takes no arguments and configures the P5.0 and P9.7 pins as output GPIO pins. Initialize the value of the P5.0 and P9.7 pins to zero.

```
void P5_0_and_P9_7_Init()
{
    P5->SEL0 &= ~0x01;
    P5->SEL1 &= ~0x01;
    P5->DIR |= 0x01;
    P5->OUT &= ~0x01;
    P9->SEL0 &= ~0x80;
    P9->SEL1 &= ~0x80;
    P9->DIR |= 0x80;
    P9->OUT &= ~0x80;
}
```

4. Write a void function named Print_Binary that has an input parameter called value_to_convert of type uint8_t. Your function must print an unsigned 8-bit integer in binary representation with an underscore (_) separator after the 4th bit. If the input value is 0, it should print the “Binary: 0000_0000” and return. Include your name in the author section of the code documentation. If you’ve used references (e.g. GeeksforGeeks, StackOverflow, etc.), cite them below.

    - [Result](print_binary.c)

## Components Used:

* MSP432 LaunchPad
* USB-A to Micro-USB cable
* TI-RSLK MAX Chassis 
* 8-Channel QTRX Sensor Array

## Analysis and Results:

The first part of the lab involved placing the Print_binary() function from the pre-lab in the Print_Binary.c source file. The function is used to print the 8-bit values read from the reflectance sensor.

Next, the lab required to implement Reflectance_Sensor_Init and Reflectance_Sensor_Read function. P5.3 and P9.2 were configured as an output GPIO pin while P7.0 - P7.7 are configured as input GPIO pins. P5.3 and P9.2 control even and odd numbered emitters while P7.0 - P7.7 are used to obtain the sensor readings. The Reflectance_Sensor_Read consectuvively reads the reflectance sensor's value by writing to specified registers. It turns on the infrared LEDs and configures P7.0 - P7.7 as outputs. The function also drives P7.0 - P7.7 to active high by setting the bits in the OUT register. It waits for a set amount of time. Then, the sensor values are read using P7->IN and is assigned to a local variable called reflectance_value. Lastly, it turns off the IR LEDs and returns the value of reflect value.

The functions are verified by moving the robot along the black lines and observing the values read from the reflectance sensor on the serial terminal.

The following table is the classification for the robot's position based on the sensor's binary output.

| Line Position | Reflectance Sensor Value |
| --- | --- |
| Center | 00011000 |
| Slightly Left | 00011100 |
| Slightly Right | 00111000 |
| Far Left | 00000001 |
| Far Right | 10000000 |
| T-Intersection | 11111111 |
| Dead End | 00000000 |
| Left Turn | 11111000 |
| Right Turn | 00011111 |

The final task was to implement the function, Detect_Line_Position, which showcases the robot's position relative to a black line by displaying a specific behavior on the LED and RGB LED. It was implemented by using switch case statements that use the value of the reflectance_value. The cases were verified by manually placing the robot on a black line while the LED outputs are observed.

## Known Issues or Limitations
No known issues or limitations.

## Author Contribution
* Michael Sanchez
    * Worked on Pre-Lab questions 2 and 4
    * Worked on the Reflectance_Sensor_Init and Reflectance_Sensor_Read functions
* Gil Gandionco 
    * Worked on Pre-Lab questions 1 and 4
    * Worked on the Detect_Line_Position function.

## References

* MSP432P4xx SimpleLink™ Microcontrollers
Technical Reference Manual
* [QTRX sensor](https://www.pololu.com/product/3672)
