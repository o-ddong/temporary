/*
 * ELF executable loading
 * Copyright (c) 2003, Jeffrey K. Hollingsworth <hollings@cs.umd.edu>
 * Copyright (c) 2003, David H. Hovemeyer <daveho@cs.umd.edu>
 *
 * All rights reserved.
 *
 * This code may not be resdistributed without the permission of the copyright holders.
 * Any student solutions using any of this code base constitute derviced work and may
 * not be redistributed in any form.  This includes (but is not limited to) posting on
 * public forums or web sites, providing copies to (past, present, or future) students
 * enrolled in similar operating systems courses the University of Maryland's CMSC412 course.
 *
 * $Revision: 1.31 $
 *
 */

#include <geekos/errno.h>
#include <geekos/kassert.h>
#include <geekos/ktypes.h>
#include <geekos/screen.h>      /* for debug Print() statements */
#include <geekos/pfat.h>
#include <geekos/malloc.h>
#include <geekos/string.h>
#include <geekos/user.h>
#include <geekos/fileio.h>
#include <geekos/elf.h>

#include <geekos/paging.h>

int elfDebug = 0;

/**
 * From the data of an ELF executable, determine how its segments
 * need to be loaded into memory.
 * @param exeFileData buffer containing the executable file
 * @param exeFileLength length of the executable file in bytes
 * @param exeFormat structure describing the executable's segments
 *   and entry address; to be filled in
 * @return 0 if successful, < 0 on error
 */

int Parse_ELF_Executable(char *exeFileData, ulong_t exeFileLength, struct Exe_Format *exeFormat) {
	elfHeader *eh;
	eh=(elfHeader*)exeFileData;

	programHeader* ph;
	ph=(programHeader *)(exeFileData+eh->phoff);
	programHeader* ph1;
	ph1=(programHeader *)(exeFileData+eh->phoff+eh->phentsize);

	exeFormat->numSegments=2;
	exeFormat->entryAddr=eh->entry;

	exeFormat->segmentList[0].offsetInFile=ph->offset;
	exeFormat->segmentList[0].lengthInFile=ph->fileSize;
	exeFormat->segmentList[0].startAddress=ph->vaddr;
	exeFormat->segmentList[0].sizeInMemory=ph->memSize;
	exeFormat->segmentList[0].protFlags=ph->flags;

	exeFormat->segmentList[1].offsetInFile=ph1->offset;
	exeFormat->segmentList[1].lengthInFile=ph1->fileSize;
	exeFormat->segmentList[1].startAddress=ph1->vaddr;
	exeFormat->segmentList[1].sizeInMemory=ph1->memSize;
	exeFormat->segmentList[1].protFlags=ph1->flags;

        return 0;
}
