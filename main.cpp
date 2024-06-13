#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
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
std::vector<std::string> words = {
        "About", "Alert", "Argue", "Beach",
        "Above", "Alike", "Arise", "Began",
        "Abuse", "Alive", "Array", "Begin",
        "Actor", "Allow", "Aside", "Begun",
        "Acute", "Alone", "Asset", "Being",
        "Admit", "Along", "Audio", "Below",
        "Adopt", "Alter", "Audit", "Bench",
        "Adult", "Among", "Avoid", "Billy",
        "After", "Anger", "Award", "Birth",
        "Again", "Angle", "Aware", "Black",
        "Agent", "Angry", "Badly", "Blame",
        "Agree", "Apart", "Baker", "Blind",
        "Ahead", "Apple", "Bases", "Block",
        "Alarm", "Apply", "Basic", "Blood",
        "Album", "Arena", "Basis", "Board",
        "Boost", "Buyer", "China", "Cover",
        "Booth", "Cable", "Chose", "Craft",
        "Bound", "Calif", "Civil", "Crash",
        "Brain", "Carry", "Claim", "Cream",
        "Brand", "Catch", "Class", "Crime",
        "Bread", "Cause", "Clean", "Cross",
        "Break", "Chain", "Clear", "Crowd",
        "Breed", "Chair", "Click", "Crown",
        "Brief", "Chart", "Clock", "Curve",
        "Bring", "Chase", "Close", "Cycle",
        "Broad", "Cheap", "Coach", "Daily",
        "Broke", "Check", "Coast", "Dance",
        "Brown", "Chest", "Could", "Dated",
        "Build", "Chief", "Count", "Dealt",
        "Built", "Child", "Court", "Death",
        "Debut", "Entry", "Forth", "Group",
        "Delay", "Equal", "Forty", "Grown",
        "Depth", "Error", "Forum", "Guard",
        "Doing", "Event", "Found", "Guess",
        "Doubt", "Every", "Frame", "Guest",
        "Dozen", "Exact", "Frank", "Guide",
        "Draft", "Exist", "Fraud", "Happy",
        "Drama", "Extra", "Fresh", "Harry",
        "Drawn", "Faith", "Front", "Heart",
        "Dream", "False", "Fruit", "Heavy",
        "Dress", "Fault", "Fully", "Hence",
        "Drill", "Fibre", "Funny", "Night",
        "Drink", "Field", "Giant", "Horse",
        "Drive", "Fifth", "Given", "Hotel",
        "Drove", "Fifty", "Glass", "House",
        "Dying", "Fight", "Globe", "Human",
        "Eager", "Final", "Going", "Ideal",
        "Early", "First", "Grace", "Image",
        "Earth", "Fixed", "Grade", "Index",
        "Eight", "Flash", "Grand", "Inner",
        "Elite", "Fleet", "Grant", "Input",
        "Empty", "Floor", "Grass", "Issue",
        "Enemy", "Fluid", "Great", "Irony",
        "Enjoy", "Focus", "Green", "Juice",
        "Enter", "Force", "Gross", "Joint",
        "Judge", "Metal", "Media", "Newly",
        "Known", "Local", "Might", "Noise",
        "Label", "Logic", "Minor", "North",
        "Large", "Loose", "Minus", "Noted",
        "Laser", "Lower", "Mixed", "Novel",
        "Later", "Lucky", "Model", "Nurse",
        "Laugh", "Lunch", "Money", "Occur",
        "Layer", "Lying", "Month", "Ocean",
        "Learn", "Magic", "Moral", "Offer",
        "Lease", "Major", "Motor", "Often",
        "Least", "Maker", "Mount", "Order",
        "Leave", "March", "Mouse", "Other",
        "Legal", "Music", "Mouth", "Ought",
        "Level", "Match", "Movie", "Paint",
        "Light", "Mayor", "Needs", "Paper",
        "Limit", "Meant", "Never", "Party",
        "Peace", "Power", "Radio", "Round",
        "Panel", "Press", "Raise", "Route",
        "Phase", "Price", "Range", "Royal",
        "Phone", "Pride", "Rapid", "Rural",
        "Photo", "Prime", "Ratio", "Scale",
        "Piece", "Print", "Reach", "Scene",
        "Pilot", "Prior", "Ready", "Scope",
        "Pitch", "Prize", "Refer", "Score",
        "Place", "Proof", "Right", "Sense",
        "Plain", "Proud", "Rival", "Serve",
        "Plane", "Prove", "River", "Seven",
        "Plant", "Queen", "Quick", "Shall",
        "Plate", "Sixth", "Stand", "Shape",
        "Point", "Quiet", "Roman", "Share",
        "Pound", "Quite", "Rough", "Sharp",
        "Sheet", "Spare", "Style", "Times",
        "Shelf", "Speak", "Sugar", "Tired",
        "Shell", "Speed", "Suite", "Title",
        "Shift", "Spend", "Super", "Today",
        "Shirt", "Spent", "Sweet", "Topic",
        "Shock", "Split", "Table", "Total",
        "Shoot", "Spoke", "Taken", "Touch",
        "Short", "Sport", "Taste", "Tough",
        "Shown", "Staff", "Taxes", "Tower",
        "Sight", "Stage", "Teach", "Track",
        "Since", "Stake", "Teeth", "Trade",
        "Sixty", "Start", "Texas", "Treat",
        "Sized", "State", "Thank", "Trend",
        "Skill", "Steam", "Theft", "Trial",
        "Sleep", "Steel", "Their", "Tried",
        "Slide", "Stick", "Theme", "Tries",
        "Small", "Still", "There", "Truck",
        "Smart", "Stock", "These", "Truly",
        "Smile", "Stone", "Thick", "Trust",
        "Smith", "Stood", "Thing", "Truth",
        "Smoke", "Store", "Think", "Twice",
        "Solid", "Storm", "Third", "Under",
        "Solve", "Story", "Those", "Undue",
        "Sorry", "Strip", "Three", "Union",
        "Sound", "Stuck", "Threw", "Unity",
        "South", "Study", "Throw", "Until",
        "Space", "Stuff", "Tight", "Upper",
        "Upset", "Whole", "Waste", "Wound",
        "Urban", "Whose", "Watch", "Write",
        "Usage", "Woman", "Water", "Wrong",
        "Usual", "Train", "Wheel", "Yield",
        "Valid", "World", "Where", "Young",
        "Value", "Worry", "Which", "Youth",
        "Video", "Worse", "While", "Worth",
        "Virus", "Worst", "White", "Would",
        "Visit", "Vital", "Voice"
    };

    int min = 0, max = words.size();
    int randomIndex = rand() % (max - min + 1) + min;
    return words[randomIndex];
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
