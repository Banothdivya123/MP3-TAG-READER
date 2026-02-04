#include "mp3_header.h"

int main(int argc, char *argv[])
{
    /* structure variable declaration */
    struct MP3 mp3;

    int ret = validate_cla(argc,argv,&mp3);         //Validate command line arguments 
    printf("It is a mp3 file\n");       //confirmation message
    if(ret == VIEW)         //If user selected view option 
    {
       view(&mp3);
    }
    else if(ret == EDIT)        //If user selected edit option
    {
        edit(argc,argv,&mp3);
    }

    return 0;

}
