#include <iostream>
void arrayReverse(int *p,int n)
{
    int counter = 1;
    int *q = p;
    int i = 1;
    while (i != n)
    {
        //printf("Value of -1 *q: %d\n", *q);
        //p++;
        //*q = *p;
        q++;
        //std::cout << "i:" << i << std::endl;
        //printf("Value of 0 *q: %d\n", *q);
        i++;

    }

    //printf("Value of 1 *p: %d\n", *p);
    //printf("Value of 1 *q: %d\n", *q);
    while(counter < n) 
    {
        counter++;
        *p ^= *q;
        //printf("Value of 2 *p: %d\n", *p);
        //printf("Value of 2 *q: %d\n", *q);
        *q ^= *p;
        //printf("Value of 3 *p: %d\n", *p);
        //printf("Value of 3 *q: %d\n", *q);
        *p ^= *q;
        //printf("Value of 4 *p: %d\n", *p);
        //printf("Value of 4 *q: %d\n", *q);
        std::cout << "counter:" << counter << std::endl;
        p++;
        q--;
        
        
    }
}
void arrayCopy(int *p,int n,int *q)
{
    int counter = 0;
    while(counter <= n) 
    {
        *p ^= *q;
        p++;
        q++;
        counter++;
    }    

}
void arrayFill(int *p,int n,int v)
{
    int counter = 0;
    while(counter <= n) 
    {
        *p = v;
        p++;
        counter++;
    }     
}
bool arrayEqual(int *p,int n,int *q)
{
    int counter = 0;
    while (counter < n)
    {   
        if ((*p = *q))
        {
            break;
        }
        if (*p != *q)
        {
            return 0;
        }
    } 
    return true;   
}
