#include "cocktail.h"

Cocktail::Cocktail(const QString& aName) {
    this->name = aName;
}

QString Cocktail::getName() const {
    return this->name;
}

QList<Position *> Cocktail::getPositions() const {
    return this->positions;
}

void Cocktail::addPosition(Position *aPosition) {
    this->positions.append(aPosition);
}
