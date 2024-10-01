/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:50:34 by yfang             #+#    #+#             */
/*   Updated: 2024/09/27 11:01:01 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap    &operator=(const ScavTrap &copy);
        ~ScavTrap(void);

        void    guardGate(void);
        void    attack(const std::string &target);
};

#endif