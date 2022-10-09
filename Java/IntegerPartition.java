import java.util.Scanner;
  
public class IntegerPartition 
{
    public static void main (String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scan.nextInt();
        System.out.printf("All unique integer partitions of %d are - \n", n);
        printAllPartitions(n);
        scan.close();
    }

    public static void printAllPartitions(int n)
    {
        int[] partitions = new int[n];
        int lastIndex = 0;
        partitions[lastIndex] = n;

        while (true)
        {
            for (int i = 0; i <= lastIndex; i++)
                System.out.print(partitions[i]+" ");
            System.out.println();

            int runningValue = 0;
            while (lastIndex >= 0 && partitions[lastIndex] == 1)
            {
                runningValue += partitions[lastIndex];
                lastIndex--;
            }

            if (lastIndex < 0)  return;

            partitions[lastIndex]--;
            runningValue++;

            while (runningValue > partitions[lastIndex])
            {
                partitions[lastIndex+1] = partitions[lastIndex];
                runningValue = runningValue - partitions[lastIndex];
                lastIndex++;
            }

            partitions[lastIndex+1] = runningValue;
            lastIndex++;
        }
    }
}