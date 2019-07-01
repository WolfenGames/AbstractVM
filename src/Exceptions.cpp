/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 07:53:37 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/26 10:30:02 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"
#include <iostream>

Exceptions::Exceptions(void){}
Exceptions::Exceptions(const Exceptions& cpy){*this = cpy;}
Exceptions::~Exceptions(void){}
Exceptions &Exceptions::operator=(const Exceptions& rhs){if (this != &rhs) *this = rhs; return *this;}

Exceptions::OutOfRange::OutOfRange(void){}
Exceptions::OutOfRange::OutOfRange(std::string val){this->reason = val;}
Exceptions::OutOfRange::OutOfRange(const OutOfRange& rhs){*this = rhs;}
Exceptions::OutOfRange &Exceptions::OutOfRange::operator=(const OutOfRange& rhs){if (this != &rhs) *this = rhs; return *this;}
Exceptions::OutOfRange::~OutOfRange(void) throw(){}
const char	*Exceptions::OutOfRange::what() const throw() { return this->reason.c_str(); }

Exceptions::ModByZero::ModByZero(void){}
Exceptions::ModByZero::ModByZero(const ModByZero& rhs){*this = rhs;}
Exceptions::ModByZero::~ModByZero(void) throw(){}
Exceptions::ModByZero &Exceptions::ModByZero::operator=(const ModByZero& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::ModByZero::what() const throw() { return "Try To mod by 0 :("; }

Exceptions::DivByZero::DivByZero(void){}
Exceptions::DivByZero::DivByZero(const DivByZero& rhs){*this = rhs;}
Exceptions::DivByZero::~DivByZero(void) throw(){}
Exceptions::DivByZero &Exceptions::DivByZero::operator=(const DivByZero& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::DivByZero::what() const throw() { return "Try To divide by 0 :("; }

Exceptions::StackToSmall::StackToSmall(void){}
Exceptions::StackToSmall::StackToSmall(const StackToSmall& rhs){*this = rhs;}
Exceptions::StackToSmall::~StackToSmall(void) throw(){}
Exceptions::StackToSmall &Exceptions::StackToSmall::operator=(const StackToSmall& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::StackToSmall::what() const throw() { return "Stack is tiny :("; }

Exceptions::AssertFailed::AssertFailed(void){}
Exceptions::AssertFailed::AssertFailed(const AssertFailed& rhs){*this = rhs;}
Exceptions::AssertFailed::~AssertFailed(void) throw(){}
Exceptions::AssertFailed &Exceptions::AssertFailed::operator=(const AssertFailed& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::AssertFailed::what() const throw() { return "Assertion failed :("; }

Exceptions::EmptyStack::EmptyStack(void){}
Exceptions::EmptyStack::EmptyStack(const EmptyStack& rhs){*this = rhs;}
Exceptions::EmptyStack::~EmptyStack(void) throw(){}
Exceptions::EmptyStack &Exceptions::EmptyStack::operator=(const EmptyStack& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::EmptyStack::what() const throw() { return "Stack is missing :("; }

Exceptions::UnknownCommand::UnknownCommand(void){}
Exceptions::UnknownCommand::UnknownCommand(const UnknownCommand& rhs){*this = rhs;}
Exceptions::UnknownCommand::~UnknownCommand(void) throw(){}
Exceptions::UnknownCommand &Exceptions::UnknownCommand::operator=(const UnknownCommand& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::UnknownCommand::what() const throw() { return "Unknown command :("; }

Exceptions::UnknownDataType::UnknownDataType(void){}
Exceptions::UnknownDataType::UnknownDataType(const UnknownDataType& rhs){*this = rhs;}
Exceptions::UnknownDataType::~UnknownDataType(void) throw(){}
Exceptions::UnknownDataType &Exceptions::UnknownDataType::operator=(const UnknownDataType& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::UnknownDataType::what() const throw() { return "Unknown Data Type :("; }

Exceptions::NoTokens::NoTokens(void){}
Exceptions::NoTokens::NoTokens(const NoTokens& rhs){*this = rhs;}
Exceptions::NoTokens::~NoTokens(void) throw(){}
Exceptions::NoTokens &Exceptions::NoTokens::operator=(const NoTokens& rhs){if (this != &rhs) *this = rhs; return *this;}
const char	*Exceptions::NoTokens::what() const throw() { return "Lexer has no tokens :("; }
