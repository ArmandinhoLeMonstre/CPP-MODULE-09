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
