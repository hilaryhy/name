#include <stdio.h>
int fun(int n){
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1;
} 

int main()
{ 
    FILE *fp=NULL;
    fp=fopen("3.txt","w");
    int i;
    int j;
    int num=0;
    int sum=0;
    const int range=100000;
    int a[range];
    a[0]=0;
    a[1]=0;
    
    
    #pragma acc kernels
    {
    for(i=2;i<100000;i++){
        num = 0;
        for(j=1;j<=i;j++)
            if(i%j==0) num += 1;
                
        if(num == 2)      
            {sum++;
            a[i]=i;}
        else
            a[i]=0;
        
                
        
        
            }
    }
    printf("%d",sum);
    
    
    for(i=0;i<range;i++){
        if (a[i] != 0)
        fprintf(fp,"%d\n",i);}
    fclose(fp);
    return 0; 
}

