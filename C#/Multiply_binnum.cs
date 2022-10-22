using System;
class program
{
    public static void Main()
    {
 
        int binary1, binary2, multiply = 0;
        int digit, factor = 1;
        prog pg = new prog();
        Console.WriteLine("Enter the first binary number: ");
        binary1 = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter the second binary number: ");
        binary2 = int.Parse(Console.ReadLine());
        while (binary2 != 0)
        {
            digit =  binary2 % 10;
            if (digit == 1)
            {
                binary1 = binary1 * factor;
                multiply = pg.binaryproduct(binary1, multiply);
            }
            else {
                binary1 = binary1 * factor;
                binary2 = binary2 / 10;
                factor = 10;
            }
            Console.WriteLine("Product of two binary numbers: {0}", multiply);
            Console.ReadLine();
        }
    }
class prog
{
    public int binaryproduct(int binary1, int binary2)
    {
        int i = 0, remainder = 0;
        int[] sum = new int[20];
        int binaryprod = 0; 
        while (binary1 != 0 || binary2 != 0)
        {
            sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
            remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
            binary1 = binary1 / 10;
            binary2 = binary2 / 10;
        }
        if (remainder != 0)
            sum[i++] = remainder;
            --i;
        while (i >= 0)
           binaryprod = binaryprod * 10 + sum[i--];
        return binaryprod;
    }
}
