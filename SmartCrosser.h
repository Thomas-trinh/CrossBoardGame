#ifndef SMARTCROSSER_H_
#define SMARTCROSSER_H_

class SmartCrosser :public Player {
public:
	SmartCrosser(int v): Player(v) {}

	void getMove(Board gameBoard, int& x, int& y, int& v){

	static bool firstMoveDone = false; 
	
	int boardSize = gameBoard.getBoardSize();

	if (!firstMoveDone)
	{
		x = rand() % boardSize; // Random starting x position for the first move
		// Attempt to place the first move. If it's valid, mark the first move as done.
		//gameBoard.addMove(x, y, v);
		firstMoveDone = true; // Ensure no additional move is made this turn
		return;				  // Exit the function after making the first move
	}
	else
	{
		int nextX, nextY;
		if (gameBoard.checkStraightLine(nextX, nextY, v))
		{
			// If a straight path is found, make the move
			x = nextX;
			y = nextY;
			// gameBoard.addMove(x, y, v);
		}
		else
		{
			Cell bestMove = gameBoard.getBestMove(x, y, v);
			x = bestMove.x;
			y = bestMove.y;
			// gameBoard.addMove(x, y, v);
		}
	}
}

};

#endif /* SMARTCROSSER_H_ */