class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        if (n < k)
            return 0;

        int operations = INT_MAX;
        int countW = 0;

        int i = 0, j = 0;

        while (j < n) {

            if (blocks[j] == 'W')
                countW++;

            
            if (j - i + 1 == k) {

                operations = min(operations, countW);

                
                if (blocks[i] == 'W')
                    countW--;

                i++;
            }

            j++;
        }

        return operations;
    }
};