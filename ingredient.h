#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>



class Ingredient
{
public:
    Ingredient(const QString& aName, const QString& anUnit);

    QString getName() const;

    QString getUnit() const;

private:
    QString name;

    QString unit;


};

#endif // INGREDIENT_H
