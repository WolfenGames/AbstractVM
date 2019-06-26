/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:33:26 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/25 10:33:26 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Factory.hpp"
#include "Parser.hpp"
#include "Lexer.hpp"
#include "Exceptions.hpp"
#include <fstream>

int		main(int ac, char *av[])
{
	if (ac < 2)
	{
		Parser p;
		p.Run();
	}
	else
	{
		std::ifstream s(av[1]);
		if (!s)
		{
			std::cout << "Invalid Input shit" << std::endl;
			return 0;
		}
		Parser p(s);
		p.Run();
	}
	return 0;
}