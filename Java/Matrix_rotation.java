public class RotateMatrix  
{  
  static void rightRotate(int matrix[][],int n)  
  {  
      for(int i=0;i<n;i++)  
      {  
          for(int j=i;j<n;j++)  
          {  
            int temp = matrix[i][j];  
            matrix[i][j] = matrix[j][i];  
            matrix[j][i] = temp;  
          }  
      }  
      for(int i=0;i<n;i++)  
      {    
        int low = 0, high = n-1;  
        while(low < high)  
        {  
            int temp = matrix[i][low];  
            matrix[i][low] = matrix[i][high];  
            matrix[i][high] = temp;  
            low++;  
            high--;  
        }  
      }  
  
System.out.println("The Right Rotated Matrix is: ");  
for(int i=0;i<3;i++)  
  {  
    for(int j=0;j<3;j++)  
    {  
      System.out.print(matrix[i][j]+" " +"\t");  
    }  
    System.out.println();  
  }  
}  
