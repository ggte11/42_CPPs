#ifndef Brain_HPP
# define Brain_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
		std::string getIdeas(int i) const;
		void setIdeas(int i, std::string idea);
};

#endif