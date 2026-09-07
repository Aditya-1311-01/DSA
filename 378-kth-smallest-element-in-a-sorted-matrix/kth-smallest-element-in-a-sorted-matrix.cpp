class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        vector<pair<int,pair<int,int>>>temp;
        
        int n=matrix.size();

        for(int i=0;i<n;i++)
        temp.push_back(make_pair(matrix[i][0] ,make_pair(i,0)));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());

        pair<int,pair<int,int>>element;
        int i,j;
        int ans;

        while(k--){
            element=p.top();
            ans=element.first;
            i=element.second.first;
            j=element.second.second;

            if(j+1<n)
            p.push(make_pair(matrix[i][j+1] ,make_pair(i,j+1)));

            p.pop();

        }

        return ans;
        
        
    }
};