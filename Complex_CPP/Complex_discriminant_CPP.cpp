/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This file describes a method for finding the roots of a quadratic equation with complex coefficients using the built-in library <complex>.
*/
#include <iostream>
#include <complex>
#include <string>
#include <fstream>
using namespace std;

//A separate method for deriving a quadratic equation with complex coefficients
void print_quadratic(double a1, double b1, double a2, double b2, double a3, double b3)
{
    complex<double> a(a1, b1), b(a2, b2), c(a3,b3);
    cout << a << "x^2+" << b << "x+" << c << "=0" << endl;
}

//A method that outputs a solution to a quadratic equation
void solution_quadratic(double a1, double b1, double a2, double b2, double a3, double b3)
{
    complex<double> a(a1, b1), b(a2, b2), c(a3,b3);
    double re = (a*c).real() * 4;
    double im = (a*c).imag() * 4;
    complex<double> part_a(re, im), part_b;
    part_b = b*b - part_a;
    re = sqrt((sqrt((part_b.real()*part_b.real()) + (part_b.imag()*part_b.imag())) + part_b.real()) / 2.0);
    im = sqrt((sqrt((part_b.real()*part_b.real()) + (part_b.imag()*part_b.imag())) - part_b.real()) / 2.0);
    complex<double> d(re, im);
    re = a.real() * 2;
    im = a.imag() * 2;
    complex<double> x2(re, im), x1;
    x1 = (-b-d)/x2;
    x2 = (-b+d)/x2;
    cout << "X1 = " << x1 << endl << "X2 = " << x2 << endl;
}

//A method that writes the solution of a quadratic equation to a file
void to_file_solution(double a1, double b1, double a2, double b2, double a3, double b3, string filename)
{
    ofstream fout;
    complex<double> a(a1, b1), b(a2, b2), c(a3,b3);
    double re = (a*c).real() * 4;
    double im = (a*c).imag() * 4;
    complex<double> part_a(re, im), part_b;
    part_b = b*b - part_a;
    re = sqrt((sqrt((part_b.real()*part_b.real()) + (part_b.imag()*part_b.imag())) + part_b.real()) / 2.0);
    im = sqrt((sqrt((part_b.real()*part_b.real()) + (part_b.imag()*part_b.imag())) - part_b.real()) / 2.0);
    complex<double> d(re, im);
    re = a.real() * 2;
    im = a.imag() * 2;
    complex<double> x2(re, im), x1;
    x1 = (-b-d)/x2;
    x2 = (-b+d)/x2;
    fout.open(filename, std::ios::app);
    fout << a << "x^2+" << b << "x+" << c << "=0" << endl;
    fout << "Solutions" << endl << "X1 = " << x1 << endl << "X2 = " << x2 << endl;
    fout.close();
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

int main(){
    int mode_input, mode_output;
    double a1, b1, a2, b2, a3, b3;
    cout << "Choose the INPUT mode" << endl << "0 - Console" << endl << "1 - File" << endl << "Your choice: ";
    cin >> mode_input;
    cout << "Choose the OUTPUT mode" << endl << "0 - Console" << endl << "1 - File" << endl << "Your choice: ";
    cin >> mode_output;
    if (mode_input == 0){
        cout << "Enter fist complex coef of quadratic quadratic equation." << endl;
        cin >> a1 >> b1;
        cout << "Enter second complex coef of quadratic quadratic equation." << endl;
        cin >> a2 >> b2;
        cout << "Enter third complex coef of quadratic quadratic equation." << endl;
        cin >> a3 >> b3;
        if (mode_output == 0){
            print_quadratic(a1, b1, a2, b2, a3, b3);
            solution_quadratic(a1, b1, a2, b2, a3, b3);
        }
        else if (mode_output == 1){
             to_file_solution(a1, b1, a2, b2, a3, b3, "solution_qud.txt");
        }
    }
     else if (mode_input == 1){
        string filename;
        cout << "Input filename for first coef (recommend qud_eq_1.txt) : ";
        cin >> filename;
        double* coef1 = coefs_from_file(filename);
        a1 = coef1[0];
        b1 = coef1[1];
        cout << "Input filename for second coef (recommend qud_eq_2.txt) : ";
        cin >> filename;
        double* coef2 = coefs_from_file(filename);
        a2 = coef2[0];
        b2 = coef2[1];
        cout << "Input filename for third coef (recommend qud_eq_3.txt) : ";
        cin >> filename;
        double* coef3 = coefs_from_file(filename);
        a3 = coef3[0];
        b3 = coef3[1];
        if (mode_output == 0){
            print_quadratic(a1, b1, a2, b2, a3, b3);
            solution_quadratic(a1, b1, a2, b2, a3, b3);
        }
        else if (mode_output == 1){
             to_file_solution(a1, b1, a2, b2, a3, b3, "solution_qud.txt");
        }
    }
    //double a = 1, b = 0, a1 = -7, b1 = 2, a2 = 13, b2 = -13;
    //print_quadratic(a, b, a1, b1, a2, b2);
    //solution_quadratic(a, b, a1, b1, a2, b2);
    return 0;

}
