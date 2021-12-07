/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This file describes a method for finding the roots of a qubic equation with natural coefficients using the built-in library <complex> by cardano method.
*/
#include <iostream>
#include <complex>
#include <string>
#include <fstream>
using namespace std;

//A separate method for deriving a qubic equation with complex coefficients
void print_qubic(double a, double b, double c, double d)
{
    cout << "(" << a << ")x^3+(" << b << ")x^2+(" << c << ")x+" << "("<< d << ")=0" << endl;
}

//A method that outputs a solution to a qubic equation
void solution_qubic_eq(double a, double b, double c, double d)
{
    double p = (3*a*c-b*b)/(3*a*a);
    double q = (2*b*b*b-9*a*b*c+27*a*a*d)/(27*a*a*a);
    double Q = (p/3)*(p/3)*(p/3) + (q/2)*(q/2);
    double alpha = cbrt(-q/2 + sqrt(Q));
    double beta = cbrt(-q/2 - sqrt(Q));
    double x = -b/3*a;;
    if (Q > 0){
        double x1 = alpha + beta;
        complex<double> x2((-(alpha+beta)/2)+x, (alpha-beta)/2*sqrt(3));
        complex<double> x3((-(alpha+beta)/2)+x, -(alpha-beta)/2*sqrt(3));
        cout << "X1 = " << x1 + x << endl;
        cout << "X2 = " << x2 << endl;
        cout << "X2 = " << x3 << endl;
    }
    if (Q < 0){
        double pfi;
        if(q<0)
            pfi = atan(sqrt(-Q)/(-q/2));
        else if (q>0)
            pfi = atan(sqrt(-Q)/(-q/2)) + M_PI;
        else
            pfi = M_PI/2;
        double x1 = 2*sqrt(-p/3)*cos(pfi / 3);
        double x2 = 2*sqrt(-p/3)*cos(pfi / 3 + 2*M_PI / 3);
        double x3 = 2*sqrt(-p/3)*cos(pfi / 3 + 4*M_PI / 3);
        cout << "X1 = " << x1 + x << endl;
        cout << "X2 = " << x2 + x << endl;
        cout << "X3 = " << x3 + x << endl;
    }
    if (Q == 0){
        double x1 = 2*cbrt(-q/2);
        double x2 = -1*cbrt(-q/2);
        cout << "X1 = " << x1 + x << endl;
        cout << "X2 = " << x2 + x << endl;
    }
}

//A method that writes the solution of a qubic equation to a file
void to_file_qubic_equation(double a, double b, double c, double d, string filename)
{
    ofstream fout;
    fout.open(filename, std::ios::app);
    fout << "(" << a << ")x^3+(" << b << ")x^2+(" << c << ")x+" << "("<< d << ")=0" << endl;
    double p = (3*a*c-b*b)/(3*a*a);
    double q = (2*b*b*b-9*a*b*c+27*a*a*d)/(27*a*a*a);
    double Q = (p/3)*(p/3)*(p/3) + (q/2)*(q/2);
    double alpha = cbrt(-q/2 + sqrt(Q));
    double beta = cbrt(-q/2 - sqrt(Q));
    double x = -b/3*a;;
    if (Q > 0){
        double x1 = alpha + beta+x;
        complex x2 ((-(alpha+beta)/2)+x, (alpha-beta)/2*sqrt(3));
        complex x3 ((-(alpha+beta)/2)+x, -(alpha-beta)/2*sqrt(3));
        fout << "Solutions" << endl << "X1 = " << x1 << endl << "X2 = " << x2 <<  endl << "X3 = " << x3 << endl;
    }
    if (Q < 0){
        double pfi;
        if(q<0)
            pfi = atan(sqrt(-Q)/(-q/2));
        else if (q>0)
            pfi = atan(sqrt(-Q)/(-q/2)) + M_PI;
        else
            pfi = M_PI/2;
        double x1 = 2*sqrt(-p/3)*cos(pfi / 3);
        double x2 = 2*sqrt(-p/3)*cos(pfi / 3 + 2*M_PI / 3);
        double x3 = 2*sqrt(-p/3)*cos(pfi / 3 + 4*M_PI / 3);
        x1 += x;
        x2 += x;
        x3 += x;
        fout << "Solutions" << endl << "X1 = " << x1 << endl << "X2 = " << x2 <<  endl << "X3 = " << x3 << endl;
    }
    if (Q == 0){
        double x1 = 2*cbrt(-q/2);
        double x2 = -1*cbrt(-q/2);
        x1 += x;
        x2 += x;
        fout << "Solutions" << endl << "X1 = " << x1 << endl << "X2 = " << x2 <<  endl;
    }
    fout.close();
}

//This method that gets four coefficients for equation
double *file_for_qubic_eq(string filename)
{
    ifstream finp;
    finp.open(filename);
    static double mas[4];
    for (int i = 0; i < 4; i++){
        double a;
        finp >> a;
        mas[i] = a;
    }
    finp.close();
    return mas;
}

int main(){
    int mode_input, mode_output;
    double a, b, c, d;
    cout << "Choose the INPUT mode" << endl << "0 - Console" << endl << "1 - File" << endl << "Your choice: ";
    cin >> mode_input;
    cout << "Choose the OUTPUT mode" << endl << "0 - Console" << endl << "1 - File" << endl << "Your choice: ";
    cin >> mode_output;
    if (mode_input == 0){
        cout << "Enter fist coef of qubic equation." << endl;
        cin >> a;
        cout << "Enter second coef of qubic equation." << endl;
        cin >> b;
        cout << "Enter third coef of qubic equation." << endl;
        cin >> c;
        cout << "Enter fourth coef of qubic equation." << endl;
        cin >> d;
        if (mode_output == 0){
            print_qubic(a, b, c, d);
            solution_qubic_eq(a, b, c, d);
        }
        else if (mode_output == 1){
             to_file_qubic_equation(a, b, c, d, "result_qubic_eq.txt");
        }
    }
    else if (mode_input == 1){
        string filename;
        cout << "Input filename for coefs (recommend coefs.txt) : ";
        cin >> filename;
        double* coefs  = file_for_qubic_eq(filename);
        a = coefs[0]; b = coefs[1]; c = coefs[2]; d = coefs[3];
        if (mode_output == 0){
            print_qubic(a, b, c, d);
            solution_qubic_eq(a, b, c, d);
        }
        else if (mode_output == 1){
             to_file_qubic_equation(a, b, c, d, "result_qubic_eq.txt");
        }
    }
    return 0;
}
