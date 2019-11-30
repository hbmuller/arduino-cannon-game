bool holding = false;

// Prepare: blank screen before changing view
void state2()
{
  // Wait for button to be pushed
  byte triggerState = digitalRead(TRIGGER_PIN);

  if (triggerState == HIGH && holding == false)
  {
    // Button pushed: clear screen
    display.clearDisplay();
    display.display();

    holding = true;
  }
  else if (triggerState == LOW && holding == true)
  {
    // Button released, prepare display and go to cannon screen
    display.clearDisplay();
    drawWall();
    game_state++;

    holding = false;
  }
  delay(50);
}