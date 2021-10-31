vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    vector<int> arr1(n);
    
    int new_index;
    for(int i=0;i<n;i++){
        if(i<d)
            new_index = n + (i-d);
        else
            new_index = i - d;
        arr1[new_index] = arr[i]; 
    }

    return arr1;
}