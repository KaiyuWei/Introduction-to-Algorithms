int ppartition(int *A, int p, int r); // declaration of function
void quickSort(int *A, int p, int r); // declaration of function


int main() {
    int A[10] = {7, 4, 2, 8, 41, 22, 9, 32, 22, 75}; // create an array to be sorted
    quickSort(A, 0, 9); // test the quick sort algorithm
    for (auto i : A) // print the array after sorting to check
        cout << i << " ";
    cout << endl;
}


int partition(int *A, int p, int r) {
    int i = p - 1;
    int j = p;
    while (j != r) {
        if (A[j] < A[r]) {
            i++;
            std::swap(A[j], A[i]);
        }
        j++;
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(int *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
