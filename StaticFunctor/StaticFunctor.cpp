#include <cstdlib>
#include <iostream>

using namespace std;

const int Nmax = 100;

class Polynomial
{
private:
    double a[Nmax];
    int power;
public:
    Polynomial(double* b, int n)
    {
        this->power = n;
        for (int i = 0; i <= this->power; i++)
            this->a[i] = b[i];
    }

    Polynomial(int n = 0)
    {
        this->power = n;
        for (int i = 0; i <= this->power; i++)
            this->a[i] = 0;
    }

    int getPower() { return this->power; }

    void coefs()
    {
        for (int i = 0; i <= this->power; i++)
            cout << this->a[i] << "\t";
        cout << endl;
    }

    double& operator[] (int k) { return this->a[k]; }

    double operator() (double x)
    {
        double s = 0, q = 1;
        for (int i = 0; i <= this->power; i++)
        {
            s += this->a[i] * q;
            q *= x;
        }
        return s;
    }

    Polynomial operator* (Polynomial P)
    {
        int n = P.getPower();
        int m = this->power + n;
        Polynomial t(m);
        for (int i = 0; i <= this->power; i++)
            for (int j = 0; j <= n; j++)
                t[i + j] += this->a[i] * P[j];
        return t;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(2014);
    const int n = 2;
    double nums[n + 1] = { 3,-2,1 };
    cout << "Полиномы\n";
    Polynomial P(nums, n);
    cout << "P: ";
    P.coefs();
    Polynomial Q(n + 1);
    //cout << "Q: ";
    //Q.coefs();
    for (int i = 0; i <= n + 1; i++)
        Q[i] = double(rand() % 5) - 2.;
    cout << "Q: ";
    Q.coefs();
    Polynomial R;
    R = P * Q;
    cout << "R: ";
    R.coefs();
    cout << "Значения полиномов\n";
    double x = -2, dx = 1;
    for (int k = 1; k <= 5; k++)
    {
        cout << "P(" << x << ") = " << P(x) << "\t";
        cout << "Q(" << x << ") = " << Q(x) << "\t";
        cout << "R(" << x << ") = " << R(x) << endl;
        x += dx;
    }
    return 0;
}