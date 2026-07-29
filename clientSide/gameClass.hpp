#include <vector>

class TicTacToe {
    private:
        std::vector<std::vector<int>> logicBoard;
        u_int32_t width = 3;
        u_int32_t height = 3;
        u_int32_t moveCount = 0;
        u_int32_t Xwins = 0;
        u_int32_t Owins = 0;
        char winner = 'n';
    public:
        enum fieldState {EMPTY, Xmark, Omark};
        TicTacToe();
        void updateMoveCount();
        int getFieldState(int x, int y);
        void setFieldState(int x, int y, int newState);
        int getMoveCount();
        bool makeMove(int x, int y);
        int hasWinner();
        void setWinner(char winner);
        char getWinner();
        void printBoard();
        void updateXwins();
        void updateOwins();
        int getXwins();
        int getOwins();
};
