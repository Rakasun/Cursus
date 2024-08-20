/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:58:08 by yfang             #+#    #+#             */
/*   Updated: 2024/08/08 17:02:25 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

Contact::Contact() {
    data[0] = "First Name: ";
    data[1] = "Last Name: ";
    data[2] = "Nickname: ";
    data[3] = "Phone Number: ";
    data[4] = "Darkest secret: ";
}

Contact::~Contact() {}

bool	check_num(const std::string& str) {
	char *aux;

	strtol(str.c_str(), &aux, 10);
	if (*aux != '\0')
		return (false);
	return (true);
}

bool    Contact::set_data(void) {
    std::string input;

    for (int i = 0; i < 5; i++) {
        std::cout << BLUE << data[i] << RESET;
        if (!std::getline(std::cin, input, '\n'))
			return (false);
		else if (input.empty()) {
			std::cout << RED "Error: Field cannot be empty." RESET << std::endl;
            i--;
		}
        else {
			if (i == 3 && !check_num(input)) {
				std::cout << RED "Error: Input must be a numeric value." RESET << std::endl;
				i--;
			}
			else
            	data[i] = input;
		}
    }
	return (true);
}
