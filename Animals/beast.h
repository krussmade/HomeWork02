#ifndef __beast__
#define __beast__

#include "animal.h"

class beast : public animal {
public:
    enum Diet{
        PREDATOR = 0,
        HERBIVOROUS = 1,
        INSECTIVORES = 2
    };
private:
    Diet diet;
public:
    beast(char *name, int weight, Diet diet);
    void out(FILE *out) override;
    ~beast() override;
};
#endif