/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:12 by armitite          #+#    #+#             */
/*   Updated: 2025/05/21 14:11:14 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


bool is_valid_date(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    // Vérification caractères numériques
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    // Cas spécifique pour février
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            if (day > 29)
                return false;
        } else {
            if (day > 28)
                return false;
        }
    }
    // Mois avec 30 jours : avril, juin, septembre, novembre
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }
    // Mois avec 31 jours
    else {
        if (day > 31)
            return false;
    }

    return true;
}


int displayBitcoins(char *av) {

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
	//float value;
	content = oss.str();

	//size_t found, found2, found3;
	size_t found2 = content.find("date | value");
	if (found2 == std::string::npos)
		return (1);
	content.erase(0, 13);
	std::cout << content << std::endl;
	while (!content.empty()) {

		found2 = content.find('\n');
		line = content.substr(0, found2);
		std::size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos || found2 == std::string::npos) {
            std::cout << "Error: line in incorrect format"<< std::endl;
            continue;
        }
        std::string date = line.substr(0, pipe_pos - 1);
        if (pipe_pos != 11 || line.at(12) != ' ') {
            std::cout << "Error: pipe is missing or at the wrong place" << std::endl;
            continue;
        }
		if (check_date(date)) {
			
			std::cout << "Error date in the data file" << std::endl;
			continue;
		}

        std::string value_str = line.substr(pipe_pos + 2);
        double value = std::atof(value_str.c_str());
		if (check_value(value_str)) {

			std::cout << "Error value in the input file" << std::endl;
			continue;
		}

        if (!is_valid_date(date)) {
            std::cout <<"Error: format date is wrong => " <<  date << std::endl;
            continue;
        }
        if (value > 1000.0f || value < 0.0f) {
            std::cout << "Error: value is too small or too big" << std::endl;
            continue;
        }
	}

	ifs.close();

	return (0);
}

int	main(int ac, char **av)
{
	if (!av[4])
		return (0);
	std::map<std::string, float> data;
	data["alo"] = 12;
	if (ac == 2)
	{
		setData(data);
		displayBitcoins(av[1]);
		// std::map<std::string, float>::iterator it = data.begin();
		// while (it != data.end()){
			
		// 	std::cout << it->first << " " << it->second << std::endl;
		// 	it++;
		// }
	}
	else
		std::cout << "Must have 2 arguments" << std::endl;

	return (0);
}