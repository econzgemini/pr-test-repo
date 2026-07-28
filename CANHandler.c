/**
 * @file CANHandler.c
 * @brief CAN frame dispatch implementation.
 */
#include "CANHandler.h"
#include <string.h>

static CAN_FrameHandlerCB g_CAN_pfHandler = NULL;

int32_t CAN_i32HandlerInit(CAN_FrameHandlerCB pfCB)
{
    if (pfCB == NULL)
    {
        return -1;
    }
    g_CAN_pfHandler = pfCB;
    return 0;
}

int32_t CAN_i32Send(const tstCAN_Frame *pstFrame)
{
    if (pstFrame == NULL || pstFrame->u8DLC > CAN_MAX_FRAME_SIZE)
    {
        return -1;
    }
    /* TODO: Write to hardware TX mailbox */
    return 0;
}

/* Called from ISR or task when a frame arrives */
void CAN_vOnReceive(const tstCAN_Frame *pstFrame)
{
    if (g_CAN_pfHandler != NULL && pstFrame != NULL)
    {
        g_CAN_pfHandler(pstFrame);
    }
}
