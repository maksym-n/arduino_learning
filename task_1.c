#include <stdio.h>

void printFibonacci(int limit) {
    int previous = 0, current = 1;

    printf ("%i ", previous);
    printf ("%i ", current);

    for (int i = 0; i < (limit - 2); i++) {
        if (previous == 0) {
            previous = 1;
        } else {
            current += previous;
            previous = current - previous;
        }
        printf ("%i ", current);
    }
}

int main() {
   printFibonacci(6);
   return 0;
}