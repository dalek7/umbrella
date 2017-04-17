/*
  multiplication table using CUDA
  code downloaded from http://blog.daum.net/heoly/7
  $ nvcc -o multiplication multiplication.cu
*/
#include <stdio.h>
#include <malloc.h>
#include <cuda_runtime.h>

#define BLOCK_SIZE 5 // upto 5+1 dan
#define THREAD_SIZE 9

// Device code
__global__ void test(int *result)
{
    int tidx, bidx;
    tidx = threadIdx.x; //x-coordinate of thread
    bidx = blockIdx.x; //x-coordinate of block

    result[THREAD_SIZE * bidx + tidx] = (bidx + 2) * (tidx + 1);
}

// Host code
int main()
{
    int *host_Result; //Save result data of host
    int *device_Result; //Save result data of device

    int i=0, j=0;

    //Allocate host memory
    host_Result = (int *)malloc( BLOCK_SIZE * THREAD_SIZE * sizeof(int) );

    //Allocate device memory
    cudaMalloc( (void**) &device_Result, sizeof(int) * BLOCK_SIZE * THREAD_SIZE);

    //Function name <<BLOCK_SIZE, THREAD_SIZE>>> parameters
    test <<<BLOCK_SIZE, THREAD_SIZE>>>(device_Result); //Execute Device code

    //Copy device result to host result
    cudaMemcpy( host_Result, device_Result, sizeof(int) * BLOCK_SIZE * THREAD_SIZE, cudaMemcpyDeviceToHost );


    //Print result
    for(j=0; j<BLOCK_SIZE; j++)
    {
        printf("%3d step\n", (j + 2));
        for(i=0; i<THREAD_SIZE; i++)
        {
            printf("%3d X %3d = %3d\n", j+2, i+1, host_Result[j * THREAD_SIZE + i]);
        }
        printf("\n");
    }
    free(host_Result); //Free host memory
    cudaFree(device_Result); //Free device memory

    return 1;
}
