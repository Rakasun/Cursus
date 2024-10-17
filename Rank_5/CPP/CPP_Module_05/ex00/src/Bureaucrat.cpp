/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:12:49 by yfang             #+#    #+#             */
/*   Updated: 2024/10/17 16:40:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _grade = other.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

const std::string   &Bureaucrat::getName(void) const {
    return _name;
}

int Bureaucrat::getGrade(void) const {
    return _grade;
}

void    Bureaucrat::incrementGrade(void) {
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade(void) {
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

const char  *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char  *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
