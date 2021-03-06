/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
/*
 * Function to reverse the string
 */
void strrev(char *str)
{
char  temp;
   int i, j = 0;
i = 0;
   j = strlen(str) - 1;
 
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
}
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char* buffer;
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     //Opening socket 
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     //Assigning address to socket file descripter
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
    // listening limit is 5 
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     while(1)
     {
        //waiting for client ,it is a blocking function 
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     int i=13;
     int j=0;
     buffer=calloc(1,1024);
     char str[70];
     //reading from client
     n = read(newsockfd,buffer,1024);
     if (n < 0) error("ERROR reading from socket");
     /*
      * Bcause this code is created for web browser and handling GET request from web browser so we are generating fresh
      * string from raw data (which is according to protocal).
      */
     while(buffer[i]!=' ')
     {
      
      if(buffer[i]=='%')
      {
        
        i=i+3;
        str[j]=' ';
        j++;
        continue;
      }
     str[j]=buffer[i];
      i++;
      j++;
     }
     str[j]='\0';
     
     strrev(str);
     printf("%s\n",str);
     n = write(newsockfd,str,strlen(str));
     if (n < 0) error("ERROR writing to socket");
     close(newsockfd);
     free(buffer);
     }
     close(sockfd);
     return 0; 
}
