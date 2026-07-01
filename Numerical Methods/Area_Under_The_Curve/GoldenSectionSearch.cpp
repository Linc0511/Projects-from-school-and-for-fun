double find_min(double (*f)(double), double a, double b)
{
    const double PHI = 0.618033988749895;
    const double TOL = 1e-10;
    
    double x1 = a + (1 - PHI) * (b - a);
    double x2 = a + PHI * (b - a);
    
    double f1 = f(x1);
    double f2 = f(x2);
    
    while ((b - a) > TOL)
    {
        if (f1 > f2)
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + PHI * (b - a);
            f2 = f(x2);
        }
        else
        {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + (1 - PHI) * (b - a);
            f1 = f(x1);
        }
    }
    
    if (f1 < f2)
        return x1;
    else
        return x2;
}