#include <iostream>
#include <ctime> // Include the ctime library to use clock() for timing
#include <cstdlib> // For rand() and srand()

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    int target = rand() % 100000000; // Generate a random 8-digit passcode (0 to 99999999)
    int currentGuess = -1; // Initialize to an invalid guess
    int attempts = 0; // Counter for the number of attempts made

    std::cout << "Challenge 2" << std::endl;

    // 1. Record the START time
    clock_t startTime = clock();

    // 2. The Brute Force Loop
    // We iterate through every possible 8-digit combination (0 to 99999999)
    for (int i = 0; i <= 99999999; i++) {
        attempts++; // Increment our counter for every guess made
        
        if (i == target) { // Check if the current guess matches the target
            currentGuess = i; // If it matches, we store the guess
            break; // Stop once we find the match
        }
    }
    // 3. Record the END time
    clock_t endTime = clock();

    // 4. Calculate the difference in seconds
    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;

    if (currentGuess != -1) {
        std::cout << "PASSCODE CRACKED!" << std::endl;
        std::cout << "Found: " << currentGuess << std::endl;
        std::cout << "Total Attempts Required: " << attempts << std::endl;
        std::cout << "Time Taken: " << timeTaken << " seconds" << std::endl;
    }
    return 0;
}