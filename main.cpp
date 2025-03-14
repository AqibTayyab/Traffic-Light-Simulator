#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Enum for traffic light states
enum LightState { RED, GREEN, YELLOW };

// Function to simulate the traffic light cycle
void trafficLightSimulation(bool emergency = false, bool pedestrian = false) {
    LightState currentLight = RED; // Initial state

    while (true) {
        switch (currentLight) {
            case RED:
                cout << "RED Light - Stop!\n";
                this_thread::sleep_for(chrono::seconds(5)); // Red light duration

                // If an emergency vehicle is detected, stay red
                if (emergency) {
                    cout << "Emergency vehicle detected, keeping RED light!\n";
                    continue;
                }
                currentLight = GREEN;
                break;

            case GREEN:
                // If a pedestrian is waiting, delay green
                if (pedestrian) {
                    cout << "Pedestrian waiting, delaying GREEN light!\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    pedestrian = false; // Pedestrian has crossed
                }
                cout << "GREEN Light - Go!\n";
                this_thread::sleep_for(chrono::seconds(5)); // Green light duration
                currentLight = YELLOW;
                break;

            case YELLOW:
                cout << "YELLOW Light - Caution!\n";
                this_thread::sleep_for(chrono::seconds(2)); // Yellow light duration
                currentLight = RED;
                break;
        }
    }
}

int main() {
    bool emergency = false;
    bool pedestrian = false;

    cout << "Traffic Light Simulation Started\n";
    cout << "Press 1 for Emergency Vehicle, 2 for Pedestrian, 0 to exit\n";

    thread trafficThread(trafficLightSimulation, ref(emergency), ref(pedestrian));

    while (true) {
        int input;
        cin >> input;

        if (input == 1) {
            emergency = true; // Emergency vehicle detected
        } else if (input == 2) {
            pedestrian = true; // Pedestrian crossing request
        } else if (input == 0) {
            cout << "Exiting Simulation...\n";
            exit(0);
        }
    }

    trafficThread.join(); // Join the thread
    return 0;
}
