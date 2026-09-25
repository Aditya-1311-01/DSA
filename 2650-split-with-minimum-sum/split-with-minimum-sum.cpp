class Solution {
public:
    void insert(int num,vector<int>&temp){
        while(num){
            temp.push_back(num%10);
            num/=10;
        }
    }
    int splitNum(int num) {
        vector<int>temp;
        insert(num,temp);

        sort(temp.begin(),temp.end());

        int num1=0,num2=0;
        for(int i=0;i<temp.size();i++){
            if(i%2==0){
                num1=num1*10+temp[i];
            }
            else{
              num2=num2*10 +temp[i];
            }
        }

        return num1+num2;
    }
};