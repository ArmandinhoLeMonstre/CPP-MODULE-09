#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <cstdlib>

void parseInput(int ac, char** av, std::vector<int>& vec, std::deque<int>& deq);
void sortVector(std::vector<int>& vec);
void sortDeque(std::deque<int>& deq);
long getTime();
void printContainer(const std::string& label, const std::vector<int>& vec);
