#include "headerfiles.h"
#define BUF_SIZE 1024

 int tcp_read_string(int sock, char* str, int nbytes) {
	  
	 //문자열의 길이를 알고 있
	size_t str_len = 0;
        while(str_len < nbytes) {
        ssize_t recv_len = read(sock, str + str_len, nbytes - str_len);
        if(recv_len > 0) {
            str_len += recv_len;
        } else if(recv_len == 0 || (recv_len == -1 && errno != EINTR)) {
            return -1;
        }
    }
    
    str[str_len] = 0;
    return 0;
    
}

