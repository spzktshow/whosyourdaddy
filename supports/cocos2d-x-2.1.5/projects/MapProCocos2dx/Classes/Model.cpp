//
//  Model.cpp
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#include "Model.h"

Model* Model::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new Model();
	}
	return _instance;
}

Model::~Model()
{

}