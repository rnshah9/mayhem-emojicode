//
//  EmojicodeSharedTypes.h
//  Emojicode
//
//  Created by Theo Weidmann on 19/07/15.
//  Copyright (c) 2015 Theo Weidmann. All rights reserved.
//

#ifndef EmojicodeShared_h
#define EmojicodeShared_h

#ifndef defaultPackagesDirectory
#define defaultPackagesDirectory "/usr/local/EmojicodePackages"
#endif

#define REMOTE_MASK (1 << 31)

/// @returns True if @c c is a whitespace character. See http://www.unicode.org/Public/6.3.0/ucd/PropList.txt
inline bool isWhitespace(char32_t c) {
    return (0x9 <= c && c <= 0xD) || c == 0x20 || c == 0x85 || c == 0xA0 || c == 0x1680 || (0x2000 <= c && c <= 0x200A)
    || c == 0x2028 || c== 0x2029 || c == 0x2029 || c == 0x202F || c == 0x205F || c == 0x3000 || c == 0xFE0F;
}

enum class ObjectVariableType {
    /// There is an object pointer a the given index
    Simple = 0,
    /// There is an object pointer a the given index if the value at @c condition is truthy
    Condition = 1,
    Box = 2,
    ConditionalSkip = 3
};

enum class ContextType {
    None = 0,
    Object = 1,
    ValueReference = 2,
};

#endif /* EmojicodeShared_h */
