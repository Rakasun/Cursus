/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:22:31 by yfang             #+#    #+#             */
/*   Updated: 2024/12/11 16:35:40 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

Intern::Intern(void) {
    std::cout << "Intern created!" << std::endl;
}

Intern::Intern(const Intern &other) {
    *this = other;
    std::cout << "Intern copied!" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        std::cout << "Intern assigned!" << std::endl;
    }
    return *this;
}

Intern::~Intern(void) {
    std::cout << "Intern destroyed!" << std::endl;
}

AForm *createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    struct FormEntry {
        const char *name;
        AForm *(*creator)(const std::string &);
    };

    static const FormEntry forms[] = {
        {"shrubbery creation", &createShrubberyForm},
        {"robotomy request", &createRobotomyForm},
        {"presidential pardon", &createPresidentialForm}
    };

    const size_t numForms = sizeof(forms) / sizeof(forms[0]);

    for (size_t i = 0; i < numForms; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }

    std::cerr << "Error: Form name \"" << formName << "\" not recognized." << std::endl;
    return NULL;
}
