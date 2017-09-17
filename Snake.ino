#ifdef USE_SNAKE
char snake[PANEL_WIDTH*PANEL_NUMBER][PANEL_HEIGHT][2];
uint8_t tail[] ={(PANEL_WIDTH*PANEL_NUMBER)/2,PANEL_HEIGHT/2};
uint8_t head[2];
uint8_t snack[2];

enum DIRECTION {RIGHT,DOWN,LEFT,UP};
DIRECTION testWay[] = {RIGHT,UP,RIGHT,UP,UP,UP,LEFT,UP,RIGHT,RIGHT,DOWN,DOWN};

int loopCount = 0;
bool game_over = false;
DIRECTION lastDirection = RIGHT;

void setupSnake()
{
  randomSeed(analogRead(0));
  for(int x = 0 ;x<PANEL_WIDTH*PANEL_NUMBER;++x)
  {
    for(int y = 0 ;y<PANEL_HEIGHT;++y)
    {
      snake[x][y][0]=-1;
      snake[x][y][1]=-1;    
    }
  }
  
  int i=0;
  for(;i<3;++i)
  {
      snake[tail[0]+i][tail[1]][0]=tail[0]+i+1;
      snake[tail[0]+i][tail[1]][1]=tail[1];
      setPixel(tail[0]+i,tail[1],true);
  }
  head[0] = tail[0]+i-1;
  head[1] = tail[1];

  createSnack();
}

void createSnack(){
  do{
    snack[0] = random(PANEL_WIDTH*PANEL_NUMBER);
    snack[1] = random(PANEL_HEIGHT);
  }while(snake[snack[0]][snack[1]][0] != -1);
  setPixel(snack[0],snack[1],true);
}

void loopSnake(){ 
  if(game_over){
    gameOver();
    return;
  } 

  if(loopCount<12){
    lastDirection = testWay[loopCount];
  }

  calcNextHead();
  if(head[0] == snack[0] && head[1]== snack[1]){
    createSnack();
  }else{
    setPixel(tail[0],tail[1],false);
    int oldTailx = tail[0];
    int oldTaily = tail[1];
    tail[0] = snake[oldTailx][oldTaily][0];
    snake[oldTailx][oldTaily][0] = -1;
    tail[1] = snake[oldTailx][oldTaily][1];
    snake[oldTailx][oldTaily][1] = -1;
  }

  if(head[0] >= PANEL_WIDTH*PANEL_NUMBER || head[0] <0){
    gameOver();
  }else if( head[1] >= PANEL_HEIGHT || head[1]<0){
    gameOver();
  }else if(snake[head[0]][head[1]][0] != -1){
    gameOver();
  }else{
    setPixel(head[0],head[1],true);
  }
  loopCount++;
}

void gameOver(){
  game_over=true;
  fillDisplay(true);
}

void calcNextHead(){
   switch(lastDirection){
    case RIGHT:
      snake[head[0]][head[1]][0]=head[0]+1;
      snake[head[0]][head[1]][1]=head[1];
      head[0] = head[0]+1;
      break;
    case DOWN:
      snake[head[0]][head[1]][0]=head[0];
      snake[head[0]][head[1]][1]=head[1]+1;
      head[1] = head[1]+1;
      break;
    case LEFT:
      snake[head[0]][head[1]][0]=head[0]-1;
      snake[head[0]][head[1]][1]=head[1];
      head[0] = head[0]-1;
      break;
    case UP:
      snake[head[0]][head[1]][0]=head[0];
      snake[head[0]][head[1]][1]=head[1]-1;
      head[1] = head[1]-1;
      break;
  }
}
#endif
