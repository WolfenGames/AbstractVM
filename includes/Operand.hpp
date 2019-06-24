/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:40:13 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/24 16:06:01 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define constructexception(x, val)	x < val ? "Underflow value ":"Overflow value"

#include "IOperand.hpp"
#include "Factory.hpp"
#include <iostream>
#include <sstream>

template<typename T>
inline	eOperandType getValueType() { return eOperandType::UNDEFINED; }

template<>
inline eOperandType getValueType<int8_t>() { return eOperandType::INT8; }

template<>
inline eOperandType getValueType<int16_t>() { return eOperandType::INT16; }

template<>
inline eOperandType getValueType<int32_t>() { return eOperandType::INT32; }

template<>
inline eOperandType getValueType<float>() { return eOperandType::FLOAT; }

template<>
inline eOperandType getValueType<double>() { return eOperandType::DOUBLE; }

template<typename T>
class Operand: public IOperand
{
	public:
		~Operand(void);
		Operand(const Operand&){};
		Operand(std::string value)
		{
			eOperandType t = getValueType<T>();
			if (t==eOperandType::INT8 || t==eOperandType::INT16 || t==eOperandType::INT32)
			{
				int32_t	x = std::stoi(value);
				this->val = static_cast<T>(x);
				// if (static_cast<int32_t>(this->val) != x)
				// 	throw std::exception("");
			}
			else if (t == eOperandType::FLOAT)
				this->val = std::stof(value);
			else if (t == eOperandType::DOUBLE)
				this->val = std::stod(value);
		};

		int	getPrecision(void) const { return static_cast<int>(getType()); };
		eOperandType	getType(void) const { return getValueType<T>(); };

		IOperand const	*operator+(IOperand const &rhs) const
		{
			std::string	str;

			eOperandType t = rhs.getType() > this->getType() ?
				rhs.getType() : this->getType();
			if (t==eOperandType::INT8 || t==eOperandType::INT16 || t==eOperandType::INT32)
				str = std::to_string(this->val + std::stoi(rhs.toString()));
			else if (t == eOperandType::FLOAT)
				str = std::to_string(this->val + std::stof(rhs.toString()));
			else if (t == eOperandType::DOUBLE)
				str = std::to_string(this->val + std::stod(rhs.toString()));
			return f.getOperator(t, str);	
		};

		IOperand const	*operator-(IOperand const &rhs) const
		{
			std::string	str;

			eOperandType t = rhs.getType() > this->getType() ?
				rhs.getType() : this->getType();
			if (t==eOperandType::INT8 || t==eOperandType::INT16 || t==eOperandType::INT32)
				str = std::to_string(this->val - std::stoi(rhs.toString()));
			else if (t == eOperandType::FLOAT)
				str = std::to_string(this->val - std::stof(rhs.toString()));
			else if (t == eOperandType::DOUBLE)
				str = std::to_string(this->val - std::stod(rhs.toString()));
			return f.getOperator(t, str);	
		};

		IOperand const	*operator*(IOperand const &rhs) const
		{
			std::string	str;

			eOperandType t = rhs.getType() > this->getType() ?
				rhs.getType() : this->getType();
			if (t==eOperandType::INT8 || t==eOperandType::INT16 || t==eOperandType::INT32)
				str = std::to_string(this->val * std::stoi(rhs.toString()));
			else if (t == eOperandType::FLOAT)
				str = std::to_string(this->val * std::stof(rhs.toString()));
			else if (t == eOperandType::DOUBLE)
				str = std::to_string(this->val * std::stod(rhs.toString()));
			return f.getOperator(t, str);	
		};

		IOperand const	*operator/(IOperand const &rhs) const
		{
			std::string	str;

			eOperandType t = rhs.getType() > this->getType() ?
				rhs.getType() : this->getType();
			if (t==eOperandType::INT8 || t==eOperandType::INT16 || t==eOperandType::INT32)
			{
				if (std::stoi(rhs.toString()) == 0) throw;
				str = std::to_string(this->val / std::stoi(rhs.toString()));
			}
			else if (t == eOperandType::FLOAT)
			{
				if (std::stof(rhs.toString()) == 0) throw;
				str = std::to_string(this->val / std::stof(rhs.toString()));
			}
			else if (t == eOperandType::DOUBLE)
			{
				if (std::stod(rhs.toString()) == 0) throw;
				str = std::to_string(this->val / std::stod(rhs.toString()));
			}
			return f.getOperator(t, str);
		};

		IOperand const	*operator%(IOperand const &rhs) const
		{
			std::string	str;

			eOperandType t = rhs.getType() > this->getType() ?
				rhs.getType() : this->getType();
			if (t==eOperandType::INT8 || t==eOperandType::INT16 || t==eOperandType::INT32)
			{
				if (std::stoi(rhs.toString()) == 0) throw;
				str = std::to_string(this->val % std::stoi(rhs.toString()));
			}
			else if (t == eOperandType::FLOAT)
			{
				if (std::stof(rhs.toString()) == 0) throw;
				str = std::to_string(this->val % std::stof(rhs.toString()));
			}
			else if (t == eOperandType::DOUBLE)
			{
				if (std::stod(rhs.toString()) == 0) throw;
				str = std::to_string(this->val % std::stod(rhs.toString()));
			}
			return f.getOperator(t, str);
		};

		std::string	const	&toString(void) const
		{
			std::stringstream ss;
			if (getType() == eOperandType::INT8)
				ss << static_cast<int>(this->val);
			else
				ss << this->val;
			
			// ss << ((getType() == eOperandType::INT8) ? static_cast<int>(this->val) : this->val);
			return ss.str();
		};
		
	private:
		Operand();
		Factory			f;
		T				val;
};
