/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *testLabel;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(1160, 665);
        testLabel = new QLabel(About);
        testLabel->setObjectName("testLabel");
        testLabel->setGeometry(QRect(90, 90, 1041, 421));
        QFont font;
        font.setPointSize(50);
        testLabel->setFont(font);

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Form", nullptr));
        testLabel->setText(QCoreApplication::translate("About", "TESTING LABEL - ABOUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
