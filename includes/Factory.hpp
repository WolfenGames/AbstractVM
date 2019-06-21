/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:04:20 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/20 14:06:33 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

#include "IOperand.hpp"
#include "Operand.hpp"

class Factory
{
	private:
		
	public:
		Factory();
		~Factory();
		IOperand	*getOperator(std::string);
};

#endif