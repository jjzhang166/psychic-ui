#pragma once

#include <SkPaint.h>
#include "Div.hpp"

namespace psychic_ui {

    /**
     * @class TextBase
     *
     * Base class for text displaying components
     */
    class TextBase : public Div {
    public:
        TextBase();
        virtual TextBase *setText(const std::string &text) = 0;
        bool lcdRender() const;
        TextBase *setLcdRender(bool lcdRender);
        bool subpixelText() const;
        TextBase *setSubPixelText(bool subPixelText);

    protected:
        bool    _lcdRender{true};
        bool    _subPixelText{true};
        float   _fontSize{0.0f};
        float   _lineHeight{0.0f};
        SkPaint _textPaint{};
        void styleUpdated() override;
    };
}

