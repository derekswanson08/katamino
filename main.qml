import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import com.swans.BoardModel 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Katamino")

    Column {
        Button {
            text: "Solve";
            onClicked: myBoard.solve();
        }

        GridView {
            width: 50*myBoard.level
            height: 50*5
            cellWidth: 50
            cellHeight: 50
            model: BoardModel {
                board: myBoard
            }
            delegate: Rectangle {
                width: 50
                height: 50
                color: model.color
            }
        }
    }
}
