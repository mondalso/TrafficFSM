#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef enum { RED, YELLOW, GREEN } LightState;
typedef enum { WAIT, WALK } PedestrianState;

typedef struct {
    LightState currentSt;
    int timer;
} TrafficSignal;

typedef struct {
    PedestrianState currentSt;
    bool buttonPressed;
    int timer;
} PedestrianLight;

void traffic_signal_update(TrafficSignal *signal) {
    switch (signal->currentSt){
        case GREEN:
            if(signal->timer >= 10){
                signal->currentSt = YELLOW;
                signal->timer = 0;
                printf("Traffic light: YELLOW\n");
            }
            break;
        case YELLOW:
            if(signal->timer >= 3){
                signal->currentSt = RED;
                signal->timer = 0;
                printf("Traffic light: RED\n");
            }
            break;
        case RED:
            if(signal->timer >= 7){
                signal->currentSt = GREEN;
                signal->timer = 0;
                printf("Traffic light: GREEN\n");
            }
            break;
    
    }
    signal->timer++;
}

void pedestrian_light_update(PedestrianLight *light, TrafficSignal *signal){
    switch(light->currentSt){
        case WAIT:
            if(signal->currentSt == RED && light->buttonPressed){
                light->currentSt = WALK;
                light->timer = 0;
                light->buttonPressed = false;
                printf("Pedestrian light: WALK\n");
            }
            break;
        case WALK:
            if (light->timer >= 5) {
                light->currentSt = WAIT;
                light->timer = 0;
                printf("Pedestrian light: WAIT\n");
            }
            break;
    }
    light->timer++;
}

int main() {
    TrafficSignal signal = {RED, 0};
    PedestrianLight pedestrian = {WAIT, false, 0};

    while (1) {
        traffic_signal_update(&signal);

        // Simulate pedestrian pressing the button
        if (signal.currentSt == RED && pedestrian.currentSt == WAIT) {
            pedestrian.buttonPressed = true;
        }

        pedestrian_light_update(&pedestrian, &signal);

        // Sleep to simulate time passing (e.g., 1 second per update)
        sleep(1);
    }

    return 0;
}
