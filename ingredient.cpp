#include "ingredient.h"

Ingredient::Ingredient(const QString& aName, const QString& anUnit) : name(aName), unit(anUnit) {

}


QString Ingredient::getName() const {
    return this->name;
}

QString Ingredient::getUnit() const {
    return this->unit;
}
