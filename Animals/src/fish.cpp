#include "../fish.h"


fish::fish(char *name, int weight, fish::Habitat habitat) {
    this->name = new Utils::string(name);
    this->weight = weight;
    this->habitat = habitat;
}

void fish::out(FILE *out) {
    fprintf(out, "[Fish]\n"
                 "-name: %s\n"
                 "-weight: %d\n"
                 "-habitat %d\n"
                 "-function result: %lf\n\n", name->toCharArray(), weight, (int) habitat, someParameter());
}

fish::~fish() = default;
