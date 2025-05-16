/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:12 by armitite          #+#    #+#             */
/*   Updated: 2025/05/16 16:48:44 by armitite         ###   ########.fr       */
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
	}
	else
		std::cout << "Must have 2 arguments" << std::endl;

	return (0);
}