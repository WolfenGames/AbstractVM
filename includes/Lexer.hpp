/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:25:01 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/25 14:25:01 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IOperand.hpp"
#include <string>
#include <vector>

enum class eCommand {
	NONE,
	PUSH,
	POP,
	DUMP,
	ASSERT,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT,
	RUN,
	UNKNOWN
};

class Lexer {
	public:
		Lexer(void);
		Lexer(std::string const&, size_t);
		~Lexer(void);
		Lexer(const Lexer&);
		Lexer &operator=(const Lexer&);
		eCommand getCommand() const;
		IOperand const *getValue() const;
		size_t getLine() const;

	private:
		eCommand Command;
		mutable size_t index;
		size_t line;
		IOperand const *val;
};