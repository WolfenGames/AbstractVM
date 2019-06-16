/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:01:35 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/16 11:01:35 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include <string>

class IOperand
{
	public:
		virtual IOperand *operator+(const IOperand&) const = 0;
		virtual IOperand *operator-(const IOperand&) const = 0;
		virtual IOperand *operator*(const IOperand&) const = 0;
		virtual IOperand *operator/(const IOperand&) const = 0;
		virtual IOperand *operator%(const IOperand&) const = 0;
		virtual std::string &toString(void) const = 0;
		virtual ~IOperand(void) {}
};

#endif