// fielddecode.c was generated by ProtoGen version 3.5.c

/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Oliver Walters / Currawong Engineering Pty Ltd
 */

#include "fielddecode.h"

/*!
 * Decode a null terminated string from a byte stream
 * \param string receives the deocded null-terminated string.
 * \param bytes is a pointer to the byte stream to be decoded.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by the number of bytes decoded when this function
 *        is complete.
 * \param maxLength is the maximum number of bytes that can be decoded.
 *        maxLength includes the null terminator, which is always applied.
 * \param fixedLength should be 1 to force the number of bytes decoded to be
 *        exactly equal to maxLength.
 */
void stringFromBytes(char* string, const uint8_t* bytes, int* index, int maxLength, int fixedLength)
{
    int i;

    // increment byte pointer for starting point
    bytes += *index;

    for(i = 0; i < maxLength - 1; i++)
    {
        if(bytes[i] == 0)
            break;
        else
            string[i] = (char)bytes[i];
    }

    // Make sure we include null terminator
    string[i++] = 0;

    if(fixedLength)
        (*index) += maxLength;
    else
        (*index) += i;

}// stringFromBytes


/*!
 * Copy an array of bytes from a byte stream without changing the order.
 * \param data receives the copied bytes
 * \param bytes is a pointer to the byte stream to be copied from.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by num when this function is complete.
 * \param num is the number of bytes to copy
 */
void bytesFromBeBytes(uint8_t* data, const uint8_t* bytes, int* index, int num)
{
    // increment byte pointer for starting point
    bytes += (*index);

    // Increment byte index to indicate number of bytes copied
    (*index) += num;

    // Copy the bytes without changing the order
    while(num > 0)
    {
        *(data++) = *(bytes++);
        num--;
    }

}// bytesFromBeBytes


/*!
 * Copy an array of bytes from a byte stream, reversing the order.
 * \param data receives the copied bytes
 * \param bytes is a pointer to the byte stream to be copied.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by num when this function is complete.
 * \param num is the number of bytes to copy
 */
void bytesFromLeBytes(uint8_t* data, const uint8_t* bytes, int* index, int num)
{
    // increment byte pointer for starting point
    bytes += (*index);

    // Increment byte index to indicate number of bytes copied
    (*index) += num;

    // To encode as "little endian bytes", (a nonsensical statement), reverse the byte order
    bytes += (num - 1);

    // Copy the bytes, reversing the order
    while(num > 0)
    {
        *(data++) = *(bytes--);
        num--;
    }

}// bytesFromLeBytes

/*!
 * Decode a 4 byte float from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
float float32FromBeBytes(const uint8_t* bytes, int* index)
{
    union
    {
        float floatValue;
        uint32_t integerValue;
    }field;

    field.integerValue = uint32FromBeBytes(bytes, index);

    return field.floatValue;
}

/*!
 * Decode a 4 byte float from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
float float32FromLeBytes(const uint8_t* bytes, int* index)
{
    union
    {
        float floatValue;
        uint32_t integerValue;
    }field;

    field.integerValue = uint32FromLeBytes(bytes, index);

    return field.floatValue;
}

/*!
 * Decode a unsigned 4 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint32FromBeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}

/*!
 * Decode a unsigned 4 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint32FromLeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 3;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}

/*!
 * Decode a signed 4 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int32FromBeBytes(const uint8_t* bytes, int* index)
{
    int32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}

/*!
 * Decode a signed 4 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int32FromLeBytes(const uint8_t* bytes, int* index)
{
    int32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 3;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}

/*!
 * Decode a unsigned 3 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint24FromBeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return number;
}

/*!
 * Decode a unsigned 3 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint24FromLeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 2;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return number;
}

/*!
 * Decode a signed 3 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int24FromBeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int32_t m = 0x00800000;
    int32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return (number ^ m) - m;
}

/*!
 * Decode a signed 3 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int24FromLeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int32_t m = 0x00800000;
    int32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 2;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return (number ^ m) - m;
}

/*!
 * Decode a unsigned 2 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint16_t uint16FromBeBytes(const uint8_t* bytes, int* index)
{
    uint16_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}

/*!
 * Decode a unsigned 2 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint16_t uint16FromLeBytes(const uint8_t* bytes, int* index)
{
    uint16_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 1;

    number = *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}

/*!
 * Decode a signed 2 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
int16_t int16FromBeBytes(const uint8_t* bytes, int* index)
{
    int16_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}

/*!
 * Decode a signed 2 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
int16_t int16FromLeBytes(const uint8_t* bytes, int* index)
{
    int16_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 1;

    number = *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}

// end of fielddecode.c
