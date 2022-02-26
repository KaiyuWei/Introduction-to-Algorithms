#include <vector>
#include <iostream>
using std::vector;

vector<int> merge(vector<int> a, vector<int> b) {
    auto aiter = a.cbegin();
    auto biter = b.cbegin();
    vector<int> merged;
    // if both of the vectors has not been traversed
    while (aiter != a.cend() && biter != b.cend()) {
        if (*aiter <= *biter) {
            merged.push_back(*aiter);  // smaller element in front of larger ones
            aiter++;
        }
        else {
            merged.push_back(*biter);
            biter++;
        }
    }
    // if one of the vectors has been traversed
    while(aiter != a.cend()) {
        merged.push_back(*aiter);
        aiter++;
    }
    while (biter != b.cend()) {
        merged.push_back(*biter);
        biter++;
    }
    return merged;
}

vector<int> mergeSort(vector<int> unsorted) {
    size_t n = unsorted.size();
    if (n == 1) {
        return unsorted;
    }
    else {
        vector<int> part1(unsorted.cbegin(), unsorted.cbegin() + floor(n / 2));
        vector<int> part2(unsorted.cbegin() + floor(n / 2), unsorted.cend());
        part1 = mergeSort(part1);
        part2 = mergeSort(part2);
        return merge(part1, part2);
    }
}

int main() {
    vector<int> vec{41, 17, 101, 0, 8, 142, 95};
    auto result = mergeSort(vec);
    for (auto e : result)
        cout << e << " ";
}
