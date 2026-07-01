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

double find_root(double (*f)(double), double a, double b, double TOLERANCE)
{
    double f_a = f(a);
    eval_count++;
    double f_b = f(b);
    eval_count++;
    
    if (f_a * f_b > 0) 
    {
        return NAN;
    }
    
    int max_iterations = (int)ceil(log2((b - a) / TOLERANCE));
    
    double midpoint;
    
    for (int i = 0; i < max_iterations; i++)
    {
        midpoint = (a + b) / 2.0;
        double f_mid = f(midpoint);
        eval_count++;
        
        if (fabs(f_mid) < TOLERANCE)
            return midpoint;
        
        if (f_a * f_mid < 0) {
            b = midpoint;
            // Don't store f_b - we never use it
        }
        else {
            a = midpoint;
            f_a = f_mid;  // Only update f_a when needed
        }
    }
    
    midpoint = (a + b) / 2.0;
    
    double rounded = round(midpoint);
    if (fabs(midpoint - rounded) < 1e-10) {
        double f_rounded = f(rounded);
        eval_count++;
        if (fabs(f_rounded) < 1e-10)
            return rounded;
    }
    
    return midpoint;
}

// Test functions
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
        {"7-x^2", test_f1, 2, 3, sqrt(7)},  // ~2.6457513
        {"7-x^2", test_f1, -0.5, 12, sqrt(7)},  // ~2.6457513
        {"192-3x^6", test_f2, 1.6000000000000001, 2.2999999999999998, 2.0},
        {"192-3x^6", test_f2, -0.5, 12, 2.0},
        {"192-3x^6", test_f2, -11, 1.8999999999999999, -2.0},
        {"3+2x-x^2", test_f3, -0.5, 13, 3.0},
        {"3+2x-x^2", test_f3, -0.5, 1300000, 3.0},
        {"3+2x-x^2", test_f3, -1000000, 1, -1.0},
        {"sqrt(4-x^2)-1", test_f4, -2, 1, -sqrt(3)},  // Changed: root is at -sqrt(3) in [-2,1]
        {"sin(x)", test_f5, 4, 8, 6.28318530717958648},  // 2*pi
        {"sin(x)", test_f5, 1, 5, 3.14159265358979312},  // pi
        {"2x^3-4x^2+3x", test_f6, -1, 1, 0.0},
        {"2x^3-4x^2+3x", test_f6, -2, 1, 0.0},
        // {"2x^3-4x^2+3x+9", test_f7, -1.5, 1, -1.90416396221094},  // Changed: actual root
        {"log2(x)-sqrt(x)/100", test_f8, 0.25, 2, 1.00697986662473},  // Changed: actual root
       // {"log2(x)-sqrt(x)/100", test_f8, 2, 10000000000.0, 4944993.59185819514}  // Changed: actual root
       {"log2(sin(x)*8)+13*100000, test_f9, -10000, "}
    };
    
    vector<double> tolerances = {1e-13, 1e-14, 1e-15, 1e-16};
    
    cout << "\n========== TOLERANCE PERFORMANCE COMPARISON ==========\n\n";
    
    for (double tol : tolerances) {
        cout << "\n--- TOLERANCE: " << scientific << tol << " ---\n";
        int total_evals = 0;
        int passed_tests = 0;
        vector<int> eval_counts;
        
        for (size_t i = 0; i < tests.size(); i++) {
            eval_count = 0;
            double result = find_root(tests[i].func, tests[i].a, tests[i].b, tol);
            
            double error = fabs(result - tests[i].expected_root);
            bool accurate = error < 1e-9;
            
            cout << fixed << setprecision(0);
            cout << eval_count << " evals | ";
            cout << setprecision(17);
            cout << tests[i].name << " [" << tests[i].a << ", " << tests[i].b << "]";
            
            if (!accurate) {
                cout << " ⚠ ERROR: " << scientific << error;
            }
            cout << endl;
            
            total_evals += eval_count;
            eval_counts.push_back(eval_count);
            if (accurate) passed_tests++;
        }
        
        cout << "\nTotal evaluations: " << total_evals << endl;
        cout << "Average evaluations: " << fixed << setprecision(2) 
             << (double)total_evals / tests.size() << endl;
        cout << "Tests passed: " << passed_tests << "/" << tests.size() << endl;
    }
    
    // Summary table
    cout << "\n\n========== SUMMARY TABLE ==========\n\n";
    cout << "Tolerance  | Total Evals | Avg Evals | Tests Passed\n";
    cout << "-----------|-------------|-----------|-------------\n";
    
    for (double tol : tolerances) {
        int total_evals = 0;
        int passed_tests = 0;
        
        for (size_t i = 0; i < tests.size(); i++) {
            eval_count = 0;
            double result = find_root(tests[i].func, tests[i].a, tests[i].b, tol);
            double error = fabs(result - tests[i].expected_root);
            
            total_evals += eval_count;
            if (error < 1e-9) passed_tests++;
        }
        
        cout << scientific << setprecision(0) << tol << "  | ";
        cout << fixed << setw(11) << total_evals << " | ";
        cout << setw(9) << setprecision(2) << (double)total_evals / tests.size() << " | ";
        cout << setw(13) << passed_tests << "/" << tests.size() << endl;
    }
    
    cout << "\n========================================\n";
    
    return 0;
}