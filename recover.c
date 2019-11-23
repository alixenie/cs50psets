//Recovers jpegs from corrupted raw file
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //ensure correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    //open raw file
    char *rawFileName = argv[1];
    FILE *rawFile = fopen(rawFileName, "r");

    //open image file
    if (rawFile == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        return 2;
    }

    //get some variables
    BYTE buffer[512];
    FILE *recoveredFile = NULL;
    int fileCount = 0;

    //read the raw file
    while (fread(buffer, sizeof(BYTE), 512, rawFile))
    {
        //get some more variables
        char recoveredFileName[8];
        bool isFound = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        //found any jpegs?
        if (isFound)
        {
            if (fileCount != 0)
            {
                //not first jpeg
                fclose(recoveredFile);
            }

            sprintf(recoveredFileName, "%03i.jpg", fileCount);
            recoveredFile = fopen(recoveredFileName, "w");

            // can't open file
            if (recoveredFile == NULL)
            {
                fprintf(stderr, "Something went wrong\n");
            }

            //recover the first 512 bytes of the file
            fwrite(buffer, sizeof(BYTE), 512, recoveredFile);

            //change the count for the next file
            fileCount++;
        }

        //keep recovering the file until you find the start of a new one
        else if (fileCount > 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, recoveredFile);
        }
    }

    //clean up
    fclose(recoveredFile);
    fclose(rawFile);
    return 0;
}