// Java program to solve fractional Knapsack Problem  
import java.util.Comparator;  
import java.util.Arrays;  
// the greedy approach  
public class FractionalKnapSackExample  
{  
// method to get maximum value  
private static double getMaxValue(int[] w, int[] v, int c)  
{  
// length of the array  
int size = w.length;  
// array of storing all the items  
ItemValues[] iValue = new ItemValues[size];  
for (int j = 0; j < size; j++)   
{  
// storing the items  
iValue[j] = new ItemValues(w[j], v[j], j);  
}  
// sorting the items on the basis of cost  
Arrays.sort(iValue, new Comparator<ItemValues>()   
{  
@Override  
public int compare(ItemValues i1, ItemValues i2)  
{  
return i2.cost.compareTo(i1.cost);  
}  
});  
// contains the maximum value that is possible   
// for the given capacity of the knapsack  
double totalVal = 0d;  
for (int j = 0; j < size; j++)   
{  
// obtaining the current weight   
// and value of the ith item  
int currWt = (int)iValue[j].w;  
int currVal = (int)iValue[j].value;  
if (c - currWt >= 0)   
{  
// the current capacity of the knapsack allows the   
// item to be taken as a whole  
cc = c - currWt;  
totalValtotalVal = totalVal + currVal;  
}  
else   
{  
// when an item can not be picked as a whole  
// we break the item and take a portion of it   
// such that we get the maximum value in the knapsack  
double fraction = ((double)c / (double)currWt);  
totalValtotalVal = totalVal + (currVal * fraction);  
c = (int)(c - (currWt * fraction));  
// the knapsack is full   
// no need to proceed further  
break;  
}  
}  
return totalVal;  
}  
// Itemvalues class  
static class ItemValues   
{  
Double cost;  
double w, value, index;  
// item value function  
public ItemValues(int w, int value, int index)  
{  
this.w = w;  
this.value = value;  
this.index = index;  
// on the basis of cost   
// we sort the item  
cost = new Double((double)value / (double)w);  
}  
}  
// main method  
public static void main(String argvs[])  
{  
// input arrays  
int[] weight = { 40, 10, 20, 30 };  
int[] values = { 40, 60, 100, 120 };  
// capacity of the knapsack  
int C = 50;  
// invoking the getMaxValue() method          
double maxVal = getMaxValue(weight, values, C);  
// printing the result  
System.out.println("Maximum value that can be obtained is = " + maxVal);  
}  
}  
