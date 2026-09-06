class testClass
{
    public static void Main()
    {
        TicTacToe testGame = new TicTacToe();
        
        while (testGame.HasWinner() == 0)
        {
            int x, y;
            Console.Write("Give x: \n");
            x = int.Parse(Console.ReadLine());
            Console.Write("Give y: \n");
            y = int.Parse(Console.ReadLine());
            testGame.makeMove(x,y);
            testGame.printBoard();
        }
    }
}