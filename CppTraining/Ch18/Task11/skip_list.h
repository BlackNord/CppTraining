#pragma once
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

namespace skiplst {
    class skip_list {
    protected:
        class node {
        public:
            node(int _key, const string& _data, int _level) : key{ _key }, data{ _data }, forward(_level, nullptr) {}

            string data;
            int key;
            vector<node*> forward;      // collection of neighbour-pointers
        };

        int node_lvl(const node* n) const {
            return n->forward.size();
        }

        vector<node*> pred(int _key) const {
            vector<node*> res(node_lvl(head), nullptr);
            node* p = head;

            for (int i = node_lvl(head); i-- > 0; ) {
                while (p->forward[i]->key < _key) {
                    p = p->forward[i];
                }
                res[i] = p;
            }
            return res;
        }

        node* m_node(int _key, const string& _val, int _lvl) {
            return new node(_key, _val, _lvl);
        }

        int rand_lvl() const {
            int lvl = 1;
            while (((double)rand() / RAND_MAX) < probability && lvl < max_lvl) {
                lvl++;
            }
            return lvl;
        }

        node* lower_bound(int _key) const {
            node* p = head;

            for (int i = node_lvl(head); i-- > 0; ) {
                while (p->forward[i]->key < _key) {
                    p = p->forward[i];
                }
            }

            return p->forward[0];
        }

        node* head;
        node* tail;
        const double probability;
        const int max_lvl;
    public:
        skip_list(double _probability, int _max_lvl) : probability{ _probability }, max_lvl{ _max_lvl } {
            // create the mega-limits of skip-list
            int head_key = numeric_limits<int>::min();
            head = new node(head_key, "Head", max_lvl);

            int tail_key = numeric_limits<int>::max();
            tail = new node(tail_key, "Tail", max_lvl);

            fill(head->forward.begin(), head->forward.end(), tail);         // make all pointers of Head to Tail
        }

        ~skip_list() {
            auto node = head;
            while (node->forward[0]) {                                      // === node->next (for current level)
                auto tmp = node;
                node = node->forward[0];
                delete tmp;
            }
            delete node;
        }

        void print() const {
            node* ptr = head->forward[0];

            while (ptr != tail) {
                cout << "Key: " << ptr->key << endl;
                cout << "Level: " << node_lvl(ptr) << endl;
                cout << "Data: " << ptr->data << endl;

                ptr = ptr->forward[0];

                cout << endl;
            }
        }

        void insert(int _key, const string& _data) {
            auto preds = pred(_key);

            auto next = preds[0]->forward[0];       // if there is current key
            if (next->key == _key && next != tail) {
                next->data = _data;
                return;
            }

            // else - create a new one
            const int new_node_lvl = rand_lvl();
            auto new_node_ptr = m_node(_key, _data, new_node_lvl);

            // and connecting it with others
            for (int i{ 0 }; i < new_node_lvl; ++i) {
                new_node_ptr->forward[i] = preds[i]->forward[i];
                preds[i]->forward[i] = new_node_ptr;
            }
        }

        void erase(int _key) {
            auto preds = pred(_key);

            // checking if the node exists
            auto node = preds[0]->forward[0];
            if (node->key != _key || node == tail) {
                return;
            }

            // update pointers and delete node 
            for (int i{ 0 }; i < node_lvl(node); ++i) {
                preds[i]->forward[i] = node->forward[i];
            }
            delete node;
        }

        string find(int _key) const {
            string res{};

            if (auto p = lower_bound(_key)) {
                if (p->key == _key && p != tail) {
                    res = p->data;
                }
            }

            return res;
        }
    };
}