#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int heigh;
  int width;
  int bombs;
} map;

int* base_map_creation(map value)
{
  int *ptr;
  int pos, size;

  size = value.heigh * value.width;
  ptr = calloc(size, sizeof(int));
  srand(time(NULL));

  for (int i = 0; i < value.bombs; i++)
  {
    pos = rand() % size;
    if (ptr[pos] == 0)
    {
      ptr[pos] = 1;
    }
    else
    {
      i--;
    }
  }
  return ptr;
}

map ask_base_map_value(void)
{
  map temp;
  int holder;

  printf("Map dificulty 0 = hard, 1 = medium, 2 = easy!: ");
  scanf("%d", &holder);

  if (holder == 2)
  {
    temp.heigh = 8;
    temp.width = 8;
    temp.bombs = 10;
  }
  else if (holder == 1)
  {
    temp.heigh = 16;
    temp.width = 16;
    temp.bombs = 40;
  }
  else
  {
    temp.heigh = 16;
    temp.width = 30;
    temp.bombs = 99;
  }
  return temp;
}

void print_map(map value, int* map)
{
  for (int i = 0; i < (value.heigh * value.width); i++)
  {
    printf("%d ", map[i]);
    if (i > 0 && (i + 1) % value.width == 0)
    {
      printf("\n");
    }
  }
}

int main(void)
{
  map base_map_value;
  int* base_map;

  base_map_value = ask_base_map_value();  
  base_map = base_map_creation(base_map_value);

  print_map(base_map_value, base_map);

  return 0;
}