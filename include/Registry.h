#pragma once
#include <vector>

template <typename T1, typename T2>
class Record{
public:
    T1 key;
    T2 value;
    Record(T1 a,T2 b): key(a), value(b) {}
};

template <typename T1, typename T2>
class Registry {
private:
    std::vector<Record<T1, T2>> reg;
public:
    void add(const T1 &_key, const T2 &_value) {
        reg.push_back(Record<T1, T2>(_key, _value));
    }

    void remove(const T1 &_key) {
        if (!reg.empty()) {
            for (auto it = reg.begin(); it <= reg.end(); it++) {
                if (it->key == _key) {
                   reg.erase(it);
                }
            }
        }
    }

    const void print() {
        if (!reg.empty()) {
            for (Record<T1, T2> rec: reg) {
                std::cout << "Key: " << rec.key << "\t\t" << "Value: " << rec.value << std::endl;
            }
        }
    }

    void find(std::vector<Record<T1, T2>> &out, T1 key) {
        out.clear();
        if (!reg.empty()) {
            for (Record<T1, T2> rec: reg) {
                if (rec.key == key) {
                    out.push_back(rec);
                }
            }
        }
    }
};