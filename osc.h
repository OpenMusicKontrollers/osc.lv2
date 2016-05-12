/*
 * Copyright (c) 2015-2016 Hanspeter Portner (dev@open-music-kontrollers.ch)
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the Artistic License 2.0 as published by
 * The Perl Foundation.
 *
 * This source is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Artistic License 2.0 for more details.
 *
 * You should have received a copy of the Artistic License 2.0
 * along the source as a COPYING file. If not, obtain it from
 * http://www.perlfoundation.org/artistic_license_2_0.
 */

#ifndef LV2_OSC_H
#define LV2_OSC_H

#include <stdint.h>

#define LV2_OSC_URI               "http://open-music-kontrollers.ch/lv2/osc"
#define LV2_OSC_PREFIX            LV2_OSC_URI "#"	

#define LV2_OSC__Event            LV2_OSC_PREFIX "Event" // atom type 
#define LV2_OSC__schedule         LV2_OSC_PREFIX "schedule" // feature

#define LV2_OSC_PADDED_SIZE(size) ( ( (size_t)(size) + 3 ) & ( ~3 ) )
#define LV2_OSC_IMMEDIATE         1ULL

#ifdef __cplusplus
extern "C" {
#endif

typedef void *LV2_OSC_Schedule_Handle;

typedef double (*LV2_OSC_Schedule_OSC2Frames)(
	LV2_OSC_Schedule_Handle handle,
	uint64_t timestamp);

typedef uint64_t (*LV2_OSC_Schedule_Frames2OSC)(
	LV2_OSC_Schedule_Handle handle,
	double frames);

typedef struct _LV2_OSC_Schedule {
	LV2_OSC_Schedule_Handle handle;
	LV2_OSC_Schedule_OSC2Frames osc2frames;
	LV2_OSC_Schedule_Frames2OSC frames2osc;
} LV2_OSC_Schedule;

typedef enum LV2_OSC_Type {
	LV2_OSC_INT32   =	'i',
	LV2_OSC_FLOAT   =	'f',
	LV2_OSC_STRING  =	's',
	LV2_OSC_BLOB    =	'b',
	
	LV2_OSC_TRUE    =	'T',
	LV2_OSC_FALSE   =	'F',
	LV2_OSC_NIL     =	'N',
	LV2_OSC_IMPULSE =	'I',
	
	LV2_OSC_INT64   =	'h',
	LV2_OSC_DOUBLE  =	'd',
	LV2_OSC_TIMETAG =	't',
	
	LV2_OSC_SYMBOL  =	'S',
	LV2_OSC_CHAR    =	'c',
	LV2_OSC_MIDI    =	'm',
	LV2_OSC_RGBA    =	'r'
} LV2_OSC_Type;

union swap32_t {
	uint32_t u;

	int32_t i;
	float f;
};

union swap64_t {
	uint64_t u;

	int64_t h;
	uint64_t t;
	double d;
};

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LV2_OSC_H