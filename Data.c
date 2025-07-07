#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressFile(const char *inputPath, const char *outputPath) {
    FILE *in = fopen(inputPath, "r");
    FILE *out = fopen(outputPath, "w");

    if (!in || !out) {
        printf("Error opening files.\n");
        return;
    }

    char currentChar, nextChar;
    int count = 1;

    currentChar = fgetc(in);
    while ((nextChar = fgetc(in)) != EOF) {
        if (nextChar == currentChar) {
            count++;
        } else {
            fprintf(out, "%d%c", count, currentChar);
            currentChar = nextChar;
            count = 1;
        }
    }

    if (currentChar != EOF)
        fprintf(out, "%d%c", count, currentChar);

    fclose(in);
    fclose(out);

    printf("Compression complete.\n");
}

void decompressFile(const char *inputPath, const char *outputPath) {
    FILE *in = fopen(inputPath, "r");
    FILE *out = fopen(outputPath, "w");

    if (!in || !out) {
        printf("Error opening files.\n");
        return;
    }

    int count;
    char ch;

    while (fscanf(in, "%d%c", &count, &ch) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("Decompression complete.\n");
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("Run-Length Encoding Tool\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file path: ");
    scanf("%s", inputFile);
    printf("Enter output file path: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        decompressFile(inputFile, outputFile);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
