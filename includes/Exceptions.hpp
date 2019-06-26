/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 07:50:42 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/26 08:08:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

class OutOfRange : public std::exception
{
	public:
		OutOfRange(void);
		OutOfRange(std::string);
		OutOfRange(const OutOfRange &src);
		virtual ~OutOfRange(void) throw();
		OutOfRange  &operator= (const OutOfRange &cpy);
		virtual const char    *what() const throw();
	private:
		std::string reason;
};

class ModByZero : public std::exception
{
	public:
		ModByZero(void);
		ModByZero(const ModByZero &src);
		virtual ~ModByZero(void) throw();
		ModByZero  &operator= (const ModByZero &cpy);
		virtual const char    *what() const throw();
};

class DivByZero : public std::exception
{
	public:
		DivByZero(void);
		DivByZero(const DivByZero &src);
		virtual ~DivByZero(void) throw();
		DivByZero  &operator= (const DivByZero &cpy);
		virtual const char    *what() const throw();
};

class StackToSmall : public std::exception
{
	public:
		StackToSmall(void);
		StackToSmall(const StackToSmall &src);
		virtual ~StackToSmall(void) throw();
		StackToSmall  &operator= (const StackToSmall &cpy);
		virtual const char    *what() const throw();
};

class AssertFailed : public std::exception
{
	public:
		AssertFailed(void);
		AssertFailed(const AssertFailed &src);
		virtual ~AssertFailed(void) throw();
		AssertFailed  &operator= (const AssertFailed &cpy);
		virtual const char    *what() const throw();
};

class EmptyStack : public std::exception
{
	public:
		EmptyStack(void);
		EmptyStack(const EmptyStack &src);
		virtual ~EmptyStack(void) throw();
		EmptyStack  &operator= (const EmptyStack &cpy);
		virtual const char    *what() const throw();
};