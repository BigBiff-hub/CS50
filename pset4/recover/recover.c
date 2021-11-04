#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_size 512

typedef uint8_t BYTE;



void ArgCount(int argc);
void fileExists(FILE *file);
int checkJPEG(BYTE buffer[]);

int main(int argc, char *argv[])
{
    ArgCount(argc);
    FILE *raw = fopen(argv[1], "r");
    fileExists(raw);


    BYTE buffer[BLOCK_size];


    char filename[8];
    FILE *image;
    int counter = 0;

    // find first jpeg
    while (fread(buffer, BLOCK_size, 1, raw) == 1)
    {
        if (checkJPEG(buffer) == 1)
        {
            // close prev jpeg
            if (counter != 0)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", counter++);
            image = fopen(filename, "w");
            fwrite(buffer, BLOCK_size, 1, image);
        }

        else if (counter > 0)
        {
            fwrite(buffer, BLOCK_size, 1, image);
        }
    }
}


void fileExists(FILE *file)
{
    if (file == NULL)
    {
        printf("File could not be opened.\n");
        exit(1);
    }
}

int checkJPEG(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}
void ArgCount(int argc)
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        exit(1);
    }
}