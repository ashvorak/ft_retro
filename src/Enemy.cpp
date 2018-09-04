/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:27:01 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 17:58:13 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Enemy.hpp"

Enemy::Enemy() {
	this->_x = rand() % 96 + 2;
	this->_y = rand() % 3 + 3;
	this->_delay = rand() % 50;
}

Enemy::Enemy(int x, int y) {
	
	this->_x = x;
	this->_y = y;
	this->_delay = rand() % 200;

}

Enemy::Enemy(const Enemy &copy) {
	*this = copy;
}

Enemy & Enemy::operator=(Enemy const &src) {
	if (this == &src)
		return (*this);
	this->_x = src._x;
	this->_y = src._y;
	return (*this);
}

Enemy::~Enemy() {
	
}

int Enemy::getDelay() {
	return (this->_delay);
}

void Enemy::setDelay(int delay) {
	this->_delay = delay;
}

void Enemy::setNewEnemy(int w) {
	this->_x = rand() % w + 2;
	this->_y = rand() % 3 + 3;
	this->_delay = rand() % 50;
}

void Enemy::printEnemy(Enemy em[]) {
	for(int j = 0; j < ENEMY_NUM; j++)
		if (em[j].getDelay() == 0)
			em[j].print(em[j].getY(), em[j].getX(), "o");
}