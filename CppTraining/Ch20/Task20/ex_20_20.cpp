#include <ctime>
#include <random>
#include <chrono>

#include "ex_20_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template<typename T>
void printVec(const vector<T>& vec) {
    for (const auto& k : vec) {
        cout << k << " ";
    }
    cout << endl;
}

template<typename T>
void printList(const list<T>& list) {
    for (const auto& k : list) {
        cout << k << " ";
    }
    cout << endl;
}

template<typename T>
void printLV(T begin, T end) {
    while (begin != end) {
        cout << *begin << " ";
        ++begin;
    }
    cout << endl;
}

int randD(int down, int up = 0) {                    // random int of some diapazon
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(up, down);
    int d_ist = dist(mt);

    return d_ist;
}

template<typename T>
typename std::vector<T>::iterator insertSortedV(vector<T>& vec, T const& item) {
    return vec.insert(
        std::upper_bound(vec.begin(), vec.end(), item), 
        item
    );
}

template<typename T>
typename std::list<T>::iterator insertSortedL(list<T>& list, T const& item) {
    return list.insert(
        std::upper_bound(list.begin(), list.end(), item), 
        item
    );
}

template<typename T>
typename std::list<T>::iterator insertSorted(list<T>& list, T const& item) {
    return list.insert(
        std::upper_bound(list.begin(), list.end(), item),
        item
    );
}

void ex_20_20() {
    int n{ 0 };
    vector<int> myVec{};
    list<int> myList{};

    cout << "Enter N: ";
    cin >> n;

    auto beginTimeL = chrono::system_clock::now();
    for (int i{ 0 }; i < n; ++i) {
        insertSortedL(myList, randD(n));
    }
    auto endTimeL = chrono::system_clock::now();

    auto beginTimeV = chrono::system_clock::now();
    for (int i{ 0 }; i < n; ++i) {
        insertSortedV(myVec, randD(n));
    }
    auto endTimeV = chrono::system_clock::now();

    //printVec<int>(myVec);
    //printList<int>(myList);
    printLV(myVec.begin(), myVec.end());
    printLV(myList.begin(), myList.end());

    cout << "List: " << chrono::duration_cast<chrono::nanoseconds>(endTimeL - beginTimeL).count() << " ns" << endl;
    cout << "Vector: " << chrono::duration_cast<chrono::nanoseconds>(endTimeV - beginTimeV).count() << " ns" << endl;
}