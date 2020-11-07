#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        while (i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);

        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root;
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        while (i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    int getMin() {
        return a[0];
    }
};

int main() {
    MinHeap min_heap;
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        min_heap.insert(x);
    }
    int cnt = 0;
    while (min_heap.a.size() > 0 && min_heap.getMin() < m) {
        int m1 = min_heap.getMin();
        min_heap.extractMin();
        if (min_heap.a.size() > 0) {
            int m2 = min_heap.getMin();
            min_heap.extractMin();
            min_heap.insert(m1 + 2 * m2);
            cnt++;
        } else {
            cnt = -1;
            break;
        }
    }
    cout << cnt;
        
    return 0;
}

// 6 8 6 15 10 18 9 
// 