/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:08 by armitite          #+#    #+#             */
/*   Updated: 2025/05/21 14:17:26 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int setData(std::map<std::string, float> &data) {

	std::ifstream ifs;

	ifs.open ("data.csv");

	if (!ifs.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
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
	size_t found;
	size_t found2;
	size_t found3;
	found2 = content.find("2009-01-02");
	if (found2 == std::string::npos || found == std::string::npos)
		return (1);
	int i = 1;
	content.erase(0, found2);
	while (found2 != std::string::npos) {

		found = content.find(",");
		found2 = content.find('\n', found + 1);
		if (found2 == std::string::npos || found == std::string::npos)
			break ;
		test.assign(content, 0, found2);
		if (i == 1) {

			std::cout << test << std::endl;
		}
		found3 = test.find(',');
		if (found3 == std::string::npos)
			break ;
		date.assign(test, 0, found3);
		value_str = test.substr(found3 + 1);
		value = std::atof(value_str.c_str());
		data[date] = value;
		content.erase(0, found2 + 1);
	}

	ifs.close();

	return (0);
}