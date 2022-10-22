using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace sortQuick
{
    class quickSort
    {
 
        private int[] array = new int[20];
        private int len;
 
        public void QuickSort()
        {
            sort(0, len - 1);
        }
 
        public void sort(int left, int right)
        {
            int pivot, leftend, rightend;
 
            leftend = left;
            rightend = right;
            pivot = array[left];
 
            while (left < right)
            {
                while ((array[right] >= pivot) && (left < right))
                {
                    right--;
                }
 
                if (left != right)
                {
                    array[left] = array[right];
                    left++;
                }
 
                while ((array[left] <= pivot) && (left < right))
                {
                    left++;
                }
 
                if (left != right)
                {
                    array[right] = array[left];
                    right--;
                }
            }
 
            array[left] = pivot;
            pivot = left;
            left = leftend;
            right = rightend;
 
            if (left < pivot)
            {
                sort(left, pivot - 1);
            }
 
            if (right > pivot)
            {
                sort(pivot + 1, right);
            }
        }
 
        public static void Main()
        {
            quickSort q_Sort = new quickSort();
 
            int[] array = { 4, 3, 1, 4, 6, 7, 5, 4, 32, 5, 26, 187, 8 };
            q_Sort.array = array;
            q_Sort.len = q_Sort.array.Length;
            q_Sort.QuickSort();
 
            for (int j = 0; j < q_Sort.len; j++)
            {
                Console.WriteLine(q_Sort.array[j]);
            }
            Console.ReadKey();
        }
    }
}
