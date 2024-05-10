/*
 * Main.cpp
 *
 *  Created on: 10/02/2024
 *      Author: Hoang Tung Trinh
 *  	Parramatta South 
 */

#include<iostream>
#include<time.h>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#include "Cell.h"
#include "Board.h"
#include "Player.h"
#include "SmartCrosser.h"
#include "SmartBlocker.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "MonteCarloPlayer.h"
#include "Game.h"

int main() {
	srand(time(0));
	Game game(7);
	game.playGame(); 
	return 0;
}