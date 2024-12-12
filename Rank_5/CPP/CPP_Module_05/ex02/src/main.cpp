/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:41:49 by yfang             #+#    #+#             */
/*   Updated: 2024/12/11 16:17:55 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("R2D2");
        PresidentialPardonForm pardon("Ford Prefect");

        bob.signForm(shrub);
        bob.executeForm(shrub);

        alice.signForm(robot);
        alice.executeForm(robot);

        alice.signForm(pardon);
        alice.executeForm(pardon);

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
