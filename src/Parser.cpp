/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:27:31 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/25 14:27:31 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>

operation_t Parser::Operations[] = {
	&Parser::None,
	&Parser::Push,
	&Parser::Pop,
	&Parser::Dump,
	&Parser::Assert,
	&Parser::Add,
	&Parser::Sub,
	&Parser::Mul,
	&Parser::Div,
	&Parser::Mod,
	&Parser::Print,
	&Parser::Exit,
	&Parser::Execute
};

Parser::Parser(void): stream(std::cin) {}
Parser::Parser(std::istream &stream): stream(stream){}
Parser &Parser::operator=(const Parser& rhs){if (this != &rhs) *this = rhs; return *this; }
Parser::~Parser(void)
{
	for (auto a : stack)
		delete a;
}

void	Parser::Push(Lexer &l) { stack.push_back(l.getValue()); }
void	Parser::Pop(Lexer &l)
{
	static_cast<void>(l);
	if (stack.size() < 1)
		throw std::exception("Empty Stack :(");
	delete stack.back();
	stack.pop_back();
}
void	Parser::Print(Lexer &l)
{
	static_cast<void>(l);
	if (stack.size() < 1)
		throw std::exception("Empty Stack :(");
	std::cout << stack.back()->toString() << std::endl;
}
void	Parser::Dump(Lexer &l)
{
	static_cast<void>(l);
	for (auto a: stack)
		std::cout << a->toString() << std::endl;
}
void	Parser::Add(Lexer &l)
{
	static_cast<void>(l);
	IOperand const *v1;
	IOperand const *v2;
	if (stack.size() < 2)
		throw std::exception("Stack is too small:(");
	v1 = stack.back();
	stack.pop_back();
	v2 = stack.back();
	stack.pop_back();
	stack.push_back(*v1 + *v2);
	delete v1;
	delete v2;
}
void	Parser::Sub(Lexer &l)
{
	static_cast<void>(l);
	IOperand const *v1;
	IOperand const *v2;
	if (stack.size() < 2)
		throw std::exception("Stack is too small:(");
	v1 = stack.back();
	stack.pop_back();
	v2 = stack.back();
	stack.pop_back();
	stack.push_back(*v1 - *v2);
	delete v1;
	delete v2;
}
void	Parser::Mul(Lexer &l)
{
	static_cast<void>(l);
	IOperand const *v1;
	IOperand const *v2;
	if (stack.size() < 2)
		throw std::exception("Stack is too small:(");
	v1 = stack.back();
	stack.pop_back();
	v2 = stack.back();
	stack.pop_back();
	stack.push_back(*v1 * *v2);
	delete v1;
	delete v2;
}
void	Parser::Div(Lexer &l)
{
	static_cast<void>(l);
	IOperand const *v1;
	IOperand const *v2;
	if (stack.size() < 2)
		throw std::exception("Stack is too small:(");
	v1 = stack.back();
	stack.pop_back();
	v2 = stack.back();
	stack.pop_back();
	stack.push_back(*v1 / *v2);
	delete v1;
	delete v2;
}
void	Parser::Mod(Lexer &l)
{
	static_cast<void>(l);
	IOperand const *v1;
	IOperand const *v2;
	if (stack.size() < 2)
		throw std::exception("Stack is too small:(");
	v1 = stack.back();
	stack.pop_back();
	v2 = stack.back();
	stack.pop_back();
	stack.push_back(*v1 % *v2);
	delete v1;
	delete v2;
}
void	Parser::Assert(Lexer &l)
{
	if (stack.size() < 1)
		throw std::exception("Stack is too small :(");
	IOperand const *v = l.getValue();
	auto v1 = std::stod(v->toString());
	auto v2 = std::stod(stack.back);
	bool ass = v1 == v2;
	delete v;
	if (!ass)
		throw std::exception("Assert failed :(");
}
void	Parser::Execute(Lexer &l)
{
	static_cast<void>(l);
}
void	Parser::None(Lexer &l)
{
	static_cast<void>(l);
}
void	Parser::Execute(Lexer &l)
{
	size_t line = 0;
	try
	{
		for (auto a: instructions)
		{
			line = a.getLine();
			operation_t fun = Operations[static_cast<size_t>(a.getCommand())];
			((*this).*(fun))(a);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "line" << line << ":: " << e.what() << '\n';
	}
	instructions.clear();
}
void Parser::Run()
{
	size_t line = 1;
	error = false;
	while (!stream.eof())
	{
		try
		{
			std::string read;
			std::cout << read;
			getline(stream, read);
			Lexer l(read, line);
			instructions.push_back(l);
			if (instructions.back().getCommand() == eCommand::EXIT)
			{
				if (!error)
					Execute();
				return;
			}
			if (instructions.back().getCommand() == eCommand::RUN)
				Execute();
		}
		catch(const std::exception& e)
		{
			error = true;
			std::cerr << "line " << line << ": " << e.what() << "\n";
			instructions.clear();
		}
		line++;
	}
	std::cerr << "line " << line << ": " << "No exit command" << "\n";
}