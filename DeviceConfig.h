/**
 * @file DeviceConfig.h
 * @brief Device configuration get/set API.
 */
#ifndef _DEVICE_CONFIG_H_
#define _DEVICE_CONFIG_H_

#include <stdint.h>
#include <stdbool.h>

#define DCFG_DEVICE_NAME_MAX_LEN    32u
#define DCFG_PAIRING_PIN_DEFAULT    123456u
#define DCFG_TX_POWER_DEFAULT       0       /* dBm */

typedef struct
{
    char     acDeviceName[DCFG_DEVICE_NAME_MAX_LEN];
    uint32_t u32PairingPin;
    int8_t   i8TxPowerDbm;
    uint32_t u32CanBitRate;
    bool     bCanEnabled;
} tstDCFG_Config;

/**
 * @brief Load config from flash, or populate with defaults if not found.
 * @param pstConfig  Output config structure.
 * @return 0 on success.
 */
int32_t DCFG_i32Load(tstDCFG_Config *pstConfig);

/**
 * @brief Persist the current config to flash.
 * @param pstConfig  Config structure to save.
 * @return 0 on success.
 */
int32_t DCFG_i32Save(const tstDCFG_Config *pstConfig);

/**
 * @brief Reset config to factory defaults.
 * @param pstConfig  Output config structure filled with defaults.
 */
void DCFG_vReset(tstDCFG_Config *pstConfig);

#endif /* _DEVICE_CONFIG_H_ */
