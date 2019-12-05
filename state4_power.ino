// Bitmap: last hit marker
const unsigned char B_MARKER[] PROGMEM = {0x81, 0x42, 0x24, 0x99, 0x42, 0x24, 0x18, 0x00};

// Power: Get power value from potentiometer and shoot once the button is released
void state4()
{
  // "Adjust power" phase
  float power = float(analogRead(POT_PIN)) / 1024;
  drawPower(power);
  display.display();
  delay(50);

  // Check if trigger was released before ending loop
  if (digitalRead(TRIGGER_PIN) == LOW)
  {
    // Cannon shot
    flicker();

    // Save power adjustment
    p_power = power;

    // Set projectile momentum
    setMomentum(p_angle, p_power);

    // Set projectile position
    p_position[0] = 19;
    p_position[1] = t_top_player0 - 2;

    // Draw terrain
    display.clearDisplay();
    drawTerrain();
    drawWind();
    display.drawBitmap(p_marker - 4, int(getSurface(p_marker)) - 8, B_MARKER, 8, 8, 1);
    display.display();

    // Go to simulation view
    game_state++;
  }
}