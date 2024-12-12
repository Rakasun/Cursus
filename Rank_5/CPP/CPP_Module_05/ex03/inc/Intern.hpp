/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:21:42 by yfang             #+#    #+#             */
/*   Updated: 2024/12/11 16:31:43 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern {
    public:
        Intern(void);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern(void);

        AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
