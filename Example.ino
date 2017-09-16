#define PANEL_WIDTH     28  // single Panel width in pixel
#define PANEL_HEIGHT    24 // single Panel height in pixel
#define PANEL_NUMBER     3 // Number of connected Panels

void setup()
{
    setupDotFlipper();
}
bool fill = false;
void loop()
{
  
  fillDisplay(fill);
  fill = !fill;
}
