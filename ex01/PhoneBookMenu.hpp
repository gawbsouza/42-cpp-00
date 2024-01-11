/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookMenu.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:23:39 by gasouza           #+#    #+#             */
/*   Updated: 2024/01/10 06:39:25 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_MENU_H
# define PHONE_BOOK_MENU_H

# include <string>
# include <iostream>
# include <cstring>

# include "PhoneBook.hpp"

# define ADD_OPTION      "ADD"
# define SEARCH_OPTION   "SEARCH"
# define EXIT_OPTION     "EXIT"
# define LIST_OPTION     "LIST"

# define RESET_COLOR     "\033[39m"
# define RED_COLOR       "\033[91m"
# define GREEN_COLOR     "\033[92m"
# define CYAN_COLOR     "\033[96m"

class PhoneBookMenu {

private:

    PhoneBook *phoneBook;

    void listOptions();
    bool isAddOption(std::string option);
    bool isSearchOption(std::string option);
    bool isExitOption(std::string option);
    bool isValidOption(std::string option);
    void doAddOption();
    void doSearchOption();
    std::string readOption();
    std::string readValueWithMinLength(std::string desc, size_t minLength);

public:
    PhoneBookMenu(PhoneBook *phoneBook);
    void readLoop();

};

#endif