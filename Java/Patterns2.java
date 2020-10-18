/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package patterns2;

/**
 *
 * @author user
 */
public class Patterns2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("Pattern1");
        for(int i=1;i<=5;i++){
            for(int k=1;k<i;k++){
                System.out.print(" ");
            }
            for(int j=5;j>=i;j--){
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println("Pattern2");
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                if(i>j)
                    System.out.print(" ");
                else
                    System.out.print("*");
            }
            System.out.println();
        }
        System.out.println("Pattern3");
        for(int i=5;i>=1;i--){
            for(int k=1;k<i;k++){
                System.out.print(" ");
            }
            for(int j=5;j>=i;j--){
                System.out.print("*");
            }
            System.out.println();
        }
        
        System.out.println("Pattern4");
        for(int i=1;i<=5;i++){
            for(int k=5;k>i-1;k--){
                System.out.print(" ");
            }
            for(int j=1;j<2*i;j++){
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println("Pattern5");
        for(int i=1;i<=5;i++){
            for(int k=5;k>i;k--){
                System.out.print(" ");
            }
            for(int j=1;j<2*i;j++){
                System.out.print("*");
            }
            System.out.println();
        }
        for(int i=4;i>=1;i--){
            for(int j=4;j>=i;j--){
                System.out.print(" ");
            }
            for(int k=2*i;k>1;k--){
                System.out.print("*");
            }
            System.out.println();
        }
    }
    
}
