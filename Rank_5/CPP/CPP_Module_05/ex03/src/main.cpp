/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:41:49 by yfang             #+#    #+#             */
/*   Updated: 2024/12/11 16:23:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    Bureaucrat john("John", 1);

    AForm *form1 = intern.makeForm("robotomy request", "Bender");
    AForm *form2 = intern.makeForm("shrubbery creation", "Garden");
    AForm *form3 = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm *form4 = intern.makeForm("invalid form", "Target");

    if (form1) {
        john.signForm(*form1);
        john.executeForm(*form1);
        delete form1;
    }

    if (form2) {
        john.signForm(*form2);
        john.executeForm(*form2);
        delete form2;
    }

    if (form3) {
        john.signForm(*form3);
        john.executeForm(*form3);
        delete form3;
    }

    if (form4) {
        delete form4;
    }

    return 0;
}
