#include<unistd.h>
#include<stdio.h>
int colxUp(int array[6][6], int col);
int colxDown(int array[6][6], int col);
int rowxleft(int array[6][6], int row);
int rowxright(int array[6][6], int row);

void array(int *outer)
{
	int counter;

	counter = 0;
	while(outer[counter])
	{
		printf("%d", outer[counter]);
		counter++;
	}
	printf("\n");

	int big[6][6] = {
	{0, 3, 2, 1, 2, 0},
	{2, 2, 1, 4, 3, 2},
	{2, 3, 4, 2, 1, 3},
	{1, 4, 3, 1, 2, 3},
	{4, 1, 2, 3, 4, 1},
	{0, 2, 3, 2, 1, 0}
	};
	printf("%d", big[1][3]);
	if (colxUp(big, 1) || colxDown(big, 2) || rowxleft(big, 1) || rowxright(big, 2))
		printf("nope");
	else
		printf("yep");


	// int first;
	// int second;
	
	// first = 0;
	// counter = 0;

	// while(first < 6)
	// {
	// 	second = 0;
	// 	while(second < 6)
	// 	{
	// 		printf("%d ", big[first][second]);
	// 		second++;
	// 	}
	// 	printf("\n");
	// 	first++;
	// }

	// 	int big[6][6] = {
	// {0, outer[0], outer[1], outer[2], outer[3], 0},
	// {outer[8], 1, 2, 3, 4, outer[12]},
	// {outer[9], 2, 3, 4, 1, outer[13]},
	// {outer[10], 3, 4, 1, 2, outer[14]},
	// {outer[11], 4, 1, 2, 3, outer[15]},
	// {0, outer[4], outer[5], outer[6], outer[7], 0}
	// };

}
