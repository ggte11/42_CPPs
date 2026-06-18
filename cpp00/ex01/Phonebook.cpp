/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:32:11 by mcardoso          #+#    #+#             */
/*   Updated: 2026/06/18 17:34:29 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : index(0), total(0) {}

Phonebook::~Phonebook() {}

std::string Phonebook::truncate(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	return str;
}

void	Phonebook::addContact() {
	std::string	input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	Contacts[index].setFirst(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	Contacts[index].setLast(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	Contacts[index].setNick(input);

	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	Contacts[index].setNumber(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	Contacts[index].setSecret(input);
	index = (index + 1) % 8;
	if (total < 8)
		total++;
}

void	Phonebook::searchContact() {

}