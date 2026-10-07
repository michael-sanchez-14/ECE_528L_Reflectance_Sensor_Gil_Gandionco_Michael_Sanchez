/** 
 *
 * @file print_binary.c
 *
 * @brief Main source code for Print_Binary program.
 *
 * This file contains the main entry point and the implementation
 * of the Print_Binary function that takes in a uint8_t value and
 * prints the value in binary format.
 * 
 * @ authors Gil Gandionco and Michael Sanchez
*/

#include <stdio.h>
#include <stdint.h>

void Print_Binary(uint8_t value_to_convert);

int main()
{
    uint8_t value_to_convert = 170;

    printf("Decimal: %d\n", value_to_convert);
    Print_Binary(value_to_convert);
        
    return 0;
}

void Print_Binary(uint8_t value_to_convert)
{
    uint8_t bit;
    printf("Binary: ");
    for(int i = 7; i >= 0; i--)
    {
        bit = (value_to_convert >> i) & 1;
        printf("%d", bit);
        if(i == 4)
        {
            printf("_");
        }
    }
}