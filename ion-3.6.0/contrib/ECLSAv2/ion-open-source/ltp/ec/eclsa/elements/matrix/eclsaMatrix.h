/*
 eclsaMatrix.h

 Author: Nicola Alessi (nicola.alessi@studio.unibo.it)
 Project Supervisor: Carlo Caini (carlo.caini@unibo.it)

 Copyright (c) 2016, Alma Mater Studiorum, University of Bologna
 All rights reserved.

todo

 * */

#ifndef LTP_EC_ECLSA_TOOLS_ECLSAMATRIX_H_

#define LTP_EC_ECLSA_TOOLS_ECLSAMATRIX_H_

#include "eclsaCodecMatrix.h"
#include "../eclsaBoolean.h"
#include "../fec/eclsaFecManager.h"
#include "../packet/eclsaSendingSequence.h"
#include "../sys/eclsaTimer.h"
#include <semaphore.h>

typedef struct
{
	/*COMMON*/
	unsigned short 	engineID; //todo manage overflows
	unsigned short  ID; //ex bid , matrix id
	unsigned long 	globalID; //todo manage overflows
	unsigned int	maxInfoSize; //max K
	unsigned int	infoSegmentAddedCount; // <= maxInfoSize
	unsigned int	redundancySegmentAddedCount; // <= N-K
	FecElement 		*encodingCode; //code used for encoding
	CodecMatrix 	*universalCodecMatrix;
	EclsaTimer 		timer;
	bool			clearedToCodec;
	bool			clearedToSend;
	sem_t			lock;
	bool			feedbackEnabled;
	char 			codecStatus;

	/*ONLY FOR ECLSI*/
    int 			workingT;
    void 			*lowerProtocolData;

    /*ONLY FOR ECLSO*/
    SendingSequence sequence;
} EclsaMatrix;


/*Single eclsa matrix functions*/
bool isMatrixInfoPartFull(EclsaMatrix *matrix);
bool isMatrixEmpty(EclsaMatrix *matrix);
bool isInfoSymbol(EclsaMatrix *matrix, int symbolID);
void eclsaMatrixInit(EclsaMatrix *matrix);
void eclsaMatrixDestroy(EclsaMatrix *matrix);
void addSegmentToEclsaMatrix(EclsaMatrix *matrix, char *buffer, int bufferLength, int symbolID,bool copyLength);
void flushEclsaMatrix(EclsaMatrix *matrix);

#endif /* LTP_EC_ECLSA_TOOLS_ECLSAMATRIX_H_ */
