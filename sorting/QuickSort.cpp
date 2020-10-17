//============================================================
//        En. NO : 180110107021
//		  Batch  : 1B07 
//============================================================
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int n;
int partition(int arr[],int start,int end)
{
	int pivot_index;
	pivot_index=start;
	while(start<end)
	{
		while(arr[start]<=arr[pivot_index])
		   start++;
		while(arr[end]>arr[pivot_index])
		    end--;
		if(start<end)
		{
		    swap(arr[start],arr[end]);
		}
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<"\n";
	}
	swap(arr[end],arr[pivot_index]);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<"\n\n";
	return end;
}

int quickSort(int arr[],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=partition(arr,lb,ub);
		quickSort(arr,lb,mid-1);
		quickSort(arr,mid+1,ub);
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
//		arr[i]=rand()%n;
		cin>>arr[i];
	}
	
	auto start = high_resolution_clock::now();
	//call sort function
	quickSort(arr,0,n-1);
	auto stop = high_resolution_clock::now();
	
	//after sorting
    //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    //cout<<"\n";
	
	auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n\nTime taken by function: "<< duration.count() << " microseconds\n";
	return 0;
}

//Output 
//10 => 0 microseconds
//100 => 0 microseconds
//1000 => 171 microseconds
//10,000 => 3027 microseconds
//1,00,00 => 33930 microseconds
//2,00,000 => 70707 microseconds
//3,00,000 => 119607 microseconds
