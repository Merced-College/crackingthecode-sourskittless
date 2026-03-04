#include <iostream>
#include <ctime> // Include the ctime library to use clock() for timing
#include <cstdlib> // For rand() and srand()
#include <string> // Added to handle letters and numbers together
#include <cmath> // Added to use the pow function for calculating combinations

int main() {
    srand(time(0));

    // 1. Define our new "Base 14" alphabet
    std::string charset = "0123456789abcdefghijklmnopqrstuvwxyz"; // make string of total possible characters
    double base = charset.length(); // This will be 36

    // 2. Generate a RANDOM 4-character password using the charset
    std::string target = ""; // Initialize an empty string for the target password
    for(int i = 0; i < 4; i++) { //We want a 4-character password
        target += charset[rand() % (int)base]; // Append a random character from the charset to the target password
    }
     std::cout << "Final Challenge" << std::endl;

    clock_t startTime = clock(); // Record the START time

    // 3. The Brute Force Logic
    // We use 4 nested loops (one for each character position)
    std::string guess = "    "; // Initialize a string to hold our current guess (4 spaces)
    long attempts = 0; // Use long to handle the large number of attempts (14^4 = 38416)
    bool found = false; // Flag to indicate when we've found the password

    for (int i = 0; i < base && !found; i++) { // Loop through the first character options
        for (int j = 0; j < base && !found; j++) { // Loop through the second character options
            for (int k = 0; k < base && !found; k++) { // Loop through the third character options
                for (int l = 0; l < base && !found; l++) { // Loop through the fourth character options
                    attempts++;

                    // Construct the current guess
                    guess[0] = charset[i];
                    guess[1] = charset[j];
                    guess[2] = charset[k];
                    guess[3] = charset[l];

                    // Check if it matches the target
                    if (guess == target) {
                        found = true;
                    }
                }
            }
        }
    }

    clock_t endTime = clock();
    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;

    // Calculate guesses per second on computer
    double guessesPerSecond = attempts / timeTaken;

    // Calculate combinations for a 10-character password (36^10)
    // this is where it starts to take a few days to crack
    //anything higher can lead to hours, days, or even years to crack
    //this is optimal for a password since it has a good amount of
    //combinations but can still be cracked in a reasonable amount of time
    double tenCharCombos = pow(base, 10);

    // Estimate time in years
    double secondsToCrack = tenCharCombos / guessesPerSecond; // total combinations divided by guesses per second gives us total seconds to crack
    double yearsToCrack = secondsToCrack / (60 * 60 * 24 * 365); // total seconds divided by seconds in a year
    //double hoursToCrack = yearsToCrack * 365 * 24; // shows in hours
    if (found) {
        std::cout << "PASSCODE CRACKED!" << std::endl;
        std::cout << "Found: " << guess << std::endl;
        std::cout << "Total Attempts Required: " << attempts << std::endl;
        std::cout << "Time Taken: " << timeTaken << " seconds" << std::endl;
        std::cout << "Your computerspeed: " << guessesPerSecond << " guesses/sec" << std::endl; // This is how many guesses your computer can make per second
        std::cout << "Combos for 7 characters: " << tenCharCombos << std::endl; // This is how many combinations there are for a 7 character password using our charset
        std::cout << "Estimated time to CRACK 7 chars: " << yearsToCrack << " years" << std::endl; // This is how long it would take to crack a 7 character password using our charset on your computer
        //std::cout << "Time in Hours: " << hoursToCrack << " hours" << std::endl;
    }

    return 0;
}
