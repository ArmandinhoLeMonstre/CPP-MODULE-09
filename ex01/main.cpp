/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:44:16 by armitite          #+#    #+#             */
/*   Updated: 2025/05/22 16:44:17 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    try {
        int result = evaluateRPN(av[1]);
        std::cout << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
