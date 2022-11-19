#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include "essai.h"
#include "function.h"

int CvC();
int sleep();
int vCompu1 = 0;
int vCompu2 = 0;
int draw3 = 0;
int countNumber2 = 0;
int currentPlayer4;

pthread_mutex_t verrou;

int table[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

void initi()
{
    srand(time(NULL));
    int should_run = 1;

    while (should_run == 1)
    {
        CvC();
    }
}

void *threadMain(void *data)
{

    const char *threadName = (const char *)data;
    bool isOver = false;

    while (isOver == false)
    {
        if (strcmp(threadName, "1") == 0)
        {
            currentPlayer4 = -1;
            pthread_mutex_lock(&verrou);
        }
        else
        {
            currentPlayer4 = 0;
            pthread_mutex_lock(&verrou);
        }

        printf("%s joue \n", threadName);

        int rep = rand() % 9 + 1;

        while (CheckCoupComputer(3, table, rep) != true)
        {
            rep = rand() % 9 + 1;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (table[i][j] == rep)
                {
                    table[i][j] = currentPlayer4;
                }
            }
        }

        afficheMatrice(3, table);

        isOver = win(table, currentPlayer4);

        switch (countNumber2)
        {

        case 8:
            if (isOver == false)
            {
                isOver = true;
                printf("La partie se termine sur un nul\n");
                draw3++;
                return EXIT_SUCCESS;
            }
            else
            {
                printf("%s a gagné !\n", threadName);
                return EXIT_SUCCESS;
            }
        default:
            if (isOver == true)
            {
                printf("%s a gagné !\n", threadName);
                return EXIT_SUCCESS;
            }
            else
            {
                countNumber2++;
            }
        }
        printf("%s a terminé son coup !\n", threadName);
        pthread_mutex_unlock(&verrou);
        sleep(1);
    }

    return EXIT_SUCCESS;
}

int CvC()
{

    pthread_t thread1, thread2;

    pthread_mutex_init(&verrou, NULL);

    pthread_create(&thread1, NULL, threadMain, (void *)"1");
    pthread_create(&thread2, NULL, threadMain, (void *)"2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&verrou);

    printf("Le thread principal s'arrête.\n");
    return EXIT_SUCCESS;
}
