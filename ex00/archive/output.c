#include <unistd.h>
#include <stdio.h>
void output(void)
{
    int count;

    count = 0;
    int arrex[] = {1, 3, 2, 4, 2, 3, 1, 4, 3, 2, 4, 1, 2, 3, 2, 3};
    char arrout[16];

    while(count < 16)
    {
        arrout[count] = arrex[count] + '0';
        //printf("%c", arrout[count]);
        write(1, &arrout[count], 1);
        if ((count + 1) % 4 == 0)
            write(1, "\n", 1);
        else
            write(1, " ", 1);
        count++;
    }
} 

int main()
{
    output();
}