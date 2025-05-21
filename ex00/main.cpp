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

int	main(int ac, char **av)
{
	if (!av[4])
		return (0);
	std::map<std::string, float> data;
	data["alo"] = 12;
	if (ac == 2)
	{
		setData(data);
		std::map<std::string, float>::iterator it = data.begin();
		while (it != data.end()){
			
			std::cout << it->first << " " << it->second << std::endl;
			it++;
		}
	}
	else
		std::cout << "Must have 2 arguments" << std::endl;

	return (0);
}