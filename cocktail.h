#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <QString>
#include <QList>

#include <position.h>

class Cocktail {
    public:
        Cocktail(const QString& aName);

        QString getName() const;

        QList<Position *> getPositions() const;

        void addPosition(Position *aPosition);

private:
        QString name;

        QList<Position *> positions;
};

#endif // COCKTAIL_H
