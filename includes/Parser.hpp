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

#ifndef PARSER_HPP
# define PARSER_HPP

#include <list>
#include "IOperand.hpp"

class Parser
{
	public:
		Parser(void);
		Parser(const Parser&);
		const Parser& operator=(const Parser&);
		Parser(std::list<void>&);
		void	push(void);
		void	pop(void);
		void	dump(void);
		void	assert(void);
		void	add(void);
		void	sub(void);
		void	mul(void);
		void	div(void);
		void	mod(void);
		void	print(void);
		void	end(void);
		~Parser(void);
	private:
		std::list<void>	stack;
};

#endif