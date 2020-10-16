package com;
 
import java.util.Scanner;
 
public class HeapSortJava
{
    public static void main(String args[])
    {
    	int n, a[];
    	Scanner sc = new Scanner(System.in);
    	System.out.println("Enter number of elements:");
    	
    	n = sc.nextInt();
    	a = new int[n];
 
    	System.out.println("\nEnter the elements:");
    	for(int i = 0; i < n; ++i)
    		a[i] = sc.nextInt();
    	
    	new HeapSortJava().sort(a);
 
        System.out.println("\nSorted array is:");
        for(int i = 0; i < n; ++i)
        	System.out.print(a[i]+" ");
        
        sc.close();
    }
    
    public void sort(int a[])
    {
        int len = a.length - 1;
 
        for (int i = len/2; i >= 0; i--)
            heapify(a, len, i);
 
        for (int i = len; i >= 0; i--)
        {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
 
            heapify(a, i, 0);
        }
    }
 
    void heapify(int a[], int n, int i)
    {
        int max = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
 
        if (l < n && a[l] > a[max])
            max = l;
 
        if (r < n && a[r] > a[max])
            max = r;
 
        if (max != i)
        {
            int temp = a[i];
            a[i] = a[max];
            a[max] = temp;
 
            heapify(a, n, max);
        }
    }
}
