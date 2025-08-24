//Dliverable: a c program demonstrating various file operations.

#include <stdio.h>
#include <stdlib.h> // Required for exit()
int main()
 {
    FILE *fptr;
    char data[100];

    // --- Writing to a file --- 
    fptr = fopen("example.txt", "w"); // Open file in write mode ("w")

    if (fptr == NULL) {
        printf("Error opening file for writing!\n");
        exit(1); // Exit if file cannot be opened
    }

    printf("Enter data to write to file: ");
    fgets(data, sizeof(data), stdin); // Read input from user
    
    fprintf(fptr, "%s", data); // Write data to file
    fclose(fptr); // Close the file

    printf("Data written successfully.\n");

    // --- Reading from a file ---
    fptr = fopen("example.txt", "r"); // Open file in read mode ("r")

    if (fptr == NULL)
    {
        printf("Error opening file for reading!\n");
        exit(1); // Exit if file cannot be opened
    }

    printf("\nReading data :\n");
    while (fgets(data, sizeof(data), fptr) != NULL) 
    {
        printf("%s", data); // Print data read from file
    }
    fclose(fptr); // Close the file

    // --- Appending to a file ---
    fptr = fopen("example.txt", "a"); // Open file in append mode ("a")

    if (fptr == NULL)
    {
        printf("Error opening file for appending!\n");
        exit(1); // Exit if file cannot be opened
    }

    printf("\nEnter additional data to append: ");
    fgets(data, sizeof(data), stdin); // Read input from user

    fprintf(fptr, "%s", data); // Write data to file
    fclose(fptr); // Close the file

    printf("Data appended  successfully.\n");

    // --- Reading after appending ---
    fptr = fopen("example.txt", "r"); // Open file in read mode ("r")

    if (fptr == NULL) 
    {
        printf("Error opening file for reading after append!\n");
        exit(1); // Exit if file cannot be opened
    }

    printf("\nReading data after appending:\n");
    while (fgets(data, sizeof(data), fptr) != NULL) 
    {
        printf("%s", data); // Print data read from file
    }
    fclose(fptr); // Close the file

    return 0;
}
