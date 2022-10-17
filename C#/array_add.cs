public static int[] AddArrays(int[] a, int[] b)
{
    int[] newArray = new int[a.Length];
    for (int i = 0; i<a.Length; i++)
    {
        newArray[i]=a[i]+b[i];
    }
    return newArray;
}
