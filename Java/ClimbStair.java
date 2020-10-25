import java.io.*;
import java.util.*;

public class Main{

public static void main(String[] args) throws Exception {
    // write your code here
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    System.out.print(stairPaths(n,new int[n+1]));
 }
public static int stairPaths(int n,int[] paths){
    if(n==0 ){
        return 1;
    }else if(n<0){
        return 0;
    }
    if(paths[n] != 0){
        return paths[n];
    }
    int path1 = stairPaths(n-1,paths);
    int path2 = stairPaths(n-2,paths);
    int path3 = stairPaths(n-3,paths);
    int total = path1+path2+path3;
    paths[n]=total;
    return total;
}
}
