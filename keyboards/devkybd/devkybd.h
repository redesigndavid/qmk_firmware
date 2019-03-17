/* Copyright 2018 ''
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DEVKYBD_H
#define DEVKYBD_H

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
	L00, L01, L02, L03, L04, L05,   R00, R01, R02, R03, R04, R05,\
	L10, L11, L12, L13, L14, L15,   R10, R11, R12, R13, R14, R15,\
	L20, L21, L22, L23, L24, L25,   R20, R21, R22, R23, R24, R25,\
	L30, L31, L32, L33, L34, L35,   R30, R31, R32, R33, R34, R35,\
	               L43, L44, L45,   R40, R41, R42                \
	) \
	{ \
		{ R05,   R15,   R25,   R35,   KC_NO,  }, \
		{ R04,   R14,   R24,   R34,   KC_NO,  }, \
		{ R03,   R13,   R23,   R33,   KC_NO,  }, \
		{ R02,   R12,   R22,   R32,   R42,    }, \
		{ R01,   R11,   R21,   R31,   R41,    }, \
		{ R00,   R10,   R20,   R30,   R40     }, \
		{ L05,   L15,   L25,   L35,   L45,    }, \
		{ L04,   L14,   L24,   L34,   L44,    }, \
		{ L03,   L13,   L23,   L33,   L43,    }, \
		{ L02,   L12,   L22,   L32,   KC_NO,  }, \
		{ L01,   L11,   L21,   L31,   KC_NO,  }, \
		{ L00,   L10,   L20,   L30,   KC_NO,  }, \
    }

#endif
