/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:44:22 by armitite          #+#    #+#             */
/*   Updated: 2025/05/22 16:44:23 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

int getOperatorCode(char c);
int applyOperation(int a, int b, int opCode);
int evaluateRPN(const std::string& expr);
