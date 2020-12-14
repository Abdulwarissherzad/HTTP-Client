// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 80

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[] = "GET / HTTP/1.1\r\nHost:db.ciu.edu.tr\r\n\r\n";
    char buffer[1024] = {0};

    if (argc < 2 ) {
        printf("Please give hostname as arg\n");
        exit(0);
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

