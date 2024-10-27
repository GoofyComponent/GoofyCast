#include <iostream>
#include "Uinputs.hpp"

int UserInputs::AskIntInput(std::string question) {
    int input;
    std::cout << question;
    std::cin >> input;
    return input;
}

float UserInputs::AskFloatInput(std::string question) {
    float input;
    std::cout << question;
    std::cin >> input;
    return input;
}

std::string UserInputs::AskStringInput(std::string question) {
    std::string input;
    std::cout << question;
    std::cin >> input;
    return input;
}

char UserInputs::AskCharInput(std::string question) {
    char input;
    std::cout << question;
    std::cin >> input;
    return input;
}

