/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:14:03 by yfang             #+#    #+#             */
/*   Updated: 2024/09/27 11:14:40 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator=(const DiamondTrap &copy);
        ~DiamondTrap(void);

        using   ScavTrap::attack;
        void    whoAmI(void);
};

#endif
