/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:29:20 by gasouza           #+#    #+#             */
/*   Updated: 2024/01/09 08:18:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void printBoderLine();

PhoneBook::PhoneBook()
{
    nextSlot = 0;
}

void PhoneBook::addContact(Contact contact)
{
    if (nextSlot >= MAX_CONTACTS) {
        nextSlot = 0;
    }

    contactList[nextSlot] = contact;
    nextSlot++;
}

bool PhoneBook::getContactAtIndex(Contact *con, size_t index)
{
    Contact tmp;
    
    if (index >= MAX_CONTACTS)
        return false;
        
    *con = contactList[index];
    return true;
}

void PhoneBook::printContactListNotBlank()
{
    std::string blank = "";

    printBoderLine();
    std::cout << "|";
    printColumn("Index");
    std::cout << "|";
    printColumn("First Name");
    std::cout << "|";
    printColumn("Last Name");
    std::cout << "|";
    printColumn("Nickname");
    std::cout << "|" << std::endl;
    printBoderLine();
    
    for (int i = 0; i < MAX_CONTACTS; i++) {
        
        Contact con = contactList[i];

        if (con.getFirstName().compare("") == 0)
            continue;
        
        std::cout << "|";
        std::cout << std::setw(10) << i + 1;
        std::cout << "|";
        
        printColumn(con.getFirstName());
        std::cout << "|";
        printColumn(con.getLastName());
        std::cout << "|";
        printColumn(con.getNickname());
        std::cout << "|" << std::endl;
        
    }
    
    printBoderLine();
}

void printBoderLine()
{
    std::cout << "+==========+==========+==========+==========+" << std::endl;
}

void PhoneBook::printColumn(std::string str)
{
    if (str.size() <= MAX_COLUMN_LENGTH) {
        std::cout << std::setw(MAX_COLUMN_LENGTH) << str;
        return;
    }
    
    std::cout  << str.substr(0, MAX_COLUMN_LENGTH - 1);
    std::cout.put('.');
}

