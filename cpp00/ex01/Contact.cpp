/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:32:22 by mcardoso          #+#    #+#             */
/*   Updated: 2026/06/18 17:09:07 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

std::string	Contact::getFirst() {
	return firstname;
}

std::string	Contact::getLast() {
	return lastname;
}

std::string	Contact::getNick() {
	return nickname;
}

std::string	Contact::getNumber() {
	return number;
}

std::string	Contact::getSecret() {
	return secret;
}

void	Contact::setFirst(const std::string& firstname) {
	this->firstname = firstname;
}

void	Contact::setLast(const std::string& lastname) {
	this->lastname = lastname;
}

void	Contact::setNick(const std::string& nickname) {
	this->nickname = nickname;
}

void	Contact::setNumber(const std::string& phonenumber) {
	this->number = phonenumber;
}

void	Contact::setSecret(const std::string& secret) {
	this->secret = secret;
}
