#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_
// class RandomPlayer : public Player
// {
// public:
// 	RandomPlayer(int v): Player(v) {}

// 	void getMove(Board board, int& x, int& y, int& v)
// 	{
// 		int boardSize = board.getBoardSize();
// 		do {
// 		x = rand() % boardSize;
// 		y = rand() % boardSize;
// 		} while (!board.isValidMove(x, y));
// 	}
// };

class RandomPlayer : public Player {

public:
    RandomPlayer(int v): Player(v) {}

    void getMove(Board board, int& x, int& y, int& v)
	{
        int boardSize = board.getBoardSize();

        if (board.checkEmpty(board) == 1) {
		x = rand() % boardSize;
 		y = rand() % boardSize;
        }
	}
};

#endif /* RANDOMPLAYER_H_ */