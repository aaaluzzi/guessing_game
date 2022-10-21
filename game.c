#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int max = 10;

void play() {
    int number = rand() % max + 1;
    char input[10];
    int guess;
    puts("Let's begin!");
    do {
        do {
            printf("Guess a number (or q to quit): ");
        } while (scanf("%s", input) == -1);
        if (strcmp(input, "q") == 0) {
            return;
        }
        guess = atoi(input);
        if (guess != number) {
            printf("The number is %s! Try again.\n", 
                number > guess ? "higher" : "lower");
        }
    } while (guess != number);
    puts("You guessed the number correctly! You win!");
}

void loadMenu() {
    puts("--------------------------------");
    puts("Press 1 to play a game");
    puts("Press 2 to change the max number");
    puts("Press 3 to quit");
    puts("--------------------------------");
    
    int choice;
    do {
        printf("Enter your choice: ");
    } while (scanf("%d", &choice) == -1 || choice < 1 || choice > 3);

    if (choice == 1) {
        play();
    } else if (choice == 2) {
        do {
            printf("Enter a new max (greater than zero): ");
        } while (scanf("%d", &max) == -1 || max <= 0);
        puts("Max has been updated");
    } else {
        puts("Thank you for playing! Goodbye.");
        return;
    }
    loadMenu();
}

int main() {
    srand(time(NULL));
    loadMenu();
    return 0;
}