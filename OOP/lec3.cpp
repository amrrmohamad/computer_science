#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int num;
    int den;
    int gcd()
    {
        for (int i = min(num, den); i >= 1; i--)
        {
            if (num % i == 0 && den % i == 0)
            {
                return i;
            }
        }
    }

public:
    Fraction(int a = 0, int b = 1)
    {
        num = a;
        den = b;
    }
    // Getters and Setters
    int getnum()
    {
        return num;
    }
    int getden()
    {
        return den;
    }
    void setnum(int a)
    {
        num = a;
    }
    void setden(int b)
    {
        if (den != 0)
            den = b;
    }
    // Genral function
    void simplify()
    {
        int d = gcd();
        num = num / d;
        den = den / d;
    }

    Fraction addint(int a)
    {
        Fraction res;
        res.num = num + (den * a);
        res.den = den;
        res.simplify();
        return res;
    }

    Fraction add(Fraction t)
    {
        Fraction res;
        res.num = num * t.den + den * t.num;
        res.den = den * t.den;
        res.simplify();
        return (res);
    }

    Fraction operator+(Fraction t)
    {
        Fraction res;
        res.num = num * t.den + den * t.num;
        res.den = den * t.den;
        res.simplify();
        return (res);
    }

    Fraction operator-(Fraction t)
    {
        Fraction res;
        res.num = num * t.den - den * t.num;
        res.den = den * t.den;
        res.simplify();
        return (res);
    }

    void operator++()
    {
        num = num + den;
    }

    bool operator<=(Fraction t)
    {
        return (num * t.den <= den * t.num);
    }

    bool operator>=(Fraction t)
    {
        return (num * t.den >= den * t.num);
    }

    operator float()
    {
        return ((double)num / den);
    }

    float val()
    {
        return ((float)num / den);
    }
};

class Root
{
private:
    int x, p;

public:
    Root(int a = 1, int b = 1)
    {
        x = a;
        p = b;
    }
    // Getters and Setters
    int getx()
    {
        return x;
    }
    int getpow()
    {
        return p;
    }
    void setnum(int a)
    {
        x = a;
    }
    void setden(int b)
    {
        p = b;
    }
    // general function
    int val()
    {
        return pow(x, 1 / p);
    }
};

int main()
{
    Fraction f, e, g(1, 2), c(3, 2);
    f = g.addint(4);
    cout << f.getnum() << "  /  " << f.getden() << endl;

    e = g <= c;

    cout << e << endl;

    // f = g.add(c);
    // cout << f.getnum() << "  /  " << f.getden() << endl;

    f = g + c;
    cout << f.getnum() << "  /  " << f.getden() << endl;

    e = g - c;
    cout << e.getnum() << "  /  " << e.getden() << endl;

    ++f;
    cout << f.getnum() << "  /  " << f.getden() << endl;

    float d = f;
    cout << d << endl;

    Fraction *p[5];
    int x, y;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter num and den: \n";
        cin >> x >> y;
        p[i] = new Fraction(x, y);
    }
    cout << "The resulte is: \n";

    for (int i = 0; i < 5; i++)
    {
        cout << p[i]->val() << endl;
    }
    //=============================================

    Root *q[5];
    int z, w;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter to claculate root: (x, pow root)\n";
        cin >> z >> w;
        q[i] = new Root(z, w);
    }

    cout << "The resulte is: \n";

    for (int i = 0; i < 5; i++)
    {
        cout << q[i]->val() << endl;
    }
}