package Banking;
import java.util.Scanner;
public class Bank_App {
    public static void main(String[] args) {
        Banking b = new Banking("Anil Adhikari","100C01A5");
        b.showMenu(); 
    }
 
}
class Banking{
    Scanner sc = new Scanner(System.in);
int balance;
int previous_transaction;
String Customer_Name;
String Customer_Id;

Banking(String n, String i)
{
Customer_Name=n;
Customer_Id=i;
}

void Deposit(int Amount)
{
if(Amount!=0)
{
balance=balance+Amount;
previous_transaction=Amount;
}
}

void Withdraw(int Amount1)
{
if(Amount1!=0)
{
balance=balance-Amount1;
previous_transaction=-Amount1;
}
}

void getPreviousTransaction()
{
if(previous_transaction>0)
{
    System.out.println("Deposited : "+previous_transaction);
}
else if(previous_transaction<0)
{
    System.out.println("Withdrawn : "+Math.abs(previous_transaction));
}
else
{
    System.out.println("No any transaction had occoured !");
}
}


void showMenu()      
{
    char choose;
    
    System.out.println("--------------------------------------------");
    System.out.println("Welcome "+Customer_Name);
    System.out.println("Your Account id is : "+Customer_Id);
    System.out.println("--------------------------------------------");
    System.out.println("\n");
    
    do
    {
    
    System.out.println("A. Check Balance of your Account ");
    System.out.println("B. Deposit Amount");
    System.out.println("C. Withdraw Amount");
    System.out.println("D. Check previous Transaction");
    System.out.println("E. Exit");
    
    
        System.out.println("/--------------------------------------/");
        System.out.print("Choose what you want to do : ");
        System.out.println();
        System.out.println("/--------------------------------------/");
        choose = sc.next().charAt(0);
        System.out.println("\n");
        
    switch(choose)
    {
        case 'A':
                {
                    System.out.println("**************************");
                    System.out.println("Your Balance is : "+balance);
                    System.out.println("**************************");
                    System.out.println("\n");
                    break;   
                }
        case 'B':
                {
                    System.out.println("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
                    System.out.println("Enter the amount you want to deposit : ");
                    System.out.println("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
                    int Amount = sc.nextInt();
                    Deposit(Amount);
                    System.out.println("\n");
                    break; 
                }
        case 'C':
                {
                    System.out.println("***********************************************");
                    System.out.println("Enter the amount you want to Withdraw : ");
                    System.out.println("***********************************************");
                    int Amount1=sc.nextInt();
                    Withdraw(Amount1);
                    System.out.println("\n");
                    break;
                }
        case 'D':
                {
                    System.out.println("***********************************************");
                    getPreviousTransaction();
                    System.out.println("***********************************************");
                    System.out.println("\n");
                    break;
                }
        case 'E':
                {
                    System.out.println("----------------------------------------"); 
                    break;
                }
        default: 
                {
                    System.out.println("Invalid character !!!");
                }
    }
   }while(choose!='E');
    
    System.out.println("Thank you for using our services....");
    System.out.println("       ___________             ");
    System.out.println("      {   @   @   }           ");
    System.out.println("      {     )     }          ");
    System.out.println("      {   >---<   }       ");
    System.out.println("      {___________}        ");
    System.out.println();
    System.out.println("----------------------------------------");
    
}
}