/*
 * MonteCarloPlayer.h
 *      Author: Hoang Tung
 */

#ifndef MONTECARLOPLAYER_H_
#define MONTECARLOPLAYER_H_

class MonteCarloPlayer: public Player {
public:
	MonteCarloPlayer(int v) :
			Player(v) {
	}

	void getMove(Board board, int &x, int &y, int& v) {
		
		int boardSize = board.getBoardSize();

		std::priority_queue<Cell> moves;

		std::cout << "Utilities of Moves" << std::endl;
		for (int i = 0; i < boardSize; i++) { 
			for (int j = 0; j < boardSize; j++) {

				if (board.getGrid(i, j) != 0) {
					cout << "  x   ";
					continue;
				}
				
				Board tempBoard(board); 

				int x1,y1;
				board.getRandomMove(x,y);
				
				if(playerSymbol == -1) {
				tempBoard.addMove(i, j, -1);
				tempBoard.addMove(x1, y1, 1);
				}else {
				tempBoard.addMove(x1, y1, -1);
				tempBoard.addMove(i, j, 1);		
				}
				

				if (tempBoard.GameStatus() == playerSymbol) {
					x = i;
					y = j;
					return;
				}

				double utility = simulation(tempBoard);
				
				Cell c(i, j, utility);
				moves.push(c);

				//cout << setw(5) << utility << " ";
				cout << setw(5) << c.heuristic << " ";
			}
			std::cout << std::endl;
		}

		if (!moves.empty()) {
			x = moves.top().x;
			y = moves.top().y;
			std::cout << "Best X " << moves.top().x + 1 << std::endl;
			std::cout << "Best Y " << moves.top().y + 1<< std::endl;
			std::cout << "Best utility " << moves.top().heuristic << std::endl;
		}

		return;
	}

	double simulation(Board board)
{
	int times = 1000;
	double winning = 0.0;

	for (int i = 0; i < times; i++)
	{
		Board tempBoard(board);
		winning += expansion(tempBoard);
	}

	return (winning / (double)times);
}


	double expansion(Board board)
{
	if (board.GameStatus() == playerSymbol)
	{
		return 1.0;
	} 
	else if (board.GameStatus() != 0)
	{ 
		return 0.0; 
	}
	int x1, y1,x2,y2;

	board.getRandomMove(x1, y1);
	board.getRandomMove(x2, y2);

	board.addMove(x1, y1, -1);
	board.addMove(x2, y2, 1);

	return expansion(board);
}
};

#endif /* MONTECARLOPLAYER_H_ */
