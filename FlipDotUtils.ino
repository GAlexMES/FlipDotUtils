#define PANEL_WIDTH     28  // single Panel width in pixel
#define PANEL_HEIGHT    24 // single Panel height in pixel
#define PANEL_NUMBER     3 // Number of connected Panels

#define USE_SNAKE // to use the snake gane
void setup()
{
    setupDotFlipper();
    fillDisplay(true);
    fillDisplay(false);
    setupSnake();
}

void loop()
{
   loopSnake();
   delay(1000);
}
