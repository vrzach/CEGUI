/***********************************************************************
filename:   SampleData.cpp
created:    4/6/2012
author:     Lukas E Meindl
*************************************************************************/
/***************************************************************************
*   Copyright (C) 2004 - 2012 Paul D Turner & The CEGUI Development Team
*
*   Permission is hereby granted, free of charge, to any person obtaining
*   a copy of this software and associated documentation files (the
*   "Software"), to deal in the Software without restriction, including
*   without limitation the rights to use, copy, modify, merge, publish,
*   distribute, sublicense, and/or sell copies of the Software, and to
*   permit persons to whom the Software is furnished to do so, subject to
*   the following conditions:
*
*   The above copyright notice and this permission notice shall be
*   included in all copies or substantial portions of the Software.
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
*   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
*   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
*   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
*   OTHER DEALINGS IN THE SOFTWARE.
***************************************************************************/
#include "SampleData.h"
#include "Sample.h"

#include "CEGUI/DynamicModule.h"
#include "CEGUI/Version.h"
#include "CEGUI/Exceptions.h"
#include "CEGUI/System.h"
#include "CEGUI/TextureTarget.h"
#include "CEGUI/BasicImage.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/Texture.h"
#include "CEGUI/ImageManager.h"
#include "CEGUI/Window.h"

using namespace CEGUI;

#define S_(X) #X
#define STRINGIZE(X) S_(X)

typedef Sample& (*getSampleInstance)();
#define GetSampleInstanceFuncName "getSampleInstance"

SampleData::SampleData(CEGUI::String sampleName, CEGUI::String summary,
    CEGUI::String description, SampleType sampleTypeEnum)
    : d_name(sampleName),
    d_summary(summary),
    d_description(description),
    d_type(sampleTypeEnum),
    d_guiContext(0),
    d_textureTarget(0),
    d_textureTargetImage(0),
    d_sampleWindow(0)
{
}

SampleData::~SampleData()
{

}

CEGUI::String SampleData::getName()
{
    return d_name;
}

void SampleData::setSampleWindow(CEGUI::Window* sampleWindow)
{
    d_sampleWindow = sampleWindow;
}

CEGUI::Window* SampleData::getSampleWindow()
{
    return d_sampleWindow;
}

void SampleData::initialise()
{
    CEGUI::System& system(System::getSingleton());

    d_textureTarget = system.getRenderer()->createTextureTarget();
    d_guiContext = &system.createGUIContext((RenderTarget&)*d_textureTarget);

    CEGUI::String imageName(d_textureTarget->getTexture().getName());
    d_textureTargetImage = static_cast<CEGUI::BasicImage*>(&CEGUI::ImageManager::getSingleton().create("BasicImage", "SampleBrowser/" + imageName));
    d_textureTargetImage->setTexture(&d_textureTarget->getTexture());
}

void SampleData::deinitialise()
{
    CEGUI::System& system(System::getSingleton());

    if(d_guiContext)
    {
        system.destroyGUIContext(*d_guiContext);
        d_guiContext = 0;
    }

    if(d_textureTarget)
    {
        system.getRenderer()->destroyTextureTarget(d_textureTarget);
        d_textureTarget = 0;
    }
}

GUIContext* SampleData::getGuiContext()
{
    return d_guiContext;
}

void SampleData::handleNewWindowSize(float width, float height)
{
    CEGUI::Sizef windowSize(width, height);
    CEGUI::Rectf renderArea(CEGUI::Rectf(0.f, height, width, 0.f));

    d_textureTargetImage->setArea(renderArea);
    d_textureTarget->declareRenderSize(windowSize);
   
    d_sampleWindow->getRenderingSurface()->invalidate();
}

CEGUI::Image& SampleData::getRTTImage()
{
    return *d_textureTargetImage;
}









SampleDataModule::SampleDataModule(CEGUI::String sampleName, CEGUI::String summary,
    CEGUI::String description, SampleType sampleTypeEnum)
    : SampleData(sampleName, summary, description ,sampleTypeEnum)
{

}

SampleDataModule::~SampleDataModule()
{
}

void SampleDataModule::initialise()
{
    SampleData::initialise();

    getSampleInstanceFromDLL();

    d_sample->initialise(d_guiContext);
}

void SampleDataModule::deinitialise()
{
    SampleData::deinitialise();

    d_sample->deinitialise();
}

CEGUI::Window*  SampleDataModule::getGuiRoot()
{
    return d_sample->getGUIRoot();
}

void SampleDataModule::getSampleInstanceFromDLL()
{
    // Version suffix for the dlls
    static const CEGUI::String versionSuffix( "-" STRINGIZE(CEGUI_VERSION_MAJOR) "." STRINGIZE(CEGUI_VERSION_MINOR) );

    CEGUI::DynamicModule* sampleModule = new CEGUI::DynamicModule(d_name + versionSuffix);
    getSampleInstance functionPointerGetSample = (getSampleInstance)sampleModule->getSymbolAddress(CEGUI::String(GetSampleInstanceFuncName));

    if(functionPointerGetSample == 0)
    {
        CEGUI::String errorMessage = "The sample creation function is not defined in the dynamic library of " + d_name;
        CEGUI_THROW(CEGUI::InvalidRequestException(errorMessage.c_str()));
    }

    d_sample =  &(functionPointerGetSample());
}