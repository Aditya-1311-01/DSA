class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> mp;

        int x = 0, y = 0;
        mp.insert({x, y});

        for(int i = 0; i < path.size(); i++) {

            if(path[i] == 'N')
                y++;

            else if(path[i] == 'S')
                y--;

            else if(path[i] == 'E')
                x++;

            else if(path[i] == 'W')
                x--;

            if(mp.find({x, y}) != mp.end())
                return true;

            mp.insert({x, y});
        }

        return false;
    }
};