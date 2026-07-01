#include <cmath>

double find_root(double (*f)(double), double a, double b)
{
    const double k1 = 0.1;
    const double k2 = 2.0;
    const double n0 = 1.0;
    const int MAX_ITERATIONS = 99;
    
    double initial_interval = fabs(b - a);
    const double epsilon = initial_interval / pow(2.0, 52.0);
    
    double n_half = ceil(log2(fabs(b - a) / (2.0 * epsilon)));
    double n_max = n_half + n0;
    double j = 0.0;
    
    double ya = f(a);
    double yb = f(b);
    
    if (yb < ya) {
        double temp = a;
        a = b;
        b = temp;
        temp = ya;
        ya = yb;
        yb = temp;
    }
    
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        if (fabs(b - a) <= 2.0 * epsilon) break;
        
        double x_half = (a + b) / 2.0;
        double r = epsilon * pow(2.0, n_max - j) - fabs(b - a) / 2.0;
        double delta = k1 * pow(fabs(b - a), k2);
        
        double x_f = (yb * a - ya * b) / (yb - ya);
        
        double sigma = (x_half - x_f) >= 0 ? 1.0 : -1.0;
        double x_t;
        if (delta <= fabs(x_half - x_f)) {
            x_t = x_f + sigma * delta;
        } else {
            x_t = x_half;
        }
        
        double x_itp;
        if (fabs(x_t - x_half) <= r) {
            x_itp = x_t;
        } else {
            x_itp = x_half - sigma * r;
        }
        
        double y_itp = f(x_itp);
        
        if (y_itp > 0.0) {
            b = x_itp;
            yb = y_itp;
        } else if (y_itp < 0.0) {
            a = x_itp;
            ya = y_itp;
        } else {
            a = x_itp;
            b = x_itp;
        }
        
        j = j + 1.0;
    }
    
    return (a + b) / 2.0;
}