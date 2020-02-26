#ifndef __CSI_COLOR_H__
#define __CSI_COLOR_H__

#define CSI "\033["
/*Color*/
#define UL CSI "4m"
#define NONE CSI "m"
#define NONE_NL NONE "\n"
#define FC(f) CSI f "m"
#define FBC(f, b) CSI f ";" b "m"
#define FBIT8(f) CSI "38;5;" f "m"
#define FBBIT8(f, b) CSI "38;5;" f "m"\
                   CSI "48;5;" b "m"
/*Console*/
#define CLS CSI "2J" CSI "H"
#define SAVE CSI "s"
#define RESTORE CSI "u"
#define CURON CSI "?25h"
#define CUROFF CSI "?25l"
#define SU CSI "S"
#define SD CSI "T"
#define CUU CSI "1A"
#define CUD CSI "1B"
#define CUF CSI "1C"
#define CUB CSI "1D"

int is_allocated;
char *pub_s0;
char *pub_s1;

void init_pubs();

/* 3/4 bits.
**
** 30~37 and 90~97 for foreground,       
** 40~47 and 100~107 for background.
**
** All functions are named by "xxx_color". 
*/
char *f_color(int f);
/* 3/4 bits.
**
** 30~37 and 90~97 for foreground,       
** 40~47 and 100~107 for background.
**
** All functions are named by "xxx_color". 
*/
char *fb_color(int f, int b);

/* 8 bits.
**
** 0~255 for all colors.
**
** All functions are named by "xxx_bit8". 
*/
char *f_bit8(int f);
/* 8 bits.
**
** 0~255 for all colors.
**
** All functions are named by "xxx_bit8". 
*/
char *fb_bit8(int f, int b);

/* memory free
**
** Before program exit, it must call this function to free the
** memory we used.
**
** It is named by "csi_free_all". 
*/
void csi_free_all();

#endif