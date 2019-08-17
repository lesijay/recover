#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Error code incase the number of command line argument is not two
    if(argc != 2)
    {
        fprintf(stderr,"Usage: recover card\n");
        return 0;
    }

    //filenames
    char *imagefile = argv[1];

    //intialize a variable to check if a jpeg file has been found
    bool jpegStarted = false;

    //initialize a variable for recovered images
    int imgRecovered = 0;

    //open input file
    FILE *inptr = fopen(imagefile,"r");

    //Error code incase file doesn't exist
    if( imagefile == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }


    //Declare an array of size of 512 bytes to store 1 block of a memory card
    unsigned char buffer[512]; // data type of unsigned char is used because it can store 1byte(256) all positive integers


    //open an output file pointer
    FILE *outptr;
    //loop through the memory card file until end of file
    while((fread(buffer, 512, 1, inptr) != 0))
    {
        // identify a jpeg file
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[3] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //closes the former outpointer if a new JPEG header has been found
            if (jpegStarted)
            {
                fclose(outptr);
            }else{
                jpegStarted = true; //Resets condition to continue writing the following JPEG image blocks  
            }
            //store the name of the jpeg file,assume it is a string of 4 characters
            char fileName[4];
            sprintf(fileName, "00%i.jpg", imgRecovered);  //instead of printing to the console, it returns a formatted string
        }
        //After identifying a JPEG image,write each block of it into the outfile from the buffer
        if(jpegStarted)
        {
            fwrite(&buffer, 512, 1, outptr);
        }

    }
    //closes the input file and output file after getting to the end of file
    fclose(outptr);

    fclose(inptr);


}

