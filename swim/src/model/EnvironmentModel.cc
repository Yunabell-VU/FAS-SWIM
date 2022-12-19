/*******************************************************************************
 * Simulator of Web Infrastructure and Management
 * Copyright (c) 2016 Carnegie Mellon University.
 * All Rights Reserved.
 *  
 * THIS SOFTWARE IS PROVIDED "AS IS," WITH NO WARRANTIES WHATSOEVER. CARNEGIE
 * MELLON UNIVERSITY EXPRESSLY DISCLAIMS TO THE FULLEST EXTENT PERMITTED BY LAW
 * ALL EXPRESS, IMPLIED, AND STATUTORY WARRANTIES, INCLUDING, WITHOUT
 * LIMITATION, THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, AND NON-INFRINGEMENT OF PROPRIETARY RIGHTS.
 *  
 * Released under a BSD license, please see license.txt for full terms.
 * DM-0003883
 *******************************************************************************/
#include "EnvironmentModel.h"

EnvironmentModel::EnvironmentModel() : arrivalMean(0), arrivalVariance(0) {}

EnvironmentModel::EnvironmentModel(double arrivalMean, double arrivalStdDev)
    : arrivalMean(arrivalMean), arrivalVariance(arrivalStdDev) {};

double EnvironmentModel::getArrivalMean() const {
    return arrivalMean;
}

void EnvironmentModel::setArrivalMean(double arrivalMean) {
    this->arrivalMean = arrivalMean;
}

double EnvironmentModel::getArrivalVariance() const {
    return arrivalVariance;
}

void EnvironmentModel::setArrivalVariance(double arrivalVariance) {
    this->arrivalVariance = arrivalVariance;
}

void EnvironmentModel::printOn(std::ostream& os) const {
    os << "environment[interArrival mean=" << arrivalMean << ", variance=" << arrivalVariance << "]";
}

std::ostream& operator<<(std::ostream& os, const EnvironmentModel& env) {
    env.printOn(os);
    return os;
}

double EnvironmentModel::asDouble() const {
    return arrivalMean;
}

