import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        Button {
            text: "Solve";
            onClicked: myBoard.solve();
        }

        Grid {
            rows: 5
            columns: 8
            Rectangle { id: rec0; color:  myBoard.color0;  width: 50; height: 50 }
            Rectangle { id: rec1; color:  myBoard.color1;  width: 50; height: 50 }
            Rectangle { id: rec2; color:  myBoard.color2;  width: 50; height: 50 }
            Rectangle { id: rec3; color:  myBoard.color3;  width: 50; height: 50 }
            Rectangle { id: rec4; color:  myBoard.color4;  width: 50; height: 50 }
            Rectangle { id: rec5; color:  myBoard.color5;  width: 50; height: 50 }
            Rectangle { id: rec6; color:  myBoard.color6;  width: 50; height: 50 }
            Rectangle { id: rec7; color:  myBoard.color7;  width: 50; height: 50 }
            Rectangle { id: rec8; color:  myBoard.color8;  width: 50; height: 50 }
            Rectangle { id: rec9; color:  myBoard.color9;  width: 50; height: 50 }
            Rectangle { id: rec10; color: myBoard.color10; width: 50; height: 50 }
            Rectangle { id: rec11; color: myBoard.color11; width: 50; height: 50 }
            Rectangle { id: rec12; color: myBoard.color12; width: 50; height: 50 }
            Rectangle { id: rec13; color: myBoard.color13; width: 50; height: 50 }
            Rectangle { id: rec14; color: myBoard.color14; width: 50; height: 50 }
            Rectangle { id: rec15; color: myBoard.color15; width: 50; height: 50 }
            Rectangle { id: rec16; color: myBoard.color16; width: 50; height: 50 }
            Rectangle { id: rec17; color: myBoard.color17; width: 50; height: 50 }
            Rectangle { id: rec18; color: myBoard.color18; width: 50; height: 50 }
            Rectangle { id: rec19; color: myBoard.color19; width: 50; height: 50 }
            Rectangle { id: rec20; color: myBoard.color20; width: 50; height: 50 }
            Rectangle { id: rec21; color: myBoard.color21; width: 50; height: 50 }
            Rectangle { id: rec22; color: myBoard.color22; width: 50; height: 50 }
            Rectangle { id: rec23; color: myBoard.color23; width: 50; height: 50 }
            Rectangle { id: rec24; color: myBoard.color24; width: 50; height: 50 }
            Rectangle { id: rec25; color: myBoard.color25; width: 50; height: 50 }
            Rectangle { id: rec26; color: myBoard.color26; width: 50; height: 50 }
            Rectangle { id: rec27; color: myBoard.color27; width: 50; height: 50 }
            Rectangle { id: rec28; color: myBoard.color28; width: 50; height: 50 }
            Rectangle { id: rec29; color: myBoard.color29; width: 50; height: 50 }
            Rectangle { id: rec30; color: myBoard.color30; width: 50; height: 50 }
            Rectangle { id: rec31; color: myBoard.color31; width: 50; height: 50 }
            Rectangle { id: rec32; color: myBoard.color32; width: 50; height: 50 }
            Rectangle { id: rec33; color: myBoard.color33; width: 50; height: 50 }
            Rectangle { id: rec34; color: myBoard.color34; width: 50; height: 50 }
            Rectangle { id: rec35; color: myBoard.color35; width: 50; height: 50 }
            Rectangle { id: rec36; color: myBoard.color36; width: 50; height: 50 }
            Rectangle { id: rec37; color: myBoard.color37; width: 50; height: 50 }
            Rectangle { id: rec38; color: myBoard.color38; width: 50; height: 50 }
            Rectangle { id: rec39; color: myBoard.color39; width: 50; height: 50 }

        }
    }
}
