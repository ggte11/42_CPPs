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
#include <algorithm>
#include <sys/time.h>

struct Pair
{
	int smaller;
	int larger;
	std::size_t id;
};

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		std::vector<std::size_t> jacobsthalOrder(std::size_t count) const;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool isValidInput(int argc, char **argv);
		void sort(int argc,char **argv);
		void sortVector();
		void sortDeque();
		long long getTimestamp() const;
};

#endif