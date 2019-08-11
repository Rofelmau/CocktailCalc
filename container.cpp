#include "container.h"
#include "filedownloader.h"

#include <QStringList>

Container::Container() {

}

QList<Cocktail*> Container::getCocktails() const {
    return this->cocktails;
}

QStringList Container::getCocktailsAsString() const {
    QStringList cocktailNames;

    foreach (Cocktail *currentCocktail, this->cocktails) {
        cocktailNames << currentCocktail->getName();
    }

    return cocktailNames;
}

void Container::addCocktail(Cocktail* aCocktail) {
    this->cocktails.append(aCocktail);
}

QList<Ingredient*> Container::getIngredients() const {
    return this->ingredients;
}

QStringList Container::getIngredientsAsString() const {
    QStringList ingredientNames;

    foreach (Ingredient *ingredient, this->ingredients) {
        ingredientNames << ingredient->getName();
    }

    return ingredientNames;
}

void Container::addIngredient(Ingredient* aIngrident) {
    this->ingredients.append(aIngrident);
}

Ingredient* Container::findIngredientByName(const QString& aName) const {
    Ingredient *searchedIngredient = nullptr;
    foreach (Ingredient *currentIngredient, this->ingredients) {
        if (currentIngredient->getName() == aName) {
            searchedIngredient = currentIngredient;
            break;
        }
    }

    return searchedIngredient;
}

Cocktail* Container::findCocktailByName(const QString& aName) const {
    Cocktail *searchedCocktail = nullptr;
    foreach (Cocktail *currentCocktail, this->cocktails) {
        if (currentCocktail->getName() == aName) {
            searchedCocktail = currentCocktail;
            break;
        }
    }

    return searchedCocktail;
}

