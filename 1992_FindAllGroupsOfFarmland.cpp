class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> result;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!land[i][j]) continue;
                
                int c2 = j;
                while(c2<m && land[i][c2]){
                    c2++;
                }
                int r2 = i;
                while(r2<n && land[r2][j]){
                    r2++;
                }
                c2 = !c2 ? c2 : c2-1;
                r2 = !r2 ? r2 : r2-1;
                result.push_back({i,j,r2,c2});
                
                for(int k=i; k<=r2; k++){
                    for(int l=j; l<=c2; l++){
                        land[k][l]=0;
                    }
                }
            }
        }
        return result;
    }
};