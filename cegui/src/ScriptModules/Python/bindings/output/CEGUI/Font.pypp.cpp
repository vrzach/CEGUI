// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "Font.pypp.hpp"

namespace bp = boost::python;

struct Font_wrapper : CEGUI::Font, bp::wrapper< CEGUI::Font > {

    Font_wrapper(::CEGUI::String const & name, ::CEGUI::String const & type_name, ::CEGUI::String const & filename, ::CEGUI::String const & resource_group, ::CEGUI::AutoScaledMode const auto_scaled, ::CEGUI::Sizef const & native_res )
    : CEGUI::Font( boost::ref(name), boost::ref(type_name), boost::ref(filename), boost::ref(resource_group), auto_scaled, boost::ref(native_res) )
      , bp::wrapper< CEGUI::Font >(){
        // constructor
    
    }

    void addFontProperties(  ){
        CEGUI::Font::addFontProperties(  );
    }

    virtual ::CEGUI::FontGlyph const * findFontGlyph( ::CEGUI::utf32 const codepoint ) const {
        if( bp::override func_findFontGlyph = this->get_override( "findFontGlyph" ) )
            return func_findFontGlyph( codepoint );
        else{
            return this->CEGUI::Font::findFontGlyph( codepoint );
        }
    }
    
    virtual ::CEGUI::FontGlyph const * default_findFontGlyph( ::CEGUI::utf32 const codepoint ) const {
        return CEGUI::Font::findFontGlyph( codepoint );
    }

    virtual void notifyDisplaySizeChanged( ::CEGUI::Sizef const & size ) {
        if( bp::override func_notifyDisplaySizeChanged = this->get_override( "notifyDisplaySizeChanged" ) )
            func_notifyDisplaySizeChanged( boost::ref(size) );
        else{
            this->CEGUI::Font::notifyDisplaySizeChanged( boost::ref(size) );
        }
    }
    
    void default_notifyDisplaySizeChanged( ::CEGUI::Sizef const & size ) {
        CEGUI::Font::notifyDisplaySizeChanged( boost::ref(size) );
    }

    virtual void onRenderSizeChanged( ::CEGUI::FontEventArgs & args ){
        if( bp::override func_onRenderSizeChanged = this->get_override( "onRenderSizeChanged" ) )
            func_onRenderSizeChanged( boost::ref(args) );
        else{
            this->CEGUI::Font::onRenderSizeChanged( boost::ref(args) );
        }
    }
    
    virtual void default_onRenderSizeChanged( ::CEGUI::FontEventArgs & args ){
        CEGUI::Font::onRenderSizeChanged( boost::ref(args) );
    }

    virtual void rasterise( ::CEGUI::utf32 start_codepoint, ::CEGUI::utf32 end_codepoint ) const {
        if( bp::override func_rasterise = this->get_override( "rasterise" ) )
            func_rasterise( start_codepoint, end_codepoint );
        else{
            this->CEGUI::Font::rasterise( start_codepoint, end_codepoint );
        }
    }
    
    virtual void default_rasterise( ::CEGUI::utf32 start_codepoint, ::CEGUI::utf32 end_codepoint ) const {
        CEGUI::Font::rasterise( start_codepoint, end_codepoint );
    }

    void setMaxCodepoint( ::CEGUI::utf32 codepoint ){
        CEGUI::Font::setMaxCodepoint( codepoint );
    }

    virtual void updateFont(  ){
        bp::override func_updateFont = this->get_override( "updateFont" );
        func_updateFont(  );
    }

    virtual void writeXMLToStream_impl( ::CEGUI::XMLSerializer & xml_stream ) const {
        bp::override func_writeXMLToStream_impl = this->get_override( "writeXMLToStream_impl" );
        func_writeXMLToStream_impl( boost::ref(xml_stream) );
    }

    virtual void fireEvent( ::CEGUI::String const & name, ::CEGUI::EventArgs & args, ::CEGUI::String const & eventNamespace="" ) {
        if( bp::override func_fireEvent = this->get_override( "fireEvent" ) )
            func_fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
        else{
            this->CEGUI::EventSet::fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
        }
    }
    
    void default_fireEvent( ::CEGUI::String const & name, ::CEGUI::EventArgs & args, ::CEGUI::String const & eventNamespace="" ) {
        CEGUI::EventSet::fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
    }

    void fireEvent_impl( ::CEGUI::String const & name, ::CEGUI::EventArgs & args ){
        CEGUI::EventSet::fireEvent_impl( boost::ref(name), boost::ref(args) );
    }

    ::CEGUI::ScriptModule * getScriptModule(  ) const {
        return CEGUI::EventSet::getScriptModule(  );
    }

    virtual ::CEGUI::RefCounted< CEGUI::BoundSlot > subscribeScriptedEvent( ::CEGUI::String const & name, ::CEGUI::String const & subscriber_name ) {
        if( bp::override func_subscribeScriptedEvent = this->get_override( "subscribeScriptedEvent" ) )
            return func_subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
        else{
            return this->CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
        }
    }
    
    ::CEGUI::RefCounted< CEGUI::BoundSlot > default_subscribeScriptedEvent( ::CEGUI::String const & name, ::CEGUI::String const & subscriber_name ) {
        return CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
    }

    virtual ::CEGUI::RefCounted< CEGUI::BoundSlot > subscribeScriptedEvent( ::CEGUI::String const & name, unsigned int group, ::CEGUI::String const & subscriber_name ) {
        if( bp::override func_subscribeScriptedEvent = this->get_override( "subscribeScriptedEvent" ) )
            return func_subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
        else{
            return this->CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
        }
    }
    
    ::CEGUI::RefCounted< CEGUI::BoundSlot > default_subscribeScriptedEvent( ::CEGUI::String const & name, unsigned int group, ::CEGUI::String const & subscriber_name ) {
        return CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
    }

};

void register_Font_class(){

    { //::CEGUI::Font
        typedef bp::class_< Font_wrapper, bp::bases< CEGUI::PropertySet, CEGUI::EventSet >, boost::noncopyable > Font_exposer_t;
        Font_exposer_t Font_exposer = Font_exposer_t( "Font", bp::no_init );
        bp::scope Font_scope( Font_exposer );
        Font_exposer.def( bp::init< CEGUI::String const &, CEGUI::String const &, CEGUI::String const &, CEGUI::String const &, CEGUI::AutoScaledMode, CEGUI::Sizef const & >(( bp::arg("name"), bp::arg("type_name"), bp::arg("filename"), bp::arg("resource_group"), bp::arg("auto_scaled"), bp::arg("native_res") )) );
        { //::CEGUI::Font::addFontProperties
        
            typedef void ( Font_wrapper::*addFontProperties_function_type )(  ) ;
            
            Font_exposer.def( 
                "addFontProperties"
                , addFontProperties_function_type( &Font_wrapper::addFontProperties )
                , "! Register all properties of this class.\n" );
        
        }
        { //::CEGUI::Font::drawText
        
            typedef float ( ::CEGUI::Font::*drawText_function_type )( ::CEGUI::GeometryBuffer &,::CEGUI::String const &,::CEGUI::Vector2f const &,::CEGUI::Rectf const *,::CEGUI::ColourRect const &,float const,float const,float const ) const;
            
            Font_exposer.def( 
                "drawText"
                , drawText_function_type( &::CEGUI::Font::drawText )
                , ( bp::arg("buffer"), bp::arg("text"), bp::arg("position"), bp::arg("clip_rect"), bp::arg("colours"), bp::arg("space_extra")=0.0f, bp::arg("x_scale")=1.0e+0f, bp::arg("y_scale")=1.0e+0f ) );
        
        }
        { //::CEGUI::Font::findFontGlyph
        
            typedef ::CEGUI::FontGlyph const * ( Font_wrapper::*findFontGlyph_function_type )( ::CEGUI::utf32 const ) const;
            
            Font_exposer.def( 
                "findFontGlyph"
                , findFontGlyph_function_type( &Font_wrapper::default_findFontGlyph )
                , ( bp::arg("codepoint") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "! finds FontGlyph in map and returns it, or 0 if none.\n" );
        
        }
        { //::CEGUI::Font::getAutoScaled
        
            typedef ::CEGUI::AutoScaledMode ( ::CEGUI::Font::*getAutoScaled_function_type )(  ) const;
            
            Font_exposer.def( 
                "getAutoScaled"
                , getAutoScaled_function_type( &::CEGUI::Font::getAutoScaled )
                , "*!\n\
                \n\
                    Checks whether this font is being auto-scaled and how.\n\
            \n\
                @return\n\
                    AutoScaledMode describing how this font should be auto scaled\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getBaseline
        
            typedef float ( ::CEGUI::Font::*getBaseline_function_type )( float ) const;
            
            Font_exposer.def( 
                "getBaseline"
                , getBaseline_function_type( &::CEGUI::Font::getBaseline )
                , ( bp::arg("y_scale")=1.0e+0f )
                , "*!\n\
                \n\
                    Return the number of pixels from the top of the highest glyph\n\
                    to the baseline\n\
            \n\
                @param y_scale\n\
                    Scaling factor to be applied to the baseline distance, where 1.0f\n\
                    is considered to be 'normal'.\n\
            \n\
                @return\n\
                    pixel spacing from top of front glyphs to baseline\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getCharAtPixel
        
            typedef ::size_t ( ::CEGUI::Font::*getCharAtPixel_function_type )( ::CEGUI::String const &,float,float ) const;
            
            Font_exposer.def( 
                "getCharAtPixel"
                , getCharAtPixel_function_type( &::CEGUI::Font::getCharAtPixel )
                , ( bp::arg("text"), bp::arg("pixel"), bp::arg("x_scale")=1.0e+0f )
                , "*!\n\
                \n\
                    Return the index of the closest text character in String  text\n\
                    that corresponds to pixel location  pixel if the text were rendered.\n\
            \n\
                @param text\n\
                    String object containing the text.\n\
            \n\
                @param pixel\n\
                    Specifies the (horizontal) pixel offset to return the character\n\
                    index for.\n\
            \n\
                @param x_scale\n\
                    Scaling factor to be applied to each glyph's x axis when measuring\n\
                    the text extent, where 1.0f is considered to be 'normal'.\n\
            \n\
                @return\n\
                    Returns a character index into String  text for the character that\n\
                    would be rendered closest to horizontal pixel offset  pixel if the\n\
                    text were to be rendered via this Font.  Range of the return is from\n\
                    0 to text.length(), so may actually return an index past the end of\n\
                    the string, which indicates  pixel was beyond the last character.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getCharAtPixel
        
            typedef ::size_t ( ::CEGUI::Font::*getCharAtPixel_function_type )( ::CEGUI::String const &,::size_t,float,float ) const;
            
            Font_exposer.def( 
                "getCharAtPixel"
                , getCharAtPixel_function_type( &::CEGUI::Font::getCharAtPixel )
                , ( bp::arg("text"), bp::arg("start_char"), bp::arg("pixel"), bp::arg("x_scale")=1.0e+0f )
                , "*!\n\
                \n\
                    Return the index of the closest text character in String  text,\n\
                    starting at character index  start_char, that corresponds\n\
                    to pixel location  pixel if the text were to be rendered.\n\
            \n\
                @param text\n\
                    String object containing the text.\n\
            \n\
                @param start_char\n\
                    index of the first character to consider.  This is the lowest\n\
                    value that will be returned from the call.\n\
            \n\
                @param pixel\n\
                    Specifies the (horizontal) pixel offset to return the character\n\
                    index for.\n\
            \n\
                @param x_scale\n\
                    Scaling factor to be applied to each glyph's x axis when measuring\n\
                    the text extent, where 1.0f is considered to be 'normal'.\n\
            \n\
                @return\n\
                    Returns a character index into String  text for the character that\n\
                    would be rendered closest to horizontal pixel offset  pixel if the\n\
                    text were to be rendered via this Font.  Range of the return is from\n\
                    0 to text.length(), so may actually return an index past the end of\n\
                    the string, which indicates  pixel was beyond the last character.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getDefaultResourceGroup
        
            typedef ::CEGUI::String const & ( *getDefaultResourceGroup_function_type )(  );
            
            Font_exposer.def( 
                "getDefaultResourceGroup"
                , getDefaultResourceGroup_function_type( &::CEGUI::Font::getDefaultResourceGroup )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "*!\n\
                \n\
                    Returns the default resource group currently set for Fonts.\n\
            \n\
                @return\n\
                    String describing the default resource group identifier that will be\n\
                    used when loading font data.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getFileName
        
            typedef ::CEGUI::String const & ( ::CEGUI::Font::*getFileName_function_type )(  ) const;
            
            Font_exposer.def( 
                "getFileName"
                , getFileName_function_type( &::CEGUI::Font::getFileName )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "! Return the filename of the used font.\n" );
        
        }
        { //::CEGUI::Font::getFontHeight
        
            typedef float ( ::CEGUI::Font::*getFontHeight_function_type )( float ) const;
            
            Font_exposer.def( 
                "getFontHeight"
                , getFontHeight_function_type( &::CEGUI::Font::getFontHeight )
                , ( bp::arg("y_scale")=1.0e+0f )
                , "*!\n\
                \n\
                    return the exact pixel height of the font.\n\
            \n\
                @param y_scale\n\
                    Scaling factor to be applied to the height, where 1.0f\n\
                    is considered to be 'normal'.\n\
            \n\
                @return\n\
                    float value describing the pixel height of the font without\n\
                    any additional padding.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getGlyphData
        
            typedef ::CEGUI::FontGlyph const * ( ::CEGUI::Font::*getGlyphData_function_type )( ::CEGUI::utf32 ) const;
            
            Font_exposer.def( 
                "getGlyphData"
                , getGlyphData_function_type( &::CEGUI::Font::getGlyphData )
                , ( bp::arg("codepoint") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
                \n\
                    Return a pointer to the glyphDat struct for the given codepoint,\n\
                    or 0 if the codepoint does not have a glyph defined.\n\
            \n\
                @param codepoint\n\
                    utf32 codepoint to return the glyphDat structure for.\n\
            \n\
                @return\n\
                    Pointer to the glyphDat struct for  codepoint, or 0 if no glyph\n\
                    is defined for  codepoint.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getLineSpacing
        
            typedef float ( ::CEGUI::Font::*getLineSpacing_function_type )( float ) const;
            
            Font_exposer.def( 
                "getLineSpacing"
                , getLineSpacing_function_type( &::CEGUI::Font::getLineSpacing )
                , ( bp::arg("y_scale")=1.0e+0f )
                , "*!\n\
                \n\
                    Return the pixel line spacing value for.\n\
            \n\
                @param y_scale\n\
                    Scaling factor to be applied to the line spacing, where 1.0f\n\
                    is considered to be 'normal'.\n\
            \n\
                @return\n\
                    Number of pixels between vertical base lines, i.e. The minimum\n\
                    pixel space between two lines of text.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getName
        
            typedef ::CEGUI::String const & ( ::CEGUI::Font::*getName_function_type )(  ) const;
            
            Font_exposer.def( 
                "getName"
                , getName_function_type( &::CEGUI::Font::getName )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "! Return the string holding the font name.\n" );
        
        }
        { //::CEGUI::Font::getNativeResolution
        
            typedef ::CEGUI::Sizef const & ( ::CEGUI::Font::*getNativeResolution_function_type )(  ) const;
            
            Font_exposer.def( 
                "getNativeResolution"
                , getNativeResolution_function_type( &::CEGUI::Font::getNativeResolution )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "*!\n\
                \n\
                    Return the native display size for this Font.  This is only relevant if\n\
                    the Font is being auto-scaled.\n\
            \n\
                @return\n\
                    Size object describing the native display size for this Font.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getTextAdvance
        
            typedef float ( ::CEGUI::Font::*getTextAdvance_function_type )( ::CEGUI::String const &,float ) const;
            
            Font_exposer.def( 
                "getTextAdvance"
                , getTextAdvance_function_type( &::CEGUI::Font::getTextAdvance )
                , ( bp::arg("text"), bp::arg("x_scale")=1.0e+0f )
                , "*!\n\
                \n\
                    Return pixel advance of the specified text when rendered with this Font.\n\
            \n\
                @param text\n\
                    String object containing the text to return the pixel advance for.\n\
            \n\
                @param x_scale\n\
                    Scaling factor to be applied to each glyph's x axis when\n\
                    measuring the advance, where 1.0f is considered to be 'normal'.\n\
            \n\
                @return\n\
                    pixel advance of  text when rendered with this Font.\n\
            \n\
                \note\n\
                    The difference between the advance and the extent of a text string is\n\
                    important for numerous reasons. Picture some scenario where a glyph\n\
                    has a swash which extends way beyond the subsequent glyph - the text\n\
                    extent of those two glyphs is to the end of the swash on the first glyph\n\
                    whereas the advance of those two glyphs is to the start of a theoretical\n\
                    third glyph - still beneath the swash of the first glyph.\n\
                    The difference can basically be summarised as follows:\n\
                    - the extent is the total rendered width of all glyphs in the string.\n\
                    - the advance is the width to the point where the next character would\n\
                      have been drawn.\n\
            \n\
                @see getTextExtent\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getTextExtent
        
            typedef float ( ::CEGUI::Font::*getTextExtent_function_type )( ::CEGUI::String const &,float ) const;
            
            Font_exposer.def( 
                "getTextExtent"
                , getTextExtent_function_type( &::CEGUI::Font::getTextExtent )
                , ( bp::arg("text"), bp::arg("x_scale")=1.0e+0f )
                , "*!\n\
                \n\
                    Return the pixel width of the specified text if rendered with\n\
                    this Font.\n\
            \n\
                @param text\n\
                    String object containing the text to return the rendered pixel\n\
                    width for.\n\
            \n\
                @param x_scale\n\
                    Scaling factor to be applied to each glyph's x axis when\n\
                    measuring the extent, where 1.0f is considered to be 'normal'.\n\
            \n\
                @return\n\
                    Number of pixels that  text will occupy when rendered with\n\
                    this Font.\n\
            \n\
                \note\n\
                    The difference between the advance and the extent of a text string is\n\
                    important for numerous reasons. Picture some scenario where a glyph\n\
                    has a swash which extends way beyond the subsequent glyph - the text\n\
                    extent of those two glyphs is to the end of the swash on the first glyph\n\
                    whereas the advance of those two glyphs is to the start of a theoretical\n\
                    third glyph - still beneath the swash of the first glyph.\n\
                    The difference can basically be summarised as follows:\n\
                    - the extent is the total rendered width of all glyphs in the string.\n\
                    - the advance is the width to the point where the next character would\n\
                      have been drawn.\n\
            \n\
                @see getTextAdvance\n\
                *\n" );
        
        }
        { //::CEGUI::Font::getTypeName
        
            typedef ::CEGUI::String const & ( ::CEGUI::Font::*getTypeName_function_type )(  ) const;
            
            Font_exposer.def( 
                "getTypeName"
                , getTypeName_function_type( &::CEGUI::Font::getTypeName )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "! Return the type of the font.\n" );
        
        }
        { //::CEGUI::Font::isCodepointAvailable
        
            typedef bool ( ::CEGUI::Font::*isCodepointAvailable_function_type )( ::CEGUI::utf32 ) const;
            
            Font_exposer.def( 
                "isCodepointAvailable"
                , isCodepointAvailable_function_type( &::CEGUI::Font::isCodepointAvailable )
                , ( bp::arg("cp") )
                , "*!\n\
                \n\
                    Return whether this Font can draw the specified code-point\n\
            \n\
                @param cp\n\
                    utf32 code point that is the subject of the query.\n\
            \n\
                @return\n\
                    true if the font contains a mapping for code point  cp,\n\
                    false if it does not contain a mapping for  cp.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::notifyDisplaySizeChanged
        
            typedef void ( ::CEGUI::Font::*notifyDisplaySizeChanged_function_type )( ::CEGUI::Sizef const & ) ;
            typedef void ( Font_wrapper::*default_notifyDisplaySizeChanged_function_type )( ::CEGUI::Sizef const & ) ;
            
            Font_exposer.def( 
                "notifyDisplaySizeChanged"
                , notifyDisplaySizeChanged_function_type(&::CEGUI::Font::notifyDisplaySizeChanged)
                , default_notifyDisplaySizeChanged_function_type(&Font_wrapper::default_notifyDisplaySizeChanged)
                , ( bp::arg("size") ) );
        
        }
        { //::CEGUI::Font::onRenderSizeChanged
        
            typedef void ( Font_wrapper::*onRenderSizeChanged_function_type )( ::CEGUI::FontEventArgs & ) ;
            
            Font_exposer.def( 
                "onRenderSizeChanged"
                , onRenderSizeChanged_function_type( &Font_wrapper::default_onRenderSizeChanged )
                , ( bp::arg("args") )
                , "! event trigger function for when the font rendering size changes.\n" );
        
        }
        { //::CEGUI::Font::rasterise
        
            typedef void ( Font_wrapper::*rasterise_function_type )( ::CEGUI::utf32,::CEGUI::utf32 ) const;
            
            Font_exposer.def( 
                "rasterise"
                , rasterise_function_type( &Font_wrapper::default_rasterise )
                , ( bp::arg("start_codepoint"), bp::arg("end_codepoint") )
                , "*!\n\
            \n\
                This function prepares a certain range of glyphs to be ready for\n\
                displaying. This means that after returning from this function\n\
                glyphs from d_cp_map[start_codepoint] to d_cp_map[end_codepoint]\n\
                should have their d_image member set. If there is an error\n\
                during rasterisation of some glyph, it's okay to leave the\n\
                d_image field set to NULL, in which case such glyphs will\n\
                be skipped from display.\n\
            @param start_codepoint\n\
                The lowest codepoint that should be rasterised\n\
            @param end_codepoint\n\
                The highest codepoint that should be rasterised\n\
            *\n" );
        
        }
        { //::CEGUI::Font::setAutoScaled
        
            typedef void ( ::CEGUI::Font::*setAutoScaled_function_type )( ::CEGUI::AutoScaledMode const ) ;
            
            Font_exposer.def( 
                "setAutoScaled"
                , setAutoScaled_function_type( &::CEGUI::Font::setAutoScaled )
                , ( bp::arg("auto_scaled") )
                , "*!\n\
                \n\
                    Enable or disable auto-scaling for this Font.\n\
            \n\
                @param auto_scaled\n\
                    AutoScaledMode describing how this font should be auto scaled\n\
            \n\
                @see AutoScaledMode\n\
                *\n" );
        
        }
        { //::CEGUI::Font::setDefaultResourceGroup
        
            typedef void ( *setDefaultResourceGroup_function_type )( ::CEGUI::String const & );
            
            Font_exposer.def( 
                "setDefaultResourceGroup"
                , setDefaultResourceGroup_function_type( &::CEGUI::Font::setDefaultResourceGroup )
                , ( bp::arg("resourceGroup") )
                , "*!\n\
                \n\
                    Sets the default resource group to be used when loading font data\n\
            \n\
                @param resourceGroup\n\
                    String describing the default resource group identifier to be used.\n\
            \n\
                @return\n\
                    Nothing.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::setMaxCodepoint
        
            typedef void ( Font_wrapper::*setMaxCodepoint_function_type )( ::CEGUI::utf32 ) ;
            
            Font_exposer.def( 
                "setMaxCodepoint"
                , setMaxCodepoint_function_type( &Font_wrapper::setMaxCodepoint )
                , ( bp::arg("codepoint") )
                , "*!\n\
            \n\
                Set the maximal glyph index. This reserves the respective\n\
                number of bits in the d_glyphPageLoaded array.\n\
            *\n" );
        
        }
        { //::CEGUI::Font::setNativeResolution
        
            typedef void ( ::CEGUI::Font::*setNativeResolution_function_type )( ::CEGUI::Sizef const & ) ;
            
            Font_exposer.def( 
                "setNativeResolution"
                , setNativeResolution_function_type( &::CEGUI::Font::setNativeResolution )
                , ( bp::arg("size") )
                , "*!\n\
                \n\
                    Set the native resolution for this Font\n\
            \n\
                @param size\n\
                    Size object describing the new native screen resolution for this Font.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::updateFont
        
            typedef void ( Font_wrapper::*updateFont_function_type )(  ) ;
            
            Font_exposer.def( 
                "updateFont"
                , updateFont_function_type( &Font_wrapper::updateFont )
                , "! Update the font as needed, according to the current parameters.\n" );
        
        }
        { //::CEGUI::Font::writeXMLToStream
        
            typedef void ( ::CEGUI::Font::*writeXMLToStream_function_type )( ::CEGUI::XMLSerializer & ) const;
            
            Font_exposer.def( 
                "writeXMLToStream"
                , writeXMLToStream_function_type( &::CEGUI::Font::writeXMLToStream )
                , ( bp::arg("xml_stream") )
                , "*!\n\
                \n\
                    Writes an xml representation of this Font to  out_stream.\n\
            \n\
                @param xml_stream\n\
                    Stream where xml data should be output.\n\
            \n\
                @return\n\
                    Nothing.\n\
                *\n" );
        
        }
        { //::CEGUI::Font::writeXMLToStream_impl
        
            typedef void ( Font_wrapper::*writeXMLToStream_impl_function_type )( ::CEGUI::XMLSerializer & ) const;
            
            Font_exposer.def( 
                "writeXMLToStream_impl"
                , writeXMLToStream_impl_function_type( &Font_wrapper::writeXMLToStream_impl )
                , ( bp::arg("xml_stream") )
                , "! implementaion version of writeXMLToStream.\n" );
        
        }
        Font_exposer.def_readonly( "DefaultColour", CEGUI::Font::DefaultColour, "! Colour value used whenever a colour is not specified.\n" );
        Font_exposer.add_static_property( "EventRenderSizeChanged"
                        , bp::make_getter( &CEGUI::Font::EventRenderSizeChanged
                                , bp::return_value_policy< bp::return_by_value >() ) );
        { //::CEGUI::EventSet::fireEvent
        
            typedef void ( ::CEGUI::EventSet::*fireEvent_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs &,::CEGUI::String const & ) ;
            typedef void ( Font_wrapper::*default_fireEvent_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs &,::CEGUI::String const & ) ;
            
            Font_exposer.def( 
                "fireEvent"
                , fireEvent_function_type(&::CEGUI::EventSet::fireEvent)
                , default_fireEvent_function_type(&Font_wrapper::default_fireEvent)
                , ( bp::arg("name"), bp::arg("args"), bp::arg("eventNamespace")="" ) );
        
        }
        { //::CEGUI::EventSet::fireEvent_impl
        
            typedef void ( Font_wrapper::*fireEvent_impl_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs & ) ;
            
            Font_exposer.def( 
                "fireEvent_impl"
                , fireEvent_impl_function_type( &Font_wrapper::fireEvent_impl )
                , ( bp::arg("name"), bp::arg("args") )
                , "! Implementation event firing member\n" );
        
        }
        { //::CEGUI::EventSet::getScriptModule
        
            typedef ::CEGUI::ScriptModule * ( Font_wrapper::*getScriptModule_function_type )(  ) const;
            
            Font_exposer.def( 
                "getScriptModule"
                , getScriptModule_function_type( &Font_wrapper::getScriptModule )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "! Implementation event firing member\n\
            ! Helper to return the script module pointer or throw.\n" );
        
        }
        { //::CEGUI::EventSet::subscribeScriptedEvent
        
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ::CEGUI::EventSet::*subscribeScriptedEvent_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( Font_wrapper::*default_subscribeScriptedEvent_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            
            Font_exposer.def( 
                "subscribeScriptedEvent"
                , subscribeScriptedEvent_function_type(&::CEGUI::EventSet::subscribeScriptedEvent)
                , default_subscribeScriptedEvent_function_type(&Font_wrapper::default_subscribeScriptedEvent)
                , ( bp::arg("name"), bp::arg("subscriber_name") ) );
        
        }
        { //::CEGUI::EventSet::subscribeScriptedEvent
        
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ::CEGUI::EventSet::*subscribeScriptedEvent_function_type )( ::CEGUI::String const &,unsigned int,::CEGUI::String const & ) ;
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( Font_wrapper::*default_subscribeScriptedEvent_function_type )( ::CEGUI::String const &,unsigned int,::CEGUI::String const & ) ;
            
            Font_exposer.def( 
                "subscribeScriptedEvent"
                , subscribeScriptedEvent_function_type(&::CEGUI::EventSet::subscribeScriptedEvent)
                , default_subscribeScriptedEvent_function_type(&Font_wrapper::default_subscribeScriptedEvent)
                , ( bp::arg("name"), bp::arg("group"), bp::arg("subscriber_name") ) );
        
        }
        Font_exposer.staticmethod( "getDefaultResourceGroup" );
        Font_exposer.staticmethod( "setDefaultResourceGroup" );
    }

}
