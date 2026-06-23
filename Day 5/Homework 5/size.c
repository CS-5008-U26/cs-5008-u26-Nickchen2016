# include <stdio.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {

    char filename[1000];

    if(argc < 2) { // If no command-line argument was given
        printf("Enter the filename: ");
        scanf("%999s", filename);
    }else {
        // Use the first argument
        snprintf(filename, sizeof(filename), "%s", argv[1]);
    }
    printf("%s", filename);

    struct stat fileInfo;
    if (stat(filename, &fileInfo) != 0) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }

    printf("%s has %lld bytes\n",
           filename,
           (long long) fileInfo.st_size);


    return 0;
}