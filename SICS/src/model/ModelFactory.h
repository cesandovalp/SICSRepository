/*
 * ModelFactory.h
 *
 *  Created on: 17 Jun 2014
 *      Author: jlgpisa
 */

#ifndef MODELFACTORY_H_
#define MODELFACTORY_H_

#include <model/parameter/ParameterModel.h>
#include <model/item/ItemModel.h>
#include <model/dimension/DimensionModel.h>

class ModelFactory {
public:
	// Constructor
	ModelFactory();

	// Methods
	virtual ParameterModel *createParameterModel() = 0;
	virtual ItemModel *createItemModel() = 0;
	virtual DimensionModel *createDimensionModel() = 0;

	// Destructor
	virtual ~ModelFactory();
};

#endif /* MODELFACTORY_H_ */
