#include <rtthread.h>
#include "drv_common.h"
#include <rtdevice.h>
#include "drv_spi_ili9488.h"  // spi lcd driver
#include <lcd_spi_port.h>  // lcd ports
#include<time.h>
#include<stdio.h>
void time_get(void)
{
        struct tm* clock;
           time_t now;
           now = time(NULL);
           clock = gmtime(&now);
           lcd_show_string(45, 399, 16, "Time: %d:%d:%d ",clock->tm_hour,clock->tm_min,clock->tm_sec);
}

extern  unsigned char hightemp[20];
extern  unsigned char lowtemp[20];
extern  unsigned char humi[30];



#include <webclient.h>
char sendbuff[] = "http://api.seniverse.com/v3/weather/daily.json?key=SnylAbcdGsrQSKgcf&location=nanjing&language=zh-Hans&unit=c&start=0&days=1";


void weather_get(void)
{
    webclient_get_comm(sendbuff);
    lcd_show_string(66, 354, 16, "Current Situaion:");
    lcd_show_string(50, 370, 16, "Nanjing  %c%c-%c%c Celcius %c%c %",lowtemp[7],lowtemp[8],
            hightemp[8],hightemp[9],humi[12],humi[13]);
}

