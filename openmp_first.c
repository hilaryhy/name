#include <stdio.h>
#include <omp.h>
//reduction
int main()
{
    int i, n;
    double a[100], b[100], result;
    // initializations
    n = 100;
    result = 0.0;
    double start = omp_get_wtime( );  
    for (i = 0; i < n; i++)
    {
        a[i] = i * 1.0;
        b[i] = i * 2.0;
        
    }
    #pragma omp parallel for private(i) reduction(+:result)
    for (i = 0; i < n; i++)
    {
        
        result = result + (a[i] * b[i]);
    }
    double end = omp_get_wtime( );  
    double wtick = omp_get_wtick( );  
    printf("a*b= %12.6lf\n", result);
    printf("start = %.16g\nend = %.16g\ndiff = %.16g seconds\n",  
             start, end, end - start);  
  
    printf("wtick = %.16g\n1/wtick = %.16g\n",  
             wtick, 1.0 / wtick);  
    return 0;
}
