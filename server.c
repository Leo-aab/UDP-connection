#include "lib.h"



int main() {
  // adding vars
  int sock; // file descriptor for the socket
  int addr_len,
      bytes_read; // size of the addres structure and number of bytes received
  char recv_data[BUFFER_SIZE],
      send_data[BUFFER_SIZE]; // buffer to store incoming data from the client
  struct sockaddr_in server_addr,
      client_addr; // Structures to hold server and client IP/PORT

  sock = socket(AF_INET, SOCK_DGRAM, 0); // AF_INET = IPV4 | SOCK_DGRAM = UDP
  if (sock == -1) {
    perror("Socket error"); //pererror = errno to print the error thats causing
    exit(1);
  }
    memset(&server_addr, 0, sizeof(server_addr)); //zero bytes before define ip and port
  server_addr.sin_family = AF_INET;   // defining ipv4
  server_addr.sin_port = htons(PORT); // defining port
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY - to bind to all interfaces

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) < 0) {
    perror("bind");
    return 1;
  } // binding
  addr_len = sizeof(struct sockaddr_in); //initalizing of structure
  
   while (1){
     bytes_read = recvfrom(sock, recv_data, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
     if (bytes_read > 0 ) {
      recv_data[bytes_read] = '\0';
      printf("Hellow client: %s\n", recv_data);
     }
     //idk how make this
   }
}
