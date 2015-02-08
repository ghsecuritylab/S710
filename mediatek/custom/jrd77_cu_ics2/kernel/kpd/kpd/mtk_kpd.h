
#ifndef _MTK_KPD_H_
#define _MTK_KPD_H_

#include <linux/kernel.h>
#include <linux/delay.h>
#include <cust_kpd.h>
/* include PMIC header file */
#include <mach/mt6577_typedefs.h>
#include <mach/pmic_mt6329_hw_bank1.h> 
#include <mach/pmic_mt6329_sw_bank1.h> 
#include <mach/pmic_mt6329_hw.h>
#include <mach/pmic_mt6329_sw.h>
#include <mach/upmu_common_sw.h>
#include <mach/upmu_hw.h>

#define KPD_PWRKEY_USE_EINT 0
#define KPD_PWRKEY_USE_PMIC 1
#define KPD_DRV_CTRL_BACKLIGHT	KPD_NO	/* retired, move to Lights framework */
#define KPD_BACKLIGHT_TIME	8	/* sec */
/* the keys can wake up the system and we should enable backlight */
#define KPD_BACKLIGHT_WAKE_KEY	\
{				\
	KEY_ENDCALL, KEY_POWER,	\
}

#define KPD_HAS_SLIDE_QWERTY	KPD_NO
#define KPD_SLIDE_EINT		CUST_EINT_KPD_SLIDE_NUM
#define KPD_SLIDE_DEBOUNCE	CUST_EINT_KPD_SLIDE_DEBOUNCE_CN		/* ms */
#define KPD_SLIDE_POLARITY	CUST_EINT_KPD_SLIDE_POLARITY
#define KPD_SLIDE_SENSITIVE	CUST_EINT_KPD_SLIDE_SENSITIVE

#if KPD_DRV_CTRL_BACKLIGHT
extern void kpd_enable_backlight(void);
extern void kpd_disable_backlight(void);
extern void kpd_backlight_handler(bool pressed, u16 linux_keycode);
#else
#define kpd_enable_backlight()		do {} while (0)
#define kpd_disable_backlight()		do {} while (0)
#define kpd_backlight_handler(pressed, linux_keycode)	do {} while (0)
#endif

/* for META tool */
extern void kpd_set_backlight(bool onoff, void *val1, void *val2);

#if KPD_PWRKEY_USE_PMIC
void kpd_pwrkey_pmic_handler(unsigned long pressed);
#endif

void kpd_pmic_rstkey_handler(unsigned long pressed);

//#define KPD_PMIC_RSTKEY_MAP KEY_VOLUMEDOWN
#define KPD_PMIC_LPRST_TD 1 /* timeout period. 0: 5sec; 1: 7sec; 2: 9sec; 3: 11sec */

#endif
