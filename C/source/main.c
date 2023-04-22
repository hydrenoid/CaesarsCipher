#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "hardware.h"
#include "structures.h"



/**
 * Takes in a decimal number and returns a pointer to an int array containing
 * the binary representation
 * @param decimal
 * @param binary
 * @return the binary representation of the given decimal number
 */
int* decimalToBinary(int decimal, int *binary) {
    int i = 0, j = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    int size = i;
    for (i = 0, j = size - 1; i < j; i++, j--) {
        int temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }
    return binary;
}

/**
 * Takes in an array of binary and returns the decimal version
 * @param binary
 * @param size
 * @return the decimal of the binary passed in
 */
int binaryToDecimal(int *binary, int size) {
    int decimal = 0, power = 0;
    for (int i = size - 1; i >= 0; i--) {
        decimal += binary[i] * pow(2, power);
        power++;
    }
    return decimal;
}


int main() {
    // initialize connection to GPIO pins
    initializeHardware();
    setupParallelPort();

    // prompt user whether they would like to encode or decode message
    int toDecode;
    printf("Would you like to encode or decode a message? (0, 1)");
    scanf("%d", &toDecode);
    if (toDecode == 1) {
        setDecode(1);
    }

    // set decoding pin to 1 or 0

    // prompt user to set the key with switches
    printf("MAKE SURE TO SET KEY WITH SLIDE SWITCHES\n");

    // prompt user to enter passphrase
    char message[100];
    printf("Enter the message that you would like to process.");
    scanf("%s", message);
    printf("The message entered is: %s\n", message);

    // prompt user to enter a key (temporary)
    int key;
    printf("Enter the key you would like to use (1-16)\n");
    scanf("%d", &key);
    printf("The chosen key is: %d", key);

    // declare variable for main loop
    char decoded_message[100];
    int beginning_binary[100];
    int i;
    int length = strlen(message);
    char output;
    int ascii_value;
    int result;
    int size;
    for (i = 0; i < length; i++) {
        // map the character to its ascii value
        ascii_value = toupper(message[i]);

        printf("\nvalue of %c = %d: ", message[i], ascii_value);

        // set the input pins to the numbers value in binary
//        result = decimalToBinary(ascii_value, beginning_binary);
//        if (ascii_value > 0) {
//            size = log2(ascii_value) + 1;
//        } else {
//            size = 1;
//        }
        setPins(ascii_value);

//        printf("Binary is : ");
//        for (int i = 0; i < size; i++) {
//            printf("%d", result[i]);
//        }
//        printf("\n");
//        setPins(result, size);

        // read the output pins
        result = readPins();

        // turn the bits to decimal
//        ascii_value = binaryToDecimal(result, size);
//        printf("\nthe returned binary number is: ");
//        for (int i = 0; i < size; i++) {
//            printf("%d", result[i]);
//        }

        // map the number to its corresponding character
        if (toDecode == 1) {
            output = result - key;
        } else {
            output = result + key;
        }

        printf("\nvalue is %d", ascii_value);
        printf("\n%c\n", output);

        // add the character to the new string
        decoded_message[i] = output;
    }

    // if there is no more letters then display the new phrase
    printf("%s", decoded_message);

    return 0;
}



