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
#include "ServerModel.h"
#include <typeinfo>

//    int brownoutLevel = 1 + (pModel->getNumberOfBrownoutLevels() - 1) * pModel->getConfiguration().getBrownOutFactor();


ServerModel::ServerModel() : servers(0), bootRemain(0), brownoutLevel(0), coldCache(false) {}

ServerModel::ServerModel(int servers, int bootRemain, int brownoutLevel, bool coldCache)
    :  servers(servers),  bootRemain(bootRemain),  brownoutLevel(brownoutLevel),
        coldCache(coldCache) {};


int ServerModel::getBootRemain() const {
    return bootRemain;
}

int ServerModel::getServers() const {
    return servers + ((bootRemain > 0) ? 1 : 0);
}

void ServerModel::setBootRemain(int bootRemain) {
    this->bootRemain = bootRemain;
}

int ServerModel::getBrownOutLevel() const {
    return brownoutLevel;
}

void ServerModel::setBrownOutLevel(int brownoutLevel) {
    this->brownoutLevel = brownoutLevel;
}

int ServerModel::getActiveServers() const {
    return servers;
}

void ServerModel::setActiveServers(int servers) {
    this->servers = servers;
    this->bootRemain = 0;
}

bool ServerModel::isColdCache() const {
    return coldCache;
}

void ServerModel::setColdCache(bool coldCache) {
    this->coldCache = coldCache;
}

bool ServerModel::equals(const pladapt::Configuration& other) const {
    try {
        const ServerModel& otherConf = dynamic_cast<const ServerModel&>(other);
        return servers == otherConf.servers && brownoutLevel == otherConf.brownoutLevel
                && bootRemain == otherConf.bootRemain && coldCache == otherConf.coldCache;
    }
    catch(std::bad_cast&) {}
    return false;
}

void ServerModel::printOn(std::ostream& os) const {
    os << "config[servers=" << servers << ", bootRemain=" << bootRemain
            << ", brownoutLevel=" << brownoutLevel << ", coldCache=" << coldCache << "]";
}

