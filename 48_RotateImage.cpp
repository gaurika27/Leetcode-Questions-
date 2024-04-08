#include <bits\stdc++.h>
#include <vector>
using namespace std;
int main(){
  vector<vector<int>> A={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  int n=A.size();
  int m=A[0].size();
  vector<vector<int>> B(n, vector<int>(m));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      B[i][j]=A[(n-1-j)][i];
    }
  }
  for(int i=0; i<n;i++){
    for(int j=0; j<m; j++){
      cout<<B[i][j]<<" ";
    }
    cout<<endl;
  }


}