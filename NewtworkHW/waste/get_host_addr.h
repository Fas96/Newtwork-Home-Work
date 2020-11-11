#include "headerfiles.h"
 in_addr_t get_host_addr(const char* name, int idx) {

	  struct hostent *host = gethostbyname("www.naver.com");
	 if (!host)
		 return inet_addr(host);
	
	 printf("debug %s\n",host->h_addr_list[idx]);
	return inet_addr((char*)host->h_addr_list[idx]);
	 
}
