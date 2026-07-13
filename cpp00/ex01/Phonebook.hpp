/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:32:14 by mcardoso          #+#    #+#             */
/*   Updated: 2026/07/13 12:11:22 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>
#include "Contact.hpp"

class	Phonebook {
	public:
		Phonebook();
		~Phonebook();
		void	addContact();
		void	searchContact();
		std::string	truncate(const std::string& str);
		std::string	clean(const std::string& str);
	private:
		Contact	Contacts[8];
		int	index;
		int	total;
};

#endif