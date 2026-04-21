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
  int sock;
  int addr_len, bytes_read;
  char recv_data[1024], send_data[1024];
  struct sockaddr_in server_addr, client_addr;
}
