#include "headerfiles.h"
#define BUF_SIZE 1024

 int server_socket(int* ssock, const char* addr, int port, int qsize) {


	 int  clnt_sock;  
	 struct sockaddr_in serv_adr, clnt_adr; 
	 ssock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	if (ssock == -1) {
     		*ssock = 0;
    		
    		return -1;
	}


	 memset(&serv_adr, 0, sizeof(serv_adr));
	 serv_adr.sin_family = AF_INET;
	 serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	 serv_adr.sin_port = htons(atoi(port));


	if (bind(ssock,(struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
    		 
    		return -2;
	}

	if (listen(ssock, 5) == -1) {
    		 
    		return -3;
	}

	qsize = sizeof(clnt_adr);
	int client_sock = accept(ssock, (struct sockaddr*)&clnt_adr, &qsize);  
	if (client_sock == -1) { 
    		return -4;
	}else{
		return client_sock;
	}

 }

 
