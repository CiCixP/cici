#include "WGCFunc.h"

char input(std::vector<int> side, std::string bank)
{
  int valid_choice = 0;
  char choice = 'a';
  do
  {
    printf("Which animal will you move from the %s side? ((w)olf, (g)oat, (c)abbage,(n)one) ", bank.c_str());
    std::cin >> choice;
    valid_choice = 1;
    if (choice != 'w' && choice != 'g' && choice != 'c' && choice != 'n')
    {
      printf("Please try a different input. \n");
      valid_choice = 0;
    }
    std::vector<char> animal = {'w','g','c'};
    std::vector<std::string> objName = {"wolf","goat","cabbage"};
    for (int i = 0; i < 3; i++)
    {
      if (choice == animal[i] && side[i] == 0)
      {
        
        printf("The %s is not on the %s side of the river. \n", objName[i].c_str(), bank.c_str());
        valid_choice = 0;
      }
    }
  }while(valid_choice == 0);
  return choice;
}

void move(std::vector<int> & From, std::vector<int> & To, char choice)
{
  int number = 3;
  From[number] = 0;
  To[number] = 1;
  if (choice == 'w')
  {
    number = 0;
    printf("Moved wolf: \n");
  }
  if (choice == 'g')
  {
    number = 1;
    printf("Moved goat: \n");
  }
  if (choice == 'c')
  {
    number = 2;
    printf("Moved cabbage: \n");
  }
  From[number] = 0;
  To[number] = 1;
}

void printMoves(std::vector<int> side)
{
  printf("   Left  |  Right \n");
  if (side[0] == 1)
    printf("   wolf  |       \n");
  else
    printf("         |  wolf \n");
  if (side[1] == 1)
    printf("   goat  |       \n");
  else
    printf("         |  goat \n");
  if (side[2] == 1)
    printf(" cabbage |       \n");
  else
    printf("         | cabbage \n");
  if (side[3] == 1)
    printf(" sailor  |        \n");
  else
    printf("         | sailor \n");
  printf("\n");
}

void check(std::vector<int> side)
{
  if (side[3] == 0)
  {
    if (side[1] == 1)
    {
      if (side[2] == 1)
      {
        if (side[0] == 1)
        {
          printf("You lost because the goat ate the cabbage and the wolf ate the goat. \n");
          exit(3);
        }
        printf("You lost because the goat ate the cabbage. \n");
        exit(1);
      }
      else if (side[0] == 1)
      {
        printf("You lost because the wolf ate the goat. \n");
        exit(2);
      }
    }
  }
  
  if (side[0] == 0 && side[1] == 0 && side[2] == 0 && side[3] == 0)
  {
    printf("You win! \n");
    exit(0);
  }
}
