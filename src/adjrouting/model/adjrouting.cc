/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "adjrouting.h"
#include "ns3/log.h"

namespace ns3 {

    NS_LOG_COMPONENT_DEFINE("Ipv4AdjRouting");
    NS_OBJECT_ENSURE_REGISTERED(Ipv4AdjRouting);

    Ipv4AdjRouting::Ipv4AdjRouting() {
        NS_LOG_FUNCTION(this);
    }

    Ipv4AdjRouting::~Ipv4AdjRouting(){
        NS_LOG_FUNCTION(this);
    }

    /*bool Ipv4AdjRouting::Stew(void) {
        printf("I'm not virtual i'm digital\n");
        return false;
    }*/

    bool Ipv4AdjRouting::RouteInput  (Ptr<const Packet> p, const Ipv4Header &header, Ptr<const NetDevice> idev, UnicastForwardCallback ucb, MulticastForwardCallback mcb,
                                LocalDeliverCallback lcb, ErrorCallback ecb)
    {
        //work with ucb (callback for packets forwarded as unicast)
        

        
        //Ipv4Header headerPrime = header;

        //Ptr<Packet> packet = ConstCast<Packet>(p);
        //Ipv4Address destAddress = headerPrime.GetDestination();
        // Ptr<Ipv4Route> route = Ipv4DoppelgangerRouting::ConstructIpv4Route(selectedPort, destAddress); ???

        //ucb(route, packet, header);
        printf("ROUTE INPUT\n");
        return true;
        
    }

    Ptr<Ipv4Route> Ipv4AdjRouting::RouteOutput (Ptr<Packet> p, const Ipv4Header &header, Ptr<NetDevice> oif, Socket::SocketErrno &sockerr)
    {
        printf("ROUTING OUTPUT");
        return NULL;
    }  

    TypeId Ipv4AdjRouting::GetTypeId(void)
    {
        TypeId tid = TypeId("ns3::Ipv4AdjRouting")
                                .SetParent<Object>()
                                .SetGroupName("Internet");

        return tid;
    }
    
    
    void Ipv4AdjRouting::NotifyInterfaceUp(uint32_t interface)
    {
        printf("NotifyInterfaceUp");
        return;
    }

    void Ipv4AdjRouting::NotifyInterfaceDown(uint32_t interface)
    {
        printf("NotifyInterfaceDown");
        return;
    }

    void Ipv4AdjRouting::NotifyAddAddress(uint32_t interface, Ipv4InterfaceAddress address)
    {
        printf("NotifyAddAddress");
        return;
    }

    void Ipv4AdjRouting::NotifyRemoveAddress(uint32_t interface, Ipv4InterfaceAddress address)
    {
        printf("Notify Remove Address");
        return;
    }

    void Ipv4AdjRouting::SetIpv4(Ptr<Ipv4> ipv4)
    {
        //NS_LOG_LOGIC(this << "Setting up Ipv4: " << ipv4);
        printf("SetIpv4");
        return;
    } 

    void Ipv4AdjRouting::PrintRoutingTable(Ptr<OutputStreamWrapper> stream, Time::Unit unit)
    {
        printf("Print Routing Table");
        return;
    }

    void Ipv4AdjRouting::DoDispose(void)
    {
        /*std::map<uint32_t, Flowlet *>::iterator itr = m_flowletTable.begin();
        for (; itr != m_flowletTable.end(); ++itr)
        {
            delete (itr->second);
        }
        m_dreEvent.Cancel();
        m_agingEvent.Cancel();
        m_ipv4 = 0;*/

        
        Ipv4RoutingProtocol::DoDispose();
        printf("DoDispose");
        return;
    }

    void Ipv4AdjRouting::AddRoute (Ipv4Address network, Ipv4Mask networkMask, uint32_t port){
        AdjRoutingEntry adjroutingentry;
        adjroutingentry.network = network;
        adjroutingentry.networkMask = networkMask;
        adjroutingentry.port = port;
        m_routeEntryList.push_back(adjroutingentry);
    }


}

