
// Flicker screen helper
void flicker()
{
  for (int i = 0; i < 6; i++)
  {
    display.fillRect(0, 0, S_RIGHT, S_BOTTOM, 2);
    display.display();

    tone(SOUND_PIN, random(200, 1500), 10);

    delay(50);
  }

  noTone(SOUND_PIN);
}
