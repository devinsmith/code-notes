/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML GRAPHICS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// RECTANGLE
// import QtQuick 2.11
// Inherits Item
Rectangle {
    color: "red"
    radius: 2
    antialiasing: true // Default true if using radius, false otherwise, gives performance hit
    border.color: "red"
    border.width: 1
    gradient: Gradient {}
}

// Slice off rounded corners on one side
Item {
    anchors.fill: parent
    clip: true
    Rectangle {
        anchors.fill: parent
        anchors.topMargin: -radius
        radius: 10
    }
}    

------------------------------------------------------------------------------------------------------------

// IMAGE
// import QtQuick 2.11
// SVG must have <style type="text/css"> not <style>
// Can have artifacts if some graphics effects are children
Image {
    asynchronous
    autoTransform
    cache
    fillMode
    horizontalAlignment
    mipmap
    mirror
    paintedHeight
    paintedWidth
    progress
    smooth
    source
    sourceSize
    status
    verticalAlignment
    
    // Image with rounded corners
    OpacityMask {
        maskSource: Rectangle {
            anchors.fill: parent
            radius: 6
        }  
    }
}

------------------------------------------------------------------------------------------------------------

// BORDERIMAGE
// import QtQuick 2.11
// Inherits Item, paints a border based on an image
BorderImage {
    asynchronous
    border.left 
    border.right 
    border.top 
    border.bottom 
    cache
    horizontalTileMode
    mirror
    progress
    smooth
    source
    sourceSize 
    status
    verticalTileMode
}

------------------------------------------------------------------------------------------------------------

// TRANSITION
// import QtQuick 2.11
// Defines animated transitions that occur on state changes
Transition {
    animations
    enabled
    from
    reversible
    running
    to    
}

------------------------------------------------------------------------------------------------------------
   
// BLEND
// import QtGraphicalEffects 1.0
// Inherits Item, Merges two source items by using a blend mode
Blend {
    cached
    foregroundSource
    mode
    source
}
 
------------------------------------------------------------------------------------------------------------
 
// BRIGHTNESSCONTRAST
// import QtGraphicalEffects 1.0    
// Inherits Item, Adjusts brightness and contrast
BrightnessContrast {
    brightness
    cached
    contrast
    source    
}

------------------------------------------------------------------------------------------------------------

// COLOROVERLAY
// import QtGraphicalEffects 1.0    
// Inherits Item, Alters the colors of the source item by applying an overlay color
ColorOverlay {
    cached
    color
    source    
}

------------------------------------------------------------------------------------------------------------

// COLORIZE
// import QtGraphicalEffects 1.0    
// Inherits Item, Sets the color in the HSL color space
Colorize {
    cached
    color
    source    
}

------------------------------------------------------------------------------------------------------------

// DESATURATE
// import QtGraphicalEffects 1.0    
// Inherits Item, Reduces the saturation of the colors
Desaturate {
    cached
    desaturation
    source    
}

------------------------------------------------------------------------------------------------------------

// GAMMAADJUST
// import QtGraphicalEffects 1.0    
// Inherits Item, Alters the luminance of the source item
GammaAdjust {
    cached
    gamma
    source    
}

------------------------------------------------------------------------------------------------------------

// HUESATURATION
// import QtGraphicalEffects 1.0    
// Inherits Item, Alters the source item colors in the HSL color space
HueSaturation {
    cached
    hue
    lightness 
    saturation
    source
}

------------------------------------------------------------------------------------------------------------

// LEVELADJUST
// import QtGraphicalEffects 1.0    
// Inherits Item, Adjusts color levels in the RGBA color space
LevelAdjust {
    cached
    gamma
    maximumInput
    maximumOutput
    minimumInput
    minimumOutput
    source    
}

------------------------------------------------------------------------------------------------------------

// GRADIENT
// import QtQuick 2.11
Gradient {
    stops
}

------------------------------------------------------------------------------------------------------------

// CONICALGRADIENT
// import QtGraphicalEffects 1.0
// Inherits Item, Draws a conical gradient
ConicalGradient {
    angle
    cached
    gradient
    horizontalOffset
    source
    verticalOffset    
}

------------------------------------------------------------------------------------------------------------

// LINEARGRADIENT
// import QtGraphicalEffects 1.0
// Inherits Item, Draws a linear gradient
LinearGradient {
    cached
    end
    gradient
    source
    start    
}

------------------------------------------------------------------------------------------------------------

// RADIALGRADIENT
// import QtGraphicalEffects 1.0    
// Inherits Item, Draws a radial gradient
RadialGradient {
    angle
    cached
    gradient
    horizontalOffset
    horizontalRadius
    source
    verticalOffset
    verticalRadius    
}

------------------------------------------------------------------------------------------------------------

// DISPLACE
// import QtGraphicalEffects 1.0    
// Inherits Item, Moves the pixels of the source item according to a displacement map
Displace {
    cached
    displacement
    displacementSource
    source    
}

------------------------------------------------------------------------------------------------------------

// DROPSHADOW
// import QtGraphicalEffects 1.0    
// Inherits Item, Generates a soft shadow behind the source item
DropShadow {
    cached
    color
    horizontalOffset
    radius
    samples
    source
    spread
    transparentBorder
    verticalOffset    
}

------------------------------------------------------------------------------------------------------------

// INNERSHADOW
// import QtGraphicalEffects 1.0    
// Inherits Item, Generates a colorized and blurred shadow inside the source
InnerShadow {
    cached
    color
    fast
    horizontalOffset
    radius
    samples
    source
    spread
    verticalOffset
}

------------------------------------------------------------------------------------------------------------

// FASTBLUR
// import QtGraphicalEffects 1.0    
// Inherits Item, Applies a fast blur effect to one or more source items
FastBlur {
    id: fastBlur
    radius: 64 // Amount of blurring [0,64]
    cached
    transparentBorder   
    source: ShaderEffectSource {
        sourceItem: myItem // Can't be parent of fastBlur
        sourceRect: Qt.rect(0, 0, fastBlur.width, fastBlur.height)
    }
}

------------------------------------------------------------------------------------------------------------

// GAUSSIANBLUR
// import QtGraphicalEffects 1.0    
// Inherits Item, Applies a higher quality blur effect
GaussianBlur {
    cached
    deviation
    radius
    samples
    source
    transparentBorder    
}

------------------------------------------------------------------------------------------------------------

// MASKEDBLUR
// import QtGraphicalEffects 1.0    
// Inherits Item, Applies a blur effect with a varying intesity
MaskedBlur {
    cached
    maskSource
    radius
    samples
    source    
}

------------------------------------------------------------------------------------------------------------

// RECURSIVEBLUR
// import QtGraphicalEffects 1.0    
// Inherits Item, Blurs repeatedly, providing a strong blur effect
RecursiveBlur {
    cached
    loops
    progress
    radius
    source
    transparentBorder    
}

------------------------------------------------------------------------------------------------------------

// DIRECTIONALBLUR
// import QtGraphicalEffects 1.0    
// Inherits Item, Applies blur effect to the specified direction
DirectionalBlur {
    angle
    cached
    length
    samples
    source
    transparentBorder    
}

------------------------------------------------------------------------------------------------------------

// RADIALBLUR
// import QtGraphicalEffects 1.0    
// Inherits Item, Applies blur in a circular direction around the item center point
RadialBlur {
    angle
    cached
    horizontalOffset
    samples
    source
    transparentBorder
    verticalOffset    
}

------------------------------------------------------------------------------------------------------------

// ZOOMBLUR
// import QtGraphicalEffects 1.0    
// Inherits Item, Applies directional blur effect towards source items center point
ZoomBlur {
    cached
    horizontalOffset 
    length
    samples
    source
    transparentBorder
    verticalOffset    
}

------------------------------------------------------------------------------------------------------------

// GLOW
// import QtGraphicalEffects 1.0    
// Inherits Item, Generates a halo like glow around the source item
Glow {
    cached
    color
    radius
    samples
    source
    spread
    transparentBorder    
}

------------------------------------------------------------------------------------------------------------

// RECTANGULARGLOW
// import QtGraphicalEffects 1.0    
// Inherits Item, Generates a blurred and colorized rectangle
RectangularGlow {
    cached
    color
    cornerRadius
    glowRadius
    spread    
}

------------------------------------------------------------------------------------------------------------
    
// OPACITYMASK
// import QtGraphicalEffects 1.0    
// Inherits Item, Masks the source item with another item
// By default only draws parts of source inside maskSource
OpacityMask {
    cached: false // Default, caches results, use if not animated, improves performance
    invert: false // Default, inverts the mask to only draw what's outside it
    maskSource: Rectangle {}
    source: myItem // Can't be parent of OpacityMask
}

------------------------------------------------------------------------------------------------------------

// THRESHOLDMASK
// import QtGraphicalEffects 1.0    
// Inherits Item, Masks the source item with another item and applies a threshold value
ThresholdMask {
    cached
    maskSource
    source
    spread
    threshold
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML SHAPES
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// SHAPE
// import QtQuick.Shapes 1.0
// Inherits Item, defines area which any child paths will be drawn
Shape {
    asynchronous
    containsMode
    data
    rendererType
    status
    vendorExtensionsEnabled
}

------------------------------------------------------------------------------------------------------------

// PATH
// import QtQuick 2.11
Path {
    closed
    pathElements
    startX
    startY
}

------------------------------------------------------------------------------------------------------------

// SHAPEPATH
// import QtQuick.Shapes 1.0
// Inherits Path
// First PathLine draws from startX/Y to x/y, next PathLine draws from previous to x/y etc.
// Can't be used with MouseArea (only Shape can)
ShapePath {
    capStyle
    dashOffset
    dashPattern: [3, 2] // [n * strokeWidth dash, n * strokeWidth blank]
    fillColor
    fillGradient
    fillRule
    joinStyle
    miterLimit
    strokeColor
    strokeWidth: 2
    strokeStyle: ShapePath.DashLine
               
    PathLine { 
        x
        y
    }

    PathArc {
        x
        y
        radiusX
        radiusY
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML MULTIMEDIA
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QtMultimedia.availableCameras
QtMultimedia.defaultCamera
QtMultimedia.convertVolume(volume, from, to)

------------------------------------------------------------------------------------------------------------
    
// CAMERA
// import QtMultimedia 5.8, Inherits QtObject
// Access viewfinder frames, and take photos and movies
Camera {
    availability
    cameraState
    cameraStatus
    captureMode
    deviceId
    digitalZoom
    displayName
    errorCode
    errorString
    lockStatus
    maximumDigitalZoom
    maximumOpticalZoom
    mediaObject
    metaData.cameraManufacturer
    metaData.cameraModel
    metaData.event
    metaData.subject
    metaData.orientation
    metaData.dateTimeOriginal
    metaData.gpsLatitude
    metaData.gpsLongitude
    metaData.gpsAltitude
    metaData.gpsTimestamp
    metaData.gpsTrack
    metaData.gpsSpeed
    metaData.gpsImgDirection
    metaData.gpsProcessingMethod
    opticalZoom
    orientation
    position
    viewfinder.resolution
    viewfinder.minimumFrameRate
    viewfinder.maximumFrameRate
    onCameraStateChanged: { state }
    onDigitalZoomChanged: { zoom }
    onError: { errorCode, errorString }
    onLockStatusChanged: {}
    onManualWhiteBalanceChanged: { qreal }
    onMaximumDigitalZoomChanged: { zoom }
    onMaximumOpticalZoomChanged: { zoom }
    onOpticalZoomChanged: { zoom }
    onWhiteBalanceModeChanged: { Camera::WhiteBalanceMode }
    
    // CameraCapture
    // Cannot be instantiated, only a child of Camera
    imageCapture {
        capturedImagePath
        errorString
        ready
        resolution
        supportedResolutions
        onCaptureFailed: { requestId, message }
        onImageCaptured: { requestId, preview }
        onImageMetadataAvailable: { requestId, key, valu }
        onImageSaved: { requestId, path }
    }
    
    // CameraExposure 
    // Cannot be instantiated, only a child of Camera
    exposure {
        aperture
        exposureCompensation
        exposureMode
        iso
        manualAperture
        manualIso 
        manualShutterSpeed
        meteringMode
        shutterSpeed
        spotMeteringPoint
        supportedExposureModes
    }
    
    // CameraFlash
    // Cannot be instantiated, only a child of Camera
    flash {
        mode
        ready
        supportedModes
    }
    
    // CameraFocus
    // Cannot be instantiated, only a child of Camera
    focus {
        customFocusPoint
        focusMode
        focusPointMode
        focusZones
        supportedFocusModes
        supportedFocusPointModes
    }
    
    // CameraImageProcessing 
    // Cannot be instantiated, only a child of Camera    
    imageProcessing {
        brightness
        colorFilter
        contrast
        denoisingLevel
        isAvailable
        manualWhiteBalance
        saturation
        sharpeningLevel
        supportedColorFilters
        supportedWhiteBalanceModes
        whiteBalanceMode
    }
    
    // CameraRecorder 
    // Cannot be instantiated, only a child of Camera    
    videoRecorder {
        actualLocation
        audioBitRate
        audioChannels
        audioCodec
        audioEncodingMode
        audioSampleRate
        duration
        errorCode 
        errorString
        frameRate
        mediaContainer
        muted
        outputLocation
        recorderState
        recorderStatus
        resolution
        videoBitRate 
        videoCodec
        videoEncodingMode
    }
}

camera.searchAndLock()
camera.start()
camera.stop()
camera.supportedViewfinderFrameRateRanges(resolution)
camera.supportedViewfinderResolutions(minimumFps, maximumFps)
camera.unlock()
    
camera.imageCapture.cancelCapture()
camera.imageCapture.capture()
camera.imageCapture.captureToLocation(location)
camera.imageCapture.setMetadata(key, value)
    
camera.exposure.setAutoAperture()
camera.exposure.setAutoIsoSensitivity()
camera.exposure.setAutoShutterSpeed()

camera.flash.flashModeChanged(int)
camera.flash.flashReady(bool)

camera.videoRecorder.record()
camera.videoRecorder.setMetadata(key, value)
camera.videoRecorder. stop()

------------------------------------------------------------------------------------------------------------

// MEDIAPLAYER
// import QtMultimedia 5.8
// Add media playback to a scene
MediaPlayer {
    audioRole
    autoLoad
    autoPlay
    availability
    bufferProgress
    customAudioRole
    duration
    error
    errorString
    hasAudio
    hasVideo
    loops
    mediaObject
    metaData.title
    metaData.subTitle
    metaData.author
    metaData.comment
    metaData.description
    metaData.category
    metaData.genre
    metaData.year
    metaData.date
    metaData.userRating
    metaData.keywords
    metaData.language
    metaData.publisher
    metaData.copyright
    metaData.parentalRating
    metaData.ratingOrganization
    metaData.size
    metaData.mediaType
    metaData.audioBitRate
    metaData.audioCodec
    metaData.averageLevel
    metaData.channelCount
    metaData.peakValue
    metaData.sampleRate
    metaData.albumTitle
    metaData.albumArtist
    metaData.contributingArtist
    metaData.composer
    metaData.conductor
    metaData.lyrics
    metaData.mood
    metaData.trackNumber
    metaData.trackCount
    metaData.coverArtUrlSmall
    metaData.coverArtUrlLarge
    metaData.resolution
    metaData.pixelAspectRatio
    metaData.videoFrameRate
    metaData.videoBitRate
    metaData.videoCodec
    metaData.posterUrl
    metaData.chapterNumber
    metaData.director
    metaData.leadPerformer 
    metaData.writer
    muted
    notifyInterval
    playbackRate
    playbackState
    playlist
    position
    seekable
    source
    status
    volume
    onError: { error, errorString }
    onPaused: {}
    onPlaybackStateChanged: {}
    onPlaying: {}
    onStopped: {}
}

player.pause()
playerplay()
playerseek(offset)
playerstop()
playersupportedAudioRoles()

------------------------------------------------------------------------------------------------------------

// VIDEO
// import QtMultimedia 5.8, Inherits Item
// A convenience type for showing a specified video
Video {
    audioRole
    autoLoad
    autoPlay
    availability
    bufferProgress
    customAudioRole
    duration
    error
    errorString
    fillMode
    hasAudio
    hasVideo
    loops
    metaData
    muted
    notifyInterval
    orientation
    playbackRate
    playbackState
    playlist
    position
    seekable
    source
    status
    volume
    onPaused: {}
    onPlaying: {}
    onStopped: {}    
}

video.pause()
video.play()
video.seek(offset)
video.stop()
video.supportedAudioRoles()

------------------------------------------------------------------------------------------------------------

// VIDEOOUTPUT
// import QtMultimedia 5.8
// Render video or camera viewfinder
VideoOutput {
    autoOrientation 
    contentRect
    fillMode
    filters
    orientation
    source
    sourceRect    
}

output.mapNormalizedPointToItem (point)
output.mapNormalizedRectToItem(rectangle)
output.mapPointToItem(point)
output.mapPointToSource(point)
output.mapPointToSourceNormalized(point)
output.mapRectToItem(rectangle)
output.mapRectToSource(rectangle)
output.mapRectToSourceNormalized(rectangle)
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML MATERIAL STYLE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
// MATERIAL ATTACHED PROPERTIES
// import QtQuick.Controls.Material 2.2
Material.theme: Material.Dark
Material.accent: "red"
Material.primary: "red"
Material.foreground: "red"
Material.background: "red"
    
// MATERIAL READONLY ATTACHED PROPERTIES
// import QtQuick.Controls.Material 2.2
Material.primaryTextColor
Material.primaryHighlightedTextColor
Material.secondaryTextColor
Material.hintTextColor
Material.textSelectionColor
Material.dropShadowColor
Material.dividerColor
Material.iconColor
Material.iconDisabledColor
Material.buttonColor
Material.buttonDisabledColor
Material.highlightedButtonColor
Material.frameColor
Material.rippleColor
Material.highlightedRippleColor
Material.switchUncheckedTrackColor
Material.switchCheckedTrackColor
Material.switchUncheckedHandleColor
Material.switchCheckedHandleColor
Material.switchDisabledTrackColor
Material.switchDisabledHandleColor
Material.scrollBarColor
Material.scrollBarHoveredColor
Material.scrollBarPressedColor
Material.dialogColor
Material.backgroundDimColor
Material.listHighlightColor
Material.tooltipColor
Material.toolBarColor
Material.toolTextColor
Material.spinBoxDisabledIconColor
    
// RIPPLE
// import QtQuick.Controls.Material.impl 2.2
Ripple
{
    clipRadius: 1 // Use 0 for circle
    width: parent.width
    height: parent.height
    pressed: mouseArea.pressed
    anchor: parent
    active: mouseArea.pressed
    color: parent.Material.rippleColor
}
