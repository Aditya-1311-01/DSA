class Solution {
public:
    int leastInterval(vector<char>& tasks, int gap) {
        unordered_map<char,int>freq;
        unordered_map<char,int>free;

        int n=tasks.size();
        for(int i=0;i<n;i++){
            freq[tasks[i]]++;
            free[tasks[i]]=1;
        }

        priority_queue<pair<int,char>>pq;

        for(auto it:freq){
            pq.push({it.second,it.first});
        }
        int seat=1;

        while(!pq.empty()){
            vector<pair<int,char>>room;

            while(!pq.empty()){
                pair<int ,char>p=pq.top();
                pq.pop();
                int fr=p.first;
                char child=p.second;

                if(free[child]<=seat){
                    if(p.first>1){
                        pq.push({p.first-1,p.second});
                        free[p.second]=seat+gap+1;
                    }
                    break;
                }
                else{
                    room.push_back(p);
                }
            }

            for(int i=0;i<room.size();i++)
            pq.push(room[i]);

            seat++;
        }

        return seat-1;

    

        
    }
};