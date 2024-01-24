#include "statebar.h"
#include <QDebug>
stateBar::stateBar(QObject *parent) : QObject(parent)
{
    qDebug()<<"test";
}

int stateBar::getInfo()
{
    return this->info;
}

void stateBar::setInfo(stateBar::AlgoState select)
{
    info = select;
}
