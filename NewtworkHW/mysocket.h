#include <stdlib.h>
#include<stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h> 
#include <stdbool.h>
#include <errno.h> 



 int server_socket(int* ssock, const char* addr, int port, int qsize) {
           
	   
	 struct sockaddr_in serv_addr, clnt_addr; 
	 socklen_t clnt_addr_sz;
	 *ssock  =  socket(PF_INET,SOCK_STREAM, 0);
	
	if (*ssock == -1) {
     		*ssock = 0;
    		return -1;
	}


	 memset(&serv_addr, 0, sizeof(serv_addr));
	  
	 serv_addr.sin_family = PF_INET;
	 serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	 serv_addr.sin_port = htons(port); 


	if (bind(*ssock,(struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) { 
	      
    		return -2;
	}
	 
	if (listen(*ssock, 5) == -1) {
    		 
    		return -3;
	}
	

	clnt_addr_sz = sizeof(clnt_addr);
	
	printf("클라이언트 소켓 연결을 기다리는 중...\n");
	
	int client_sock = accept(*ssock, (struct sockaddr*)&clnt_addr, &clnt_addr_sz);  
	printf("descriptor of client %d\n\n\n",client_sock);
	if (client_sock == -1)
    		return -4;
	 else{
		return client_sock;
		};
	
 
 }

 int client_socket(int* csock, const char* addr, int port) {
	  
	 int decscriptor_len;
	 struct sockaddr_in serv_addr;

	
	 // 서버 소켓 생성 에러(-1)
	 *csock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	 if (*csock == -1){
	 	*csock=0;
		return -1;}

	 memset(&serv_addr, 0, sizeof(serv_addr));
	 serv_addr.sin_family = AF_INET;
	 serv_addr.sin_addr.s_addr = inet_addr(addr);
	 serv_addr.sin_port = htons(port);
	 
	printf("D up hereh\n");
	decscriptor_len = connect(*csock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if ( decscriptor_len== -1){ 
    		*csock=0;
    		return -2;
    		}
	 else{
		return decscriptor_len;
		}
	


 }
 
 // and that the socket is blocking.
int tcp_read_string(int socket,  char* str, int nbytes)
{
    int bytesRead = 0;
    int result;
    while (bytesRead < nbytes)
    {
        result = read(socket, &str[bytesRead], nbytes - bytesRead);
        if (result < 1 )
        {
            return -1;
        }

        bytesRead += result;
    }
    
     str[nbytes]=0;
    return 0;
}
 

 in_addr_t get_host_addr(const char* name, int idx) {

	  struct hostent *host;
	  host = gethostbyname(name); 
	 if (!host){
	 perror("cannot gethost Address error");
	 }
	
	  
	 if(host->h_addr_list[idx]==NULL)
        	host->h_addr_list[idx]=INADDR_NONE;
     
     	return host->h_addr_list[idx];
}

char* get_host_name(const char *addr){
	int *retFail = NULL;
	struct hostent *he;
 	struct in_addr addrz;
	inet_aton(addr, &addrz);
	he = gethostbyaddr(&addrz, sizeof(addrz), AF_INET);

       if(he){
	return (char*) (he->h_name);
	}else{
	return *retFail;
	}


}


int is_official_name(const char* name) { 

	struct hostent *he;

	he = gethostbyname(name);
	if (!he) { // do some error checking
    		return -1;
	}
	//aliases
	if(name==he->h_name)
		return 1;
	else if(name==he->h_aliases)
		return 0;

}

bool write_to_socket(int sock, const char* buffer, size_t size) {
    size_t total_bytes = 0;
    while(total_bytes < size) {
        ssize_t bytes_written = write(sock, buffer + total_bytes, size - total_bytes);
        if(bytes_written >= 0) {
            total_bytes += bytes_written;
        } else if(bytes_written == -1 && errno != EINTR) {
            return false;
        }
    }
    return true;
}


void error_handling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
