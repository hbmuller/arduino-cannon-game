// Generate terrain data
void createTerrain()
{
  randomSeed(analogRead(POT_PIN));
  t_init = (random(360) / 180) * PI;
  t_step = (random(50) / 500) * PI + 0.05;

  t_height = random(12) + 5;
  t_base = S_BOTTOM - 5 - t_height;

  p_angle = PI / 2;
  p_power = -1;
  p_marker = 255;

  // Player and enemy hitbox Y
  t_top_player = getSurface(15) - 8;
  t_top_enemy = getSurface(105) - 8;
}