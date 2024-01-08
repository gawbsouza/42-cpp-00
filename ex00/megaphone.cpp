/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:20:04 by gasouza           #+#    #+#             */
/*   Updated: 2024/01/08 06:02:01 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#define NO_PARAMETERS_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void printLoudly(char *str);

int main(int argc, char *argv[])
{

    if (argc < 2) {
        std::cout << NO_PARAMETERS_MSG << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++ ) {
        printLoudly(argv[i]);
    }

    std::cout << std::endl;
    
    return 0;
}

void printLoudly(char *str)
{
    while (*str) {
        std::cout.put(toupper(*str));
        str++;
    }
}