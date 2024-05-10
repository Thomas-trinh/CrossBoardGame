#ifndef SMARTBLOCKER_H_
#define SMARTBLOCKER_H_

class SmartBlocker : public Player
{
public:
    SmartBlocker(char v) : Player(v) {}

    void getMove(Board gameBoard, int& currentX, int& currentY, int& v)
    {
        int boardSize = gameBoard.getBoardSize();

        bool isCrosserNearby = false; // Biến cờ để kiểm tra sự hiện diện của Crosser gần đó

        // addMove(currentX, currentY, v);
        // Kiểm tra xem có Crosser nào ở cạnh không
        for (int i = std::max(0, currentX - 1); i <= std::min(boardSize - 1, currentX + 1); i++)
        {
            for (int j = std::max(0, currentY - 1); j <= std::min(boardSize - 1, currentY + 1); j++)
            {
                if (gameBoard.getGrid(i, j) == -1)
                { 
                    isCrosserNearby = true;
                    break;
                }
            }
            // if (isCrosserNearby) break;
        }

        // Nếu phát hiện Crosser ở gần và có thể di chuyển sang phải, hãy di chuyển
        if (isCrosserNearby && currentY < boardSize - 1 && gameBoard.getGrid(currentX, currentY + 1) == 0)
        {
            currentY++;
        }
        else if (currentX < boardSize - 1 && gameBoard.getGrid(currentX + 1, currentY) == 0)
        {
            // Nếu không thể di chuyển sang phải hoặc không có Crosser gần đó, di chuyển xuống dưới
            currentX++;
        }
        else
        {
            // Nếu không thể di chuyển xuống dưới, tìm vị trí ngẫu nhiên mới
            do
            {
                currentX = rand() % boardSize;
                currentY = rand() % boardSize;
            } while (!gameBoard.isValidMove(currentX, currentY));
        }

        //addMove(currentX, currentY, v);
    }

};

#endif /* SMARTBLOCKER_H_ */