/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:41:49 by yfang             #+#    #+#             */
/*   Updated: 2024/10/17 17:02:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void) {
    // Case 1: Create a valid Bureaucrat with a name and grade
    try {
        Bureaucrat b1("John", 50);
        std::cout << "Bureaucrat created: " << b1 << std::endl; // Display the Bureaucrat using the << operator
        
        // Case 2: Increment and decrement the grade
        b1.incrementGrade();
        std::cout << "After incrementing grade: " << b1 << std::endl;

        b1.decrementGrade();
        std::cout << "After decrementing grade: " << b1 << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Case 3: Try to create a Bureaucrat with an invalid grade (too low)
    try {
        Bureaucrat b2("Alice", 0);
        std::cout << "Bureaucrat created: " << b2 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Case 4: Try to create a Bureaucrat with an invalid grade (too high)
    try {
        Bureaucrat b3("Bob", 151);
        std::cout << "Bureaucrat created: " << b3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Case 5: Test increments and decrements at the boundaries
    try {
        Bureaucrat b4("Charlie", 1);
        std::cout << "Bureaucrat created: " << b4 << std::endl;

        b4.incrementGrade();
        std::cout << "After incrementing grade: " << b4 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("David", 150);
        std::cout << "Bureaucrat created: " << b5 << std::endl;

        b5.decrementGrade();
        std::cout << "After decrementing grade: " << b5 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
