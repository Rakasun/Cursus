/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:41:49 by yfang             #+#    #+#             */
/*   Updated: 2024/12/02 19:13:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main() {
    try {
        // Create a Bureaucrat with a valid grade
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        // Create a Form with valid grades for signing and execution
        Form contract("Contract", 45, 30);
        std::cout << contract << std::endl;

        // Attempt to have Bob sign the form (his grade is too low)
        bob.signForm(contract);

        // Increment Bob's grade so he can sign the form
        bob.incrementGrade();
        std::cout << bob << " after incrementing grade." << std::endl;

        // Attempt to sign the form again
        bob.signForm(contract);

        // Check the form's status
        std::cout << contract << std::endl;

        // Test boundary: create a Bureaucrat with an out-of-range grade
        Bureaucrat alice("Alice", 151); // This should throw an exception
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        // Test boundary: create a Form with an invalid grade
        Form invalidForm("InvalidForm", 0, 30); // This should throw an exception
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        // Create a Bureaucrat with the lowest possible grade
        Bureaucrat tom("Tom", 150);
        std::cout << tom << std::endl;

        // Attempt to decrement Tom's grade (should throw an exception)
        tom.decrementGrade();
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        // Create a Bureaucrat with the highest possible grade
        Bureaucrat jane("Jane", 1);
        std::cout << jane << std::endl;

        // Attempt to increment Jane's grade (should throw an exception)
        jane.incrementGrade();
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
