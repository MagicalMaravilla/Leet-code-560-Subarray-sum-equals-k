#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <chrono>

// Function to generate a vector of random integers
std::vector<int> generateRandomIntegers(int n, int minValue, int maxValue) {
    std::vector<int> nums(n);
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(minValue, maxValue); // Define the range

    for (int& num : nums) {
        num = distr(gen); // Generate a random int
    }

    return nums;
}

// The function to find subarray sum equals k
int findSubarraySumEqualsK(const std::vector<int>& nums, int k) {
    int count = 0;
    long long cumulativeSum = 0;
    std::unordered_map<long long, int> sumFrequency = {{0, 1}};

    for (int num : nums) {
        cumulativeSum += num;
        long long desiredSum = cumulativeSum - k;
        if (sumFrequency.find(desiredSum) != sumFrequency.end()) {
            count += sumFrequency[desiredSum];
        }
        sumFrequency[cumulativeSum]++;
    }

    return count;
}

int main() {
    // Generate a very large dataset of integers
    int n = 10000000; // 10 million integers
    std::vector<int> nums = generateRandomIntegers(n, -100, 100);
    int k = 50; // Example target sum

    // Measure the execution time
    auto start = std::chrono::high_resolution_clock::now();
    int result = findSubarraySumEqualsK(nums, k);
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Total subarrays with sum " << k << ": " << result << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    return 0;
}
