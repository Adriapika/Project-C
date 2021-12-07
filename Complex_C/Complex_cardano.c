/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This file describes a method for finding the roots of a qubic equation with natural coefficients using the built-in library <complex> by cardano method.
*/
#include <stdio.h>
#include <complex.h>
#include <tgmath.h>
#define M_PI  3.14159265358979323846  /* pi */
#define N 100

//A separate method for deriving a qubic equation with complex coefficients
void print_equation(double a, double b, double c, double d)
{
    printf("(%.1lf)x^3 + (%.1lf)x^2 + (%.1lf)x + (%.1lf) = 0\n", a, b, c, d);
}

//A method that outputs a solution to a qubic equation
void solution(double a, double b, double c, double d)
{
    double p = (3*a*c-b*b)/(3*a*a);
    double q = (2*b*b*b-9*a*b*c+27*a*a*d)/(27*a*a*a);
    double Q = (p/3)*(p/3)*(p/3) + (q/2)*(q/2);
    double alpha = cbrt(-q/2 + sqrt(Q));
    double beta = cbrt(-q/2 - sqrt(Q));
    if (Q > 0){
        double x1 = alpha + beta;
        double complex x2 = -(alpha+beta)/2 + ((alpha-beta)/2*sqrt(3))*I;
        double complex x3 = -(alpha+beta)/2 - ((alpha-beta)/2*sqrt(3))*I;
        double x = -b/3*a;
        printf("x1 = %lf\n", x1+x);
        printf("x2 = %lf + (%lf)i\n", creal(x2) + x, cimag(x2));
        printf("x3 = %lf + (%lf)i", creal(x3) + x, cimag(x3));
    }
    if (Q < 0){
        double pfi;
        if(q<0){
            pfi = atan(sqrt(-Q)/(-q/2));
        }
        else if (q>0){
            pfi = atan(sqrt(-Q)/(-q/2)) + M_PI;
        }
        else{
            pfi = M_PI/2;
        }
        double x1 = 2*sqrt(-p/3)*cos(pfi / 3);
        double x2 = 2*sqrt(-p/3)*cos(pfi / 3 + 2*M_PI / 3);
        double x3 = 2*sqrt(-p/3)*cos(pfi / 3 + 4*M_PI / 3);
        double x = -b/3*a;
        printf("x1 = %lf\n", x1+x);
        printf("x2 = %lf\n", x2+x);
        printf("x3 = %lf\n", x3+x);
    }
    if (Q == 0){
        double x1 = 2*cbrt(-q/2);
        double x2 = -1*cbrt(-q/2);
        double x = -b/3*a;
        printf("x1 = %lf\n", x1+x);
        printf("x2 = %lf\n", x2+x);
    }
}

//A method that writes the solution of a qubic equation to a file
void print_solution_t_file(double a, double b, double c, double d, char filename[N])
{
    FILE *fout;
    fout = fopen(filename, "w");
    double p = (3*a*c-b*b)/(3*a*a);
    double q = (2*b*b*b-9*a*b*c+27*a*a*d)/(27*a*a*a);
    double Q = (p/3)*(p/3)*(p/3) + (q/2)*(q/2);
    double alpha = cbrt(-q/2 + sqrt(Q));
    double beta = cbrt(-q/2 - sqrt(Q));
    if (Q > 0){
        double x1 = alpha + beta;
        double complex x2 = -(alpha+beta)/2 + ((alpha-beta)/2*sqrt(3))*I;
        double complex x3 = -(alpha+beta)/2 - ((alpha-beta)/2*sqrt(3))*I;
        double x = -b/3*a;
        fprintf(fout, "x1 = %lf\n", x1+x);
        fprintf(fout, "x2 = %lf + (%lf)i\n", creal(x2) + x, cimag(x2));
        fprintf(fout, "x3 = %lf + (%lf)i", creal(x3) + x, cimag(x3));
    }
    if (Q < 0){
        double pfi;
        if(q<0){
            pfi = atan(sqrt(-Q)/(-q/2));
        }
        else if (q>0){
            pfi = atan(sqrt(-Q)/(-q/2)) + M_PI;
        }
        else{
            pfi = M_PI/2;
        }
        double x1 = 2*sqrt(-p/3)*cos(pfi / 3);
        double x2 = 2*sqrt(-p/3)*cos(pfi / 3 + 2*M_PI / 3);
        double x3 = 2*sqrt(-p/3)*cos(pfi / 3 + 4*M_PI / 3);
        double x = -b/3*a;
        fprintf(fout, "x1 = %lf\n", x1+x);
        fprintf(fout, "x2 = %lf\n", x2+x);
        fprintf(fout, "x3 = %lf\n", x2+x);
    }
    if (Q == 0){
        double x1 = 2*cbrt(-q/2);
        double x2 = -1*cbrt(-q/2);
        double x = -b/3*a;
        fprintf(fout, "x1 = %lf\n", x1+x);
        fprintf(fout, "x2 = %lf\n", x2+x);
    }
    fclose(fout);
}

//This method that gets four coefficients for equation
double *coefs_f_file(char filename[N])
{
    FILE *fin;
    fin = fopen(filename, "r");
    double a, b, c, d;
    static double mas[4];
    fscanf(fin,"%lf%lf%lf%lf", &a, &b, &c, &d);
    mas[0] = a; mas[1] = b; mas[2] = c; mas[3] = d;
    fclose(fin);
    return mas;
}

int main()
{
    int mode_input, mode_output;
    double a, b, c, d;
    printf("Choose the INPUT mode\n0 - Console\n1 - File\nYour choice: ");
    scanf("%d", &mode_input);
    printf("Choose the OUTPUT mode\n0 - Console\n1 - File\nYour choice: ");
    scanf("%d", &mode_output);
    if (mode_input == 0){
        printf("Enter fist coef of quadratic equation.\n");
        scanf("%lf", &a);
        printf("Enter second coef of quadratic equation.\n");
        scanf("%lf", &b);
        printf("Enter third coef of quadratic equation.\n");
        scanf("%lf", &c);
        printf("Enter fourth coef of quadratic equation.\n");
        scanf("%lf", &d);
        if (mode_output == 0){
            print_equation(a, b, c, d);
            solution(a, b, c, d);
        }
        else if (mode_output == 1){
             print_solution_t_file(a, b, c, d, "result1.txt");
        }
    }
    else if (mode_input == 1){
        char filename[N];
        printf("Input filename for coefs (recommend coefs.txt) : ");
        scanf("%99s", filename);
        double* coefs = coefs_f_file(filename);
        a = coefs[0]; b = coefs[1]; c = coefs[2]; d = coefs[3];
        if (mode_output == 0){
            print_equation(a, b, c, d);
            solution(a, b, c, d);
        }
        else if (mode_output == 1){
             print_solution_t_file(a, b, c, d, "result1.txt");
        }
    }
    return 0;
}
