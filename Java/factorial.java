import java.util.*;

class factorial

{

    public static void main(String args[])

    {

        Scanner sc=new Scanner(System.in);

        System.out.println("Enter a number-");

        int n=sc.nextInt();         //To enter a number

        int multi=1;       

        do{                                  //do-while loop to find the factorial of entered number.

            multi = multi*n;       //To multiply both the numbers and stores in the variable multi

            n = n-1;

        }while(n>=1);

        System.out.println("Factorial of "+n+" is "+multi);   //To print the factorial

    }

}
