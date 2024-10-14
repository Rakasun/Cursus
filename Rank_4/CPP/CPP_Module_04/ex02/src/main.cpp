/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:26:50 by yfang             #+#    #+#             */
/*   Updated: 2024/10/07 11:37:40 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"

int main(void) {
	 std::cout << "==== Test 1: Creating and deleting individual Dog and Cat objects ====" << std::endl;
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << "Deleting the Dog and Cat objects..." << std::endl;
    delete dog;  // Proper destructor calls for Dog
    delete cat;  // Proper destructor calls for Cat

    std::cout << std::endl;

    std::cout << "==== Test 2: Creating an array of Animal* with Dogs and Cats ====" << std::endl;
    const int numAnimals = 4;
    AAnimal* animals[numAnimals];

    // First half of the array will be Dogs
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    // Second half of the array will be Cats
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    std::cout << "Deleting the array of animals..." << std::endl;
    // Delete all animals in the array
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    std::cout << std::endl;

    std::cout << "==== Test 3: Deep copy for Dog ====" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->makeSound();

    // Creating a deep copy
    Dog* copiedDog = new Dog(*originalDog);
    copiedDog->makeSound();

    delete originalDog;
    delete copiedDog;

    std::cout << std::endl;

    std::cout << "==== Test 4: Deep copy for Cat ====" << std::endl;
    Cat* originalCat = new Cat();
    originalCat->makeSound();

    // Creating a deep copy
    Cat* copiedCat = new Cat(*originalCat);
    copiedCat->makeSound();

    delete originalCat;
    delete copiedCat;

    std::cout << std::endl;

    std::cout << "==== Test 5: Verifying abstract class (AAnimal) cannot be instantiated ====" << std::endl;
    // The following line will not compile because AAnimal is abstract
    // AAnimal* invalidAnimal = new AAnimal();  // Uncommenting this will cause a compilation error

    std::cout << "==== Test complete ====" << std::endl;

    return 0;
}
