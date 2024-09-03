/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:35:42 by yfang             #+#    #+#             */
/*   Updated: 2024/09/03 16:33:23 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av) {
    if (ac == 4) {
        std::string     file = av[1];
        std::string     s1 = av[2];
        std::string     s2 = av[3];
        std::ifstream   infile(file.c_str());
        std::string     newfile = file + ".replace";
        std::ofstream   outfile(newfile.c_str());
        std::string     line;
        size_t          ptr;

        if (s1.empty()) {
            std::cout << "Error: the second argument cant be empty.";
            return 1;
        }
        if (!infile.is_open() || !outfile.is_open()) {
            std::cout << "Error: fatal\n";
            return 1;
        }
        while (getline(infile, line)) {
            ptr = 0;
            while ((ptr = line.find(s1, ptr)) != std::string::npos) {
                line.erase(ptr, s1.length());
                line.insert(ptr, s2);
                ptr += s2.length();
            }
            outfile << line << std::endl;
        }
        infile.close();
        outfile.close();
    }
    else {
        std::cout << "Bad arguments num." << std::endl;
        return 1;
    }
    return 0;
}
