/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:12 by armitite          #+#    #+#             */
/*   Updated: 2025/05/22 17:14:59 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool is_valid_date(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
   			return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    if (month == 2) {
        if (year % 4 == 0) {
            if (day > 29)
                return false;
        } else {
            if (day > 28)
                return false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }
    else {
        if (day > 31)
            return false;
    }

    return true;
}

int displayBitcoins(char *av, std::map<std::string, float> &data) {

	std::ifstream ifs;

	ifs.open (av);

	if (!ifs.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
		return (1);
	}
	std::ostringstream oss;
    oss << ifs.rdbuf();

	std::string content;
	std::string line;
	std::string date;
	std::string value_str;
	content = oss.str();

	size_t found2 = content.find("date | value");
	if (found2 == std::string::npos)
		return (1);
	content.erase(0, 13);
	while (!content.empty()) {
        
        found2 = content.find('\n');
        line = content.substr(0, found2);
        content.erase(0, found2 == std::string::npos ? content.size() : found2 + 1);

        std::size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos || pipe_pos < 10 || line.length() <= pipe_pos + 2) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe_pos - 1);
        std::string value_str = line.substr(pipe_pos + 2);
        double value = std::atof(value_str.c_str());

        if (check_date(date) || !is_valid_date(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (check_value(value_str)) {
            std::cout << "Error: bad value => " << value_str << std::endl;
            continue;
        }
        if (value < 0.0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getRateForDate(date, data);
        if (rate < 0.0f) {
            std::cout << "Error: no available data for :" << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }

	ifs.close();

	return (0);
}

int	main(int ac, char **av)
{
	if (!av[4])
		return (0);
	std::map<std::string, float> data;
	if (ac == 2)
	{
		setData(data);
		displayBitcoins(av[1], data);
	}
	else
		std::cout << "Must have 2 arguments" << std::endl;

	return (0);
}