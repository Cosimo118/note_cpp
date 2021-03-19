#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;
complex& __doapl(complex* ths, const complex& r);
complex& __doami(complex* ths, const complex& r);
complex& __doaml(complex* ths, const complex& r);

class complex
{
public:
    complex(double r=0,double i=0): re(r), im(i) {}
    complex& operator += (const complex&);
    complex& operator -= (const complex&);
    complex& operator *= (const complex&);
    complex& operator /= (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re,im;

    friend complex& __doapl(complex*, const complex&);//这里没有参数名了
    friend complex& __doami(complex*, const complex&);
    friend complex& __doaml(complex*, const complex&);
};

inline complex&
__doapl(complex* ths, const complex& r)//这里为啥又变*了，因为这里传进来的是this
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator +=(const complex& r)
{
    return __doapl(this,r);
}


#endif  //__MYCOMPLEX__