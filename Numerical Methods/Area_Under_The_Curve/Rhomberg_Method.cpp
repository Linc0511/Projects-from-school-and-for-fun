#include <cmath>

double integrate(double (*f)(double), double a, double b, double epsilon) {
    double I[10][10];
    int n = 1;
    double h = b - a;
    I[0][0] = 0.5 * h * (f(a) + f(b));
    
    int iter = 0;
    double ea;
    
    do {
        iter = iter + 1;
        n = pow(2, iter);
        h = (b - a) / n;
        
        double sum = 0.0;
        for (int i = 1; i <= n / 2; i++) {
            sum += f(a + (2 * i - 1) * h);
        }
        I[iter][0] = 0.5 * I[iter - 1][0] + h * sum;
        
        for (int k = 1; k <= iter; k++) {
            int j = iter - k;
            double power = pow(4, k);
            I[j][k] = (power * I[j + 1][k - 1] - I[j][k - 1]) / (power - 1);
        }
        
        ea = fabs((I[0][iter] - I[1][iter - 1]) / I[0][iter]) * 100;
        
    } while (iter < 9 && ea > epsilon);
    
    return I[0][iter];
}