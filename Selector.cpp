#include "Selector.hpp"

Selector::Selector(QWidget *parent)
    : QMainWindow(parent)
    , ui(Ui::Selector())
{
    ui.setupUi(this);
}

Selector::~Selector()
{

}