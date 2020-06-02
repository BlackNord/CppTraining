#pragma once
#include <vector>
#include <list>
#include <iostream>

using namespace std;

namespace iterators {
    class Iterator {
    public:
        virtual double* next() = 0;
    };

    class Vector_iterator : public Iterator {
    private:
        vector<double> vec;
        int current;
    public:
        Vector_iterator(const vector<double>& _vec) : vec{ _vec }, current{ -1 } {}
        virtual double* next() override {
            if (vec.size() == 0) {
                throw runtime_error("Is empty");
            }
            current++;
            if (current < (int)vec.size()) {
                return &vec[current];
            }
            else return nullptr;
        }
    };

    class List_iterator : public Iterator {
    private:
        list<double> lst;
        list<double>::iterator iter;
    public:
        List_iterator(const list<double>& _lst) : lst{ _lst }, iter{ lst.begin() } {}
        virtual double* next() override {
            if (lst.size() == 0) throw runtime_error("Is empty");
            auto temp = iter;
            if (distance(lst.begin(), iter) == lst.size()) return nullptr;
            iter++;
            return &(*temp);
        }
    };

    void print(Iterator& it) {
        double* _it;
        while ((_it = it.next()) != nullptr) {
            cout << *_it << endl;
        }
    }
}