#include <cs50.h>
#include <stdio.h>

int main(void)

{
int  a = 28;
int  b = 50;
int *c = 50;

*c = 14;
c = &b;
*c = 25;

string  a = "1234";
string* b = a;


printf("%s %s", a, *b);

}