#include <time.h>
#include <stdio.h>

int
main(int argc, char* argv[]) {
  int listenfd, connectfd;
  struct sockaddr_in servaddr;
  char buff[1024];
  time_t ticks; 

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  
  if (listenfd < 0) {
    
  }
}
