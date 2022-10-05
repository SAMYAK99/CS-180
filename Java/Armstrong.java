import java.util.Scanner;
public class Armstrong {

    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        int number=sc.nextInt();
        int originalNumber, remainder, result = 0, count=0;

        originalNumber = number;

        while (originalNumber != 0)
        {
            count++;
            originalNumber /= 10;
        }
        originalNumber = number;
        while (originalNumber != 0)
        {
            remainder = originalNumber % 10;
            result += Math.pow(remainder, count);
            originalNumber /= 10;
        }
        if(result == number)
            System.out.println(number + " is an Armstrong number.");
        else
            System.out.println(number + " is not an Armstrong number.");
    }
}
