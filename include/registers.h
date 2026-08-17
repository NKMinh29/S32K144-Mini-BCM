/*
 * registers.h
 *
 *  Created on: Aug 17, 2026
 *      Author: Admin
 */

#ifndef REGISTERS_H
#define REGISTERS_H

/* --- WATCHDOG TIMER --- */
#define WDOG_CS_ADDR     0x40052000u
#define WDOG_CS          (*((volatile unsigned int*)WDOG_CS_ADDR))
#define WDOG_CNT_ADDR    0x40052004u
#define WDOG_CNT         (*((volatile unsigned int*)WDOG_CNT_ADDR))
#define WDOG_TOVAL_ADDR  0x40052008u
#define WDOG_TOVAL       (*((volatile unsigned int*)WDOG_TOVAL_ADDR))

/* --- KHOI DIEU KHIEN LED (PTD0) --- */
#define PCC_PORTD_ADDR   0x40065130u
#define PCC_PORTD        (*((volatile unsigned int*)PCC_PORTD_ADDR))

#define PORTD_PCR0_ADDR  0x4004C000u
#define PORTD_PCR0       (*((volatile unsigned int*)PORTD_PCR0_ADDR))

#define PTD_PDDR_ADDR    0x400FF0D4u
#define PTD_PDDR         (*((volatile unsigned int*)PTD_PDDR_ADDR))

#define PTD_PTOR_ADDR    0x400FF0CCu
#define PTD_PTOR         (*((volatile unsigned int*)PTD_PTOR_ADDR))

#endif /* REGISTERS_H */
