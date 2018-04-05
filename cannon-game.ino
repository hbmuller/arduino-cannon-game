// ### IMPORTS ###
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*
 *  ###############
 *  ### SPRITES ###
 *  ###############
*/
const unsigned char B_CASTLE [] PROGMEM = { 0x82, 0xd6, 0xfe, 0xaa, 0xaa, 0xfe, 0xee, 0xc6 };
const unsigned char B_CROSSHAIR [] PROGMEM = { 0x82, 0x44, 0x00, 0x10, 0x00, 0x44, 0x82, 0x00 };
const unsigned char B_MARKER [] PROGMEM = { 0x81, 0x42, 0x24, 0x99, 0x42, 0x24, 0x18, 0x00 };

const unsigned char B_HAPPY [] PROGMEM = {
  0x00, 0x0f, 0xf0, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x01, 0xf8, 0x1f, 0x80, 0x03, 0xc0, 0x03, 0xc0,
  0x07, 0x00, 0x00, 0xe0, 0x0e, 0x00, 0x00, 0x70, 0x1c, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x1c,
  0x30, 0x38, 0x1c, 0x0c, 0x70, 0x38, 0x1c, 0x0e, 0x60, 0x38, 0x1c, 0x06, 0x60, 0x38, 0x1c, 0x06,
  0xe0, 0x38, 0x1c, 0x07, 0xc0, 0x38, 0x1c, 0x03, 0xc0, 0x38, 0x1c, 0x03, 0xc0, 0x38, 0x1c, 0x03,
  0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc3, 0x00, 0x00, 0xc3, 0xe3, 0x00, 0x00, 0xc7,
  0x63, 0x80, 0x01, 0xc6, 0x61, 0xc0, 0x03, 0x86, 0x70, 0xe0, 0x07, 0x0e, 0x30, 0x78, 0x1e, 0x0c,
  0x38, 0x3f, 0xfc, 0x1c, 0x1c, 0x0f, 0xf0, 0x38, 0x0e, 0x00, 0x00, 0x70, 0x07, 0x00, 0x00, 0xe0,
  0x03, 0xc0, 0x03, 0xc0, 0x01, 0xf8, 0x1f, 0x80, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x0f, 0xf0, 0x00
};
const unsigned char B_SAD [] PROGMEM = {
  0x00, 0x0f, 0xf0, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x01, 0xf8, 0x1f, 0x80, 0x03, 0xc0, 0x03, 0xc0,
  0x07, 0x00, 0x00, 0xe0, 0x0e, 0x00, 0x00, 0x70, 0x1c, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x1c,
  0x30, 0x38, 0x1c, 0x0c, 0x70, 0x38, 0x1c, 0x0e, 0x60, 0x38, 0x1c, 0x06, 0x60, 0x38, 0x1c, 0x06,
  0xe0, 0x38, 0x1c, 0x07, 0xc0, 0x38, 0x1c, 0x03, 0xc0, 0x38, 0x1c, 0x03, 0xc0, 0x38, 0x1c, 0x03,
  0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf0, 0x07,
  0x60, 0x3f, 0xfc, 0x06, 0x60, 0x78, 0x1e, 0x06, 0x70, 0xe0, 0x07, 0x0e, 0x31, 0xc0, 0x03, 0x8c,
  0x38, 0x80, 0x01, 0x1c, 0x1c, 0x00, 0x00, 0x38, 0x0e, 0x00, 0x00, 0x70, 0x07, 0x00, 0x00, 0xe0,
  0x03, 0xc0, 0x03, 0xc0, 0x01, 0xf8, 0x1f, 0x80, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x0f, 0xf0, 0x00
};


/*
 * ###################
 * ### GLOBAL VARS ###
 * ###################
*/

// Game phase control
byte game_phase = 0;

// Push switch values
const byte TRIGGER_PIN = 2;
byte triggerState;
byte lastTriggetState;

// Pot pin (analog)
const byte POT_PIN = 2;

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

// Cannon base coords
const byte C_BASE[] = {C_CENTER_X - 15, C_CENTER_X + 16, C_CENTER_Y, C_CENTER_X + 16, C_CENTER_Y + 15, C_CENTER_X - 25, C_CENTER_Y + 15};

// Cannon redraw area
const byte C_CLEAR_SIZE = byte(sqrt(pow(C_RADIUS, 2) + pow(C_LENGTH, 2))) + C_RADIUS + 2;
const byte C_CLEAR_X = C_CENTER_X - C_RADIUS - 1;
const byte C_CLEAR_Y = C_CENTER_Y - C_CLEAR_SIZE + C_RADIUS;


/*
 * ###############
 * ### METHODS ###
 * ###############
 */

// Refresh push switch values
void updateTrigger() {
  lastTriggetState = triggerState;
  triggerState = digitalRead(2);
}

// Generate terraing data
void createTerrain() {
  randomSeed(analogRead(POT_PIN));
  t_init = (random(360) / 180) * PI;
  t_step = (random(50) / 500) * PI + 0.05;

  t_height = random(12) + 5;
  t_base = S_BOTTOM - 5 - t_height;

  p_angle = PI / 2;
  p_power = -1;
  p_marker = 255;

  // Player and enemy hitbox Y
  t_top_player = getSurface(15) - 8;
  t_top_enemy = getSurface(105) - 8;
}

// Calculate terrain surface for X position
float getSurface(byte pos){
  return sin(t_step * pos + t_init) * t_height + t_base;
}

// Clears terrain and draws a castle
void drawCastle(int pos) {
  int surface = int(getSurface(pos));
  display.fillRect(pos - 1, surface - 8, 10, 8, 0);
  display.fillRect(pos - 1, surface, 10, 30, 1);
  display.drawBitmap(pos, surface - 8, B_CASTLE, 8, 8, 1);
}

// Draws the whole terrain, including castles
void drawTerrain() {
  for (int i=0; i <= S_RIGHT; i++){
    display.drawLine(i, int(getSurface(i)), i, S_BOTTOM, 1);
  }

  // Player
  drawCastle(15);

  // Enemy
  drawCastle(105);
}

// Draws the wall part for the cannon screen
void drawWall() {

  // Bottom bricks
  display.drawLine(0, C_FLOOR, 127, C_FLOOR, 1);
  for(int i = 15; i < 128; i += 16) {
    display.drawLine(i, C_FLOOR, i, S_BOTTOM, 1);
  }

  // Extra bricks
  display.drawRect(111, C_FLOOR - 6, 17, 7, 1);
  display.drawRect(79, C_FLOOR - 6, 17, 7, 1);

  // Cannon base fix part
  display.drawLine(C_CENTER_X - 25, C_FLOOR, C_CENTER_X - 15, C_CENTER_Y, 1);
  display.drawLine(C_CENTER_X - 15, C_CENTER_Y, C_CENTER_X + 15, C_CENTER_Y, 1);
  display.drawLine(C_CENTER_X + 15, C_CENTER_Y, C_CENTER_X + 15, C_FLOOR, 1);
}

// Refreshes the cannon
void drawCannon(float angle, bool crosshair = false) {
  display.fillRect(C_CLEAR_X, C_CLEAR_Y, C_CLEAR_SIZE, C_CLEAR_SIZE, 0);

  // Barrel corners
  int barrel_side[2];
  barrel_side[0] = int(cos(angle - PI / 2) * C_RADIUS);
  barrel_side[1] = int(sin(angle - PI / 2) * C_RADIUS);

  // Barrel length
  int barrel_length[2];
  barrel_length[0] = int(cos(angle) * C_LENGTH);
  barrel_length[1] = int(sin(angle) * C_LENGTH);

  // Barrel corners
  byte barrel_a[2] = {C_CENTER_X + barrel_side[0], C_CENTER_Y + barrel_side[1]};
  byte barrel_b[2] = {C_CENTER_X - barrel_side[0], C_CENTER_Y - barrel_side[1]};
  byte barrel_c[2] = {barrel_a[0] + barrel_length[0], barrel_a[1] + barrel_length[1]};
  byte barrel_d[2] = {barrel_b[0] + barrel_length[0], barrel_b[1] + barrel_length[1]};

  // Draw cannon
  display.fillTriangle(barrel_a[0], barrel_a[1], barrel_b[0], barrel_b[1], barrel_c[0], barrel_c[1], 1);
  display.fillTriangle(barrel_b[0], barrel_b[1], barrel_c[0], barrel_c[1], barrel_d[0], barrel_d[1], 1);
  display.fillCircle(C_CENTER_X, C_CENTER_Y + 1, C_RADIUS, 1);

  // Fix base
  display.drawRect(C_CENTER_X - C_RADIUS - 1, C_CENTER_Y, C_RADIUS + 17, C_RADIUS + 1, 1);
  display.fillRect(C_CENTER_X - C_RADIUS - 2, C_CENTER_Y + 1, C_RADIUS + 17, C_RADIUS + 1, 0);

  // Draw crosshair
  if(crosshair == true) {
    display.drawBitmap(C_CENTER_X + (cos(p_angle) * (C_LENGTH + 15)) - 2, C_CENTER_Y + (sin(p_angle) * (C_LENGTH + 15)) - 3, B_CROSSHAIR, 8, 8, 1);
  }
}

// Draw power meter phase
void drawPower(float power) {
  byte height = int(power * 44);
  byte oldTop = 54 - int(p_power * 44);

  display.fillRect(0, 9, 9, 46, 0);
  display.fillRect(0, 54 - height, 8, height, 1);
  display.drawLine(0, oldTop, 9, oldTop, 2);
}

// Flicker screen helper
void flicker(){
  for(int i = 0; i < 4; i++){
    display.fillRect(0, 0, S_RIGHT, S_BOTTOM, 2);
    display.display();
    delay(50);
  }
}

void setup() {
  // Give some time for the display to initialize
  delay(100);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Trigger pin config
  pinMode(TRIGGER_PIN, INPUT);
}

void loop() {
  // Run game phase
  switch (game_phase) {
    case 0: {
        // Simulate terrain
        createTerrain();
        game_phase++;
      }
      break;
    case 1: {
        // Draw terrain
        display.clearDisplay();
        drawTerrain();
        display.display();
        game_phase++;
      }
      break;
    case 2: {
        // Wait for button to be pushed
        updateTrigger();
        if(triggerState == HIGH && lastTriggetState == LOW) {
          // Button pushed: clear screen
          display.clearDisplay();
          display.display();
        } else if(triggerState == LOW && lastTriggetState == HIGH) {
          // Button released, prepare display and go to cannon screen
          display.clearDisplay();
          drawWall();
          game_phase++;
        }
        delay(50);
      }
      break;
    case 3: {
        // Get angle and redraw cannon
        float ang = float(analogRead(POT_PIN) - 1024) / 2048 * PI;
        drawCannon(ang, true);
        display.display();
        delay(50);

        // Check trigger before next run of the loop
        updateTrigger();
        if(triggerState == HIGH) {
          // Save angle and go to "adjust power" phase
          p_angle = ang;
          drawCannon(ang);
          display.drawRect(0, 8, 10, 48, 1);
          game_phase++;
        }
      }
      break;
    case 4: {
        // "Adjust power" phase
        float power = float(analogRead(POT_PIN)) / 1024;
        drawPower(power);
        display.display();
        delay(50);

        // Check if trigger was released before ending loop
        updateTrigger();
        if(triggerState == LOW) {
          // Cannon shot
          flicker();

          // Save power adjustment
          p_power = power;

          // Calculate projectile momentum
          float power_final = P_POWER_AMP * p_power + P_POWER_MIN;
          p_momentum[0] = cos(p_angle) * power_final;
          p_momentum[1] = sin(p_angle) * power_final;

          // Set projectile position
          p_position[0] = 19;
          p_position[1] = getSurface(15) - 10;

          // Draw terrain
          display.clearDisplay();
          drawTerrain();
          display.drawBitmap(p_marker - 4, int(getSurface(p_marker)) - 8, B_MARKER, 8, 8, 1);
          display.display();

          // Go to simulation view
          game_phase++;
        }
      }
      break;
    case 5: {
        // Apply gravity and simulate position
        p_momentum[1] += P_GRAVITY;
        p_position[0] += p_momentum[0];
        p_position[1] += p_momentum[1];

        // Get ground Y for current X
        float surface = getSurface(p_position[0]);


        display.drawPixel(p_position[0], p_position[1], 1);
        display.display();

        if(p_position[0] >= 15 && p_position[0] <= 23 && p_position[1] >= t_top_player) {
          // Collision with player: Lose
          flicker();
          game_phase = 6;
      } else if(p_position[0] >= 105 && p_position[0] <= 113 && p_position[1] >= t_top_enemy) {
          // Collision with enemy: Win
          flicker();
          game_phase = 7;
        } else if(p_position[1] >= surface) {
          // No hit. Set marker and back to cannon
          p_marker = int(p_position[0]);
          display.clearDisplay();
          drawWall();
          game_phase = 3;
        }

        delay(25);
      }
      break;

    case 6: {
        // Lose
        display.clearDisplay();
        display.drawBitmap(48, 16, B_SAD, 32, 32, 1);
        display.display();

        game_phase = 8;
      }
      break;
    case 7: {
        // Win
        display.clearDisplay();
        display.drawBitmap(48, 16, B_HAPPY, 32, 32, 1);
        display.display();

        game_phase = 8;
      }
      break;
    case 8: {
        // Wait before restarting
        delay(5000);
        game_phase = 0;
      }
      break;
    default: {
        // Fallback to restart game
        game_phase = 0;
      }
      break;
  }
}
