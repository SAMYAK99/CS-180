package com.company;

public class rainWater_Trapping_Problem {
    public static int rainWater(int a[]){
        int n=a.length;
        int left[]=new int[n];
        int right[]=new int[n];
        left[0]=a[0];
        for (int i=1;i<n;i++){
            left[i]=Math.max(left[i-1],a[i]);
        }
        right[n-1]=a[n-1];
        for (int i=n-2;i>=0;i--){
            right[i]=Math.max(right[i+1],a[i]);
        }
        int ans=0;
        for (int i=0;i<n;i++){
            ans+=(Math.min(left[i],right[i])-a[i]);
        }
        return ans;
    }
    public static void main(String[] args) {
        int a[]={3,1,2,4,0,1,3,2};
        System.out.println(rainWater(a)+" Blocks are fill by water");
    }
}
