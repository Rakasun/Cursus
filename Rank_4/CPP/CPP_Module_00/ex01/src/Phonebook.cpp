/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:23:33 by yfang             #+#    #+#             */
/*   Updated: 2024/08/08 17:14:31 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

Phonebook::Phonebook() : index(0), flag(0){}
Phonebook::~Phonebook() {}

bool	Phonebook::show_contact(int index) {
	std::string	input;
	std::string	datatext[5];
	char		*end;

	if (!index) {
		std::cout << RED "Error: No contacts registred." RESET << std::endl;
		return (true);
	}
	datatext[0] = "First Name: ";
    datatext[1] = "Last Name: ";
    datatext[2] = "Nickname: ";
    datatext[3] = "Phone Number: ";
    datatext[4] = "Darkest secret: ";
	for (int i = 0; i < 1; i++) {
		std::cout << BOLD GREEN "Please choose a index (1 to " << index << "): " RESET;
		if (!std::getline(std::cin, input, '\n'))
			return (false);
		if (input.empty() || strtol(input.c_str(), &end, 10) < 1 || strtol(input.c_str(), &end, 10) > index) {
			std::cout << RED "Error: Field cannnot be empty or Index doesn't exist." RESET << std::endl;
			i--;
		}
		else {
			for (int j = 0; j < 5; j++) {
				std::cout << std::setw(16) << datatext[j] << std::right
				<< contacts[strtol(input.c_str(), &end, 10) - 1].getData(j) << std::endl;
			}
			std::cout << std::endl;
		}
	}
	return (true);
}

int    Phonebook::search_contact(void) {

	int index = 0;
	
	if (flag == 0)
		while (index < this->index)
			index++;
	else
		index = 8;
	if (!index)
		return (index);
	std::cout << YELLOW << "|"
	<< std::setw(10) << std::right << "Index" << "|"
	<< std::setw(10) << std::right << "First Name" << "|"
	<< std::setw(10) << std::right << "Last Name" << "|"
	<< std::setw(10) << std::right << "Nickname" << "|"
	<< RESET << std::endl;
	for (int i = 0; i < index; i++) {
		std::cout << YELLOW << "---------------------------------------------" << std::endl;
		std::cout << "|" << std::setw(10) << i + 1 << std::right << "|";
		for (int j = 0; j < 3; j++) {
			if (contacts[i].getData(j).length() < 10) 
				std::cout << std::setw(10) << contacts[i].getData(j) << std::right << "|";
			else {
				std::cout << std::setw(9) << contacts[i].getData(j).substr(0, 9)
				<< ".|";
			}
		}
		std::cout << RESET << std::endl;
	}
	std::cout << std::endl;
	return (index);
}

bool    Phonebook::new_contact(void) {
	Contact contacts;

	if (!contacts.set_data())
		return (false);
	if (index == 8) {
		index = 0;
		flag = 1;
	}
	this->contacts[index] = contacts;
	index++;
	return (true);
}
