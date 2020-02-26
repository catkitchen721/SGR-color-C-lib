#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "csi_color.h"

int is_allocated = 0;

void init_pubs()
{
    if(!is_allocated)
    {
        pub_s0 = (char *)malloc(16 * sizeof(char));
        pub_s1 = (char *)malloc(32 * sizeof(char));
        is_allocated = 1;
    }
}

char *f_color(int f)
{
    if(f < 30 || f > 107 ||
      f == 38 || f == 48 || 
      f == 98 || f == 99 ||
      (f > 49 && f < 90))
    {
        return "";
    }
    init_pubs();
    sprintf(pub_s0, CSI "%dm", f);
    return pub_s0;
}

char *fb_color(int f, int b)
{
    if(f < 30 || f > 107 ||
      f == 38 || f == 48 || 
      f == 98 || f == 99 ||
      (f > 49 && f < 90))
    {
        return "";
    }
    if(b < 30 || b > 107 ||
      b == 38 || b == 48 || 
      b == 98 || b == 99 ||
      (b > 49 && b < 90))
    {
        return "";
    }
    init_pubs();
    sprintf(pub_s0, CSI "%d;%dm", f, b);
    return pub_s0;
}

char *f_bit8(int f)
{
    if(f < 0 || f > 255)
    {
        return "";
    }
    init_pubs();
    sprintf(pub_s0, CSI "38;5;%dm", f);
    return pub_s0;
}

char *fb_bit8(int f, int b)
{
    if(f < 0 || f > 255)
    {
        return "";
    }
    if(b < 0 || b > 255)
    {
        return "";
    }
    init_pubs();
    sprintf(pub_s1, CSI "38;5;%dm" CSI "48;5;%dm", f, b);
    return pub_s1;
}

void csi_free_all()
{
    if(!is_allocated) return;
    free(pub_s0);
    free(pub_s1);
}