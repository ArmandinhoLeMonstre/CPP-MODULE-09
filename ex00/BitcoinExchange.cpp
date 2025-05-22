/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:08 by armitite          #+#    #+#             */
/*   Updated: 2025/05/22 17:14:26 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float getRateForDate(const std::string& date, const std::map<std::string, float>& data) {
    std::map<std::string, float>::const_iterator it = data.begin();
	if (date < it->first)
		return -1.0f;
	while (it != data.end()) {
		
		if (it->first == date) {

			if (it == data.begin())
				return -1.0f;
			return it->second;
		}
		if (it->first > date) {
			
			it--;
			return it->second;
		}
		it++;
	}
	it--;
    return it->second;
}

int check_value(std::string value) {

	size_t i = 0;
	size_t dot_counter = 0;

	if (value.at(0) == '.')
		return (1);
	while (i < value.size())
	{
		if (isdigit(value.at(i)) == 0 && value.at(i) != '.')
			return (1);
		else if (value.at(i) == '.')
			dot_counter++;
		if (dot_counter > 1)
			return (1);
		i++;
	}
	return (0);
}

int check_date(std::string date) {

	size_t i = 0;
	
	while (i < date.size())
	{
		if (i <= 3 || (i >= 5 && i <= 6) || (i >= 8 && i <= 9))
		{
			if (isdigit(date.at(i)) == 0)
				return (1);
		}
		else if (date.at(i) != '-')
			return (1);
		i++;
	}
	return (0);
}

int setData(std::map<std::string, float> &data) {

	std::ifstream ifs;

	ifs.open ("data.csv");

	if (!ifs.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ostringstream oss;
    oss << ifs.rdbuf();

	std::string content;
	std::string test;
	std::string date;
	std::string value_str;
	float value;
	content = oss.str();

	size_t found, found2, found3;
	found2 = content.find("2009-01-02");
	content.erase(0, found2);
	while (!content.empty()) {

		found = content.find(",");
		found2 = content.find('\n', found + 1);
		if (found2 == std::string::npos || found == std::string::npos)
			break ;
		test.assign(content, 0, found2);
		found3 = test.find(',');
		if (found3 == std::string::npos)
			break ;
		date.assign(test, 0, found3);
		if (check_date(date)) {
			
			std::cout << "Error date in the data file" << std::endl;
			return (1);
		}
		value_str = test.substr(found3 + 1);
		if (check_value(value_str)) {

			std::cout << "Error value in the data file" << std::endl;
			return (1);
		}
		value = std::atof(value_str.c_str());
		data[date] = value;
		content.erase(0, found2 + 1);
	}

	ifs.close();

	return (0);
}