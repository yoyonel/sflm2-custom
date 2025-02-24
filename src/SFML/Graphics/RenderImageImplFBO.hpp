////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_RENDERIMAGEIMPLFBO_HPP
#define SFML_RENDERIMAGEIMPLFBO_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/RenderImageImpl.hpp>
#include <SFML/Window/Context.hpp>
#include <SFML/Window/GlResource.hpp>


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
/// \brief Specialization of RenderImageImpl using the
///        Frame Buffer Object OpenGL extension
///
////////////////////////////////////////////////////////////
class RenderImageImplFBO : public RenderImageImpl, GlResource
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    RenderImageImplFBO();

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~RenderImageImplFBO();

    ////////////////////////////////////////////////////////////
    /// \brief Check whether the system supports FBOs or not
    ///
    /// \return True if FBO render images are supported
    ///
    ////////////////////////////////////////////////////////////
    static bool IsSupported();

private :

    ////////////////////////////////////////////////////////////
    /// \brief Create the render image implementation
    ///
    /// \param width            Width of the image to render to
    /// \param height           Height of the image to render to
    /// \param textureId        OpenGL texture identifier of the target image
    /// \param depthBuffer      Is a depth buffer requested?
    /// \param stencilBuffer    Do you want this render-image to have a stencil buffer?
    ///
    /// \return True if creation has been successful
    ///
    ////////////////////////////////////////////////////////////
    virtual bool Create(unsigned int width, unsigned int height, unsigned int textureId, bool depthBuffer, bool stencilBuffer);

    ////////////////////////////////////////////////////////////
    /// \brief Activate or deactivate the render image for rendering
    ///
    /// \param active True to activate, false to deactivate
    ///
    /// \return True on success, false on failure
    ///
    ////////////////////////////////////////////////////////////
    virtual bool Activate(bool active);

    ////////////////////////////////////////////////////////////
    /// \brief Update the pixels of the target texture
    ///
    /// \param textureId OpenGL identifier of the target texture
    ///
    ////////////////////////////////////////////////////////////
    virtual void UpdateTexture(unsigned textureId);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    unsigned int myFrameBuffer; ///< OpenGL frame buffer object
    unsigned int myDepthBuffer; ///< Optional depth buffer attached to the frame buffer
    unsigned int myStencilBuffer;   ///< Optional stencil buffer attached to the frame buffer
    Context      myContext;     ///< Needs a separate OpenGL context for not messing up the other ones
};

} // namespace priv

} // namespace sf


#endif // SFML_RENDERIMAGEIMPLFBO_HPP
