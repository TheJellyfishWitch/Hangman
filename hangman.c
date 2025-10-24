//AE, JL, EG, XP, EM 7th Hangman Video Game
//Addie Erickson made repository + overall debugging 
//Xander Parker, including basic libraries and what not
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for srand
#include <time.h>
#include <ctype.h> // for time

#define MAX_TRIES 6
#define WORD_LENGTH 100

void display_hangman(int wrong){
//Eva Gilbert + Jovie Lineback, making the board
    if(wrong == 0){
        printf(" |__| \n |  \n| \n| \n|______ \n");
    } else if (wrong == 1){
        printf(" |__| \n |  0  \n | \n | \n |______ \n");
    } else if (wrong == 2){
        printf(" |__| \n |  0  \n |  |\n | \n |______ \n");
    } else if (wrong == 3){
        printf(" |__| \n |  0  \n | /|\n | \n |______\n ");
    } else if (wrong == 4){
        printf(" |__| \n |  0  \n | /|\\ \n | \n |______\n ");
    } else if (wrong == 5){
        printf(" |__| \n |  0  \n | /|\\ \n | / \n |______\n ");
    } else {
        printf(" |__| \n |  0  \n | /|\\ \n | /\\ \n |______\n ");
    }
}
// Jovie Lineback making word peice
int main(void){
    
    // word list containing words for the hangman game
    
    const char *word_list[] = {"pancakes", "waffles","burgers", "cinnamonrolls", "cake", "pizza", "supercalifragilisticexpialidocious", "jumpsuit","pneumonoultramicroscopicsilicovolcanoconiosis", "minions", "microsopic","water","apples","radioactive","pasta","tortellini","jellyfish","fruitsnacks", "space", "red","stingray","octopus","bike","pinapples", "peices", "cherries", ":)", "harold","supernova","hangman", "invincible", "python", "code", "go", "cancer", "atmosphere", "dyslexic", "big", "vector", "fortnite", "freddyfazbear", "mcdonalds", "programmers", "glasses", "because", "c", "yesterday", "computer", "mcdonalds", "discumbobulate", "meow" ,"bored", "hawk", "batman", "spiderman", "q", "no", "greengoblin", "shootingstars"};
    
    //gets how much spaces the word chosen has

    int word_count = sizeof(word_list) / sizeof(word_list[0]);
    srand(time(0));
    
    const char *chosen_word = word_list[rand() % word_count];
    int word_len = strlen(chosen_word);
    
    // this makes the spaces for the letters in the word _
    
    char guessed[word_len + 1];
    for (int i = 0; i < word_len; i++) {
        guessed[i] = '_';
    }
    guessed[word_len] = '\0';
    
    //keeps count of tries and guessed letters
    
    int tries = MAX_TRIES;
    char guessed_letters[26] = {0};
    int guessed_count = 0;
    printf("Welcome to Hangman!\n");
    
// Xander Parker + Addie Erickson, general game logic and whatnot
    while (tries > 0) {
        printf("\nWord: %s\n", guessed);
        printf("Guessed letters: ");
        for (int i = 0; i < guessed_count; i++) {
            printf("%c ", guessed_letters[i]);
        }
        printf("\n");
        display_hangman(MAX_TRIES - tries);
        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);
        int already_guessed = 0;
        for (int i = 0; i < guessed_count; i++) {
            if (guessed_letters[i] == guess) {
                already_guessed = 1;
                break;
            }
        }

    // tells the user if they've already guessed the letter

        if (already_guessed) {
            printf("You already guessed that letter. Try again.\n");
            continue;
        }
        guessed_letters[guessed_count++] = guess;
        int correct_guess = 0;
        for (int i = 0; i < word_len; i++) {
            if (tolower(chosen_word[i]) == guess) {
                guessed[i] = chosen_word[i];
                correct_guess = 1;
            }
        }

    // tells the user if the answer is wrong with tries left or if its right and you guessed the word

        if (!correct_guess) {
            tries--;
            printf("Wrong guess! You have %d tries left.\n", tries);
        } else {
            printf("Good guess!\n");
        }
// Enzo Marin end statement
        if (strcmp(guessed, chosen_word) == 0) {
            printf("\nCongratulations! You've guessed the word: %s\n", chosen_word);
            break;
        }
    }
    
    // tells the user when they ran out of tries to guess the letter

    if (tries == 0) {
        display_hangman(MAX_TRIES);
        printf("\nYou dumb stupid idiot. The word was: %s\n", chosen_word);
    }
    return 0;
}
