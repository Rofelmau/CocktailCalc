#ifndef CONTAINER_H
#define CONTAINER_H

#include "cocktail.h"
#include "ingredient.h"

#include <QList>



class Container {

public:
    static Container& instance() {
           static Container _instance;
           return _instance;
    }

    ~Container() {}

    QList<Cocktail> getCocktails() const;
    QStringList getCocktailsAsString() const;
    void addCocktail(const Cocktail& aCocktail);

    QList<Ingredient> getIngredients() const;
    QStringList getIngredientsAsString() const;
    void addIngredient(const Ingredient& aIngrident);

private:

    QList<Cocktail> cocktails;
    QList<Ingredient> ingredients;

    Container() {}
    Container( const Container& );
    Container & operator = (const Container &);

};

#endif // CONTAINER_H
