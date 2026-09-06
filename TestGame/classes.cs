using System.Collections.Generic;

public class TicTacToe
{
    private List<List<int>> logicBoard = new List<List<int>>();
    private int width = 3;
    private int height = 3;
    private int moveCount = 0;
    private int Xwins = 0;
    private int Owins = 0;
    private char winner = 'n';

    public enum fieldState {EMPTY, Xmark, Omark};

    public const int TIE = 3;
    
    public TicTacToe()
    {
        List<List<int>> tempLogicBoard = new List<List<int>>();
        tempLogicBoard.Add(new List<int>{0,0,0});
        tempLogicBoard.Add(new List<int>{0,0,0});
        tempLogicBoard.Add(new List<int>{0,0,0});
        this.logicBoard = tempLogicBoard;
    }

    public void displayBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Console.Write(this.logicBoard[i][j] + "\t");
            }
            Console.Write("\n");
        }
    }

    public void incrementMoveCount()
    {
        this.moveCount++;
    }
    
    public int getFieldState(int x, int y)
    {
        return this.logicBoard[x][y];
    }

    public void setFieldState(int x, int y, int newState)
    {
        if (this.logicBoard[x][y] == (int)fieldState.EMPTY) this.logicBoard[x][y] = newState;
    }

    public int getMoveCount()
    {
        return this.moveCount;
    }

    public void makeMove(int x, int y)
    {
        this.incrementMoveCount();
        int movesMade = this.getMoveCount();
        int symbol;
        if (movesMade % 2 == 1)
        {
            symbol = (int)fieldState.Xmark;
        } 
        else
        {
            symbol = (int)fieldState.Omark;    
        }
        this.setFieldState(x,y,symbol);
    }

    public void setWinner(char newWinner)
    {
        if (this.winner == 'n') this.winner = newWinner;
    }

    public void updateOwins()
    {
        this.Owins++;
    }
    public void updateXwins()
    {
        this.Xwins++;
    }
    public void printBoard()
    {
        for (int i = 0; i < this.height; i++)
        {
            for (int j = 0; j < this.width; j++)
            {
                char symbol = '0';
                int currState = this.getFieldState(i,j);
                if (currState == (int)fieldState.EMPTY) symbol = '_';
                else if (currState == (int)fieldState.Xmark) symbol = 'X';
                else if (currState == (int)fieldState.Omark) symbol = 'O';
                Console.Write(symbol + "\t");
            }
            Console.Write("\n");
        }
    }

    public int getOwins()
    {
        return this.Owins;
    }
    public int getXwins()
    {
        return this.Xwins;
    }
    public void clearBoard()
    {
        List<List<int>> tempLogicBoard = new List<List<int>>();
        tempLogicBoard.Add(new List<int>{0,0,0});
        tempLogicBoard.Add(new List<int>{0,0,0});
        tempLogicBoard.Add(new List<int>{0,0,0});
        this.logicBoard = tempLogicBoard;
    }
    public int HasWinner()
    {
    for (int i = 0; i < 3; i++)
    {
        if (this.logicBoard[i][0] != (int)fieldState.EMPTY && this.logicBoard[i][0] == this.logicBoard[i][1] && this.logicBoard[i][1] == this.logicBoard[i][2])
        {
            return this.logicBoard[i][0];
        }
        if (this.logicBoard[0][i] != (int)fieldState.EMPTY && this.logicBoard[0][i] == this.logicBoard[1][i] && this.logicBoard[1][i] == this.logicBoard[2][i])
        {
            return this.logicBoard[0][i];
        }
    }

    // DIAGONALS
    if (this.logicBoard[0][0] != (int)fieldState.EMPTY && this.logicBoard[0][0] == this.logicBoard[1][1] && this.logicBoard[1][1] == this.logicBoard[2][2])
    {
        return this.logicBoard[0][0];
    }

    if (this.logicBoard[0][2] != (int)fieldState.EMPTY && this.logicBoard[0][2] == this.logicBoard[1][1] && this.logicBoard[1][1] == this.logicBoard[2][0])
    {
        return this.logicBoard[0][2];
    }

    // CHECK IF TIE
    for (int i = 0; i < this.width; i++)
    {
        for (int j = 0; j < this.height; j++)
        {
            if (this.logicBoard[i][j] == (int)fieldState.EMPTY) return 0;
        }
    }
    return TIE;
    }
}