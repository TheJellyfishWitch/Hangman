// AE, JL, EG, XP, EM 7th Hangman Video Game
// Addie Erickson made ripository + overall debugging + adding code that the others coded while at home
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for srand
#include <time.h> // for time
 #define max_word_length 50;

void board (wrong){
//Eva Gilbert + Jovie Lineback, making the board
    if (wrong == 0){
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
 
}

int main(void){ 
//Xander P, general user introduction and greeting
    char username[20];
    printf("Welcome to Hangman! What is your username?\n");
    scanf("%s", &username);
//Xander P, general game logic and function
    char guessed_letters[50]; //makes a list of guessed letters
    const char *chosen_word = "blue";
    char *display = (char *)malloc((chosen_word + 1)*size_of(char));
    if (display == NULL){
        printf(stderr, "fail\n");
        return 1;
}

    for(int i = 0; i < chosen_word; i++){
        if (chosen_word[i] != '_'){
        display[i] = '_'
    }
}




// Jovie Lineback word list
    srand(time(NULL)); // makes a random word generated
    char word[][15] = {"pancakes", "waffles","burgers", "cinnamonrolls", "scooter","cake","pizza","supercalifragilisticexpialidocious","jumpsuit","pneumonoultramicroscopicsilicovolcanoconiosis","minions","microsopic","water","apples","radioactive","pasta","tortellini","jellyfish","fruitsnacks","red","stingray","octopus","smiley face","","bike","pinapples","JOVIE","cherries","harold","supernova","hangman", "femboys", "invincible", "python", "code", "cancer", "atmosphere", "dyslexic", "little", "big", "yeah dog", "OH YEAHH", "VECTOR", "ISAIAH", "boxing", "fortnite", "xander", "eva", "jesus", "fernando", "kyle", "samamntha", "mcdonalds", "ryan", "prorammers", "wear", "glasses", "because", "they", "cant", "C", "why", "do", "python", "today", "comuter", "ciera", "archie", "hannah", "MCdonalds", "gyan", "discumbobulae", "bored", "help", "mike", "hawk", "turn", "batman", "spiderman","green", "goblin"};
    for(int i= 0; i<1000; i++){
        int num = rand() % 75;
        printf("our random word is %s\n", word[num]);
    
//Enzo end statement
    printf("%s good job you guessed the word", username);

    printf("%s wow you didn't get it, how?! You LOST", username);

    return 0;
} 

