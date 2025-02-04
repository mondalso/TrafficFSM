# Traffic Signal and Pedestrian Light Simulation

## Overview
This project simulates a **traffic signal system** and a **pedestrian crossing light**. The traffic signal cycles through **GREEN, YELLOW, and RED** states, while the pedestrian light transitions between **WAIT and WALK** states when the pedestrian button is pressed.

## Features
- The **traffic light** follows a fixed sequence:
  - **GREEN** for 10 seconds
  - **YELLOW** for 3 seconds
  - **RED** for 7 seconds
- The **pedestrian light** follows these rules:
  - When the traffic light is **RED**, pedestrians can press a button to turn the light to **WALK**.
  - The **WALK** signal lasts for 5 seconds before switching back to **WAIT**.
- The program runs in a continuous loop, simulating real-world traffic behavior.

## How It Works
1. The **traffic light** updates its state based on a timer.
2. The **pedestrian light** changes state when the button is pressed, provided the traffic signal is **RED**.
3. The program prints updates to the console, showing the current state of both lights.

## Requirements
- **C Compiler** (e.g., GCC)
- **POSIX-compliant OS** (e.g., Linux, macOS) due to the use of `sleep()`

## Compilation and Execution
To compile the code, run:

```sh
gcc traffic_signal.c -o traffic_signal
```

To execute the program:

```sh
./traffic_signal
```

## Expected Output
Example output showing the state transitions:

```
Traffic light: RED
Pedestrian light: WALK
Traffic light: GREEN
Traffic light: YELLOW
Traffic light: RED
Pedestrian light: WAIT
...
```

## Future Improvements
- Add user input to manually trigger the pedestrian button.
- Implement a graphical representation of the signals.
- Introduce real-time scheduling for precise timing.

## License
This project is open-source and available under the **MIT License**.

