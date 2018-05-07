#include  <sys/types.h> /* basic system data types */
#include  <sys/socket.h>  /* basic socket definitions */

#include <stdio.h>

int
main(int argc, char* argv[]) {
  int socketfd, n;
  char recvline[1024];
  struct sockaddr_in servaddr;

  if (argc < 2) {
    printf("usage %s <IPaddress>", argv[0]);
    exit(1);
  }

  if ( ( socketfd = socket(AF_INET, SOCK_SREAM, 0)) < 0) {
    fprintf(stderr, "socket error\n");
    exit(-1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(13);

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "inet_pton error for %s\n", argv[1]);
    exit(-1);
  }

  if (connect(socketfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    fprintf(stderr, "connect error\n");
    exit(-1);
  } 

  while ( (n = read(socketdf, recvline, 1023)) > 0) {
    recvline[n] = 0;
    if (fputs(recvline, stdout) == EOF) {
      fprintf(stderr, "fputs error\n");
      exit(-1);
    }
  }
  
  if ( n < 0 ) {
    fprintf(stderr, "read error\n");
    exit(-1);
  }

  exit(0);
}
