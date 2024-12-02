/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:44:45 by yfang             #+#    #+#             */
/*   Updated: 2024/12/02 18:49:15 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(void) : _name("Default"), _status(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const Form &other) : _name(other._name), _status(other._status), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::Form(const std::string &name, int gradeToSing, int gradeToExecute) : _name(name), _status(false), _gradeToSign(gradeToSing), _gradeToExecute(gradeToExecute) {
    if (gradeToSing < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSing > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form    &Form::operator=(const Form &other) {
    if (this != &other)
        _status = other._status;
    return *this;
}

Form::~Form(void) {}

std::string Form::getName(void) const {
    return _name;
}

bool    Form::getStatus(void) const {
    return _status;
}

int Form::getSignGrade(void) const {
    return _gradeToSign;
}

int Form::getExecGrade(void) const {
    return _gradeToExecute;
}

bool    Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _status = true;
    return _status;
}

const char  *Form::GradeTooHighException::what() const throw() {
    return "Form is too high!";
}

const char  *Form::GradeTooLowException::what() const throw() {
    return "Form is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
    out << "Form " << f.getName() << ": "
        << "status=" << (f.getStatus() ? "signed" : "not signed")
        << ", grade to sign=" << f.getSignGrade()
        << ", grade to execute=" << f.getExecGrade();
    return out;
}
