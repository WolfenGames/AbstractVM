/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:40:13 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/20 12:11:20 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"
#include <iostream>

template<typename T>
class Operand: public IOperand
{
	public:
		~Operand();
		Operand(const Operand&);
		Operand(eOperandType, int, const std::string, const OperandFactory&)

		int	getPrecision(void) const { return precision; };
		eOperandType	getType(void) const { return type; };

		IOperand const	*operator+(IOperand const &rhs) const
		{

		};

		IOperand const	*operator-(IOperand const &rhs) const
		{
			
		};

		IOperand const	*operator*(IOperand const &rhs) const
		{

		};

		IOperand const	*operator/(IOperand const &rhs) const
		{

		};

		IOperand const	*operator%(IOperand const &rhs) const
		{

		};

		std::string	const	&toString(void) const
		{

		};

	private:
		Operand();
		int				precision;
		eOperandType	type;
};


#endif