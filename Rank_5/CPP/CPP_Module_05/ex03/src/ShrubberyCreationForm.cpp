/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:58:55 by yfang             #+#    #+#             */
/*   Updated: 2024/12/11 15:59:10 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    verifyExecution(executor);
    std::string file_name = _target + "_shrubbery";
    std::ofstream file(file_name.c_str());
    if (!file.is_open())
        throw std::ios_base::failure("Error opening file");
    file << "         _-_         \n"
         << "      /~~   ~~\\     \n"
         << "   /~~         ~~\\ \n"
         << "  {               }\n"
         << "   \\  _-     -_  /\n"
         << "     ~  \\\\ //  ~ \n"
         << " _- -   | | _- _  \n"
         << "   _ -  | |   -_  \n"
         << "       // \\\\      \n";
    file.close();
}
