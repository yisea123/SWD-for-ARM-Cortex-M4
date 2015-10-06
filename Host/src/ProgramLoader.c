#include "ProgramLoader.h"

int programSize = 0;
static Tlv *response;
static User_Session *userSession;

char *FLASH_PROGRAMMER_FILE_PATH = "C:/Users/susan_000/Projects/SWD-for-ARM-Cortex-M4/FlashProgrammer/FlashProgrammer/Debug/bin/FlashProgrammer.elf";

/** tlvWriteTargetRegister is a function to write data into target register
  * 
  * input   : session contain a element/handler used by tlv protocol
  *           registerAddress is the address of the target register
  *           data is the data need to write into the target register
  *
  * return  : 1 successfully write into target register
  *           0 waiting reply from target
  */
int tlvWriteTargetRegister(Tlv_Session *session, uint32_t registerAddress, uint32_t *data) {
  Tlv *tlv; uint32_t buffer[] = {registerAddress, *data};
  
  /* Start tlv request task */
  startTask(session->state);
  
  /* Send tlv request */
  tlv = tlvCreatePacket(TLV_WRITE_REGISTER, 8, (uint8_t *)buffer);
  session->ongoingProcessFlag = FLAG_SET;
  tlvSend(session, tlv);
  
  /* Waiting reply from probe */
  while((response = tlvReceive(session)) == NULL) {
    /* Check is maximum timeout is reached */
    if(isTimeOut()) Throw(PROBE_NOT_RESPONDING);
    yield(session->state);
  };
  
  resetSystemTime();
  /* Verify response reply from probe */
  verifyTlvPacket(response);
  session->ongoingProcessFlag = FLAG_CLEAR;
  
  /* End tlv request task */
  endTask(session->state);
  
  return 1;
}

/** tlvReadTargetRegister is a function to read target register
  * 
  * input   : session contain a element/handler used by tlv protocol
  *           registerAddress is the address of the target register
  *
  * return  : register value if successfully read from probe
  *           0 if waiting reply from probe
  */
uint32_t tlvReadTargetRegister(Tlv_Session *session, uint32_t registerAddress) {
  Tlv *tlv;
  
  /* Start tlv request task */
  startTask(session->state);
  
  /* Send tlv request */
  tlv = tlvCreatePacket(TLV_READ_REGISTER, 4, (uint8_t *)&registerAddress);
  session->ongoingProcessFlag = FLAG_SET;
  tlvSend(session, tlv);
  
  /* Waiting reply from probe */
  while((response = tlvReceive(session)) == NULL) {
    /* Check is maximum timeout is reached */
    if(isTimeOut()) Throw(PROBE_NOT_RESPONDING);
    yield(session->state);
  };
  
  resetSystemTime();
  /* Verify response reply from probe */
  verifyTlvPacket(response);
  session->ongoingProcessFlag = FLAG_CLEAR;
  // printf("register %x\n", get4Byte(&response->value[0]));
  
  /* End tlv request task */
  endTask(session->state);
  
  return get4Byte(&response->value[0]);
}

/** tlvHaltTarget is a function halt target processor
  * 
  * input   : session contain a element/handler used by tlv protocol
  *           registerAddress is the address of the target register
  *
  * return  : 1 if successfully halted
  *           0 if waiting reply from probe
  */
int tlvHaltTarget(Tlv_Session *session) {
  Tlv *tlv;
  
  /* Start tlv request task */
  startTask(session->state);
  
  /* Send tlv request */
  tlv = tlvCreatePacket(TLV_HALT_TARGET, 0, 0);
  session->ongoingProcessFlag = FLAG_SET;
  tlvSend(session, tlv);
  
  /* Waiting reply from probe */
  while((response = tlvReceive(session)) == NULL) {
    /* Check is maximum timeout is reached */
    if(isTimeOut()) Throw(PROBE_NOT_RESPONDING);
    yield(session->state);
  };
  
  resetSystemTime();
  /* Verify response reply from probe */
  verifyTlvPacket(response);
  session->ongoingProcessFlag = FLAG_CLEAR;
  
  /* End tlv request task */
  endTask(session->state);
  
  return 1;
}

/** tlvRunTarget is a function run target processor
  * 
  * input   : session contain a element/handler used by tlv protocol
  *           registerAddress is the address of the target register
  *
  * return  : 1 if successfully run
  *           0 if waiting reply from probe
  */
int tlvRunTarget(Tlv_Session *session) {
  Tlv *tlv;
  
  /* Start tlv request task */
  startTask(session->state);
  
  /* Send tlv request */
  tlv = tlvCreatePacket(TLV_RUN_TARGET, 0, 0);
  session->ongoingProcessFlag = FLAG_SET;
  tlvSend(session, tlv);
  
  /* Waiting reply from probe */
  while((response = tlvReceive(session)) == NULL) {
    /* Check is maximum timeout is reached */
    if(isTimeOut()) Throw(PROBE_NOT_RESPONDING);
    yield(session->state);
  };
  
  resetSystemTime();
  /* Verify response reply from probe */
  verifyTlvPacket(response);
  session->ongoingProcessFlag = FLAG_CLEAR;
  
  /* End tlv request task */
  endTask(session->state);
  
  return 1;
}

/** tlvMultipleStepTarget is a function send tlv request to
  * execute number of instructions
  * 
  * input   : session contain a element/handler used by tlv protocol
  *           nInstructions is the number of instruction need to execute
  *
  * return  : Current program counter address if successfully step
  *           0 if waiting reply from probe
  */
uint32_t tlvMultipleStepTarget(Tlv_Session *session, int nInstructions) {
  Tlv *tlv;
  
  /* Start tlv request task */
  startTask(session->state);
  
  /* Send tlv request */
  tlv = tlvCreatePacket(TLV_STEP, 4, (uint8_t *)&nInstructions);
  session->ongoingProcessFlag = FLAG_SET;
  tlvSend(session, tlv);
  
  /* Waiting reply from probe */
  while((response = tlvReceive(session)) == NULL) {
    /* Check is maximum timeout is reached */
    if(isTimeOut()) Throw(PROBE_NOT_RESPONDING);
    yield(session->state);
  };
  
  resetSystemTime();
  /* Verify response reply from probe */
  verifyTlvPacket(response);
  session->ongoingProcessFlag = FLAG_CLEAR;
  
  /* End tlv request task */
  endTask(session->state);
  
  return get4Byte(&response->value[0]);
}

/** tlvSoftReset is a function software reset target
  *
  * Input   : session contain a element/handler used by tlv protocol
  *
  * Return  : NONE
  */
void tlvSoftReset(Tlv_Session *session) {
  Tlv *tlv = tlvCreatePacket(TLV_SOFT_RESET, 0, 0);

  tlvSend(session, tlv);
}

/** tlvSoftReset is a function hardware reset target
  *
  * Input   : session contain a element/handler used by tlv protocol
  *
  * Return  : NONE
  */
void tlvHardReset(Tlv_Session *session) {
  Tlv *tlv = tlvCreatePacket(TLV_HARD_RESET, 0, 0);

  tlvSend(session, tlv);
}

/** tlvWriteDataChunk is a function used to send data in chunk
  * by using tlv protocol
  * 
  * input   : session contain a element/handler used by tlv protocol
  *           dataAddress is the address of the data need to send
  *           destAddress is the address of the data need to be store
  *           size is the size of the data can be any value
  *           memorySelect can be one of the following value :
  *             TLV_WRITE_RAM
  *             TLV_WRITE_FLASH
  *
  * return  : NONE
  */
void tlvWriteDataChunk(Tlv_Session *session, uint8_t *dataAddress, uint32_t destAddress, int size, Tlv_Command memorySelect) {
  Tlv *tlv; uint8_t chksum = 0;
  
  /* create tlv packet with register address */
  tlv = tlvCreatePacket(memorySelect, size + 4, NULL);
  
  chksum = tlvPackIntoBuffer(tlv->value, (uint8_t *)&destAddress, 4);
  chksum += tlvPackIntoBuffer(&tlv->value[4], dataAddress, size);

  /* Update checksum with destAddress */
  tlv->value[tlv->length - 1] = chksum;
  
  tlvSend(session, tlv);
}

/** tlvWriteTargetMemory is a function used to write data into target memory
  * by using tlv protocol
  * 
  * Input   : session contain a element/handler used by tlv protocol
  *           dataAddress is the address of the data need to send
  *           destAddress is the address of the data need to be store
  *           size is the size of the data can be any value
  *           memorySelect can be one of the following value :
  *            - TLV_WRITE_RAM
  *            - TLV_WRITE_FLASH
  *
  * return  : NONE
  */
void tlvWriteTargetMemory(Tlv_Session *session, uint8_t **dataAddress, uint32_t *destAddress, int *size, Tlv_Command memorySelect)  {

  if(*size > TLV_DATA_SIZE) 
    tlvWriteDataChunk(session, *dataAddress, *destAddress, TLV_DATA_SIZE, memorySelect);
  else 
    tlvWriteDataChunk(session, *dataAddress, *destAddress, *size, memorySelect);
  
  *dataAddress += TLV_DATA_SIZE;
  *destAddress += TLV_DATA_SIZE;
  *size -= TLV_DATA_SIZE;
}

/** tlvReadDataChunk is a function used to read data in chunk
  * by using tlv protocol
  * 
  * input   : session contain a element/handler used by tlv protocol
  *           destAddress is the address of the data need to be store
  *           size is the size of the data can be any value
  *
  * return  : NONE
  */
void tlvReadDataChunk(Tlv_Session *session, uint32_t destAddress, int size) {
  Tlv *tlv;
  uint32_t buffer[] = {destAddress, size};
  
  /* create tlv packet with register address */
  tlv = tlvCreatePacket(TLV_READ_MEMORY, 8, (uint8_t *)buffer);

  tlvSend(session, tlv);
}

/** tlvReadTargetMemory is a function to read data from target memory
  * base on tlv->type
  *
  * Input   : session contain a element/handler used by tlv protocol
  *           destAddress is the address of the data need to be read
  *           size is the size of the data can be any value
  *
  * Return  : NONE
  */
void tlvReadTargetMemory(Tlv_Session *session, uint32_t *destAddress, int *size) {
  Tlv *tlv; 
  session->ongoingProcessFlag = FLAG_SET;

  if(*size > TLV_DATA_SIZE) {
    tlvReadDataChunk(session, *destAddress, TLV_DATA_SIZE);
  }
  else  {
    tlvReadDataChunk(session, *destAddress, *size);
    session->ongoingProcessFlag = FLAG_CLEAR;
  }
  
  *destAddress += TLV_DATA_SIZE;
  *size -= TLV_DATA_SIZE;
}

/** !< Internal Function used by Load Program To Memory >!
  * tlvLoadProgram is a function to load program into target memory
  *
  * Input   : session contain a element/handler used by tlv protocol
  *           file is the file need to be load into target memory
  *           memorySelect can be one of the following value :
  *            - TLV_WRITE_RAM
  *            - TLV_WRITE_FLASH
  *
  * Return  : NONE
  */
void tlvLoadProgram(Tlv_Session *session, char *file, Tlv_Command memorySelect) {
  
  switch(session->loadProgramState) {
    
    case TLV_LOAD_ISR_VECTOR :
      if(fileStatus == FILE_CLOSED) {
        getElfSection(file);
        session->ongoingProcessFlag = FLAG_SET;
      }
      tlvWriteTargetMemory(session, &isr->dataAddress, &isr->destAddress, &isr->size, memorySelect);
      if(isr->size <= 0) {
        printf("Load ISR_VECTOR...OK\n");
        session->loadProgramState = TLV_LOAD_TEXT;
      }
    break;
    
    case TLV_LOAD_TEXT :
      tlvWriteTargetMemory(session, &text->dataAddress, &text->destAddress, &text->size, memorySelect);
      if(text->size <= 0) {
        printf("Load Text...OK\n");
        session->loadProgramState = TLV_LOAD_RO_DATA;
      }
    break;
    
    case TLV_LOAD_RO_DATA :
      tlvWriteTargetMemory(session, &roData->dataAddress, &roData->destAddress, &roData->size, memorySelect);
      if(roData->size <= 0) {
        printf("Load RO Data...OK\n");
        session->loadProgramState = TLV_LOAD_INIT_ARRAY;
      }
    break;
  
    case TLV_LOAD_INIT_ARRAY :
      tlvWriteTargetMemory(session, &initArray->dataAddress, &initArray->destAddress, &initArray->size, memorySelect);
      if(initArray->size <= 0) {
        printf("Load Init Array...OK\n");
        session->loadProgramState = TLV_LOAD_FINI_ARRAY;
      }
    break;
    
    case TLV_LOAD_FINI_ARRAY :
      tlvWriteTargetMemory(session, &finiArray->dataAddress, &finiArray->destAddress, &finiArray->size, memorySelect);
        if(finiArray->size <= 0) {
          printf("Load Fini Array...OK\n");
          session->loadProgramState = TLV_LOAD_DATA;
        }
    break;
    
    case TLV_LOAD_DATA :
      tlvWriteTargetMemory(session, &data->dataAddress, &data->destAddress, &data->size, TLV_WRITE_RAM);
      if(data->size <= 0) {
        /* Close elf file */
        printf("Load Data...OK\n");
        closeElfFile();
        session->ongoingProcessFlag = FLAG_CLEAR;
        session->loadProgramState = TLV_LOAD_ISR_VECTOR;
      }
    break;
  }
}

void tlvRequestFlashErase(Tlv_Session *session, uint32_t address, int size) {
  uint32_t buffer[] = {address, size};
  
  /* create tlv packet address and size */
  Tlv *tlv = tlvCreatePacket(TLV_FLASH_ERASE, 8, (uint8_t *)buffer);
  
  tlvSend(session, tlv);
}

/** tlvFlashErase
  *
  * Input   : session contain a element/handler used by tlv protocol
  *           file is the file need to be load into target memory
  *
  * Return  : NONE
  */
void tlvEraseTargetFlash(Tlv_Session *session, uint32_t address, int size) {
  
  switch(session->eraseState) {
    case TLV_LOAD_FLASH_PROGRAMMER :
      tlvLoadToRam(session, FLASH_PROGRAMMER_FILE_PATH);
      if(session->ongoingProcessFlag == FLAG_CLEAR) {
        session->ongoingProcessFlag = FLAG_SET;
        session->eraseState = TLV_REQUEST_ERASE;
      }
    break;
    
    case TLV_REQUEST_ERASE :
      tlvRequestFlashErase(session, address, size);
      session->ongoingProcessFlag = FLAG_CLEAR;
      session->eraseState = TLV_LOAD_FLASH_PROGRAMMER;
    break;
  }
}

void tlvRequestFlashMassErase(Tlv_Session *session, uint32_t banks) {
  /* create tlv packet address and size */
  Tlv *tlv = tlvCreatePacket(TLV_FLASH_MASS_ERASE, 4, (uint8_t *)&banks);
  
  tlvSend(session, tlv);
}

/** tlvFlashMassErase
  *
  * Input   : session contain a element/handler used by tlv protocol
  *           file is the file need to be load into target memory
  *
  * Return  : NONE
  */
void tlvMassEraseTargetFlash(Tlv_Session *session, uint32_t banks) {
  
  switch(session->mEraseState) {
    case TLV_LOAD_FLASH_PROGRAMMER :
      tlvLoadToRam(session, FLASH_PROGRAMMER_FILE_PATH);
      if(session->ongoingProcessFlag == FLAG_CLEAR) {
        session->ongoingProcessFlag = FLAG_SET;
        session->mEraseState = TLV_REQUEST_ERASE;
      }
    break;
    
    case TLV_REQUEST_ERASE :
      tlvRequestFlashMassErase(session, banks);
      session->ongoingProcessFlag = FLAG_CLEAR;
      session->mEraseState = TLV_LOAD_FLASH_PROGRAMMER;
    break;
  }
}

/** tlvLoadToRam is a function to load elf file and update PC 
  * to the program entry addresss
  *
  * Input   : session contain a element/handler used by tlv protocol
  *           file is the file need to be load into target memory
  *
  * Return  : NONE
  */
void tlvLoadToRam(Tlv_Session *session, char *file) {
  
  switch(session->ramState) {
    case TLV_LOAD_PROGRAM :
      /* Load elf file isr_vector, ro_data, data
         and text section into target RAM */
      tlvLoadProgram(session, file, TLV_WRITE_RAM);
      
      if(session->ongoingProcessFlag == FLAG_CLEAR) {
        session->ongoingProcessFlag = FLAG_SET;
        session->ramState = TLV_UPDATE_PC;
      }
    break;
    
    case TLV_UPDATE_PC :        
      /* Update program counter to the entry address 
         of the loaded program */
      tlvWriteTargetRegister(session, PC, &entryAddress);
      session->ramState = TLV_RUN_PROGRAM;
    break;
    
    case TLV_RUN_PROGRAM :
      /* Run program on target */
      tlvRunTarget(session);
      session->ongoingProcessFlag = FLAG_CLEAR;
      session->ramState = TLV_LOAD_PROGRAM;
    break;
  }
}

/** tlvLoadToFlash is a function to load elf file and update PC 
  * to the program entry addresss
  *
  * Input   : session contain a element/handler used by tlv protocol
  *           file is the file need to be load into target memory
  *
  * Return  : NONE
  */
void tlvLoadToFlash(Tlv_Session *session, char *file)  {
  
  switch(session->flashState) {
    case TLV_REQUEST_ERASE :
      if(programSize == 0) programSize = getProgramSize(file);

      /* Request Flash Programmer to erase flash according to program size */
      tlvEraseTargetFlash(session, 0x08000000, programSize);
      
      if(session->ongoingProcessFlag == FLAG_CLEAR) {
        programSize = 0;
        session->ongoingProcessFlag = FLAG_SET;
        session->flashState = TLV_LOAD_ACTUAL_PROGRAM;
      }
    break;
      
    case TLV_LOAD_ACTUAL_PROGRAM :
      /* Load elf file isr_vector, ro_data, data
      and text section into target Flash */
      tlvLoadProgram(session, file, TLV_WRITE_FLASH);
      
      if(session->ongoingProcessFlag == FLAG_CLEAR) {
        session->ongoingProcessFlag = FLAG_SET;
        session->flashState = TLV_UPDATE_PC;
      }
    break;
    
    case TLV_UPDATE_PC :
      /* Update program counter to the entry address 
         of the loaded program */
      tlvWriteTargetRegister(session, PC, &entryAddress);
      session->flashState = TLV_RUN_PROGRAM;
      break;
      
    case TLV_RUN_PROGRAM :
      /* Run program on target */
      tlvRunTarget(session);

      session->ongoingProcessFlag = FLAG_CLEAR;
      session->flashState = TLV_REQUEST_ERASE;
    break;
  }
}

/** tlvSetBreakpoint is a function to set breakpoint
  * at specified address
  *
  * Input   : session contain a element/handler used by tlv protocol
  *           address is the address want to be stop at
  *
  * Return  : NONE
  */
void tlvSetBreakpoint(Tlv_Session *session, uint32_t address) {
  Tlv *tlv = tlvCreatePacket(TLV_BREAKPOINT, 4, (uint8_t *)&address);

  tlvSend(session, tlv);
}

/** selectCommand is a function to select instruction 
  * base on userSession
  *
  * Input   : tlv is pointer pointing to tlv packet
  *
  * Return  : NONE
  */
void selectCommand(Tlv_Session *session, User_Session *userSession) {

  switch(userSession->tlvCommand) {
    case TLV_WRITE_RAM          : tlvLoadToRam(session, userSession->fileName);                                                 break;
    case TLV_WRITE_FLASH        : tlvLoadToFlash(session, userSession->fileName);                                               break;
    case TLV_READ_MEMORY        : tlvReadTargetMemory(session, &userSession->address, &userSession->size);                      break;
    case TLV_WRITE_REGISTER     : tlvWriteTargetRegister(session, userSession->address, userSession->data);                     break;
    case TLV_READ_REGISTER      : tlvReadTargetRegister(session, userSession->address);                                         break;
    case TLV_HALT_TARGET        : tlvHaltTarget(session);                                                                       break;
    case TLV_RUN_TARGET         : tlvRunTarget(session);                                                                        break;
    case TLV_STEP               : tlvMultipleStepTarget(session, (int)(*userSession->data));                                    break;
    case TLV_BREAKPOINT         : tlvSetBreakpoint(session, userSession->address);                                              break;
    case TLV_FLASH_ERASE        : tlvEraseTargetFlash(session, userSession->address, userSession->size);                        break;
    case TLV_FLASH_MASS_ERASE   : tlvMassEraseTargetFlash(session, userSession->address);                                       break;
    case TLV_SOFT_RESET         : tlvSoftReset(session);                                                                        break;
    case TLV_HARD_RESET         : tlvHardReset(session);                                                                        break;
  }
}

/** isLastOperationDone is a function to check last operation
  * state if still ongoing it will continue intepret
  *
  * input   : session contain a element/handler used by tlv protocol
  *
  * return  : NONE
  */
int isLastOperationDone(Tlv_Session *session) {
  if(session->ongoingProcessFlag == FLAG_CLEAR) {
    return 1;
  }
  else return 0;
}

/** hostInterpreter
  */
void hostInterpreter(Tlv_Session *session) {
  
  switch(session->hostState)  {
    
    case HOST_WAIT_USER_COMMAND :
      userSession = waitUserCommand();
      if(userSession != NULL) {
        if(userSession->tlvCommand == TLV_EXIT) 
          session->hostState = HOST_EXIT;
        else session->hostState = HOST_INTERPRET_COMMAND;
      }
    break;
      
    case HOST_INTERPRET_COMMAND :
      selectCommand(session, userSession);
      if(isLastOperationDone(session))
        session->hostState = HOST_WAIT_USER_COMMAND;
    break;
      
    // case HOST_WAITING_RESPONSE :
      // startTimer();
      // response = tlvReceive(session);

      // if(response == NULL) {
        // if(getElapsedTime()) {
          // Throw(PROBE_NOT_RESPONDING);
        // }
      // }

      // if(verifyTlvPacket(response)) {
        // elapsedTime = 0;
        // #if !defined (TEST)
        // displayTlvData(response); 
        // #endif
        
        // isLastOperationDone(session);
      // }
    // break;
  }
}