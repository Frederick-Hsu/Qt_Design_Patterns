#include "CardPics.h"
#include <QChar>

#include <QCoreApplication>

const QString CardPics::values = "23456789tjqka";
const QString CardPics::suits = "cdhs";

CardPics::CardPics(QObject* parent) : QObject(parent)
{
    foreach (QChar suit, suits)
    {
        foreach (QChar value, values)
        {
            QString card = QString("%1%2").arg(value).arg(suit);
            QImage image(fileName(card));
            m_Images[card] = image;
        }
    }
}

CardPics::~CardPics()
{
}

CardPics* CardPics::instance()
{
    static CardPics* inst = nullptr;
    if (inst == nullptr)
    {
        inst = new CardPics(qApp);
    }
    return inst;
}

QString CardPics::fileName(QString card)
{
    return QString(":/new/icons/images/%1.png").arg(card);
}

QImage CardPics::get(QString card) const
{
    return m_Images.value(card.toLower(), QImage());
}
