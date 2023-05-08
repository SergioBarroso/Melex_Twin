/********************************************************************************
** Form generated from reading UI file 'localUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALUI_H
#define UI_LOCALUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_local_guiDlg
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_acc;
    QFrame *frame_plot;

    void setupUi(QWidget *local_guiDlg)
    {
        if (local_guiDlg->objectName().isEmpty())
            local_guiDlg->setObjectName(QString::fromUtf8("local_guiDlg"));
        local_guiDlg->resize(972, 647);
        verticalLayout = new QVBoxLayout(local_guiDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_acc = new QFrame(local_guiDlg);
        frame_acc->setObjectName(QString::fromUtf8("frame_acc"));
        frame_acc->setFrameShape(QFrame::StyledPanel);
        frame_acc->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_acc);

        frame_plot = new QFrame(local_guiDlg);
        frame_plot->setObjectName(QString::fromUtf8("frame_plot"));
        frame_plot->setFrameShape(QFrame::StyledPanel);
        frame_plot->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_plot);


        retranslateUi(local_guiDlg);

        QMetaObject::connectSlotsByName(local_guiDlg);
    } // setupUi

    void retranslateUi(QWidget *local_guiDlg)
    {
        local_guiDlg->setWindowTitle(QApplication::translate("local_guiDlg", "Path follower", nullptr));
    } // retranslateUi

};

namespace Ui {
    class local_guiDlg: public Ui_local_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALUI_H
