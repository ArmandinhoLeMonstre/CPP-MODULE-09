#include "PmergeMe.hpp"

void printContainer(const std::string& msg, const std::vector<int>& vec) {
    std::cout << msg;
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

long getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

void parseInput(int ac, char** av, std::vector<int>& vec, std::deque<int>& deq) {
    for (int i = 1; i < ac; ++i) {
        std::string arg = av[i];
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
        int val = std::atoi(arg.c_str());
        if (val < 0) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        vec.push_back(val);
        deq.push_back(val);
    }
}

std::vector<size_t> jacobsthalOrder(size_t n) {
	
	std::vector<size_t> order;
	
	order.push_back(0);
	if (n == 1)
		return order;
	order.push_back(1);
	if (n == 2)
		return order;
	size_t j0 = 1;
	size_t j1 = 1;
	size_t next = j1 + 2 * j0;

	while (next < n){

		order.push_back(next);
		j0 = j1;
		j1 = next;
		next = j1 + 2 * j0;
	}

	size_t i = 0;
	while (i < n){

		if (std::find(order.begin(), order.end(), i) == order.end()) {
        	order.push_back(i);
   		}
		i++;
	}

	return order;
}

void mergeInsertSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1) {
        return;
    }

    std::vector<int> mainChain;
    std::vector<int> pending;
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b) {
            std::swap(a, b);
        }
        mainChain.push_back(a);
        pending.push_back(b);
    }
    if (vec.size() % 2 == 1) {
        mainChain.push_back(vec.back());
    }

    mergeInsertSortVector(mainChain);

    std::vector<size_t> order = jacobsthalOrder(pending.size());
    for (size_t k = 0; k < order.size(); ++k) {
        size_t idx = order[k];
        int val = pending[idx];
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(it, val);
    }

    vec = mainChain;
}

void mergeInsertSortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1) {
        return;
    }

    std::deque<int> mainChain;
    std::deque<int> pending;
    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        int a = deq[i];
        int b = deq[i + 1];
        if (a < b) {
            std::swap(a, b);
        }
        mainChain.push_back(a);
        pending.push_back(b);
    }
    if (deq.size() % 2 == 1) {
        mainChain.push_back(deq.back());
    }

    mergeInsertSortDeque(mainChain);

    std::vector<size_t> order = jacobsthalOrder(pending.size());
    for (size_t k = 0; k < order.size(); ++k) {
        size_t idx = order[k];
        int val = pending[idx];
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(it, val);
    }

    deq = mainChain;
}

void sortVector(std::vector<int>& vec) {
    mergeInsertSortVector(vec);
}

void sortDeque(std::deque<int>& deq) {
    mergeInsertSortDeque(deq);
}
