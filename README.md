# ServiceCenter

#### Overview
This project simulates a student services center (SSC) where students arrive at various offices (registrar, cashier, financial aid) needing assistance. The simulation aims to optimize window usage to minimize student wait times and idle window times.

#### Project Structure
- **main.cpp**: Contains the main logic for reading input, initializing the service center, simulating student arrivals and interactions, and calculating performance metrics.
- **input.txt**: Input file specifying the number of windows at each office, student arrival times, and their service requirements.
- **output.txt**: Output file containing metrics such as mean and longest student wait times, mean and longest window idle times, and counts of significant wait and idle times.
- **README.md**: This readme file provides an overview of the project, instructions for compiling and running the code, and additional information.

#### How to Run
To compile and run the program:

1. **Compile**: Use g++ to compile the `main.cpp` file.
   ```bash
   g++ main.cpp -o waiting_game
   ```

2. **Run**: Execute the compiled program with the input file name as a command-line argument.
   ```bash
   ./waiting_game input.txt
   ```
   This will generate an `output.txt` file containing detailed metrics from the simulation.

#### Simulation Details
- **Initialization**: Reads parameters from `input.txt` to set up the SSC with specified number of windows at each office.
- **Simulation Loop**: Models student arrivals, queueing at offices, service times, and window idle times until all student requests are handled.
- **Metrics Calculation**: Computes and logs performance metrics including student wait times, window idle times, and counts of significant waits and idles.

#### Requirements
- C++ compiler (tested with g++)
- Text editor or IDE (e.g., VSCode) for code editing
- Terminal or command prompt for compiling and running the executable
- Adherence to C++ standards and course coding style guidelines
- Use of primitive data structures only; no STL usage allowed.

#### Additional Notes
- The simulation strictly follows provided specifications and constraints.
- No external libraries or non-primitive data structures (e.g., vectors) are used, as per project requirements.
