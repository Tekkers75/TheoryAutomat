#include <iostream>
#include <fstream>
#include <string>

enum class State {
    Normal_mode,
    Oneliner,
    Multiliner,
    String_literal
};

void processFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }

    if (!outputFile) {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    State state = State::Normal_mode;
    bool ignoreNextChar = false;

    char c;
    while (inputFile.get(c)) {
        switch (state) {
        case State::Normal_mode:
            if (c == '%') {
                if (inputFile.peek() == '{') {
                    state = State::Multiliner;
                    inputFile.ignore();
                }
                else {
                    state = State::Oneliner;
                }
            }
            else if (c == '.') {
                if (inputFile.peek() == '.' && inputFile.get() && inputFile.peek() == '.' && inputFile.get()) {
                    state = State::Oneliner;
                    inputFile.ignore();
                    inputFile.ignore();
                }
                else {
                    outputFile << c;
                }
            }
            else if (c == '\'') {
                //inputFile.ignore();
                state = State::String_literal;
                /*outputFile << c;*/
            }
            else {
                outputFile << c;
            }
            break;

        case State::Oneliner:
            if (c == '\n') {
                state = State::Normal_mode;
                outputFile << c;
            }
            break;

        case State::Multiliner:
            if (c == '%' && inputFile.peek() == '}') {
                state = State::Normal_mode;
                inputFile.ignore();
            }
            break;

        case State::String_literal:
            if (ignoreNextChar) {
                ignoreNextChar = false;
            }
            else {
                if (c == '\'') {
                    state = State::Normal_mode;
                }
                else {
                    ignoreNextChar = (c == '\\');
                }
            }
            break;
        }
    }

    inputFile.close();
    outputFile.close();

    // Удаление последней одинарной кавычки
    if (state == State::String_literal) {
        outputFile << '\'';
    }
}

int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";
    processFile(inputFileName, outputFileName);

    std::cout << "Comments and string literals removed successfully." << std::endl;

    return 0;
}