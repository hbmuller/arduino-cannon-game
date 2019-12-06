# Arduino Cannon Game

A small game made with Arduino and a tiny I2C display

<img src="https://imgur.com/cXnjCQl.jpg" alt="Game prototype" width="45%" />
<img src="https://imgur.com/swyzJpl.jpg" alt="Finished game inside case" width="45%" />

A bit more info into it:

- The terrain is generated in the beginning of each match and it is a randomly generated sine wave. I just save the amplitude, angular velocity and initial angle to vars.
- I used Adafruit's graphic lib to draw to the screen.
- The cannon is drawn using some very primitive shapes from the lib (a lot of trigonometry went into it)

See more at:
https://imgur.com/gallery/uBGFM

## Future Plans

I've already done most of what I wanted to do. Only thing left would be:

- Make it 2 players
- Update to latest version of `Adafruit_SSD1306` lib. There have been some breaking changes, so I didn't update. Current version used is `1.1.2`.
- Maybe abstract some of the logic into a library, separating core functionality from the game itself.
