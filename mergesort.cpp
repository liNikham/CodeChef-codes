#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e) {
    vector<int> temp;
    int left = s, right = mid + 1;
    while ((left <= mid) && (right <= e)) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= e) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }
}

void mergesort(vector<int>& arr, int s , int e) {
    if (s == e) return;
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main() {
    int size = 10;
    vector<int> arr;
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    cout << "The array is" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergesort(arr, 0, size - 1);
    cout << "array after merge sort" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
