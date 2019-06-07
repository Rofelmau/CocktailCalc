#include "ingredient.h"

Ingredient::Ingredient(const QString& aName) : name(aName) {

}


QString Ingredient::getName() const {
    return this->name;
}
