#include "mysocket.h"

int main(int argc , char* argv[]) 
{
	 unsigned int host_addr;
	if(argc!=3)
	{
    		printf("Usage %s addr\n",argv[0]);
    		exit(1);
  	}
  
 	host_addr=get_host_addr(argv[1],0); 
 	
	 if (!host_addr)
		 error_handling("gethost .. errror");

	// printf("official name:%s\n",host_addr->h_name);

 	
  	printf("\n\nIP address of %s --> %s\n",argv[1],inet_ntoa(*(struct in_addr*)host_addr));
 
  	printf("Official Name of IP %s --> %s\n",argv[2],get_host_name(argv[2]));


  	printf("%s   ->   %s\n\n",argv[1],((is_official_name(argv[1]))==1)?"Is the Official name Provided":" Is the Aliases");

  return 0;
}
