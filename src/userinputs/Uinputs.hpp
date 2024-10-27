#pragma once

#include <iostream>

/** 
 * @class UserInputs
 * @brief handle user interactions with the cli
 */
class UserInputs{
    public:
    /**
     * @brief Ask the user for an input
     * @param string : the question to ask the user
     * @return int : the input of the user
     */
    int AskIntInput(std::string question);

    /**
     * @brief Ask the user for an input
     * @param string : the question to ask the user
     * @return float : the input of the user
     */
    float AskFloatInput(std::string question);

    /**
     * @brief Ask the user for an input
     * @param string : the question to ask the user
     * @return string : the input of the user
     */
    std::string AskStringInput(std::string question);

    /**
     * @brief Ask the user for an input
     * @param string : the question to ask the user
     * @return char : the input of the user
     */
    char AskCharInput(std::string question);

};