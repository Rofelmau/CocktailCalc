#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>



class Ingredient
{
public:
    Ingredient(const QString& aName);

    QString getName() const;

private:
    QString name;


};

#endif // INGREDIENT_H
