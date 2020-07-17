#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define llu unsigned long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
#define M 1000000007
#define vi vector<int>
#define vlli vector<lli>
#define pi pair<int,int>
#define mp make_pair
#define mapi map<int,int>
void display(int *array, int size) 
{
   for(int i = 0; i<size; i++)	cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) 
{
	int i, j, k, nl, nr;
	nl = m-l+1; nr = r-m;
	int larr[nl], rarr[nr];
	for(i = 0; i<nl; i++)	larr[i] = array[l+i];
	for(j = 0; j<nr; j++)	rarr[j] = array[m+1+j];
	i = 0; j = 0; k = l;
	while(i < nl && j<nr) 
	{
    	if(larr[i] <= rarr[j]) array[k] = larr[i],i++;
    	else	array[k] = rarr[j],j++;
    }
    k++;
	while(i<nl)	array[k] = larr[i],i++,k++;
	while(j<nr)	array[k] = rarr[j],j++,k++;
}
void mergeSort(int *array, int l, int r) 
{
	int m;
	if(l < r) 
	{
    	int m = l+(r-l)/2;
    	mergeSort(array, l, m);
    	mergeSort(array, m+1, r);
    	merge(array, l, m, r);
	}
}
int main() 
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++)	cin >> arr[i];
	mergeSort(arr, 0, n-1);
	display(arr, n);
}



