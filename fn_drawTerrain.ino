// Draws the whole terrain, including castles
void drawTerrain()
{
  for (int i = 0; i <= S_RIGHT; i++)
  {
    display.drawLine(i, int(getSurface(i)), i, S_BOTTOM, 1);
  }

  // Player
  drawCastle(15);

  // Enemy
  drawCastle(105);
}