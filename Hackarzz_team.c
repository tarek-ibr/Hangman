#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void hangMan (int mistakes);
int randIndex(int size);

/*
Extra functionalities we did in the project:
1) Game levels.
2) You can re-play the game.
3) A Hint you can use while your playing.
4) An exit button for the game.
5) display the score , mistakes , correct attempts.
6) display the previous entered letters to avoid entering them again.
*/

// While you're playing, if u want to use a hint you might have to wait a little bit after pressing the space button until the process is done.

int main()
{
    char wordsEasy[10][5]={"four","girl","game","word","pool","shoe","egg","arm","sun","free"};
    char wordsMedium[10][7]={"length","square","circle","horse","mouse","funny","house","cross","woman","scream"};
    char wordsHard[10][11]={"beautiful","baseball","friendship","nightmare","eyeballs","scream","darkness","skeleton","costume","syndrome"};
    char guess[11]={'_','_','_','_','_','_','_','_','_','_','_'};
    char guessWord,guessed[100]={0};
    int condition=0,oldCorrect=0,newCorrect=0,mistakes=1,score=0,level=0,index=randIndex(9),temp,size=0,hint=1,randInd=0;
    int sizeHard=strlen(wordsHard[index]) , sizeMedium=strlen(wordsMedium[index]) , sizeEasy=strlen(wordsEasy[index]);
    time_t startTime, currentTime;


    while(1){
    printf("\t\t\t\t\t\tHACKARZZ TEAM\n");
    printf("\t\t\t\t\t\tHANGMAN GAME\n\n");
    printf("YOU HAVE ONLY ONE HINT TO USE :) \n\n");
    printf("1) Easy \n2) Medium \n3) Hard\n4) exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &level);
    if(level==4)
       break;

    printf("\nYour score is : %d",score);

    switch(level){

case 1:
    index=randIndex(9);
    sizeEasy = strlen(wordsEasy[index]);
    mistakes=1;
    newCorrect=0;
    oldCorrect=0;
    size=0;
    hint=1;
    for(int i=0;i<size;i++)
        guessed[i]=0;

    for(int i=0;i<11;i++)
        guess[i]='_';

    do{
    oldCorrect=newCorrect;

    printf("\n\nMistakes:%d\n",mistakes-1);
    printf("Correct:%d\n", newCorrect);
    hangMan(mistakes);

    printf("The word: ");
    for(int i=0;i<sizeEasy;i++)
        printf("%c",guess[i]);

    printf("\n");

    if(newCorrect==sizeEasy)
        break;

    printf("\n");
    printf("The letters you entered: ");

    for(int i=0;i<size;i++)
        printf("%c",guessed[i]);

    printf("\n\nYOU HAVE ONLY ONE HINT TO USE :)\nTo use your hint press space");
    printf("\n\nYOU HAVE MAXIMUM 15 SECONDS TO ENTER A LETTER\n");
    printf("\nEnter a lower case letter: ");

    startTime=time(NULL);

    if(guessWord=='\n')
        temp=getch();

    guessWord = getche();

    currentTime=time(NULL);

    if(difftime(currentTime,startTime)>15){
        printf("\n\n\nTime expired\n");
        mistakes++;
        continue;
    }

    if(guessWord == 32 && hint == 1){
        printf("Your hint is: ");
        do{
            randInd = randIndex(sizeEasy);
            if(guess[randInd] == '_')
                break;
        }while(1);
        guess[randInd] = wordsEasy[index][randInd];
        newCorrect++;
        hint=0;
    }

    guessed[size]=guessWord;
    size++;

    for(int i=0;i<size-1;i++){
        printf("\n");
        if(guessed[i]==guessWord)
        condition=1;
        }

    if(condition){
        condition=0;
        continue;
        }

    for(int i=0;i<sizeEasy;i++){

        if(guessWord==wordsEasy[index][i]){
            guess[i]=guessWord;
            newCorrect++;
            }
    }

    if(oldCorrect==newCorrect){
        mistakes=mistakes+1;
        printf("\nWrong guess\n");}
    else
        printf("\nCorrect guess\n");

    }while(mistakes<=6);

    if(mistakes<6){
        printf("\nYou Won\n\n");
        score++;}
    else{
        printf("the word was :%s\n",wordsEasy[index]);
        printf("\nYou lost\n\n");
    }

    break;

case 2:
    index=randIndex(9);
    sizeMedium = strlen(wordsMedium[index]);
    mistakes=1;
    newCorrect=0;
    oldCorrect=0;
    size=0;
    hint=1;
    for(int i=0;i<size;i++)
        guessed[i]=0;

    for(int i=0;i<11;i++)
        guess[i]='_';

        do{
    oldCorrect=newCorrect;

    printf("\n\nMistakes:%d\n",mistakes-1);
    printf("Correct:%d\n", newCorrect);
    hangMan(mistakes);

    printf("The word: ");
    for(int i=0;i<sizeMedium;i++)
        printf("%c",guess[i]);

    printf("\n");

    if(newCorrect==sizeMedium)
        break;

    printf("\n");
    printf("The letters you entered: ");

    for(int i=0;i<size;i++)
        printf("%c",guessed[i]);

    printf("\n\nYOU HAVE ONLY ONE HINT TO USE :)\nTo use your hint press space");
    printf("\n\nYOU HAVE MAXIMUM 15 SECONDS TO ENTER A LETTER\n");
    printf("\nEnter a lower case letter: ");
    startTime=time(NULL);

    if(guessWord=='\n')
        temp=getch();

    guessWord = getche();

    currentTime=time(NULL);

    if(difftime(currentTime,startTime)>15){
        printf("\n\n\nTime expired\n");
        mistakes++;
        continue;
    }

    if(guessWord == 32 && hint == 1){
        printf("Your hint is: ");
        do{
            randInd = randIndex(sizeMedium);
            if(guess[randInd] == '_')
                break;
        }while(1);
        guess[randInd] = wordsMedium[index][randInd];
        newCorrect++;
        hint=0;
    }

    guessed[size]=guessWord;
    size++;

    for(int i=0;i<size-1;i++){
        printf("\n");
        if(guessed[i]==guessWord)
        condition=1;

    }

    if(condition){
        condition=0;
        continue;
    }

    for(int i=0;i<sizeMedium;i++){

        if(guessWord==wordsMedium[index][i]){
            guess[i]=guessWord;
            newCorrect++;
            }
    }

    if(oldCorrect==newCorrect){
        mistakes=mistakes+1;
        printf("\nWrong guess");}
    else
        printf("\nCorrect guess");

    }while(mistakes<=6);

    if(mistakes<6){
        printf("\nYou Won\n\n");
        score++;}
    else{
        printf("the word was :%s\n",wordsMedium[index]);
        printf("\nYou lost\n\n");
    }

    break;

case 3:
    index=randIndex(9);
    sizeHard = strlen(wordsHard[index]);
    mistakes=1;
    newCorrect=0;
    oldCorrect=0;
    size=0;
    hint=1;

    for(int i=0;i<size;i++)
        guessed[i]=0;

    for(int i=0;i<11;i++)
        guess[i]='_';

    do{
    oldCorrect=newCorrect;

    printf("\n\nMistakes:%d\n",mistakes-1);
    printf("Correct:%d\n", newCorrect);
    hangMan(mistakes);

    printf("The word: ");
    for(int i=0;i<sizeHard;i++)
        printf("%c",guess[i]);

    printf("\n");

    if(newCorrect==sizeHard)
        break;

    printf("\n");
    printf("The letters you entered: ");

    for(int i=0;i<size;i++)
        printf("%c",guessed[i]);

    printf("\n\nYOU HAVE ONLY ONE HINT TO USE :)\nTo use your hint press space");
    printf("\n\nYOU HAVE MAXIMUM 15 SECONDS TO ENTER A LETTER\n");
    printf("\nEnter a lower case letter: ");
    startTime=time(NULL);

    if(guessWord=='\n')
        temp=getch();

    guessWord = getche();

    currentTime=time(NULL);

    if(difftime(currentTime,startTime)>15){
        printf("\n\n\nTime expired\n");
        mistakes++;
        continue;
    }

    if(guessWord == 32 && hint == 1){
        printf("Your hint is: ");
        do{
            randInd = randIndex(sizeHard);
            if(guess[randInd] == '_')
                break;
        }while(1);
        guess[randInd] = wordsHard[index][randInd];
        newCorrect++;
        hint=0;
    }

    guessed[size]=guessWord;
    size++;

    for(int i=0;i<size-1;i++){
        printf("\n");
        if(guessed[i]==guessWord)
            condition=1;
    }

    if(condition){
        condition=0;
        continue;
    }

    for(int i=0;i<sizeHard;i++){

        if(guessWord==wordsHard[index][i]){
            guess[i]=guessWord;
            newCorrect++;
            }
    }

    if(oldCorrect==newCorrect){
        mistakes=mistakes+1;
        printf("\nWrong guess");}
    else
        printf("\nCorrect guess");

    }while(mistakes<=6);

    if(mistakes<6){
        printf("\nYou Won\n\n");
        score++;}
    else{
        printf("the word was :%s\n",wordsHard[index]);
        printf("\nYou lost\n\n");
    }

    break;

default:
    printf("wrong input");

        }
    }
return 0;
}

void hangMan (int mistakes){

    char mistake[7]={' ',' ',' ',' ',' ',' ',' '};

    switch(mistakes){
        case 6:
            mistake[6]='\\';
        case 5:
            mistake[5]='/';
        case 4:
            mistake[4]='\\';
        case 3:
            mistake[3]='/';
        case 2:
            mistake[2]='|';
        case 1:
            mistake[0]='(';
            mistake[1]=')';
            break;
    }

     printf("___________________\n"
           "|                  |\n"
           "|                  |\n"
           "|                 %c %c\n"
           "|                 %c%c%c\n"
           "|                 %c %c\n"
           "|\n|\n|\n|\n",mistake[0],mistake[1],mistake[3],mistake[2],mistake[4],mistake[5],mistake[6]);
}


int randIndex(int size){
    srand(time(NULL));
    int i = rand() % size;
    return i;}
