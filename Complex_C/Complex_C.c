/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This file describes a method for finding the roots of a quadratic equation with complex coefficients using the built-in library <complex.h> and <tgmath.h>.
*/
#include <stdio.h>
#include <complex.h>
#include <tgmath.h>
#define N 100

//Complex number input method from console
double complex create_comp()
{
    double a, b;
    printf("Input real part : ");
    scanf("%lf", &a);
    printf("Input imaginary part : ");
    scanf("%lf", &b);
    double complex z = a+b*I;
    printf("\n");
    return z;
}

//A separate method for deriving a quadratic equation with complex coefficients
void print_eq(double complex a, double complex b, double complex c)
{
    printf("(%.1lf+%.1lfi)x^2+(%.1lf+%.1lfi)x+(%.1lf+%.1lfi)=0\n", creal(a), cimag(a), creal(b), cimag(b), creal(c), cimag(c));
}

//A method that outputs a solution to a quadratic equation
void solution(double complex a, double complex b, double complex c)
{
    double complex d, x1, x2;
    d = b*b - 4*a*c;
    double re, im;
    re = sqrt((sqrt((creal(d)*creal(d)) + (cimag(d)*cimag(d))) + creal(d))/2);
    im = sqrt((sqrt((creal(d)*creal(d)) + (cimag(d)*cimag(d))) - creal(d))/2);
    double complex disc = re + im*I;
    x1 = (-b-disc)/ (a*2);
    x2 = (-b+disc) / (a*2);
    printf("Solutions:\n(%.1lf)+(%.1lfi) \n(%.1lf)+(%.1lfi)\n", creal(x1), cimag(x1), creal(x2), cimag(x2));
}

//This method that gets two coefficients for a complex number in a file
double complex coefs_f_file(char filename[N])
{
    FILE *fin;
    fin = fopen(filename, "r");
    double a, b;
    fscanf(fin,"%lf%lf", &a, &b);
    fclose(fin);
    double complex c = a+b*I;
    return c;
}

//A method that writes the solution of a quadratic equation to a file
void print_solution_t_file(double complex a, double complex b, double complex c, char filename[N])
{
    FILE *fout;
    fout = fopen(filename, "w");
    double complex d, x1, x2;
    d = b*b - 4*a*c;
    double re, im;
    re = sqrt((sqrt((creal(d)*creal(d)) + (cimag(d)*cimag(d))) + creal(d))/2);
    im = sqrt((sqrt((creal(d)*creal(d)) + (cimag(d)*cimag(d))) - creal(d))/2);
    double complex disc = re + im*I;
    x1 = (-b-disc)/ (a*2);
    x2 = (-b+disc) / (a*2);
    fprintf(fout,"(%.1lf+%.1lfi)x^2+(%.1lf+%.1lfi)x+(%.1lf+%.1lfi)=0\n", creal(a), cimag(a), creal(b), cimag(b), creal(c), cimag(c));
    fprintf(fout,"Solutions:\n(%.1lf)+(%.1lfi) \n(%.1lf)+(%.1lfi)\n", creal(x1), cimag(x1), creal(x2), cimag(x2));
    fclose(fout);
}

int main()
{
    /*
    int mode_input, mode_output;
    printf("Choose the INPUT mode\n0 - Console\n1 - File\nYour choice: ");
    scanf("%d", &mode_input);
    printf("Choose the OUTPUT mode\n0 - Console\n1 - File\nYour choice: ");
    scanf("%d", &mode_output);
    if (mode_input == 0){
        printf("Enter fist complex coef of quadratic quadratic equation.\n");
        double complex a = create_comp();
        printf("Enter second complex coef of quadratic quadratic equation.\n");
        double complex b = create_comp();
        printf("Enter third complex coef of quadratic quadratic equation.\n");
        double complex c = create_comp();
        if (mode_output == 0){
            print_eq(a, b, c);
            solution(a, b, c);
        }
        else if (mode_output == 1){
             print_solution_t_file(a, b, c, "result.txt");
        }
    }
    else if (mode_input == 1){
        char filename[N];
        printf("Input filename for second coef (recommend qud_eq_1.txt) : ");
        scanf("%99s", filename);
        double complex a = coefs_f_file(filename);
        printf("Input filename for second coef (recommend qud_eq_2.txt) : ");
        scanf("%99s", filename);
        double complex b = coefs_f_file(filename);
        printf("Input filename for second coef (recommend qud_eq_3.txt) : ");
        scanf("%99s", filename);
        double complex c = coefs_f_file(filename);
        if (mode_output == 0){
            print_eq(a, b, c);
            solution(a, b, c);
        }
        else if (mode_output == 1){
             print_solution_t_file(a, b, c, "result.txt");
        }
    }
    */
    double complex a = 1 + 0*I, b = -7 + 2*I, c = 13 -13*I;
    print_eq(a, b, c);
    solution(a, b, c);
    return 0;
}
