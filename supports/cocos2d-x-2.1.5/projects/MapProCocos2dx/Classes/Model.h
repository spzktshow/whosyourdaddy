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
class Model : public Group
{
public:
    static Model* getInstance();
	~Model();
private:
	static Model* _instance;
};
#endif /* defined(__MapPro__Model__) */