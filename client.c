#include "lib.h"




int main() {
   
   char buffer[MAXLINE];
   char message[MAXLINE];   
   int sockfd;
  struct sockaddr_in servaddr;
   sockfd = socket(AF_INET, SOCK_DGRAM, 0); // AF_INET = IPV4 | SOCK_DGRAM = UDP
   if (sockfd == -1) {
    perror( "Socket error"); //pererror = errno to print the error thats causing
     exit(1);
     }
   //clear addr sv
   bzero(&servaddr, sizeof(servaddr));
   // config server addr
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = inet_addr(LOCALIP);
   servaddr.sin_port = htons(PORT); 

   while(1){
   printf("Digite a mensagem: ");
    fgets(message, MAXLINE, stdin);

   sendto(sockfd, message, strlen(message), 0, 
           (const struct sockaddr *) &servaddr, sizeof(servaddr));
    }
}


