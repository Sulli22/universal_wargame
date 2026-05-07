import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: racineBoutonChoix
    property string couleurExtremiteGradient: ""
    property string couleurCentreGradient: ""
    font.pointSize: Math.max(12, layoutValidation.Layout.maximumHeight * 0.4)
    font.bold: true
    opacity: enabled ? 1 : 0.2

    background: Rectangle{
        radius: layoutValidation.Layout.maximumHeight/2

        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop {position: 0.0; color:couleurExtremiteGradient}
            GradientStop {position: 0.5; color: couleurCentreGradient}
            GradientStop {position: 1.0; color: couleurExtremiteGradient}
        }
    }
}
