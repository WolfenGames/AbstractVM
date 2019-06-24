/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:52:12 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/16 10:52:12 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Factory.hpp"

int		main(void)
{
	Factory			OperandFactory;
	while (true)
	{
		std::string	input;
		std::getline(std::cin, input);
	};
	return 0;
}