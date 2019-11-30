# Arduino Cannon Game

A small game made with Arduino and a tiny I2C display

![](https://i.imgur.com/QSWL7rN.jpg)

A bit more info into it:

- The terrain is generated in the beginning of each match and it is a randomly generated sine wave. I just save the amplitude, angular velocity and initial angle to vars.
- I used Adafruit's graphic lib to draw to the screen
- The cannon is drawn using some very primitive shapes from the lib (a lot of trigonometry went into it)

See more at:
https://imgur.com/gallery/uBGFM

## Future Plans

These are some stuff I mean to update/upgrade in the future

- Make it 2 players
- Add some text and nicer graphics
