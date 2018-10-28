// used below link as reference for getting random number in range.
// https://stackoverflow.com/questions/29381843/generate-random-number-in-range-min-max

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MIN 0
#define MAX 126

int random_int(int min, int max){
    return min + rand() % (max+1 - min);
}

char inputChar()
{   char rand_char;
    rand_char = random_int(MIN, MAX);
    while(rand_char > 0 && rand_char < 32){
      rand_char = random_int(MIN, MAX);
    }
    return rand_char;
}

char *inputString()
{
    int i;
    char *string = malloc(6 * sizeof(char));
    char eligible_chars[5] = {'r', 'e', 's', 't', '\0'};
    char rand_char;

    for(i = 0; i < 6; i++){
      rand_char = random_int(0, 5);
      string[i] = eligible_chars[rand_char];
    }
    return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
