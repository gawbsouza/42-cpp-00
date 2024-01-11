/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:42:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/08 06:40:19 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookMenu.hpp"

int main()
{
    PhoneBook pb;
    PhoneBookMenu menu(&pb);
    menu.readLoop();
    return 0;
}