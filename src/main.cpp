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

int		main(void)
{
	Factory f;
	IOperand const *x = f.getOperator(eOperandType::DOUBLE, "12");
	std::cout << x->toString() << std::endl; 
	return 0;
}