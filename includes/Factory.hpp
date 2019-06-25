/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:04:20 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/24 20:05:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IOperand.hpp"
#include <functional>

#include <ostream>

class Factory;
typedef IOperand const* (Factory::* creator_t)(const std::string &) const; 

class Factory
{
	private:
		
	public:
		
		Factory(void);
		Factory(const Factory&);
		~Factory(void);
		Factory			&operator=(const Factory&);
		
		IOperand const	*getOperator(eOperandType, std::string) const;
	
	private:
		static creator_t CreatorFunctions[];
		IOperand const	*CreateINT8(const std::string&) const;
		IOperand const	*CreateINT16(const std::string&) const;
		IOperand const	*CreateINT32(const std::string&) const;
		IOperand const	*CreateFLOAT(const std::string&) const;
		IOperand const	*CreateDOUBLE(const std::string&) const;	
};
