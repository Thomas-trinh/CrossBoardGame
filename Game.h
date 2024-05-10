#ifndef GAME_H_
#define GAME_H_

class Game
{
private:
    Board gameBoard; // Member to hold the game board

public:
    // Constructor that initializes the board with a given size
    Game(int boardSize) : gameBoard(boardSize) {}

    void playGame()
    {
        int pC;
        int pB;
        Player *player[2];
        cout << "Choose the level for Crosser : " << std::endl;
        cout << "1. Random Player" << std::endl;
        cout << "2. Human Player" << std::endl;
        cout << "3. Smart Player" << std::endl;
        cout << "4. MonteCarlo Player" << std::endl;
        cin >> pC;
        switch (pC)
        {
        case 1:
            player[0] = new RandomPlayer(-1);
            break;
        case 2:
            player[0] = new HumanPlayer(-1);
            break;
        case 3:
            player[0] = new SmartCrosser(-1);
            break;
        case 4:
            player[0] = new MonteCarloPlayer(-1);
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }

        cout << "Choose the level for Blocker : " << std::endl;
        cout << "1. Random Player" << std::endl;
        cout << "2. Human Player" << std::endl;
        cout << "3. Smart Player" << std::endl;
        cout << "4. MonteCarlo Player" << std::endl;
        cin >> pB;
        switch (pB)
        {
        case 1:
            player[1] = new RandomPlayer(1);
            break;
        case 2:
            player[1] = new HumanPlayer(1);
            break;
        case 3:
            player[1] = new SmartBlocker(1);
            break;
        case 4:
            player [1] = new MonteCarloPlayer(1);
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }

        int x ;
        int y = 0;
        static int currentX = -1; // Lưu vị trí x hiện tại của B
        static int currentY = ((gameBoard.getBoardSize() / 4) * 3);
        int vC = -1;
        int vB = 1;

        gameBoard.printBoard();
        while (gameBoard.GameStatus() == 0)
        {
            player[0]->getMove(gameBoard, x, y, vC);
            player[1]->getMove(gameBoard, currentX, currentY, vB);
            gameBoard.addMove(x, y, player[0]->getPlayerSymbol());
            gameBoard.addMove(currentX, currentY, player[1]->getPlayerSymbol());
            gameBoard.printBoard();
            
            if (gameBoard.GameStatus() == -1)
            {
                std::cout << "Crosser won!" << std::endl;
                return; 
            } else if (gameBoard.GameStatus() == 1){
                std::cout << "Blocker won!" << std::endl; 
                return;
            }
        }
    }
};

#endif /* GAME_H_ */