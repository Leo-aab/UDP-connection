#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
//header for posix sockets



int main() {
  // adding vars
  int sock; // file descriptor for the socket
  int addr_len,
      bytes_read; // size of the addres structure and number of bytes received
  char recv_data[1024],
      send_data[1024]; // buffer to store incoming data from the client
  struct sockaddr_in server_addr,
      client_addr; // Structures to hold server and client IP/PORT

  sock = socket(AF_INET, SOCK_DGRAM, 0); // AF_INET = IPV4 | SOCK_DGRAM = UDP
  if (sock == -1) {
    perror("Socket error"); //pererror = errno to print the error thats causing
    exit(1);
  }
    memset(&server_addr, 0, sizeof(server_addr)); //zero bytes before define ip and port
  server_addr.sin_family = AF_INET;   // defining ipv4
  server_addr.sin_port = htons(5000); // defining port
  server_addr.sin_addr.s_addr =
      INADDR_ANY; // INADDR_ANY - to bind to all interfaces

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) < 0) {
    perror("bind");
    return 1;
  } // binding

   while (1){
     bytes_read = recvfrom(sock, recv_data, 1024, 0, (struct sockaddr *)&client_addr, &addr_len);
     //idk how make this
   }
}
