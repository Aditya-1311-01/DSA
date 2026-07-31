class compare{
    public:
       bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first == b.first){
               return  a.second > b.second;
            }
            return a.first < b.first;
       }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare>p;
        unordered_map<string,int>mpp;

        for(int i =0;i<words.size();i++){
            mpp[words[i]]++;
        }

        for(auto it:mpp){
            p.push(make_pair(it.second,it.first));
        }

        vector<string>ans;
        pair<int,string> element;
        while(k!=0){
            element = p.top();
            p.pop();
            ans.push_back(element.second);
            k--;
        }

        return ans;
    }
};