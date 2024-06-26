/********************************************************************************
** Form generated from reading UI file 'medium.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIUM_H
#define UI_MEDIUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_medium
{
public:

    void setupUi(QDialog *medium)
    {
        if (medium->objectName().isEmpty())
            medium->setObjectName("medium");
        medium->resize(400, 300);

        retranslateUi(medium);

        QMetaObject::connectSlotsByName(medium);
    } // setupUi

    void retranslateUi(QDialog *medium)
    {
        medium->setWindowTitle(QCoreApplication::translate("medium", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class medium: public Ui_medium {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIUM_H
