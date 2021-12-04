/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This type header file contains a template for the Complex class.
*/
#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

class complex
{
public:
    double re, im;
    complex(){re = 0; im = 0;}
    complex(double re, double im){this->re = re; this->im = im;}
    complex (complex &c){re = c.re; im = c.im;}
    ~complex() {}
    void print();
    complex operator + (complex &c);
    complex operator - (complex &c);
    complex operator * (complex &c);
    complex operator * (int a);
    complex operator / (complex &c);
    complex operator / (int a);
    complex & operator = (complex);
    complex sqrt_complex(complex &c);
    friend std::istream& operator >>(std::istream&, complex&);
    friend std::ostream& operator << (std::ostream&, const complex&);
};

double *coefs_from_file(string filename);
void write_to_file(complex a, string filename);
complex sqrt_discriminant(complex &a, complex &b, complex &c);
void print_quadratic_eq(complex a, complex b, complex c);
void solution_quadratic_eq(complex a, complex b, complex c);
void to_file_solution_eq(complex &a, complex &b, complex &c, string filename);


#endif // COMPLEX_H_INCLUDED
