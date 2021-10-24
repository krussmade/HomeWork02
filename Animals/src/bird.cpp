#include "../bird.h"

bird::bird(char *name, int weight, bool isMigration) {
    this->name = new Utils::string(name);
    this->weight = weight;
    this->isMigration = isMigration;
}

void bird::out(FILE *out) {
    fprintf(out, "[Bird]\n"
                 "-name: %s\n"
                 "-weight: %d\n"
                 "-migration %d\n"
                 "-function result: %lf\n\n", name->toCharArray(), weight, (int) isMigration, someParameter());
}

bird::~bird() = default;
