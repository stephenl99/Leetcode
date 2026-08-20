class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long left = 0; 
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        long long right = max(abs(houses[houses.size() - 1] - heaters[0]), abs(houses[0] - heaters[0]));
        while (left <= right) {
            int mid = right - (right - left) / 2;
            bool works = false;
            int houseIndex = 0;
            for (int heater : heaters) {
                if (works) {
                    break;
                }
                if (houses[houseIndex] < heater - mid) {
                    break;
                }
                while (houseIndex < houses.size() && abs(houses[houseIndex] - heater) <= mid) {
                    houseIndex++;
                    if (houseIndex == houses.size()) {
                        works = true;
                        break;
                    }
                }
            }
            if (works) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};