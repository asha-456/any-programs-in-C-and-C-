#include<iostream>
using namespace std;

#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i + 2
#define PARENT(i) (i-1)/2

class MaxHeap{
    int *arr;
    int n;
    public:
    MaxHeap(){

    }
    MaxHeap(int arr[], int n){
        try{
            this->arr = new int[n];
            for(int i=0;i<n;i++)
                this->arr[i] = arr[i];
            this->n = n;

            build_maxHeap(); 
        }
        catch (const bad_alloc& e) {
        cout << "Memory Allocation"
             << " is failed: "
             << e.what()
             << endl;
        }   

    }

    ~MaxHeap(){
        delete [] this->arr;
    }

    void heapify(int i){
        int l = LEFT(i);
        int r = RIGHT(i);

        int max = i;

        if (l<=n-1){
            if (arr[l] > arr[max])
                max = l; 
        }

        if(r<=n-1){
            if(arr[r] > arr[max])
                max = r;
        }

        if(max != i){
            swap(arr[i],arr[max]);
            heapify(max);
        }
    }

    void build_maxHeap(){
        for(int j = n/2 - 1; j>=0 ; j--){
            heapify(j);
        }
    }

    void print_heap(){
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }

    int extract_max(){
        if(this->n <= 0){
            return -1;
        }

        int top = arr[0];
        arr[0] = arr[n-1];
        n--;
        heapify(0);
        return top;
    }

    int top(){
        if(n > 0){
            return arr[0];
        }
        return -1;
    }

    int& operator[](int index)
    {
    if (index >= n) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return arr[index];
    }
  
};

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = { 7, 4, 6, 3, 9, 1 };
    int n = sizeof(arr)/sizeof(int);
    int k = 2;

    MaxHeap M(arr,n);
    for(int i=0;i<k-1;i++){
        M.extract_max();        
    }

    cout<<"kth largest element: "<<M[0]<<endl;
    return 0;
}
