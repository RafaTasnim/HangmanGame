#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char word[100];
char guessed_letters[100];
char user_guess[] = "";
char blank[1] = "-";

int random_number;
int word_len;
int user_input;
int attempts;
int score = 0;
int total_score;
int level;
int chance =6;
int hard_attempt=4;
int attempt_count=10;
int chance_count=6;
char name[50];

void start_game();
void get_input();
void print_blanks();
void draw_platform();
void draw_medium_platform();
void draw_hard_platform();

void get_word();
void get_wordM();
void get_wordH();
void winMsg();
void looseMsg();



int main()
{

    system("cls");
    printf("\n\t\t WELCOME TO THE HANGMAN GAME!!!!\t\t\n");
    printf("\n\t\t ENTER YOUR NAME: ");
    scanf("%s", name);
    printf("\n\t\t Be aware you can be hanged!!.");

    printf("\n\n\t\t Rules : ");
    printf("\n\t\t - Maximum 10 mistakes are allowed.");
    printf("\n\t\t - All alphabet are in lower case except the first letter.");
    printf("\n\t\t - If you enjoy continue, otherwise close it.");

    printf("\n\t\t Syntax : Alphabet");
    printf("\n\t\t Example : Ab \n\n");

    printf("\n\t\t choose level \n\n ");
    printf("\n\t\t press (0) for easy level\n");
    printf("\n\t\t press (1) for medium level\n");
    printf("\n\t\t press (2) for hard level\n");
    scanf("%d",&level);


    system("PAUSE");
    while(1)
    {

        if(level==0)
        {
            printf("YOU HAVE CHOOSEN EASY LEVEL \n");
            start_game();

            while (attempts > 0)
            {
                system("cls");
                if (attempts == 5)
                    printf("\t\t HINT: The word is any Asian country name!!!!\n \t\tkeep trying\n");

                if (strlen(guessed_letters) == word_len - 1)
                {
                    print_blanks();

                    break;
                }

                else
                {
                    printf("Attempts Remaining: %i\n", attempts);
                    print_blanks();
                    get_input();
                }
                attempt_count--;
            }

            system("cls");

            if (attempts > 0)
            {
                print_blanks();
                winMsg();
            }

            else
            {

                draw_platform();
                looseMsg();
            }
        }

        if(level==1)
        {
            printf("YOU HAVE CHOOSEN MEDIUM LEVEL \n");
            start_game();

            while (chance > 0)
            {
                system("cls");
                if (chance == 3)
                    printf("\t\t HINT: The word is any European  country name!!!!\n \t\tkeep trying\n");

                if (strlen(guessed_letters) == word_len - 1)
                {
                    print_blanks();

                    break;
                }

                else
                {
                    printf("Attempts Remaining: %i\n", chance);
                    print_blanks();
                    get_input();

                }
                chance_count--;
            }

            system("cls");

            if (chance > 0)
            {
                print_blanks();
                winMsg();
            }

            else
            {

                draw_medium_platform();
                looseMsg();
            }
        }
        if(level==2)
        {
            printf("YOU HAVE CHOOSEN HARD LEVEL \n");
            start_game();

            while (hard_attempt > 0)
            {
                system("cls");

                if (strlen(guessed_letters) == word_len - 1)
                {
                    print_blanks();

                    break;
                }

                else
                {
                    printf("Attempts Remaining: %i\n", hard_attempt);
                    print_blanks();
                    get_input();

                }

            }

            system("cls");

            if (hard_attempt > 0)
            {
                print_blanks();
                winMsg();
            }

            else
            {

                draw_hard_platform();
                looseMsg();
            }
        }

        scanf("%i", &user_input);

        if (user_input == 1)
        {
            continue;
        }
        if (user_input == 0)
        {

            system("cls");
            printf("\n\n\t\t\t\t\t THANK YOU!! ");
            system("PAUSE");
            return 0;
        }
    }
}
void winMsg()
{
    score = 10 + score;
    printf("\n\n\t\t\t\t CONGRATULATION!!! %s You Won!\n",name);
    printf("\t\t\t-----------------------------------------");
    printf("\n\n\t\t\t\t SCORE : %d", score);
    printf("\n\n\t\t\t\t DO you want to play again? \n\n");
    printf("\t\t\t-----------------------------------------");
    printf("\n\n\t\t\t\t PRESS (1) to continue playing... ");
    printf("\n\n\t\t\t\t PRESS (0)  to exit... ");
}
void looseMsg()
{
    printf("\n\n\t\t\t\t OHH NO !!! You Lost! The word was %s\n", word);
    printf("\t\t\t-----------------------------------------------------");
    printf("\n\n\t\t\t\t SCORE : %d", score);
    printf("\n\n\t\t\t\t DO you want to play again? \n");
    printf("\t\t\t-----------------------------------------------------");
    printf("\n\n\t\t\t\t PRESS (1) to continue playing... ");
    printf("\n\n\t\t\t\t PRESS (0) to exit... ");
}

void start_game()
{

    if (level ==0)
    {

        get_word();
        word_len = strlen(word);
        for (int i = 0; i < sizeof(guessed_letters); i++)
        {
            guessed_letters[i] = 0;
        }
        attempts = 10;
    }
    if (level==1)
    {

        get_wordM();
        word_len = strlen(word);
        for (int i = 0; i < sizeof(guessed_letters); i++)
        {
            guessed_letters[i] = 0;
        }
        chance = 6;
    }
    if (level==2)
    {

        get_wordH();
        word_len = strlen(word);
        for (int i = 0; i < sizeof(guessed_letters); i++)
        {
            guessed_letters[i] = 0;
        }
        hard_attempt=4;
    }

}

void get_input()
{

    int i;
    int letter_hit = 0;

    printf("\nGUESS THE WORD : \n");
    scanf(" %c", user_guess);

    for (i = 0; i < word_len; i++)
    {
        if (user_guess[0] == word[i])
        {
            guessed_letters[i] = user_guess[0];
            letter_hit++;
        }
    }
    if (letter_hit > 0)
    {
        return;
    }
    else
    {
        attempts--;
        chance--;
        hard_attempt--;
    }
}

void print_blanks()
{
    int i, j;

    if(level==0)
        draw_platform();
    if(level ==1)
        draw_medium_platform();
    if(level==2)
        draw_hard_platform();
    for (i = 0; i < word_len; i++)
    {
        printf("%c", guessed_letters[i]);
        printf(" ");
    }
    printf("\n");

    for (j = 0; j < word_len - 1; j++)
    {
        printf("%s", blank);
        printf(" ");
    }
    printf("\n");
}

void draw_platform()
{

    char *platform[] =
    {

        "      ===\n",

        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "   =====|\n"
        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "  |     |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "  |-    |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "  |     |\n"
        "       ===\n",

        "   |=====|\n"
        "   O     |\n"
        "  -|-    |\n"
        "  //     |\n"
        "       ===\n"

    };
    if (attempts == 9)
        printf("\n\n%s\n", platform[0]);

    if (attempts == 8)
        printf("\n\n%s\n", platform[1]);

    if (attempts == 7)
        printf("\n\n%s\n", platform[2]);

    if (attempts == 6)
        printf("\n\n%s\n", platform[3]);

    if (attempts == 5)
        printf("\n\n%s\n", platform[4]);
    if (attempts == 4)
        printf("\n\n%s\n", platform[5]);

    if (attempts == 3)
        printf("\n\n%s\n", platform[6]);
    if (attempts == 2)
        printf("\n\n%s\n", platform[7]);
    if (attempts == 1)
        printf("\n\n%s\n", platform[8]);
    if (attempts == 0)
        printf("\n\n%s\n", platform[9]);
}



void draw_medium_platform()
{

    char *platform_medium[] =
    {

        "  |=====|\n"
        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "  |-    |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "  |     |\n"
        "       ===\n",

        "   |=====|\n"
        "   O     |\n"
        "  -|-    |\n"
        "  //     |\n"
        "       ===\n"

    };
    if (chance == 5)
        printf("\n\n%s\n", platform_medium[0]);
    if (chance == 4)
        printf("\n\n%s\n",  platform_medium[1]);
    if (chance == 3)
        printf("\n\n%s\n",  platform_medium[2]);
    if (chance == 2)
        printf("\n\n%s\n",  platform_medium[3]);
    if (chance == 1)
        printf("\n\n%s\n",  platform_medium[4]);
    if (chance == 0)
        printf("\n\n%s\n",  platform_medium[5]);
}

void draw_hard_platform()
{
    char *platform_hard[] =
    {

        "  |=====|\n"
        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",


        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "  |     |\n"
        "       ===\n",

        "   |=====|\n"
        "   O     |\n"
        "  -|-    |\n"
        "  //     |\n"
        "       ===\n"

    };
    if(hard_attempt==3)
        printf("\n\n%s\n", platform_hard[0]);
    if(hard_attempt==2)
        printf("\n\n%s\n", platform_hard[1]);
    if(hard_attempt==1)
        printf("\n\n%s\n", platform_hard[2]);
    if(hard_attempt==0)
        printf("\n\n%s\n", platform_hard[3]);

}
void get_word()
{

    FILE *fp,*fp1,*fp2;

    int line_number = 0;
    int i;
    char current_word[100];

    fp  = fopen("easy.txt", "r");


    if (fp == NULL)
    {
        printf("Error in opening file");
        exit(0);
    }

    while (fgets(current_word, 50, fp) != NULL)
    {
        line_number++;
    }

    random_number = rand() % line_number;

    rewind(fp);

    for (line_number = 0; line_number != random_number; line_number++)
    {
        fgets(current_word, 50, fp);
    }

    strcpy(word, current_word);


    fclose(fp);
}
void get_wordM()
{

    FILE *fp;
    int line_number = 0;
    int i;
    char current_word[1000];

    fp = fopen("medium.txt", "r");

    if (fp == NULL)
    {
        perror("Error in opening file");
    }

    while (fgets(current_word, 50, fp) != NULL)
    {
        line_number++;
    }

    random_number = rand() % line_number;

    rewind(fp);

    for (line_number = 0; line_number != random_number; line_number++)
    {
        fgets(current_word, 50, fp);
    }

    strcpy(word, current_word);


    fclose(fp);
}
void get_wordH()
{

    FILE *fp;
    int line_number = 0;
    int i;
    char current_word[1000];

    fp = fopen("hard.txt", "r");

    if (fp == NULL)
    {
        perror("Error in opening file");
    }

    while (fgets(current_word, 50, fp) != NULL)
    {
        line_number++;
    }

    random_number = rand() % line_number;

    rewind(fp);

    for (line_number = 0; line_number != random_number; line_number++)
    {
        fgets(current_word, 50, fp);
    }

    strcpy(word, current_word);


    fclose(fp);
}
