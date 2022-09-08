#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

unsigned char LEDs;

int LED_function(int input) {
    /*
    * 
    your code
    */
    LEDs = (1 << input);
    return LEDs;
}

int main() {
    int val;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            val = LED_function(j);
            printf("%d ", val);
        }
        for (int j = 6; j >= 1; j--) {
            val = LED_function(j);
            printf("%d ", val);
        }
    }
    return 0;
}
