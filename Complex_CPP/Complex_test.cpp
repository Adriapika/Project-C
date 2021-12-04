/*
Project Topic: Complex numbers C and C++
Group: Computer mathematics 2
Creator: Driapika Arsenii
In this file, I test all functions in three ways.
In Test1, I set complex numbers in the main code and check the work of all operators.
In test 2, complex numbers are entered from the console, and in test 3,
the coefficients are read from a given file and their results are displayed.
*/
#include "Complex.cpp"

int main()
{
    cout << "//////////////////////////////////////////////////////////////////" << endl;
    complex test1_a(15, 3);
    complex test1_b(13, -1);
    cout << "TEST 1 : by data entry in the main code." << endl << endl;
    cout << "Method test a.print() : "; test1_a.print();
    cout << "Method test b.print() : "; test1_b.print(); cout << endl;
    cout << "Reload Method '+' : " << test1_a + test1_b << endl;
    cout << "Reload Method '-' : " << test1_a - test1_b << endl;
    cout << "Reload Method '*' : " << test1_a * test1_b << endl;
    cout << "Reload Method '/' : " << test1_a / test1_b << endl;
    test1_a = test1_b;
    cout << "Reload Method '=' : " << test1_a << "=" << test1_b << endl;

    cout << "//////////////////////////////////////////////////////////////////" << endl;
    complex test2_a, test2_b;
    cout << endl << "TEST 2 : by data entry in console." << endl << endl;
    cout << "Input complex number 1 " << endl;
    cin >> test2_a;
    cout << "Method test a.print() : "; test2_a.print(); cout << endl;
    cout << "Input complex number 2 " << endl;
    cin >> test2_b;
    cout << "Method test b.print() : "; test2_b.print(); cout << endl;
    cout << "Reload Method '+' : " << test2_a + test2_b << endl;
    cout << "Reload Method '-' : " << test2_a - test2_b << endl;
    cout << "Reload Method '*' : " << test2_a * test2_b << endl;
    cout << "Reload Method '/' : " << test2_a / test2_b << endl;
    test2_a = test2_b;
    cout << "Reload Method '=' : " << test2_a << "=" << test2_b << endl;

    cout << "//////////////////////////////////////////////////////////////////" << endl;
    double* coefs_1 = coefs_from_file("coefs_1.txt");
    complex test3_a(coefs_1[0], coefs_1[1]);
    double* coefs_2 = coefs_from_file("coefs_2.txt");
    complex test3_b(coefs_2[0], coefs_2[1]);
    cout << endl << "TEST 3 : by data entry in file." << endl << endl;
    cout << "Method test a.print() : "; test3_a.print();
    cout << "Method test b.print() : "; test3_b.print(); cout << endl;
    cout << "Reload Method '+' : " << test3_a + test3_b << endl;
    cout << "Reload Method '-' : " << test3_a - test3_b << endl;
    cout << "Reload Method '*' : " << test3_a * test3_b << endl;
    cout << "Reload Method '/' : " << test3_a / test3_b << endl;
    cout << "//////////////////////////////////////////////////////////////////" << endl;
    write_to_file(test3_a, "result.txt");
    write_to_file(test3_b, "result.txt");
    write_to_file(test3_a + test3_b, "result.txt");
    write_to_file(test3_a - test3_b, "result.txt");
    write_to_file(test3_a * test3_b, "result.txt");
    write_to_file(test3_a / test3_b, "result.txt");
    return 0;
}
