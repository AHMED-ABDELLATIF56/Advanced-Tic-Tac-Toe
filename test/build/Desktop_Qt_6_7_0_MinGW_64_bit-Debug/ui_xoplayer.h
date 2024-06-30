/********************************************************************************
** Form generated from reading UI file 'xoplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XOPLAYER_H
#define UI_XOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_xoplayer
{
public:

    void setupUi(QDialog *xoplayer)
    {
        if (xoplayer->objectName().isEmpty())
            xoplayer->setObjectName("xoplayer");
        xoplayer->resize(400, 300);

        retranslateUi(xoplayer);

        QMetaObject::connectSlotsByName(xoplayer);
    } // setupUi

    void retranslateUi(QDialog *xoplayer)
    {
        xoplayer->setWindowTitle(QCoreApplication::translate("xoplayer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class xoplayer: public Ui_xoplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XOPLAYER_H
