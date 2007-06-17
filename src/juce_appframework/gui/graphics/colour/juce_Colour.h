/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-7 by Raw Material Software ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the
   GNU General Public License, as published by the Free Software Foundation;
   either version 2 of the License, or (at your option) any later version.

   JUCE is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with JUCE; if not, visit www.gnu.org/licenses or write to the
   Free Software Foundation, Inc., 59 Temple Place, Suite 330, 
   Boston, MA 02111-1307 USA

  ------------------------------------------------------------------------------

   If you'd like to release a closed-source product which uses JUCE, commercial
   licenses are also available: visit www.rawmaterialsoftware.com/juce for
   more information.

  ==============================================================================
*/

#ifndef __JUCE_COLOUR_JUCEHEADER__
#define __JUCE_COLOUR_JUCEHEADER__

#include "../colour/juce_PixelFormats.h"


//==============================================================================
/**
    Represents a colour, also including a transparency value.

    The colour is stored internally as unsigned 8-bit red, green, blue and alpha values.
*/
class JUCE_API  Colour
{
public:
    //==============================================================================
    /** Creates a transparent black colour. */
    JUCE_CALLTYPE Colour() throw();

    /** Creates a copy of another Colour object. */
    JUCE_CALLTYPE Colour (const Colour& other) throw();

    /** Creates a colour from a 32-bit ARGB value.

        The format of this number is:
            ((alpha << 24) | (red << 16) | (green << 16) | blue).

        All components in the range 0x00 to 0xff.
        An alpha of 0x00 is completely transparent, alpha of 0xff is opaque.

        @see getPixelARGB
    */
    explicit JUCE_CALLTYPE Colour (const uint32 argb) throw();

    /** Creates an opaque colour using 8-bit red, green and blue values */
    JUCE_CALLTYPE Colour (const uint8 red,
                          const uint8 green,
                          const uint8 blue) throw();

    /** Creates a colour using 8-bit red, green, blue and alpha values. */
    JUCE_CALLTYPE Colour (const uint8 red,
                          const uint8 green,
                          const uint8 blue,
                          const uint8 alpha) throw();

    /** Creates a colour from 8-bit red, green, and blue values, and a floating-point alpha.

        Alpha of 0.0 is transparent, alpha of 1.0f is opaque.
        Values outside the valid range will be clipped.
    */
    JUCE_CALLTYPE Colour (const uint8 red,
                          const uint8 green,
                          const uint8 blue,
                          const float alpha) throw();

    /** Creates a colour using floating point hue, saturation and brightness values, and an 8-bit alpha.

        The floating point values must be between 0.0 and 1.0.
        An alpha of 0x00 is completely transparent, alpha of 0xff is opaque.
        Values outside the valid range will be clipped.
    */
    JUCE_CALLTYPE Colour (const float hue,
                          const float saturation,
                          const float brightness,
                          const uint8 alpha) throw();

    /** Creates a colour using floating point hue, saturation, brightness and alpha values.

        All values must be between 0.0 and 1.0.
        Numbers outside the valid range will be clipped.
    */
    JUCE_CALLTYPE Colour (const float hue,
                          const float saturation,
                          const float brightness,
                          const float alpha) throw();

    /** Destructor. */
    JUCE_CALLTYPE ~Colour() throw();

    /** Copies another Colour object. */
    const Colour& JUCE_CALLTYPE operator= (const Colour& other) throw();

    /** Compares two colours. */
    bool JUCE_CALLTYPE operator== (const Colour& other) const throw();
    /** Compares two colours. */
    bool JUCE_CALLTYPE operator!= (const Colour& other) const throw();

    //==============================================================================
    /** Returns the red component of this colour.

        @returns a value between 0x00 and 0xff.
    */
    uint8 JUCE_CALLTYPE getRed() const throw()                    { return argb.getRed(); }

    /** Returns the green component of this colour.

        @returns a value between 0x00 and 0xff.
    */
    uint8 JUCE_CALLTYPE getGreen() const throw()                  { return argb.getGreen(); }

    /** Returns the blue component of this colour.

        @returns a value between 0x00 and 0xff.
    */
    uint8 JUCE_CALLTYPE getBlue() const throw()                   { return argb.getBlue(); }

    /** Returns the red component of this colour as a floating point value.

        @returns a value between 0.0 and 1.0
    */
    float JUCE_CALLTYPE getFloatRed() const throw();

    /** Returns the green component of this colour as a floating point value.

        @returns a value between 0.0 and 1.0
    */
    float JUCE_CALLTYPE getFloatGreen() const throw();

    /** Returns the blue component of this colour as a floating point value.

        @returns a value between 0.0 and 1.0
    */
    float JUCE_CALLTYPE getFloatBlue() const throw();

    /** Returns a premultiplied ARGB pixel object that represents this colour.
    */
    const PixelARGB JUCE_CALLTYPE getPixelARGB() const throw();

    /** Returns a 32-bit integer that represents this colour.

        The format of this number is:
            ((alpha << 24) | (red << 16) | (green << 16) | blue).
    */
    uint32 JUCE_CALLTYPE getARGB() const throw();

    //==============================================================================
    /** Returns the colour's alpha (opacity).

        Alpha of 0x00 is completely transparent, 0xff is completely opaque.
    */
    uint8 JUCE_CALLTYPE getAlpha() const throw()                  { return argb.getAlpha(); }

    /** Returns the colour's alpha (opacity) as a floating point value.

        Alpha of 0.0 is completely transparent, 1.0 is completely opaque.
    */
    float JUCE_CALLTYPE getFloatAlpha() const throw();

    /** Returns true if this colour is completely opaque.

        Equivalent to (getAlpha() == 0xff).
    */
    bool JUCE_CALLTYPE isOpaque() const throw();

    /** Returns true if this colour is completely transparent.

        Equivalent to (getAlpha() == 0x00).
    */
    bool JUCE_CALLTYPE isTransparent() const throw();

    /** Returns a colour that's the same colour as this one, but with a new alpha value. */
    const Colour JUCE_CALLTYPE withAlpha (const uint8 newAlpha) const throw();

    /** Returns a colour that's the same colour as this one, but with a new alpha value. */
    const Colour JUCE_CALLTYPE withAlpha (const float newAlpha) const throw();

    /** Returns a colour that's the same colour as this one, but with a modified alpha value.

        The new colour's alpha will be this object's alpha multiplied by the value passed-in.
    */
    const Colour JUCE_CALLTYPE withMultipliedAlpha (const float alphaMultiplier) const throw();

    //==============================================================================
    /** Returns a colour that is the result of alpha-compositing a new colour over this one.

        If the foreground colour is semi-transparent, it is blended onto this colour
        accordingly.
    */
    const Colour JUCE_CALLTYPE overlaidWith (const Colour& foregroundColour) const throw();

    //==============================================================================
    /** Returns the colour's hue component.
        The value returned is in the range 0.0 to 1.0
    */
    float JUCE_CALLTYPE getHue() const throw();

    /** Returns the colour's saturation component.
        The value returned is in the range 0.0 to 1.0
    */
    float JUCE_CALLTYPE getSaturation() const throw();

    /** Returns the colour's brightness component.
        The value returned is in the range 0.0 to 1.0
    */
    float JUCE_CALLTYPE getBrightness() const throw();

    /** Returns the colour's hue, saturation and brightness components all at once.
        The values returned are in the range 0.0 to 1.0
    */
    void JUCE_CALLTYPE getHSB (float& hue,
                               float& saturation,
                               float& brightness) const throw();

    //==============================================================================
    /** Returns a copy of this colour with a different hue. */
    const Colour JUCE_CALLTYPE withHue (const float newHue) const throw();

    /** Returns a copy of this colour with a different saturation. */
    const Colour JUCE_CALLTYPE withSaturation (const float newSaturation) const throw();

    /** Returns a copy of this colour with a different brightness.
        @see brighter, darker, withMultipliedBrightness
    */
    const Colour JUCE_CALLTYPE withBrightness (const float newBrightness) const throw();

    /** Returns a copy of this colour with it hue rotated.

        The new colour's hue is ((this->getHue() + amountToRotate) % 1.0)

        @see brighter, darker, withMultipliedBrightness
    */
    const Colour JUCE_CALLTYPE withRotatedHue (const float amountToRotate) const throw();

    /** Returns a copy of this colour with its saturation multiplied by the given value.

        The new colour's saturation is (this->getSaturation() * multiplier)
        (the result is clipped to legal limits).
    */
    const Colour JUCE_CALLTYPE withMultipliedSaturation (const float multiplier) const throw();

    /** Returns a copy of this colour with its brightness multiplied by the given value.

        The new colour's saturation is (this->getBrightness() * multiplier)
        (the result is clipped to legal limits).
    */
    const Colour JUCE_CALLTYPE withMultipliedBrightness (const float amount) const throw();

    //==============================================================================
    /** Returns a brighter version of this colour.

        @param amountBrighter   how much brighter to make it - a value from 0 to 1.0 where 0 is
                                unchanged, and higher values make it brighter
        @see withMultipliedBrightness
    */
    const Colour JUCE_CALLTYPE brighter (float amountBrighter = 0.4f) const throw();

    /** Returns a darker version of this colour.

        @param amountDarker     how much darker to make it - a value from 0 to 1.0 where 0 is
                                unchanged, and higher values make it darker
        @see withMultipliedBrightness
    */
    const Colour JUCE_CALLTYPE darker (float amountDarker = 0.4f) const throw();

    //==============================================================================
    /** Returns a colour that will be clearly visible against this colour.

        The amount parameter indicates how contrasting the new colour should
        be, so e.g. Colours::black.contrasting (0.1f) will return a colour
        that's just a little bit lighter; Colours::black.contrasting (1.0f) will
        return white; Colours::white.contrasting (1.0f) will return black, etc.
    */
    const Colour JUCE_CALLTYPE contrasting (const float amount = 1.0f) const throw();

    /** Returns a colour that contrasts against two colours.

        Looks for a colour that contrasts with both of the colours passed-in.

        Handy for things like choosing a highlight colour in text editors, etc.
    */
    static const Colour JUCE_CALLTYPE contrasting (const Colour& colour1,
                                                   const Colour& colour2) throw();

    //==============================================================================
    /** Returns an opaque shade of grey.

        @param brightness the level of grey to return - 0 is black, 1.0 is white
    */
    static const Colour JUCE_CALLTYPE greyLevel (const float brightness) throw();

    //==============================================================================
    /** Returns a stringified version of this colour.

        The string can be turned back into a colour using the fromString() method.
    */
    const String JUCE_CALLTYPE toString() const throw();

    /** Reads the colour from a string that was created with toString().
    */
    static const Colour JUCE_CALLTYPE fromString (const String& encodedColourString);

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    PixelARGB argb;
};

#endif   // __JUCE_COLOUR_JUCEHEADER__
