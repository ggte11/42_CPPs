#include "Contact.hpp"

Contact::Contact(){}

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
	return phonenumber;
}

std::string	Contact::getSecret() {
	return darkestsecret;
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
	this->phonenumber = phonenumber;
}

void	Contact::setSecret(const std::string& darkestsecret) {
	this->darkestsecret = darkestsecret;
}
