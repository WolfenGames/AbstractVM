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

int		main(void)
{
	Factory f;
	try
	{
		IOperand const *x = f.getOperator(eOperandType::INT16, "12");
		IOperand const *y = f.getOperator(eOperandType::INT16, "0");
		IOperand const *z = *x % *y;
		std::cout << z->toString() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}