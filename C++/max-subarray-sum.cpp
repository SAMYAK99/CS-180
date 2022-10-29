int max_sum(int *vector, int len)
{
    int best = 0, curr = 0;
    int i = 0;
    for(i = 0; i < len; ++i)
    {
        current += *(vector + i);
        if(curr 0)
        {
            curr = 0;
        }
        best = best > curr ? best : curr;
    }
    return best;
}
