/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2021 Bruno Van de Velde (vdv_b@tgui.eu)
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <TGUI/Font.hpp>
#include <TGUI/Backend.hpp>
#include <TGUI/BackendFont.hpp>
#include <TGUI/Loading/Deserializer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    namespace
    {
        Font globalFont;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Font::setGlobalFont(const Font& font)
    {
        globalFont = font;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Font Font::getGlobalFont()
    {
        if (!globalFont)
            globalFont = getBackend()->createDefaultFont();

        return globalFont;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Font::Font(std::nullptr_t)
    {
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Font::Font(const String& id) :
        Font(Deserializer::deserialize(ObjectConverter::Type::Font, id).getFont()) // Did not compile with clang 3.6 when using braces
    {
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Font::Font(const char* id) :
        Font(String{id})
    {
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Font::Font(const void* data, std::size_t sizeInBytes) :
        m_backendFont{getBackend()->createFont()}
    {
        m_backendFont->loadFromMemory(data, sizeInBytes);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Font::Font(std::shared_ptr<BackendFontBase> backendFont, const String& id) :
        m_backendFont(backendFont),
        m_id(id)
    {
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const String& Font::getId() const
    {
        return m_id;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Font::operator bool() const
    {
        return m_backendFont != nullptr;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Font::operator==(std::nullptr_t) const
    {
        return m_backendFont == nullptr;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Font::operator!=(std::nullptr_t) const
    {
        return m_backendFont != nullptr;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Font::operator==(const Font& right) const
    {
        return m_backendFont == right.m_backendFont;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Font::operator!=(const Font& right) const
    {
        return m_backendFont != right.m_backendFont;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    FontGlyph Font::getGlyph(char32_t codePoint, unsigned int characterSize, bool bold, float outlineThickness) const
    {
        TGUI_ASSERT(m_backendFont != nullptr, "Font::getGlyph called on font that wasn't initialized");
        return m_backendFont->getGlyph(codePoint, characterSize, bold, outlineThickness);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    float Font::getKerning(char32_t first, char32_t second, unsigned int characterSize, bool bold) const
    {
        if (m_backendFont)
            return m_backendFont->getKerning(first, second, characterSize, bold);
        else
            return 0;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    float Font::getLineSpacing(unsigned int characterSize) const
    {
        if (m_backendFont)
            return m_backendFont->getLineSpacing(characterSize);
        else
            return 0;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::shared_ptr<BackendFontBase> Font::getBackendFont() const
    {
        return m_backendFont;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
