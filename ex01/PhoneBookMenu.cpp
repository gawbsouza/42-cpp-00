/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookMenu.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:23:26 by gasouza           #+#    #+#             */
/*   Updated: 2024/01/15 20:22:22 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <cstdio>

#include "PhoneBookMenu.hpp"

void clearScreen()
{
    std::system("clear");
}

void clearInputStream()
{
    std::clearerr(stdin);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pressToContinue()
{
    std::string dummy;
    std::cout  << std::endl << "Press enter to continue." << std::endl;
    std::getline(std::cin, dummy);
}

PhoneBookMenu::PhoneBookMenu(PhoneBook *phoneBook)
{
    this->phoneBook = phoneBook;
}

bool PhoneBookMenu::isAddOption(std::string option)
{ 
    return option.compare(ADD_OPTION) == 0; 
}

bool PhoneBookMenu::isSearchOption(std::string option)
{
    return option.compare(SEARCH_OPTION) == 0;
}

bool PhoneBookMenu::isExitOption(std::string option)
{
    return option.compare(EXIT_OPTION) == 0;
};

void PhoneBookMenu::listOptions()
{
    std::cout << ADD_OPTION << std::endl;
    std::cout << SEARCH_OPTION << std::endl;
    std::cout << EXIT_OPTION << std::endl;
}

bool PhoneBookMenu::isValidOption(std::string option)
{ 
    if (isAddOption(option)) return true;
    if (isSearchOption(option)) return true;
    if (isExitOption(option)) return true;
    
    return false;
}

std::string PhoneBookMenu::readOption()
{
    std::string option;
    
    std::cout << "Please select an option bellow:" << std::endl;
    std::cout << std::endl;
    listOptions();
    std::cout << std::endl;

    for (;;) {
        
        std::cout << "Your input: ";
        std::cin >> option;
        
        if (!std::cin.eof())
        {
            for (std::size_t i = 0; i < option.size(); i++) {
                option[i] = toupper(option[i]);
            }
        }

        clearInputStream();

        if (!isValidOption(option)) {
            std::cout 
                << RED_COLOR << "Invalid option!" 
                << RESET_COLOR << std::endl;
            continue;
        }

        break;
    }

    return option;
}

std::string PhoneBookMenu::readValueWithMinLength(std::string desc, size_t minLength)
{
    std::string value;
    
    for(;;) {
        
        std::cout << desc << ": ";
        std::getline(std::cin, value);

        if (value.size() < minLength) {
            std::cout 
                << RED_COLOR
                << desc << " must have at least " 
                << minLength << " characters."
                << RESET_COLOR
                << std::endl;
            continue;
        }
        
        break;
    }

    return value;
}

void PhoneBookMenu::doAddOption()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string secret;
    std::string phoneNumber;
    
    std::cout << ":: Adding new contact ::" << std::endl << std::endl;
    
    firstName = readValueWithMinLength("First Name", 3);
    lastName = readValueWithMinLength("Last Name", 3);
    nickname = readValueWithMinLength("Nickname", 0);
    phoneNumber = readValueWithMinLength("Phone Number", 8);
    secret = readValueWithMinLength("Secret", 0);
    
    Contact con;
    
    con.setFirstName(firstName);
    con.setLastName(lastName);
    con.setNickname(nickname);
    con.setPhoneNumber(phoneNumber);
    con.setSecret(secret);

    phoneBook->addContact(con);
    
    std::cout 
        << GREEN_COLOR << "Contact added!" 
        << RESET_COLOR << std::endl;
        
    pressToContinue();
    clearScreen();
}

void PhoneBookMenu::doSearchOption()
{
    size_t index;
    Contact con;
    
    std::cout << ":: Searching contact ::" << std::endl << std::endl ;
    phoneBook->printContactListNotBlank();
    std::cout << std::endl;
    std::cout << "You can inform 0 to exit this screen." <<std::endl;
    std::cout << std::endl;

    for (;;) {
        
        std::cout << "Index to show: ";
        std::cin >> index;
        
        if (std::cin.fail() || std::cin.eof())
        {
            if (std::cin.eof())
                std::cout << std::endl;
                
            std::cout 
                << RED_COLOR << "Invalid input!" << RESET_COLOR << std::endl;
            clearInputStream();
            continue;
        }
        
        if (index == 0) {
            clearInputStream();
            clearScreen();
            return;
        }

        bool exists = phoneBook->getContactAtIndex(&con, index - 1);
        
        if (!exists) {
            std::cout 
                << RED_COLOR << "Index should be between 1 and " << MAX_CONTACTS 
                << RESET_COLOR << std::endl;
            continue;
        }

        if (con.getFirstName().compare("") == 0)
        {
            std::cout 
                << CYAN_COLOR << "Hmmm, there is no contact here yet." 
                << RESET_COLOR << std::endl;
            continue;
        }

        break;
    }
    
    clearScreen();
    clearInputStream();
    std::cout << ":: Showing contact (" << index << ") ::" << std::endl << std::endl ;
    std::cout << "First Name: " << con.getFirstName() << std::endl;
    std::cout << "Last Name: " << con.getLastName() << std::endl;
    std::cout << "Nickname: " << con.getNickname() << std::endl;
    std::cout << "Phone Number: " << con.getPhoneNumber() << std::endl;
    std::cout << "Secret: " << con.getSecret() << std::endl;
    pressToContinue();
    clearScreen();
}

void PhoneBookMenu::readLoop()
{
    std::string option;

    for(;;) {

        option = readOption();

        if (isAddOption(option))  {
            clearScreen();
            doAddOption();
        }

        if (isSearchOption(option))  {
            clearScreen();
            doSearchOption();
        }

        if (isExitOption(option)) {
            std::cout << "Bye Bye!" << std::endl;
            break;
        }
    }

}