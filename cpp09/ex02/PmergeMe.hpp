#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <stdexcept>
#include <limits>
#include <sstream>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool isValidInput(int argc, char **argv);
		void sort(int argc,char **argv);
		void sortVector();
		void sortDeque();
};

#endif