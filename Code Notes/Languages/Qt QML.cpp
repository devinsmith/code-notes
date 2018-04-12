/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QT MODELING LANGUAGE (QML)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

import QtQuick 2.6
import QtQuick.Controls 1.4
import MyEnums 1.0

id: nameOfControl                      // unique id of element, can be used to access it
objectName: "UserName"                 // user defined name
anchors.left: parent.left              // don't use with RowLayout, use Layout.fillWidth
anchors.right: parent.right            // don't use with RowLayout, use Layout.fillWidth
anchors.left: parent.left              // don't use with ColumnLayout, use Layout.fillHeight
anchors.right: parent.right            // don't use with ColumnLayout, use Layout.fillHeight
anchors.fill: parent                   // completely fills to parent
anchors.margins: 1                     // adds margins between the anchor
property bool myProperty: true         // custom property
property int myEnum: MyEnum.ONE        // enum property
property int myProperty: myFunction    // if property used in function changes, re-evaluates property
property alias myAlias: myProperty     // reference for property
    
/* Called when the element has been instantiated */
Component.onCompleted: {}

/* Called when the element is destroyed */
Component.onDestruction: {}

/* Called when the property has changed */
onMyPropertyChanged: {}

/* Javascript custom function */
function myFunction(x, y) {
    return x + y;
}

Qt.quit() // Quits the application
console.log("Message")

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML COMPONENTS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Item {
}

MouseArea {
    hoverEnabled: true
    acceptedButtons: Qt.RightButton | Qt.LeftButton | Qt.AllButtons
    onPressed: {}
    onRelease: {}
    onClicked: {
        var clickX = mouse.x;
        var clickY = mouse.y;
        var button = mouse.button;
    }
}

// Call using id.popup() to show at mouse position
Menu {
    visible: false
    MenuItem {
        text: "Item"
        iconSource: "qrc:///icon.png"
        enabled: true
        onTriggered: {}
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML LAYOUTS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
Layout.fillHeight: true
Layout.fillWidth: true
Layout.preferredHeight: 30
Layout.preferredWidth: 30

// Aligns elements after each other in a single row
RowLayout {
    spacing: 5
    anchors.fill: parent // Still use anchors on base
}

// Aligns elements after each other in a single column
ColumnLayout {
    spacing: 5
    anchors.fill: parent // Still use anchors on base
}

// Aligns elements in a grid with n columns
GridLayout {
    columns: 3
    spacing: 5
    anchors.fill: parent // Still use anchors on base
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML WIDGETS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Rectangle {
    color: "#8EACFF"
    radius: 2
    border.color: "red"
    border.width: 1      
}

Text {
    text: "text"
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
    font.bold: true
}

Button {
    iconSource: "qrc:///icon.png"
    enabled: true
    onClicked: {}
}

ProgressBar {
    maximumValue: 20
    minimumValue: 0
    style: ProgressBarStyle {
        background: Rectangle {
            radius: 2
            color: "grey"
            implicitWidth: 100
            implicitHeight: 20
        }
        progress: Rectangle {
            color: "blue"
        }
    }
}

Dialog {
    visible: false // Turning on/off will show dialog window
    title: "Title"
    width: 300
    height: 80
    contentItem: Rectangle {
        anchors.fill: parent
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML VIEWS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ScrollView {
    Layout.fillWidth: true
    Layout.fillHeight: true
    ListView {
        id: listView
        Layout.fillWidth: true
        Layout.fillHeight: true
        model: context_model // Set through C++

        onCurrentIndexChanged: {
            console.log("Selected " + currentIndex);
        }          
        onCurrentItemChanged: {
            console.log("Selected " + currentItem);
        }
        
        // Each item of the model is instantiated with the delegate
        delegate: Item {
            property bool isHighlighted: mouseArea.containsMouse
            property bool isSelected: listView.currentIndex == index
            MouseArea {
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.RightButton | Qt.LeftButton
                onPressed: { listView.currentIndex = index; }
                onClicked: { listView.currentIndex = index; }
            }                   
            Text {
                width: listView.width
                height: 30
                text: role_name // Set through C++
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML OPTIMIZATIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*************************************************************************************************************
PROPERTY OPTIMIZATIONS:
• Avoid declaring with var keyword unless type is QVariantMap/variant
• Using a propery resolves it; faster to store result in local and access that
      var rectColor = rect.color; // resolve the common base.
      printValue("red", rectColor.r);
      printValue("green", rectColor.g)
• Avoid lots of writes to Q_PROPERTIES especially if has notify signal, pefer temp while initialising
      var tempProperty = [];
      tempProperty.length = 100;
      for (var i = 0; i < 100; ++i) {
          tempProperty[i] = i;
      }
      qProperty = tempProperty;
• Avoid binding as container[index] as it will re-evaluate when any container member is changed, do instead
      property int intermediateBinding: cointainer[index]
      property int firstBinding: intermediateBinding + x;
      property int secondBinding: intermediateBinding + y;

PROPERTY BINDING OPTIMZATIONS:
• Avoid declaring intermediate JavaScript variables
• Avoid accessing "var" properties
• Avoid calling JavaScript functions
• Avoid constructing closures or defining functions within the binding expression
• Avoid accessing properties outside of the immediate evaluation scope (non-component properties)
• Avoid writing to other properties
• Prefer binding to anchors over using another component's height/width properties

JAVASCRIPT OPTIMIZATIONS:
• Avoid using eval() if at all possible
• Do not delete properties of objects
• Don't manually invoke the garbage collector

COMPONENT OPTIMIZATIONS:
• If a component has a custom property, it becomes its own implicit type. 
  If more than one of these used, move to own file to save memory
• Consider using an asynchronous Loader component
• Prefer Item over invisible Rectangles
• For global data, use singleton types instead of pragma library scripts
  
RENDERING OPTIMIZATIONS:
• Set asynchronous property of images to true for loading
• Set sourceSize property for images to the exact size you want to ensure only what's needed is cached
• Avoid smoothing images using the smooth property
• May be better to disable bindings before and animation and re-enable once finished
• Avoid running JavaScript during animation
• Avoid enabling clipping
• Opaque faster than translucent, only one pixel needed to be considered translucent

MODEL/VIEW OPTIMIZATIONS
• Use WorkerScript with ListModel to move processing to another thread if needed
• Avoid setting the ListModel dynamicRoles property to true
• Avoid using ShaderEffect elements within delegates
• Never enable clipping on a delegate
• Use view cacheBuffer property to allow asynchronous creation and buffering of
  delegates outside of the visible area, at a memory usage increase cost
**************************************************************************************************************/
