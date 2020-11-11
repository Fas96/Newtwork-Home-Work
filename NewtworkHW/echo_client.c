#include "mysocket.h"


#define BUF_SIZE 1024
#define TRUE 1

int main(int argc, char* argv[]){

	struct sockaddr_in serv_addr;
	int csock;
  	char message[BUF_SIZE];
  	int message_len,readMessageChecker;
  	int messageCount; 
  	const char address[]= "192.168.1.1";

	  if(argc!=3)
	  {
	    printf("Usage %s port\n",argv[0]);
	    exit(2);
	  }


	printf("hereh");
	int recVal = client_socket((int*)&csock,(const char *)argv[1], argv[2]);
	
	printf("hereh");
	if(recVal>0){
		printf("Connected success\n");
	}else if(recVal==-1){
	 	perror("Socket creation error");
	}else if(recVal==-2){
		perror("Connection error");
	}
	
	while(TRUE) {
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);
		
		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
			break;

		message_len=write(csock, message, strlen(message));
		readMessageChecker=tcp_read_string(csock, message, message_len);
		if(readMessageChecker==0){
			printf("Message from server: %s", message);
		}else if(readMessageChecker==-1)
			printf("Message Reading failure!!!\n");
		 
	}
	close(csock);
	return 0;
}
