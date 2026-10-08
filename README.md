# ECE 528/L - Robotics and Embedded Systems with Lab
**CSU Northridge**

**Department of Electrical and Computer Engineering**

## Reflectance Sensor Lab
The Reflectance Sensor lab interfaces with the following:

* User LEDs of the TI MSP432 LaunchPad
* 8-Channel QTRX Sensor Array - [Product Link](https://www.pololu.com/product/3672)

## Overview

## Pre Lab
1. What does a reflectance sensor consist of? How many reflectance sensors are on the QTRX Reflectance Sensor Array? What is its operating voltage? Refer to Pololu’s documentation page of the QTRX Reflectance Sensor Array.

    - The reflectance sensor consist of dimmable IR emitter coupled with a phototransistor. The QTRX Reflectance Sensor Array has 8 reflectance sensors. The operating voltage is 2.9 V to 5.5 V.

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

## Analysis and Results:

## Known Issues or Limitations


## Author Contribution


## References

* MSP432P4xx SimpleLink™ Microcontrollers
Technical Reference Manual
* [QTRX sensor](https://www.pololu.com/product/3672)
