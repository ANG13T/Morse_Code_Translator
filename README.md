# Morse Code Translator

This projects translates user input (text) from the LCD to morse code indicated by a speaker and 2 LED lights. 

## Materials
- 3 Push Buttons
- 20 - 30 jumper wires
- 5 x 220ohm resistors
- 1 potentiometer
- 2 LED (both different colors)
- 1 piezo speaker
- Arduino Uno
- IC2 LCD 
- Breadboard

## Schematic (excluding LCD)

![design image](https://github.com/angelina-tsuboi/LCD_Visual_Display/blob/main/images/base_design.png)

The CAD I was using didn't have the LCD (I2C). Wiring the LCD should be pretty simple as long as you look over the source code.

## How It Works

Since this project contains many components, I will describe the functionalties of each component individually.

### Push Button Mechanism

 A button contains a sealed mechanism which connects a small metal spring and a wire when it is pressed. This allows electricity to flow through the legs of the button. In order to detect whether the electricity is flowing through the button or not, the Arduino includes digital pins which detect the presence or abscence of voltage. The **digitalRead** function tells your program whether the pin is HIGH (5 volts) or LOW (0 volts). Sometimes circuits include pull up resistors (like in this case) that adjust the voltage that is sensed by digitalRead. For this project, the push buttons are used to interface with the LCD. The left most button is used to move the LCD cursor to the left and the right most button oves the cursor to the right. The push button in between the two buttons changes the letter at the slot the cursor is on. For example, if the cursor is on the letter *A* and the middle button is pressed it will change the letter to *B*.


### LCD Display Functionality

A Liquid Crystal Display or LCD contains many pixels in order to display text and characters onto the screen. In this case, we are controlling a very compact LCD (16 x 2) with only which only uses the color black. The LCD contains liquid crystal sandwiched between glass that reacts with the current applied to display specific characters. In this tutorial, I used a I2C LCD in order to make the wiring and programming easier. For this project, the functionality of the LCD is to view and edit the text that is converted into morse code. This allows you to write your own custom messages!

### Potentiometer Functionality

A potentiometer provides a variable resistance when it is turned. When we turn the knob it controls how much of the current can flow through. This is called a analog value when the output can take any number of values. In this project, I used a potentiometer in order to change the frequency of the rate at which the LEDs lights up and the piezo speaker buzzes. This allows the user to adjust the difficulty of the morse code by changing the speed.


### Piezo Speaker Functionality

A piezo speaker utilizes piezo electic material (material that changes shape when a voltage is applied which induces the base material to vibrate and create sound waves) in order to make a sound. The piezo speaker makes a sound when an electrical current is applied. We can alter the sound frequency the speaker emits by adjusting the amount of electrical current that is applied to the speaker. In this project the piezo speaker emits a high pitched noise to indicate a dot and a lower pitched tone to signify a dash.


### LED Functionality

An LED (short for light emitting diode) contains semiconducters which emits light when a current passes through it. For this project we are using two LEDs which indicates a dot or a dash (red: dot, white: dash).

## Morse Code Algorithm

I typically don't provide an overview of the code, but this project contains complex algorithm which converts letters to morse code values (dots and dashes).


## Completed Project

![project photo](https://github.com/angelina-tsuboi/LCD_Visual_Display/blob/main/images/completed-project.jpg)


