
// Flicker screen helper
void flicker()
{
  for (int i = 0; i < 8; i++)
  {
    display.fillRect(0, 0, S_RIGHT, S_BOTTOM, 2);
    display.display();

    delay(50);
  }
}
