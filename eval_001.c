#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *inputFile1, *inputFile2, *outputFile;
    char sentence1[100], sentence2[100], word[20], replace[20], *ptr;
    int i, j, k;

    // Open input files
    inputFile1 = fopen("input1.txt", "r");
    if (inputFile1 == NULL)
    {
        printf("Error opening input1.txt file\n");
        exit(1);
    }

    inputFile2 = fopen("input2.txt", "r");
    if (inputFile2 == NULL)
    {
        printf("Error opening input2.txt file\n");
        exit(1);
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening output.txt file\n");
        exit(1);
    }

    // Read in the first sentence
    fgets(sentence1, 100, inputFile1);

    // Read in the second sentence
    fgets(sentence2, 100, inputFile2);

    // Prompt user to enter word to be replaced and replacement word
    printf("Enter word to be replaced: ");
    scanf("%s", word);

    printf("Enter replacement word: ");
    scanf("%s", replace);

    // Replace the word in sentence1 if found
    ptr = strstr(sentence1, word);
    if (ptr != NULL)
    {
        i = ptr - sentence1;
        j = strlen(word);
        k = strlen(replace);

        memmove(&sentence1[i + k], &sentence1[i + j], strlen(&sentence1[i + j]) + 1);
        memcpy(&sentence1[i], replace, k);
    }

    // Replace the word in sentence2 if found
    ptr = strstr(sentence2, word);
    if (ptr != NULL)
    {
        i = ptr - sentence2;
        j = strlen(word);
        k = strlen(replace);

        memmove(&sentence2[i + k], &sentence2[i + j], strlen(&sentence2[i + j]) + 1);
        memcpy(&sentence2[i], replace, k);
    }

    // Write the modified sentences to the output file
    fprintf(outputFile, "%s", sentence1);
    fprintf(outputFile, "%s", sentence2);

    // Close the files
    fclose(inputFile1);
    fclose(inputFile2);
    fclose(outputFile);

    printf("Replacement successful! Check output.txt file.\n");

    return 0;
}
