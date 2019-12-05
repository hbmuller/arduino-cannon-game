// Bitmap: Left caret
const unsigned char B_CARET_L[] PROGMEM = {
    0x0c, 0x18, 0x30, 0x60, 0x60, 0x30, 0x18, 0x0c};

// Bitmap: Right caret
const unsigned char B_CARET_R[] PROGMEM = {
    0x30, 0x18, 0x0c, 0x06, 0x06, 0x0c, 0x18, 0x30};

void drawWind()
{
    for (int i = abs(p_wind); i > 0; i--)
    {
        display.drawBitmap(S_RIGHT - 4 - i * 6, 2, p_wind < 0 ? B_CARET_L : B_CARET_R, 8, 8, 1);
    }
}
