#include <cs50.h>
#include <stdio.h>

int main(void)
 {
        string name = get_string("Name: ");
        printf("%s!\n", name);

        int age = get_int("Age: ");
        printf("%i\n", age);

        string phone = get_string("Phone number: ");
        printf("%s\n", phone);
    }
