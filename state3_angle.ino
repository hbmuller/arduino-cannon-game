// Bitmap: Left caret
const unsigned char B_CARET_L[] PROGMEM = {
    0x0c, 0x18, 0x30, 0x60, 0x60, 0x30, 0x18, 0x0c};

// Bitmap: Right caret
const unsigned char B_CARET_R[] PROGMEM = {
    0x30, 0x18, 0x0c, 0x06, 0x06, 0x0c, 0x18, 0x30};

bool refreshedWind = false;

// Angle: Get input from potentiometer and refresh canon
void state3()
{
  // Update and draw wind on first loop of the state
  if (refreshedWind == false)
  {
    int wind = random(-3, 3);

    p_wind = wind / 100;
    refreshedWind = true;

    for (int i = abs(wind); i > 0; i--)
    {
      display.drawBitmap(S_RIGHT - 2 - i * 8, 2, wind < 0 ? B_CARET_L : B_CARET_R, 8, 8, 1);
    }
  }

  // Get angle and redraw cannon
  float ang = float(analogRead(POT_PIN) - 1024) / 2048 * PI;
  drawCannon(ang, true);
  display.display();
  delay(50);

  // Check trigger before next run of the loop

  if (digitalRead(TRIGGER_PIN) == HIGH)
  {
    // Save angle and go to "adjust power" phase
    p_angle = ang;
    drawCannon(ang);
    refreshedWind = false; // Clear before leaving
    display.drawRect(0, 8, 10, 48, 1);
    game_state++;
  }
}
