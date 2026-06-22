/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:32:17 by mcardoso          #+#    #+#             */
/*   Updated: 2026/06/22 16:37:35 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main() {
	Phonebook	phonebook;
	std::string	command;
	std::cout << "Enter command (ADD, SEARCH, EXIT): ";
	while (true)
	{
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Unknown command.\n";
		if (std::cin.eof())
			return 0;
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
	}
	return 0;
}