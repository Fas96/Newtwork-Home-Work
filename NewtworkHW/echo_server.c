#include "mysocket.h"
#define BUF_SIZE 1024 

int main(int argc , char* argv[]) {

  int serv_sock;
  
  char message[BUF_SIZE];
  int message_len;
  int qeueSize=10;
  int strlen;
  const char* address= "192.168.1.1";


  struct sockaddr_in serv_addr,clnt_addr;
  socklen_t clnt_addr_sz;

  if(argc!=2)
  {
    printf("Usage %s port\n",argv[0]);
  }
    
     int client_sock=server_socket((int*)&serv_sock,(char*)&address,atoi(argv[1]),qeueSize);
       if(client_sock>0){
       	printf("client_sock Connected");
       	while((message_len=read(client_sock, message, BUF_SIZE))!=0)
        	  write(client_sock, message, message_len);
        
            	close(client_sock);
	  
 }
	 if(client_sock==-1)
	 	perror("Socket creation error");
	 else if(client_sock==-2)
	 	perror("Bind error");
	 else if(client_sock==-3)
	 	perror("Listen error");
	 else if(client_sock==-4)
	 	perror("Accept error");
	 	
	
 
	close(serv_sock);

	 return 0;
}
