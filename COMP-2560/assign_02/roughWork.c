#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	//Checks if there are enough arguments in the command line
	if(argc != 7)
	{
		printf("ERROR: Invalid number of arguments");	//Or use write(1, "text here", # of characters)
		return 0;	//Or use Exit(1) 
	}
	

	//We create a new file in which we are going to name whatever the 3rd argument user entered as
	int f1 = creat(argv[1], 0722);
	int status, id;

	//Write a generic header
	char headerDefault[] = "P6\n1000 1000\n255\n";
	write(f1, headerDefault, strlen(headerDefault));	

	int white = 16777215;
	int black = 0;
	int green = 65280;
	int yellow = 16776960;
	int purple = 3342387;

	int colors[4];
	//colors[0] = green;

	bool startCenter = false;

	for(int i = 0 ; i < 10 ; i++)
	{	
		if(fork() == 0)
		{
			if(i <= 4)
			{
				//This will loop 1000*100 times, which in reference, is the number of pixels in 100 rows of a 1000 by 1000 image
				for(int x = 0 ; x < 1000*100 ; x++)	//This is 100 rows
				{
					//In order to 
					if( (x+1) % 500  == 0  && (x+1) % 1000 != 0 )
					{
						for(int z = 0 ; z < 500 ; z++)
						{
							write(f1, &white, 3);
							x++;
						}
						x--; //We need to take one away because the loop below will actually add one extra increment to the x
					}
					else
						write(f1, &yellow, 3);
				}
			} 
			else 
			{
				for(int x = 0 ; x < 1000*100 ; x++)	//This is 100 rows
				{
					if( (x+1) % 500  == 0  && (x+1) % 1000 != 0 )
					{
						for(int z = 0 ; z < 500 ; z++)
						{
							write(f1, &black, 3);
							x++;
						}
						x--;	//We need to take one away because the loop below will actually add one extra increment to the x
					}
					else
						write(f1, &green, 3);
				}
			}

			exit(1);
		}

		wait(&status);
	}

	close(f1);

    return 0;
}