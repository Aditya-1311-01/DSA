class Solution {
public:
    int findDays(string date,vector<int>&monthdays){
        int month=stoi(date.substr(0,2));
        int days=stoi(date.substr(3));

        return monthdays[month-1]+days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int>monthdays(13,0);
        monthdays[1]=31;

        for(int i=2;i<13;i++){
            monthdays[i]=monthdays[i-1]+days[i-1];
        }
        int arrivealice=findDays(arriveAlice,monthdays);
        int leavealice=findDays(leaveAlice,monthdays);
        int arrivebob=findDays(arriveBob,monthdays);
        int leavebob=findDays(leaveBob,monthdays);

        int ans=min(leavealice,leavebob)-max(arrivealice,arrivebob)+1;

        return ans<0?0:ans;

    }
};