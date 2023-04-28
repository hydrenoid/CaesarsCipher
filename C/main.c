/**
 * Created by Jonathon Moore
 * SWE-450
 * Professor Mark
 *
 * This module is the main driving code for the application.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "hardware.h"
#include "structures.h"


int main() {
    // initialize connection to GPIO pins
    initializeHardware();
    setupParallelPort();

    // greet user
    printf("-------------------------------------\n");
    printf("Welcome to Caesars Cipher\n");
    printf("To begin follow these steps:\n");
    printf("    1) Set switch 10 to high, this is the enabling pin\n");
    printf("    2) Use switch 5 to set encode (low) or decode (high)\n");
    printf("    3) Use switches 1-4 to set the key\n");
    printf("    4) Enter message into terminal and will return the output message\n");
    printf("-------------------------------------\n");

    char message[100];
    char decoded_message[100];

    while(1)
    {
        // prompt user to enter passphrase
        printf("Input message: ");
        fgets(message, sizeof(message), stdin);

        // declare variable for main loop
        int i, result, ascii_value, size;
        char output;
        for (i = 0; i < strlen(message); i++) {
            // check to see if it is a space
            if(message[i] == " ")
            {
                decoded_message[i] = " ";
            }
            else {
                // map the character to its ascii value
                ascii_value = toupper(message[i]);

                setPins(ascii_value);

                // read the output pins
                result = readPins();
                output = result;

                // add the character to the new string
                decoded_message[i] = output;
            }
        }

        // if there is no more letters, then display the new phrase
        printf("Output Message: %s\n", decoded_message);
        printf("---------------------\n");

        // clear the messages from memory
        memset(message, 0, sizeof(message));
        memset(decoded_message, 0, sizeof(decoded_message));
    }
    // close hardware
    closeResources();

    return 0;
}



