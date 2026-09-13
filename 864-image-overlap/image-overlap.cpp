class Solution {
public:
    int countoverlap(vector<vector<int>>& img1, vector<vector<int>>& img2,int rowoff,int coloff){

        int n=img1.size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                int img2_i=i+rowoff;
                int img2_j=j+coloff;

                if(img2_i<0 || img2_i>=n || img2_j<0 || img2_j>=n)
                continue;

                if(img1[i][j]==1 && img2[img2_i][img2_j]==1)
                count++;
            }
        }

        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();

        int maxoverlap=0;

        for(int rowoff=-n+1;rowoff<n;rowoff++){
            for(int coloff=-n+1;coloff<n;coloff++){
                int count=countoverlap(img1,img2,rowoff,coloff);

                maxoverlap=max(count,maxoverlap);
            }
        }

        return maxoverlap;
        
    }
};