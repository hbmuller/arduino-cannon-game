// Bitmap: crosshair
const unsigned char B_CROSSHAIR[] PROGMEM = {0x82, 0x44, 0x00, 0x10, 0x00, 0x44, 0x82, 0x00};

// Refreshes the cannon
void drawCannon(float angle, bool crosshair = false)
{
  display.fillRect(C_CLEAR_X, C_CLEAR_Y, C_CLEAR_SIZE, C_CLEAR_SIZE, 0);

  // Barrel corners
  int barrel_side[2];
  barrel_side[0] = int(cos(angle - PI / 2) * C_RADIUS);
  barrel_side[1] = int(sin(angle - PI / 2) * C_RADIUS);

  // Barrel length
  int barrel_length[2];
  barrel_length[0] = int(cos(angle) * C_LENGTH);
  barrel_length[1] = int(sin(angle) * C_LENGTH);

  // Barrel corners
  int barrel_a[2] = {C_CENTER_X + barrel_side[0], C_CENTER_Y + barrel_side[1]};
  int barrel_b[2] = {C_CENTER_X - barrel_side[0], C_CENTER_Y - barrel_side[1]};
  int barrel_c[2] = {barrel_a[0] + barrel_length[0], barrel_a[1] + barrel_length[1]};
  int barrel_d[2] = {barrel_b[0] + barrel_length[0], barrel_b[1] + barrel_length[1]};

  // Draw cannon
  display.fillTriangle(barrel_a[0], barrel_a[1], barrel_b[0], barrel_b[1], barrel_c[0], barrel_c[1], 1);
  display.fillTriangle(barrel_b[0], barrel_b[1], barrel_c[0], barrel_c[1], barrel_d[0], barrel_d[1], 1);
  display.fillCircle(C_CENTER_X, C_CENTER_Y + 1, C_RADIUS, 1);

  // Fix base
  display.drawRect(C_CENTER_X - C_RADIUS - 1, C_CENTER_Y, C_RADIUS + 17, C_RADIUS + 1, 1);
  display.fillRect(C_CENTER_X - C_RADIUS - 2, C_CENTER_Y + 1, C_RADIUS + 17, C_RADIUS + 1, 0);

  // Draw crosshair
  if (crosshair == true)
  {
    display.drawBitmap(C_CENTER_X + (cos(p_angle) * (C_LENGTH + 15)) - 2, C_CENTER_Y + (sin(p_angle) * (C_LENGTH + 15)) - 3, B_CROSSHAIR, 8, 8, 1);
  }
}
