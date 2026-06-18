/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:32:11 by mcardoso          #+#    #+#             */
/*   Updated: 2026/06/18 18:44:40 by mcardoso         ###   ########.fr       */
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
	bool		valid;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	Contacts[index].setFirst(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	Contacts[index].setLast(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	Contacts[index].setNick(input);
	while (true) {
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
		valid = true;
		if (input.length() != 9)
			valid = false;
		else {
			for (size_t i = 0; i < input.length(); i++) {
				if (!std::isdigit(input[i])) {
					valid = false;
					break ;
				}
			}
		}
		if (valid)
			break ;
	}
	Contacts[index].setNumber(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	Contacts[index].setSecret(input);
	index = (index + 1) % 8;
	if (total < 8)
		total++;
}

void	Phonebook::searchContact() {
	std::string input;
	int	index;
	if (total == 0) {
		std::cout << "Phonebook is empty\n";
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < total; i++) {
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << truncate(Contacts[i].getFirst()) << "|"
				  << std::setw(10) << truncate(Contacts[i].getLast()) << "|"
				  << std::setw(10) << truncate(Contacts[i].getNick()) << std::endl;
	}
	while (true) {
		std::cout << "Enter index: ";
		if (!std::getline(std::cin, input))
			return ;
		std::stringstream ss(input);
		if (ss >> index && ss.eof() && (index >= 1 && index <= total))
			break ;
		std::cout << "Invalid index. Try again.\n";
	}
	index--;
	std::cout << "First name: " << Contacts[index].getFirst() << std::endl;
	std::cout << "Last name: " << Contacts[index].getLast() << std::endl;
	std::cout << "Nickname: " << Contacts[index].getNick() << std::endl;
	std::cout << "Phone number: " << Contacts[index].getNumber() << std::endl;
	std::cout << "Darkest secret: " << Contacts[index].getSecret() << std::endl;
}