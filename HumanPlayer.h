/*
 * HumanPlayer.h
 *      Author: Hoang Tung
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

class HumanPlayer : public Player
{
public:
	HumanPlayer(int v): Player(v) {}

	void getMove(Board board, int& x, int& y, int& v)
	{
		x = 0;
		y = 0;
		
		do
		{
			if (v == 1){
				std::cout << "Player B enter move (row and column) :";
			} else if (v == -1) {
				std::cout << "Player C enter move (row and column) :";
			}
			std::cin >> x >> y;
			std::cout << std::endl;
			x = x - 1;
			y = y - 1;

			if (!board.isValidMove(x, y))
				std::cout << "Invalid move!" << std::endl;

		} while (!board.isValidMove(x, y));

		board.addMove(x, y, v);
	}
};

#endif /* HUMANPLAYER_H_ */