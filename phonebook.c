#include <cs50.h>
#include <stdio.h>

int main(void)
 {
        string answer = get_string("Name: ");
        printf("%s!\n", answer);

        int i = get_int("Age: ");
        printf("%d\n", i);

        long phone = get_long("Phone number: ");
        printf("%ld\n", phone);
    }
