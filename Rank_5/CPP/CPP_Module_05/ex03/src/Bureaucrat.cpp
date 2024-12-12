/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:12:49 by yfang             #+#    #+#             */
/*   Updated: 2024/12/11 16:05:12 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

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

void    Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn't sing " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << GREEN << _name << " executed " << form.getName() << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << _name << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
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
