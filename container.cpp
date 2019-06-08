#include "container.h"
#include "filedownloader.h"

#include <QStringList>

Container::Container() {

}

QList<Cocktail> Container::getCocktails() const {
    return this->cocktails;
}

QStringList Container::getCocktailsAsString() const {
    QStringList cocktailNames;

    foreach (Cocktail cocktail, this->cocktails) {
        cocktailNames << "HI"; //cocktail.getName();
    }

    return cocktailNames;
}

void Container::addCocktail(const Cocktail& aCocktail) {
    this->cocktails.append(aCocktail);
}

QList<Ingredient> Container::getIngredients() const {
    return this->ingredients;
}

QStringList Container::getIngredientsAsString() const {
    QStringList ingredientNames;

    foreach (Ingredient ingredient, this->ingredients) {
        ingredientNames << ingredient.getName();
    }

    return ingredientNames;
}

void Container::addIngredient(const Ingredient& aIngrident) {
    this->ingredients.append(aIngrident);
}
