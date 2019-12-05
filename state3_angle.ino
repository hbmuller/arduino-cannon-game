bool refreshedWind = false;

// Angle: Get input from potentiometer and refresh canon
void state3()
{
  // Update and draw wind on first loop of the state
  if (refreshedWind == false)
  {
    p_wind = random(-3, 3);
    refreshedWind = true;

    drawWind();
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
