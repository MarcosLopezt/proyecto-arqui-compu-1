#include <stdio.h>
#include <unistd.h> 

void display_leds(char leds[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", leds[i]);
    }
    printf("\n");
}

void progressive_pattern(char leds[], int size) {
    // prender LEDs uno por uno
    for (int i = 0; i < size; i++) {
        leds[i] = '*';
        display_leds(leds, size);
        usleep(500000); 
    }

    // apagar LEDs uno por uno
    for (int i = 0; i < size; i++) {
        leds[i] = '_';
        display_leds(leds, size);
        usleep(500000); 
    }
}

int main() {
    char leds[] = {'_', '_', '_', '_', '_', '_', '_', '_'}; 
    int size = sizeof(leds) / sizeof(leds[0]);

    while (1) {
        progressive_pattern(leds, size);
    }

    return 0;
}
