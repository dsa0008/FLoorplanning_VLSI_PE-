Polish Expression Evaluation


Module Class:
Represents a module in the floorplan.
Contains attributes such as name, width, height, and positions.
Provides methods for combining modules vertically and horizontally, as well as printing module details.

checkBallotingProperty Function:
Checks if the expression adheres to the balloting property, which states that the number of operands should be greater than the number of operators by exactly one.

evaluatePolishExpression Function:
Evaluates a Polish expression by utilizing a stack-based approach.
Parses the expression tokens and performs the corresponding operations (combining modules horizontally or vertically).
Outputs the resulting module details.

Main Function:
Reads module details from a file specified as a command-line argument and stores them in an unordered map.
Reads expressions from another file specified as a command-line argument.
For each expression, it:
Checks if the balloting property is satisfied.
Evaluates the expression and prints the resulting module details.
Measures and prints the runtime of expression evaluation.




Compiling the code:   g++ -std=c++11 -o polisheval Main4.cpp

Input Files:
	./polisheval Mod100/Mod100.size Mod100/Mod100.pe

	
	./polisheval Mod5/Mod5.size Mod5/Mod5.pe




Simulated Annealing Algorithm 

main.cpp:
Input Handling: Reads input from a file specified by the user, storing module data in a map.
Initialization: Creates an initial floorplan topology and calculates its cost.
Simulated Annealing: Executes the simulated annealing algorithm to optimize the floorplan.
Output: Prints the optimized floorplan and its cost, as well as the execution time.

fp.h:
Header Guard: Ensures that the header file is included only once during compilation.
Includes: Contains necessary header file inclusions.
Constants: Defines various constants used in the simulated annealing algorithm.
Data Structures: Declares classes Tile and NPE for handling floorplan tiles and the floorplan itself.
Function Declarations: Declares member functions of the NPE class for floorplan operations.

fp.cpp:
Includes: Includes the header file and necessary standard library headers.
NPE Class Member Functions: Defines the member functions declared in fp.h for floorplan operations.
Simulated Annealing Logic: Implements the simulated annealing algorithm, including moves and cost calculations.

Makefile:
Compilation Rules: Defines rules for compiling the main program and associated objects.
Cleaning Rule: Provides a rule for cleaning up object files and executables.
This structure separates concerns effectively, encapsulating floorplan logic within classes and implementing the simulated annealing algorithm separately. This modular approach enhances readability, maintainability, and reusability of the codebase.


To compile (Windows): g++ -o fpexec main.cpp fp.cpp

To run: fpexec

Input files: 
	Mod5.txt

	Mod30.txt

	Mod20.txt
