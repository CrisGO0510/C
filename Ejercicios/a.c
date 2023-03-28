#include <stdio.h>

int main(){

  char string[10];

  for (int i = 0; i < 10; i++){
    if (i % 2 == 0){
      string[i] = 219;
    }else{
      string[i] = 82;
    }
  }

  for (int i = 0; i < 10; i++){
    printf("%c", string[i]);
  }

  return 0;
}