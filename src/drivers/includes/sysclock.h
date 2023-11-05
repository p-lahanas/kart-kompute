#ifndef SYSCLOCK_H
#define SYSCLOCK_H


void sys_time_init(void);
unsigned long sys_time_elapsed(void);
unsigned long sys_time_err(void);

#endif