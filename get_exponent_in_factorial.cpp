
int64_t get_exponent_in_factorial(int n, int p)
{
    int64_t exponent = 0;
    int64_t temp = p;

    while (temp <= n)
    {
        exponent += n / temp;
        if (n / temp < p)
        {
            break;
        }
        temp *= p;
    }
    return exponent;
}
