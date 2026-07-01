#include <cmath>

double integrate(double (*f)(double), double a, double b, double epsilon) {
    int n = 1;
    double width = b - a;
    double sum = f(a);
    double prev_integral = sum * width;
    
    while (true) {
        n *= 2;
        width = (b - a) / n;
        
        for (int i = 1; i < n; i += 2) {
            sum += f(a + i * width);
        }
        
        double integral = sum * width;
        
        if (fabs(integral - prev_integral) < epsilon) {
            return integral;
        }
        
        prev_integral = integral;
    }
}