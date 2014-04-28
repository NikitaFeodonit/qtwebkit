# -------------------------------------------------------------------
# This file contains a static list of default values for all the
# ENABLE_FOO features of WebKit.
#
# If a feature is enabled, it most likely does not have any detection
# in features.prf except basic sanitazion. If a feature is disabled it
# will have detection in features.prf, unless it's something we
# completely disable.
#
# FIXME: Add warning about auto-generating when Features.py land
#
# See 'Tools/qmake/README' for an overview of the build system
# -------------------------------------------------------------------


include(cfg_config.pri)

for(feature, CFG_FEATURE_DEFAULTS) {
    FEATURE_DEFAULTS += $$upper($$feature)
}



#FEATURE_DEFAULTS = \
#    ENABLE_3D_RENDERING=1 \
#    ENABLE_ACCELERATED_2D_CANVAS=0 \
#    ENABLE_BATTERY_STATUS=0 \
#    ENABLE_BLOB=1 \
#    ENABLE_CANVAS_PATH=1 \
#    ENABLE_CANVAS_PROXY=0 \
#    ENABLE_CHANNEL_MESSAGING=1 \
#    ENABLE_CSP_NEXT=0 \
#    ENABLE_CSS_BOX_DECORATION_BREAK=1 \
#    ENABLE_CSS_COMPOSITING=1 \
#    ENABLE_CSS_EXCLUSIONS=1 \
#    ENABLE_CSS_FILTERS=1 \
#    ENABLE_CSS_GRID_LAYOUT=0 \
#    ENABLE_CSS_HIERARCHIES=0 \
#    ENABLE_CSS_IMAGE_ORIENTATION=0 \
#    ENABLE_CSS_IMAGE_RESOLUTION=0 \
#    ENABLE_CSS_IMAGE_SET=1 \
#    ENABLE_CSS_REGIONS=1 \
#    ENABLE_CSS_SHADERS=0 \
#    ENABLE_CSS_SHAPES=1 \
#    ENABLE_CSS_STICKY_POSITION=1 \
#    ENABLE_CSS_TRANSFORMS_ANIMATIONS_UNPREFIXED=1 \
#    ENABLE_CSS_VARIABLES=0 \
#    ENABLE_CSS3_CONDITIONAL_RULES=0 \
#    ENABLE_CSS3_TEXT=0 \
#    ENABLE_CSS3_TEXT_LINE_BREAK=0 \
#    ENABLE_DASHBOARD_SUPPORT=0 \
#    ENABLE_DATAGRID=0 \
#    ENABLE_DATALIST_ELEMENT=1 \
#    ENABLE_DATA_TRANSFER_ITEMS=0 \
#    ENABLE_DETAILS_ELEMENT=1 \
#    ENABLE_DEVICE_ORIENTATION=1 \
#    ENABLE_DIRECTORY_UPLOAD=0 \
#    ENABLE_DOWNLOAD_ATTRIBUTE=1 \
#    ENABLE_FAST_MOBILE_SCROLLING=1 \
#    ENABLE_FILE_SYSTEM=0 \
#    ENABLE_FILTERS=1 \
#    ENABLE_FONT_LOAD_EVENTS=0 \
#    ENABLE_FTPDIR=1 \
#    ENABLE_FULLSCREEN_API=1 \
#    ENABLE_GAMEPAD=0 \
#    ENABLE_GEOLOCATION=1 \
#    ENABLE_GESTURE_EVENTS=1 \
#    ENABLE_HIGH_DPI_CANVAS=0 \
#    ENABLE_ICONDATABASE=1 \
#    ENABLE_IFRAME_SEAMLESS=1 \
#    ENABLE_INDEXED_DATABASE=1 \
#    ENABLE_INPUT_SPEECH=0 \
#    ENABLE_INPUT_TYPE_COLOR=1 \
#    ENABLE_INPUT_TYPE_DATE=0 \
#    ENABLE_INPUT_TYPE_DATETIME_INCOMPLETE=0 \
#    ENABLE_INPUT_TYPE_DATETIMELOCAL=0 \
#    ENABLE_INPUT_TYPE_MONTH=0 \
#    ENABLE_INPUT_TYPE_TIME=0 \
#    ENABLE_INPUT_TYPE_WEEK=0 \
#    ENABLE_INSPECTOR=1 \
#    ENABLE_INSPECTOR_SERVER=1 \
#    ENABLE_JAVASCRIPT_DEBUGGER=1 \
#    ENABLE_LEGACY_CSS_VENDOR_PREFIXES=0 \
#    ENABLE_LEGACY_NOTIFICATIONS=1 \
#    ENABLE_LEGACY_VIEWPORT_ADAPTION=1 \
#    ENABLE_LEGACY_VENDOR_PREFIXES=1 \
#    ENABLE_LEGACY_WEB_AUDIO=1 \
#    ENABLE_LINK_PREFETCH=1 \
#    ENABLE_MATHML=0 \
#    ENABLE_MEDIA_SOURCE=0 \
#    ENABLE_MEDIA_STATISTICS=0 \
#    ENABLE_MEDIA_STREAM=0 \
#    ENABLE_METER_ELEMENT=1 \
#    ENABLE_MHTML=1 \
#    ENABLE_MICRODATA=0 \
#    ENABLE_MOUSE_CURSOR_SCALE=0 \
#    ENABLE_NAVIGATOR_CONTENT_UTILS=0 \
#    ENABLE_NETSCAPE_PLUGIN_API=0 \
#    ENABLE_NETWORK_INFO=0 \
#    ENABLE_NOSNIFF=0 \
#    ENABLE_NOTIFICATIONS=1 \
#    ENABLE_ORIENTATION_EVENTS=1 \
#    ENABLE_PAGE_VISIBILITY_API=1 \
#    ENABLE_PROGRESS_ELEMENT=1 \
#    ENABLE_PROXIMITY_EVENTS=0 \
#    ENABLE_QUOTA=0 \
#    ENABLE_RESOLUTION_MEDIA_QUERY=1 \
#    ENABLE_RESOURCE_TIMING=0 \
#    ENABLE_REQUEST_ANIMATION_FRAME=1 \
#    ENABLE_SCRIPTED_SPEECH=0 \
#    ENABLE_SECCOMP_FILTERS=0 \
#    ENABLE_SHADOW_DOM=0 \
#    ENABLE_SHARED_WORKERS=1 \
#    ENABLE_SMOOTH_SCROLLING=1 \
#    ENABLE_SQL_DATABASE=1 \
#    ENABLE_STYLE_SCOPED=0 \
#    ENABLE_SUBPIXEL_LAYOUT=1 \
#    ENABLE_SVG=1 \
#    ENABLE_SVG_FONTS=1 \
#    ENABLE_TEMPLATE_ELEMENT=0 \
#    ENABLE_TEXT_AUTOSIZING=0 \
#    ENABLE_THREADED_HTML_PARSER=0 \
#    ENABLE_TOUCH_ADJUSTMENT=1 \
#    ENABLE_TOUCH_EVENTS=1 \
#    ENABLE_TOUCH_ICON_LOADING=0 \
#    ENABLE_USER_TIMING=0 \
#    ENABLE_VIBRATION=0 \
#    ENABLE_VIDEO=0 \
#    ENABLE_VIDEO_TRACK=1 \
#    ENABLE_VIEW_MODE_CSS_MEDIA=1 \
#    ENABLE_WEBGL=0 \
#    ENABLE_WEB_AUDIO=0 \
#    ENABLE_WEB_SOCKETS=1 \
#    ENABLE_WEB_TIMING=1 \
#    ENABLE_WORKERS=1 \
#    ENABLE_XHR_TIMEOUT=1 \
#    ENABLE_XSLT=0 \
