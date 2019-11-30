// ### IMPORTS ###
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*
 * ###################
 * ### GLOBAL VARS ###
 * ###################
*/

// Game phase control
byte game_state = 0;

// Push switch values
const byte TRIGGER_PIN = 2;

// Pot pin (analog)
const byte POT_PIN = 2;

// Sound pin
const byte SOUND_PIN = 4;

// Diplay
Adafruit_SSD1306 display;

// Screen size constants
const byte S_BOTTOM = 63;
const byte S_RIGHT = 127;

// Terrain sine (initial phase, angle step, amplitude and base height)
float t_init;
float t_step;
byte t_height;
byte t_base;
float t_top_player;
float t_top_enemy;

// Projectile constants
const float P_GRAVITY = 0.035;
const float P_POWER_MIN = 0.25;
const float P_POWER_AMP = 1.755;

// Projectile vars
float p_angle;
float p_power;
byte p_marker; // Last hit X position
float p_momentum[2] = {0, 0};
float p_position[2] = {0, 0};

// Cannon constants
const byte C_RADIUS = 8;
const byte C_LENGTH = 25;
const byte C_CENTER_X = 30;
const byte C_CENTER_Y = 45;
const byte C_FLOOR = C_CENTER_Y + 15;

// Cannon redraw area
const byte C_CLEAR_SIZE = byte(sqrt(pow(C_RADIUS, 2) + pow(C_LENGTH, 2))) + C_RADIUS + 2;
const byte C_CLEAR_X = C_CENTER_X - C_RADIUS - 1;
const byte C_CLEAR_Y = C_CENTER_Y - C_CLEAR_SIZE + C_RADIUS;

/*
 * ###########################
 * ### LIFECYCLE FUNCTIONS ###
 * ###########################
 */

void setup()
{
  // Give some time for the display to initialize
  delay(100);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Trigger pin config
  pinMode(TRIGGER_PIN, INPUT);
}

void loop()
{
  // Run game phase
  switch (game_state)
  {
  case 0:
  {
    // Initialize: Simulate terrain
    state0();
  }
  break;
  case 1:
  {
    // Overview: Draw terrain
    state1();
  }
  break;
  case 2:
  {
    // Prepare: blank screen before changing view
    state2();
  }
  break;
  case 3:
  {
    // Angle: Get input from potentiometer and refresh canon
    state3();
  }
  break;
  case 4:
  {
    // Power: Get power value from potentiometer and shoot once the button is released
    state4();
  }
  break;
  case 5:
  {
    // Projectile: simulate Projectile and do hittesting
    state5();
  }
  break;
  case 6:
  {
    // Defeat
    state6();
  }
  break;
  case 7:
  {
    // Victory
    state7();
  }
  break;
  default:
  {
    // Fallback to restart game
    game_state = 0;
  }
  break;
  }
}
