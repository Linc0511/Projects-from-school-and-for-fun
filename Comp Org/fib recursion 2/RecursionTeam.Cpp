#include <iostream>
int recursiveSummation(int n)
{
    if (n <= 0)
    {
        std::cout << "You entered a negative numebr. Please enter a postive number." << std::endl;
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else 
    {
        //std::cout << "need sum of " << (n-1) << std::endl;
        int answer = recursiveSummation(n-1);
        //std::cout << "sum of " << (n-1) << " is " << answer<< std::endl;
        return answer + n;
    }
    
}
iterativeSummation(int n)
{
    if (n <= 0)
    {
        std::cout << "You entered a negative numebr. Please enter a postive number." << std::endl;
        return 0;
    }
    int sum = 0; 
    for (int i = 1; i <= n; i++ ) 
    {
        sum+=i;
    }
    return sum; 
}
int main() {
std::cout << iterativeSummation(4) << std::endl;
}