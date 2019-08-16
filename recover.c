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

    //open input file
    FILE *inptr = fopen(imagefile,"r");

    //Error code incase file doesn't exist
    if( imagefile == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }
}