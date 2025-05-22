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

void mergeInsertSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            int a = vec[i];
            int b = vec[i + 1];
            if (a < b) std::swap(a, b);
            mainChain.push_back(a);
            pending.push_back(b);
        } else {
            mainChain.push_back(vec[i]);
        }
    }

    for (size_t i = 1; i < mainChain.size(); ++i) {
        int key = mainChain[i];
        int j = i - 1;
        while (j >= 0 && mainChain[j] > key) {
            mainChain[j + 1] = mainChain[j];
            --j;
        }
        mainChain[j + 1] = key;
    }

    for (size_t i = 0; i < pending.size(); ++i) {
        int val = pending[i];
        std::vector<int>::iterator it = mainChain.begin();
        while (it != mainChain.end() && *it < val)
            ++it;
        mainChain.insert(it, val);
    }

    vec = mainChain;
}

void mergeInsertSortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (size_t i = 0; i < deq.size(); i += 2) {
        if (i + 1 < deq.size()) {
            int a = deq[i];
            int b = deq[i + 1];
            if (a < b) std::swap(a, b);
            mainChain.push_back(a);
            pending.push_back(b);
        } else {
            mainChain.push_back(deq[i]);
        }
    }

    for (size_t i = 1; i < mainChain.size(); ++i) {
        int key = mainChain[i];
        int j = i - 1;
        while (j >= 0 && mainChain[j] > key) {
            mainChain[j + 1] = mainChain[j];
            --j;
        }
        mainChain[j + 1] = key;
    }

    for (size_t i = 0; i < pending.size(); ++i) {
        int val = pending[i];
        std::deque<int>::iterator it = mainChain.begin();
        while (it != mainChain.end() && *it < val)
            ++it;
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

