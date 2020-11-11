#include "headerfiles.h"

int is_official_name(const char* name) { 
    struct  hostent *myent;
    struct in_addr  myen;
    long int *add;

    myent = gethostbyname(name);
    
    if (myent == NULL)
    {
        perror("ERROR : ");
        return -1;
    }

   if(name== myent->h_name){
   return 1;
   }else if(name==myent->h_aliases){
   return 0;
   }


}
