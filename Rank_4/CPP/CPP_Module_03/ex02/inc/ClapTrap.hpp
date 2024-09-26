/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:52:43 by yfang             #+#    #+#             */
/*   Updated: 2024/09/26 13:44:38 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

class ClapTrap {
    protected:
        std::string _name;
        int         _health;
        int         _energy;
        int         _damage;
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int damage);
        ClapTrap    &operator=(const ClapTrap &copy);
        ~ClapTrap(void);
    
        std::string     getName(void) const;
        unsigned int    getHealth(void) const;
        unsigned int    getEnergy(void) const;
        unsigned int    getDamage(void) const;
        void            setEnergy(unsigned int energy);
        void            attack(const std::string &target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
};

#endif