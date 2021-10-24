#include "utils.h"

void Utils::RandomName(char *content, int size) {
    content[0] = toupper(char('a' + std::rand() % 26));
    for (int i = 1; i < size; ++i) {
        content[i] = char('a' + std::rand() % 26);
    }
    content[size] = '\0';
}

Utils::string::string(char *src) {
    if (src) {
        unsigned n = 0;
        while (src[n] != '\0') n++;
        capacity = n;
        data = new char[n + 1];
        for (int j = 0; j < n; j++)
            data[j] = src[j];
        data[capacity] = '\0';
    } else {
        capacity = 0;
        data = new char[0];
    }
}

int Utils::string::lenght() const {
    return capacity;
}

Utils::string::~string() {
    delete[] data;
    capacity = 0;
}

char *Utils::string::toCharArray() {
    return data;
}

char Utils::string::operator[](int i) const {
    if (i >= capacity || i < 0) throw 1;
    return data[i];
}

char &Utils::string::operator[](int i) {
    if (i >= capacity || i < 0) throw 1;
    return data[i];
}
