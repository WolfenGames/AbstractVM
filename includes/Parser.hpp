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
		void	push(std::list<void>::iterator&);
		void	pop(std::list<void>::iterator&);
		void	dump(std::list<void>::iterator&);
		void	assert(std::list<void>::iterator&);
		void	add(std::list<void>::iterator&);
		void	sub(std::list<void>::iterator&);
		void	mul(std::list<void>::iterator&);
		void	div(std::list<void>::iterator&);
		void	mod(std::list<void>::iterator&);
		void	print(std::list<void>::iterator&);
		void	exit(std::list<void>::iterator&);
		void	end(std::list<void>::iterator&);
		~Parser(void);
	private:
		std::list<void>	stack;
};

#endif