package com.company;

import java.util.ArrayList;

public class ZeroOneKnapsack {
    public static void main(String[] args){
        ArrayList<item> items = new ArrayList<>();
        items.add(new item(31, 1));
        items.add(new item(26, 1));
        items.add(new item(17, 1));
        items.add(new item(72, 1));

        int m = zeroOne(items, 3, 0);
        System.out.println(m);
    }
    public static int zeroOne(ArrayList<item>items, int capacity, int index){
        if (index>=items.size()){
            return 0;
        }
        else if(items.get(index).weight <= capacity){
            int p1 = items.get(index).profit + zeroOne(items, capacity - items.get(index).weight, index+1);
            int p2 = zeroOne(items, capacity, index+1);
            return Math.max(p1,p2);
        }
        else return 0;
    }
}
class item{
    int profit;
    int weight;
    public item(int profit, int weight){
        this.profit = profit;
        this.weight = weight;
    }
}
