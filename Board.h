#ifndef BOARD_H_
#define BOARD_H_

class Board
{
private:
	int boardSize;
	int **grid;

public:
	Board(int);
	virtual ~Board();
	Board(const Board &);
	bool addMove(int, int, int);
	void printBoard();

	int getBoardSize() const
	{
		return boardSize;
	}

	int getGrid(int x, int y) const
	{
		return grid[x][y];
	}

	std::vector<int> getNeighbours(int x, int y, int v) const;
	int getRow(int index) const
	{
		return index / boardSize;
	}
	int getCol(int index) const
	{
		return index % boardSize;
	}
	vector<int> emptyCells;

	bool CheckBoard();
	bool checkCPath();
	bool isValidMove(int x, int y) const;
	int heuristicsForCrosser(int current_y, int ny);
	Cell getBestMove(int x, int y, int v);
	bool checkStraightLine(int &x, int &y, int v);
	void getRandomMove(int &x, int &y);
	bool checkStraightCol(int &x, int &y, int v);
	int GameStatus();
	int checkEmpty(Board board);
};

int Board ::checkEmpty(Board board)
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			if (board.getGrid(i, j) == 0)
			{
				int eCell = board.getGrid(i, j);
				emptyCells.push_back(eCell);
				eCell = 0;
				return 1;
			}
		}
	}
	return 0;
}

void Board::getRandomMove(int &x, int &y)
{
	if (CheckBoard())
	{
		return;
	}
	do
	{
		x = rand() % boardSize;
		y = rand() % boardSize;
	} while (!isValidMove(x, y));
}

Cell Board::getBestMove(int x, int y, int v)
{
	std::priority_queue<Cell> pq;

	// Check for the immediate right cell first
	if (y + 1 < boardSize && grid[x][y + 1] == 0)
	{
		int heuristicValue = heuristicsForCrosser(y, y + 1); // If the right cell is free, it's the best move
		return Cell(x, y + 1, heuristicValue);
	}

	else if (x + 1 < boardSize && y + 1 < boardSize && grid[x + 1][y + 1] == 0)
	{

		// If the diagonal down-right cell is free, it's the best move
		int heuristicValue = heuristicsForCrosser(y, y + 1); // Update heuristic as needed
		return Cell(x + 1, y + 1, heuristicValue);
	}
	// If neither right nor diagonal down-right is free, use the heuristic to find the best move
	else
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0)
					continue;
				int nx = x + i;
				int ny = y + j;
				if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && grid[nx][ny] == 0)
				{
					int heuristicValue = heuristicsForCrosser(y, ny);
					pq.push(Cell(nx, ny, heuristicValue));
				}
			}
		}
	}

	// If we have candidates in the priority queue, return the best one
	if (!pq.empty())
	{
		return pq.top();
	}
}

bool Board::isValidMove(int row, int col) const
{
	if (0 <= row && row <= boardSize - 1 && 0 <= col && col <= boardSize - 1 && grid[row][col] == 0)
		return true;
	else
		return false;
}

bool Board::checkCPath()
{ // smart C moves
	std::stack<int> trackingStack;
	std::vector<bool> visited(boardSize * boardSize, false); //

	// Push initial positions of CROSSER to the stack
	for (int i = 0; i < boardSize; i++)
	{
		if (grid[i][0] == -1)
		{
			trackingStack.push(i * boardSize);
			visited[i * boardSize] = true;
		}
	}

	// Perform DFS to find the path
	while (!trackingStack.empty())
	{
		int current = trackingStack.top();
		trackingStack.pop();

		// Check if we have reached the last column
		if (getCol(current) == boardSize - 1)
		{

			return true;
		}

		std::vector<int> neighbours = getNeighbours(getRow(current), getCol(current), -1);
		for (int neighbour : neighbours)
		{
			if (!visited[neighbour])
			{
				trackingStack.push(neighbour);
				visited[neighbour] = true;
			}
		}
	}

	return false;
}

int Board ::GameStatus()
{
	if (checkCPath() == true)
	{
		return -1;
	}
	else if (CheckBoard() == true)
	{
		return 1;
	}
	else
		return 0;
}

std::vector<int> Board::getNeighbours(int x, int y, int v) const
{
	std::vector<int> indices;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			int nx = x + i;
			int ny = y + j;
			if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && grid[nx][ny] == v)
			{
				indices.push_back(nx * boardSize + ny);
			}
		}
	}
	return indices;
}

Board::Board(int bs)
{
	boardSize = bs;
	grid = new int *[boardSize];
	for (int i = 0; i < boardSize; i++)
		grid[i] = new int[boardSize];

	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
		{
			grid[i][j] = 0;
		}
}

Board::~Board()
{
	for (int i = 0; i < boardSize; i++)
		delete[] grid[i];

	delete[] grid;
}

Board::Board(const Board &cboard)
{
	boardSize = cboard.getBoardSize();

	grid = new int *[boardSize];
	for (int i = 0; i < boardSize; i++)
		grid[i] = new int[boardSize];

	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			grid[i][j] = cboard.getGrid(i, j);
}

bool Board::addMove(int x, int y, int v)
{
	if (x < 0 || y < 0 || x >= boardSize || y >= boardSize)
	{
		// std::cout << "Move (" << x + 1 << ", " << y + 1 << ") out of range!" << std::endl;
		return false;
	}
	grid[x][y] = v;
	return true;
}

bool Board::checkStraightLine(int &x, int &y, int v)
{
	for (int row = 0; row < boardSize; ++row)
	{
		int col;
		for (col = 0; col < boardSize; ++col)
		{
			if (grid[row][col] == v)
			{
				// Found a 'C', now check the cell to its right
				int nextCol = col + 1;
				if (nextCol < boardSize && grid[row][nextCol] == 0)
				{
					// The cell to the right is empty, so place 'C' here
					x = row;
					y = nextCol;
					return true;
				}
				else
				{
					// The cell to the right is either a 'B' or the edge of the board
					// 'C' can't move further right on this row, break to check the next row
					break;
				}
			}
		}
	}
	return false; // No available spot to move 'C' to the right
}

int Board::heuristicsForCrosser(int current_y, int ny)
{
	if (ny > current_y)
	{
		return 3; // If the neighbour's 'y' is greater than the current 'y'
	}
	else if (ny == current_y)
	{
		return 2; // If the neighbour's 'y' is equal to the current 'y'
	}
	else if (ny < current_y)
	{
		return 1; // If the neighbour's 'y' is less than the current 'y'
	}

	return 0;
}

bool Board::CheckBoard()
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			if (grid[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Board::checkStraightCol(int &x, int &y, int v)
{
	for (int col = 0; col < boardSize; ++col)
	{
		for (int row = 0; row < boardSize; ++row)
		{
			if (grid[row][col] == v)
			{
				// Kiểm tra ô tiếp theo trong cùng một cột
				int nextRow = row + 1;
				if (nextRow < boardSize && grid[nextRow][col] == 0)
				{
					x = nextRow;
					y = col;
					return true; // Đã tìm được vị trí phù hợp để di chuyển
				}
			}
		}
	}
	return false; // Không tìm được ô nào phù hợp để di chuyển
}

void Board::printBoard()
{
	std::cout << "     ";
	for (int j = 0; j < boardSize; j++)
	{
		if (j < 9)
			std::cout << j + 1 << "   ";
		else
			std::cout << j + 1 << "  ";
	}
	std::cout << std::endl;

	std::cout << "   ";
	for (int j = 0; j < boardSize; j++)
	{
		std::cout << "----";
	}
	std::cout << std::endl;

	for (int i = 0; i < boardSize; i++)
	{
		if (i < 9)
			std::cout << " " << i + 1 << " ";
		else
			std::cout << i + 1 << " ";

		for (int j = 0; j < boardSize; j++)
		{
			if (grid[i][j] == 0)
			{
				if (j == 0)
				{
					std::cout << "|   |";
				}
				else
				{
					std::cout << "   |";
				}
			}

			else if (grid[i][j] == 1)
			{
				if (j == 0)
				{
					std::cout << "| B |";
				}
				else
				{
					std::cout << " B |";
				}
			}
			else
			{
				if (j == 0)
				{
					std::cout << "| C |";
				}
				else
				{
					std::cout << " C |";
				}
			}
		}
		std::cout << std::endl;
		if (i < boardSize - 1)
			std::cout << std::endl;
	}
	std::cout << "   ";
	for (int j = 0; j < boardSize; j++)
	{
		std::cout << "----";
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

#endif /* BOARD_H_ */