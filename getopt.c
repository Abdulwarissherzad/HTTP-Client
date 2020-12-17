/**********************************/
/**-----http/1.1 client----------**/
/**---Abdul waris sherzad--------**/
/**********************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*Getopt Library*/
#include <getopt.h>
/*Socket Library*/
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 80

int main(int argc, char **argv)
{
	int option_val =0;

	FILE *file;
	FILE *fileout;
	char string[1000]= "";
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char hello[] = "";

	while((option_val =getopt(argc,argv,"c:u:a:h:t:o:d:G"))!= -1)
	{
		switch(option_val)
		{
			case'c':{
				    if(optarg != NULL)
	                sprintf(hello,"GET / HTTP/1.1\r\nHost:%s\r\n\r\n",optarg);
                    }
				break;
			case'u':
				sprintf(hello,"GET /~%s HTTP/1.1\r\nHost:%s\r\n\r\n",optarg,argv[2]);
				break;
			case 'a':
		     	sprintf(hello,"GET / HTTP/1.1\r\nHost:%s\r\nUser-Agent:%s\r\n\r\n",argv[2],optarg);
				break;  
			case 'h':{
				sprintf(hello,"GET / HTTP/1.1\r\nHost:%s\r\nX-First-Name:%s\r\n\r\n",argv[2],optarg);
				break;
			}
			case't':
				if((file = fopen(optarg,"r"))) //optarg for reading name of file
				{
                while(fgets(string,sizeof(string),file))
                {   
				     printf("%s\n",string);
					sprintf(hello,"POST /~devrim/test.php HTTP/1.1\r\nHost:db.ciu.edu.tr \r\n\r\n","%s\n \n\r",string);
	            }
				}
				fclose(file);
				break;

			case'?':
				if (optopt == 'u'){
				 sprintf(hello,"GET /~%s HTTP/1.1\r\nHost:%s\r\n\r\n",optarg,argv[2]);
            	}else
				break;
			case 'o':{
				if(fileout = fopen(optarg,"w")){
                   if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
				    {
				        printf("\n Socket creation error \n");
				        return -1;
				    }
				    serv_addr.sin_family = AF_INET;
				    serv_addr.sin_port = htons(PORT);
				    inet_aton(argv[1],&serv_addr.sin_addr);

				    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
				    {
				        printf("\nConnection Failed \n");
				        return -1;
				    }
				    send(sock , hello , strlen(hello) , 0 );
				    valread = read( sock , buffer, 1024);
					fprintf(fileout,"%s\n",buffer);
			    	}
				    fclose(fileout);
			    	printf("\nResponse file has been written to <file:%s> instead of stdout.\n\n",optarg);
			    	return 0;
				break;
			case'd':
				 sprintf(hello, "POST /~devrim/test.php HTTP/1.1\r\nHost:db.ciu.edu.tr\r\n\r\n%s&%s\r\n",optarg,optarg);
				break;
			case'G':
				if(optarg != NULL)
				sprintf(hello,"GET /~devrim/test.php?%s&%s HTTP/1.1\r\nHost:db.ciu.edu.tr\r\n\r\n",optarg,optarg);
				break;
		    	}
			default:
			{
				return 0;
			}
		}
    }
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
	    printf("\n Socket creation error \n");
		return -1;
	}
    serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	inet_aton(argv[1],&serv_addr.sin_addr);

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
 	send(sock , hello , strlen(hello) , 0 );
    printf("Message sent \n%s",hello);
   	valread = read( sock , buffer, 1024);
 	printf("%s\n",buffer );
	return 0;
}

