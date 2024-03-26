#include <iostream>
#include <unordered_map>
#include <vector>

int findSubarraySumEqualsK(const std::vector<int>& nums, int k) {
    int count = 0;
    long long cumulativeSum = 0; // Use long long for potentially large sums
    std::unordered_map<long long, int> sumFrequency;
    sumFrequency[0] = 1; // Initialize to handle edge case for a subarray starting at index 0

    for (int num : nums) {
        cumulativeSum += num;
        
        // Check if the difference between the cumulativeSum and k is in the map
        long long desiredSum = cumulativeSum - k;
        if (sumFrequency.find(desiredSum) != sumFrequency.end()) {
            count += sumFrequency[desiredSum];
        }
        
        // Update the frequency of the current cumulativeSum in the map
        sumFrequency[cumulativeSum]++;
    }

    return count;
}

int main() {
    std::vector<int> nums = {1, 1, 1}; // Example input
    int k = 2; // Example target sum
    std::cout << "Total subarrays with sum " << k << ": " << findSubarraySumEqualsK(nums, k) << std::endl;
    return 0;
}
