#include <cmath>

double simpsonSingle(double (*f)(double), double a, double b, double fa, double fb) {
    double m = (a + b) / 2.0;
    double fm = f(m);
    return (b - a) / 6.0 * (fa + 4.0 * fm + fb);
}

double adaptiveSimpson(double (*f)(double), double a, double b, 
                       double epsilon, double fa, double fb, double whole) {
    double m = (a + b) / 2.0;
    double fm = f(m);
    
    double left = simpsonSingle(f, a, m, fa, fm);
    double right = simpsonSingle(f, m, b, fm, fb);
    double combined = left + right;
    
    if (std::abs(combined - whole) <= 15.0 * epsilon) {
        return combined + (combined - whole) / 15.0;
    }
    
    return adaptiveSimpson(f, a, m, epsilon / 2.0, fa, fm, left) +
           adaptiveSimpson(f, m, b, epsilon / 2.0, fm, fb, right);
}

double integrate(double (*f)(double), double a, double b, double epsilon) {
    if (a == b) return 0.0;
    if (a > b) return -integrate(f, b, a, epsilon);
    
    double fa = f(a);
    double fb = f(b);
    double whole = simpsonSingle(f, a, b, fa, fb);
    
    return adaptiveSimpson(f, a, b, epsilon, fa, fb, whole);
}