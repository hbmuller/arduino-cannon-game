void setMomentum(float angle, float power)
{
    // Calculate projectile momentum
    float power_final = P_POWER_AMP * power + P_POWER_MIN;
    p_momentum[0] = cos(angle) * power_final;
    p_momentum[1] = sin(angle) * power_final;
}