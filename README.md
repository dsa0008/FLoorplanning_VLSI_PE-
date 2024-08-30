# Polish Expression Evaluation and Simulated Annealing for Floorplanning

This repository contains code for evaluating floorplans using Polish expressions and optimizing them using a Simulated Annealing algorithm. The code is organized into different modules and functions to handle various tasks such as module management, expression evaluation, and optimization.

## Table of Contents

- [Introduction](#introduction)
- [Polish Expression Evaluation](#polish-expression-evaluation)
  - [Module Class](#module-class)
  - [Balloting Property Check](#balloting-property-check)
  - [Polish Expression Evaluation Function](#polish-expression-evaluation-function)
  - [Main Function](#main-function)
- [Simulated Annealing Algorithm](#simulated-annealing-algorithm)
  - [Main Program (`main.cpp`)](#main-program-maincpp)
  - [Floorplanning Header (`fp.h`)](#floorplanning-header-fph)
  - [Floorplanning Implementation (`fp.cpp`)](#floorplanning-implementation-fpcpp)
  - [Makefile](#makefile)
- [Compilation and Execution](#compilation-and-execution)
- [Input Files](#input-files)
- [License](#license)

## Introduction

This project is focused on evaluating and optimizing floorplans using Polish expressions. It includes a modular C++ implementation for evaluating these expressions and optimizing floorplans using a Simulated Annealing approach. The code is structured to ensure maintainability and scalability.

## Polish Expression Evaluation

### Module Class

- **Purpose:** Represents a module in the floorplan.
- **Attributes:** Includes properties such as the module's name, width, height, and positional information.
- **Methods:** Provides functionality for combining modules either vertically or horizontally and for printing detailed module information.

### Balloting Property Check

- **Function:** `checkBallotingProperty`
- **Purpose:** Ensures the Polish expression adheres to the balloting property, which mandates that the number of operands must always exceed the number of operators by exactly one throughout the expression.

### Polish Expression Evaluation Function

- **Function:** `evaluatePolishExpression`
- **Purpose:** Evaluates a given Polish expression using a stack-based approach. The function parses the expression tokens and performs operations to combine modules either horizontally or vertically, outputting the final module configuration.

### Main Function

- **Purpose:** Orchestrates the overall flow of Polish expression evaluation.
- **Workflow:**
  1. **Input Handling:** Reads module details from a specified file and stores them in an unordered map.
  2. **Expression Processing:** Reads and evaluates expressions from another file.
  3. **Validation:** Verifies each expression against the balloting property.
  4. **Evaluation:** Evaluates the expression and prints the resulting module details.
  5. **Performance Measurement:** Records and prints the runtime of each expression evaluation.

## Simulated Annealing Algorithm

### Main Program (`main.cpp`)

- **Purpose:** Implements the Simulated Annealing algorithm for floorplan optimization.
- **Workflow:**
  1. **Input Handling:** Reads module data from a specified file and stores it in a map.
  2. **Initialization:** Generates an initial floorplan topology and calculates its cost.
  3. **Simulated Annealing:** Executes the optimization process to minimize floorplan cost.
  4. **Output:** Prints the optimized floorplan, its cost, and the execution time.

### Floorplanning Header (`fp.h`)

- **Purpose:** Defines the structure and functions for handling floorplan operations.
- **Key Components:**
  - **Header Guard:** Ensures the file is included only once during compilation.
  - **Constants:** Defines constants used in the Simulated Annealing process.
  - **Data Structures:** Declares classes such as `Tile` and `NPE` for managing floorplan tiles and expressions.
  - **Function Declarations:** Lists member functions for the `NPE` class to perform various floorplan operations.

### Floorplanning Implementation (`fp.cpp`)

- **Purpose:** Implements the methods and functions declared in `fp.h`.
- **Key Components:**
  - **Includes:** Necessary header files and standard libraries.
  - **NPE Class Functions:** Implements the member functions for floorplan operations.
  - **Simulated Annealing Logic:** Contains the core logic for the algorithm, including various moves and cost calculations.

### Makefile

- **Purpose:** Provides rules for compiling the program and managing object files.
- **Key Features:**
  - **Compilation Rules:** Defines how to compile the main program and associated objects.
  - **Cleaning Rule:** A rule for cleaning up object files and executables to maintain a clean build environment.

## Compilation and Execution

### Compilation (Windows)
```sh
g++ -std=c++11 -o polisheval Main4.cpp
g++ -o fpexec main.cpp fp.cpp


Input Files
Polish Expression Evaluation:
Mod100.size
Mod100.pe
Simulated Annealing:
Mod5.txt
Mod30.txt
Mod20.txt


Execution
./polisheval Mod100/Mod100.size Mod100/Mod100.pe
./fpexec Mod5.txt

