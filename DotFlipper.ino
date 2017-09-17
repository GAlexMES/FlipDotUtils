#ifndef PANEL_WIDTH
  #define PANEL_WIDTH     28 // single Panel width in pixel
#endif

#ifndef PANEL_HEIGHT
  #define PANEL_HEIGHT     24 // single Panel width in pixel
#endif

#ifndef PANEL_NUMBER
  #define PANEL_NUMBER     1 // single Panel width in pixel
#endif

#ifndef DEBUG_LOG
  #define DEBUG_LOG     false
#endif

#define PIXEL_PER_CHAR_3x5 4
#define PIXEL_PER_CHAR_5x7 6
#define PIXELS_WIDTH (PANEL_WIDTH * PANEL_NUMBER)
#define PIXELS_HEIGHT PANEL_HEIGHT

#define LED_PIN         13

char pixels[PANEL_WIDTH*PANEL_NUMBER][PANEL_HEIGHT];
int px, py;
int dx, dy;
int oldx, oldy;
uint8_t coord_to_row_col[28] = {1,2,3,4,5,6,7,9,10,11,12,13,14,15,17,18,19,20,21,22,23,25,26,27,28,29,30,31};
uint8_t panel_to_bits[8] = {1,2,4,8,16,32,64,128};

bool image[1344] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,false,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,false,false,false,false,true,true,true,true,true,true,true,false,false,false,false,false,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,true,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,false,false,true,true,true,true,true,true,true,true,true,false,false,false,false,true,true,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,true,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,true,true,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,true,true,false,true,true,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,true,true,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,true,true,false,true,true,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,true,true,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,false,false,false,true,true,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,true,true,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,false,false,false,true,true,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,true,true,false,false,false,false,false,true,true,true,false,false,false,false,false,false,false,false,true,true,false,false,false,true,true,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,true,true,false,false,false,false,true,true,true,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,true,true,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,true,true,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,true,true,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,false,true,true,false,false,false,false,false,true,true,true,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,false,false,true,true,false,false,false,false,false,false,false,true,true,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,true,true,true,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,false,false,false,true,true,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,true,true,false,true,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,true,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,true,true,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,true,true,true,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,true,true,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
//--------------------------------------------------------
//--------------------------------------------------------
void setupDotFlipper()
{
  // Serial 1 is the command port
  Serial.begin(115200);
  Serial.print("Setup \r\n");
  
  // Port A, C & L = output
  DDRA = 0xFF;
  DDRC = 0xFF;
  DDRL = 0xFF;
  // Set all pins to LOW
  PORTA = 0x00;
  PORTC = 0x00;
  PORTL = 0x00;
  
  // Required for the various effects
  dx = 1;
  dy = 1;
  px = 0;
  py = 2;
  oldx = 0;
  oldy = 0;

  // initialize the digital pin as an output.
  pinMode(LED_PIN, OUTPUT);     
 }

void setPixel(uint8_t col, uint8_t row, bool on)
{
  if ((col < 0) || (col > ((PANEL_WIDTH * PANEL_NUMBER) - 1)) || (row < 0) || (row > (PANEL_HEIGHT - 1))) return;
  if (pixels[col][row] == on) return;  //saving time on switching pixels already in the correct state
  pixels[col][row] = on;

  // Translate Column to Panel
  uint8_t panel = col/PANEL_WIDTH; 
  col = col - (panel * PANEL_WIDTH);
  // Translate pixel coordinates to row and column address
  // This is necessary because the FP2800A chip skips the
  // addresses 0, 8, 16, 24
  row = coord_to_row_col[row];
  col = coord_to_row_col[col];
  // Translate the panelnumber into correct bits
  panel = panel_to_bits[panel];
  
  // Set row address
  PORTA = (row & 0x1F);
  // Set column address
  PORTC = (col & 0x1F);
  // Set Data signal
  if (on)
    PORTC |= 0x20;
  else
    PORTC &= 0xDF;
    
  // Wait t_SE  
  delayMicroseconds(50);
  
  // Set Enable
  PORTL = (panel & 0xFF);  // Col_Enable panel x
  if (on)
  {
    PORTA |= 0x40;  // Row_Enable_on
//    PORTC |= 0x40;  // Col_Enable
  }
  else
  {
    PORTA |= 0x80;  // Row_Enable_off
//    PORTC |= 0x40;  // Col_Enable
  }
  
  // Give the dots time to flip
  delayMicroseconds(1200);
    
  // Reset Data and Enable lines
  PORTA &= 0x1F;
  PORTC &= 0x1F;
  PORTL = 0x00;
  
  // Wait t_off
  delayMicroseconds(150);
}  

 void fillRect(int x1, int y1, int x2, int y2, bool on)
{
  
  for (int y = y1;  y <= y2;  y++) 
    for (int x = x1;  x <= x2;  x++)
      {
          setPixel(x, y, on);
      }
}

//--------------------------------------------------------


//--------------------------------------------------------
// Fills the display
// black == false -> display will be filled with black
// black == true -> display will be filled in the other color
void fillDisplay(bool black)
{
  Serial.println("Fill display");
  fillRect(0, 0, ((PANEL_WIDTH * PANEL_NUMBER) - 1) , (PANEL_HEIGHT - 1), black);
}
