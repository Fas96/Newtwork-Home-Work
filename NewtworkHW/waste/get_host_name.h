#include "headerfiles.h"
#include "mysocket.h"
char* get_host_name(const char *addr){
	struct hostent *host;
	struct sockaddr_in addrr;
	int i ;
	 if (!host)
		error_handling("gethost .. errror");
		 
		

	 memset(&addr, 0, sizeof(addr));

	 addrr.sin_addr.s_addr = inet_addr(addr);
	 host = gethostbyaddr((char*)&addrr.sin_addr, 4, AF_INET);

	 if (!host)
		 printf("gethost error!!\n");
		 

	 printf("official name:%s\n",host->h_name);

	 for (size_t i = 0; host->h_aliases[i]; i++)
		 printf("Aliases %d: %s \n",i+1,host->h_aliases[i]);

	 printf("Address type: %s\n",(host->h_addrtype==AF_INET)?"AF_INET":"AF_INET6");


	 for (size_t i = 0; host->h_aliases[i]; i++)
		 return inet_ntoa(*(struct in_addr*)host->h_addr_list[i]);

	


}
