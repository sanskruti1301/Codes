#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char words[100][100]; // Assuming a maximum of 100 words, each with a maximum length of 100 characters
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from fgets
    sentence[strcspn(sentence, "\n")] = '\0';

    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Reconstruct the reversed sentence
    printf("Reversed sentence: ");
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
