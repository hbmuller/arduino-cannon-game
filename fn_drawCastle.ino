// Bitmap: Castle
const unsigned char B_CASTLE[] PROGMEM = {0x82, 0xd6, 0xfe, 0xaa, 0xaa, 0xfe, 0xee, 0xc6};

// Clears terrain and draws a castle
void drawCastle(int pos)
{
  int surface = int(getSurface(pos));
  display.fillRect(pos - 1, surface - 8, 10, 8, 0);
  display.fillRect(pos - 1, surface, 10, 30, 1);
  display.drawBitmap(pos, surface - 8, B_CASTLE, 8, 8, 1);
}