typedef array<int, K> base;

base make_empty()
{
    base b;
    for(int i = 0; i < K; i++)
        b[i] = 0;
    return b;
}
 
int reduce(const base& b, int x)
{
    for(int i = K - 1; i >= 0; i--)
        if(x & (1 << i))
            x ^= b[i];
    return x;
}   
 
bool add(base& b, int x)
{
    x = reduce(b, x);
    if(x != 0)
    {
        for(int i = K - 1; i >= 0; i--)
            if(x & (1 << i))
            {
                b[i] = x;
                return true;
            }
    }   
    return false;
}
 
bool check(const base& b, int x)
{
    return reduce(b, x) == 0;
}