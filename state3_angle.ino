// Angle: Get input from potentiometer and refresh canon
void state3()
{
  // Get angle and redraw cannon
  float ang = float(analogRead(POT_PIN) - 1024) / 2048 * PI;
  drawCannon(ang, true);
  display.display();
  delay(50);

  // Check trigger before next run of the loop
  if (analogRead(TRIGGER_PIN) == HIGH)
  {
    // Save angle and go to "adjust power" phase
    p_angle = ang;
    drawCannon(ang);
    display.drawRect(0, 8, 10, 48, 1);
    game_state++;
  }
}