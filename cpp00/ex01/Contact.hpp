/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:32:20 by mcardoso          #+#    #+#             */
/*   Updated: 2026/06/18 17:08:44 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		std::string	getFirst();
		std::string	getLast();
		std::string	getNumber();
		std::string	getNick();
		std::string	getSecret();

		void	setFirst(const std::string& firstname);
		void	setLast(const std::string& lastname);
		void	setNick(const std::string& nickname);
		void	setNumber(const std::string& number);
		void	setSecret(const std::string& secret);
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	number;
		std::string	secret;
};

#endif