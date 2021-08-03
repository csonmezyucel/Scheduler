// Code by Cevat Sonmez Yucel
#include "AVLNode.h"
#include "AVLTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <set>

// Takes in 2 arguments, the time as a string, and its am or pm status
// Returns an integer that represent the time in 24 hour format
int convertTimeToInt(std::string time, std::string ampm) {
    int intTime;
    // Checking for edge case 12pm
    if (ampm == "pm" and time == "12") {
        intTime = 12;
    }
    // Checking for edge case 12am
    else if (ampm == "am" and time == "12") {
        intTime = 24;
    }
    else {
        if (ampm == "am") {
            intTime = std::stoi(time);
        }
        else {
            intTime = std::stoi(time) + 12;
        }
    }  
    return intTime;
}

int main() {
    AVLTree myTree;
    bool complete = false;
    std::cout << "--------------------------------\n";
    std::cout << "Welcome to Scheduler\n";
    std::cout << "--------------------------------\n";
    std::cout << "You can add things to do to your schedule. Each activity must begin at the hour (ex. 4:00 PM)\n";
    std::cout << "--------------------------------\n";
    std::string userInput; // declaring variable that will possibly be used multiple times
    std::cout << "Would you like to add anything to your schedule (y / n)? ";
    std::cin >> userInput;
    std::cout << "--------------------------------\n";
    std::set<std::string> validInput{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    std::string ampm; // declaring variable that will possibly be used multiple times
    std::string time; // declaring variable that will possibly be used multiple times
    int intTime; // declaring variable that will possibly be used multiple times
    std::string activity; // declaring variable that will possibly be used multiple times
    
    // Checking for valid input
    while (userInput != "y" and userInput != "n") {
        std::cout << "Invalid input, please type either 'y' or 'n': ";
        std::cin >> userInput;
        std::cout << "--------------------------------\n";
    }
    if (userInput == "n") {
        complete = true;
    }
    else if (userInput == "y") {
        std::cout << "Morning or Afternoon (am / pm)? ";
        std::cin >> ampm;
        std::cout << "--------------------------------\n";

        // Checking for valid input
        while (ampm != "am" and ampm != "pm") {
            std::cout << "Invalid input, please type either 'am' or 'pm': ";
            std::cin >> ampm;
            std::cout << "--------------------------------\n";
        }
        std::cout << "At what time (1- 12)? ";
        std::cin >> time;
        std::cout << "--------------------------------\n";

        // Checking for valid input
        while (validInput.find(time) == validInput.end()) {
            std::cout << "Invalid input, please type a number from 1 to 12: ";
            std::cin >> time;
            std::cout << "--------------------------------\n";
        }
        intTime = convertTimeToInt(time, ampm);
        std::cout << "Please type activity: ";
        std::cin.ignore();
        std::getline(std::cin, activity);
        std::cout << "--------------------------------\n";
        myTree.insert(intTime, activity);
    }

    while (!complete) {
        std::cout << "Would you like to add anything else (y / n)? ";
        std::cin >> userInput;
        std::cout << "--------------------------------\n";
        while (userInput != "y" and userInput != "n") {
            std::cout << "Invalid input, please type either 'y' or 'n': ";
            std::cin >> userInput;
            std::cout << "--------------------------------\n";
        }
        if (userInput == "n") {
            break;
        }
        std::cout << "Morning or Afternoon (am / pm)? ";
        std::cin >> ampm;
        std::cout << "--------------------------------\n";

        // Checking for valid input
        while (ampm != "am" and ampm != "pm") {
            std::cout << "Invalid input, please type either 'am' or 'pm': ";
            std::cin >> ampm;
            std::cout << "--------------------------------\n";
        }
        std::cout << "At what time (1- 12)? ";
        std::cin >> time;
        std::cout << "--------------------------------\n";

        // Checking for valid input
        while (validInput.find(time) == validInput.end()) {
            std::cout << "Invalid input, please type a number from 1 to 12: ";
            std::cin >> time;
            std::cout << "--------------------------------\n";
        }
        intTime = convertTimeToInt(time, ampm);
        if (myTree.find(intTime) != "") {
            std::cout << "The following activity is already scheduled for the time you selected: \n";
            std::cout << myTree.find(intTime) << "\n";
            std::cout << "--------------------------------\n";
            std::string userDecision;
            std::cout << "Would you like to overwrite it (y / n)? ";
            std::cin >> userDecision;
            std::cout << "--------------------------------\n";

            // Checking for valid input
            while (userDecision != "y" and userDecision != "n") {
                std::cout << "Invalid input, please either type 'y' or 'n': ";
                std::cin >> userDecision;
                std::cout << "--------------------------------\n";
            }
            if (userDecision == "n") {
                continue;
            }         
        }
        myTree.remove(intTime);
        std::cout << "Please type activity: ";
        std::cin.ignore();
        std::getline(std::cin, activity);
        std::cout << "--------------------------------\n";
        myTree.insert(intTime, activity);
    }
    std::vector<std::string> schedule = myTree.returnSchedule(); // Schedule in vector form

    // Creating a text file in the same directory and writing the schedule to that file
    std::ofstream myFile;
    myFile.open("Schedule.txt");
    myFile << "--------------------------------\n";
    myFile << "My Schedule\n";
    myFile << "--------------------------------\n";
    for (int i = 1; i <= 24; i++) {
        if (i < 12) {
            myFile << i << ":00 AM - " << schedule[i] << "\n";
        }
        else if (i == 12) {
            myFile << i << ":00 PM - " << schedule[i] << "\n";
        }
        else if (i < 24) {
            myFile << i - 12 << ":00 PM - " << schedule[i] << "\n";
        }
        else if (i == 24) {
            myFile << i - 12 << ":00 AM - " << schedule[i] << "\n";
        }
        myFile << "--------------------------------\n";
    }
    myFile.close();
    return 0;
}