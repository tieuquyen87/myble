/* Copyright (c) 2017 pcbreflux. All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>. *
 */
#ifndef BLE_SERVER_H_
#define BLE_SERVER_H_
#include "esp_wifi.h"
#include "esp_event.h"
#include "lwip/inet.h"
#include "lwip/ip4_addr.h"
#include "lwip/dns.h"
#ifdef __cplusplus
extern "C" {
#endif

#define GATTS_SERVICE_UUID   0x0001
//#define GATTS_CHAR_UUID      0xFF01
//#define GATTS_DESCR_UUID     0x3333
#define GATTS_CHAR_NUM		2
#define GATTS_NUM_HANDLE     1+(3*GATTS_CHAR_NUM)

#define BLE_DEVICE_NAME            "ACR_ESP32_SERVER"
#define BLE_MANUFACTURER_DATA_LEN  4

#define GATTS_CHAR_VAL_LEN_MAX		22

#define BLE_PROFILE_APP_ID 0
static int timeblink = 10000;
//char* datatransfer = NULL;
char datatransferr[128];
static int statustransfer = 0;
void gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);
void gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

void char1_read_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void char1_write_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void descr1_read_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void descr1_write_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void char2_read_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void char2_write_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void descr2_read_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void descr2_write_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
int getTimeBlink();
void mainTaskkk();
int get_notification(char * messages, int messages_len);
//void dns_found_cb(const char *name, const ip_addr_t *ipaddr, void *callback_arg);
esp_err_t wifi_event_cb(void *ctx, system_event_t *event);
#ifdef __cplusplus
}
#endif

#endif /* BLE_SERVER_H_ */
