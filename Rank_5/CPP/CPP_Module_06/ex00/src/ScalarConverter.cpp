/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:25:52 by yfang             #+#    #+#             */
/*   Updated: 2025/03/04 18:07:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(void) {}

static int scapeChar(std::string str) {
    if (str == "\0")
        return (0);
    if (str == "\a")
        return (7);
    if (str == "\b")
        return (8);
    if (str == "\t")
        return (9);
    if (str == "\n")
        return (10);
    if (str == "\v")
        return (11);
    if (str == "\f")
        return (12);
    if (str == "\r")
        return (13);
    return (str[0]);
}

static void getChar(std::string str) {
    char c;

    if (str.length() == 1)
        c = str[0];
    else
        c = scapeChar(str);
    std::cout << "char: ";
    if (c < CHAR_MIN || c > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
    << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
    << static_cast<double>(c) << std::endl;
}

static void getInt(std::string str) {
    long int i;

    i = atol(str.c_str());
    std::cout << "char: ";
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: ";
    if (i < INT_MIN || i > INT_MAX)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << i << std::endl;
    std::cout << "float: ";
    if (i < INT_MIN)
        std::cout << (INT_MIN) << "0.f" << std::endl;
    else if (i > INT_MAX)
        std::cout << (INT_MAX) << "0.f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
        << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: ";
    if (i < INT_MIN)
        std::cout << (INT_MIN) << ".0" << std::endl;
    else if (i > INT_MAX)
        std::cout << (INT_MAX) << ".0" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
        << static_cast<double>(i) << std::endl;
}

static void getFloat(std::string str) {
    double i;

    i = atof(str.c_str());
    std::cout << "char: ";
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: ";
    if (i < INT_MIN || i > INT_MAX)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << static_cast<int>(i) << std::endl;
    std::cout << "float: ";
    if (isinf(static_cast<float>(i)) && i > 0)
        std::cout << "+inff" << std::endl;
    else if (isinf(static_cast<float>(i)) && i < 0)
        std::cout << "-inff" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
        << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: ";
    if (isinf(i) && i > 0)
        std::cout << "+inf" << std::endl;
    else if (isinf(i) && i < 0)
        std::cout << "-inf" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
        << i << std::endl;
}

static void getDouble(std::string str) {
    double i;

    i = atof(str.c_str());
    std::cout << "char: ";
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: ";
    if (i < INT_MIN || i > INT_MAX)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << static_cast<int>(i) << std::endl;
    std::cout << "float: ";
    if (isinf(static_cast<float>(i)) && i > 0)
        std::cout << "+inff" << std::endl;
    else if (isinf(static_cast<float>(i)) && i < 0)
        std::cout << "-inff" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
        << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: ";
    if (isinf(i) && i > 0)
        std::cout << "+inf" << std::endl;
    else if (isinf(i) && i < 0)
        std::cout << "-inf" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
        << i << std::endl;
}

static void getPseudo(std::string str) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "+inff" || str == "+inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (str == "+inff" || str == "+inf") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

static int  getType(const std::string &str) {
    if (str == "nan" || str == "nanf" ||
        str == "+inf" || str == "+inff" ||
        str == "-inf" || str == "-inff") {
        return PSEUDO;
    }
    
    if ((str.length() == 1 && !isdigit(str[0])) ||
        (str.length() == 2 && (str == "\0" || str == "\a" ||
        str == "\b" || str == "\t" || str == "\n" ||
        str == "\v" || str == "\f" || str == "\r"))) {
        return CHAR;
    }

    bool hasDot = false;
    bool hasFlo = false;
    bool hasSig = false;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (hasDot)
                return INVALID;
            hasDot = true;
        } else if (str[i] == 'f' || str[i] == 'F') {
            if (hasFlo || i != str.length() - 1)
                return INVALID;
            hasFlo = true;
        } else if (str[i] == '+' || str[i] == '-') {
            if (hasSig || i != 0)
                return INVALID;
            hasSig = true;
        } else if (!isdigit(str[i]))
            return INVALID;
    }

    if (hasDot && hasFlo)
        return FLOAT;
    if (hasDot)
        return DOUBLE;
    if (!hasDot && !hasFlo)
        return INT;

    return INVALID;
}

void ScalarConverter::convert(std::string str) {
    switch(getType(str)) {
        case CHAR:
            getChar(str);
            break ;
        case INT:
            getInt(str);
            break ;
        case FLOAT:
            getFloat(str);
            break ;
        case DOUBLE:
            getDouble(str);
            break ;
        case PSEUDO:
            getPseudo(str);
            break ;
        default:
            std::cerr << "ERROR: Type not found." << std::endl;

    }
}
