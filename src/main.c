/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "S32K144.h"
#include "registers.h"


#if defined (__ghs__)
    #define __INTERRUPT_SVC  __interrupt
    #define __NO_RETURN _Pragma("ghs nowarning 111")
#elif defined (__ICCARM__)
    #define __INTERRUPT_SVC  __svc
    #define __NO_RETURN _Pragma("diag_suppress=Pe111")
#elif defined (__GNUC__)
    #define __INTERRUPT_SVC  __attribute__ ((interrupt ("SVC")))
    #define __NO_RETURN
#else
    #define __INTERRUPT_SVC
    #define __NO_RETURN
#endif

int counter, accumulator = 0, limit_value = 1000000;
void disable_wdog(void) {
    /* Unlock watchdog */
    WDOG_CNT = 0xD928C520u;
    /* ghi cau hinh tat Watchdog (Clear bit EN) */
    WDOG_CS = 0x00002100u;
    /* dat gia tri Timeout toi da */
    WDOG_TOVAL = 0x0000FFFFu;
}
/* (Software Delay) */
/* O chuong 8, ta se thay ham nay bang Timer de co do chinh xac tuyet doi */
void delay_ms(unsigned int ms) {
    for (volatile unsigned int i = 0; i < ms * 4000; i++) {
        __asm("nop"); /* No-Operation: giup vong lap khong bi compiler toi uu hoa xoa mat*/
    }
}

int main(void) {
	disable_wdog();
	/* 1. CAP NGUON XUNG NHIP (CLOCK GATE) */
	/* Set bit 30 de cap clock cho PORTD */
	PCC_PORTD |= (1 << 30);

	/* 2. DINH TUYEN CHUC NANG CHAN (MULTIPLEXING) */
	/* Xoa cac bit cau hinh cu (8, 9, 10) va set bit 8 de mode GPIO cho PTD0 */
	PORTD_PCR0 &= ~((1 << 8) | (1 << 9) | (1 << 10));
	PORTD_PCR0 |= (1 << 8);

	/* 3. CAU HINH NGO RA (OUTPUT) */
	/* Dat bit 0 cua thanh ghi PDDR len 1 (Output) */
	PTD_PDDR |= (1 << 0);

	/* 4. VONG LAP HOAT DONG CHINH (SUPER-LOOP) */
	while (1) {
		/* Dao trang thai den LED (Toggle) */
		PTD_PTOR |= (1 << 0);

		/* Tre 333ms de dat chuan 90nhip/phut cua xi-nhan */
		delay_ms(333);
	}
    /* to avoid the warning message for GHS and IAR: statement is unreachable*/
    __NO_RETURN
    return 0;
}

__INTERRUPT_SVC void SVC_Handler() {
    accumulator += counter;
}
