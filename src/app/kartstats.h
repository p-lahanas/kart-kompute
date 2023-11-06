#ifndef KARTSTATS_H
#define KARTSTATS_H

void kartstats_init(void);
void kartstats_close(void);
void kartstats_update(void);

unsigned long kartstats_get_axle_rpm(void);
unsigned long kartstats_get_engine_rpm(void);
unsigned int kartstats_get_speed(void);

#endif