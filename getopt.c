#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv)
{
	int option_val =0,counter =0, rand_num;
	FILE *file;
	time_t t;
	char string[1000]= "";
	while((option_val =getopt(argc,argv,"n:h:f:e")))
	{
		switch(option_val)
		{
			case'n':
				if(optarg != NULL)
				    counter = atoi(optarg);
			    	for (int i=0; i <counter;++i)
			    	printf("Hello world\n");
				break;
			case'h':
				printf("Enter -h for help\n");
				printf("Enter -e for a random even number between 0 and 99\n");
				printf("Enter -n for 10 printed lines\n");
				printf("Enter \"-f [filename]\" to print a file of your choice to stand output\n");
				break;
			case'f':
				if((file = fopen(optarg,"r")))
				{
					while(fgets(string,sizeof(string),file))
					{
						printf("%s\n",string);
					}
				}
				break;
			case'e':
				srand((unsigned) time(&t));
				rand_num = rand()%100;
				if(rand_num%2 !=0)
				    rand_num +=1;
				printf("%d\n",rand_num);
				break;
			default:
				printf("You chose wrong");
				return 0;
		}
	}
	return 0;
}
