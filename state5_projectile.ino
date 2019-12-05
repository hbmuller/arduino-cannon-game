bool player1Turn = false;

// Projectile: simulate Projectile and do hittesting
void state5()
{
  // Apply wind and gravity and simulate position
  p_momentum[0] += p_wind / 100;
  p_momentum[1] += P_GRAVITY;
  p_position[0] += p_momentum[0];
  p_position[1] += p_momentum[1];

  // Get ground Y for current X
  float surface = getSurface(p_position[0]);

  display.drawPixel(p_position[0], p_position[1], 1);
  display.display();

  if (p_position[0] >= 15 && p_position[0] <= 23 && p_position[1] >= t_top_player0)
  {
    // Collision with player0: Lose
    flicker();
    game_state = 6;
  }
  else if (p_position[0] >= 105 && p_position[0] <= 113 && p_position[1] >= t_top_player1)
  {
    // Collision with player1: Win
    flicker();
    game_state = 7;
  }
  else if (p_position[1] >= surface && player1Turn == false)
  {
    // No hit for player0. Set marker and prepare for player1.
    p_marker = int(p_position[0]);
    display.clearDisplay();
    drawTerrain();
    drawWind();

    // Random player1 shot
    p_position[0] = 105;
    p_position[1] = t_top_player1 - 2;
    float randomAngle = random(0, 100) / 250 * PI - PI;
    float randomPower = random(0, 100) / 100;
    setMomentum(randomAngle, randomPower);

    delay(1000);
  }
  else if (p_position[1] >= surface && player1Turn == true)
  {
    // No hit for player1. Go back to cannon
    player1Turn = false;
    display.clearDisplay();
    drawWall();
    game_state = 3;
  }

  delay(25);
}
