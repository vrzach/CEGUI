/***********************************************************************
    filename:   ItemModel.h
    created:    Tue May 20 2014
    author:     Timotei Dolean <timotei21@gmail.com>

    purpose:    Provides ModelIndex and ItemModel which are the basis of the
                Model-View architecture.
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2014 Paul D Turner & The CEGUI Development Team
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
#ifndef _CEGUIItemModel_h_
#define _CEGUIItemModel_h_

#include "CEGUI/Base.h"
#include "CEGUI/String.h"

// Start of CEGUI namespace section
namespace CEGUI
{

/*!
\brief
    Class that holds an index to a model item.
*/
class CEGUIEXPORT ModelIndex
{
public:
    /*!
    \brief
        Constructs an index with the specified model data

    \param model_data
        Optional model data associated with this index.
    */
    ModelIndex(void* model_data = 0) :
        d_modelData(model_data)
    {
    }

    /*!
    \brief
        Pointer to model-specific data.

    \remark
        DO NOT USE/INTERPRET in view. This is just a simple way for the model
        to be able to manage its data and logic.
    */
    void* d_modelData;
};

/*!
\brief
    Enumeration that specifies which type of data is required from the ItemModel
    in order for the View to render it.

    Users can use the IDR_UserDefinedItemDataRole as a base for custom roles.
*/
enum ItemDataRole
{
    IDR_Text,
    IDR_ImageDecoration,
    IDR_Tooltip,

    IDR_UserDefinedItemDataRole = 0x1000 //!< This marks the beginning of the user-defined item data roles
};

/*!
\brief
    Abstract class defining the interface between the view and the model.
    This is used by views to query data that is to be shown.
*/
class CEGUIEXPORT ItemModel
{
public:
    virtual ~ItemModel();

    //! Name of the event triggered after new children were added
    static const String EventChildrenAdded;
    //! Name of the event triggered after existing children were removed
    static const String EventChildrenRemoved;
    //! Name of the event triggered after existing children's data was changed
    static const String EventChildrenDataChanged;

    /*!
    \brief
        Returns true if the specified ModelIndex is valid, false otherwise.

    \param model_index
        The ModelIndex for which to get the validity.
    */
    virtual bool isValidIndex(const ModelIndex& model_index) const = 0;

    /*!
    \brief
        Creates a new ModelIndex for the specified child and parent index.

    \param child
        The child index, which is a number between 0 and getChildrenCount(parentIndex).

    \param model_index
        The parent ModelIndex of the new index.

    \return
        The newly created ModelIndex.
    */
    virtual ModelIndex makeIndex(int child, const ModelIndex& model_index) = 0;

    /*!
    \brief
        Returns the ModelIndex which is parent for the specified ModelIndex.

    \param model_index
        The ModelIndex for which to compute the parent index.

    \return
        The parent ModelIndex.
    */
    virtual ModelIndex getParentIndex(const ModelIndex& model_index) = 0;

    /*!
    \brief
        Returns the number of children of the specified ModelIndex.

    \param model_index
        The ModelIndex for which to compute the number of children.
    */
    virtual int getChildrenCount(const ModelIndex& model_index) = 0;

    /*!
    \brief
        Returns the string representation of the specified data role.
        It is up to the view to interpret the string based on the role requested.

    \remark
        For example, in the case of an image decoration, the name of the image
        could be returned, and the view could use ImageManager to retrieve the
        specific Image instance by the name and render that.

    \param model_index
        The ModelIndex for which to compute the string representation.

    \param role
        The role of data to be returned.
    */
    virtual String getData(const ModelIndex& model_index, ItemDataRole role = IDR_Text) = 0;
};

} // End of  CEGUI namespace section

#endif  // end of guard _CEGUIItemModel_h