#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	const int N = 1e3+2;
	int idx[N];

	int minIndex = INT_MAX;
	for(int i=0;i<N;i++){
		idx[i] = -1;
	}

	for(int i=0;i<n;i++){
		if(idx[arr[i]] != -1){
			minIndex = min(minIndex,idx[arr[i]]);
		}
		else{
			idx[arr[i]] = i;
		}
	}

	if(minIndex == INT_MAX){
		cout<<"-1"<<endl;
	}
	cout<<"Min index: "<<minIndex<<endl;	



	return 0;
}