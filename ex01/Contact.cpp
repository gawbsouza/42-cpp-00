/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:01:12 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/08 05:55:04 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

Contact::Contact() {
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    secret = "";
}
    
void Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setNickname(std::string nickName) {
    this->nickname = nickName;
}

void Contact::setSecret(std::string secret) {
    this->secret = secret;
}

std::string Contact::getFirstName() {
    return this->firstName;
}

std::string Contact::getLastName() {
    return this->lastName;
}

std::string Contact::getNickname() {
    return this->nickname;
}

std::string Contact::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Contact::getSecret() {
    return this->secret;
}
