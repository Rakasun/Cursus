/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:44:45 by yfang             #+#    #+#             */
/*   Updated: 2024/12/02 18:49:15 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(void) : _name("Default"), _status(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const AForm &other) : _name(other._name), _status(other._status), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::AForm(const std::string &name, int gradeToSing, int gradeToExecute) : _name(name), _status(false), _gradeToSign(gradeToSing), _gradeToExecute(gradeToExecute) {
    if (gradeToSing < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSing > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm    &AForm::operator=(const AForm &other) {
    if (this != &other)
        _status = other._status;
    return *this;
}

AForm::~AForm(void) {}

std::string AForm::getName(void) const {
    return _name;
}

bool    AForm::getStatus(void) const {
    return _status;
}

int AForm::getSignGrade(void) const {
    return _gradeToSign;
}

int AForm::getExecGrade(void) const {
    return _gradeToExecute;
}

bool    AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _status = true;
    return _status;
}

void AForm::verifyExecution(const Bureaucrat &executor) const {
    if (!_status)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

const char  *AForm::GradeTooHighException::what() const throw() {
    return "AForm is too high!";
}

const char  *AForm::GradeTooLowException::what() const throw() {
    return "AForm is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << "AForm " << f.getName() << ": "
        << "status=" << (f.getStatus() ? "signed" : "not signed")
        << ", grade to sign=" << f.getSignGrade()
        << ", grade to execute=" << f.getExecGrade();
    return out;
}
