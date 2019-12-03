// Bitmap: sword and flag
const unsigned char B_VICTORY[] PROGMEM = {
    0x73, 0xff, 0xff, 0xc2, 0x98, 0x1f, 0x03, 0xed, 0xa4, 0x11, 0x03, 0xe1, 0xc2, 0x06, 0x03, 0xe1, 
    0x5f, 0x09, 0x03, 0xed, 0x20, 0x9b, 0x03, 0xe2, 0x10, 0x53, 0x03, 0xe0, 0x0b, 0xd3, 0x03, 0xe0, 
    0x04, 0x33, 0x03, 0xe0, 0x02, 0x75, 0x03, 0xe0, 0x00, 0xea, 0x03, 0xe0, 0x07, 0x9d, 0x03, 0xe0, 
    0x0c, 0x0e, 0x83, 0xe0, 0x10, 0x47, 0x43, 0xe0, 0x14, 0x23, 0xa3, 0xe0, 0x04, 0x11, 0xd3, 0xe0, 
    0x04, 0x08, 0xeb, 0xe0, 0x04, 0x14, 0x75, 0xe0, 0x04, 0x1a, 0x3a, 0xe0, 0x04, 0x1d, 0x1d, 0x60, 
    0x04, 0x1e, 0x8e, 0xa0, 0x04, 0x1f, 0x47, 0x40, 0x04, 0x1f, 0x23, 0xa0, 0x04, 0x1f, 0x11, 0xd0, 
    0x04, 0x1f, 0x08, 0xe8, 0x04, 0x1f, 0x04, 0x74, 0x04, 0x3f, 0x02, 0x3a, 0x04, 0x5f, 0x09, 0x1d, 
    0x04, 0x8f, 0x10, 0x8d, 0x05, 0x07, 0x20, 0x47, 0x06, 0x03, 0x40, 0x23, 0x04, 0x01, 0x80, 0x1f};

// Victory
void state7()
{
  display.clearDisplay();
  display.drawBitmap(48, 16, B_VICTORY, 32, 32, 1);
  display.display();

  delay(5000);
  game_state = 0;
}