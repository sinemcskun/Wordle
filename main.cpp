#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <windows.h>

const int WORD_LENGTH = 5;
const int NOT_MATCHED = 0;
const int PARTIAL_MATCHED = 1;
const int MATCHED = 2;
const int NUMBER_OF_GUESSES = 6;

void toUpperCase(std::string &input){
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c)
        {return std::toupper(c);});
}

std::string getRandomWord(){
    //get a random word from an API
    return "ready";
}

bool isValidWord(const std::string& word){
    return word.length() == WORD_LENGTH && std::all_of(word.begin(), word.end(), ::isalpha);
}

void markMatched(std::vector<std::vector<int>> &matches, int tryIndex, const std::string& target, const std::string& guess){
    std::vector<bool> matched(target.length(), false);
    for(int i = 0 ; i < guess.length(); i++)
        matches[tryIndex][i] = NOT_MATCHED;

    for(int i = 0; i < guess.length(); i++){
        if(guess[i] == target[i]){
            matches[tryIndex][i] = MATCHED;
            matched[i] = true;
        }
    }

    for(int i = 0; i < guess.length(); i++){
        if(matches[tryIndex][i] != MATCHED){
            for(int j = 0; j < target.length(); j++){
                if(guess[i] == target[j] && !matched[j]){
                    matches[tryIndex][i] = PARTIAL_MATCHED;
                    matched[j] = true;
                    break;
                }
            }
        }
    }
}

bool isAllMatched(const std::string& target, const std::string& guess){
    return target == guess;
}

void printWordle(const std::vector<std::string>& guesses, const std::vector<std::vector<int>>& matches, int currentTry){
    system("cls");
    std::cout << "=================================================================" << std::endl;
    std::cout << "|                                                               |" << std::endl;
    std::cout << "|   $$\\       $$\\                           $$\\ $$\\   |" << std::endl;
    std::cout << "|   $$ | $\\   $$ |                          $$ |$$ |             |" << std::endl;
    std::cout << "|   $$ |$$$\\  $$ | $$$$$$\\   $$$$$$\\   $$$$$$$ |$$ | $$$$$$\\     |" << std::endl;
    std::cout << "|   $$ $$  $$\\$$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$ |$$  __$$\\    |" << std::endl;
    std::cout << "|   $$$$   _$$$$ |$$ /  $$ |$$ |  \\__|$$ /  $$ |$$ |$$$$$$$$ |   |" << std::endl;
    std::cout << "|   $$$   / \\$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |$$   ____|   |" << std::endl;
    std::cout << "|   $$   /   \\$$ |\\$$$$$$  |$$ |      \\$$$$$$$ |$$ |\\$$$$$$$\\    |" << std::endl;
    std::cout << "|   \\__/     \\__| \\______/ \\__|       \\_______|\\__| \\_______|   |" << std::endl;
    std::cout << "|                                                               |" << std::endl;
    std::cout << "=================================================================" << std::endl;

    for(int i = 0; i <= currentTry && i < guesses.size(); i++){
        std::string separator = "-";
        std::string padding = "|";
        std::string text = "|";

        for(int j = 0; j < guesses[i].length(); j++){
            separator += "------";
            padding += "      |";
            char value = std::toupper(guesses[i][j]);
            text += "  ";
            
            if(matches[i][j] == PARTIAL_MATCHED){
                text += "\033[33m"; 
            }else if(matches[i][j] == MATCHED){
                text += "\033[32m";
            }

            text += value;

            if(matches[i][j] == PARTIAL_MATCHED || matches[i][j] == MATCHED){
                text += "\033[0m";
            }

            text += "   |"; 
        }

        if(i == 0)
            std::cout << separator << std::endl;
        
        std::cout << padding << std::endl;
        std::cout << text << std::endl;
        std::cout << padding << std::endl;
        std::cout << separator << std::endl;
    }
}

int main(){
    std::vector<std::string> guesses(NUMBER_OF_GUESSES);
    std::vector<std::vector<int>> matches(NUMBER_OF_GUESSES, std::vector<int>(WORD_LENGTH));
    std::string targetWord = getRandomWord();
    toUpperCase(targetWord);

    std::string input;
    int currentGuessCount = 0;

    printWordle(guesses, matches, -1);

    while(currentGuessCount < NUMBER_OF_GUESSES){
        do{
            std::cout << "Please enter your guess (word length must be " + std::to_string(WORD_LENGTH) + ") or type Q to quit: " << std::endl;
            std::getline(std::cin, input);
            toUpperCase(input);

        }while(input != "Q" && !isValidWord(input));

        if(input == "Q"){
            std::cout << "Quit game" << std::endl;
            break;
        }

        guesses[currentGuessCount] = input;
        markMatched(matches, currentGuessCount, targetWord, input);
        printWordle(guesses, matches, currentGuessCount);

        if(isAllMatched(targetWord, input)){
            std::cout << "Found the word" << std::endl;
            break;
        }

        currentGuessCount++;

        if(currentGuessCount == NUMBER_OF_GUESSES){
            std::cout << "You did not find the word" << std::endl;
            std::cout << "The correct word was: " << targetWord << std::endl;
        }
    }
    return 0;
}
