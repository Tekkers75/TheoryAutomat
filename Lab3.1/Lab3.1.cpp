#include <iostream>
#include <fstream>
#include <string>

enum class State {
    Normal_mode,
    Comment_mode,
    Multiline_comment_mode
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
    char prevChar = '\0';
    char currChar;
    int multilineCommentDepth = 0;

    while (inputFile.get(currChar)) {
        switch (state) {
        case State::Normal_mode:
            if (prevChar == '#' && currChar != '=') {
                state = State::Comment_mode;
            }
            else if (prevChar == '#' && currChar == '=') {
                state = State::Multiline_comment_mode;
                multilineCommentDepth = 1;
            }
            else {
                outputFile << prevChar;
            }
            break;
        case State::Comment_mode:
            if (currChar == '\n') {
                state = State::Normal_mode;
                outputFile << currChar;
            }
            break;
        case State::Multiline_comment_mode:
            if (prevChar == '=' && currChar == '#') {
                multilineCommentDepth--;
                if (multilineCommentDepth == 0) {
                    state = State::Normal_mode;
                }
            }
            else if (prevChar == '#' && currChar == '=') {
                multilineCommentDepth++;
            }
            break;
        }

        prevChar = currChar;
    }

    // Handle the last character
    if (state == State::Normal_mode || state == State::Comment_mode) {
        outputFile << prevChar;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFileName = "input1.txt";
    std::string outputFileName = "output.txt";
    processFile(inputFileName, outputFileName);

    std::cout << "Comments removed successfully." << std::endl;

    return 0;
}