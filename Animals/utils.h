#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <xlocinfo>
#include "constants.h"

namespace Utils {
    void RandomName(char *content, int size);

    class string {
        char *data;
        int capacity;
    public:
        explicit string(char *src);

        int lenght() const;

        char* toCharArray();

        char operator[] (int i) const;

        char& operator[] (int i);

        ~string();
    };
}
#endif