/*****************************************************************************
 *	Copyright(c) 2017 FCI Inc. All Rights Reserved
 *
 *	File name : fc8350_tun_table.c
 *
 *	Description : API source of ISDB-T baseband module
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public License for more details.
 *
 *	History :
 *	----------------------------------------------------------------------
 *******************************************************************************/
#include "fci_types.h"

u32 ch_mode_saw[121][11] = {
	{0x00, 0x11, 0x12, 0x11d, 0x11f, 0x11e, 0x120, 0x121, 0x123, 0x122,
		0x124},
	{90000, 0x04, 0xc0, 0x7f, 0x7f, 0x81, 0x81, 0x91, 0x91, 0x75, 0x75},
	{96000, 0x04, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x91, 0x91, 0x75, 0x75},
	{102000, 0x04, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x91, 0x91, 0x75, 0x75},
	{108000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x91, 0x91, 0x75, 0x75},
	{114000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x91, 0x91, 0x76, 0x76},
	{120000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x90, 0x90, 0x76, 0x76},
	{126000, 0x04, 0xc0, 0x82, 0x82, 0x80, 0x80, 0x8f, 0x8f, 0x77, 0x77},
	{132000, 0x04, 0xc0, 0x81, 0x81, 0x81, 0x81, 0x8f, 0x8f, 0x77, 0x77},
	{138000, 0x04, 0xc0, 0x82, 0x82, 0x81, 0x81, 0x90, 0x90, 0x76, 0x76},
	{144000, 0x04, 0xc0, 0x82, 0x82, 0x81, 0x81, 0x8f, 0x8f, 0x78, 0x78},
	{150000, 0x04, 0xc0, 0x83, 0x83, 0x83, 0x83, 0x8f, 0x8f, 0x77, 0x77},
	{156000, 0x04, 0xc0, 0x82, 0x82, 0x83, 0x83, 0x90, 0x90, 0x77, 0x77},
	{164000, 0x04, 0xc0, 0x84, 0x84, 0x83, 0x83, 0x90, 0x90, 0x76, 0x76},
	{170000, 0x04, 0xc0, 0x83, 0x83, 0x83, 0x83, 0x90, 0x90, 0x77, 0x77},
	{176000, 0x04, 0xc0, 0x83, 0x83, 0x83, 0x83, 0x91, 0x91, 0x77, 0x77},
	{182000, 0x04, 0xc0, 0x83, 0x83, 0x84, 0x84, 0x91, 0x91, 0x77, 0x77},
	{188000, 0x04, 0xc0, 0x84, 0x84, 0x84, 0x84, 0x92, 0x92, 0x77, 0x77},
	{192000, 0x04, 0xc0, 0x84, 0x84, 0x84, 0x84, 0x92, 0x92, 0x77, 0x77},
	{198000, 0x04, 0xc0, 0x7d, 0x7d, 0x81, 0x81, 0x90, 0x90, 0x72, 0x72},
	{204000, 0x04, 0xc0, 0x7d, 0x7d, 0x81, 0x81, 0x91, 0x91, 0x72, 0x72},
	{210000, 0x04, 0xc0, 0x7d, 0x7d, 0x81, 0x81, 0x92, 0x92, 0x73, 0x73},
	{216000, 0x04, 0xc0, 0x7d, 0x7d, 0x82, 0x82, 0x92, 0x92, 0x72, 0x72},
	{222000, 0x04, 0xc0, 0x7e, 0x7e, 0x82, 0x82, 0x92, 0x92, 0x72, 0x72},
	{228000, 0x04, 0x00, 0x7f, 0x7f, 0x81, 0x81, 0x94, 0x94, 0x72, 0x72},
	{234000, 0x04, 0x00, 0x7d, 0x7d, 0x7f, 0x7f, 0x95, 0x95, 0x71, 0x71},
	{240000, 0x04, 0x00, 0x9d, 0x9d, 0xac, 0xac, 0x8f, 0x8f, 0x76, 0x76},
	{246000, 0x04, 0x00, 0x77, 0x77, 0x89, 0x89, 0x87, 0x87, 0x7b, 0x7b},
	{252000, 0x04, 0x00, 0x80, 0x80, 0x80, 0x80, 0x92, 0x92, 0x74, 0x74},
	{258000, 0x04, 0x00, 0x7f, 0x7f, 0x81, 0x81, 0x95, 0x95, 0x72, 0x72},
	{264000, 0x04, 0x00, 0x7f, 0x7f, 0x7e, 0x7e, 0x97, 0x97, 0x71, 0x71},
	{270000, 0x04, 0x00, 0x82, 0x82, 0x71, 0x71, 0x9e, 0x9e, 0x64, 0x64},
	{276000, 0x04, 0x00, 0xac, 0xac, 0x91, 0x91, 0xad, 0xad, 0x95, 0x95},
	{282000, 0x04, 0x00, 0x7e, 0x7e, 0x82, 0x82, 0x8f, 0x8f, 0x73, 0x73},
	{288000, 0x04, 0x00, 0x80, 0x80, 0x82, 0x82, 0x92, 0x92, 0x75, 0x75},
	{294000, 0x04, 0x00, 0x81, 0x81, 0x80, 0x80, 0x94, 0x94, 0x74, 0x74},
	{300000, 0x04, 0x00, 0x84, 0x84, 0x80, 0x80, 0x95, 0x95, 0x73, 0x73},
	{306000, 0x04, 0x00, 0x80, 0x80, 0x7e, 0x7e, 0x97, 0x97, 0x73, 0x73},
	{312000, 0x04, 0x00, 0x82, 0x82, 0x7e, 0x7e, 0x98, 0x98, 0x71, 0x71},
	{318000, 0x04, 0x00, 0x82, 0x82, 0x7a, 0x7a, 0x99, 0x99, 0x72, 0x72},
	{324000, 0x04, 0x00, 0x83, 0x83, 0x7a, 0x7a, 0x97, 0x97, 0x72, 0x72},
	{330000, 0x04, 0x00, 0x86, 0x86, 0x78, 0x78, 0x9a, 0x9a, 0x71, 0x71},
	{336000, 0x04, 0x00, 0x82, 0x82, 0x73, 0x73, 0x9a, 0x9a, 0x6a, 0x6a},
	{342000, 0x04, 0x00, 0x85, 0x85, 0x79, 0x79, 0x95, 0x95, 0x70, 0x70},
	{348000, 0x04, 0x00, 0x84, 0x84, 0x6f, 0x6f, 0x98, 0x98, 0x65, 0x65},
	{354000, 0x04, 0x00, 0x8e, 0x8e, 0x79, 0x79, 0x8b, 0x8b, 0x63, 0x63},
	{360000, 0x04, 0x00, 0x8c, 0x8c, 0x8a, 0x8a, 0x9e, 0x9e, 0x68, 0x68},
	{366000, 0x04, 0x00, 0x83, 0x83, 0x77, 0x77, 0x9a, 0x9a, 0x6e, 0x6e},
	{372000, 0x04, 0x00, 0x8b, 0x8b, 0x7f, 0x7f, 0xa4, 0xa4, 0x87, 0x87},
	{378000, 0x04, 0x00, 0x8f, 0x8f, 0x76, 0x76, 0x79, 0x79, 0x84, 0x84},
	{384000, 0x04, 0x00, 0x5a, 0x5a, 0x76, 0x76, 0x8d, 0x8d, 0x85, 0x85},
	{390000, 0x04, 0x00, 0x94, 0x94, 0xac, 0xac, 0x58, 0x58, 0x8b, 0x8b},
	{396000, 0x02, 0x00, 0x9b, 0x9b, 0x9a, 0x9a, 0x82, 0x82, 0x99, 0x99},
	{402000, 0x02, 0x00, 0xa6, 0xa6, 0x7e, 0x7e, 0x8b, 0x8b, 0x67, 0x67},
	{408000, 0x02, 0x00, 0x84, 0x84, 0x8c, 0x8c, 0x8d, 0x8d, 0xad, 0xad},
	{414000, 0x02, 0x00, 0x8c, 0x8c, 0x66, 0x66, 0x88, 0x88, 0x96, 0x96},
	{420000, 0x02, 0x00, 0x88, 0x88, 0x83, 0x83, 0x67, 0x67, 0x97, 0x97},
	{426000, 0x02, 0x00, 0x6b, 0x6b, 0x81, 0x81, 0x5f, 0x5f, 0x9b, 0x9b},
	{432000, 0x02, 0x00, 0x6d, 0x6d, 0x74, 0x74, 0x63, 0x63, 0x99, 0x99},
	{438000, 0x02, 0x00, 0x8a, 0x8a, 0x89, 0x89, 0x83, 0x83, 0x73, 0x73},
	{444000, 0x02, 0x00, 0x98, 0x98, 0x7a, 0x7a, 0xa5, 0xa5, 0x9b, 0x9b},
	{450000, 0x02, 0x00, 0x74, 0x74, 0x93, 0x93, 0x84, 0x84, 0x87, 0x87},
	{456000, 0x02, 0x00, 0x94, 0x94, 0xa4, 0xa4, 0x6f, 0x6f, 0x7f, 0x7f},
	{462000, 0x02, 0x00, 0xac, 0xac, 0x64, 0x64, 0x88, 0x88, 0x60, 0x60},
	{470000, 0x02, 0x00, 0x63, 0x63, 0x7c, 0x7c, 0x76, 0x76, 0x86, 0x86},
	{476000, 0x02, 0x00, 0x8f, 0x8f, 0x81, 0x81, 0x5a, 0x5a, 0x5a, 0x5a},
	{482000, 0x02, 0x00, 0x8c, 0x8c, 0x80, 0x80, 0x5b, 0x5b, 0x5b, 0x5b},
	{488000, 0x02, 0x00, 0x92, 0x92, 0x80, 0x80, 0x85, 0x85, 0x6a, 0x6a},
	{494000, 0x02, 0x00, 0xa0, 0xa0, 0xa0, 0xa0, 0x50, 0x50, 0x60, 0x60},
	{500000, 0x02, 0x00, 0x61, 0x61, 0x92, 0x92, 0x77, 0x77, 0x6b, 0x6b},
	{506000, 0x02, 0x00, 0x97, 0x97, 0x77, 0x77, 0x69, 0x69, 0x68, 0x68},
	{512000, 0x02, 0x00, 0x6a, 0x6a, 0x74, 0x74, 0x9d, 0x9d, 0x65, 0x65},
	{518000, 0x02, 0x00, 0x5e, 0x5e, 0x76, 0x76, 0x81, 0x81, 0x5c, 0x5c},
	{524000, 0x02, 0x00, 0x58, 0x58, 0x9c, 0x9c, 0x89, 0x89, 0x65, 0x65},
	{530000, 0x02, 0x00, 0x79, 0x79, 0x8f, 0x8f, 0x62, 0x62, 0x8c, 0x8c},
	{536000, 0x02, 0x00, 0x77, 0x77, 0x82, 0x82, 0x9a, 0x9a, 0x8f, 0x8f},
	{542000, 0x02, 0x00, 0x70, 0x70, 0x50, 0x50, 0x0f, 0x0f, 0x8b, 0x8b},
	{548000, 0x02, 0x00, 0x8c, 0x8c, 0x72, 0x72, 0x84, 0x84, 0xaa, 0xaa},
	{554000, 0x02, 0x00, 0xb2, 0xb2, 0x15, 0x15, 0x55, 0x55, 0x50, 0x50},
	{560000, 0x02, 0x00, 0x88, 0x88, 0x92, 0x92, 0x68, 0x68, 0x69, 0x69},
	{566000, 0x02, 0x00, 0x66, 0x66, 0x63, 0x63, 0x8e, 0x8e, 0x72, 0x72},
	{572000, 0x02, 0x00, 0x75, 0x75, 0x8b, 0x8b, 0xab, 0xab, 0x74, 0x74},
	{578000, 0x01, 0x00, 0x6e, 0x6e, 0x6c, 0x6c, 0x6c, 0x6c, 0x9a, 0x9a},
	{584000, 0x01, 0x00, 0x92, 0x92, 0x82, 0x82, 0x8c, 0x8c, 0x57, 0x57},
	{590000, 0x01, 0x00, 0x91, 0x91, 0x93, 0x93, 0x5c, 0x5c, 0x9d, 0x9d},
	{596000, 0x01, 0x00, 0x87, 0x87, 0x9b, 0x9b, 0x98, 0x98, 0x98, 0x98},
	{602000, 0x01, 0x00, 0x85, 0x85, 0x50, 0x50, 0x20, 0x20, 0x50, 0x50},
	{608000, 0x01, 0x00, 0x94, 0x94, 0x76, 0x76, 0x5a, 0x5a, 0x75, 0x75},
	{614000, 0x01, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7a, 0x7a, 0x9f, 0x9f},
	{620000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{626000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{632000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{638000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{644000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{650000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{656000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{662000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{668000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{674000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{680000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{686000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{692000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{698000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{704000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{710000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{716000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{722000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{728000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{734000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{740000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{746000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{752000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{758000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{764000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{770000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60}
};

u32 ch_mode_nosaw[121][11] = {
	{0x00, 0x11, 0x12, 0x11d, 0x11f, 0x11e, 0x120, 0x121, 0x123, 0x122,
		0x124},
	{90000, 0x04, 0xc0, 0x7d, 0x7d, 0x7d, 0x7d, 0x8f, 0x8f, 0x76, 0x76},
	{96000, 0x04, 0xc0, 0x7d, 0x7d, 0x7e, 0x7e, 0x8e, 0x8e, 0x76, 0x76},
	{102000, 0x04, 0xc0, 0x7d, 0x7d, 0x7d, 0x7d, 0x8f, 0x8f, 0x76, 0x76},
	{108000, 0x04, 0xc0, 0x7d, 0x7d, 0x7d, 0x7d, 0x8f, 0x8f, 0x76, 0x76},
	{114000, 0x04, 0xc0, 0x7e, 0x7e, 0x7e, 0x7e, 0x8f, 0x8f, 0x76, 0x76},
	{120000, 0x04, 0xc0, 0x7e, 0x7e, 0x7e, 0x7e, 0x8f, 0x8f, 0x76, 0x76},
	{126000, 0x04, 0xc0, 0x7f, 0x7f, 0x7f, 0x7f, 0x8f, 0x8f, 0x76, 0x76},
	{132000, 0x04, 0xc0, 0x7f, 0x7f, 0x7f, 0x7f, 0x8f, 0x8f, 0x76, 0x76},
	{138000, 0x04, 0xc0, 0x7f, 0x7f, 0x7f, 0x7f, 0x8f, 0x8f, 0x76, 0x76},
	{144000, 0x04, 0xc0, 0x7f, 0x7f, 0x7e, 0x7e, 0x90, 0x90, 0x76, 0x76},
	{150000, 0x04, 0xc0, 0x80, 0x80, 0x7f, 0x7f, 0x90, 0x90, 0x75, 0x75},
	{156000, 0x04, 0xc0, 0x80, 0x80, 0x7f, 0x7f, 0x90, 0x90, 0x75, 0x75},
	{164000, 0x04, 0xc0, 0x80, 0x80, 0x7e, 0x7e, 0x90, 0x90, 0x75, 0x75},
	{170000, 0x04, 0xc0, 0x80, 0x80, 0x7e, 0x7e, 0x90, 0x90, 0x75, 0x75},
	{176000, 0x04, 0xc0, 0x80, 0x80, 0x7e, 0x7e, 0x90, 0x90, 0x75, 0x75},
	{182000, 0x04, 0xc0, 0x81, 0x81, 0x7e, 0x7e, 0x91, 0x91, 0x75, 0x75},
	{188000, 0x04, 0xc0, 0x82, 0x82, 0x7e, 0x7e, 0x91, 0x91, 0x75, 0x75},
	{192000, 0x04, 0xc0, 0x82, 0x82, 0x7f, 0x7f, 0x91, 0x91, 0x75, 0x75},
	{198000, 0x04, 0xc0, 0x7d, 0x7d, 0x7c, 0x7c, 0x91, 0x91, 0x72, 0x72},
	{204000, 0x04, 0xc0, 0x7d, 0x7d, 0x7c, 0x7c, 0x91, 0x91, 0x72, 0x72},
	{210000, 0x04, 0xc0, 0x7e, 0x7e, 0x7c, 0x7c, 0x91, 0x91, 0x72, 0x72},
	{216000, 0x04, 0xc0, 0x7e, 0x7e, 0x7c, 0x7c, 0x91, 0x91, 0x72, 0x72},
	{222000, 0x04, 0xc0, 0x7e, 0x7e, 0x7c, 0x7c, 0x92, 0x92, 0x72, 0x72},
	{228000, 0x04, 0x00, 0x7e, 0x7e, 0x7d, 0x7d, 0x92, 0x92, 0x72, 0x72},
	{234000, 0x04, 0x00, 0x7f, 0x7f, 0x7d, 0x7d, 0x92, 0x92, 0x71, 0x71},
	{240000, 0x04, 0x00, 0x7f, 0x7f, 0x7d, 0x7d, 0x92, 0x92, 0x71, 0x71},
	{246000, 0x04, 0x00, 0x7f, 0x7f, 0x7d, 0x7d, 0x92, 0x92, 0x71, 0x71},
	{252000, 0x04, 0x00, 0x80, 0x80, 0x7d, 0x7d, 0x92, 0x92, 0x71, 0x71},
	{258000, 0x04, 0x00, 0x80, 0x80, 0x7c, 0x7c, 0x92, 0x92, 0x71, 0x71},
	{264000, 0x04, 0x00, 0x80, 0x80, 0x7c, 0x7c, 0x93, 0x93, 0x71, 0x71},
	{270000, 0x04, 0x00, 0x80, 0x80, 0x7d, 0x7d, 0x93, 0x93, 0x70, 0x70},
	{276000, 0x04, 0x00, 0x81, 0x81, 0x7d, 0x7d, 0x93, 0x93, 0x71, 0x71},
	{282000, 0x04, 0x00, 0x81, 0x81, 0x7d, 0x7d, 0x93, 0x93, 0x70, 0x70},
	{288000, 0x04, 0x00, 0x81, 0x81, 0x7d, 0x7d, 0x93, 0x93, 0x70, 0x70},
	{294000, 0x04, 0x00, 0x82, 0x82, 0x7d, 0x7d, 0x93, 0x93, 0x70, 0x70},
	{300000, 0x04, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x94, 0x94, 0x70, 0x70},
	{306000, 0x04, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x94, 0x94, 0x70, 0x70},
	{312000, 0x04, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x94, 0x94, 0x6f, 0x6f},
	{318000, 0x04, 0x00, 0x84, 0x84, 0x7d, 0x7d, 0x94, 0x94, 0x6f, 0x6f},
	{324000, 0x04, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x94, 0x94, 0x6f, 0x6f},
	{330000, 0x04, 0x00, 0x84, 0x84, 0x7e, 0x7e, 0x94, 0x94, 0x6e, 0x6e},
	{336000, 0x04, 0x00, 0x84, 0x84, 0x7e, 0x7e, 0x94, 0x94, 0x6e, 0x6e},
	{342000, 0x04, 0x00, 0x84, 0x84, 0x7d, 0x7d, 0x94, 0x94, 0x6e, 0x6e},
	{348000, 0x04, 0x00, 0x84, 0x84, 0x7e, 0x7e, 0x94, 0x94, 0x6d, 0x6d},
	{354000, 0x04, 0x00, 0x85, 0x85, 0x7e, 0x7e, 0x95, 0x95, 0x6e, 0x6e},
	{360000, 0x04, 0x00, 0x85, 0x85, 0x7e, 0x7e, 0x94, 0x94, 0x6d, 0x6d},
	{366000, 0x04, 0x00, 0x86, 0x86, 0x7e, 0x7e, 0x96, 0x96, 0x6c, 0x6c},
	{372000, 0x04, 0x00, 0x80, 0x80, 0x7c, 0x7c, 0x91, 0x91, 0x6c, 0x6c},
	{378000, 0x04, 0x00, 0x82, 0x82, 0x7d, 0x7d, 0x91, 0x91, 0x6c, 0x6c},
	{384000, 0x04, 0x00, 0x80, 0x80, 0x7d, 0x7d, 0x90, 0x90, 0x6a, 0x6a},
	{390000, 0x04, 0x00, 0x80, 0x80, 0x7d, 0x7d, 0x91, 0x91, 0x6b, 0x6b},
	{396000, 0x02, 0x00, 0x82, 0x82, 0x7d, 0x7d, 0x90, 0x90, 0x6a, 0x6a},
	{402000, 0x02, 0x00, 0x81, 0x81, 0x7e, 0x7e, 0x91, 0x91, 0x6a, 0x6a},
	{408000, 0x02, 0x00, 0x81, 0x81, 0x7d, 0x7d, 0x91, 0x91, 0x69, 0x69},
	{414000, 0x02, 0x00, 0x82, 0x82, 0x7d, 0x7d, 0x91, 0x91, 0x69, 0x69},
	{420000, 0x02, 0x00, 0x82, 0x82, 0x7e, 0x7e, 0x92, 0x92, 0x68, 0x68},
	{426000, 0x02, 0x00, 0x82, 0x82, 0x7d, 0x7d, 0x92, 0x92, 0x68, 0x68},
	{432000, 0x02, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x93, 0x93, 0x68, 0x68},
	{438000, 0x02, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x93, 0x93, 0x69, 0x69},
	{444000, 0x02, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x93, 0x93, 0x69, 0x69},
	{450000, 0x02, 0x00, 0x83, 0x83, 0x7d, 0x7d, 0x93, 0x93, 0x69, 0x69},
	{456000, 0x02, 0x00, 0x84, 0x84, 0x7d, 0x7d, 0x93, 0x93, 0x68, 0x68},
	{462000, 0x02, 0x00, 0x85, 0x85, 0x7e, 0x7e, 0x93, 0x93, 0x68, 0x68},
	{470000, 0x02, 0x00, 0x8a, 0x8a, 0x81, 0x81, 0x98, 0x98, 0x6a, 0x6a},
	{476000, 0x02, 0x00, 0x8f, 0x8f, 0x81, 0x81, 0x90, 0x90, 0x65, 0x65},
	{482000, 0x02, 0x00, 0x8a, 0x8a, 0x80, 0x80, 0x98, 0x98, 0x6a, 0x6a},
	{488000, 0x02, 0x00, 0x97, 0x97, 0x80, 0x80, 0x90, 0x90, 0x6d, 0x6d},
	{494000, 0x02, 0x00, 0xa0, 0xa0, 0xa0, 0xa0, 0x50, 0x50, 0x60, 0x60},
	{500000, 0x02, 0x00, 0x8a, 0x8a, 0x81, 0x81, 0x97, 0x97, 0x68, 0x68},
	{506000, 0x02, 0x00, 0x8b, 0x8b, 0x81, 0x81, 0x96, 0x96, 0x69, 0x69},
	{512000, 0x02, 0x00, 0x8b, 0x8b, 0x81, 0x81, 0x97, 0x97, 0x67, 0x67},
	{518000, 0x02, 0x00, 0x8a, 0x8a, 0x7f, 0x7f, 0x97, 0x97, 0x68, 0x68},
	{524000, 0x02, 0x00, 0x8b, 0x8b, 0x81, 0x81, 0x98, 0x98, 0x68, 0x68},
	{530000, 0x02, 0x00, 0x8b, 0x8b, 0x81, 0x81, 0x98, 0x98, 0x67, 0x67},
	{536000, 0x02, 0x00, 0x8a, 0x8a, 0x81, 0x81, 0x96, 0x96, 0x68, 0x68},
	{542000, 0x02, 0x00, 0x8e, 0x8e, 0x8a, 0x8a, 0x9a, 0x9a, 0x67, 0x67},
	{548000, 0x02, 0x00, 0x8a, 0x8a, 0x82, 0x82, 0x97, 0x97, 0x67, 0x67},
	{554000, 0x02, 0x00, 0x89, 0x86, 0x7a, 0x80, 0x8e, 0x8b, 0x6f, 0x71},
	{560000, 0x02, 0x00, 0x8d, 0x8d, 0x81, 0x81, 0x99, 0x99, 0x65, 0x65},
	{566000, 0x02, 0x00, 0x8b, 0x8b, 0x82, 0x82, 0x97, 0x97, 0x67, 0x67},
	{572000, 0x02, 0x00, 0x8b, 0x8b, 0x83, 0x83, 0x99, 0x99, 0x64, 0x64},
	{578000, 0x01, 0x00, 0x8c, 0x8c, 0x83, 0x83, 0x97, 0x97, 0x64, 0x64},
	{584000, 0x01, 0x00, 0x8f, 0x8f, 0x81, 0x81, 0x99, 0x99, 0x67, 0x67},
	{590000, 0x01, 0x00, 0x8c, 0x8c, 0x84, 0x84, 0x97, 0x97, 0x63, 0x63},
	{596000, 0x01, 0x00, 0x8d, 0x8d, 0x83, 0x83, 0x98, 0x98, 0x66, 0x66},
	{602000, 0x01, 0x00, 0x86, 0x86, 0x7b, 0x7d, 0x8d, 0x81, 0x70, 0x68},
	{608000, 0x01, 0x00, 0x8b, 0x8b, 0x88, 0x88, 0x99, 0x99, 0x65, 0x65},
	{614000, 0x01, 0x00, 0x8a, 0x8a, 0x85, 0x85, 0x97, 0x97, 0x66, 0x66},
	{620000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{626000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{632000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{638000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{644000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{650000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{656000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{662000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{668000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{674000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{680000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{686000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{692000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{698000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{704000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{710000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{716000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{722000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{728000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{734000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{740000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{746000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{752000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{758000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{764000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{770000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60}
};

