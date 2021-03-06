// *****************************************************************************
//
// Copyright (c) 2018, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************

#include "Defines.h"
#include "MyRegisterEventSink.h"
#include "Camera.h"

///
/// \brief Constructor
///

MyRegisterEventSink::MyRegisterEventSink()
{

}


///
/// \brief Destructor
///

MyRegisterEventSink::~MyRegisterEventSink()
{

}


///
/// \brief Pre-read notification - usually a good place to update the register content
///

PvResult MyRegisterEventSink::PreRead( IPvRegister *aRegister )
{
 //   std::cout << aRegister->GetName().GetAscii() << " PreRead" << std::endl;
    return PvResult::Code::OK;
}


///
/// \brief Post-read nofitication
///

void MyRegisterEventSink::PostRead( IPvRegister *aRegister )
{
 //   std::cout << aRegister->GetName().GetAscii() << " PostRead" << std::endl;
;
}


///
/// \brief Pre-write notification - this is where a new register value is usually validated
///

PvResult MyRegisterEventSink::PreWrite( IPvRegister *aRegister )
{
     PvString sValue;
     if (aRegister->GetAddress() == BARCODEREADERADDR)
     {
        aRegister->Read(sValue);
        set_barcode_read (sValue.GetLength());
     }
//    std::cout << aRegister->GetName().GetAscii() << " PreWrite" << std::endl;
    return PvResult::Code::OK;
}


///
/// \brief Post-write notification: react to a register write
///

void MyRegisterEventSink::PostWrite( IPvRegister *aRegister )
{
 //   std::cout << aRegister->GetName().GetAscii() << " PostWrite" << std::endl;
;
}

