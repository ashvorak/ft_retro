/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:13:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/23 17:15:39 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Player.hpp"

Player::Player() {
	
}

Player::Player(int x, int y) {

	this->_x = x;
	this->_y = y;
}

Player::Player(const Player &copy) {
	*this = copy;
}

Player & Player::operator=(Player const &src) {
	if (this == &src)
		return (*this);
	this->_x = src._x;
	this->_y = src._y;
	return (*this);
}

Player::~Player() {
}
