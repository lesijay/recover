#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf("Usage: recover card\n");
        return 0;
    }

    //filenames
    char *imagefile = argv[1];

    //open input file
    FILE *inptr = fopen(imagefile,"r");
}