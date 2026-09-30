#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()

// Function to display the welcome message and game rules
void displayWelcomeMessage() {
    std::cout << "=========================================\n";
    std::cout << "   Welcome to the Number Guessing Game!  \n";
    std::cout << "=========================================\n";
    std::cout << "Instructions:\n";
    std::cout << "1. I am thinking of a number between 1 and 100.\n";
    std::cout << "2. Try to guess the number in as few attempts as possible.\n";
    std::cout << "3. After each guess, I will tell you if your guess is too high or too low.\n";
    std::cout << "-----------------------------------------\n\n";
}

// Function to play a single round of the number guessing game
void playGame() {
    // Generate a random number between 1 and 100
    // rand() % 100 generates a number from 0 to 99, so adding 1 gives 1 to 100
    int targetNumber = (std::rand() % 100) + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "A new number has been chosen! Good luck!\n\n";

    // Loop until the player guesses the correct number
    while (guess != targetNumber) {
        std::cout << "Enter your guess (1-100): ";

        // Read player input
        if (!(std::cin >> guess)) {
            if (std::cin.eof()) {
                // Input stream closed (EOF)
                std::cout << "\nGame terminated due to end of input stream.\n";
                return;
            }
            // Handle non-numeric or invalid input
            std::cout << "Invalid input! Please enter a valid integer.\n";
            std::cin.clear(); // Clear error state flags
            // Ignore invalid characters remaining in the input buffer
            std::cin.ignore(10000, '\n');
            continue; // Skip the rest of this loop iteration
        }

        // Increment the attempt counter for valid input
        attempts++;

        // Provide feedback based on the player's guess
        if (guess > targetNumber) {
            std::cout << "Too high! Try again.\n\n";
        } else if (guess < targetNumber) {
            std::cout << "Too low! Try again.\n\n";
        } else {
            std::cout << "\nCongratulations! You guessed the correct number ("
                      << targetNumber << ")!\n";
            std::cout << "Total attempts taken: " << attempts << "\n\n";
        }
    }
}

// Function to ask if the player wants to play another round
bool askPlayAgain() {
    char choice = 'n';
    std::cout << "Would you like to play again? (y/n): ";
    if (!(std::cin >> choice)) {
        return false;
    }

    // Return true if player types 'y' or 'Y', otherwise false
    return (choice == 'y' || choice == 'Y');
}

int main() {
    // Seed the random number generator using the current time
    // This ensures a different sequence of random numbers each time the program runs
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Display the welcome message once at startup
    displayWelcomeMessage();

    // Main game loop: plays rounds as long as the player wants to continue
    bool keepPlaying = true;
    while (keepPlaying && std::cin.good()) {
        playGame();
        if (std::cin.good()) {
            keepPlaying = askPlayAgain();
            std::cout << "\n";
        } else {
            keepPlaying = false;
        }
    }

    std::cout << "Thank you for playing! Goodbye!\n";
    return 0;
}
