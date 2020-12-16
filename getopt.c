#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <getopt.h>
#include <string.h>

/*Socket Library*/
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 80

int main(int argc, char **argv)
{
	int option_val =0,counter =0, rand_num;
    

	
	FILE *file;
	FILE *fileout;
	time_t t;
	char string[1000]= "";
	
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char buffer1[1024];
    char hello[] = "";
 //   char  hello[] = "GET / HTTP/1.1\r\nHost:www.google.com\r\n\r\n";

	while((option_val =getopt(argc,argv,"n:c:u:a:h:f:o:d:G:e"))!= -1)
	{
		switch(option_val)
		{
			case'n':
				if(optarg != NULL)
				    counter = atoi(optarg);
				    int i;
			    	for (i=0; i <counter;++i)
			    	printf("Hello world\n");
				break;
			case'c':{
				    if (argc < 2 ) {
				        printf("Please give hostname as arg\n");
				        exit(0);
				    }
				    if(optarg != NULL)
	                sprintf(hello,"GET / HTTP/1.1\r\nHost:%s\r\n\r\n",optarg);
	                //char hello1[] = "\r\n\r\n";
	                //strcat(hello, hello1);
			    	/*	if(optopt =='u'){
					sprintf(hello,"GET /%s HTTP/1.1\r\nHost:%s\r\n\r\n",argv[4],argv[2]);
					}*/
                    }
				break;
			case'u': 
				sprintf(hello,"GET /~%s HTTP/1.1\r\nHost:%s\r\n\r\n",optarg,argv[2]);
				break;
			case 'a':
		     	sprintf(hello,"GET / HTTP/1.1\r\nHost:%s\r\nUser-Agent:%s\r\n\r\n",argv[2],optarg);
				break;   //argv[2],argv[4]
			case 'h':{
				sprintf(hello,"GET / HTTP/1.1\r\nHost:%s\r\nX-First-Name:%s\r\n\r\n",argv[2],optarg);
				break;
			}
			case'f':
				if((file = fopen(optarg,"r"))) //optarg for reading of file
				{
					while(fgets(string,sizeof(string),file))
					{
						printf("%s\n",string);
					}
				}
				fclose(file);
				break;
			case 'o':{
				if((fileout = fopen(optarg,"w"))){
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
				    printf("%s\n",buffer );
					fprintf(fileout,"%s\n",buffer);               //fprintf(fileout,"%s\n",buffer);
				}
				fclose(fileout);
				break;
			}
			case'?':

				if (optopt == 'u')
				{
				if((fileout = fopen(optarg,"w"))){
				char a[] = "hello world";
				fprintf(fileout,"%s",a);
				}
				fclose(fileout);
				}
                else
				
				break;
			case'd':
				if(optarg != NULL)
				
				 sprintf(hello, "POST /~devrim/test.php HTTP/1.1\r\nHost:db.ciu.edu.tr\r\n\r\n%s&%s\r\n",optarg,optarg);
				/*Curl method*/
		    	/*char *data="name=daniel&project=curl";
                curl_easy_setopt(easyhandle, CURLOPT_POSTFIELDS, data);
                curl_easy_setopt(easyhandle, CURLOPT_URL, "http://db.ciu.edu.tr/~devrim/test.php/");
                curl_easy_perform(easyhandle); /* post away! */
				break;
			case'G':
				if(optarg != NULL)
				sprintf(hello,"GET /~devrim/test.php?%s&%s HTTP/1.1\r\nHost:db.ciu.edu.tr\r\n\r\n",optarg,optarg);
				break;
			case'e':
				srand((unsigned) time(&t));
				rand_num = rand()%100;
				if(rand_num%2 !=0)
				    rand_num +=1;
				printf("%d\n",rand_num);
				break;
			default:
			//	printf("You chose wrong");
				return 0;
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
/**/
