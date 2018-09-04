/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:49:38 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 16:10:42 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "Element.hpp" 
#include "Bullet.hpp"

class Player : public Element {

	public :
		Player();
		Player(int x, int y);
		Player(const Player &copy);
		Player & operator=(const Player &src);
		~Player();
};

#endif