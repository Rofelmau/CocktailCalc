#include "position.h"

Position::Position(Ingredient *anIngredient, const double anAmount) : ingredient(anIngredient), amount(anAmount) {

}

Ingredient* Position::getIngredient() const {
    return this->ingredient;
}

double Position::getAmount() const {
    return this->amount;
}
