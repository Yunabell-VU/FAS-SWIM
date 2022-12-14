//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


//
// This is queueing network consists of several queues, connected in tandem.
// Based on the idea from Nicky van Foreest (vanforeest@gmail.com)
//
network TandemQueue
{
    parameters:
        @display("i=block/network");
    submodules:
        source: Source {
            @display("p=40,80");
        }
        queue1: Queue {
            @display("p=140,80");
        }
        queue2: Queue {
            @display("p=240,80");
        }
        sink: Sink {
            @display("p=340,80");
        }
    connections:
        source.out --> queue1.in++;
        queue1.out --> queue2.in++;
        queue2.out --> sink.in++;
}
