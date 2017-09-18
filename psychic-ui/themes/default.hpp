#pragma once

#include <psychic-ui/style/StyleManager.hpp>
#include <psychic-ui/style/StyleSheet.hpp>
#include <psychic-ui/skins/SliderRangeSkin.hpp>
#include <psychic-ui/skins/DefaultButtonSkin.hpp>
#include <psychic-ui/skins/DefaultScrollBarSkin.hpp>
#include <psychic-ui/skins/DefaultCheckBoxSkin.hpp>
#include <psychic-ui/skins/DefaultMenuButtonSkin.hpp>
#include <psychic-ui/skins/TitleBarButtonSkin.hpp>
#include <psychic-color/spaces/RGB.hpp>
#include <psychic-color/spaces/HSB.hpp>

using namespace psychic_ui;
using namespace psychic_color;

#define BASE_00 0xFF151515
#define BASE_01 0xFF202020
#define BASE_02 0xFF303030
#define BASE_03 0xFF505050
#define BASE_04 0xFFB0B0B0
#define BASE_05 0xFFD0D0D0
#define BASE_06 0xFFE0E0E0
#define BASE_07 0xFFF5F5F5

#define BASE_RED 0xFFAC4142
#define BASE_ORANGE 0xFFD28445
#define BASE_YELLOW 0xFFF4BF75
#define BASE_GREEN 0xFF90A959
#define BASE_TURQUOISE 0xFF75B5AA
#define BASE_BLUE 0xFF6A9FB5
#define BASE_VIOLET 0xFFAA759F
#define BASE_BROWN 0xFF8F5536

#define ONE_LIGHT 0xFFABB2BF
#define ONE_MEDIUM 0xFF828997
#define ONE_DARK 0xFF5C6370
#define ONE_CYAN 0xFF56B6C2
#define ONE_BLUE 0xFF61AFEF
#define ONE_PURPLE 0xFFC678DD
#define ONE_GREEN 0xFF98C379
#define ONE_RED_FADED 0xFFE06C75
#define ONE_RED 0xFFBE5046
#define ONE_ORANGE 0xFFD19A66
#define ONE_YELLOW 0xFFE5C07B
#define ONE_FOREGROUND 0xFFABB2BF
#define ONE_BACKGROUND 0xFF282C34
#define ONE_GUTTER 0xFF636D83
#define ONE_BLUE_ACCENT 0xFF528BFF

/**
 * Psychic UI Style
 */
class PsychicUIStyleSheet : public StyleSheet {
protected:
    HSB themeBackgroundColor{};
    HSB themeForegroundColor{};
    HSB themeLowContrastColor{};
    HSB themeMediumContrastColor{};
    HSB themeHighContrastColor{};
    HSB themeHighlightColor{};
    HSB themeCyanColor{};
    HSB themeBlueColor{};
    HSB themePurpleColor{};
    HSB themeGreenColor{};
    HSB themeRedColor{};
    HSB themeRedOrangeColor{};
    HSB themeOrangeColor{};
    HSB themeYellowColor{};
public:
    PsychicUIStyleSheet() = default;
    void load(StyleManager *manager) override {
        int smallText     = 10;
        int text          = 12;
        int mediumText    = 14;
        int largeText     = 18;
        int bigText       = 24;
        int hugeText      = 36;
        int radius        = 6;
        int scrollBarSize = 12;

        manager->loadFont("stan0755", "../res/fonts/stan0755.ttf");
        manager->loadFont("Ubuntu Light", "../res/fonts/Ubuntu/Ubuntu-Light.ttf");
        manager->loadFont("Ubuntu Regular", "../res/fonts/Ubuntu/Ubuntu-Regular.ttf");

        manager->registerSkin("default-button-skin", SkinType::make([]() { return std::make_shared<DefaultButtonSkin>(); }));
        manager->registerSkin("default-checkbox-skin", SkinType::make([]() { return std::make_shared<DefaultCheckBoxSkin>(); }));
        manager->registerSkin("default-scrollbar-skin", SkinType::make([]() { return std::make_shared<DefaultScrollBarSkin>(); }));
        manager->registerSkin("menu-button-skin", SkinType::make([]() { return std::make_shared<DefaultMenuButtonSkin>(); }));
        manager->registerSkin("sub-menu-button-skin", SkinType::make([]() { return std::make_shared<DefaultSubMenuButtonSkin>(); }));
        manager->registerSkin("title-bar-button", SkinType::make([]() { return std::make_shared<TitleBarButtonSkin>(); }));
        manager->registerSkin("slider", SkinType::make([]() { return std::make_shared<SliderRangeSkin>(); }));

        // region Defaults
        manager->style("*")
               ->set(overflow, "visible")
               ->set(fontFamily, "Ubuntu Regular")
               ->set(fontSize, text)
               ->set(lineHeight, 16)
               ->set(color, themeForegroundColor.getColorAlpha())
               ->set(antiAlias, true)
               ->set(textAntiAlias, true)
               ->set(multiline, false);
        // endregion

        // region Typography

        manager->style(".h1")
               ->set(fontFamily, "Ubuntu Light")
               ->set(fontSize, hugeText)
               ->set(lineHeight, hugeText);

        manager->style(".h2")
               ->set(fontFamily, "Ubuntu Light")
               ->set(fontSize, bigText)
               ->set(lineHeight, bigText);

        manager->style(".h3")
               ->set(fontFamily, "Ubuntu Light")
               ->set(fontSize, largeText)
               ->set(lineHeight, largeText);

        manager->style(".h4")
               ->set(fontFamily, "Ubuntu Regular")
               ->set(fontSize, mediumText)
               ->set(lineHeight, mediumText);

        manager->style(".h5")
               ->set(fontFamily, "Ubuntu Regular")
               ->set(fontSize, text)
               ->set(lineHeight, text);

        manager->style(".h6")
               ->set(fontFamily, "Ubuntu Regular")
               ->set(fontSize, smallText)
               ->set(lineHeight, smallText);

        // endregion

        // region Window
        manager->style("Window")
               ->set(color, themeForegroundColor.getColorAlpha())
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha())
               ->set(border, 1)
               ->set(borderColor, themeBackgroundColor.getColorAlpha());
        // endregion

        // region Title Bar
        manager->style("TitleBar")
               ->set(alignItems, "center")
               ->set(height, 48)
               ->set(padding, 12)
               ->set(backgroundColor, themeLowContrastColor.getColorAlpha())
               ->set(borderBottom, 1)
               ->set(borderColor, themeBackgroundColor.getColorAlpha());

        manager->style("TitleBar Label.title")
               ->set(fontFamily, "Ubuntu Light")
               ->set(fontSize, largeText)
               ->set(marginLeft, 12)
               ->set(grow, 1);

        manager->style("TitleBar Button")
               ->set(skin, "title-bar-button")
               ->set(width, 18)
               ->set(height, 18)
               ->set(margin, 3)
               ->set(padding, 0)
               ->set(border, 0);

        manager->style("TitleBar Button.close")
               ->set(backgroundColor, themeRedColor.getColorAlpha());

        manager->style("TitleBar Button.close:hover")
               ->set(backgroundColor, themeRedOrangeColor.getColorAlpha());

        manager->style("TitleBar Button.minimize")
               ->set(backgroundColor, themeOrangeColor.getColorAlpha());

        manager->style("TitleBar Button.minimize:hover")
               ->set(backgroundColor, themeYellowColor.getColorAlpha());

        manager->style("TitleBar Button.maximize")
               ->set(backgroundColor, themeGreenColor.getColorAlpha());

        manager->style("TitleBar Button.maximize:hover")
               ->set(backgroundColor, themeGreenColor.getColorAlpha());

        // endregion

        // region Boxes

        // endregion

        // region Labels

        // endregion

        // region ScrollBars

        manager->style("ScrollBar")
               ->set(skin, "default-scrollbar-skin");

        manager->style("ScrollBar.vertical")
               ->set(width, scrollBarSize);

        manager->style("ScrollBar.horizontal")
               ->set(height, scrollBarSize);

        manager->style("ScrollBar .track")
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha());

        manager->style("ScrollBar .thumb")
               ->set(backgroundColor, themeLowContrastColor.getColorAlpha());

        manager->style("ScrollBar.vertical .thumb")
               ->set(marginLeft, 1)
               ->set(minHeight, 24);

        manager->style("ScrollBar.horizontal .thumb")
               ->set(marginTop, 1)
               ->set(minWidth, 24);

        manager->style("ScrollBar:hover .thumb")
               ->set(backgroundColor, themeMediumContrastColor.getColorAlpha());

        manager->style("ScrollBar:active .thumb")
               ->set(backgroundColor, themeHighlightColor.getColorAlpha());

        manager->style("ScrollBar:disabled .thumb")
               ->set(backgroundColor, themeLowContrastColor.getColorAlpha());

        manager->style("Scroller ScrollBar.horizontal")
               ->set(marginRight, scrollBarSize);

        // endregion

        // region Buttons
        manager->style("Button")
               ->set(skin, "default-button-skin")
               ->set(cursor, Cursor::Hand)
               ->set(flexDirection, "row")
               ->set(alignItems, "center")
               ->set(padding, 12)
               ->set(borderRadius, radius)
               ->set(backgroundColor, themeMediumContrastColor.getColorAlpha())
               ->set(color, themeForegroundColor.getColorAlpha())
               ->set(fontSize, mediumText)
               ->set(lineHeight, mediumText);

        manager->style("Button:hover")
               ->set(backgroundColor, themeHighContrastColor.getColorAlpha());

        manager->style("Button:active")
               ->set(color, BASE_00)
               ->set(backgroundColor, themeHighlightColor.getColorAlpha());
        // endregion

        // region CheckBox
        manager->style("CheckBox")
               ->set(skin, "default-checkbox-skin")
               ->set(flexDirection, "row")
               ->set(alignItems, "center")
               ->set(padding, 12)
               ->set(borderRadius, radius)
               ->set(color, BASE_07)
               ->set(fontSize, mediumText)
               ->set(lineHeight, mediumText);

        manager->style("CheckBox Shape")
               ->set(width, 24)
               ->set(height, 24)
               ->set(marginRight, 6)
               ->set(borderRadius, radius)
               ->set(borderColor, themeForegroundColor.getColorAlpha())
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha());

        manager->style("CheckBox:hover Shape")
               ->set(color, themeMediumContrastColor.getColorAlpha());

        manager->style("CheckBox:active Shape")
               ->set(color, themeHighlightColor.getColorAlpha());
        // endregion

        // region Menus
        manager->style("Menu")
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha())
               ->set(opacity, 0.8f)
               ->set(minWidth, 200)
               ->set(alignItems, "stretch");

        manager->style("Menu MenuButton")
               ->set(flexDirection, "row")
               ->set(paddingHorizontal, 6)
               ->set(paddingVertical, 6)
               ->set(borderRadius, 0)
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha());

        manager->style("Menu MenuButton.simple")
               ->set(skin, "menu-button-skin");

        manager->style("Menu MenuButton.submenu")
               ->set(skin, "sub-menu-button-skin");

        manager->style("Menu MenuButton .label")
               ->set(grow, 1)
               ->set(fontFamily, "Ubuntu Regular")
               ->set(fontSize, smallText)
               ->set(lineHeight, text);

        manager->style("Menu MenuButton .shortcut")
               ->set(fontSize, smallText)
               ->set(lineHeight, text)
               ->set(color, BASE_04);

        manager->style("Menu MenuButton.submenu .arrow")
               ->set(width, 6);

        manager->style("Menu MenuButton:hover")
               ->set(backgroundColor, themeHighlightColor.getColorAlpha());

        manager->style("Menu MenuButton:hover .label")
               ->set(color, BASE_00);

        manager->style("Menu MenuButton:hover .shortcut")
               ->set(color, BASE_03);

        manager->style("Menu MenuButton.submenu:hover .arrow")
               ->set(color, BASE_00);

        manager->style("Menu MenuButton:active")
               ->set(backgroundColor, themeHighlightColor.getColorAlpha());

        manager->style("Menu MenuButton:active .label")
               ->set(color, BASE_00);

        manager->style("Menu MenuButton:active .shortcut")
               ->set(color, BASE_03);

        manager->style("Menu MenuButton.submenu:active .arrow")
               ->set(color, BASE_00);

        // endregion

        // region Ranges

        manager->style("Range")
               ->set(skin, "slider")
               ->set(borderRadius, radius)
               ->set(border, 1)
               ->set(padding, 1)
               ->set(borderColor, themeForegroundColor.getColorAlpha())
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha())
               ->set(fontFamily, "Ubuntu Regular")
               ->set(fontSize, smallText)
               ->set(lineHeight, smallText)
               ->set(color, themeForegroundColor.getColorAlpha());

        manager->style("Range Slider.horizontal")
               ->set(height, 24);

        manager->style("Range Slider.vertical")
               ->set(width, 24);

        manager->style("Range:hover Slider.inverted")
               ->set(color, BASE_00);

        manager->style("Range:active Slider.inverted")
               ->set(color, BASE_00);

        manager->style("Range:hover Slider")
               ->set(color, themeHighContrastColor.getColorAlpha());

        manager->style("Range Slider .track")
               ->set(backgroundColor, themeLowContrastColor.getColorAlpha());

        manager->style("Range:hover Slider .track");

        manager->style("Range Slider .range")
               ->set(backgroundColor, themeMediumContrastColor.getColorAlpha());

        manager->style("Range:hover Slider .range")
               ->set(backgroundColor, themeHighContrastColor.getColorAlpha());

        manager->style("Range:active Slider .range")
               ->set(backgroundColor, themeHighlightColor.getColorAlpha());
        // endregion

        // region Tabs
        manager->style("tabs")
               ->set(flexDirection, "row")
               ->set(borderBottom, 1)
               ->set(borderColor, themeBackgroundColor.getColorAlpha());

        manager->style("tabs button")
               ->set(fontSize, smallText)
               ->set(lineHeight, text)
               ->set(marginHorizontal, -1)
               ->set(paddingHorizontal, 12)
               ->set(paddingVertical, 6)
               ->set(borderRadius, 0)
               ->set(borderHorizontal, 1)
               ->set(borderColor, themeBackgroundColor.getColorAlpha());

//        manager->style("tabs button:firstChild")
//               ->set(borderRadiusLeft, radius);
//
//        manager->style("tabs button:lastChild")
//               ->set(borderRadiusRight, radius);

        // endregion

        // region Tab Container

        manager->style("tabcontainer")
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha());

        // endregion

        // region MenuBar
        manager->style("MenuBar")
               ->set(flexDirection, "row")
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha())
               ->set(borderBottom, 1)
               ->set(borderColor, themeBackgroundColor.getColorAlpha());

        manager->style("MenuBar Button")
               ->set(fontSize, smallText)
               ->set(lineHeight, smallText)
               ->set(paddingHorizontal, 12)
               ->set(paddingVertical, 6)
               ->set(borderRadius, 0)
               ->set(backgroundColor, themeBackgroundColor.getColorAlpha());

        manager->style("MenuBar Button:hover")
               ->set(color, themeHighlightColor.getColorAlpha());

        manager->style("MenuBar Button:active")
               ->set(color, BASE_00)
               ->set(backgroundColor, themeHighlightColor.getColorAlpha());

        // endregion

        // region ToolBar
        manager->style("toolbar")
               ->set(flexDirection, "row")
               ->set(backgroundColor, themeLowContrastColor.getColorAlpha())
               ->set(borderBottom, 1)
               ->set(borderColor, themeBackgroundColor.getColorAlpha());

        manager->style("toolbar button")
               ->set(marginHorizontal, -1)
               ->set(paddingHorizontal, 18)
               ->set(borderRadius, 0)
               ->set(borderHorizontal, 1)
               ->set(borderColor, themeBackgroundColor.getColorAlpha());
        // endregion
    }
};

/**
 * Psychic UI Style
 */
class PsychicUIDarkStyleSheet : public PsychicUIStyleSheet {
public:
    PsychicUIDarkStyleSheet() :
        PsychicUIStyleSheet() {
        themeBackgroundColor = HSB{0x282C34};
        themeForegroundColor = HSB{0xABB2BF};
        themeLowContrastColor = HSB{0x5C6370};
        themeMediumContrastColor = HSB{0x828997};
        themeHighContrastColor = HSB{0xABB2BF};
        themeHighlightColor = HSB{0x528BFF}; //{0xFF00FFEC}

        themeCyanColor = HSB{0x56B6C2};
        themeBlueColor = HSB{0x61AFEF};
        themePurpleColor = HSB{0xC678DD};
        themeGreenColor = HSB{0x98C379};
        themeRedColor = HSB{0xBE5046};
        themeRedOrangeColor = HSB{0xE06C75};
        themeOrangeColor = HSB{0xD19A66};
        themeYellowColor = HSB{0xE5C07B};
    }
};

/**
 * Psychic UI Style
 */
class PsychicUILightStyleSheet : public PsychicUIStyleSheet {
public:
    PsychicUILightStyleSheet() :
        PsychicUIStyleSheet() {
        themeBackgroundColor = HSB{0xF9F9F9};
        themeForegroundColor = HSB{0x2A2C33};
        themeLowContrastColor = HSB{0xE5E5E6};
        themeMediumContrastColor = HSB{0x8F9097};
        themeHighContrastColor = HSB{0x565964};
        themeHighlightColor = HSB{0x528BFF};

        themeCyanColor = HSB{0x56B6C2};
        themeBlueColor = HSB{0x61AFEF};
        themePurpleColor = HSB{0xC678DD};
        themeGreenColor = HSB{0x98C379};
        themeRedColor = HSB{0xBE5046};
        themeRedOrangeColor = HSB{0xE06C75};
        themeOrangeColor = HSB{0xD19A66};
        themeYellowColor = HSB{0xE5C07B};
        }
};
