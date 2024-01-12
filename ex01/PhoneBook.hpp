/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:07:38 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/12 11:31:47 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"
# include <string>

# define MAX_CONTACTS 8
# define MAX_COLUMN_LENGTH 10

class PhoneBook
{
    
private:

    int nextSlot;
	
    Contact contactList[MAX_CONTACTS];
    void printColumn(std::string str);

public:

    PhoneBook();
    void addContact(Contact contact);
    void printContactListNotBlank();
    bool getContactAtIndex(Contact *con, size_t index);
    
};

#endif