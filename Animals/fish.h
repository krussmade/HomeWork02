#ifndef __fish__
#define __fish__

#include "animal.h"

class fish : public animal {
public:
    enum Habitat {
        SEA = 0,
        LAKE = 1,
        RIVER = 2,
        OCEAN = 3,
        POND = 4
    };
private:
    Habitat habitat;
public:
    fish(char *name, int weight, Habitat habitat);

    void out(FILE *out) override;

    ~fish() override;
};

#endif