import java.util.Scanner;
public class BinarySearch 
{	
	int binarySearch(int arr[], int l, int r, int x)
	{//Function for Binary Searching
		if (r >= l){
			int mid = l + (r - l) / 2;
			if (arr[mid] == x){
				return mid;
            }
			if (arr[mid] > x){
				return binarySearch(arr, l, mid - 1, x);
            }
			return binarySearch(arr, mid + 1, r, x);
		}
		return -1;
	}
	
	public static void main(String args[])
	{//Main method for calling the binarySearch function
		Scanner sc=new Scanner(System.in);
		BinarySearch ob = new BinarySearch();//Creating an object
		int arr[] = { 2, 3, 4, 10, 40 };
		int n = arr.length;
		int x = sc.nextInt();
		int result = ob.binarySearch(arr, 0, n - 1, x);
		if (result == -1){
			System.out.println("Element not present");
        }
		else
		{
			System.out.println("Element found at index " + result);
        }
	}
}
