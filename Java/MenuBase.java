import java.util.Scanner;

class MenuBase
{
  public static void main(String args[])
  {
    int menu=1;

    char op;//char of calculator
    int a,b,res;//int of calculator

    int d,e,z;//int of Triangle

    int eng,phy,chem,math,computer,total_marks=500,obt_marks,std_name;//int of Marksheet
    float per;//float of Marksheet


    Scanner obj=new Scanner(System.in);
   
    System.out.print("\n\t^^^^^^^^^^^^");
    System.out.print("\n\t1.Calculator \n\t2.Triangle \n\t3.Marksheet\n\t4.Exit");
    System.out.print("\n\t^^^^^^^^^^^^");


    while(menu!=4)
    {
      System.out.print("\n\n\tChoose Task: ");
      menu=obj.nextInt();      
  
         switch(menu)
         {
            case 1:  
            System.out.print("\n\t CALCULATOR");
            System.out.print("\n\t*************");
            System.out.print("\n\t + - * / : ");
            op=obj.next().charAt(0);
            System.out.print("\n\t*************");

            System.out.print("\n\t1st Value: ");
            a=obj.nextInt();
   
            System.out.print("\n\t2nd Value: ");
            b=obj.nextInt();    

           if(op=='+')
           {
             res=a+b;
             System.out.print("\n\tAnswer: " + res);
           } 
    
           else if(op=='-')
           {
             res=a-b;
             System.out.print("\n\tAnswer: " + res);
           }
    
           else if(op=='*')
           {
             res=a*b;
             System.out.print("\n\tAnswer: " + res);
           }
   
           else if(op=='/')
           {
             res=a/b;
             System.out.print("\n\tAnswer: " + res);
           }
           else
           {
             System.out.print("\n\tInvailid Entry");
           }
           break;
           
           case 2:
     
           System.out.print("\n\tEnter The Star print Number: ");
           z=obj.nextInt();
 
           for(d=1; d<=z; d++)
           {
            for(e=1; e<=d; e++)
            {
              System.out.print(" *");
            }
            System.out.print("\n");
           }

           break;

           case 3:
          
      Scanner mm=new Scanner(System.in);
       
      System.out.print("\n\tAptech Compuetr Education Defence Hyderabad \n\t\t\tMarksheet\n");
       
      System.out.println("========================================================");

      System.out.print("\nSubjects                 Total Marks      Obtained Marks\n");      

      System.out.print("\nEnter The Eng Marks:        100                  ");
      eng=mm.nextInt();
      
      System.out.print("\nEnter The Phy Marks:        100                  ");
      phy=mm.nextInt();
    
      System.out.print("\nEnter The Chem Marks:       100                  ");
      chem=mm.nextInt();

      System.out.print("\nEnter The Math Marks:       100                  ");
      math=mm.nextInt();
   
      System.out.print("\nEnter The Computer Marks:   100                  ");
      computer=mm.nextInt();

      System.out.println("=======================================================================================");
      
      System.out.print("\t\t\tTotal Marks=500"); 
      
      obt_marks=eng+phy+chem+math+computer;
      System.out.print("\t  Obtain Marks= " + obt_marks); 

      per=obt_marks*100/total_marks;
      System.out.print("\tPersontage= % " + per); 

      System.out.println("\n=======================================================================================");

      if(obt_marks>=180)
      {
        System.out.println("PASS");
      }
      else
      {
        System.out.println("FAIL");
      }
       break;

	case 4: 
		System.exit(0);
       default:
       System.out.print("\n You Are Choose Wrong Task!");    

       }//end of Switch

    }//end of While Loop
      
  }
}