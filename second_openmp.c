#include <stdio.h>
#include <omp.h>
#define D 1000
//reduction
int main()
{
    int i, n;
    float a[D], b[D], result;
    // initializations
    result = 0.0;
    for (i = 0; i < D; i++)
    {
        a[i] = i * 1.0;
        b[i] = i * 2.0;
        
    }
    #pragma omp parallel for private(i) reduction(+:result)
    for (i = 0; i < n; i++)
    {
        
        result = result + (a[i] * b[i]);
    }
    
    printf("a*b= %12.6lf\n", result);
    
    return 0;
}
