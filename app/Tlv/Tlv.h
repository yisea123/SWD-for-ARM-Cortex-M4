#ifndef Tlv_H
#define Tlv_H

#ifdef TEST
extern int uartReady;
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Tlv_ex.h"
#include "uart.h"
#include "CException.h"

Tlv_Session *tlvCreateSession(void);

Tlv *tlvCreatePacket(uint8_t command, int size, uint8_t *data);
void tlvPackIntoBuffer(uint8_t *targetBuffer, uint8_t *currentBuffer, int length);

void tlvSend(Tlv_Session *session, Tlv *tlv);
Tlv *tlvReceive(Tlv_Session *session);

/* Tlv service state machine */
void tlvSendService(Tlv_Session *session);
void tlvReceiveService(Tlv_Session *session);
void tlvService(Tlv_Session *session);

#endif // Tlv_H
