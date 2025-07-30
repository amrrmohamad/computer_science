#include <iostream>
#include <string>
#include <cmath>


using namespace std;

class rect
{
    private:
        float len;
        float wid;

    public:
        rect(){len = 0; wid = 0;}
        rect(float a, float b){
            len = a;
            wid = b;}
        float area(){ return (len * wid);}
        void setlen(float h)
        {
            len = h;
        }
        void setwid(float g)
        {
            wid = g;
        }
        float getlen()
        {
            return (len);
        }
        float getwid()
        {
            return (wid);
        }
};

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// 2d_point
class point
{
    private:
        float xcoord, ycoord;

    public:
        point()
        {
            xcoord = ycoord = 0;
        }
        point(float a, float b)
        {
            xcoord = a;
            ycoord = b;
        }
        void setx(float h)
        {
            xcoord = h;
        }
        void sety(float g)
        {
            ycoord = g;
        }
        float getx()
        {
            return (xcoord);
        }
        float gety()
        {
            return (ycoord);
        }
        float sumcoord()
        {
            return (xcoord + ycoord);
        }
        void scale(float f)
        {
            xcoord = f * xcoord;
            ycoord *= f;
        }
        point addpoint(point t)
        {
            point res;
            res.xcoord = t.xcoord + xcoord;
            res.ycoord = t.ycoord + ycoord;
            return (res);
        //cuz addpoint &t in the same class then we can use t.xcoord or t.getx
        }
        float distance(point p)
        {
            return (sqrt(pow(p.xcoord - xcoord, 2) + pow(p.ycoord - ycoord, 2)));
        }
        void Quartile()
        {
            if (xcoord >= 0 && ycoord >= 0)
                cout << "first qurtile \n";
            else if (xcoord >= 0 && ycoord < 0)
                cout << "4th qurtile \n";
        }
};

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  -- -- -- -- -- -- -- -- -- -- -- -

class fraction
{
    private:
        int num;
        int den;
        int gcd()
        {
            //function for gcd
            return 0;
        }

    public:
        fraction(int a, int b)
        {
            num = a;
            if (b != 0)
                den = b;
            else
                den = 1;
        }
        fraction()
        {
            num = 0;
            den = 1;
        }
        void setnum(float h)
        {
            num = h;
        }
        void setden(float g)
        {
            if (g != 0)
                den = g;
            else
                den = 1;
        }
        int getnum()
        {
            return (num);
        }
        int getden()
        {
            return (den);
        }
        void mulbyint(int g)
        {
            num = num * g;
        }
        float value()
        {
            return (1.0 * num / den);
        }
        fraction add(fraction t)
        {
            fraction res;
            res.num = num * t.den + den * t.num;
            res.den = den * t.den;
            return (res);
        }
        void simplify()
        {
            int gcd, min;
            if (num < den)
                min = num;
            else
                min = den;
            for (int i = min; i >= 1; i++)
            {
                if (num % i == 0 && den % i == 0)
                {
                    gcd = i;
                    break;
                }
                num = num / gcd;
                den = den / gcd;
            }
        }
        string data()
        {
            return ("num = " + to_string(num) + "and den = " + to_string(den));
        }
        //to_string(den) in(#include<string>)convert numbers to string.
        fraction div(fraction t)
        {
            fraction res;
            res.num = num * t.den;
            res.den = den * t.num;
        }
};

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -class cx
class Complex {
    private:
        float re;
        float im;

    public:
        Complex()
        {
            re = 0;
            im = 0;
        }
        Complex(float x, float y)
        {
            re = x;
            im = y;
        }
        void setre(float h)
        {
            re = h;
        }
        void setim(float g)
        {
            im = g;
        }
        int getre()
        {
            return (re);
        }
        int getim()
        {
            return (im);
        }
        float abs()
        {
            return (sqrt(pow(re, 2) + pow(im, 2)));
        }
        float arg()
        {
            return (atan(im / re));
        }
        Complex add(Complex t)
        {
            Complex res;
            res.re = re + t.re;
            res.im = im + t.im;
            return (res);
        }
        Complex sub(Complex t)
        {
            Complex res;
            res.re = re - t.re;
            res.im = im - t.im;
            return (res);
        }
        Complex mul(Complex t)
        {
        }
        Complex div(Complex t)
        {
            Complex res;
            res.re = (re * t.re + im * t.im) / (pow(t.re, 2) + pow(t.im, 2));
            res.im = (re * t.im + t.re * im) / (pow(t.re, 2) + pow(t.im, 2));
            return(res);
        }
};

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

/*
aggregation
circle has a center center is a class of type point and it is a one of its
data
(center we can use it in any thing else)
------------------------------------------------
composition
car consists of (not has a) motor we can not use the motor only (not have any
mean)
inheritance
student of physics&mathimatics is a student of computer scince
*/
class circle
{
private:
    float rad;
    point center;

public:
    void setcenter(point c)
    {
        c = center;
    }
    void setrad(float r)
    {
        r = rad;
    }
    point getcenter()
    {
        return (center);
    }
    float getrad()
    {
        return (rad);
    }
    circle(float h, point t) //(M.A.I said): we can use that circle(float h, float x, float y) : point(x, y)
    {
        rad = h;
        center = t;
    }

    float area()
    {
        return (3.14 * rad * rad);
    }

    void relation(circle t)
    {
        float d = center.distance(t.center);
        if (d > rad + t.rad)
            cout << "far";
        else if (d < rad + t.rad)
            cout << "near";
        else
            cout << "same";
    }
};


//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// class cylinder 
// {
//     private:
//         float hight;
//         circle base;

//     public:
//         cylinder(float h, circle t)
//         {
//             h = hight;
//             t = base;
//         }
//         void setbase(circle c)
//         {
//             c = base;
//         }
//         void sethight(float h)
//         {
//             h = hight;
//         }
//         circle getbase()
//         {
//             return (base);
//         }
//         float gethight()
//         {
//             return (hight);
//         }
//         float volume()
//         {
//             return (3.14 * hight * base.getrad() * base.getrad());
//         }
// };

int main()
{
    //====================================
    point v3(5, 7);
    point t(10, 20);
    circle c1(10, v3);
    circle c2(3, t);
    cout << c1.getcenter().distance(c2.getcenter()); // the distance between c1,c2. H.W complex
    //====================================
    Complex z1(2, 3), z2(5, 8), z;
    z = z1.add(z2);
    //====================================
    fraction f(5, 7);
    fraction g(4, 9);
    f.mulbyint(20);
    fraction q;
    if (g.getnum() != 0)
    {
        q = f.div(g);
        cout << q.data();
    }
    else
        cout << "DIV BY ZERO!!!";
    //====================================
    point p(5, 7);
    point j(6, 8);
    point h;
    cout << p.sumcoord();
    h = p.addpoint(j);
    //=====================================
    rect t1(5, 7);
    rect v;
    cout << t1.area();
    v = t1;
    v.setlen(20);
    v.setwid(10);
    float res = v.area();
    //======================================
    // cylinder v1(5, c1), v2(10, c2);
    // cout << v1.getbase().getcenter().distance(v2.getbase().getcenter()); // the dicetance between two cylinder.
}
//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
