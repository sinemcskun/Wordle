# Wordle-Like Game

This is a simple command-line implementation of a Wordle-like game in C++. The objective is to guess a 5-letter word within 6 attempts. The game provides feedback on each guess, indicating which letters are correct and in the correct position, which are correct but in the wrong position, and which are incorrect.

## Features

- Randomly selects a target word for the player to guess. (In development stage)
- Validates the player's guesses to ensure they are 5-letter words.
- Provides feedback on each guess:
  - Green for correct letters in the correct position.
  - Yellow for correct letters in the wrong position.
  - No color for incorrect letters.
- Allows the player to quit the game at any time by entering `Q`.

## Requirements

- C++ compiler supporting C++11 or later.
- (Optional) Windows for colored output in the console.

## Compilation and Execution

1. **Clone the repository:**
    ```sh
    git clone <repository_url>
    cd <repository_directory>
    ```

2. **Compile the program:**
    ```sh
    g++ -o wordle_game main.cpp
    ```

3. **Run the program:**
    ```sh
    ./wordle_game
    ```

## How to Play

1. The game starts by randomly selecting a target 5-letter word.
2. You have 6 attempts to guess the word.
3. Enter your guess when prompted.
4. The game provides feedback on your guess:
   - Green letters are correct and in the correct position.
   - Yellow letters are correct but in the wrong position.
   - Letters with no color are incorrect.
5. If you guess the word correctly, the game congratulates you and ends.
6. If you use up all 6 guesses without finding the word, the game reveals the correct word and ends.
7. To quit the game at any time, type `Q` and press Enter.

## Code Overview

- **main.cpp**: The main file containing the game logic.

### Functions

- `toUpperCase(std::string &input)`: Converts a string to uppercase.
- `getRandomWord()`: Returns a random 5-letter word (placeholder implementation).
- `isValidWord(const std::string &word)`: Checks if a word is valid (length and characters).
- `markMatched(std::vector<std::vector<int>> &matches, int tryIndex, const std::string &target, const std::string &guess)`: Marks the guessed word against the target word for correct and partially correct matches.
- `isAllMatched(const std::string &target, const std::string &guess)`: Checks if the guessed word matches the target word.
- `printWordle(const std::vector<std::string> &guesses, const std::vector<std::vector<int>> &matches, int currentTry)`: Prints the game board with the guesses and their feedback.

## Known Issues

- The color formatting uses ANSI escape codes, which might not work in the Windows Command Prompt by default.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
