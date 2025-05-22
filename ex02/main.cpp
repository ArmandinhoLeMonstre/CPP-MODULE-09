/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:44:10 by armitite          #+#    #+#             */
/*   Updated: 2025/05/22 16:44:11 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe <int> <int> ..." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    parseInput(ac, av, vec, deq);
    printContainer("Before: ", vec);

    long startVec = getTime();
    sortVector(vec);
    long endVec = getTime();

    long startDeq = getTime();
    sortDeque(deq);
    long endDeq = getTime();

    printContainer("After: ", vec);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << (endVec - startVec) << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << (endDeq - startDeq) << " us" << std::endl;

    return 0;
}
