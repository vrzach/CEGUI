/************************************************************************
    filename:   CEGUIRenderCache.cpp
    created:    Fri Jun 17 2005
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
#include "CEGUIRenderCache.h"

// Start of CEGUI namespace section
namespace CEGUI
{
    RenderCache::RenderCache()
    {}

    RenderCache::~RenderCache()
    {}

    bool RenderCache::hasCachedImagery() const
    {
        return !(d_cachedImages.empty() && d_cachedTexts.empty());
    }

    void RenderCache::render(const Point& basePos, float baseZ, const Rect& clipper) const
    {
        Rect finalRect;

        // Send all cached images to renderer.
        for(ImageryList::const_iterator image = d_cachedImages.begin(); image != d_cachedImages.end(); ++image)
        {
            finalRect = (*image).target_area;
            finalRect.offset(basePos);
            (*image).source_image->draw(finalRect, baseZ + (*image).z_offset, clipper, (*image).colours);
        }

        // send all cached texts to renderer.
        for(TextList::const_iterator text = d_cachedTexts.begin(); text != d_cachedTexts.end(); ++text)
        {
            finalRect = (*text).target_area;
            finalRect.offset(basePos);
            (*text).source_font->drawText((*text).text, finalRect, baseZ + (*text).z_offset, clipper, (*text).formatting, (*text).colours);
        }

    }

    void RenderCache::clearCachedImagery()
    {
        d_cachedImages.clear();
        d_cachedTexts.clear();
    }

    void RenderCache::cacheImage(const Image& image, const Rect& destArea, float zOffset, const ColourRect& cols)
    {
        ImageInfo imginf;
        imginf.source_image = &image;
        imginf.target_area  = destArea;
        imginf.z_offset     = zOffset;
        imginf.colours      = cols;

        d_cachedImages.push_back(imginf);
    }

    void RenderCache::cacheText(const String& text, const Font* font, TextFormatting format, const Rect& destArea, float zOffset, const ColourRect& cols)
    {
        TextInfo txtinf;
        txtinf.text         = text;
        txtinf.source_font  = font;
        txtinf.formatting   = format;
        txtinf.target_area  = destArea;
        txtinf.z_offset     = zOffset;
        txtinf.colours      = cols;

        d_cachedTexts.push_back(txtinf);
    }


} // End of  CEGUI namespace section
