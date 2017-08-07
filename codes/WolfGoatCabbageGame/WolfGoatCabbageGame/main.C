#include "WGCFunc.h"

int main(int argc, const char * argv[]) {
  printf("Welcome to the Wolf, Goat, and Cabbage Game! \n");
  printf("A sailor must get the wolf, goat, and cabbage \n");
  printf(" from the left side to the right side of the river. \n");
  printf("If the wolf and goat are on the same side \n");
  printf(" or the goat and cabbage are on the same side \n");
  printf(" without the sailor, the game is over. \n\n");

  std::vector<int> LB = {1, 1, 1, 1};
  std::vector<int> RB = {0, 0, 0, 0};
  printMoves(LB);
  do
  {
    char left = input(LB,"left");
    move(LB, RB, left);
    printMoves(LB);
    check(LB);
    check(RB);
    
    char right = input(RB, "right");
    move(RB, LB, right);
    printMoves(LB);
    check(LB);
    check(RB);
    
  }while(1);

  return 0;
}
