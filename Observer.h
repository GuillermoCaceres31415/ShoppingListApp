//
// Created by Guillermo on 03/02/25.
//

#ifndef SHOPPINGLISTAPP_OBSERVER_H
#define SHOPPINGLISTAPP_OBSERVER_H


class Observer {
public:
    virtual ~Observer ()= default;
    virtual void update ()=0;
};


#endif //SHOPPINGLISTAPP_OBSERVER_H
