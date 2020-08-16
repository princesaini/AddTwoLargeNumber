// Program to add to very big numbers (out of range of int)
#include <stdio.h>
#include <string.h>

int main()
{
    int i, last = 0, maxlen = 0;
    int num1[255] = {0}, num2[255] = {0}, sum[255] = {0};
    int len_num1, len_num2;
    char str1[100], str2[100];

    // Getting Numbers as Strings
    printf("Enter Number 1 : ");
    gets(str1);
    printf("Enter Number 2 : ");
    gets(str2);

    // Calculating String Length
    len_num1 = strlen(str1);
    len_num2 = strlen(str2);

    maxlen = ((len_num1 > len_num2) ? len_num1 : len_num2);

    // Reversing Strings
    strrev(str1);
    strrev(str2);

    // Converting Character Arrays into Integers
    // Converting str1 into num1
    for(i=0; i<len_num1; i++)
        num1[i] = str1[i] - 48;
    // Converting str2 into num2
    for(i=0; i<len_num2; i++)
        num2[i] = str2[i] - 48;

    // Adding Number Arrays
    if(len_num1 >= len_num2)
    {
        for(i = 0; i<len_num1; i++)
            if(num1[i] + num2[i] >= 10)
            {
                sum[i] = (num1[i] + num2[i]) % 10;
                num1[i+1]++;
            }
            else
                sum[i] = num1[i] + num2[i];
    }
    else
    {
        for(i = 0; i<len_num2; i++)
            if(num2[i] + num1[i] >= 10)
            {
                sum[i] = (num2[i] + num1[i]) % 10;
                num2[i+1]++;
            }
            else
                sum[i] = num2[i] + num1[i];
    }

    if(num1[len_num1 - 1] + num2[len_num2 - 1] >= 10)
    {
        last = 1;
        sum[maxlen] = 1;
    }

    // Printing Sum
    if(last == 1)
    {
        printf("\nSum :  ");
        for(i = maxlen; i >= 0; i--)
            printf("%d", sum[i]);
    }
    else
    {
        printf("\nSum :  ");
        for(i = maxlen-1; i >= 0; i--)
            printf("%d", sum[i]);
    }

    return 0;
}