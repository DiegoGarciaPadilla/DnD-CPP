/**
 * @file Functions.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that are used in the game.
 * @version 0.1
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FUNCTIONS_H // If the preprocessor FUNCTIONS_H is not defined
#define FUNCTIONS_H // Define the preprocessor FUNCTIONS_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings
#include <cstdlib>  // Library for system functions

#include "Initializer.h" // Include the Initializer file
#include "Race.h"          // Include the race class
#include "Class.h"         // Include the class class
#include "Stats.h"  // Include the statistics class
#include "Character.h"     // Include the character class

// Functions

// General functions

/**
 * @brief Function to clear the screen on Windows
 *
 * @param
 * @return
 */

void cleanScreen()
{
    system("cls");
}

/**
 * @brief Function to pause the program on Windows
 *
 * @param
 * @return
 */

void pause()
{
    system("pause");
}

/**
 * @brief Function to print an array
 *
 * @param array
 * @return
 */

void printArray(std::string *array)
{
    // Get the size of the array
    int size = sizeof(array) / sizeof(array[0]);

    // Print the array
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << array[i] << std::endl;
    }
}

/**
 * @brief Function to create a character with the data entered by the user
 *
 * @param character
 * @return
 */

void createCharacter(Character &character)
{
    // Variables
    std::string name;
    std::string gender;
    int age;
    std::string alignment;
    Race race;
    int option;

    // Arrays
    std::string *genders = listGenders();
    std::string *alignments = listAlignments();
    std::string *races = listRaces();
    std::string *classes = listClasses(); 
    
    // Clear the screen
    cleanScreen();

    // Title
    std::cout << "CHARACTER CREATOR" << std::endl;
    std::cout << std::endl;

    // Set the name
    std::cout << "Name: ";
    getline(std::cin >> std::ws, name);
    std::cout << std::endl;
    character.setName(name);

    // Set the gender
    std::cout << "Gender: " << std::endl;
    printArray(genders);
    std::cin >> option;
    while (option < 1 || option > 3)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    character.setGender(genders[option - 1]);

    // Set the age
    std::cout << "Age: ";
    std::cin >> age;
    while (age < 0)
    {
        std::cout << "Invalid age" << std::endl;
        std::cin >> age;
    }
    std::cout << std::endl;
    character.setAge(age);

    // Set the alignment
    std::cout << "Alignment: " << std::endl;
    printArray(alignments);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    character.setAlignment(alignments[option - 1]);

    // Set the race
    std::cout << "Race: " << std::endl;
    printArray(races);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    character.defineRace(option - 1);

    // Set the class
    std::cout << "Class: " << std::endl;
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    character.defineClass(option - 1);

    // Set the stats
    std::cout << "Stats:" << std::endl;
    std::cout << "The stats are generated randomly." << std::endl;
    character.defineStats();
    std::cout << std::endl;

    return;
}

#endif // End of the preprocessor FUNCTIONS_H