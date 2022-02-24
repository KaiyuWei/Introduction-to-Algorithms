#including <vector>
#including <iostream>

//sort the vector descendingly
std::vector<int> desCountingSort(std::vector<int> A, int k) {
    std::vector<int> C(k + 1);
    auto length = A.size();
    for (int i = 0; i != length; ++i ) {
        C[A[i]]++;
    }
    for (int i = k - 1; i >= 0; --i) {
        // counting the number of numbers that are smaller than the current one
        C[i] = C[i] + C[i + 1];
    }
    std::vector<int> B(length);
    for (int i = length - 1; i >= 0 ; --i) {
        B[C[A[i]] - 1] = A[i]; //A[i] is the value, C[A[i]] is the index
        C[A[i]]--;
    }
    return B;
}

// sort the vector ascendingly
std::vector<int> AsCountingSort(std::vector<int> A, int k) {
    std::vector<int> C(k + 1);  // index of C: 0..k
    auto length = A.size();
    for (int i = 0; i != length; ++i ) {
        C[A[i]]++;
    }
    for (int i = 1; i != k + 1; ++i) {
        // counting the number of numbers that are smaller than the current one
        C[i] = C[i] + C[i - 1];
    }
    std::vector<int> B(length);
    for (int i = length - 1; i >= 0 ; --i) {
        B[C[A[i]] - 1] = A[i]; //A[i] is the value, C[A[i]] is the index
        C[A[i]]--;
    }
    return B;
}

int main() {
    // test the sorting functions
    std::vector<int> ivec{7, 4, 2, 8, 9, 13, 6, 0, 2, 11};
    auto descending = desCountingSort(ivec, 14); // input argument k is the largest number in the vector
    auto ascending = AsCountingSort(ivec, 14);

    for (auto e : descending)
        std::cout << e << " ";
    std::cout << std::endl;

    for (auto e : ascending)
        std::cout << e << " ";
    std::cout << std::endl;
}
