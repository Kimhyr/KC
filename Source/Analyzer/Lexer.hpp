#pragma once
#ifndef ANALYZER_LEXER_HPP
#define ANALYZER_LEXER_HPP

#include "../Utils/Error.hpp"
#include "../Utils/String.hpp"
#include "Token.hpp"

struct Lexer {
  enum struct Flag {
    EoF = 0x01,
    Error = 0x02,
    Continue = 0x04,
  };

  ErrorBuffer *errBuf;
  const Char8 *sourcePath;
  UInt64 index;
  const Char8 *source;
  Char8 peek;
  Token::Point point;
  UInt8 flags;
  String buffer;

  Lexer(ErrorBuffer *errBuf, const Char8 *sourcePath, const Char8 *source);
  Void Destroy();

  Lexer::Flag Lex(Token *out);

  constexpr Char8 Peek(Char8 offset = 1) {
    return this->source[this->index + offset];
  }
  Void Advance();

  static constexpr Bool FlagHasEoF(Lexer::Flag flags) {
    return ((UInt8)flags | 0xfe) ^ 0xfe;
  }
};

#endif  // ANALYZER_LEXER_HPP
