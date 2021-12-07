/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
This file describes an algorithm for solving a qubic equation with natural coefficients using the cardano method and Complex.cpp.
With a choice of output and data input.
*/
#include "Complex.cpp"

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
            print_qubic_equation(a, b, c, d);
            solution_qubic_equation(a, b, c, d);
        }
        else if (mode_output == 1){
             to_file_solution_qubic_equation(a, b, c, d, "result_qubic_eq.txt");
        }
    }
    else if (mode_input == 1){
        string filename;
        cout << "Input filename for coefs (recommend coefs.txt) : ";
        cin >> filename;
        double* coefs  = coefs_f_file_for_qubic_eq(filename);
        a = coefs[0]; b = coefs[1]; c = coefs[2]; d = coefs[3];
        if (mode_output == 0){
            print_qubic_equation(a, b, c, d);
            solution_qubic_equation(a, b, c, d);
        }
        else if (mode_output == 1){
             to_file_solution_qubic_equation(a, b, c, d, "result_qubic_eq.txt");
        }
    }
    return 0;
}
