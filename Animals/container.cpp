#include "container.h"

container::container(int capacity) {
    this->data = new animal *[capacity];
    this->capacity = capacity;
    this->count = 0;
}

container::container() {
    int const DEFAULT_CAPACITY = 128;
    this->data = new animal *[DEFAULT_CAPACITY];
    this->capacity = DEFAULT_CAPACITY;
    this->count = 0;
}

container::~container() {
    for (int i = 0; i < this->count; ++i) {
        delete this->data[i];
    }
    delete[] this->data;
}

void container::remove(int idx) {
    if (idx >= count || idx < 0)
        return;
    if (idx == --count) {
        delete this->data[idx];
        return;
    }
    auto lastValue = data[count];
    auto idxValue = data[idx];

    data[count] = idxValue;
    data[idx] = lastValue;
    delete data[count];
}

void container::add(animal *value) {
    if (count >= capacity) {
        auto newData = new animal *[count << 1];
        for (int i = 0; i < count; ++i) {
            newData[i] = data[i];
        }
        delete[] this->data;
        data = newData;
        capacity = count << 1;
    }
    data[count++] = value;
}

animal *container::get(int idx) {
    if (idx >= count || idx < 0)
        return nullptr;
    return data[idx];
}

int container::size() const {
    return count;
}

void container::fill(FILE *in) {
    while (!feof(in)) {
        auto value = animal::read(in);
        if (value != nullptr) {
            add(value);
        }
    }
}

void container::fill() {
    for (int i = 0; i < this->capacity; i++) {
        add(animal::readRnd());
    }
}

void container::out(FILE *out) {
    for (int i = 0; i < this->count; i++) {
        fprintf(out, "%d. ", (i + 1));
        data[i]->out(out);
    }
}

template<typename T>
void swap(T &a, T &b) {
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}

void container::heapify(int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l]->someParameter() > data[largest]->someParameter())largest = l;
    if (r < n && data[r]->someParameter() > data[largest]->someParameter())largest = r;

    if (largest != i) {
        swap(data[i], data[largest]);
        heapify(n, largest);
    }
}

void container::heapSort() {
    int n = count;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(data[0], data[i]);
        heapify(i, 0);
    }
}
