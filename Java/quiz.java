import org.w3c.dom.Text;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Scanner;

public class task2 {
    String choicesOne="";
    String choicesTwo="";
    String choicesThree="";
    String correctAnswer="2";
    public void getRandom(ArrayList<String> list,int minScore) {
        String x = "";
        int points=0;
        int chances=8;
        Scanner sc = new Scanner(System.in);
        int j = 0;
        while (j <chances) {
            for (int i = j; i < list.size(); i++) {
                String k = list.get(i);

                if (i == 0) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "James Chedwik";
                    choicesTwo = "James Gosling";
                    choicesThree = "Jet Brines";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                } else if (i == 1) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "Dennis M.Ritchie";
                    choicesTwo = "Bijarne Stroustrup";
                    choicesThree = "Bill Joy";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;

                } else if (i == 2) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "2 bytes";
                    choicesTwo = "4 bytes";
                    choicesThree = "3 bytes";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                }
                if (i == 3) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "3";
                    choicesTwo = "2";
                    choicesThree = "4";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                } else if (i == 4) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "Earth";
                    choicesTwo = "Jupyter";
                    choicesThree = "Naptune";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                }
                else if (i == 5) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "28 July";
                    choicesTwo = "27 July";
                    choicesThree = "30 July";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                }
                else if (i == 6) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "China";
                    choicesTwo = "Russia";
                    choicesThree = "America";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                }
                else if (i == 7) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "2 bits";
                    choicesTwo = "8 bits";
                    choicesThree = "16 bits";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                }
                else if (i == 8) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "Ram Nath Kovind";
                    choicesTwo = "Raj Nath Singh";
                    choicesThree = "Yogi Adityanath";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                }
                else if (i == 9) {
                    System.out.println(k);
                    System.out.println("Enter the choices of the following?\n");
                    choicesOne = "Ajit Divel";
                    choicesTwo = "Kiran Bedi";
                    choicesThree = "Shivdeep";
                    System.out.println("a." + choicesOne);
                    System.out.println("b." + choicesTwo);
                    System.out.println("c." + choicesThree);
                    System.out.println("Press 1.for first choices\nPress 2.for second choices\nPress 3.for choices");
                    x = sc.next();
                    break;
                }
            }

            if (correctAnswer.equals(x)) {
                System.out.println("Cogrates! your answer is correct");
                System.out.println("You got 10 points");
                points+=10;
                System.out.println(chances-j-1+ ": chances are remaining\n");

            } else {
                System.out.println("Incorrect answer! the correct answer is: " + choicesTwo);
                System.out.println(chances-j-1+ ":chances are remaining\n");

            }
            j++;
        }
        System.out.println("Your total score is :" +points);
        if(points>=minScore)
        {
            System.out.println("You win..");
        }
        else
        {
            System.out.println("You Loose..! Please try again Later");
        }
        System.out.println("Quiz Finished...");

    }

    public static void main(String args[])
    {
        System.out.println("\n-----------------Welcome to My Quiz---------------\n");
        int minScore=40;
        System.out.println("If you  get more the " +minScore+ " then you would win?");
        ArrayList<String> list=new ArrayList<>();
        list.add("Who are the developers of java?\n");
        list.add("C++ is developed by?");
        list.add("what is the size of int in java?\n");
        list.add("How many types of data types in java?\n");
        list.add("What is the largest planet in our solar System?\n");
        list.add("When did Rafale Come to India?\n");
        list.add("Rafale fighter jet is made by?\n");
        list.add("1 byte equals to how many bit in java?\n");
        list.add("who is the defence miniter of india?\n");
        list.add("Who was the first IPS officer in india?\n");

        task2 t=new task2();

       t.getRandom(list,minScore);
    }
}
