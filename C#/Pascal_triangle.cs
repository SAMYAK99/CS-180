using System;
class Pascal
{
    public static void Main()
    {
        int[,] arr = new int[8, 8];
        Console.WriteLine("Pascal Triangle : ");
        for (int i = 0; i < 5; i++)
        {
            for (int k = 5; k > i; k--)
            {   
                Console.Write(" ");
            }
 
            for (int j = 0; j < i; j++)
            {
                if (j == 0 || i == j)
                {
                    arr[i, j] = 1;
                }
                else
                {
                    arr[i, j] = arr[i - 1, j] + arr[i - 1, j - 1];
                }
                Console.Write(arr[i, j] + " ");
            }
            Console.ReadLine();
        }
    }
}
