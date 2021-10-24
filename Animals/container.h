#ifndef __container__
#define __container__

#include "animal.h"

class container {
    animal **data;
    int capacity;
    int count;
private:
    void heapify(int n, int i);
public:
    explicit container(int capacity);
    container();
    int size() const;
    void fill(FILE *in);
    void fill();
    void out(FILE* out);
    void add(animal *value);
    void remove(int idx);
    animal* get(int idx);
    void heapSort();
    ~container();
};

#endif