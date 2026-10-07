#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    const int secretNumber = distribution(generator);

    int guess = 0;
    int attempts = 0;

    std::cout << "=== Number Guessing Game ===\n";
    std::cout << "I have chosen a number between 1 and 100.\n";
    std::cout << "Try to guess it!\n\n";

    while (guess != secretNumber) {
        std::cout << "Enter your guess: ";

        if (!(std::cin >> guess)) {
            std::cout << "Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        ++attempts;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        }
        else if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        }
        else {
            std::cout << "\nCorrect! You found the number in "
                      << attempts << " attempts.\n";
        }
    }

    return 0;
}
