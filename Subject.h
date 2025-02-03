//
// Created by Guillermo on 03/02/25.
//

#ifndef SHOPPINGLISTAPP_SUBJECT_H
#define SHOPPINGLISTAPP_SUBJECT_H
#include "Observer.h"


class Subject {
public:
    virtual void subscribe (Observer*o)=0;
    virtual void unsubscribe(Observer*o)=0;
    virtual void notify()=0;
    virtual ~Subject ()= default;

};


#endif //SHOPPINGLISTAPP_SUBJECT_H
