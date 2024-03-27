#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <chrono>

std::vector<int> generateRandomIntegers(int n, int minValue, int maxValue) {
    std::vector<int> nums(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minValue, maxValue);

    for (int& num : nums) {
        num = distr(gen);
    }

    return nums;
}

long long findSubarraySumEqualsK(const std::vector<int>& nums, int k) {
    long long count = 0;
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
    int n = 50000000; // 50 million integers
    std::vector<int> nums = generateRandomIntegers(n, -100, 100);
    int k = 50;

    auto start = std::chrono::high_resolution_clock::now();
    long long result = findSubarraySumEqualsK(nums, k);
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Total subarrays with sum " << k << ": " << result << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    return 0;
}
