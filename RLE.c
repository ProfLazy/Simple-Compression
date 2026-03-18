#include <stdio.h>
#include <stdlib.h>

// First Idea -> Note down repeating patterns
// If I get AAABBBCCDDEEEFGGG, it will be (3,A)(3,B)(2,C)(2,D)(3,E)(1,F)(3,G)
// I can use a struct to store the count and the character
typedef struct {
    char character;
    int count;
} RepeatedChar;

// Function to compress the string using repeated characters
void compressString(const char *input, RepeatedChar *output, int *size) {

    // Make sure the input string is not empty
    if (input == NULL || input[0] == '\0') {
        *size = 0;
        return;
    }
    
    // Initialize variables
    int count = 1;
    int index = 0;
    char currentChar = input[0];

    // Loop through the input string starting from the second character
    for (int i = 1; input[i] != '\0'; i++) {

        // If character is same as previous, increment count. this works because we are starting from the second character.
        if (input[i] == currentChar) {
            count++;
        } else {

            // If there is a new character
            // We add the previous character and its count to the output array
            output[index].character = currentChar;
            output[index].count = count;
            index++;

            // Reset count for the new character
            count = 1;
            currentChar = input[i];

        }
    }

    // Add the last character and its count to the output array
    output[index].character = currentChar;
    output[index].count = count;
    index++;

    *size = index; 
}

int main() {
    const char *input = "AAABBBCCDDEEEFGGGAA";
    RepeatedChar output[100]; // Assuming the output will not exceed 100 characters
    int size;

    compressString(input, output, &size);

    // Print the original string
    printf("Original String: %s\n", input);

    // Print the compressed string
    printf("Compressed String: ");
    for (int i = 0; i < size; i++) {
        printf("(%d,%c)", output[i].count, output[i].character);
    }
    printf("\n");
    printf("\n");
    printf("\n");

    // Pure random 1's and 0's
    char randomBinaryInput[201];
    for (int i = 0; i < 201; i++) {
        randomBinaryInput[i] = (rand() % 2) ? '1' : '0';
    }

    randomBinaryInput[201] = '\0'; // Null-terminate the string
    
    printf("Random Binary String: ");

    for (int i = 0; i < 201; i++) {
        printf("%c", randomBinaryInput[i]);
    }

    printf("\n");

    // Compressed randomBinaryInput
    RepeatedChar randomBinaryOutput[1000];
    int randomBinarySize;
    compressString((const char*)randomBinaryInput, randomBinaryOutput, &randomBinarySize);

    // Print the compressed random binary string
    printf("Compressed Random Binary String: ");
    for (int i = 0; i < randomBinarySize; i++) {
        printf("(%d,%c)", randomBinaryOutput[i].count, randomBinaryOutput[i].character);
    }
    printf("\n");

    return 0;
}