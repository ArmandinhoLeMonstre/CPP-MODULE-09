/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:08 by armitite          #+#    #+#             */
/*   Updated: 2025/05/16 17:21:54 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int setData(std::map<std::string, float> &data) {

	data["Alo"] = 12;
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
	content = oss.str();
	size_t found;
	size_t found2;
	found = content.find(",");
	found2 = content.find(',', found + 1);
	std::cout << "Found 1 : " << found << "Found 2 : " << found2 <<std::endl;
	test.assign(content, 0, found2);
	//std::cout << content << std::endl;
	std::cout << test << std::endl;

	ifs.close();

	return (0);
}