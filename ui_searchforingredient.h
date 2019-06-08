/********************************************************************************
** Form generated from reading UI file 'searchforingredient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORINGREDIENT_H
#define UI_SEARCHFORINGREDIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QComboBox *selectIngredientComboBox;
    QListView *listView;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(279, 20, 111, 24));
        selectIngredientComboBox = new QComboBox(Form);
        selectIngredientComboBox->setObjectName(QString::fromUtf8("selectIngredientComboBox"));
        selectIngredientComboBox->setGeometry(QRect(30, 20, 231, 24));
        listView = new QListView(Form);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(35, 91, 351, 201));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QApplication::translate("Form", "Suche starten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORINGREDIENT_H
