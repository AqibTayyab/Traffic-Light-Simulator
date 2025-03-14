# Traffic Light Simulator

## Overview
This is a simple C++ simulation of a traffic light system that changes lights based on a timed cycle. The simulation includes real-time conditions, such as pedestrian crossing requests and emergency vehicle priority.

## Features
- Simulates a traffic light cycle (Red, Green, Yellow)
- Handles pedestrian crossing requests, delaying the green light
- Detects emergency vehicles and keeps the red light active
- Uses multi-threading for continuous execution
- User interaction via console input

## Requirements
- C++ Compiler (G++/Clang/MSVC)
- C++11 or later

## Installation & Usage
1. Clone the repository:
   ```sh
   git clone https://github.com/AqibTayyab/Traffic-Light-Simulator.git
   cd Traffic-Light-Simulator
   ```
2. Compile the program:
   ```sh
   g++ main.cpp -o main -std=c++11 -pthread
   ```
3. Run the executable:
   ```sh
   ./main
   ```
4. User Inputs:
   - Press `1` to simulate an emergency vehicle (keeps the red light active)
   - Press `2` to simulate a pedestrian crossing (delays green light activation)
   - Press `0` to exit the simulation

## Example Output
```
Traffic Light Simulation Started
Press 1 for Emergency Vehicle, 2 for Pedestrian, 0 to exit
RED Light - Stop!
GREEN Light - Go!
YELLOW Light - Caution!
Pedestrian waiting, delaying GREEN light!
Emergency vehicle detected, keeping RED light!
```

## Contributing
Feel free to fork the repository and submit pull requests for improvements.

## License
This project is open-source and available under the MIT License.

