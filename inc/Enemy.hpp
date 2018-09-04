/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:26:49 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 17:58:20 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include <ctime>
#include "Element.hpp"

#define   ENEMY_NUM 100

class Enemy : public Element {

	private:
		int _delay;

	public :
		Enemy();
		Enemy(int x, int y);
		Enemy(const Enemy &copy);
		Enemy & operator=(const Enemy &src);
		~Enemy();

		int 	getDelay();
		void	setDelay(int delay);
		void	setNewEnemy(int w);
		void	printEnemy(Enemy em[]);
};

#endif