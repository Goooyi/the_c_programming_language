#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 100
#define MAXSIZE 100

int get_line(char arr[], int maxline);
int htoi(char str[], int size, int maxsize);

int main(void)
{
    char currLine[MAXLINE];
    int size = 0;
    while (size = get_line(currLine, MAXLINE))
    {
        int test_htoi = htoi(currLine, size, MAXSIZE);
        printf("input hexa-decimal is %s, output in decimal is %d\n", currLine, test_htoi);
        /* TODO: what if not using system-wise opt memset()?*/
        memset(currLine, 0, size);
    }
}

int get_line(char arr[], int maxsize)
{
    int cur = 0;
    char c = getchar();
    while (!(cur == maxsize || c == '\n' || c == EOF))
    {
        arr[cur++] = c;
        c = getchar();
    }
    return cur;
}

int htoi(char str[], int size, int maxlen)
{
    int i;
    int res = 0;
    for (i = 0; i < size; ++i)
    {
        if (!((i == 0 && str[i] == 0) || (i == 1 && (str[i] == 'x' || str[i] == 'X'))))
        {
            // convert the current digit to decimal
            int tmp = 0;
            if (str[i])
            res += (str[i] - '0') * pow(16, size - i - 1);
        }
    }
    return res;
}