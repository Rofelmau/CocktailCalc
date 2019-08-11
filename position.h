#ifndef POSITION_H
#define POSITION_H

#include "ingredient.h"

class Position {

    public:
        Position(Ingredient *anIngredient, const double anAmount);

        Ingredient* getIngredient() const;

        double getAmount() const;

    private:
        Ingredient *ingredient;

        double amount;
};

#endif // POSITION_H
