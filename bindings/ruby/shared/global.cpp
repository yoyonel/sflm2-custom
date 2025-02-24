/* rbSFML - Copyright (c) 2010 Henrik Valter Vogelius Hansson - groogy@groogy.se
 * This software is provided 'as-is', without any express or
 * implied warranty. In no event will the authors be held
 * liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute
 * it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 *    you must not claim that you wrote the original software.
 *    If you use this software in a product, an acknowledgment
 *    in the product documentation would be appreciated but
 *    is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 *    and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any
 *    source distribution.
 */
 
#include "global.hpp"

VALUE globalSFMLNamespace;

VALUE RetrieveSFMLClass( const char * aName )
{
	ID name = rb_intern( aName );
	if( rb_cvar_defined( globalSFMLNamespace, name ) == Qfalse )
	{
		rb_raise( rb_eRuntimeError, "This module depends on SFML::%s", aName );
	}
	
	return rb_cvar_get( globalSFMLNamespace, name );
}
