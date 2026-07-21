#include <vector>

class TicTacToe {
    private:
        std::vector<std::vector<int>> logicBoard;
        u_int32_t width = 3;
        u_int32_t height = 3;
        u_int32_t moveCount = 0;
        char winner = 'n';
    public:
        enum fieldState {EMPTY, Xmark, Omark};
        TicTacToe();
        void updateMoveCount();
        int getFieldState(int x, int y);
        void setFieldState(int x, int y, int newState);
        int getMoveCount();
        int hasWinner();
        void setWinner(char winner);
        char getWinner();
        void printBoard();
};
