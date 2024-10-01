/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:35:51 by yfang             #+#    #+#             */
/*   Updated: 2024/09/27 11:00:54 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        FragTrap    &operator=(const FragTrap &copy);
        ~FragTrap(void);
        
        void    highFivesGuys(void);
};

#endif
