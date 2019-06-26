/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 07:53:37 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/26 08:33:49 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"
#include <iostream>

OutOfRange::OutOfRange(void){}
OutOfRange::OutOfRange(std::string val){this->reason = val;}
OutOfRange::OutOfRange(const OutOfRange& rhs){*this = rhs;}
OutOfRange &OutOfRange::operator=(const OutOfRange& rhs){if (this != &rhs) *this = rhs; return *this;}
OutOfRange::~OutOfRange(void) throw(){}
const char	*OutOfRange::what() const throw() { return this->reason.c_str(); }

ModByZero::ModByZero(void){}
ModByZero::ModByZero(const ModByZero& rhs){*this = rhs;}
ModByZero::~ModByZero(void) throw(){}
ModByZero &ModByZero::operator=(const ModByZero& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*ModByZero::what() const throw()
{
	return "Try To mod by 0 :(";
}

DivByZero::DivByZero(void){}
DivByZero::DivByZero(const DivByZero& rhs){*this = rhs;}
DivByZero::~DivByZero(void) throw(){}
DivByZero &DivByZero::operator=(const DivByZero& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*DivByZero::what() const throw()
{
	return "Try To divide by 0 :(";
}

StackToSmall::StackToSmall(void){}
StackToSmall::StackToSmall(const StackToSmall& rhs){*this = rhs;}
StackToSmall::~StackToSmall(void) throw(){}
StackToSmall &StackToSmall::operator=(const StackToSmall& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*StackToSmall::what() const throw()
{
	return "Stack is tiny :(";
}

AssertFailed::AssertFailed(void){}
AssertFailed::AssertFailed(const AssertFailed& rhs){*this = rhs;}
AssertFailed::~AssertFailed(void) throw(){}
AssertFailed &AssertFailed::operator=(const AssertFailed& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*AssertFailed::what() const throw()
{
	return "Assertion failed :(";
}

EmptyStack::EmptyStack(void){}
EmptyStack::EmptyStack(const EmptyStack& rhs){*this = rhs;}
EmptyStack::~EmptyStack(void) throw(){}
EmptyStack &EmptyStack::operator=(const EmptyStack& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*EmptyStack::what() const throw()
{
	return "Stack is missing :(";
}