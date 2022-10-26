#include <stdio.h>
int rowxleft(int array[6][6], int row)
{
    int temp;
    int counter;
    int viscount;
    viscount = 1;
    counter = 1;
    temp = array[row][counter];
    //printf("%d\n", array[1][3]);
        while(counter < 4)
        {
            if(array[row][counter] < array[row][counter + 1])
            
                if(array[row][counter +1] > temp)
                {
                temp = array[row][counter +1];
                viscount++;
                }        
            counter++;
        }
    if (viscount == array[row][0])
        return (0);
    return (1);
}

int rowxright(int array[6][6], int row)
{
    int temp;
    int counter;
    int viscount;
    int start;
    start = 5;
    viscount = 1;
    counter = 1;
    temp = array[row][start - counter];
        while(counter < 4)
        {
            if(array[row][start - counter] < array[row][start - counter - 1])
            
                if(array[row][start - counter - 1] > temp)
                {
                temp = array[row][start - counter - 1];
                viscount++;
                }
            counter++;
        }
    if (viscount == array[row][5])
        return (0);
    return (1);
}

int colxUp(int array[6][6], int col)
{
    int temp;
    int counter;
    int viscount;
    viscount = 1;
    counter = 1;
    temp = array[counter][col];
        while(counter < 4)
        {
            if(array[counter][col] < array[counter + 1][col])
            
                if(array[counter + 1][col] > temp)
                {
                temp = array[counter + 1][col];
                viscount++;
                }
            
            counter++;
        }
    if (viscount == array[0][col])
        return (0);
    return (1);
}

int colxDown(int array[6][6], int col)
{
    int temp;
    int counter;
    int viscount;
    int start;
    start = 5;
    viscount = 1;
    counter = 1;
    temp = array[start - counter][col];
        while(counter < 4)
        {
            if(array[start - counter][col] < array[start - counter - 1][col])
            
                if(array[start - counter - 1][col] > temp)
                {
                temp = array[start - counter -1][col];
                viscount++;
                }
            
            counter++;
        }
    if (viscount == array[5][col])
        return (0);
    return (1);
}
