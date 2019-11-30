// Calculates ground height for X position
float getSurface(byte pos)
{
  return sin(t_step * pos + t_init) * t_height + t_base;
}