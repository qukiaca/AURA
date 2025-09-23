#include "program.h"

int start(int *pg_status, droneport *dp, drone_unit *drone)
{
    printf("Проверка UID дронпорта...\n");
    if(generated_id(dp->uid))
    {
        printf("UID: %s сгенерирован и активирован\n", dp->uid);
    }
    
    printf("Проверка UID дрона...\n");
    if(generated_id(drone->uid))
    {
        printf("UID: %s сгенерирован и активирован\n", drone->uid);
    }


    drone->drone_battery.battery_charge_perc = 100;
    drone->drone_battery.capacity_mah = 2590;
    drone->drone_battery.voltage_v = 7.32;
    drone->drone_battery.current_ma = 4570;
    drone->drone_battery.charge_level_mah = drone->drone_battery.capacity_mah - 0;
    drone->drone_battery.battery_status = BATTERY_NORMAL;
    drone->initialized = true;

    dp->dp_battery.battery_charge_perc = 100;
    dp->dp_battery.capacity_mah = 50000;
    dp->dp_battery.voltage_v = 7.4;
    dp->dp_battery.current_ma = 5000;
    dp->dp_battery.charge_level_mah = dp->dp_battery.capacity_mah - 0;
    dp->dp_battery.battery_status = BATTERY_NORMAL;
    dp->initialized = true;

    printf("Система инициализирована...\n");

    //-------------ЗДЕСЬ НАЧИНАЕТСЯ ШИЗОФРЕНИЧЕСКИЙ БРЕД-----------------//
    fflush(stdout);
    usleep(1000000);
    printf("Дорогой пользователь данной системы...\n");
    fflush(stdout);
    usleep(1000000);
    printf("Вы управляете дронами, телеметрией, зарядкой, серверами — и вдруг…пыль.\n");
    fflush(stdout);
    usleep(1000000);
    printf("Под ногами. Под дроном. Даже на серверной стойке.\n");
    fflush(stdout);
    usleep(1000000);
    printf("Кто это допустил?\n\n");
    fflush(stdout);
    usleep(1000000);
    printf("Обычный пылесос вам не нужен.\nНо наш — поддерживает:\n");
    fflush(stdout);
    usleep(1000000);
    printf("→ Автономный маршрут по топологии квартиры\n");
    fflush(stdout);
    usleep(1000000);
    printf("→ Режим Low Latency Suction™ — без задержек при всасывании\n");
    fflush(stdout);
    usleep(1000000);
    printf("→ Автодокинг с самоочисткой фильтра по cron-расписанию\n");
    fflush(stdout);
    usleep(1000000);
    printf("→ Push-уведомления: “Кошка на маршруте — приостанавливаю работу”\n");
    fflush(stdout);
    usleep(1000000);
    printf("→ Интеграция с вашим droneport’ом: “Заряжайся сам — я пока полы пропылесошу”\n");
    fflush(stdout);
    usleep(1000000);
    printf("\nAURA — Autonomous Unit for Robotic Absorption\n\n");
    fflush(stdout);
    usleep(1000000);
    printf("Не просто пылесос. Это — ваш ground unit в системе тотального контроля.\n");
    fflush(stdout);
    usleep(1000000);
    printf("→ Интеграция с вашим droneport’ом: “Заряжайся сам — я пока полы”\n");
    fflush(stdout);
    usleep(1000000);
    printf("\nAURA — Autonomous Unit for Robotic Absorption\n\n");

    const char *msg = " *Внимание: AURA не всасывает дроны, кофе, чувства вины и legacy-код. Батарейки не нужны — он на RTFM-зарядке. Не используйте для деплоя продакшена. Случайное всасывание носков — фича, а не баг. Поддержка WebSocket не отменяет необходимости мыть полы вручную раз в год. Работает только там, где Wi-Fi ловит лучше, чем ваше терпение.* ";
    int len = strlen(msg);
    int display_width = 80;

    for (int offset = 0; offset < len; offset++)
    {
        printf("\r");
        for (int i = 0; i < display_width && offset + i < len; i++)
        {
            printf("%c", msg[offset + i]);
        }
        if (offset + display_width < len)
            printf(" ");
        fflush(stdout);
            usleep(10000); // 80 миллисекунд — плавный скролл
    }
    printf("\n"); // переводим строку после анимации

    //-------------ЗДЕСЬ ЗАКАНЧИВАЕТСЯ ШИЗОФРЕНИЧЕСКИЙ БРЕД-----------------//

    return *pg_status; 
}