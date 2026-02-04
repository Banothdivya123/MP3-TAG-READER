#ifndef MP3_HEADER_H
#define MP3_HEADER_H

#include <stdio.h>          //Standard input-output functions 
#include <string.h>          //string handling function

//Macro definitions for program modes 

#define VIEW 	1           //View MP3 tag information
#define EDIT 	2           //Edit MP3 tag information


struct MP3
{
    char *mp3_filename;         // Stores MP3 file name
    FILE *org_mp3_fptr;         // File pointer for original MP3 file
    FILE *dup_mp3_fptr;         // File pointer for temporary MP3 file
    char given_tag[5];           // Stores the tag to be edited
};

int validate_cla(int argc, char *argv[], struct MP3 *mp3);      //Validates command line arguments
void view(struct MP3 *mp3);                                     //Displays MP3 tag information 
void edit(int argc, char *argv[],struct MP3 *mp3);              //Edits a specific tag in the MP3 file 
void toggle_endianess(struct MP3 *mp3, char *size);             //Converts data between big-endian and little-endian
void print_tag_data(struct MP3 *mp3);                           //Copies remaining MP3 data after tag processing 
void tag_to_name(char *);                                        //Copies remaining MP3 data after tag processing 
void print_edit(char *argv[],struct MP3 *mp3);                     //it prints edit success message
#endif
