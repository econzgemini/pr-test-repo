/**
 * @file DeviceConfig.c
 * @brief Device configuration load/save/reset implementation.
 */
#include "DeviceConfig.h"
#include <string.h>

int32_t DCFG_i32Load(tstDCFG_Config *pstConfig)
{
    if (pstConfig == NULL)
    {
        return -1;
    }

    /* TODO: Read from NVS flash; fall back to defaults on miss */
    DCFG_vReset(pstConfig);
    return 0;
}

int32_t DCFG_i32Save(const tstDCFG_Config *pstConfig)
{
    if (pstConfig == NULL)
    {
        return -1;
    }

    /* TODO: Write to NVS flash */
    return 0;
}

void DCFG_vReset(tstDCFG_Config *pstConfig)
{
    if (pstConfig == NULL)
    {
        return;
    }

    memset(pstConfig, 0, sizeof(tstDCFG_Config));
    strncpy(pstConfig->acDeviceName, "VECS-HUB", DCFG_DEVICE_NAME_MAX_LEN - 1u);
    pstConfig->u32PairingPin = DCFG_PAIRING_PIN_DEFAULT;
    pstConfig->i8TxPowerDbm  = DCFG_TX_POWER_DEFAULT;
    pstConfig->u32CanBitRate = 500000u;
    pstConfig->bCanEnabled   = true;
}
