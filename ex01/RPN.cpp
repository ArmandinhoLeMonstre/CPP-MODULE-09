/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:44:19 by armitite          #+#    #+#             */
/*   Updated: 2025/05/22 16:44:20 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int getOperatorCode(char c) {
    if (c == '+') return 1;
    if (c == '-') return 2;
    if (c == '*') return 3;
    if (c == '/') return 4;
    return 0;
}

int applyOperation(int a, int b, int opCode) {
    switch (opCode) {
        case 1: return a + b;
        case 2: return a - b;
        case 3: return a * b;
        case 4:
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        default: throw std::runtime_error("Unknown operator");
    }
}

int evaluateRPN(const std::string& expr) {
    std::stack<int> stack;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            stack.push(token[0] - '0');
        }
        else if (token.length() == 1 && getOperatorCode(token[0])) {
            if (stack.size() < 2)
                throw std::runtime_error("Not enough operands");

            int b = stack.top(); 
			stack.pop();
            int a = stack.top(); 
			stack.pop();

            int result = applyOperation(a, b, getOperatorCode(token[0]));

            stack.push(result);
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression");

    return stack.top();
}
