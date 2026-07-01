#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

int eval_count = 0;
bool debug_mode = false;

double find_root(double (*f)(double), double a, double b)
{
    double f_a = f(a);
    double f_b = f(b);
    
    if (f_a * f_b > 0) 
    {
        return NAN;
    }
    
    double range = fabs(b - a);
    double epsilon = range / pow(2.0, 52);
    
    double c;
    int iteration = 0;
    
    while (true)
    {
        double old_a = a;
        double old_b = b;
        
        c = (a * f_b - b * f_a) / (f_b - f_a);
        double f_c = f(c);
        
        if (debug_mode) {
            //cout << "  Iteration " << ++iteration << ": c = " << setprecision(17) << c 
                 //<< ", f(c) = " << scientific << f_c << fixed << endl;
        }
        
        if (fabs(f_c) < epsilon)
            return c;
        
        if (fabs(b - a) < epsilon)
            return c;
        
        if (f_a * f_c < 0) {
            b = c;
            f_b = f_c;
        }
        else {
            a = c;
            f_a = f_c;
        }
        
        if (a == old_a && b == old_b)
            return c;
        
        eval_count++;
    }
    
}

double test_f1(double x) { return 7 - x*x; }
double test_f2(double x) { return 192 - 3*pow(x, 6); }
double test_f3(double x) { return 3 + 2*x - x*x; }
double test_f4(double x) { return sqrt(4 - x*x) - 1; }
double test_f5(double x) { return sin(x); }
double test_f6(double x) { return 2*x*x*x - 4*x*x + 3*x; }
double test_f7(double x) { return 2*x*x*x - 4*x*x + 3*x + 9; }
double test_f8(double x) { return log2(x) - sqrt(x)/100; }

struct TestCase {
    string name;
    double (*func)(double);
    double a;
    double b;
    double expected_root;
};

int main() {
    vector<TestCase> tests = {
        {"7-x^2", test_f1, 2, 3, sqrt(7)},
        {"7-x^2", test_f1, -0.5, 12, sqrt(7)},
        {"192-3x^6", test_f2, 1.6000000000000001, 2.2999999999999998, 2.0},
        {"192-3x^6", test_f2, -0.5, 12, 2.0},
        {"192-3x^6", test_f2, -11, 1.8999999999999999, -2.0},
        {"3+2x-x^2", test_f3, -0.5, 13, 3.0},
        {"3+2x-x^2", test_f3, -0.5, 1300000, 3.0},
        {"3+2x-x^2", test_f3, -1000000, 1, -1.0},
        {"sqrt(4-x^2)-1", test_f4, -2, 1, -sqrt(3)},
        {"sin(x)", test_f5, 4, 8, 6.28318530717958648},
        {"sin(x)", test_f5, 1, 5, 3.14159265358979312},
        {"2x^3-4x^2+3x", test_f6, -1, 1, 0.0},
        {"2x^3-4x^2+3x", test_f6, -2, 1, 0.0},
        {"log2(x)-sqrt(x)/100", test_f8, 0.25, 2, 1.00697986662473}
    };
    
    
    cout << "\n========== FALSE POSITION METHOD - 52 BIT PRECISION ==========\n";
    cout << "Tolerance: epsilon = range / 2^52\n\n";
    
    debug_mode = true;
    int total_evals = 0;
    int passed_tests = 0;
    
    for (size_t i = 0; i < tests.size(); i++) {
        eval_count = 0;
        
        double range = fabs(tests[i].b - tests[i].a);
        double epsilon = range / pow(2.0, 52);
        
        cout << "\nTest " << (i+1) << ": " << tests[i].name 
             << " on [" << tests[i].a << ", " << tests[i].b << "]" << endl;
        cout << "  epsilon = " << scientific << epsilon << fixed << endl;
        
        double result = find_root(tests[i].func, tests[i].a, tests[i].b);
        cout << "Root found:" << result << endl;
        
        double error = fabs(result - tests[i].expected_root);
        bool accurate = error < 1e-9;
        
        cout << "  Final result: " << setprecision(17) << result << endl;
        cout << "  Expected:     " << tests[i].expected_root << endl;
        cout << "  Error:        " << scientific << error << fixed << endl;
        cout << "  Evaluations:  " << eval_count << endl;
        
        if (!accurate) {
            cout << "  ⚠ WARNING: Error exceeds threshold!" << endl;
        }
        
        total_evals += eval_count;
        if (accurate) passed_tests++;
    }
    
    cout << "\n========== SUMMARY ==========\n";
    cout << "Total evaluations: " << total_evals << endl;
    cout << "Average evaluations: " << fixed << setprecision(2) 
         << (double)total_evals / tests.size() << endl;
    cout << "Tests passed: " << passed_tests << "/" << tests.size() << endl;
    cout << "========================================\n";
    
    return 0;
}