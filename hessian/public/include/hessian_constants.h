/*
 * hessian_constants.h
 *
 *  Created on: Jul 31, 2011
 *      Author: alexander
 */

#ifndef HESSIAN_CONSTANTS_H_
#define HESSIAN_CONSTANTS_H_

static int INT_DIRECT_MIN = -0x10;
static int INT_DIRECT_MAX = 0x2f;
static int INT_ZERO = 0x90;

static int INT_BYTE_MIN = -0x800;
static int INT_BYTE_MAX = 0x7ff;
static int INT_BYTE_ZERO = 0xc8;

static int INT_SHORT_MIN = -0x40000;
static int INT_SHORT_MAX = 0x3ffff;
static int INT_SHORT_ZERO = 0xd4;

static long LONG_DIRECT_MIN = -0x08;
static long LONG_DIRECT_MAX =  0x0f;
static int LONG_ZERO = 0xe0;

static long LONG_BYTE_MIN = -0x800;
static long LONG_BYTE_MAX =  0x7ff;
static int LONG_BYTE_ZERO = 0xf8;

static int LONG_SHORT_MIN = -0x40000;
static int LONG_SHORT_MAX = 0x3ffff;
static int LONG_SHORT_ZERO = 0x3c;

static int STRING_DIRECT_MAX = 0x1f;
static int STRING_DIRECT = 0x00;

static int BYTES_DIRECT_MAX = 0x0f;
static int BYTES_DIRECT = 0x20;
  // 0x30-0x37 is reserved

static int LONG_INT = 0x77;

static int DOUBLE_ZERO = 0x67;
static int DOUBLE_ONE = 0x68;
static int DOUBLE_BYTE = 0x69;
static int DOUBLE_SHORT = 0x6a;
static int DOUBLE_FLOAT = 0x6b;

static int BC_END = 'Z';

static int BC_LIST_VARIABLE = 0x55;
static int BC_LIST_FIXED = 'V';
static int BC_LIST_VARIABLE_UNTYPED = 0x57;
static int BC_LIST_FIXED_UNTYPED = 0x58;

static int BC_LIST_DIRECT = 0x70;
static int BC_LIST_DIRECT_UNTYPED = 0x78;
static int LIST_DIRECT_MAX = 0x7;

static int REF_BYTE = 0x4a;
static int REF_SHORT = 0x4b;

static int TYPE_REF = 0x75;

#endif /* HESSIAN_CONSTANTS_H_ */
