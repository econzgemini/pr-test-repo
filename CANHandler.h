/**
 * @file CANHandler.h
 * @brief CAN frame dispatch — routes received frames to registered handlers.
 */
#ifndef _CAN_HANDLER_H_
#define _CAN_HANDLER_H_

#include <stdint.h>
#include <stdbool.h>

#define CAN_MAX_FRAME_SIZE      8u
#define CAN_TX_TIMEOUT_MS       50u

typedef struct
{
    uint32_t u32Id;
    uint8_t  u8DLC;
    uint8_t  au8Data[CAN_MAX_FRAME_SIZE];
    bool     bIsExtended;
} tstCAN_Frame;

typedef void (*CAN_FrameHandlerCB)(const tstCAN_Frame *pstFrame);

/**
 * @brief Initialise CAN handler and register a receive callback.
 * @param pfCB  Callback invoked on each received frame.
 * @return 0 on success.
 */
int32_t CAN_i32HandlerInit(CAN_FrameHandlerCB pfCB);

/**
 * @brief Transmit a CAN frame.
 * @param pstFrame  Frame to transmit.
 * @return 0 on success, -1 on timeout.
 */
int32_t CAN_i32Send(const tstCAN_Frame *pstFrame);

#endif /* _CAN_HANDLER_H_ */
