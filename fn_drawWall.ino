// Draws the wall part for the cannon screen
void drawWall()
{
  // Bottom bricks
  display.drawLine(0, C_FLOOR, 127, C_FLOOR, 1);
  for (int i = 15; i < 128; i += 16)
  {
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