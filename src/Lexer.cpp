/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:27:24 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/25 14:27:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Factory.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <istream>

Lexer::Lexer(void){}
Lexer::Lexer(std::string const& s, size_t line):
	Command(eCommand::NONE), line(line), val(nullptr)
{
	std::vector<std::string> tokens;
	Factory		f;
	size_t		op, cl;
	std::string	work, stype, data;
	eOperandType oper;
	std::string seperator = " \t\v\n";
	size_t	comment = s.find_first_of(";");

	if (comment == 0 && s[1] == ';')
		tokens.push_back(";;");
	for(size_t i = 0; i < s.length() && s[i] != ';' && i < comment; i++)
	{
		i = s.find_first_not_of(seperator, i);
		size_t end = s.find_first_of(seperator, i);
		if (i >= comment) break;
		tokens.push_back(s.substr(i, end - i));
		i = end;
		if (i >= comment) break;
	}
	if (tokens.size() == 0)
		return;
	std::string command = tokens[0];
	if (strcmp(static_cast<const char *>(command.c_str()), "add") == 0) this->Command = eCommand::ADD;
	else if (strcmp(static_cast<const char *>(command.c_str()), "push") == 0) this->Command = eCommand::PUSH;
	else if (strcmp(static_cast<const char *>(command.c_str()), "pop") == 0) this->Command = eCommand::POP;
	else if (strcmp(static_cast<const char *>(command.c_str()), "dump") == 0) this->Command = eCommand::DUMP;
	else if (strcmp(static_cast<const char *>(command.c_str()), "assert") == 0) this->Command = eCommand::ASSERT;
	else if (strcmp(static_cast<const char *>(command.c_str()), "sub") == 0) this->Command = eCommand::SUB;
	else if (strcmp(static_cast<const char *>(command.c_str()), "mul") == 0) this->Command = eCommand::MUL;
	else if (strcmp(static_cast<const char *>(command.c_str()), "div") == 0) this->Command = eCommand::DIV;
	else if (strcmp(static_cast<const char *>(command.c_str()), "mod") == 0) this->Command = eCommand::MOD;
	else if (strcmp(static_cast<const char *>(command.c_str()), "print") == 0) this->Command = eCommand::PRINT;
	else if (strcmp(static_cast<const char *>(command.c_str()), "exit") == 0) this->Command = eCommand::EXIT;
	else if (strcmp(static_cast<const char *>(command.c_str()), ";;") == 0) this->Command = eCommand::RUN;
	else  this->Command = eCommand::UNKNOWN;
	if (this->Command == eCommand::UNKNOWN)
		throw Exceptions::UnknownCommand();
	tokens.erase(tokens.begin());
	switch (this->Command)
	{
		case eCommand::PUSH:
		case eCommand::ASSERT:
			if (tokens.size()  == 0)
				throw Exceptions::NoTokens();
			work = tokens[0];
			op = work.find_first_of('(');
			cl = work.find_first_of(')');
			if (work.find(')', op) == std::string::npos)
				throw Exceptions::NoTokens();
			stype = work.substr(0, op);
			data = work.substr(op + 1, cl - op - 1);
			if (strcmp(static_cast<const char *>(stype.c_str()), "int8") == 0) oper = eOperandType::INT8;
			else if (strcmp(static_cast<const char *>(stype.c_str()), "int16") == 0) oper = eOperandType::INT16;
			else if (strcmp(static_cast<const char *>(stype.c_str()), "int32") == 0) oper = eOperandType::INT32;
			else if (strcmp(static_cast<const char *>(stype.c_str()), "float") == 0) oper = eOperandType::FLOAT;
			else if (strcmp(static_cast<const char *>(stype.c_str()), "double") == 0) oper = eOperandType::DOUBLE;
			else throw Exceptions::UnknownDataType();
			this->val = f.getOperator(oper, data);
			break;
		default:
			break;
	}
};
Lexer::Lexer(const Lexer& rhs) { this->val = rhs.getValue(); this->line = rhs.line; this->Command = rhs.Command; }
Lexer	&Lexer::operator=(const Lexer& rhs) { this->val = rhs.val; this->line = rhs.line; this->Command = rhs.Command; return *this;}
Lexer::~Lexer(void){ if (this->val && this->Command != eCommand::NONE) delete val; };
eCommand Lexer::getCommand(void) const { return this->Command; }
IOperand const	*Lexer::getValue(void) const { if (!this->val) return nullptr; Factory f; return f.getOperator(this->val->getType(), this->val->toString()); }
size_t	Lexer::getLine(void) const { return this->line; }