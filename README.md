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

- Put it into a proper casing
- Make it 2 players
- Move into a graphic library with a smaller footprint (maybe [U8x8](https://github.com/olikraus/u8g2/wiki/u8x8reference), not sure though)
- Add some text and nicer graphics
- Refactor the code a bit:
  - Move some vars into local scope, saving some global memory
  - Maybe move the rendering functions into a separate library
  - Keep constant clock (`delay`) among all _game phases_
  - Improve performance on the math parts
