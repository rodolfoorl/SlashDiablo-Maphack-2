/**
 * SlashDiablo Maphack
 * Copyright (C) SlashDiablo Community
 *
 * BH
 * Copyright 2011 (C) McGod
 *
 * This file is part of SlashDiablo Maphack.
 *
 * SlashDiablo Maphack is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Affero General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef BH_COMMON_STRING_UTIL_H_
#define BH_COMMON_STRING_UTIL_H_

#include <optional>
#include <string>
#include <string_view>

namespace common::str_util {
namespace ascii {

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns a copy of the specified characters with all uppercase 7-bit
 * ASCII characters converted to lowercase.
 */
template <typename CharT>
std::basic_string<CharT> ToLower(const CharT* str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns a copy of the specified characters with all uppercase 7-bit
 * ASCII characters converted to lowercase.
 */
template <typename CharT>
std::basic_string<CharT> ToLower(const std::basic_string<CharT>& str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns a copy of the specified characters with all uppercase 7-bit
 * ASCII characters converted to lowercase.
 */
template <typename CharT>
std::basic_string<CharT> ToLower(std::basic_string_view<CharT> str);

/**
 * Returns the lowercase character for a specified character. If the
 * character is not an uppercase character for 7-bit ASCII, then the
 * function returns the unmodified character.
 */
template <typename CharT>
constexpr CharT ToLowerChar(CharT ch);

}  // namespace ascii

/**
 * String-to-type functions
 */

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns true if the specified string is equal to "true" via
 * case-insensitive comparison. Returns false if the same comparison
 * applies to "false". Otherwise, returns nullopt.
 */
template <typename CharT>
std::optional<bool> ToBool(const CharT* str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns true if the specified string is equal to "true" via
 * case-insensitive comparison. Returns false if the same comparison
 * applies to "false". Otherwise, returns nullopt.
 */
template <typename CharT>
std::optional<bool> ToBool(const std::basic_string<CharT>& str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns true if the specified string is equal to "true" via
 * case-insensitive comparison. Returns false if the same comparison
 * applies to "false". Otherwise, returns nullopt.
 */
template <typename CharT>
std::optional<bool> ToBool(std::basic_string_view<CharT> str);

/**
 * String property functions
 */

/**
 * Determines the integer-base encoding that matches the contents of
 * the string. If the integer-base encoding could not be detected,
 * then the function returns nullopt.
 *
 * Only supports detection of octal, decimal, and hexadecimal.
 */
template <typename CharT>
constexpr std::optional<int> GetIntegerBase(const CharT* str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Determines the integer-base encoding that matches the contents of
 * the string. If the integer-base encoding could not be detected,
 * then the function returns nullopt.
 *
 * Only supports detection of octal, decimal, and hexadecimal.
 */
template <typename CharT>
std::optional<int> GetIntegerBase(const std::basic_string<CharT>& str);

/**
 * Determines the integer-base encoding that matches the contents of
 * the string. If the integer-base encoding could not be detected,
 * then the function returns nullopt.
 *
 * Only supports detection of octal, decimal, and hexadecimal.
 */
template <typename CharT>
constexpr std::optional<int> GetIntegerBase(
    std::basic_string_view<CharT> str);

/**
 * Determines the integer-base encoding that matches the contents of
 * the string's prefix. If the integer-base encoding could not be
 * detected, then the function returns nullopt.
 *
 * Only supports detection of octal, decimal, and hexadecimal.
 */
template <typename CharT>
constexpr std::optional<int> GetIntegerBaseFromPrefix(const CharT* str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Determines the integer-base encoding that matches the contents of
 * the string's prefix. If the integer-base encoding could not be
 * detected, then the function returns nullopt.
 *
 * Only supports detection of octal, decimal, and hexadecimal.
 */
template <typename CharT>
std::optional<int> GetIntegerBaseFromPrefix(
    const std::basic_string<CharT>& str);

/**
 * Determines the integer-base encoding that matches the contents of
 * the string's prefix. If the integer-base encoding could not be
 * detected, then the function returns nullopt.
 *
 * Only supports detection of octal, decimal, and hexadecimal.
 */
template <typename CharT>
constexpr std::optional<int> GetIntegerBaseFromPrefix(
    std::basic_string_view<CharT> str);

/**
 * Returns true if the specified string is representable as a decimal
 * number with the specified integer type.
 */
template <typename IntT, typename CharT>
constexpr bool IsDecimal(const CharT* str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns true if the specified string is representable as a decimal
 * number with the specified integer type.
 */
template <typename IntT, typename CharT>
bool IsDecimal(const std::basic_string<CharT>& str);

/**
 * Returns true if the specified string is representable as a decimal
 * number with the specified integer type.
 */
template <typename IntT, typename CharT>
constexpr bool IsDecimal(std::basic_string_view<CharT> str);

/**
 * Returns true if the specified character is representable as a
 * decimal number.
 */
template <typename CharT>
constexpr bool IsDecimalDigit(CharT ch);

/**
 * Returns true if the specified character is representable as a
 * number with the specified integer-base encoding.
 *
 * Only the values in the interval [1, 36] are valid for base. The
 * function will always return false if an invalid base is specified.
 */
template <typename CharT>
constexpr bool IsDigitOfBase(CharT ch, int base);

/**
 * Returns true if the specified string is representable as a
 * hexadecimal number with the specified integer type.
 */
template <typename IntT, typename CharT>
constexpr bool IsHex(const CharT* str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns true if the specified string is representable as a
 * hexadecimal number with the specified integer type.
 */
template <typename IntT, typename CharT>
bool IsHex(const std::basic_string<CharT>& str);

/**
 * Returns true if the specified string is representable as a
 * hexadecimal number with the specified integer type.
 */
template <typename IntT, typename CharT>
constexpr bool IsHex(std::basic_string_view<CharT> str);

/**
 * Returns true if the specified character is representable as a
 * hexadecimal number.
 */
template <typename CharT>
constexpr bool IsHexDigit(CharT ch);

/**
 * Returns true if the specified string is representable as an octal
 * number with the specified integer type.
 */
template <typename IntT, typename CharT>
constexpr bool IsOctal(const CharT* str);

// TODO (Mir Drualga): Make this constexpr in C++20.
/**
 * Returns true if the specified string is representable as an octal
 * number.
 */
template <typename CharT>
bool IsOctal(const std::basic_string<CharT>& str);

/**
 * Returns true if the specified string is representable as an octal
 * number.
 */
template <typename CharT>
constexpr bool IsOctal(std::basic_string_view<CharT> str);

/**
 * Returns true if the specified character is representable as an
 * octal number.
 */
template <typename CharT>
constexpr bool IsOctalDigit(CharT ch);

/**
 * String transformation functions
 */

/**
 * Returns a copy of the specified string, with the starting and
 * ending whitespace removed.
 */
template <typename CharT>
std::basic_string<CharT> Trim(const CharT* str);

/**
 * Returns a copy of the specified string, with the starting and
 * ending whitespace removed.
 */
template <typename CharT>
std::basic_string<CharT> Trim(const std::basic_string<CharT>& str);

/**
 * Returns a copy of the specified string, with the starting and
 * ending whitespace removed.
 */
template <typename CharT>
std::basic_string<CharT> Trim(std::basic_string_view<CharT> str);

/**
 * String-to-number functions
 */

/**
 * Returns an integer value converted from a string. If the string is
 * not a number, or cannot be represented with the interger type, then
 * nullopt is returned instead.
 */
template <typename IntT, typename CharT>
constexpr std::optional<IntT> ToInteger(const CharT* str);

/**
 * Returns an integer value converted from a string. If the string is
 * not a number, or cannot be represented with the interger type, then
 * nullopt is returned instead.
 */
template <typename IntT, typename CharT>
constexpr std::optional<IntT> ToInteger(const std::basic_string<CharT>& str);

/**
 * Returns an integer value converted from a string. If the string is
 * not a number, or cannot be represented with the interger type, then
 * nullopt is returned instead.
 */
template <typename IntT, typename CharT>
constexpr std::optional<IntT> ToInteger(std::basic_string_view<CharT> str);

/**
 * Returns an integer value converted from a character. If the
 * character is not a number, or cannot be represented with the
 * integer type, then nullopt is returned instead.
 */
template <typename IntT, typename CharT>
constexpr std::optional<IntT> ToIntegerFromDigit(CharT ch, int base);

}  // namespace common::str_util

#include "StringUtilTemplate.inc"
#include "StringUtilStaticTests.inc"

#endif  // BH_COMMON_STRING_UTIL_H_
