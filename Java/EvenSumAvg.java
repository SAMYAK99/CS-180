import java.util.*;
public class EvenSumAvg{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a, b, n, e, x, sum, avg, count;
        System.out.print("Enter the range number: ");
        n = input.nextInt();
        a = 1;
        x = 0; 
        b = 0;
        sum = 0;
        count = 0;
            e = n / 2;
            System.out.println("Even number from " + a + " to " + n + " is " + e);
            
        while (x < n){
            if (n % 2 == 1) continue;
             x = x + 2;
             System.out.println("The even number " + a + " is " + x);
             a++;
             b += x;
             count++;
             }
             sum = b;
             System.out.println("The sum of the even number from 1 to " + n + " is " + b);
             avg = b / e;
             System.out.println("the average of the even number from 1 to " + n + " is " + avg);
        }
    }
