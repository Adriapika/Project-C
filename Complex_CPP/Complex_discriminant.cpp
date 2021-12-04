/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This file describes an algorithm for solving a quadratic equation with complex coefficients using the methods described in Complex.cpp.
With a choice of output and data input.
*/
#include "Complex.cpp"

int main(){
    complex a, b,c;
    int mode_input, mode_output;
    cout << "Choose the INPUT mode" << endl << "0 - Console" << endl << "1 - File" << endl << "Your choice: ";
    cin >> mode_input;
    cout << "Choose the OUTPUT mode" << endl << "0 - Console" << endl << "1 - File" << endl << "Your choice: ";
    cin >> mode_output;
    if (mode_input == 0){
        cout << endl << "Enter fist complex coef of quadratic quadratic equation." << endl;
        cin >> a;
        cout << endl << "Enter second complex coef of quadratic quadratic equation." << endl;
        cin >> b;
        cout << endl << "Enter third complex coef of quadratic quadratic equation." << endl;
        cin >> c;
        if (mode_output == 0){
            print_quadratic_eq(a, b, c);
            solution_quadratic_eq(a, b, c);
        }
        else if (mode_output == 1){
             to_file_solution_eq(a, b, c, "solution_qud_eq.txt");
        }
    }
    else if (mode_input == 1){
        string filename;
        cout << "Input filename for first coef (recommend qud_eq_1.txt) : ";
        cin >> filename;
        double* coef1 = coefs_from_file(filename);
        complex a(coef1[0], coef1[1]);
        cout << "Input filename for second coef (recommend qud_eq_2.txt) : ";
        cin >> filename;
        double* coef2 = coefs_from_file(filename);
        complex b(coef2[0], coef2[1]);
        cout << "Input filename for third coef (recommend qud_eq_3.txt) : ";
        cin >> filename;
        double* coef3 = coefs_from_file(filename);
        complex c(coef3[0], coef3[1]);
        if (mode_output == 0){
            print_quadratic_eq(a, b, c);
            solution_quadratic_eq(a, b, c);
        }
        else if (mode_output == 1){
             to_file_solution_eq(a, b, c, "solution_qud_eq.txt");
        }
    }

    //complex a(1, 0), b(-7, 2), c(13, -13);
    //print_quadratic_eq(a, b, c);
    //solution_quadratic_eq(a, b, c);
    return 0;
}
