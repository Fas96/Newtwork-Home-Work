#include "headerfiles.h"
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
