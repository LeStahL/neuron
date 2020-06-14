#include <QDebug>
#include <QApplication>

#include "Selector.hpp"
#include "Settings.hpp"
#include "DemoWindow.hpp"

int main(int argc, char **args)
{
    QApplication application(argc, args);
    Settings settings;
    DemoWindow demoWindow(&application, &settings);
    Selector selector(&application, &settings, &demoWindow);
    selector.show();
    return application.exec();
}
