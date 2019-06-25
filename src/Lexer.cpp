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
#include <iostream>
#include <istream>

Lexer::Lexer(void){}
Lexer::Lexer(std::string const& s, size_t line):
	Command(eCommand::NONE), index(1), line(line), val(nullptr)
{

};
Lexer::Lexer(const Lexer& rhs) { *this = rhs; }
Lexer	&Lexer::operator=(const Lexer& rhs) { if (this != &rhs) *this = rhs; return *this;}
Lexer::~Lexer(void){};