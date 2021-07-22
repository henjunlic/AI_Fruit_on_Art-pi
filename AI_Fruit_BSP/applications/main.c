#include "netdev_ipaddr.h"
#include "netdev.h"
//#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "time.h"
#include "ntp.h"
#define LED_PIN GET_PIN(I, 8)
extern void wlan_autoconnect_init(void);
int main(void)
{
    struct netdev *netdev = RT_NULL;
    wlan_autoconnect_init();
    rt_wlan_config_autoreconnect(RT_TRUE);

    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
    rt_kprintf("Mdelaycxxx");

    do
    {
        netdev = netdev_get_first_by_flags(NETDEV_FLAG_LINK_UP);
        rt_thread_mdelay(1000);
    }
    while(netdev == RT_NULL);

    if(netdev != RT_NULL)
    {
        time_t cur_time;
        cur_time = ntp_sync_to_rtc(NULL);
        if (cur_time)
        {
            rt_kprintf("Cur Time: %s", ctime(&cur_time));
        }
        else
        {
            rt_kprintf("NTP sync fail.\n");
        }
        fruit_app();
    }
}

#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);
