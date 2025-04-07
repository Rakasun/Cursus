/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:38:23 by yfang             #+#    #+#             */
/*   Updated: 2025/04/07 17:39:20 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    this->_stack = other._stack;
    return *this;
}

RPN::~RPN(void) {}

bool    RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void    RPN::applyOperator(char op) {
    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enoug operands");

    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();
    int result = 0;

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            result = a / b;
            break;
        
    }
    _stack.push(result);
}

int RPN::evaluate(const std::string &expresion) {
    std::istringstream  iss(expresion);
    std::string         token;

    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0]))
            applyOperator(token[0]);
        else if (token.length() == 1 && isdigit(token[0]))
            _stack.push(token[0] - '0');
        else
            throw std::runtime_error("Error: invalid token => " + token);
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expresion");
    return _stack.top();
}
