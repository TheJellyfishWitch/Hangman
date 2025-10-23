// AE, JL, EG, XP, EM 7th Hangman Video Game
// Addie Erickson made repository + overall debugging
// xander parker, including basic libraries and stuffs
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for srand
#include <time.h>
#include <ctype.h> // for time

#define MAX_TRIES 6
#define WORD_LENGTH 100

void board(wrong){
//Eva Gilbert + Jovie Lineback, making the board
    if(wrong == 0){
        printf( " |__| \n |  \n | \n | \n|______ \n");
    } else if (wrong == 1){
        printf(" |__| \n |  0  \n | \n | \n |______ \n");
    } else if (wrong == 2){
        printf(" |__| \n |  0  \n |   |\n | \n |______ \n");
    } else if (wrong == 3){
        printf(" |__| \n |  0  \n |   /|\n | \n |______\n ");
    } else if (wrong == 4){
        printf(" |__| \n |  0  \n |   /|\\ \n | \n |______\n ");
    } else if (wrong == 5){
        printf(" |__| \n |  0  \n |   /|\\ \n |  / \n |______\n ");
    } else {
        printf(" |__| \n |  0  \n |   /|\\ \n |  /\\ \n |______\n ");
    }
    printf("%s\n", stages[MAX_TRIES - tries]); 
}
   //jovie lineback making word peice
int main(void){
    const char *word_list[] = {"pancakes", "waffles","burgers", "cinnamonrolls", "scooter","cake","pizza","supercalifragilisticexpialidocious","jumpsuit","pneumonoultramicroscopicsilicovolcanoconiosis","minions","microsopic","water","apples","radioactive","pasta","tortellini","jellyfish","fruitsnacks","red","stingray","octopus","smiley face","","bike","pinapples","JOVIE","cherries","harold","supernova","hangman", "femboys", "invincible", "python", "code", "cancer", "atmosphere", "dyslexic", "little", "big", "yeah dog", "OH YEAHH", "VECTOR", "ISAIAH", "boxing", "fortnite", "xander", "eva", "jesus", "fernando", "kyle", "samamntha", "mcdonalds", "ryan", "prorammers", "wear", "glasses", "because", "they", "cant", "C", "why", "do", "python", "today", "comuter", "ciera", "archie", "hannah", "MCdonalds", "gyan", "discumbobulate","meow" ,"bored", "help", "mike", "hawk", "turn", "batman", "spiderman","green", "goblin"};
    
    int word_count = sizeof(word_list) / sizeof(word_list[0]);
    srand(time(0));
    
    const char *chosen_word = word_list[rand() % word_count];
    int word_len = strlen(chosen_word);
    



    
    char guessed[word_len + 1];
    for (int i = 0; i < word_len; i++) {
        guessed[i] = '_';
    }
    guessed[word_len] = '\0';
    int tries = MAX_TRIES;
    char guessed_letters[26] = {0};
    int guessed_count = 0;
    printf("Welcome to Hangman!\n");
    
    // Xander Parker, general game logic and whatnot
    while (tries > 0) {
        printf("\nWord: %s\n", guessed);
        printf("Guessed letters: ");
        for (int i = 0; i < guessed_count; i++) {
            printf("%c ", guessed_letters[i]);
        }
        printf("\n");
        display_hangman(tries);
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


//Addie Erickson guesses
void guessing(void){
        if (already_guessed) {
            printf("You already guessed that letter. Try again.\n");
            continue;
        }
        guessed_letters[guessed_count++] = guess;
        int correct_guess = 0;
        for (int i = 0; i < word_len; i++) {
            if (chosen_word[i] == guess) {
                guessed[i] = guess;
                correct_guess = 1;
            }
        }
        if (!correct_guess) {
            tries--;
            printf("Wrong guess! You have %d tries left.\n", tries);
        } else {
            printf("Good guess!\n");
        }
        if (strcmp(guessed, chosen_word) == 0) {
            printf("\nCongratulations! You've guessed the word: %s\n", chosen_word);
            break;
        }
    }
    
    if (tries == 0) {
        display_hangman(tries);
        printf("\nSorry, you've run out of tries. The word was: %s\n", chosen_word);
    }
    return 0;
}
