#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono> // Include chrono for time measurement

class Module {
public:
    std::string name;
    int width, height;
    std::vector<std::pair<int, int>> positions;

    Module() : name(""), width(0), height(0) {}

    Module(std::string n, int w, int h) : name(n), width(w), height(h) {
        positions.push_back({0, 0});
    }

    Module combineVertical(const Module& other) {
        Module combined(name + "|" + other.name, width + other.width, std::max(height, other.height));
        int this_max_y = std::max_element(positions.begin(), positions.end(), 
                                          [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second < b.second; })->second;
        for (const auto& pos : positions) {
            combined.positions.push_back(pos); // Add current module's positions unchanged
        }
        for (const auto& pos : other.positions) {
            combined.positions.push_back({pos.first + width, this_max_y + pos.second});
        }
        return combined;
    }

    Module combineHorizontal(const Module& other) {
        Module combined(name + "-" + other.name, std::max(width, other.width), height + other.height);
        int this_max_x = std::max_element(positions.begin(), positions.end(),
                                          [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.first < b.first; })->first;
        for (const auto& pos : positions) {
            combined.positions.push_back(pos); // Add current module's positions unchanged
        }
        for (const auto& pos : other.positions) {
            combined.positions.push_back({this_max_x + pos.first, pos.second + height});
        }
        return combined;
    }

    void printDetails() const {
        std::cout << " | Width: " << width << " | Height: " << height << " | Positions: ";
        for (const auto& pos : positions) {
            std::cout << "(" << pos.first << "," << pos.second << ") ";
        }
        std::cout << std::endl;
    }
};

bool checkBallotingProperty(const std::vector<std::string>& expression) {
    int num_operands = 0, num_operators = 0;
    for (const auto& token : expression) {
        if (token == "H" || token == "V") {
            num_operators++;
        } else {
            num_operands++;
        }
    }
    return num_operands - num_operators == 1;
}

void evaluatePolishExpression(const std::vector<std::string>& expression, std::unordered_map<std::string, Module>& modules) {
    std::stack<Module> stack;
    for (const auto& token : expression) {
        if (token == "H" || token == "V") {
            if (stack.size() < 2) {
                std::cerr << "Invalid expression: not enough elements to perform operation.\n";
                return;
            }
            Module top = stack.top(); stack.pop();
            Module next = stack.top(); stack.pop();
            stack.push(token == "V" ? next.combineVertical(top) : next.combineHorizontal(top));
        } else {
            if (modules.find(token) == modules.end()) {
                std::cerr << "Module not found: " << token << "\n";
                return;
            }
            stack.push(modules[token]);
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Invalid expression: incorrect final number of elements.\n";
        return;
    }
    stack.top().printDetails();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <size file> <expression file>\n";
        return 1;
    }

    std::unordered_map<std::string, Module> modules;
    std::ifstream moduleFile(argv[1]);
    std::string line;
    int id = 1, width, height;

    while (moduleFile >> width >> height) {
        modules[std::to_string(id)] = Module(std::to_string(id), width, height);
        id++;
    }

    std::ifstream expressionFile(argv[2]);
    int expressionCount = 0;
    while (getline(expressionFile, line)) {
        std::stringstream lineStream(line);
        std::string segment;
        while (std::getline(lineStream, segment, '+')) {  // Split by '+'
            segment.erase(std::remove(segment.begin(), segment.end(), '-'), segment.end());  // Remove any '-' signs
            std::istringstream iss(segment);
            std::vector<std::string> expression;
            std::string token;
            while (iss >> token) {
                expression.push_back(token);
            }

            if (!checkBallotingProperty(expression)) {
                std::cerr << "Error: Balloting property violated on expression #" << expressionCount + 1 << ". Number of operands is not larger than number of operators.\n";
                return 1; // Exit on first violation
            }

            std::cout << "Evaluating expression #" << expressionCount + 1 << ":\n";
            auto start = std::chrono::high_resolution_clock::now(); // Start measuring time
            evaluatePolishExpression(expression, modules);
            auto end = std::chrono::high_resolution_clock::now(); // End measuring time
            std::chrono::duration<double> elapsed = end - start; // Calculate elapsed time
            std::cout << "Runtime: " << elapsed.count() << " seconds\n"; // Print runtime
            expressionCount++;
        }
    }

    return 0;
}

