#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int *arr = NULL;                             //arr is storing the index number of the vowel for which * is used.
int checkbag(int num, char *bag, char str[]) //checking if the word is made up of letters in the bag.
{
    arr = NULL;
    int i, j, count = 0, count1 = 0, k = 0;
    for (i = 0; i < strlen(str); i++)
    {
        for (j = 0; j < 2 * num; j++) //count1 counts number of * in the bag.
                                      //if the word matches with the word in the bag of letters then count increments.
        {
            if (str[i] == bag[j])
            {
                str[i] = '0';
                bag[j] = '0';
                count++;
                break;
            }
        }
    }
    for (j = 0; j < 2 * num; j++)
    {
        if (bag[j] == '*')
            count1++;
    }
    if (count1 > 0)
    {
        arr = (int *)malloc(count1 * sizeof(int));
        assert(arr != NULL);
        for (i = 0; i < count1; i++)
            arr[i] = -1;
    }
    //if vowel is there in the word but not counted and * is there in the bag  of then vowel gets counted with the help of *.//
    while (count != strlen(str) && count1 != 0)
    {
        for (i = 0; i < strlen(str); i++)
        {
            if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                arr[k] = i;
                break;
            }
        }
        if (arr[k] == -1)
            break;
        for (j = 0; j < 2 * num; j++)
        {
            if (bag[j] == '*' && arr[k] != -1)
            {
                str[arr[k]] = '0';
                k++;
                bag[j] = '0';
                count++;
                count1--;
                break;
            }
        }
    }

    if (count == strlen(str))
        return 1; // if word is made up of letters in the bag.
    else
        return 0; // if word is not made up of letters in the bag
}
int score(char temp2[], int *arr1, int s) //score function taking word ,an array containing the index no. of string, and number of letters in the bag;
{
    int i = 0, mult, good, bad, score2, l = 0;
    int count3 = strlen(temp2); //wordlength
    int weight = 0;
    while (temp2[i] != '\0')
    {
        if (arr1 != NULL && i == arr1[l])
        {
            weight += 0;
            l++;
        }
        else
        {
            switch (temp2[i])
            {

            case 'E':
            case 'A':
            case 'I':
            case 'O':
            case 'N':
            case 'R':
            case 'T':
            case 'L':
            case 'S':
            case 'U':
                weight += 1;
                break;

            case 'D':
            case 'G':
                weight += 2;
                break;

            case 'B':
            case 'C':
            case 'M':
            case 'P':
                weight += 3;
                break;

            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                weight += 4;
                break;

            case 'K':
                weight += 5;
                break;

            case 'J':
            case 'X':
                weight += 8;
                break;

            case 'Q':
            case 'Z':
                weight += 10;
            }
        }
        i++;
    }
    good = (s - 1) * count3;
    bad = (3 * (s + 1 - count3));
    if (bad < 1)
        bad = 1;
    mult = good - bad;
    score2 = weight * mult;
    return score2;
}
int main()
{
    FILE *f6, *f5, *f4, *f3, *f2, *f7, *f8, *f9, *f10, *f11, *f12, *f13, *f14, *f15;
    char *bag, *bag1; //str is string for word.
    int m, t, num, i, score1 = 0;

    printf("Enter number of letters in the bag="); //input data from user
    scanf("%d", &num);

    fflush(stdin);
    bag = (char *)malloc(2 * num * sizeof(char));
    bag1 = (char *)malloc(2 * num * sizeof(char));

    printf("Enter bag of letters\n 1.Each letter(if small,they will be converted to capital in program) should be separated by single space\n 2.Press enter just after last letter\n please include * in letters:");
    for (i = 0; i < 2 * num; i++)
        scanf("%c", &bag[i]);
    clock_t time;
    time = clock();
    //to remove newline character from stdin
    for (m = 0; m < 2 * num; m++) // converting bag of letters in upper case.
    {
        if (isspace(bag[m]))
            continue;
        else
        {
            t = bag[m];
            if (t >= 97 && t <= 122)
            {
                t = t - 32;
                bag[m] = t;
            }
        }
    }
    char spell1[101], spell2[101];
    int p, b, prev_score = 0;
    switch (num)
    {
    case 15:
        f15 = fopen("dc15.txt", "r");
        while (!feof(f15))
        {
            fscanf(f15, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f15);
    case 14:
        f14 = fopen("dc14.txt", "r");
        while (!feof(f14))
        {
            fscanf(f14, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f14);
    case 13:
        f13 = fopen("dc13.txt", "r");
        while (!feof(f13))
        {
            fscanf(f13, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f13);
    case 12:
        f12 = fopen("dc12.txt", "r");
        while (!feof(f12))
        {
            fscanf(f12, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f12);
    case 11:
        f11 = fopen("dc11.txt", "r");
        while (!feof(f11))
        {
            fscanf(f11, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f11);
    case 10:
        f10 = fopen("dc10.txt", "r");
        while (!feof(f10))
        {
            fscanf(f10, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f10);
    case 9:
        f9 = fopen("dc9.txt", "r");
        while (!feof(f9))
        {
            fscanf(f9, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f9);
    case 8:
        f8 = fopen("dc8.txt", "r");
        while (!feof(f8))
        {
            fscanf(f8, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f8);
    case 7:
        f7 = fopen("dc7.txt", "r");
        while (!feof(f7))
        {
            fscanf(f7, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f7);

    case 6:
        f6 = fopen("dc6.txt", "r");
        while (!feof(f6))
        {
            fscanf(f6, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f6);
    case 5:
        f5 = fopen("dc5.txt", "r");
        while (!feof(f5))
        {
            fscanf(f5, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f5);
    case 4:
        f4 = fopen("dc4.txt", "r");
        while (!feof(f4))
        {
            fscanf(f4, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f4);
    case 3:
        f3 = fopen("dc3.txt", "r");
        while (!feof(f3))
        {
            fscanf(f3, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f3);
    case 2:
        f2 = fopen("dc1.txt", "r");
        while (!feof(f2))
        {
            fscanf(f2, "%s", spell1);
            strcpy(spell2, spell1);
            for (b = 0; b < 2 * num; b++)
            {
                bag1[b] = bag[b];
            }
            p = checkbag(num, bag1, spell1);
            if (p == 1)
            {
                score1 = score(spell2, arr, num);
            }
            if (score1 > prev_score)
            {
                printf("%s-%d\n", spell2, score1);
                prev_score = score1;
            }
        }
        fclose(f2);
    }
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC; // in seconds

    printf("Process took %f seconds to execute \n", time_taken);
    getch();
    // return 0;
    return 0;
}
