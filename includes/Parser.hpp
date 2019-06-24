/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:09:56 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/16 11:09:56 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <vector>
#include "Operand.hpp"
#include "IOperand.hpp"

class Parser
{
	typedef std::vector<const IOperand*> stackType;
	public:
		Parser(void);
		Parser(const Parser&);
		const Parser& operator=(const Parser&);
		Parser(stackType&);
		void	Push(void);
		void	Pop(void);
		void	Dump(void);
		void	Assert(void);
		void	Add(void);
		void	Sub(void);
		void	Mul(void);
		void	Div(void);
		void	Mod(void);
		void	Print(void);
		void	End(void);
		~Parser(void);
	private:
		stackType m_stack;
};