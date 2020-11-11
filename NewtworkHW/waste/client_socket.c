#include "headerfiles.h"
#define BUF_SIZE 1024

 int client_socket(int* csock, const char* addr, int port) {
	  
	 int str_len;
	 struct sockaddr_in serv_adr;

	
	 // 서버 소켓 생성 에러(-1)
	 csock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	 if (csock == -1)
	 	*csock=0;
		return -1;

	 memset(&serv_adr, 0, sizeof(serv_adr));
	 serv_adr.sin_family = AF_INET;
	 serv_adr.sin_addr.s_addr = inet_addr(addr);
	 serv_adr.sin_port = htons(atoi(port));
	 
	 int recVal = connect(csock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));

	if (recVal == -1) {
    		*csock=0;
    		return -2;
	}else{
		return recVal;
	}


 	
 	}
 
