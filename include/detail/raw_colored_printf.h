#if !defined RAW_COLORED_PRINTF_INCLUDED
#define      RAW_COLORED_PRINTF_INCLUDED

#include <stdlib.h>
#include <stdint.h>

//! terminal foreground color
extern uint8_t const TERMINAL_FR_BLACK  ;
extern uint8_t const TERMINAL_FR_RED    ;
extern uint8_t const TERMINAL_FR_GREEN  ;
extern uint8_t const TERMINAL_FR_YELLOW ;
extern uint8_t const TERMINAL_FR_BLUE   ;
extern uint8_t const TERMINAL_FR_MAGENTA;
extern uint8_t const TERMINAL_FR_CYAN   ;
extern uint8_t const TERMINAL_FR_WHITE  ;
extern uint8_t const TERMINAL_FR_256COLOR_TEXT;
extern uint8_t const TERMINAL_FR_DEFAULT;

//! terminal background color
extern uint8_t const TERMINAL_BK_BLACK  ;
extern uint8_t const TERMINAL_BK_RED    ;
extern uint8_t const TERMINAL_BK_GREEN  ;
extern uint8_t const TERMINAL_BK_YELLOW ;
extern uint8_t const TERMINAL_BK_BLUE   ;
extern uint8_t const TERMINAL_BK_MAGENTA;
extern uint8_t const TERMINAL_BK_CYAN   ;
extern uint8_t const TERMINAL_BK_WHITE  ;
extern uint8_t const TERMINAL_BK_256COLOR_TEXT;
extern uint8_t const TERMINAL_BK_DEFAULT;

//! Text attributes
extern uint8_t const TEXT_ATTR_OFF       ;   //!< All attributes off
extern uint8_t const TEXT_ATTR_BOLD      ;   //!< Bold on
extern uint8_t const TEXT_ATTR_UNDERSCORE;   //!< Underscore (on monochrome display adapter only)
extern uint8_t const TEXT_ATTR_BLINK     ;   //!< Blink on
extern uint8_t const TEXT_ATTR_REVERSE   ;   //!< Reverse video on
extern uint8_t const TEXT_ATTR_CONCEALED ;   //!< Concealed on

int fprintf_qualify (FILE * fp, uint8_t qualify);
int  printf_qualify (uint8_t qualify);
int vfprintf_colored(uint8_t qualify, FILE * fp, char const * format, va_list ap);
int fprintf_colored(uint8_t qualify, FILE * fp, char const * format, ...);
int printf_colored(uint8_t qualify, char const * format, ...);

#endif    /* RAW_COLORED_PRINTF_INCLUDED */

