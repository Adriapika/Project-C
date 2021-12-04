/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This file contains a description of the functions written in "Complex.h"
*/
#include "Complex.h"

//Separate method for outputting a complex number
void complex :: print()
{
    if(im < 0)
      if(im == -1)
         cout << re << "-i" << endl;
      else
         cout << re << im << "i" << endl;
      else
         if(im == 1)
            cout << re << "+i"<< endl;
         else
            cout << re << "+" << im << "i" <<endl;
}

//Operator + overloading
complex complex :: operator + (complex &c)
{
    complex res;
    res.re = re + c.re;
    res.im = im + c.im;
    return res;
}

//Operator - overloading
complex complex :: operator - (complex &c)
{
    complex res;
    res.re = re - c.re;
    res.im = im - c.im;
    return res;
}

//Operator * overloading
complex complex :: operator * (complex &c)
{
    complex res;
    res.re = re * c.re - im * c.im;
    res.im = re * c.im + c.re * im;
    return res;
}

//Operator * (on integer) overloading
complex complex :: operator * (int a)
{
    complex res;
    res.re = a*re;
    res.im = a*im;
    return res;
}

//Operator / overloading
complex complex :: operator / (complex &c)
{
    complex res;
    res.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
    res.im = (c.re * im - re * c.im) / (c.re * c.re + c.im * c.im);
    return res;
}

//Operator / (on integer) overloading
complex complex :: operator / (int a)
{
    complex res;
    res.re = re/a;
    res.im = im/a;
    return res;
}

//Operator = overloading
complex& complex :: operator = (complex c)
{
    re = c.re;
    im = c.im;
    return *this;
}

//Operator << overloading
ostream &operator<<(ostream &out, const complex &c)
{
    out << c.re;
    if (c.im != 0){
        if( c.im > 0 )
            out << "+";
        out << c.im << "i";
    }
    return out;
}

//Operator >> overloading
istream &operator >> (istream& in, complex& c)
{
    cout << "Input real part : ";
    in >> c.re;
    cout << "Input imaginary part : ";
    in >> c.im;
    return in;
}

//This method that gets two coefficients for a complex number in a file
double *coefs_from_file(string filename)
{
    ifstream finp;
    finp.open(filename);
    static double mas[2];
    for (int i = 0; i < 2; i++){
        double a;
        finp >> a;
        mas[i] = a;
    }
    finp.close();
    return mas;
}

//This method writes a complex number to a file
void write_to_file(complex a, string filename)
{
    ofstream fout;
    fout.open(filename, std::ios::app);
    fout << a << endl;
    fout.close();
}

//Method for finding the square root of the discriminant for complex numbers
complex sqrt_discriminant(complex &a, complex &b, complex &c)
{
    complex part_a = (b * b);
    complex part_b = (a * c)*4;
    complex disr = part_a - part_b;
    complex res;
    res.re = sqrt((sqrt((disr.re*disr.re) + (disr.im*disr.im)) + disr.re)/2);
    res.im = sqrt((sqrt((disr.re*disr.re) + (disr.im*disr.im)) - disr.re)/2);
    return res;
}

//A separate method for deriving a quadratic equation with complex coefficients
void print_quadratic_eq(complex a, complex b, complex c)
{
    cout << "(" << a << ")" << "x^2+" << "(" << b << ")x+" << "(" << c << ")" << "=0" << endl;
}

//A method that outputs a solution to a quadratic equation
void solution_quadratic_eq(complex a, complex b, complex c)
{
    static complex res;
    complex d = sqrt_discriminant(a, b, c);
    complex x1, x2;
    x2 = a*2;
    x1 = (b*(-1) - d) / x2;
    x2 = (b*(-1) + d) / x2;
    cout << "X1 = " << x1 << endl << "X2 = " << x2 << endl;
}

//A method that writes the solution of a quadratic equation to a file
void to_file_solution_eq(complex &a, complex &b, complex &c, string filename)
{
    ofstream fout;
    complex x1, x2, d;
    d = sqrt_discriminant(a, b, c);
    x2 = a*2;
    x1 = (b*(-1) - d) / x2;
    x2 = (b*(-1) + d) / x2;
    fout.open(filename, std::ios::app);
    fout << "(" << a << ")" << "x^2+" << "(" << b << ")x+" << "(" << c << ")" << "=0" << endl;
    fout << "Solutions" << endl << "X1 = " << x1 << endl << "X2 = " << x2 << endl;
    fout.close();
}
