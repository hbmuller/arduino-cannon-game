// Draw power meter for state4
void drawPower(float power)
{
  byte height = int(power * 44);
  byte oldTop = 54 - int(p_power * 44);

  display.fillRect(0, 9, 9, 46, 0);
  display.fillRect(0, 54 - height, 8, height, 1);
  display.drawLine(0, oldTop, 9, oldTop, 2);
}