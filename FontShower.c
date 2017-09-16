#include "Fonts.h"
//--------------------------------------------------------
// Print a letter at (x, y) = top-left corner of the letter
// A letter takes up 5x7 pixels.
// Return the width of the letter in pixels.
int printLetter5x7(char character, int x, int y)
{
  uint8_t* letter = font5x7[character - '!' + 1];

  // Go through the 5 columns of the letter
  for (int col = 0;  col < 5;  col++)
  {
    uint8_t bits = letter[col];
    // Go through the pixels of the letter
    for (int row = 6;  row >= 0;  row--)
    {
      uint8_t pixel = bits & 0x01;
      bits >>= 1;
      setPixel(x + col, 6 + y - row, pixel);
    }
  }
  return PIXEL_PER_CHAR_5x7;
}

void printString5x7(char string_buffer[100], uint16_t stringLength, int cursor_x, int cursor_y)
{
  for (int i = 1;
       i < min(stringLength + 1, 1 + PIXELS_WIDTH / PIXEL_PER_CHAR_5x7);
       i++)
      {
        cursor_x += printLetter5x7(string_buffer[i-1], cursor_x, cursor_y);
      }
}

//--------------------------------------------------------
// Print a letter at (x, y) = top-left corner of the letter
// A letter takes up 3x5 pixels.
int printLetter3x5(char character, int x, int y)
{
  // convert lower case to upper case
//  if ((character >= 'a')  && (character <= 'z'))
//  {
//    character -= 'a' + 'A';
//  }
//  character = toupper(character);
  uint8_t* letter = font3x5[character - '!' + 1];

  // Go through the 3 columns of the letter
  for (int col = 0;  col < 3;  col++)
  {
    uint8_t bits = letter[col];
    // Go through the pixels of the letter
    for (int row = 4;  row >= 0;  row--)
    {
      uint8_t pixel = bits & 0x01;
      bits >>= 1;
      setPixel(x + col, 4 + y - row, pixel);
    }
  }

  return PIXEL_PER_CHAR_3x5;
}

void printString3x5(char string_buffer[100], uint16_t stringLength, int cursor_x, int cursor_y)
{
  for (int i = 1;
       i < min(stringLength + 1, 1 + PIXELS_WIDTH / PIXEL_PER_CHAR_3x5);
       i++)
      {
        cursor_x += printLetter3x5(string_buffer[i-1], cursor_x, cursor_y);
      }
}
