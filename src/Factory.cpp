/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:37:39 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/25 10:37:39 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Operand.hpp"

creator_t	 Factory::CreatorFunctions[]=
{
	&Factory::CreateINT8,
	&Factory::CreateINT16,
	&Factory::CreateINT32,
	&Factory::CreateFLOAT,
	&Factory::CreateDOUBLE,
};


Factory::Factory(void){}
Factory::Factory(const Factory& rhs){*this = rhs;}
Factory::~Factory(void){}

Factory &Factory::operator=(const Factory& rhs) { if (this != &rhs) *this = rhs; return *this; }

IOperand const *Factory::getOperator(eOperandType type, std::string val) const
{
	creator_t fun = CreatorFunctions[static_cast<int>(type)];
	return ((*this).*(fun))(val);
}

IOperand const *Factory::CreateINT8(const std::string& val) const { return new Operand<int8_t>(val); }
IOperand const *Factory::CreateINT16(const std::string& val) const { return new Operand<int16_t>(val); }
IOperand const *Factory::CreateINT32(const std::string& val) const { return new Operand<int32_t>(val); }
IOperand const *Factory::CreateFLOAT(const std::string& val) const { return new Operand<float>(val); }
IOperand const *Factory::CreateDOUBLE(const std::string& val) const { return new Operand<double>(val); }
