#include<bits/stdc++.h> 
using namespace std; 
void print(int i, int j, int n, 
					int br[100][100], char &name) 
{ 
	if (i == j) 
	{ 
		cout << name++; 
		return; 
	} 

	cout << "("; 
	print(i, br[i][j], n, 
					br, name); 
	print(br[i][j] + 1, j, 
					n, br, name); 
	cout << ")"; 
} 

void matrixChainOrder(int p[], int n) 
{ 
	int m[n][n]; 

	int br[100][100]; 
	for (int i=1; i<n; i++) 
		m[i][i] = 0; 
	for (int L=2; L<n; L++) 
	{ 
		for (int i=1; i<n-L+1; i++) 
		{ 
			int j = i+L-1; 
			m[i][j] = INT_MAX; 
			for (int k=i; k<=j-1; k++) 
			{ 
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
				if (q < m[i][j]) 
				{ 
					m[i][j] = q; 
					br[i][j] = k; 
				} 
			} 
		} 
	} 

	char name = 'A'; 
 
	print(1, n-1, n, br, name); 
	cout << "\nCost is : " << m[1][n-1]; 
} 


int main() 
{ 
	//fast cpp code
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int arr[] = {40, 20, 30, 10, 30}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	matrixChainOrder(arr, n); 
	return 0; 
} 

