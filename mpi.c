#include <stdio.h>
#include <mpi.h>

int fun(int n){
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1;
} 

int main(int argc, char* argv[])
{
    int myid, numprocs;

    MPI_Status status;
    const int range = 100000;

    int a[range];

    a[0] = 0;
    a[1] = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    for(int i = 2; i < range; i++){
        if(i % numprocs != myid)
            continue;
        
        int is_prim = fun(i);
        if(is_prim)
            a[i] = i;
        else
            a[i] = 0;
    }

    if(myid != 0)
        MPI_Send(a, range, MPI_INT, 0, 99, MPI_COMM_WORLD);
        
    if(myid == 0){
        FILE *fp=NULL;
        fp=fopen("3.txt","w");
        int sum = 0;
        for(int source = 0; source < numprocs; source ++)
            {   
                if(source != 0)
                    MPI_Recv(a, range, MPI_INT, source, 99, MPI_COMM_WORLD, &status);
                for(int i = 0; i < range; i++){
                    if(a[i] != 0)
                        {sum += 1;
                        fprintf(fp, "%d\n", a[i]);}
                }
            }
        printf("素数的个数是：%d", sum);
        fclose(fp);
    }

    MPI_Finalize();
    return 0;
}