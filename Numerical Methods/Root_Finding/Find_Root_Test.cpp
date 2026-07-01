#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cfloat>
#include <fstream> // Required for file output

// --- PART 1: A ROBUST SINGLE ROOT FINDER ---
// This is a refined version of our hybrid algorithm. It's the engine
// that `find_all_roots` will use to find the root in each isolated interval.

double find_root(double (*f)(double), double (*df)(double), double a, double b) {
    const int MAX_ITER = 100;
    const double TOL = 4.0 * DBL_EPSILON;

    if (std::isnan(a) || std::isnan(b)) return NAN;

    double fa = f(a);
    double fb = f(b);

    if (std::fabs(fa) == 0.0) return a;
    if (std::fabs(fb) == 0.0) return b;
    if (a == b && df == nullptr) return NAN;

    // Prioritize b as the current best guess
    if (std::fabs(fa) < std::fabs(fb)) {
        std::swap(a, b);
        std::swap(fa, fb);
    }

    double x_prev = a;
    double fx_prev = fa;
    double x_curr = b;
    double fx_curr = fb;
    double last_step = x_curr - x_prev;

    for (int i = 0; i < MAX_ITER; ++i) {
        bool has_bracket = (fx_prev * fx_curr < 0.0);

        // Convergence check
        if (std::fabs(last_step) <= TOL * std::fmax(1.0, std::fabs(x_curr))) {
            return x_curr;
        }
        if (std::fabs(fx_curr) == 0.0) return x_curr;

        double step;
        bool interpolation_failed = false;

        if (has_bracket) { // --- Bracketing Mode (False Position / Bisection) ---
            double fp_denom = fx_curr - fx_prev;
            if (std::fabs(fp_denom) > DBL_MIN) {
                step = -fx_curr * (x_curr - x_prev) / fp_denom;
            } else {
                interpolation_failed = true;
            }
            // If false position isn't shrinking the interval enough, bisect
            if (interpolation_failed || std::fabs(2.0 * step) >= std::fabs(last_step)) {
                step = (x_prev - x_curr) / 2.0;
            }
        } else { // --- Open Mode (Newton / Secant) ---
            if (df != nullptr) { // Newton's Method
                double dfx = df(x_curr);
                if (std::fabs(dfx) > DBL_MIN) {
                    step = -fx_curr / dfx;
                } else {
                    interpolation_failed = true;
                }
            }
            if (df == nullptr || interpolation_failed) { // Secant Method
                double sec_denom = fx_curr - fx_prev;
                if (std::fabs(sec_denom) > DBL_MIN) {
                    step = -fx_curr * (x_curr - x_prev) / sec_denom;
                } else {
                    return (std::fabs(fx_curr) < sqrt(TOL)) ? x_curr : NAN;
                }
            }
        }

        last_step = step;
        x_prev = x_curr;
        fx_prev = fx_curr;
        x_curr += step;
        fx_curr = f(x_curr);
    }

    return (std::fabs(fx_curr) < sqrt(TOL)) ? x_curr : NAN;
}


// --- PART 2: FINDING ALL ROOTS IN A RANGE ---

std::vector<double> find_all_roots(
    double (*f)(double),
    double (*df)(double),
    double a,
    double b,
    int subdivisions = 10000) // Increased subdivisions for higher accuracy
{
    std::vector<double> roots;
    std::vector<std::pair<double, double>> brackets;
    
    // Ensure a < b for interval processing
    if (a > b) std::swap(a, b);

    double step = (b - a) / subdivisions;
    double x1 = a;
    double y1 = f(x1);

    // 1. Isolate Roots: Find all sub-intervals where a sign change occurs.
    for (int i = 0; i < subdivisions; ++i) {
        double x2 = x1 + step;
        if (x2 > b) x2 = b; // Ensure we don't go past the end
        double y2 = f(x2);

        if (std::fabs(y1) < 1e-14) { // Check if the point itself is a root
            if (roots.empty() || std::fabs(roots.back() - x1) > 1e-9) {
                 roots.push_back(x1);
            }
        }
        else if (y1 * y2 < 0) { // Found a sign change -> a bracket
            brackets.push_back({x1, x2});
        }
        x1 = x2;
        y1 = y2;
    }

    // 2. Extract Roots: Use find_root on each identified bracket.
    for (const auto& bracket : brackets) {
        double root = find_root(f, df, bracket.first, bracket.second);
        if (!std::isnan(root)) {
             // Avoid adding duplicate roots
            bool is_duplicate = false;
            for(double existing_root : roots) {
                if (std::fabs(existing_root - root) < 1e-9) {
                    is_duplicate = true;
                    break;
                }
            }
            if (!is_duplicate) {
                roots.push_back(root);
            }
        }
    }

    std::sort(roots.begin(), roots.end());
    return roots;
}


// --- The Tricky Test Cases ---

// The problem_t struct is needed to organize the tests.
struct problem_t {
    const char *description;
    double (*f)(double);
    double (*df)(double);
    double a,b;
};

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Problem 1: Derivative Trap
static double f1(double x) { return (x * x - 1.0) * exp(-100.0 * (x - 0.1) * (x - 0.1)) + 0.001; }
static double df1(double x) {
    double exp_term = exp(-100.0 * (x - 0.1) * (x - 0.1));
    return exp_term * (2.0 * x + (x * x - 1.0) * (-200.0 * (x - 0.1)));
}

// Problem 2: High Multiplicity Root
static double f2(double x) { return pow(x - M_PI, 16.0); }
static double df2(double x) { return 16.0 * pow(x - M_PI, 15.0); }

// Problem 3: Non-bracketing Interval (Root outside)
static double f3(double x) { return exp(x) - 10.0; }
static double df3(double x) { return exp(x); }

// Problem 4: Jumping Between Roots
static double f4(double x) { return x * x * x - 2.0 * x * x - 11.0 * x + 12.0; }
static double df4(double x) { return 3.0 * x * x - 4.0 * x - 11.0; }

// Problem 5: Catastrophic Cancellation
static double f5(double x) { return cos(x) - cos(x + 1e-9); }
static double df5(double x) { return -sin(x) + sin(x + 1e-9); }

int main() {
    problem_t problems[] = {
        {"(x^2-1)e^(-100(x-0.1)^2)+0.001", f1, df1, -2.0, 2.0},
        {"(x-pi)^16", f2, df2, 3.0, 3.2},
        {"e^x - 10", f3, df3, 0.0, 1.0}, // Original devious bound
        {"x^3-2x^2-11x+12", f4, df4, -2.0, 0.0}, // Original devious bound
        {"cos(x)-cos(x+1e-9)", f5, df5, 1.5, 1.6} // Original devious bound
    };

    // Open the output file
    std::ofstream outFile("root_finding_results.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open output file." << std::endl;
        return 1;
    }

    // Set precision for both console and file output
    std::cout << std::fixed << std::setprecision(15);
    outFile << std::fixed << std::setprecision(15);

    for (const auto& p : problems) {
        // Write to console
        std::cout << "-----------------------------------------------------\n";
        std::cout << "Searching for roots of: " << p.description << "\n";
        std::cout << "In original range: [" << p.a << ", " << p.b << "]\n";
        // Write to file
        outFile << "-----------------------------------------------------\n";
        outFile << "Searching for roots of: " << p.description << "\n";
        outFile << "In original range: [" << p.a << ", " << p.b << "]\n";

        std::vector<double> all_roots = find_all_roots(p.f, p.df, p.a, p.b);

        if (all_roots.empty()) {
            std::cout << "  No roots found in the given interval.\n";
            outFile << "  No roots found in the given interval.\n";
        } else {
            std::cout << "  Found " << all_roots.size() << " root(s):\n";
            outFile << "  Found " << all_roots.size() << " root(s):\n";
            for (double root : all_roots) {
                std::cout << "    x = " << root << "\n";
                outFile << "    x = " << root << "\n";
            }
        }
    }
    // Final separator
    std::cout << "-----------------------------------------------------\n";
    outFile << "-----------------------------------------------------\n";
    
    outFile.close();
    std::cout << "\nResults have been written to root_finding_results.txt\n";

    return 0;
}