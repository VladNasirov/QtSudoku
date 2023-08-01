import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property int rows: 9
    property int cols: 9
    property var sudokuData: [] // Ваша модель данных с числами для судоку (замените этот массив на свои данные)

    width: cols * cellSize
    height: rows * cellSize

    // Параметры для ячейки судоку
    property int cellSize: 50
    property color cellBorderColor: "black"
    property color cellFillColor: "white"

    // Отрисовка сетки судоку
    Repeater {
        model: rows * cols
        Rectangle {
            width: cellSize
            height: cellSize
            border.color: cellBorderColor
            color: cellFillColor

            // Размещение ячеек судоку в сетке
            x: (index % cols) * cellSize
            y: Math.floor(index / cols) * cellSize

            // Отображение числа в ячейке судоку (если число не равно 0)
            Text {
                text: sudokuData[index] !== 0 ? sudokuData[index].toString() : ""
                font.pixelSize: cellSize * 0.6
                anchors.centerIn: parent
            }
        }
    }
}
