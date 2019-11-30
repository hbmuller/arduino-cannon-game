// Projectile: simulate Projectile and do hittesting
void state5()
{
  // Apply gravity and simulate position
  p_momentum[1] += P_GRAVITY;
  p_position[0] += p_momentum[0];
  p_position[1] += p_momentum[1];

  // Whistle sound
  int pitchBend = (int)max(0, p_momentum[1] * 10);
  tone(SOUND_PIN, 2000 - pitchBend, 15);

  // Get ground Y for current X
  float surface = getSurface(p_position[0]);

  display.drawPixel(p_position[0], p_position[1], 1);
  display.display();

  if (p_position[0] >= 15 && p_position[0] <= 23 && p_position[1] >= t_top_player)
  {
    // Collision with player: Lose
    flicker();
    game_state = 6;
  }
  else if (p_position[0] >= 105 && p_position[0] <= 113 && p_position[1] >= t_top_enemy)
  {
    // Collision with enemy: Win
    flicker();
    game_state = 7;
  }
  else if (p_position[1] >= surface)
  {
    // No hit. Set marker and back to cannon
    p_marker = int(p_position[0]);
    display.clearDisplay();
    noTone(SOUND_PIN);
    drawWall();
    game_state = 3;
  }

  delay(25);
}