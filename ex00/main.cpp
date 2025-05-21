/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:12 by armitite          #+#    #+#             */
/*   Updated: 2025/05/21 13:28:30 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (!av[4])
		return (0);
	std::map<std::string, float> data;
	if (ac == 2)
	{
		setData(data);
		std::map<std::string, float>::iterator it;
		for (it = data.begin(); it != data.end(); it++){
			
			std::cout << it->first << " " << it->second << std::endl;
		}
	}
	else
		std::cout << "Must have 2 arguments" << std::endl;

	return (0);
}