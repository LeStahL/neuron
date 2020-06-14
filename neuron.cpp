#include <QDebug>
#include <QApplication>

#include "Selector.hpp"

int main(int argc, char **args)
{
    QApplication application(argc, args);
    Selector selector(&application);
    selector.show();
    return application.exec();
}
