#ifndef STYLES_H
#define STYLES_H
#include <QString>

namespace StyleHelper {
const QString comboBoxStyle = R"(
        QComboBox {
            background-color: #FFFFFF;
            color: #1E2350;
            border: 1px solid #ccc;
            border-radius: 8px;
            padding: 6px 30px 6px 10px;
            font-size: 14px;
            min-width: 150px;
        }

        QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 25px;
            border-left: 1px solid #ccc;
            background-color: #f0f0f0;
            border-top-right-radius: 8px;
            border-bottom-right-radius: 8px;
        }

        QComboBox::down-arrow {
            image: url(:/icons/down-arrow.png); /* Replace with actual icon or remove */
            width: 14px;
            height: 14px;
        }

        QComboBox QAbstractItemView {
            background-color: #ffffff;
            selection-background-color: #dcefff;
            color: #1E2350;
            border: 1px solid #ccc;
            border-radius: 6px;
            outline: none;
        }
    )";
}
#endif // STYLES_H
