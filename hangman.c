// AE, JL, EG, XP, EM 7th Hangman Video Game
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int main(void){ 
//Xander P, general user introduction and greeting
char username[20];
printf("what is your username?\n");
scanf("%s", &username);
//Xander P, general game logic and function
char guessed_letters[50]; //makes a list of guessed letters


//Eva Gilbert + Jovie Lineback, making the board
    int wrong;
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
    } else
        printf(" |__| \n |  0  \n |   /|\\ \n |  /\\ \n |______\n ");
    }
 







// Jovie Lineback word list  
    srand(time(NULL));
    char word[][15] = {"pancakes", "waffles","burgers", "cinnamonrolls", "scooter","cake","pizza","supercalifragilisticexpialidocious","jumpsuit","pneumonoultramicroscopicsilicovolcanoconiosis","minions","microsopic","water","apples","radioactive","pasta","tortellini","jellyfish","fruitsnacks","red","stingray","octopus","smiley face","","bike","pinapples","JOVIE","cherries","harold","supernova","hangman", "femboys", "invincible", "python", "code", "cancer", "atmosphere", "dyslexic", "little", "big", "yeah dog", "OH YEAHH", "VECTOR", "ISAIAH", "boxing", "fortnite", "xander", "eva", "jesus", "fernando", "kyle", "samamntha", "mcdonalds", "ryan", "prorammers", "wear", "glasses", "because", "they", "cant", "C", "why", "do", "python", "today", "comuter", "ciera", "archie", "hannah", "MCdonalds", "gyan"};
    for(int i= 0; i<1000; i++){
        int num = rand() % 75;
        printf("our random word is %s\n", word[num]);
    
    }





    printf("good job you guessed the word");

    printf("you're so dumb how did you not get it? You LOST");

    return 0;
} 

