#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("1 arg only\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }



    int jpgCount = 0;

    FILE *jpg;

    unsigned char buffer[512];
    char filename[8];

    while (fread(buffer, 1, 512, file) == 512)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {



            if (jpgCount == 0)
            {
                sprintf(filename, "%03i.jpg", 0);
                jpg = fopen(filename, "w");
                fwrite(buffer, 1, 512, jpg);
                jpgCount++;
                //open but don't close
            }

            else
            {
                fclose(jpg);
                sprintf(filename, "%03i.jpg", jpgCount);
                jpg = fopen(filename, "w");
                fwrite(buffer, 1, 512, jpg);
                jpgCount++;
                //close and then open new based on count
            }
        }

        else if (jpgCount != 0)
        {
            fwrite(buffer, 1, 512, jpg);
            //continue to write
        }

    }
    fclose(jpg);
    fclose(file);

}
