// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "Exception.pypp.hpp"

namespace bp = boost::python;

struct Exception_wrapper : CEGUI::Exception, bp::wrapper< CEGUI::Exception > {

    Exception_wrapper(::CEGUI::String const & message="", ::CEGUI::String const & name="CEGUI::Exception", ::CEGUI::String const & filename="", int line=0, ::CEGUI::String const & function="" )
    : CEGUI::Exception( boost::ref(message), boost::ref(name), boost::ref(filename), line, boost::ref(function) )
      , bp::wrapper< CEGUI::Exception >(){
        // constructor
    
    }

};

void translate_Exception( const CEGUI::Exception& exc ){
    PyErr_SetString( PyExc_RuntimeError, exc.what() ); 
}

void register_Exception_class(){

    { //::CEGUI::Exception
        typedef bp::class_< Exception_wrapper, boost::noncopyable > Exception_exposer_t;
        Exception_exposer_t Exception_exposer = Exception_exposer_t( "Exception", bp::no_init );
        bp::scope Exception_scope( Exception_exposer );
        Exception_exposer.def( bp::init< bp::optional< CEGUI::String const &, CEGUI::String const &, CEGUI::String const &, int, CEGUI::String const & > >(( bp::arg("message")="", bp::arg("name")="CEGUI::Exception", bp::arg("filename")="", bp::arg("line")=(int)(0), bp::arg("function")="" )) );
        { //::CEGUI::Exception::isStdErrEnabled
        
            typedef bool ( *isStdErrEnabled_function_type )(  );
            
            Exception_exposer.def( 
                "isStdErrEnabled"
                , isStdErrEnabled_function_type( &::CEGUI::Exception::isStdErrEnabled )
                , "*!\n\
                \n\
                  Checks whether newly constructed exceptions will output to stderr\n\
            \n\
                  @see\n\
                     Exception.setStdErrEnabled\n\
                *\n" );
        
        }
        { //::CEGUI::Exception::setStdErrEnabled
        
            typedef void ( *setStdErrEnabled_function_type )( bool );
            
            Exception_exposer.def( 
                "setStdErrEnabled"
                , setStdErrEnabled_function_type( &::CEGUI::Exception::setStdErrEnabled )
                , ( bp::arg("enabled") )
                , "*!\n\
                \n\
                  Sets whether every exception construction should output to stderr\n\
            \n\
                \note\n\
                  The default is true, all constructed exceptions output to stderr\n\
            \n\
                  You should only set it to false if you:\n\
                  1) Know where your log is\n\
                  2) Know what the log is for\n\
                  3) Know how to use the info that's in the log\n\
                *\n" );
        
        }
        Exception_exposer.staticmethod( "isStdErrEnabled" );
        Exception_exposer.staticmethod( "setStdErrEnabled" );
        bp::register_exception_translator< CEGUI::Exception >( &translate_Exception );
    }

}
