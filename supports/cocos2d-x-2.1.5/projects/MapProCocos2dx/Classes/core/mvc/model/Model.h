//
//  Model.h
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#ifndef __MapPro__Model__
#define __MapPro__Model__

#include <iostream>
#include "Group.h"
#include "Model.h"
class Model : public Group
{
public:
    static Model* getInstance()
    {
        if (0 == instance)
        {
            instance = new Model();
        }
        return instance;
    }
protected:
	static Model* instance;
};
#endif /* defined(__MapPro__Model__) */