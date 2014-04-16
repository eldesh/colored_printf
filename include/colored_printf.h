#if !defined COLORED_PRINTF_INCLUDED
#define      COLORED_PRINTF_INCLUDED

#include <stdlib.h>

//! terminal foreground color
extern uint8_t const TERMINAL_FR_BLACK  ;
extern uint8_t const TERMINAL_FR_RED    ;
extern uint8_t const TERMINAL_FR_GREEN  ;
extern uint8_t const TERMINAL_FR_YELLOW ;
extern uint8_t const TERMINAL_FR_BLUE   ;
extern uint8_t const TERMINAL_FR_MAGENTA;
extern uint8_t const TERMINAL_FR_CYAN   ;
extern uint8_t const TERMINAL_FR_WHITE  ;

//! terminal background color
extern uint8_t const TERMINAL_BK_BLACK  ;
extern uint8_t const TERMINAL_BK_RED    ;
extern uint8_t const TERMINAL_BK_GREEN  ;
extern uint8_t const TERMINAL_BK_YELLOW ;
extern uint8_t const TERMINAL_BK_BLUE   ;
extern uint8_t const TERMINAL_BK_MAGENTA;
extern uint8_t const TERMINAL_BK_CYAN   ;
extern uint8_t const TERMINAL_BK_WHITE  ;

//! Text attributes
extern uint8_t const TEXT_ATTR_OFF       ;   //!< All attributes off
extern uint8_t const TEXT_ATTR_BOLD      ;   //!< Bold on
extern uint8_t const TEXT_ATTR_UNDERSCORE;   //!< Underscore (on monochrome display adapter only)
extern uint8_t const TEXT_ATTR_BLINK     ;   //!< Blink on
extern uint8_t const TEXT_ATTR_REVERSE   ;   //!< Reverse video on
extern uint8_t const TEXT_ATTR_CONCEALED ;   //!< Concealed on

int vfprintf_colored(uint8_t qualify, FILE * fp, char const * format, va_list ap);
int fprintf_colored(uint8_t qualify, FILE * fp, char const * format, ...);
int printf_colored(uint8_t qualify, char const * format, ...);

/**
 * \pre gray < 24
 */
int fprintf_gray(FILE * fp, uint8_t gray, char const * format, ...);

typedef struct {
	uint8_t red;	//!< < 6
	uint8_t green;  //!< < 6
	uint8_t blue;   //!< < 6
} terminal_256color_t;

int fprintf_color (FILE * fp, terminal_256color_t color, char const * format, ...);

#endif    /* COLORED_PRINTF_INCLUDED */

