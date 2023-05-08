# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainUI.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_guiDlg(object):
    def setupUi(self, guiDlg):
        if not guiDlg.objectName():
            guiDlg.setObjectName(u"guiDlg")
        guiDlg.resize(731, 908)
        self.emergency_melex_1 = QPushButton(guiDlg)
        self.emergency_melex_1.setObjectName(u"emergency_melex_1")
        self.emergency_melex_1.setGeometry(QRect(630, 280, 91, 25))
        self.emergency_melex_1.setStyleSheet(u"background-color: rgb(204, 0, 0);")
        self.label = QLabel(guiDlg)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(10, 280, 67, 17))
        self.label_2 = QLabel(guiDlg)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(10, 310, 67, 17))
        self.emergency_melex_2 = QPushButton(guiDlg)
        self.emergency_melex_2.setObjectName(u"emergency_melex_2")
        self.emergency_melex_2.setGeometry(QRect(630, 310, 91, 25))
        self.emergency_melex_2.setStyleSheet(u"background-color: rgb(204, 0, 0);")
        self.busy_melex_1 = QPushButton(guiDlg)
        self.busy_melex_1.setObjectName(u"busy_melex_1")
        self.busy_melex_1.setGeometry(QRect(230, 280, 89, 21))
        self.busy_melex_2 = QPushButton(guiDlg)
        self.busy_melex_2.setObjectName(u"busy_melex_2")
        self.busy_melex_2.setGeometry(QRect(230, 310, 89, 21))
        self.start_melex_2 = QPushButton(guiDlg)
        self.start_melex_2.setObjectName(u"start_melex_2")
        self.start_melex_2.setGeometry(QRect(530, 310, 89, 21))
        self.start_melex_1 = QPushButton(guiDlg)
        self.start_melex_1.setObjectName(u"start_melex_1")
        self.start_melex_1.setGeometry(QRect(530, 280, 89, 21))
        self.intention_melex_2 = QPushButton(guiDlg)
        self.intention_melex_2.setObjectName(u"intention_melex_2")
        self.intention_melex_2.setGeometry(QRect(330, 310, 89, 21))
        self.intention_melex_1 = QPushButton(guiDlg)
        self.intention_melex_1.setObjectName(u"intention_melex_1")
        self.intention_melex_1.setGeometry(QRect(330, 280, 89, 21))
        self.path_melex_2 = QPushButton(guiDlg)
        self.path_melex_2.setObjectName(u"path_melex_2")
        self.path_melex_2.setGeometry(QRect(430, 310, 89, 21))
        self.path_melex_1 = QPushButton(guiDlg)
        self.path_melex_1.setObjectName(u"path_melex_1")
        self.path_melex_1.setGeometry(QRect(430, 280, 89, 21))
        self.progress_list = QTreeWidget(guiDlg)
        self.progress_list.setObjectName(u"progress_list")
        self.progress_list.setGeometry(QRect(10, 30, 711, 71))
        self.label_3 = QLabel(guiDlg)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(10, 110, 67, 17))
        self.label_4 = QLabel(guiDlg)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(10, 10, 91, 17))
        self.melex_state_1 = QLabel(guiDlg)
        self.melex_state_1.setObjectName(u"melex_state_1")
        self.melex_state_1.setGeometry(QRect(70, 280, 151, 20))
        self.melex_state_1.setAlignment(Qt.AlignCenter)
        self.requests_list = QTreeWidget(guiDlg)
        self.requests_list.setObjectName(u"requests_list")
        self.requests_list.setGeometry(QRect(10, 130, 711, 141))
        self.melex_state_2 = QLabel(guiDlg)
        self.melex_state_2.setObjectName(u"melex_state_2")
        self.melex_state_2.setGeometry(QRect(70, 310, 151, 20))
        self.melex_state_2.setAlignment(Qt.AlignCenter)
        self.label_5 = QLabel(guiDlg)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setGeometry(QRect(110, 340, 531, 551))
        self.label_5.setPixmap(QPixmap(u"../../../../../../../../Downloads/asdf.jpg"))
        self.label_5.setScaledContents(False)

        self.retranslateUi(guiDlg)

        QMetaObject.connectSlotsByName(guiDlg)
    # setupUi

    def retranslateUi(self, guiDlg):
        guiDlg.setWindowTitle(QCoreApplication.translate("guiDlg", u"api_communicator", None))
        self.emergency_melex_1.setText(QCoreApplication.translate("guiDlg", u"Stop", None))
        self.label.setText(QCoreApplication.translate("guiDlg", u"Melex 1", None))
        self.label_2.setText(QCoreApplication.translate("guiDlg", u"Melex 2", None))
        self.emergency_melex_2.setText(QCoreApplication.translate("guiDlg", u"Stop", None))
        self.busy_melex_1.setText(QCoreApplication.translate("guiDlg", u"Change busy", None))
        self.busy_melex_2.setText(QCoreApplication.translate("guiDlg", u"Change busy", None))
        self.start_melex_2.setText(QCoreApplication.translate("guiDlg", u"Start", None))
        self.start_melex_1.setText(QCoreApplication.translate("guiDlg", u"Start", None))
        self.intention_melex_2.setText(QCoreApplication.translate("guiDlg", u"Intention", None))
        self.intention_melex_1.setText(QCoreApplication.translate("guiDlg", u"Intention", None))
        self.path_melex_2.setText(QCoreApplication.translate("guiDlg", u"Path", None))
        self.path_melex_1.setText(QCoreApplication.translate("guiDlg", u"Path", None))
        ___qtreewidgetitem = self.progress_list.headerItem()
        ___qtreewidgetitem.setText(5, QCoreApplication.translate("guiDlg", u"arrivalStop", None));
        ___qtreewidgetitem.setText(4, QCoreApplication.translate("guiDlg", u"long", None));
        ___qtreewidgetitem.setText(3, QCoreApplication.translate("guiDlg", u"lat", None));
        ___qtreewidgetitem.setText(2, QCoreApplication.translate("guiDlg", u"pickupStop", None));
        ___qtreewidgetitem.setText(1, QCoreApplication.translate("guiDlg", u"car", None));
        ___qtreewidgetitem.setText(0, QCoreApplication.translate("guiDlg", u"id", None));
        self.label_3.setText(QCoreApplication.translate("guiDlg", u"Requests", None))
        self.label_4.setText(QCoreApplication.translate("guiDlg", u"In progress", None))
        self.melex_state_1.setText("")
        ___qtreewidgetitem1 = self.requests_list.headerItem()
        ___qtreewidgetitem1.setText(5, QCoreApplication.translate("guiDlg", u"arrivalStop", None));
        ___qtreewidgetitem1.setText(4, QCoreApplication.translate("guiDlg", u"long", None));
        ___qtreewidgetitem1.setText(3, QCoreApplication.translate("guiDlg", u"lat", None));
        ___qtreewidgetitem1.setText(2, QCoreApplication.translate("guiDlg", u"pickupStop", None));
        ___qtreewidgetitem1.setText(1, QCoreApplication.translate("guiDlg", u"car", None));
        ___qtreewidgetitem1.setText(0, QCoreApplication.translate("guiDlg", u"id", None));
        self.melex_state_2.setText("")
        self.label_5.setText("")
    # retranslateUi

