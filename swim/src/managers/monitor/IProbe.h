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
#ifndef IPROBE_H_
#define IPROBE_H_

#include <omnetpp.h>
#include "model/SystemModel.h"
#include "model/EnvironmentModel.h"

/**
 * Abstract base class for collecting information from the target system
 */
class IProbe : public omnetpp::cSimpleModule
{
public:
    virtual double getBasicResponseTime() = 0;
    virtual double getOptResponseTime() = 0;
    virtual double getBasicThroughput() = 0;
    virtual double getOptThroughput() = 0;
    virtual double getUtilization(const std::string& serverName) = 0;
    virtual double getArrivalRate() = 0;

    /**
     * Computes the statistics of systemModel
     *
     * Important: this method resets the collected statistics
     *
     * @return systemModel since the last time it was called
     */
    virtual SystemModel getUpdatedSystemModel() = 0;

    /**
     * Computes statistics of the environmentModel
     *
     * Important: this method resets the collected statistics
     *
     * @return environmentModel statistics since the last time it was called
     */
    virtual EnvironmentModel getUpdatedEnvironmentModel() = 0;
    virtual ~IProbe();
};

#endif /* IPROBE_H_ */
