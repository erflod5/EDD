// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest
// DO NOT EDIT. ANY CHANGES WILL BE LOST

#ifndef PRUEBASWRAPPER_H
#define PRUEBASWRAPPER_H

#include <string>

#include <ngrest/engine/ServiceWrapper.h>
#include "pruebas.h"




class pruebas;

//! pruebas service wrapper
class pruebasWrapper: public ::ngrest::ServiceWrapper
{
public:
    pruebasWrapper();
    virtual ~pruebasWrapper();

    virtual ::ngrest::Service* getServiceImpl() override;

    virtual void invoke(const ::ngrest::OperationDescription* operation, ::ngrest::MessageContext* context) override;

    virtual const ::ngrest::ServiceDescription* getDescription() const override;

private:
    pruebas* service;
};





#endif // PRUEBASWRAPPER_H

