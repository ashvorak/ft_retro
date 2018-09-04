/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:58:12 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 18:27:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bullet.hpp"

Bullet::Bullet() {
	this->_x = 0;
	this->_y = 0;
	this->_on_line = false;
	this->_av = true;
}

Bullet::Bullet(int x, int y) {
	
	this->_x = x;
	this->_y = y;
	this->_on_line = false;
	this->_av = true;

}

Bullet::Bullet(const Bullet &copy) {
	*this = copy;
}

Bullet & Bullet::operator=(Bullet const &src) {
	if (this == &src)
		return (*this);
	this->_x = src._x;
	this->_y = src._y;
	this->_on_line = src._on_line;
	this->_av = src._av;
	return (*this);
}

Bullet::~Bullet() {
	
}

bool Bullet::getOnLine() {
	return (this->_on_line);
}

void	Bullet::setOnLine(bool bl) {
	this->_on_line = bl;
}

bool Bullet::getAv() {
	return (this->_av);
}

void	Bullet::setAv(bool bl) {
	this->_av = bl;
}

void Bullet::setMove(int x, int y) {
	this->_x = x;
	this->_y = y;
	this->_on_line = true; 
}