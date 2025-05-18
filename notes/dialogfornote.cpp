#include "dialogfornote.h"
#include "ui_dialogfornote.h"


dialogfornote::dialogfornote(QWidget* parent)
    : QWidget(parent), ui(new Ui::dialogfornote) {
    ui->setupUi(this);
}

dialogfornote::~dialogfornote() {
    delete ui;
}

void dialogfornote::SetManager(Manager* manager) {
    this->manager = manager;
}
