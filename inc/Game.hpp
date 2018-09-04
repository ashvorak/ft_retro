/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:41:44 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 20:46:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#define BULLET_NUM 20

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <sys/time.h>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Item.hpp"

class Game {
	
	private:
		int w;
		int h;
		int s;
		int bonus;
		int ammo;
		int fps;
		int	lives;
		Player 	*p1;
		Item	it;
		Enemy 	em[ENEMY_NUM];
		Bullet	bullet[BULLET_NUM];

	public:
		Game();
		Game(const Game &copy);
		Game &operator = (const Game &src);
		~Game();

		void	init();
		void	play();
		void	info(WINDOW *win, int key, int s);
			
		void	movePlayer(Player *p, int key);
		void	moveEnemy(Enemy *em);
		void	moveBullet(Bullet *bullet);

		bool	checkCollision(Player *p1, Enemy em[]);
		void	checkCollision(Enemy *em, Bullet *bullet);

		void	printArr(Enemy em[]);
		void	printArr(Bullet bullet[]);

		void	initEnemy();

		void	launch();
		void	game_over(WINDOW *win);

};

#endif