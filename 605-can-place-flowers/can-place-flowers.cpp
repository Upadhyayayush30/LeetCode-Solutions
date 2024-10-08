class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            // Check if the current plot is empty, and the adjacent plots are also empty (or boundaries)
            if (flowerbed[i] == 0 && 
               (i == 0 || flowerbed[i - 1] == 0) && 
               (i == size - 1 || flowerbed[i + 1] == 0)) {
                
                // Place a flower
                flowerbed[i] = 1;
                count++;

                // If we've placed enough flowers, return true
                if (count >= n) return true;

                // Skip the next plot to avoid placing adjacent flowers
                i++;
            }
        }

        // If we couldn't place enough flowers, return false
        return count >= n;
    }
};
