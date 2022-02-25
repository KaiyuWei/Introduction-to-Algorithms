include <vector>
include <utility>
include <iostream>

// radix sort needs a stable sorting algorithm, e.g. counting sort
// sort the vector ascendingly in radix sort according to the firt element of the pair
std::vector<std::pair<int, int>>
RadixCountingSort(std::vector<std::pair<int, int>> A, int k) {
    // A is a vector of pairs, with the first element the digit by which the radix sort is executing,
    // the second element the whole number
    std::vector<int> C(k + 1);  // index of C: 0..k
    auto length = A.size();
    for (int i = 0; i != length; ++i ) {
        C[A[i].first]++;
    }
    for (int i = 1; i != k + 1; ++i) {
        // counting the number of numbers that are smaller than the current one
        C[i] = C[i] + C[i - 1];
    }
    std::vector<std::pair<int, int>> B(length);
    for (int i = length - 1; i >= 0 ; --i) {
        B[C[A[i].first] - 1] = A[i]; //A[i] is the value, C[A[i]] is the index
        C[A[i].first]--;
    }
    return B;
}

std::vector<int> RadixSort(std::vector<int> unsorted, unsigned digits) {
    std::vector<std::pair<int, int>> radix(unsorted.size());
    std::vector<int> output(unsorted); // for storing output sorted result
    for (int i = 1; i <= digits; i++) {
        int divisor = pow(10, i);
        for (int j = 0; j != output.size(); j++) { // fill each  element in the pair vector
            int num = static_cast<int> (output[j] / pow(10, i - 1)) % 10; // the specific digit
            std::pair<int, int> digiNum{num, output[j]};
                // first element the digit, second element the whole number
            radix[j] = digiNum;
        }
        auto sorted = RadixCountingSort(radix, 10);  // we sort by individual digit so the range is 0-9
        for (int j = 0; j != sorted.size(); j++)
            output[j] = sorted[j].second; //copy sorted value for output or the next loop
    }
    return output;
}

int main() {
    // test the sorting functions
    std::vector<int> ivec{44, 33, 12, 456, 44, 73, 289, 133, 9};
    auto result = RadixSort(ivec, 3); // the second argument is the highest digit number among all the parameters. 
    for (auto i : result) {
        cout << i << " ";  // print out the sorted result
    }
}
