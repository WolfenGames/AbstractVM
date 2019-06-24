/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:04:20 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/24 16:04:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IOperand.hpp"
#include <functional>

#include <ostream>

class Factory;
typedef IOperand const* (Factory::* creator_t)(const std::string) const; 

class Factory
{
	private:
		
	public:
		static creator_t CreatorFunctions[];
		
		Factory(void);
		~Factory(void);
		IOperand const	*getOperator(eOperandType, std::string);
		Factory			&operator=(const Factory&);
		
		IOperand const	*CreateINT8(const std::string) const;
		IOperand const	*CreateINT16(const std::string) const;
		IOperand const	*CreateINT32(const std::string) const;
		IOperand const	*CreateFLOAT(const std::string) const;
		IOperand const	*CreateDOUBLE(const std::string) const;
};
