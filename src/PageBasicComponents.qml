import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

Page{
    id: pageBasicComponents
    objectName: "pageBasicComponents"
    signal qmlSignal(string msg)

    Column {
        spacing: SettingsApp.marginCommon
        anchors.fill: parent

        TextField {
            id: field1
            objectName: "field1"
            placeholderText: qsTr("Input first number")
        }

        TextField {
            id: field2
            objectName: "field2"
            placeholderText: qsTr("Input second number")
        }

        Button {
            id: button
            text: qsTr("Download")
            onClicked: qmlSignal( qsTr("apples") )
        }

        ButtonGreen {
            id: button2
            text: qsTr("Download")
            onClicked: qmlSignal( qsTr("tables") )
            icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
        }

        ButtonBlue {
            id: button22
            text: qsTr("Console")
            onClicked: console.log( Qt.platform.os )
            icon:  IconFontAwesome { symbol: FontAwesome.fa_vk }
        }

        Button {
            id: button3
            text: qsTr("Download")
            enabled: false
            onClicked: qmlSignal( qsTr("images") )
            icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
        }

        Text {
            text: "Answer:"
            font.pixelSize: textArea.font.pixelSize
        }

        TextArea {
            id: textArea
            objectName: "textArea"
            wrapMode: TextArea.Wrap
            readOnly: true
            width: 250
        }

        Image {
            source: "qrc:/images/harrix_photo.png"
            width: 300
            height: 300
            smooth: true

            MouseAreaRipple {
                id: mouseAreaImage
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    console.log("image")
                }
            }
        }

        Text {
            text: "Сабж — исключение из золотого правила, гласящего, что каждый годный фантаст должен иметь еврейские корни: его отец был потомком англичан, понаехавших в эту вашу Америку нагибать индейцев, а мать и вовсе была шведкой. Семья любила повышать своё ЧСВ легендой, что бабка отца Мэри Брэдбери якобы была небезосновательно сожжена во время Салемской охоты на ведьм. Вообще, в семейке дичайше котировались всякие легенды, байки и крипипасты — достаточно сказать, что Рэй впоследствии сделал своих родственников прототипами семьи Эллиот, а уже от них его друг Чарльз Аддамс скопипастил свою знаменитую «Семейку Аддамс». Неудивительно, что Рэй тоже с детства «заболел» всякой чертовщиной и начал чуть ли не мнить себя тёмным колдуном. Некоторые предпосылки для этого имелись — например, Брэдбери утверждал, что ясно помнит момент своего рождения и всё, что происходило после (свои позитивные младенческие переживания он потом описал в рассказе «Маленький убийца»).
Впрочем, с колдунским поприщем особо не сложилось. К моменту окончания Рэем школы в Америке вовсю гуляла Великая Депрессия, и его выпнули на улицу продавать газеты. Даже в вуз он так и не поступил, ибо нищебродство. Всё свободное время будущий писатель хикковал в библиотеках, так как в те дни интернета не было. Позже он признавался, что все девушки, с которыми ему посчастливилось, были либо библиотекарями, либо продавщицами в книжных магазинах. Собственно, как и напарница по счастливому 56-летнему браку. Так как зарабатывать деньги Рэй нихуя не умел (сказывалось отсутствие ЕРЖ-компоненты в крови), то фактически он долго сидел на иждивении у жены, пока наконец не раскрутился как писатель."
            width: parent.width
            wrapMode: Text.Wrap
            anchors.margins: SettingsApp.marginCommon
        }
    }
}
