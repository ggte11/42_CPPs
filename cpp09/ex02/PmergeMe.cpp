#include "PmergeMe.hpp"
#include <cmath>
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidInput(int argc, char **argv) {
	_vector.clear();
	_deque.clear();
	if (argc < 2)
		return false;
	for (int i = 1; i < argc; i++) {
		std::istringstream stream(argv[i]);
		int nb;
		stream >> nb;
		if (stream.fail() || !stream.eof())
			return false;
		if (nb <= 0)
			return false;
		_vector.push_back(nb);
		_deque.push_back(nb);
	}
	return true;
}

void PmergeMe::sort(int argc, char **argv) {
	if (!isValidInput(argc, argv))
		throw std::runtime_error("Error");
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin();
		it != _vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::size_t count = _vector.size();
	long long vectorStart = getTimestamp();
	sortVector();
	long long vectorEnd = getTimestamp();
	long long dequeStart = getTimestamp();
	sortDeque();
	long long dequeEnd = getTimestamp();
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = _vector.begin();
		it != _vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of "
		<< count << " elements with std::vector : "
		<< vectorEnd - vectorStart << " us" << std::endl;
	std::cout << "Time to process a range of "
		<< count << " elements with std::deque : "
		<< dequeEnd - dequeStart << " us" << std::endl;
}

std::vector<std::size_t> PmergeMe::jacobsthalOrder(std::size_t count) const {
	std::vector<std::size_t> order;
	if (count == 0)
		return order;
	std::vector<bool> used(count, false);
	order.push_back(0);
	used[0] = true;
	std::size_t jPrev = 1;
	std::size_t jCurr = 3;
	while (order.size() < count) {
		std::size_t high = (jCurr > count) ? count :jCurr;
		std::size_t low = (jPrev > count) ? count : jPrev;
		for (std::size_t k = high; k > low; k--) {
			std::size_t idx = k - 1;
			if (idx < count && !used[idx]) {
				order.push_back(idx);
				used[idx] = true;
			}
		}
		std::size_t next = jCurr + 2 * jPrev;
		jPrev = jCurr;
		jCurr = next;
	}
	return order;
}

void PmergeMe::sortVector() {
	if (_vector.size() < 2)
		return ;
	std::vector<int> src = _vector;
	std::vector<int> mainChain;
	std::vector<Pair> pairs;
	bool hasOdd = (src.size() % 2 != 0);
	int oddValue = 0;
	for (std::size_t i = 0; i + 1 < src.size(); i += 2) {
		int first = src[i];
		int second = src[i + 1];
		Pair pair;
		if (first < second) {
			pair.smaller = first;
			pair.larger = second;
		}
		else {
			pair.smaller = second;
			pair.larger = first;
		}
		pairs.push_back(pair);
		mainChain.push_back(pair.larger);
	}
	if (hasOdd)
		oddValue = src.back();
	_vector = mainChain;
	sortVector();
	mainChain = _vector;
	std::vector<std::size_t> order = jacobsthalOrder(pairs.size());
	for (std::size_t i = 0; i < order.size(); i++) {
		int value = pairs[order[i]].smaller;
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(pos, value);
	}
	if (hasOdd) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddValue);
		mainChain.insert(pos, oddValue);
	}
	_vector = mainChain;
}

void PmergeMe::sortDeque() {
	if (_deque.size() < 2)
		return;
	std::deque<int> src = _deque;
	std::deque<int> mainChain;
	std::vector<Pair> pairs;
	bool hasOdd = (src.size() % 2 != 0);
	int oddValue = 0;
	for (std::size_t i = 0; i + 1 < src.size(); i += 2) {
		int first = src[i];
		int second = src[i + 1];
		Pair pair;
		if (first < second) {
			pair.smaller = first;
			pair.larger = second;
		}
		else {
			pair.smaller = second;
			pair.larger = first;
		}
		pairs.push_back(pair);
		mainChain.push_back(pair.larger);
	}
	if (hasOdd)
		oddValue = src.back();
	_deque = mainChain;
	sortDeque();
	mainChain = _deque;
	std::vector<std::size_t> order =
		jacobsthalOrder(pairs.size());
	for (std::size_t i = 0; i < order.size(); ++i) {
		int value = pairs[order[i]].smaller;
		std::deque<int>::iterator position =
			std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(position, value);
	}
	if (hasOdd) {
		std::deque<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), oddValue);
		mainChain.insert(position, oddValue);
	}
	_deque = mainChain;
}

long long PmergeMe::getTimestamp() const {
	struct timeval time;
	gettimeofday(&time, NULL);
	return (static_cast<long long>(time.tv_sec) * 1000000 + time.tv_usec);
}