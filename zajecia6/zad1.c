#include <stdio.h>

union variables {
  int Integer;
  float floatingPoint;
  char Character;
  
};

int main()
{
    union variables vars;
    vars.Integer = 1782;
    
    printf("%d \n", vars.Integer);
    
    vars.floatingPoint = 2.13;
    
    printf("%.2f \n", vars.floatingPoint);
    
    vars.Character = 'w';
    
    printf("%c \n", vars.Character);
}
