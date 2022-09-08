#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

unsigned char LEDs;

int LED_function(int input) {
    /*
    * 
    your code
    */
    LEDs = 0;
    for(int i=0; i <input; i++){
        LEDs |= ( 1 << (7-i));
    }
    return LEDs;
}

int main() {
    scanf("%uc", &LEDs);
    int cnt =0;
    for(int i=0; i <8; i ++){
        if( (LEDs & (1 << i ) ) == ( 1 << i )) {
            cnt++;
        }
    }
    printf("1의 개수? %d\n", cnt);

    int value = LED_function(cnt);
    printf("Shift시의 값은? %d", value);
    return 0;
}
