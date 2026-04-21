#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // adding vars
  int sock; // file descriptor for the socket
  int addr_len,
      bytes_read; // size of the addres structure and number of bytes received
  char recv_data[1024],
      send_data[1024]; // buffer to store incoming data from the client
  struct sockaddr_in server_addr,
      client_addr; // Structures to hold server and client IP/PORT
}
