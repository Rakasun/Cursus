/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:26:50 by yfang             #+#    #+#             */
/*   Updated: 2024/10/04 12:08:45 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"

int main(void) {
	// Create Dog and Cat objects as Animal pointers
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Deleting Dog (j) and Cat (i)" << std::endl;
    delete j; // Should not cause a memory leak
    delete i;

    std::cout << std::endl;

    // Create an array of Animal* with half Dogs and half Cats
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int k = 0; k < numAnimals / 2; ++k) {
        animals[k] = new Dog();
    }
    for (int k = numAnimals / 2; k < numAnimals; ++k) {
        animals[k] = new Cat();
    }

    std::cout << "\nDeleting the array of animals..." << std::endl;
    // Free memory of the Animal* array
    for (int k = 0; k < numAnimals; ++k) {
        delete animals[k];
    }

    std::cout << std::endl;

    // Check deep copy for Dog
    Dog* dog1 = new Dog();
    dog1->makeSound();

    // Create a deep copy
    Dog* dog2 = new Dog(*dog1);

    delete dog1;
    delete dog2;

    std::cout << std::endl;

    // Check deep copy for Cat
    Cat* cat1 = new Cat();
    cat1->makeSound();

    // Create a deep copy
    Cat* cat2 = new Cat(*cat1);

    delete cat1;
    delete cat2;

    return 0;
}
