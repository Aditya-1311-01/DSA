
class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;

        bool Alice = true;
        bool Bob = false;
        int N = 10;

        while (n > 0) {
            if (Alice) {
                if (n >= N) {
                    n -= N;
                    N--;
                    Alice = false;
                    Bob = true;
                }
                else {
                    return false;
                }
            }
            else if (Bob) {
                if (n >= N) {
                    n -= N;
                    N--;
                    Bob = false;
                    Alice = true;
                }
                else {
                    return true;
                }
            }
        }

        return Bob;
    }
};
