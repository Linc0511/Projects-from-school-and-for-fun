#include <cmath>

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
    
    while (true)
    {
        double old_a = a;
        double old_b = b;
        
        c = (a * f_b - b * f_a) / (f_b - f_a);
        double f_c = f(c);
        
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
    }
}