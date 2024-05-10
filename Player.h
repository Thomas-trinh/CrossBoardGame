/*
 * Player.h
 *      Author: Hoang Tung
 */
#include "Board.h"
#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
	protected:
	int playerSymbol;
public:
	Player(int v) {
		playerSymbol = v;
	}

	int getPlayerSymbol() {
		return playerSymbol;
	}

	virtual void getMove(Board board, int& x, int& y, int& v) = 0;
};

#endif /* PLAYER_H_ */
