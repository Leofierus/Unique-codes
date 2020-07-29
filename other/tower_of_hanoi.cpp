#include <bits/stdc++.h> 
using namespace std; 
void towerOfHanoi(int n, char fr, char tr, char mr) 
{ 
 	if (n == 1) cout << "Disk 1 from rod " << fr << " to rod " << tr << endl,return;
	towerOfHanoi(n - 1, fr, mr, tr); 
	cout << "Disk " << n << " from rod " << fr << " to rod " << tr << endl; 
	towerOfHanoi(n - 1, mr, tr, fr); 
}  
int main() 
{ 
	int n;
 	cin >> n;
	towerOfHanoi(n, '1', '2', '3'); 
	return 0; 
}
