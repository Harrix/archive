import QtQuick 2.7

pragma Singleton

QtObject {
    //Colors
    readonly property color colorBackground: "#fff"
    readonly property color colorFont: "#5f5f5f"
    readonly property color colorFontButton: "#fff"
    readonly property color colorRipple: "#fff"
    readonly property color colorNavigationDrawerDark: "#000"

    //Common colors
    readonly property color colorRed: "#de2b26"
    readonly property color colorRedLight: "#f54d4c"
    readonly property color colorRedDark: "#8d130f"
    readonly property color colorBlue: "#19a5a5"
    readonly property color colorBlueLight: "#71c2c2"
    readonly property color colorGreen: "#4abf60"
    readonly property color colorGreenLight: "#77cb87"

    //Fonts
    readonly property string fontName: "Open Sans"
    readonly property string fontNameCode: "PT Mono"
    readonly property int fontSize: 14
    readonly property int fontRenderType: Text.QtRendering
    readonly property int fontWeightButton: Font.Bold
    readonly property int fontCapitalizationButton: Font.AllUppercase

    //Indents
    readonly property int marginCommon: 10
    readonly property int spacingCommon: 10
    readonly property int spacingIconText: 6
    readonly property int paddingButton: 8
    readonly property int leftPaddingButton: 24
    readonly property int rightPaddingButton: 24
    readonly property int startDragDistance: 20

    //Sizes
    readonly property int widthWindow: 640
    readonly property int heightWindow: 480
    readonly property int widthNavigationDrawer: 320

    //EasingType
    readonly property int easingTypeRipple: Easing.Linear
    readonly property int easingTypeNavigationDrawer: Easing.OutBack
    readonly property int easingDarkNavigationDrawer: Easing.Linear

    //Durations
    readonly property int durationAnimation: 300

    //Opacities
    readonly property real opacityNotEnabled: 0.3
    readonly property real opacityRipple: 0.3
    readonly property real opacityDarkNavigationDrawer: 0.5

    //Opacities
    readonly property int cursorShapeRipple: Qt.PointingHandCursor
}
