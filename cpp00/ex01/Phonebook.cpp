/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:32:11 by mcardoso          #+#    #+#             */
/*   Updated: 2026/07/13 12:22:16 by mcardoso         ###   ########.fr       */
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

std::string Phonebook::clean(const std::string& str) {
	std::string cleaned;

	for (size_t i = 0; i < str.length(); i++) {
		unsigned char ch = static_cast<unsigned char>(str[i]);
		if (std::isprint(ch))
			cleaned += str[i];
		else
			cleaned += ' ';
	}
	return cleaned;
}

void	Phonebook::addContact() {
	std::string	input;
	bool		valid;

	while (true) {
		std::cout << "First name: ";
		if (!std::getline(std::cin, input))
			return ;
		if (!input.empty())
			break ;
		std::cout << "Field cannot be empty.\n";
	}
	Contacts[index].setFirst(input);
	while (true) {
		std::cout << "Last name: ";
		if (!std::getline(std::cin, input))
			return ;
		if (!input.empty())
			break ;
		std::cout << "Field cannot be empty.\n";
	}
	Contacts[index].setLast(input);
	while (true) {
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, input))
			return ;
		if (!input.empty())
			break ;
		std::cout << "Field cannot be empty.\n";
	}
	Contacts[index].setNick(input);
	while (true) {
		std::cout << "Phone Number: ";
		if (!std::getline(std::cin, input))
			return ;
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
		std::cout << "Phone number must contain exactly 9 digits.\n";
	}
	Contacts[index].setNumber(input);
	while (true) {
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, input))
			return ;
		if (!input.empty())
			break ;
		std::cout << "Field cannot be empty.\n";
	}
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
				  << std::setw(10) << truncate(clean(Contacts[i].getFirst())) << "|"
				  << std::setw(10) << truncate(clean(Contacts[i].getLast())) << "|"
				  << std::setw(10) << truncate(clean(Contacts[i].getNick())) << std::endl;
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
	std::cout << "First name: " << clean(Contacts[index].getFirst()) << std::endl;
	std::cout << "Last name: " << clean(Contacts[index].getLast()) << std::endl;
	std::cout << "Nickname: " << clean(Contacts[index].getNick()) << std::endl;
	std::cout << "Phone number: " << clean(Contacts[index].getNumber()) << std::endl;
	std::cout << "Darkest secret: " << clean(Contacts[index].getSecret()) << std::endl;
}