/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:23:47 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/25 14:23:47 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Factory.hpp"
#include "sstream"
#include "vector"
#include "Lexer.hpp"

class Parser;
typedef void (Parser::* operation_t)(Lexer &);

class Parser
{

	public:
		Parser();
		Parser(std::istream &stream);
		~Parser();
		Parser(Parser const &rhs);
		Parser &operator=(Parser const &rhs);

		void Push(Lexer &l);
		void Pop(Lexer &l);
		void Print(Lexer &l);
		void Dump(Lexer &l);
		void Add(Lexer &l);
		void Sub(Lexer &l);
		void Div(Lexer &l);
		void Mul(Lexer &l);
		void Assert(Lexer &l);
		void Exit(Lexer &l);
		void None(Lexer &l);
		void Mod(Lexer &l);
		void Execute(Lexer &l);
		void Run();
		void Execute();
	
	private:
		static operation_t Operations[];
		std::istream &stream;
		std::stringstream ss;
		std::vector<IOperand const *> stack;
		std::vector<Lexer> instructions;
		bool error;
};
