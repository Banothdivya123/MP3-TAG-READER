#include "mp3_header.h"

void view(struct MP3 *mp3)
{
    //Display header
    printf("-------------------------------------------------------\n");
    printf("MP3 Tag Reader and Editor for ID3v2\n");
    printf("-------------------------------------------------------\n");
    //Open MP3 file in read mode 
    FILE *org_mp3_fptr=fopen(mp3->mp3_filename,"r");
    if(org_mp3_fptr == NULL)            //Check if file exists
    {
       printf("Invalid file\n");
       return ;
    }
    fseek(org_mp3_fptr ,10,SEEK_CUR);           //Skip the first 10 bytes 

    for(int i=0;i<6;i++)            //read first 6 frames
    {
        char tag[5];                        //read tags
        fread(tag,4,1,org_mp3_fptr);
        int frame_size;
        tag[4]='\0';                        // Null-terminate tag string
        fread(&frame_size,sizeof(int),1,org_mp3_fptr);          //read framesize
        toggle_endianess(mp3,(char *) &frame_size);         //Convert frame size from big-endian to little-endian 
        fseek(org_mp3_fptr,3,SEEK_CUR);             //skip frame flags

        tag_to_name(tag);               //Print readable tag name 
        // Read and print frame data 
        for(int i=0;i<frame_size-1;i++)
        {
            char ch;
            fread(&ch,1,1,org_mp3_fptr);
            printf("%c",ch);
        }
        printf("\n");
        
    }
    fclose(org_mp3_fptr);           //close the mp3 file
    printf("-------------------------------------------------------------\n");
    

}

