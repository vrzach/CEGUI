/************************************************************************
    filename:   CEGUIFalTextComponent.cpp
    created:    Sun Jun 19 2005
    author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
 
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#include "falagard/CEGUIFalTextComponent.h"
#include "CEGUIFontManager.h"
#include "CEGUIExceptions.h"
#include "CEGUIPropertyHelper.h"

// Start of CEGUI namespace section
namespace CEGUI
{
    TextComponent::TextComponent() :
        d_colours(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF),
        d_vertFormatting(VTF_TOP_ALIGNED),
        d_horzFormatting(HTF_LEFT_ALIGNED),
        d_colourProperyIsRect(false)
    {}

    void TextComponent::render(Window& srcWindow, float base_z, const CEGUI::ColourRect* modColours, const Rect* clipper, bool clipToDisplay) const
    {
        // calculate area to render to
        Rect destRect(d_area.getPixelRect(srcWindow));
        render_impl(srcWindow, destRect, base_z, modColours, (clipper != 0) ? clipper : &destRect, clipToDisplay);
    }

    void TextComponent::render(Window& srcWindow, const Rect& baseRect, float base_z, const CEGUI::ColourRect* modColours, const Rect* clipper, bool clipToDisplay) const
    {
        // calculate area to render to
        Rect destRect(d_area.getPixelRect(srcWindow, baseRect));
        render_impl(srcWindow, destRect, base_z, modColours, (clipper != 0) ? clipper : &destRect, clipToDisplay);
    }

    const ComponentArea& TextComponent::getComponentArea() const
    {
        return d_area;
    }

    void TextComponent::setComponentArea(const ComponentArea& area)
    {
        d_area = area;
    }

    const String& TextComponent::getText() const
    {
        return d_text;
    }

    void TextComponent::setText(const String& text)
    {
        d_text = text;
    }

    const String& TextComponent::getFont() const
    {
        return d_font;
    }

    void TextComponent::setFont(const String& font)
    {
        d_font = font;
    }

    const ColourRect& TextComponent::getColours() const
    {
        return d_colours;
    }

    void TextComponent::setColours(const ColourRect& cols)
    {
        d_colours = cols;
    }

    VerticalTextFormatting TextComponent::getVerticalFormatting() const
    {
        return d_vertFormatting;
    }

    void TextComponent::setVerticalFormatting(VerticalTextFormatting fmt)
    {
        d_vertFormatting = fmt;
    }

    HorizontalTextFormatting TextComponent::getHorizontalFormatting() const
    {
        return d_horzFormatting;
    }

    void TextComponent::setHorizontalFormatting(HorizontalTextFormatting fmt)
    {
        d_horzFormatting = fmt;
    }

    void TextComponent::setColoursPropertySource(const String& property)
    {
        d_colourPropertyName = property;
    }

    void TextComponent::setColoursPropertyIsColourRect(bool setting)
    {
        d_colourProperyIsRect = setting;
    }

    void TextComponent::initColoursRect(const Window& wnd, ColourRect& cr) const
    {
        // if colours come via a colour property
        if (!d_colourPropertyName.empty())
        {
            // if property accesses a ColourRect
            if (d_colourProperyIsRect)
            {
                cr = PropertyHelper::stringToColourRect(wnd.getProperty(d_colourPropertyName));
            }
            // property accesses a colour
            else
            {
                colour val(PropertyHelper::stringToColour(wnd.getProperty(d_colourPropertyName)));
                cr.d_top_left     = val;
                cr.d_top_right    = val;
                cr.d_bottom_left  = val;
                cr.d_bottom_right = val;
            }
        }
        // use explicit ColourRect.
        else
        {
            cr = d_colours;
        }
    }

    void TextComponent::render_impl(Window& srcWindow, Rect& destRect, float base_z, const CEGUI::ColourRect* modColours, const Rect* clipper, bool clipToDisplay) const
    {
        // get font to use
        const Font* font;

        try
        {
            font = d_font.empty() ? srcWindow.getFont() : FontManager::getSingleton().getFont(d_font);
        }
        catch (UnknownObjectException)
        {
            font = 0;
        }

        // exit if we have no font to use.
        if (!font)
            return;

        // calculate final colours to be used
        ColourRect finalColours;
        initColoursRect(srcWindow, finalColours);
        if (modColours)
        {
            finalColours *= *modColours;
        }

        // decide which string to render.
        const String& renderString = d_text.empty() ? srcWindow.getText() : d_text;

        // calculate height of formatted text
        float textHeight = font->getFormattedLineCount(renderString, destRect, (TextFormatting)d_horzFormatting) * font->getLineSpacing();

        // handle dest area adjustments for vertical formatting.
        switch(d_vertFormatting)
        {
        case VTF_CENTRE_ALIGNED:
            destRect.d_top += (destRect.getHeight() - textHeight) * 0.5f;
            break;

        case VTF_BOTTOM_ALIGNED:
            destRect.d_top = destRect.d_bottom - textHeight;
            break;
        }

        // add text to the rendering cache for the target window.
        srcWindow.getRenderCache().cacheText(renderString, font, (TextFormatting)d_horzFormatting, destRect, base_z, finalColours, clipper, clipToDisplay);
    }

} // End of  CEGUI namespace section
