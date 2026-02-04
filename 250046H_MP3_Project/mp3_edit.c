#include "mp3_header.h"

//Edits a specific ID3 tag in the MP3 file and updates it

void edit(int argc, char *argv[],struct MP3 *mp3)
{
    //Open original MP3 file in read mode 
    mp3->org_mp3_fptr= fopen(mp3->mp3_filename,"r");
    //Create a temporary MP3 file to write updated data
    mp3->dup_mp3_fptr= fopen("temp.mp3","w");

    if(mp3->org_mp3_fptr == NULL )      //Check if original file exists 
    {
        printf("File Not Availble\n");
        return ;
    }
    char header[10];
    fread(header,10,1,mp3->org_mp3_fptr);       //Read and copy the first 10 bytes of header
    fwrite(header,10,1,mp3->dup_mp3_fptr);
    
    for(int i=1;i<=6;i++)       //loop for 6 frames
    {
        
        char tag[5]= {0};           //read the frame tags
        fread(tag,4,1,mp3->org_mp3_fptr);
        fwrite(tag,4,1,mp3->dup_mp3_fptr);
        if(strcmp(tag,mp3->given_tag) == 0)         // If current tag matches the tag to be edited
        {
            int size;                       //read frame size

            fread(&size,4,1,mp3->org_mp3_fptr);
            toggle_endianess(mp3, (char *)&size);       //convert size big endiann to little endian
            
            int new_size = strlen(argv[3])+1;
            toggle_endianess(mp3, (char *)&new_size);       //conver the new size from bigendian to little endian
            
            fwrite(&new_size,4,1,mp3->dup_mp3_fptr);        //write new frame size
            
            char flag[3];                                      //Read and copy frame 3 byte flags
            fread(flag,3,1,mp3->org_mp3_fptr); 
            fwrite(flag,3,1,mp3->dup_mp3_fptr);
            toggle_endianess(mp3, (char *)&new_size);           //Convert new size back for internal use 
            fwrite(argv[3],new_size-1,1,mp3->dup_mp3_fptr);      //Write updated tag content 
            fseek(mp3->org_mp3_fptr,size-1,SEEK_CUR);           // for skip old tag data into original file
            print_edit(argv,mp3);               //print success message
            break;
        }
        else
        {                                       //If tag does not match, copy it as is it
            int size;
            fread(&size,sizeof(int),1,mp3->org_mp3_fptr);           //read frame size
            fwrite(&size,sizeof(int),1,mp3->dup_mp3_fptr);            //write frame size

            char flag[3];                                              //read and write flags
            fread(flag,3,1,mp3->org_mp3_fptr);
            fwrite(flag,3,1,mp3->dup_mp3_fptr);
            toggle_endianess(mp3, (char *)&size);               //Convert size to little endian

            for(int i=0;i<size-1;i++)                   //Copy frame data byte by byte
            {
                char ch;
                fread(&ch,1,1,mp3->org_mp3_fptr);
                fwrite(&ch,1,1,mp3->dup_mp3_fptr);
            }
        }
  
    }
    //Copy remaining data after ID3 tags 
    print_tag_data(mp3);

    remove(mp3->mp3_filename);          //Replace original file with updated file
    rename("temp.mp3",mp3->mp3_filename);
    fclose(mp3->org_mp3_fptr);          //close both files
    fclose(mp3->dup_mp3_fptr);
    
}
//Copies remaining MP3 data after tag editing
void print_tag_data(struct MP3 *mp3)
{
    //Copy remaining bytes till end of file 
    char ch;
    while(fread(&ch,1,1,mp3->org_mp3_fptr ) == 1)
    {
        fwrite(&ch,1,1,mp3->dup_mp3_fptr );
    }
    
}