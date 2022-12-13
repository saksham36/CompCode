class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (n < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double pow = 1;
        double current_product = x;
        for (long long i = N; i; i /= 2)
        {
            cout << i << endl;
            if ((i % 2) == 1)
            {
                pow = pow * current_product;
            }
            current_product = current_product * current_product;
        }
        return pow;
    }
};
