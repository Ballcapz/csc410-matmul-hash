#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>

unsigned long hash(char *str);


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Please provide an argument ./<exe> <hashValue>\n");
		return 0;
	}

	char *ptr;
	unsigned long hashNumber = strtoul(argv[1], &ptr, 10);

	char resultString[5];
	unsigned long testRes;


	#pragma omp parallel for num_threads(8) collapse(2)
	for (char i = 97; i <= 122; i++)
	{
		for (char j = 97; j <= 122; j++)
		{
			for (char k = 97; k <= 122; k++)
			{
				for (char l = 97; l <= 122; l++)
				{
					char param[5];
					param[0] = i;
					param[1] = j;
					param[2] = k;
					param[3] = l;
					param[4] = '\0';
					
					testRes = hash(param);
					if (testRes == hashNumber)
					{
						resultString[0] = i;
						resultString[1] = j;
						resultString[2] = k;
						resultString[3] = l;
						printf("%s  <-- string value\n", resultString);
						exit(0);
					}

				} // end l
			} // end k
		} // end j
	} // end i

	return 0;
}








